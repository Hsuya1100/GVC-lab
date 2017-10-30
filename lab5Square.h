//
// Created by panther on 28/9/17.
//

#ifndef OPENGLSTART_LAB5SQUARE_H
#define OPENGLSTART_LAB5SQUARE_H


#include <GL/glut.h>
#include <math.h>
#define pi 3.14

class lab5Square {

public:
    void init(void){
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-60.0,60.0,-60.0,60.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    static void squared(void){
        double x = -20.0;
        double y = -20.0;

//        glBegin(GL_LINES);
//        glColor3f(1.0,0.0,0.0);
//        glVertex2d(-60.0,0.0);
//        glVertex2d(60.0,0.0);
//        glVertex2d(0.0,-60.0);
//        glVertex2d(0.0,60.0);
//        glEnd();

        double v1x = x + 15.0,v2x = x - 15.0,v3x = x - 15.0,v4x = x + 15.0,v1y = y + 15.0,v2y = y + 15.0,v3y = y - 15.0,v4y = y - 15.0;

        glBegin(GL_QUADS);
        glColor3f(1.0,1.0,0.0);
        glVertex2d(v1x,v1y);
        glVertex2d(v2x,v2y);
        glVertex2d(v3x,v3y);
        glVertex2d(v4x,v4y);

        v1y = -v1y;
        v2y = -v2y;
        v3y = -v3y;
        v4y = -v4y;

        v1x = v1x + 20.0;
        v2x = v2x + 20.0;
        v3x = v3x + 20.0;
        v4x = v4x + 20.0;

        v1y = v1y - 20.0;
        v2y = v2y - 20.0;
        v3y = v3y - 20.0;
        v4y = v4y - 20.0;

        v1x = v1x * cos(pi/4) - v1y * sin(pi/4);
        v2x = v2x * cos(pi/4) - v2y * sin(pi/4);
        v3x = v3x * cos(pi/4) - v3y * sin(pi/4);
        v4x = v4x * cos(pi/4) - v4y * sin(pi/4);

        v1y = v1x * sin(pi/4) + v1y * cos(pi/4);
        v2y = v2x * sin(pi/4) + v2y * cos(pi/4);
        v3y = v3x * sin(pi/4) + v3y * cos(pi/4);
        v4y = v4x * sin(pi/4) + v4y * cos(pi/4);

        v1x = v1x + 2*v1y;
        v2x = v2x + 2*v2y;
        v3x = v3x + 2*v3y;
        v4x = v4x + 2*v4y;

        v1x = v1x - 20.0;
        v2x = v2x - 20.0;
        v3x = v3x - 20.0;
        v4x = v4x - 20.0;

        v1y = v1y + 20.0;
        v2y = v2y + 20.0;
        v3y = v3y + 20.0;
        v4y = v4y + 20.0;

        glColor3f(1.0,0.0,1.0);
        glVertex2d(v1x,v1y);
        glVertex2d(v2x,v2y);
        glVertex2d(v3x,v3y);
        glVertex2d(v4x,v4y);



        glEnd();
        glFlush();

    }

    static void startit(){
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(600,600);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Square");

        lab5Square *l = new lab5Square();
        l->init();
        glutDisplayFunc(l->squared);
        glutMainLoop();
    }

};


#endif //OPENGLSTART_LAB5SQUARE_H
