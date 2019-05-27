/**
 * This is an extremely simple and clean demo showing the basics of OpenGL and glut.
 * You can use this project as a starting point to create your own OpenGL application.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

// Constants to define the width/height of the window
const int WIDTH = 800;
const int HEIGHT = 800;

void curva(){
	glBegin(GL_POINTS);
		/*glColor3f(1,1,1);	glVertex2f(-2.0,-1.0);
		glColor3f(1,1,1); 	glVertex2f(-1.5,4.0);
		glColor3f(1,1,1);	glVertex2f(2.0,4.0);
		glColor3f(1,1,1);	glVertex2f(3.0,-1.5);*/
		double x0 = -2.0, x1 = -1.5 , x2 = 2.0 , x3 = 3.0, y0 = -1.0 ,y1 =4.0 , y2 = 4 , y3 = -1.5 ;

		for (double t = 0; t < 1; t+=0.001)
		{
			glVertex2f((((1-t)*(1-t)*(1-t)*x0) + (3*t*(1-t)*(1-t)*x1) + (3*t*(1-t)*x2) + t*t*t *x3),     (((1-t)*(1-t)*(1-t)*y0) + (3*t*(1-t)*(1-t)*y1) + (3*t*(1-t)*y2) + t*t*t *y3));
		}


	glEnd();



}

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-10.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -10.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it with the white color
	glClearColor(0.5, 0.5, 0.5, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -10.0f);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a red square
	//        R  G  B
	/*glColor3f(1, 0, 0);
	//        x1    y1    x2     y2
	glRectf(-1.0f, 1.0f, 1.0f, -1.0f);

	// Start the rendering on a new frame*/
	curva();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	glutMainLoop();
	return 0;
}