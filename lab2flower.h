//
// Created by panther on 27/9/17.
//

#ifndef OPENGLSTART_LAB2FLOWER_H
#define OPENGLSTART_LAB2FLOWER_H


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.14

class lab2flower {
public:
    void init(void){
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-5.0,5.0,-5.0,5.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0,0.4,0.2);
        glLineWidth(3.0);
    }

public:
    void flower(void){
        double v[4][2];
        v[0][0] = 0.0;
        v[0][1] = 0.0;
        v[1][0] = 0.5;
        v[1][1] = 1.0;
        v[2][0] = 0.0;
        v[2][1] = 2.0;
        v[3][0] = -0.5;
        v[3][1] = 1.0;
        double theta;
        for (theta = 0.0; theta < 2*pi; theta += pi/30){
            glBegin(GL_LINE_LOOP);
            glVertex2d(v[0][0]*cos(theta) - v[0][1]*sin(theta),v[0][0]*sin(theta) + v[0][1]*cos(theta));
            glVertex2d(v[1][0]*cos(theta) - v[1][1]*sin(theta),v[1][0]*sin(theta) + v[1][1]*cos(theta));
            glVertex2d(v[2][0]*cos(theta) - v[2][1]*sin(theta),v[2][0]*sin(theta) + v[2][1]*cos(theta));
            glVertex2d(v[3][0]*cos(theta) - v[3][1]*sin(theta),v[3][0]*sin(theta) + v[3][1]*cos(theta));
            glEnd();
        }
        glFlush();
    }
public:
    static void labtri1(){
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(0,0);
        glutInitWindowSize(1920,1080);
        glutCreateWindow("sadsad");

        lab2flower *l =  new lab2flower();
        l->init();
        l->flower();
        glutMainLoop();
    }



};


#endif //OPENGLSTART_LAB2FLOWER_H
