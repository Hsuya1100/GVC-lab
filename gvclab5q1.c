#include <GL/glut.h>  

GLfloat angle = 0.0f;
int refreshMills = 300;
int shear= 2; 

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}
 
void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}

GLfloat m[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    shear, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


void display() {
   glClear(GL_COLOR_BUFFER_BIT);    
   glMatrixMode(GL_MODELVIEW);      
   glLoadIdentity();                
 
   glPushMatrix();                     // Save model-view matrix setting
   //glTranslatef(-0.5f, 0.0f, 0.0f);    // Translate left and up
   glRotatef(angle, 0.0f, 0.0f, 1.0f);  
   glBegin(GL_QUADS);               
      glColor3f(1.0f, 1.0f, 1.0f);  
      glVertex2f(-0.35f, -0.05f);     
      glVertex2f( 0.05f, -0.35f);     
      glVertex2f( 0.35f,  0.05f);
      glVertex2f(-0.05f,  0.35f);
   glEnd();

  // glMultMatrixf(m);

   glPopMatrix();


/*   glPushMatrix();                     // Save model-view matrix setting
//   glTranslatef(0.4f, -0.3f, 0.0f);    // Translate
//   glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
   //glMultMatrixf(m);
   glScalef(1.0f, 1.0f, -1.0f);
   glBegin(GL_QUADS);               
      glColor3f(1.0f, 1.0f, -1.0f);  
      glVertex2f(-0.35f, -0.05f);     
      glVertex2f( 0.05f, -0.35f);     
      glVertex2f( 0.35f,  0.05f);
      glVertex2f(-0.05f,  0.35f);
   glEnd();
   glPopMatrix(); */ 
 
//   glTranslatef(0.1f, -0.7f, 0.0f); // Translate right and down 
//   glTranslatef(-0.3f, -0.2f, 0.0f); // Translate left and down
 
   glutSwapBuffers();
   angle += 45.0f;

    //glScalef(0.86,0.86,0.86);
    //glTranslatef(200,0,0);
    //glRotatef(30, 0, 0,1);



}
 

void reshape(GLsizei width, GLsizei height) {  
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   glViewport(0, 0, width, height);
 
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();
   if (width >= height) {
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);          
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("Model Transform");  
   glutDisplayFunc(display);       
   glutReshapeFunc(reshape); 
   glutTimerFunc(0, Timer, 0);      
   initGL();                       
   glutMainLoop();                 
   return 0;
}