//
// Created by panther on 3/10/17.
//

#ifndef OPENGLSTART_LAB3Q2_H
#define OPENGLSTART_LAB3Q2_H


#include <GL/glut.h>

class lab3Q2 {
public:
    void initGL() {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glShadeModel(GL_SMOOTH);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    }

    static void display() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();
        glTranslatef(-3.5f, 3.0f, -10.0f);

        glBegin(GL_QUADS);
        //Red on left top
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f( 1.0f, -1.0f, 1.0f);
        glEnd();

        glLoadIdentity();
        glTranslatef(-3.0f, 0.0f, -10.0f);
        glBegin(GL_QUADS);
        //Green below red
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f( 1.0f, -1.0f, 1.0f);
        glEnd();

        glLoadIdentity();
        glTranslatef(-3.0f, -0.5f, -7.0f);
        glBegin(GL_TRIANGLES);
        //Green below red
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f( 0.5f,  0.5f, 0.5f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.5f,  0.5f, 0.5f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 0.5f, -0.5f, 0.5f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f( 0.5f,  0.5f, 0.5f);
        glEnd();

        glLoadIdentity();
        glTranslatef(3.0f, 4.0f, -13.0f);
        glBegin(GL_POLYGON);
        //Green below red
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f,  0.0f, 1.0f);
        glVertex3f( 0.5f,  1.0f, 1.0f);
        glVertex3f(-0.5f,  1.0f, 1.0f);
        glVertex3f(-1.0f,  0.0f, 1.0f);
        glVertex3f(-0.5f, -1.0f, 1.0f);
        glVertex3f( 0.5f, -1.0f, 1.0f);
        glEnd();

        glLoadIdentity();
        glTranslatef(0.5f, -0.6f, -9.0f);
        glBegin(GL_TRIANGLES);
        //Green below red
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f,  0.0f, 1.0f);
        glVertex3f( 0.0f,  1.5f, 1.0f);
        glVertex3f(-1.0f,  0.0f, 1.0f);
        glEnd();

        glLoadIdentity();
        glTranslatef(1.0f, -0.3f, -9.0f);
        glBegin(GL_TRIANGLES);
        //Green below red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 1.0f,  0.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 0.0f,  -1.5f, 1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,  0.0f, 1.0f);
        glEnd();


        glutSwapBuffers();
    }


    static void reshape(GLsizei width, GLsizei height) {
        if (height == 0) height = 1;
        GLfloat aspect = (GLfloat)width / (GLfloat)height;

        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0f, aspect, 0.1f, 30.0f);
    }



    static void draww(){
        glutInitDisplayMode(GLUT_DOUBLE);
        glutInitWindowSize(640, 480);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("dasadasadasad");
        lab3Q2 *l = new lab3Q2();
        glutDisplayFunc(l->display);
        glutReshapeFunc(l->reshape);
        l->initGL();
        glutMainLoop();
    }
};


#endif //OPENGLSTART_LAB3Q2_H
