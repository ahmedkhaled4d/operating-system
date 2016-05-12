#include <windows.h>

#include <math.h>

#include<gl/glut.h>

#include<gl/glu.h>

#include<gl/gl.h>

bool state=false;

float p=0;

float TO_RAD(int t)

{

	return (t*3.14)/180.0;

}

void semicircle(float pos,int x,int y,float radius, float r,float g, float b){  

	

	float rad;  

	int theta;  

	

	glColor3f(r, g, b);   

	glBegin(GL_POLYGON);  

	for(theta=x; theta<=y;theta++)  

	{  

		rad=TO_RAD(theta);  

		glVertex2f( radius*cos(rad)+pos,radius*sin(rad));    

	}  

	glEnd();  

}

void circle(float radius, float r,float g, float b){  

	

	float rad;  

	int theta;  

	

	glColor3f(r, g, b);   

	glBegin(GL_POLYGON);  

	for(theta=0; theta<360; theta++)  

	{  

		rad=TO_RAD(theta);  

		glVertex2f(radius*cos(rad), radius*sin(rad));    

	}  

	glEnd();  

	

} 

void PacMan(bool s)

{

	semicircle(p,s*30,180,.2,1,0,1);

	semicircle(p,-180,s*-30,.2,1,0,0);

}

void render(void) 

{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    

  glLoadIdentity();  

  glTranslatef(0,0,-1);

  PacMan(!state);

 glutSwapBuffers() ;

 state=!state;

 p+=.03;

 Sleep(500);

}

void main(int argc, char **argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowPosition(100,100);

    glutInitWindowSize(500,500);

    glutCreateWindow("test");

    glutDisplayFunc(render);

    glutIdleFunc(render);

    glutMainLoop();

}
