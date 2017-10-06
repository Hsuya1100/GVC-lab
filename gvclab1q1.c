#include <GL/glut.h>

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  //set bckgrnd color
	glMatrixMode (GL_PROJECTION); //projection matrix
	gluOrtho2D (0.0, 20.0, 0.0, 15.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clea background
	glColor3f(1.0, 0.0, 0.0);

	//draw two points
	glBegin(GL_POINTS);
	for(int i = 0; i < 10; i++)
	{
		glVertex2i(10+5*i,110);
	}
	glEnd();

	//draw a line
	glBegin(GL_LINES);
	glVertex2i(5.0,1.5);
	glVertex2i(9.3,7.2);
	glEnd();

	glFlush(); //render now
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display); //fun t be rendered for writing
	glutMainLoop();  //event processing loop, waits for the next event, always
	return 0;
}
