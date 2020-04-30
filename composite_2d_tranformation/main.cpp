#include<windows.h>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

int deg,i,j,k;

float initMatrix[3][4]={{100,200,200,100},{100,100,200,200},{1,1,1,1}};
float pt1Matrix[3][3]={{1,0,50},{0,1,50},{0,0,1}};
float pt2Matrix[3][3]={{1,0,-50},{0,1,-50},{0,0,1}};
float t[3][3]={{0,0,0},{0,0,0},{0,0,0}}; // T
float result[3][4]; // T

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
}

void rotation()
{
    double theta=(deg*3.14159)/180;
    double cos1=cos(theta),sin1=sin(theta);
    double temp[3][3];
    double rotationFactor[3][3]={{cos1,-sin1,0},{sin1,cos1,0},{0,0,1}};
    glColor3f(1.0,1.0,1.0);

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            temp[i][j]=0.0;
            for(k=0;k<3;k++)
            {
                temp[i][j]=temp[i][j]+pt1Matrix[i][k]*rotationFactor[k][j];
            }
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            t[i][j]=0.0;
            for(k=0;k<3;k++)
            {
                t[i][j]=t[i][j]+temp[i][k]*pt2Matrix[k][j];
            }
        }
    }

}

void composite(){

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            for(k=0;k<3;k++)
            {
                result[i][j]=result[i][j]+t[i][k]*initMatrix[k][j];
                printf("%f\n",result[i][j]);
            }
        }
    }


    glColor3f(2.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(i=0;i<4;i++)
        glVertex2d(initMatrix[0][i],initMatrix[1][i]);
    glEnd();

glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(i=0;i<4;i++)
        glVertex2d(result[0][i],result[1][i]);
    glEnd();

    glFlush();


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    deg=10;
    rotation();
    composite();
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);
    glutCreateWindow("Square");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
