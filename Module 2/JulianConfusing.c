/*
 * Test if a point is inside a triangle.
 * Julian Saknussemm
 *
 * Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
 * the triangle.
 *
 * This is determined by satisfying the following rule:
 * A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2) if:
 * P is on the same side of the line AB as C
 * P is on the same side of the line BC as A
 * and
 * P is on the same side of the line AC as B
 *
 * A special case exits for a vertical line (inf gradient) when testing the side of the line
 */

#include <stdio.h>
#include <stdlib.h>

#define UNDER -1
#define ON_LINE 0
#define OVER 1

int test1( double px, double py, double m, double b);
int test2( double px, double py, double m,double b, double lx,double ly);
int tritest(double x1,double y1,double x2,double y2,double x3,double y3,double pointX, double pointY)

int main(int argc, char* argv[]) {
    int numOfInputs = 0;
    
    printf("Please print your inputs in the format of: a,b\n");
    
    // get input
    printf("Triangle Vertex A (x,y): ");
    double x1, y1;
    numOfInputs += scanf("%lf,%lf", &x1, &y1);
    
    printf("Triangle Vertex  B (x,y): ");
    double x2, y2;
    numOfInputs += scanf("%lf,%lf", &x2, &y2);
    
    printf("Triangle Vertex  C (x,y): ");
    double x3, y3;
    numOfInputs += scanf("%lf,%lf", &x3, &y3);
    
    printf("Test Point (x,y): ");
    double pointX, pointY
    numOfInputs += scanf("%lf,%lf", &pointX, &pointY);
    

    if( numOfInputs != 8 ) {
        // print error
        printf("You're stupid and didn't put in the right inputs!\n");
    } else {
        // print answer
        printf("Point (%.2lf,%.2lf) is ", pointX, pointY);
        
        if(tritest(x1,y1,x2,y2,x3,y3,pointX,pointY)) {
            printf("inside");
        } else {
            printf("outside");
        }
        
        printf(" the Triangle\n");
        
    }
    
    // return 0
    return EXIT_SUCCESS;
}


int test1 (double pointX, double pointY, double m, double b) {
    int return_value;
    if pointY < (m * pointX + b) {
        return_value = UNDER;
    }else if pointY == (m * pointX + b){
        return_value = ON_LINE;
    } else {
        return_value = OVER;
    }
    return return_value;
}

int test2( double px, double py, double m,double b, double lx,double ly) {
    return (test1( px,py, m,b ) == test1(lx,ly,m,b));
}

int tritest(double x1,double y1,double x2,double y2,double x3,double y3,double pointX, double pointY){
    
    int line1, line2, line3;
    
    double gradient1, gradient2, gradient3
    gradient1 = (y2-y1)/(x2-x1);
    gradient2 = (y3-y2)/(x3-x2);
    gradient3 = (y3-y1)/(x3-x1);
    
    double y_Int1, y_Int2, y_Int3
    y_Int1 = gradient1 * -x2 + y2;
    y_Int2 = gradient2 * -x3 + y3;
    y_Int3 = gradient3 * -x3 + y3;
    
    // vertical line checks
    if (x2 == x1) {
        line1 = ((pointX <= x1) == (x3 <= x1));
    } else {
        line1 = test2(pointX, pointY, gradient1, y_Int1,x2,y2);
    }
    
    if (x2 == x3) {
        line2 = ((px <= x3) == (x1 <= x3));
    } else {
        line2 = test2(pointX, pointY, gradient2, y_Int2, x1, y1);
    }
    
    if (x3 == x1) {
        line3 = ((pointX <= x1 ) == (x2 <= x1));
    } else {
        line3 = test2(pointX, pointY, gradient3, y_Int3, x2, y2);
    }
    
    return line1 && line2 && line3;
}

