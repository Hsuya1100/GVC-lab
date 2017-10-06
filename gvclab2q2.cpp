#include <GL/glut.h>

void sun_flower() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	float i;
	for (i = 0; i <= 360; i += 9) {
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.15, 0.03);
			glVertex2f(0.18, 0.21);
			glVertex2f(0.03, 0.15);
			glVertex2f(0.0, 0.0);
		glEnd();
		glLoadIdentity();
		glRotatef(i, 0.0, 0.0, 1.0);
	}
	glLoadIdentity();
	glBegin(GL_LINES);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -0.8);		
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2f(0.0, -0.8);
		glVertex2f(-0.03, -0.77);
		glVertex2f(0.03, -0.77);
	glEnd();
	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900,900);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Sun Flower");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(sun_flower);
	glutMainLoop();
}
