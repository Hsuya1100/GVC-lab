#include <GL/glut.h>

void cross_triangles() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	int i, j;
	for(i = 1; i <= 2; i++) {
		for(j = 1; j <= 2; j++) {			
			glBegin(GL_LINES);
				glVertex2f(-0.3, 0.4);
				glVertex2f(0.3, 0.4);
			glEnd();
			glBegin(GL_LINES);
				glVertex2f(-0.1, 0.3);
				glVertex2f(-0.1, 0.5);
			glEnd();
			glBegin(GL_TRIANGLES);
				glVertex2f(-0.1, 0.4);
				glColor3f(0.6, 0.6, 0.6);
				glVertex2f(0.1, 0.5);
				glVertex2f(0.1, 0.3);
				glColor3f(0.0, 0.0, 0.0);
			glEnd();
			
			if (j == 1) {
				if (i == 1) {
					glTranslatef(0.0, -0.8, 0.0);
				} else {
					glLoadIdentity();
					glRotatef(90.0, 0.0, 0.0, 1.0);
				}
			}
		}
		if (i == 1) {
			glLoadIdentity();
			glTranslatef(0.8, 0.0, 0.0);
			glRotatef(90.0, 0.0, 0.0, 1.0);
		}
	}
	glLoadIdentity();
	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cross Triangles");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(cross_triangles);
	glutMainLoop();
}
