//
// Created by death_teaser on 30/9/17.
//

#ifndef OPENGLSTART_LAB1LINE_H
#define OPENGLSTART_LAB1LINE_H


#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glut.h>

class lab1Line {
public:
    void init(void){
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-0.5,10.0,-0.5,10.0);
    }

    static void lineseg(void){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0,0.4,0.2);
        glBegin(GL_LINES);
            glVertex2d(0.0,0.0);
            glVertex2d(10.0,0.0);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(0.0,0.0);
            glVertex2d(0.0,10.0);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(5.0,1.5);
            glVertex2d(9.3,7.2);
        glEnd();
        glFlush();
    }

public:
    static void labline(){
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(0,0);
        glutInitWindowSize(1920,1080);
        glutCreateWindow("sadsad");

        lab1Line *l = new lab1Line();
        l->init();
        glutDisplayFunc(l->lineseg);
        glutMainLoop();
    }

};


#endif //OPENGLSTART_LAB1LINE_H
