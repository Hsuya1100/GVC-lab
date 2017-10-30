//
// Created by panther on 27/9/17.
//

#ifndef OPENGLSTART_LAB4WHEEL_H
#define OPENGLSTART_LAB4WHEEL_H

#include <iostream>
#include <GL/glut.h>
#include <math.h>
#define pi 3.14

using namespace std;


class lab4Wheel {
public:
    void init(void){
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-10.0,10.0,-10.0,10.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(2.0);
    }
    void drawwheel(void){
        double r1 = 1.0,r2 = 2.0,r3 = 3.0;
        double thetha;
        int i = 0;
        for (thetha = 0.0; thetha <= 2*pi; i++,thetha += pi/12){
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            glBegin(GL_POLYGON);
            glVertex2f(0.0,0.0);
            glVertex2f(r3 * cos(thetha), r3 * sin(thetha));
            glVertex2f(r3 * cos(thetha+(pi/12)), r3 * sin(thetha+(pi/12)));
            glEnd();
        }
        i=0;
        for (thetha =0.0; thetha < 2*pi; i++,thetha += pi/12){
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            if(i%2==0)
                glColor3f(1.0,0.0,0.0);
            else
                glColor3f(0.0,0.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(0.0,0.0);
            glVertex2f(r3 * cos(thetha), r3 * sin(thetha));
            glVertex2f(r3 * cos(thetha+(pi/12)), r3 * sin(thetha+(pi/12)));
            glEnd();
        }

        thetha = 0.0;
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(2.0,0.0);
        thetha += pi/12;
        for (; thetha < 2*pi; thetha += pi/12){
            glVertex2f(r2 * cos(thetha), r2 * sin(thetha));
        }
        glVertex2f(2.0,0.0);
        glEnd();


        thetha =0.0;
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(2.0,0.0);
        thetha += pi/12;
        i = 0;
        for (; thetha < 2*pi; i++,thetha += pi/12){
            glVertex2f(r2 * cos(thetha), r2 * sin(thetha));
        }
        glVertex2f(2.0,0.0);
        glEnd();


        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        thetha = 0.0;
        for(;thetha <= 2*pi; thetha += pi/12){
            glVertex2f(0.0,0.0);
            glVertex2f(r3*cos(thetha),r3*sin(thetha));
        }
        glEnd();

        thetha = 0.0;
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(1.0,0.0);
        thetha += pi/12;
        for (; thetha < 2*pi; thetha += pi/12){
            glVertex2f(r1 * cos(thetha), r1 * sin(thetha));
        }
        glVertex2f(1.0,0.0);
        glEnd();
        thetha =0.0;
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(1.0,0.0);
        thetha += pi/12;
        i = 0;
        for (; thetha < 2*pi; i++,thetha += pi/12){
            glVertex2f(r1 * cos(thetha), r1 * sin(thetha));
        }
        glVertex2f(1.0,0.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        thetha = 0.0;
        for(;thetha <= 2*pi; thetha += pi/4){
            glVertex2f(0.0,0.0);
            glVertex2f(r3*cos(thetha),r3*sin(thetha));
        }
        glEnd();
        glFlush();
    }

    static void draw1(){
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(0,0);
        glutInitWindowSize(1920,1080);
        glutCreateWindow("aas");

        lab4Wheel *l = new lab4Wheel();
        l->init();
        l->drawwheel();
        glutMainLoop();
    }

};


#endif //OPENGLSTART_LAB4WHEEL_H
