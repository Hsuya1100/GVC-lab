//
// Created by panther on 27/9/17.
//

#ifndef OPENGLSTART_LAB2TRI1_H
#define OPENGLSTART_LAB2TRI1_H



#include <GL/glut.h>
#include <vector>
using namespace std;
class lab2tri1 {
public:
    void init(void){
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-10.0,10.0,-10.0,10.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0,0.4,0.2);
        glLineWidth(3.0);
    }
    static void drawtriangle(void){
        double v[3][2];
        v[0][0] = -1.0;
        v[0][1] =  0.0;
        v[1][0] =  0.5;
        v[1][1] =  1.0;
        v[2][0] =  0.5;
        v[2][1] = -1.0;
        glBegin(GL_TRIANGLES);
            glVertex2d(v[0][0],v[0][1]-0.1);
            glVertex2d(v[1][0],v[1][1]-0.1);
            glVertex2d(v[2][0],v[2][1]-0.1);
        glEnd();
        glBegin(GL_TRIANGLES);
            glVertex2d(v[0][0],v[0][1] + 5.1);
            glVertex2d(v[1][0],v[1][1] + 5.1);
            glVertex2d(v[2][0],v[2][1] + 5.1);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex2d(-v[0][1]-3,v[0][0]+3);
        glVertex2d(-v[1][1]-3,v[1][0]+3);
        glVertex2d(-v[2][1]-3,v[2][0]+3);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex2d(-v[0][1]+2,v[0][0]+3);
        glVertex2d(-v[1][1]+2,v[1][0]+3);
        glVertex2d(-v[2][1]+2,v[2][0]+3);
        glEnd();
        glFlush();
    }
    static void drawlines(void){
        double v[4][2];
        v[0][0] = -3.0;
        v[0][1] =  0.0;
        v[1][0] =  2.0;
        v[1][1] =  0.0;
        v[2][0] = -1.0;
        v[2][1] =  1.0;
        v[3][0] = -1.0;
        v[3][1] = -1.0;
        glBegin(GL_LINES);
            glVertex2d(v[0][0],v[0][1]-0.1);
            glVertex2d(v[1][0],v[1][1]-0.1);
            glVertex2d(v[2][0],v[2][1]-0.1);
            glVertex2d(v[3][0],v[3][1]-0.1);
        glEnd();
        glBegin(GL_LINES);
        glVertex2d(v[0][0],v[0][1] + 5.1);
        glVertex2d(v[1][0],v[1][1] + 5.1);
        glVertex2d(v[2][0],v[2][1] + 5.1);
        glVertex2d(v[3][0],v[3][1] + 5.1);
        glEnd();
        glBegin(GL_LINES);
        glVertex2d(-v[0][1]-3,v[0][0]+3);
        glVertex2d(-v[1][1]-3,v[1][0]+3);
        glVertex2d(-v[2][1]-3,v[2][0]+3);
        glVertex2d(-v[3][1]-3,v[3][0]+3);
        glEnd();
        glBegin(GL_LINES);
        glVertex2d(-v[0][1]+2,v[0][0]+3);
        glVertex2d(-v[1][1]+2,v[1][0]+3);
        glVertex2d(-v[2][1]+2,v[2][0]+3);
        glVertex2d(-v[3][1]+2,v[3][0]+3);
        glEnd();
        glFlush();
    }
public:
    static void labtri1(){
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(0,0);
        glutInitWindowSize(1920,1080);
        glutCreateWindow("sadsad");

        lab2tri1 *l =  new lab2tri1();
        l->init();
        l->drawtriangle();
        l->drawlines();
        glutMainLoop();
    }


};


#endif //OPENGLSTART_LAB2TRI1_H
