#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<time.h>


int xmi,xma,ymi,yma;
int xmin=-100;
int xmax=100;
int ymin=-100;
int ymax=100;

int cut;

void display1()
{
glColor3f(0.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
glVertex2i(xmin,ymin);
glVertex2i(xmax,ymin);
glVertex2i(xmax,ymax);
glVertex2i(xmin,ymax);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(xmi,ymi);
glVertex2i(xma,ymi);
glVertex2i(xma,yma);
glVertex2i(xmi,yma);
glEnd();
glFlush();
}
void clip(void)
{

    while(xmi<xmin|xma>xmax|ymi<ymin|yma>ymax)
{
if(xmi<xmin)
{
cut=xmin-xmi;
xmi=xmi+cut;
}
else if(xma>xmax)
{
cut=xma-xmax;
xma=xma-cut;
}
else if(ymi<ymin)
{
cut=ymin-ymi;
ymi=ymi+cut;
}
else if(yma>ymax)
{
cut=yma-ymax;
yma=yma-cut;
}

}
}
void delay(float secs)
{
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}
void display()
{
    display1();
    clip();
    delay(3);
    display1();
}
void init(void)
{

    glClearColor(0.0,0,0,0);
    gluOrtho2D(-300,300,-300,300);

}

int main(int argc,char *argv[])
{

   glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    printf("enter the points for left bottom of polygon:");
    scanf("%d%d",&xmi,&ymi);
    printf("Enter the points for right up of the polygon:");
    scanf("%d%d",&xma,&yma);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return (0);
}
