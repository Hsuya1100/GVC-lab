#include<GL/glut.h>
#include<math.h>
void initGL(){
	glClearColor(0.0f,0.0f,0.0f,1.0);
	gluOrtho2D(-100.0,100,-100,100);
}
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//glRotatef(45,0.0f,0.0f,1.0f);
	glBegin(GL_QUADS);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex2f( -35.0f, 5.0f);
     	 	glVertex2f(-35.0f, 35.0f);
    		glVertex2f(-5.0f, 35.0f);
      		glVertex2f( -5.0f, 5.0f);
	glEnd();
	glFlush();
	//glRotatef(315,0.0,0.0,1);
	
	float x=1/(sqrt(2));
	GLfloat ro[16]={x,x,0,0,
	-x,x,0,0,
	0,0,1,0,
	0,0,0,1};
	glMultMatrixf(ro);

	GLfloat m[16] = {
   	 1.0f, 0.0f, 0.0f, 0.0f,
   	 2, 1.0f, 0.0f, 0.0f,
   	 0.0f, 0.0f, 1.0f, 0.0f,
   	 0.0f, 0.0f, 0.0f, 1.0f
	};


glMultMatrixf(m);
}
int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("sds");
	glutDisplayFunc(Display);
	initGL();
	glutMainLoop();
	return 0;
}
