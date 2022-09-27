#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
int p;
void static_rocket();
void rocket_to_cam_pos();

float i,j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0;

// function to display the text content of the home screen
void drawstring(int x, int y, char *s)
{
    char *c;
    glRasterPos2i(x, y);
    for (c = s; *c != '\0'; *c++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
}

//determines the state of rocket launch
void control()
{
    count1++; //unlimited
    if(count1==250)
        flag=1;

    else if (flag == 1 && (count1 == 600 || count1 == 601))
        rocket_to_cam_pos();
}

void static_rocket()
{

    count1++;
    if(count1==150)
        flag=1;

}
void rocket_to_cam_pos()
{

  //  for(i=0; i<=200; i++)
  //  {

        glClearColor(0.0,0.0,1.0,0.0);// rocket background
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glColor3f(0.8,0.498039,19.196078);
        glBegin(GL_POLYGON);//core body
        glVertex2f(237.5,20.0+i);
        glVertex2f(262.5,20.0+i);
        glVertex2f(262.5,120.0+i);
        glVertex2f(237.5,120.0+i);


        glEnd();

        glColor3f(1.0,1.0,1.0);//bonnet
        glBegin(GL_POLYGON);//front
        glVertex2f(237.5,120.0+i);
        glVertex2f(262.5,120.0+i);
        glVertex2f(250,170.0+i);
        glEnd();
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);//left_side_top
        glVertex2f(237.5,120.0+i);
        glVertex2f(217.5,95.0+i);
        glVertex2f(237.5,95.0+i);
        glEnd();
        glBegin(GL_POLYGON);//left_side_bottom
        glVertex2f(237.5,20.0+i);
        glVertex2f(217.5,20.0+i);
        glVertex2f(237.5,70.0+i);
        glEnd();
        glBegin(GL_POLYGON);//right_side_bottom
        glVertex2f(262.5,20.0+i);
        glVertex2f(282.5,20.0+i);
        glVertex2f(262.5,70.0+i);
        glEnd();
        glBegin(GL_POLYGON);//right_side_top
        glVertex2f(262.5,120.0+i);
        glVertex2f(262.5,95.0+i);
        glVertex2f(282.5,95.0+i);
        glEnd();

        if((p%2)==0)
            glColor3f(1.0,0.25,0.0);
        else
            glColor3f(1.0,0.816,0.0);

        glBegin(GL_POLYGON);//outer fume
        glVertex2f(237.5,20+i);
        glVertex2f(234.16,16.66+i);
        glVertex2f(230.82,13.32+i);
        glVertex2f(227.48,9.98+i);
        glVertex2f(224.14,6.64+i);
        glVertex2f(220.8,3.3+i);
        glVertex2f(217.5,0+i);
        glVertex2f(221.56,-5+i);
        glVertex2f(225.62,-10+i);
        glVertex2f(229.68,-15+i);
        glVertex2f(233.74,-20+i);
        glVertex2f(237.8,-25+i);
        glVertex2f(241.86,-30+i);
        glVertex2f(245.92,-35+i);
        glVertex2f(250,-40+i);
        glVertex2f(254.06,-35+i);
        glVertex2f(258.12,-30+i);
        glVertex2f(262.18,-25+i);
        glVertex2f(266.24,-20+i);
        glVertex2f(270.3,-15+i);
        glVertex2f(274.36,-10+i);
        glVertex2f(278.42,-5+i);
        glVertex2f(282.5,0+i);
        glVertex2f(278.5,4+i);
        glVertex2f(274.5,8+i);
        glVertex2f(270.5,12+i);
        glVertex2f(266.5,16+i);
        glVertex2f(262.5,20+i);//28 points
        glEnd();

        if((p%2)==0)
            glColor3f(1.0,0.816,0.0);
        else
            glColor3f(1.0,0.25,0.0);

        glBegin(GL_POLYGON);//inner fume
        glVertex2f(237.5,20+i);
        glVertex2f(236.5,17.5+i);
        glVertex2f(235.5,15+i);
        glVertex2f(234.5,12.5+i);
        glVertex2f(233.5,10+i);
        glVertex2f(232.5,7.5+i);
        glVertex2f(236,5+i);
        glVertex2f(239.5,2.5+i);
        glVertex2f(243,0+i);
        glVertex2f(246.5,-2.5+i);
        glVertex2f(250,-5+i);
        glVertex2f(253.5,-2.5+i);
        glVertex2f(257,0+i);
        glVertex2f(260.5,2.5+i);
        glVertex2f(264,5+i);
        glVertex2f(267.5,7.5+i);
        glVertex2f(266.5,10+i);
        glVertex2f(265.5,12.5+i);
        glVertex2f(264.5,15+i);
        glVertex2f(263.5,17.5+i);
        glVertex2f(262.5,20+i);//21 points

        glEnd();
    //    p=p+1;
    //    for(j=0; j<=1000000; j++)
            ;
        glutSwapBuffers();
  //  }
}
//keys that trigger manual Launch
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'S' || key == 's')
    {
        for(int i=0; i<100; i++)
            static_rocket();
        flag = 1;
    }
    if (key == 'Q' || key == 'q')
        exit(0);
}

//design of homescreen
void page()
{
    glColor3f(1, 1, 1);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glVertex2d(75, 425);
    glVertex2d(375, 425);
    glVertex2d(375, 325);
    glVertex2d(75, 325);
    glEnd();

    drawstring(100, 400, "ROCKET LAUNCHING SIMULATION");
    drawstring(100, 380, "TEAM : OTAKUS");

    glBegin(GL_LINE_LOOP);
    glVertex2d(75, 75);
    glVertex2d(375, 75);
    glVertex2d(375, 225);
    glVertex2d(75, 225);
    glEnd();

    drawstring(100, 200, "INSTRUCTIONS");
    drawstring(100, 180, "Press S to START");
    drawstring(100, 140, "Press Q to quit");
}
//display all components
void display()
{
    if (flag == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        page();
        glutSwapBuffers();
    }
    else
        control();
}
void myinit()
{
    glClearColor(0.196078,0.6,2.8,1.0);
    glPointSize(1.0);
    gluOrtho2D(0.0,499.0,0.0,499.0);
}
int main(int argc,char*argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("rocket");
    myinit();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
