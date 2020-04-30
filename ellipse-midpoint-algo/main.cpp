#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define ROUND(a)((int)(a+0.5));

int xc = 320, yc = 240;
// Plot four points using ellipse symmetrical property
void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc-x, yc-y);
  glEnd();
}

void ellipsemidpoint(int rx, int ry)
{
    int rx2=rx*rx;
    int ry2=ry*ry;
    int tworx2= 2*rx2;
    int twory2=2*ry2;
    int p,x=0,y=ry,px=0;
    int py=tworx2*y;
    //plot the first point
    plot_point(x,y);
    //drawing of region 1
    p=ROUND (ry2-(rx2*ry)+(0.25*rx2));
    while(px<py)
    {
        x++;
        px=px+twory2;
        if(p<0)
        {
            p=p+ry2+px;
        }
        else
        {
            y--;
            py=py-tworx2;
            p=p+ry2+px-py;

        }
        plot_point(x,y);
    }


// drawing of region2
p=ROUND(ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2);
while(y>0)
{
    y--;
    py=py-tworx2;
    if(p>0)
        p=p+rx2-py;
    else
    {
        x++;
        px=px+twory2;
        p=p+rx2-py+px;
    }
    plot_point(x,y);
}
  glFlush();
}

void Midpointellipse(void)
{
  /* Clears buffers to preset values */
  glClear(GL_COLOR_BUFFER_BIT);

  int radius1 = 200, radius2 = 100;
 ellipsemidpoint(radius1,radius2);
}

void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
  /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Midpoint_Ellipse");
  /* Initialize drawing colors */
  Init();
  /* Call the displaying function */
  glutDisplayFunc(Midpointellipse);
  /* Keep displaying untill the program is closed */
  glutMainLoop();
  return(0);
}
