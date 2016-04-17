
#include <GL/freeglut.h>
#include <time.h>
#include <cmath>
 
class reflector{
public:
	float x, y;
	float vy;
	float size;
	bool Up, Down, hold;
	reflector(){
		vy = 0;
		y = 0;
		Up = false;
		Down = false;
		hold = false;
	} 
}left, right;

class square{
public:
	float x;
	float y;
	float vx;
	float vy;
	void move();
	void reflection();
	void draw();
}square;

class game{
public:
	int OrthoWid;
	int OrthoHei;
	int WinWid;
	int WinHei;
	int winXPos;
	int winYPos; 
	int delay;
	float PThickness;
	float SquareSize;
	float SquareSpeedX;
	float PSpeedY;
	game(){
		WinWid = 700;
		WinHei = 500;
		OrthoWid = 700;
		OrthoHei = 500;
		delay = 1;
		PThickness = 1; //border thickness
		SquareSize = 60;
		SquareSpeedX = 0.5;
		PSpeedY = 1;
	}
	void start();  
}settings;

// implementation level 

void game::start(){
	 
	left.x = -610;
	right.x = 610;
	while (square.vx == 0)square.vx = (rand() % 3 - 1)*SquareSpeedX;
	square.vy = 0;
	square.x = 0;
	square.y = 0;
}
 
void square::reflection(){
	//if ((y <= settings.FieldSizeY) || (y >= settings.FieldSizeY))vy = -vy;
	// reflect left directions
	if ((x <= left.x + settings.PThickness) && (fabs(double(y - left.y)) <= left.size / 2 + fabs(vy))){
		vx = -vx;
		vy += left.vy;
	}
	 
	// reflect right directions
	if ((x >= right.x - settings.PThickness) && (fabs(double(y - right.y)) <= right.size / 2 + fabs(vy))){
		vx = -vx;
		vy += right.vy;
	}
}

void square::draw(){
	glVertex2f(x + settings.SquareSize, y + settings.SquareSize);
	glVertex2f(x + settings.SquareSize, y - settings.SquareSize);
	glVertex2f(x - settings.SquareSize, y - settings.SquareSize);
	glVertex2f(x - settings.SquareSize, y + settings.SquareSize);
}

void square::move(){
	x += vx;
	y += vy;
}

void Timer(int value){ 
	square.move();
	square.reflection();
	glutPostRedisplay();
	glutTimerFunc(settings.delay, Timer, 0);
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	square.draw();
	glEnd(); 
	glutSwapBuffers();
}

int main(int argc, char ** argv){
	srand(time(NULL));
	settings.start();  // init games frist
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(settings.WinWid, settings.WinHei);
	glutInitWindowPosition(settings.winXPos, settings.winYPos);
	glutCreateWindow("Moving Square");
	glutDisplayFunc(draw);
	glutTimerFunc(settings.delay, Timer, 0);
	//glutKeyboardFunc(keyboard);
	//glutKeyboardUpFunc(keyboardUp);
	glClearColor(.6, 1, .6, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-settings.OrthoWid, settings.OrthoWid, -settings.OrthoHei, settings.OrthoHei);
	glutMainLoop();
	return(0);
}
