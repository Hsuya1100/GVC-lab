#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
const int screenWidth=640;
const int screenHeight=480;
void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5.0);
}

void setWindow(float left,float right,float bottom,float top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
}

void setViewport(int left,int right,int bottom,int top)
{
	glViewport(left,right,bottom,top);
}

void myDisplay()
{
	GLdouble i=0;
	GLfloat x=0;
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(-4.0,4.0,-0.3,1.0);
	glBegin(GL_POINTS);
	for(x=-4.0; x<4.0; x+=0.1)
		glVertex2f(x,sin(3.1415*x)/(3.1415*x));
	glEnd();
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(320,480);
	glVertex2i(320,0);
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutCreateWindow("sinc function = sin(PI*X)/PI*X");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
