#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
GLfloat base[][2]={{130.0,-120.0},{180.0,-175.0},{480.0,-175.0},{480.0,-120.0}};
GLint body1[][2]={{235,-60},{235,-120},{460,-120},{460,-40},{410,-40},{410,-65},{390,-65},{390,-90},{280,-90},{280,-60}};
void display()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glColor3f(0.2,0.2,0.2);
		for(i=0;i<4;i++)
		glVertex2fv(base[i]);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0.4,0.4,0.4);
		for(i=0;i<10;i++)
		glVertex2iv(body1[i]);
	glEnd();
	glFlush();
}
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0,500.0,-300.0,300.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutCreateWindow("Destroyer");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
