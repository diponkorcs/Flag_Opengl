#include<windows.h>
#include<iostream>
#include<math.h>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;

int R, X1, Y1;

void Rectangle(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0,-200.0, 200.0);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex2f(-180.0f, 180.0f);
    glVertex2f(180.0f, 180.0f);
    glVertex2f(180.0f, -180.0f);
    glVertex2f(-180.0f, -180.0f);

	glEnd();
	glFlush();
}

void Circle(void)
{
    float x = X1,y = Y1,r = R;

    double x0 = 0, y0 = r, d = 5/4-r;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i < R-10 ; i++)
    {
        if(d<0)
        {
            x0 +=1;
            d += (2*x0)+1;
        }
        else
        {
            d += ((2*x0)+1-(2*y0));
            x0 += 1;
            y0 -= 1;
        }

        glVertex2f(x0+x,y0+y);
        glVertex2f(y0+x,x0+y);
        glVertex2f(-y0+x,x0+y);
        glVertex2f(x0+x,-y0+y);
        glVertex2f(-x0+x,-y0+y);
        glVertex2f(-y0+x,-x0+y);
        glVertex2f(y0+x,-x0+y);
        glVertex2f(-x0+x,y0+y);
    }

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0,-200.0, 200.0);

    glEnd();
    glFlush();
}

//void myInit (void)
//{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glPointSize(4.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-200.0, 200.0,-200.0, 200.0);
//    //gluOrtho2D(-100.0, 640.0,-100.0, 480.0);
//    //gluOrtho2D(0.0, 640.0,0.0, 480.0);
//}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize (640, 480);
    glutInitWindowSize (640, 480);
    //glutInitWindowPosition (100, 150);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Bangladesh Flag");

    cout<<"Enter Circle Mid-point(X): ";
    cin>>X1;
    cout<<"Enter Circle Mid-point point(Y): ";
    cin>>Y1;

    cout<<"Enter the Radius: ";
    cin>>R;

    //glutDisplayFunc(Rectangle);
    glutDisplayFunc(Circle);
    //Rectangle();
    //Circle();
    //myInit();
    glutMainLoop();
}

