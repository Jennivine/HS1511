#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

#include "pixelColor.h"
#include "mandelbrot.h"

int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket, double x, double y, int z);
static void serveHTML(int socket);

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 7191
#define NUMBER_OF_PAGES_TO_SERVE 500
// after serving this many pages the server will halt

#define SIZE 512

int main (int argc, char *argv[]) {
    double x,y;
    int z;
    
    printf ("************************************\n");
    printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
    printf ("Serving bmps since 2018\n");
    
    int serverSocket = makeServerSocket (DEFAULT_PORT);
    printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
    printf ("************************************\n");
    
    char request[REQUEST_BUFFER_SIZE];
    
    int numberServed = 0;
    while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
        
        printf ("*** So far served %d pages ***\n", numberServed);
        
        int connectionSocket = waitForConnection (serverSocket);
        // wait for a request to be sent from a web browser, open a new
        // connection for this conversation
        
        // read the first line of the request sent by the browser
        int bytesRead;
        bytesRead = read (connectionSocket, request, (sizeof request)-1);
        assert (bytesRead >= 0);
        // were we able to read any data from the connection?
        
        printf("%s\n", request);
        
        int input = sscanf(request, "GET /mandelbrot/2/%d/%lf/%lf/tile.bmp HTTP/1.1", &z, &x, &y);
        int input2 = sscanf(request, "GET /tile_x%lf_y%lf_z%d.bmp HTTP/", &x, &y, &z);
        
        if (input == 0 && input2 == 0) {
            serveHTML(connectionSocket);
        } else if (input == 3 || input2 == 3){
            serveBMP(connectionSocket, x, y, z);
        }
        // close the connection after sending the page- keep aust beautiful
        close(connectionSocket);
        numberServed++;
    }
    
    // close the server connection after we are done- keep aust beautiful
    printf ("** shutting down the server **\n");
    close (serverSocket);
    
    return EXIT_SUCCESS;
}

int escapeSteps(double x, double y) {
    double r = 0;
    double i = 0;
    double nextR;
    double nextI;
    double iterations = 0;
    
    while ((r*r + i*i <= 4) && (iterations < 256)) {
        nextR = (r * r - i * i) + x;
        nextI = (2 * r * i) + y;
        
        r = nextR;
        i = nextI;
        
        iterations++; //counts how many iterations it takes
    }
    
    return iterations;
}

void serveBMP (int socket, double x, double y, int z) {
    int counterY = 0;
    int counterX = 0;
    int counterRGB = 0;
    double xBack;
    
    // first send the http response header
    
    // (if you write stings one after another like this on separate
    // lines the c compiler kindly joins them togther for you into
    // one long string)
    char* bmpMessage;
    bmpMessage = "HTTP/1.0 200 OK\r\n"
    "Content-Type: image/bmp\r\n"
    "\r\n";
    
    // now send the BMP header
    unsigned char bmpHeader[54] = {
        0x42,0x4D,0x36,0x00,0x0C,0x00,0x00,0x00,
        0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
        0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,
        0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x0C,0x00,0x13,0x0B,
        0x00,0x00,0x13,0x0B,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00
    };
    
    // code below generates the actual mandelbrot bmp
    double distBetweenPixels = pow(2, -z);
    double regionLength = distBetweenPixels * (SIZE - 1); // length of entire BMP
    x = x - (regionLength / 2); // starting x
    xBack = x; // x to return to after each row
    y = y - (regionLength / 2); // starting y
    
    unsigned char bmpImage[SIZE*SIZE*3];
    while (counterY < SIZE) {
        x = xBack;
        counterX = 0;
        while (counterX < SIZE) {
            bmpImage[counterRGB] = stepsToRed(escapeSteps(x,y));
            bmpImage[counterRGB+1] = stepsToGreen(escapeSteps(x,y));
            bmpImage[counterRGB+2] = stepsToBlue(escapeSteps(x,y));
            counterRGB += 3;
            counterX++;
            x += distBetweenPixels;
        }
        counterY++;
        y += distBetweenPixels;
    }
    
    // sends the bytes to the HTML server
    write(socket, bmpMessage, strlen(bmpMessage) );
    write(socket, bmpHeader,  sizeof(bmpHeader)  );
    write(socket, bmpImage,   sizeof(bmpImage)   );
}

// start the server listening on the specified port number
int makeServerSocket (int portNumber) {
    
    // create socket
    int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
    assert (serverSocket >= 0);
    // error opening socket
    
    // bind socket to listening port
    struct sockaddr_in serverAddress;
    memset ((char *) &serverAddress, 0,sizeof (serverAddress));
    
    serverAddress.sin_family      = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port        = htons (portNumber);
    
    // let the server start immediately after a previous shutdown
    int optionValue = 1;
    setsockopt (
                serverSocket,
                SOL_SOCKET,
                SO_REUSEADDR,
                &optionValue,
                sizeof(int)
                );
    
    int bindSuccess =
    bind (
          serverSocket,
          (struct sockaddr *) &serverAddress,
          sizeof (serverAddress)
          );
    
    assert (bindSuccess >= 0);
    // if this assert fails wait a short while to let the operating
    // system clear the port before trying again
    
    return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
    // listen for a connection
    const int serverMaxBacklog = 10;
    listen (serverSocket, serverMaxBacklog);
    
    // accept the connection
    struct sockaddr_in clientAddress;
    socklen_t clientLen = sizeof (clientAddress);
    int connectionSocket =
    accept (
            serverSocket,
            (struct sockaddr *) &clientAddress,
            &clientLen
            );
    
    assert (connectionSocket >= 0);
    // error on accept
    
    return (connectionSocket);
}

static void serveHTML (int socket) {
    char* message;
    
    // first send the http response header
    message =
    "HTTP/1.0 200 Found\n"
    "Content-Type: text/html\n"
    "\n";
    printf ("about to send=> %s\n", message);
    write (socket, message, strlen (message));
    
    message =
    "<script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>"
    "\n";
    write (socket, message, strlen (message));
}
