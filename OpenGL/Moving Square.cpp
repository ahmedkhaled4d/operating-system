#include <stdio.h> 
#include <GL/glut.h>

void display(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON); // Drow Square
		glVertex3f(2.0, 4.0, 0.0);
		//glVertex3f(4.2, 4.2, .2);
		glVertex3f(8.0, 4.0, 0.0);
		glVertex3f(8.0, 8.0, 0.0);
		glVertex3f(2.0, 8.0, 0.0);
	glEnd();
	glFlush();
}


int main(int argc, char **argv)
{
	printf("Assignmrnt1\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Moving square");

	glClearColor(0.0, 0.0, 0.0, 0.0);         // black background 
	glMatrixMode(GL_PROJECTION);              // setup viewing projection 
	glLoadIdentity();                           // start with identity matrix 
	glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
