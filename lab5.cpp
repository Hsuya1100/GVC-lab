#include <GL/glut.h>  

int shear = 2;

GLfloat m[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    shear, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};
/*      glVertex2f(-0.35f, -0.05f);     
      glVertex2f( 0.05f, -0.35f);     
      glVertex2f( 0.35f,  0.05f);
      glVertex2f(-0.05f,  0.35f);*/

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2f(-35, -5);
    glVertex2f(5, -35);
    glVertex2f(35, 5);
    glVertex2f(-5, 35);
    glEnd();
    glMultMatrixf(m);
    glScalef(0.86,0.86,0.86);
    glTranslatef(200,0,0);
    glRotatef(30, 0, 0,1);

    glBegin(GL_QUADS);
    glVertex2f(-35, -5);
    glVertex2f(5, -35);
    glVertex2f(35, 5);
    glVertex2f(-5, 35);
    glEnd();



    glFlush();
}


void init()
{
    glClearColor(0.5,0.5,0.0, 0.0);
    glColor3f(1,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,      // left
        800,  // right
        800, // bottom
        0,      // top
        0,      // zNear
        1       // zFar
        );

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowSize(900, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Simple");

    glutDisplayFunc(display);

    init();

    glutMainLoop();
    return 0;
}