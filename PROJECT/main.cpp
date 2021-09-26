#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
# define PI 3.14159265358979323846
using namespace std;

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

GLfloat pa =10, qa=100;
int qflag =1, pflag=1;
//////cloud moving
GLfloat skyposition = 0.0;
GLfloat skyposition1 = 0.0;
GLfloat speed = 2;
GLfloat speed0 = 4;
////////////bird
 GLfloat birdposition1 = -500;
GLfloat birdspeed = 4;
GLfloat manmoving=0;
GLfloat manspeed =2;
GLfloat speed1 = 1;
GLfloat watermoves = 0.0;
GLfloat watermoves1 = 0.0;


GLfloat rain = 1;
bool rainday = false;

void init(){

	glClearColor(1,1,1,1);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(-1000,1000,-1000,1000);

}

void update(int value) {


    if(skyposition >1000)


          skyposition = -1000;

          skyposition += speed;




    glutPostRedisplay();

      if(skyposition1 >1000)


          skyposition1 = -2000;

          skyposition1 += speed0;




    glutPostRedisplay();

     if(birdposition1 >300)


          birdposition1 = -500;

          birdposition1 += birdspeed;




    glutPostRedisplay();



	if (watermoves >15)
           watermoves = -15;
           watermoves += speed1;



    glutPostRedisplay();

    if (watermoves1 >1)
           watermoves1 = -1;
           watermoves1 += speed;



    glutPostRedisplay();



    if (manmoving >100)
           manmoving = -800;
           manmoving+= manspeed;



    glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}


void flagupdate ()

{

    if (qa>-100 && qflag==1)
        qa=qa-0.2;
    if (qa<=-100 && qflag==1)
        qflag =0;
    if (qa<100 && qflag ==0)
        qa=qa+0.2;
    if(qa>=100 && qflag==0)
        qflag=1;
    if (pa>-10 && pflag==1)
        pa=pa-0.2;
    if (pa<=-10 && pflag==1)
        pflag =0;
    if (pa<10 && pflag ==0)
        pa=pa+0.2;
    if(pa>=10 && pflag==0)
        pflag=1;

    glutPostRedisplay();

}

void circle(GLdouble x, GLdouble y, GLdouble radius, GLdouble triangleAmount,GLdouble  m,GLdouble n,GLdouble o)
{
    GLfloat twicePi = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(m,n,o);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)));

    }
    glEnd();
}

void monuent()
{
    ///////monument//////////
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex2d(-300,100);
    glVertex2d(0,900);
    glVertex2d(300,100);
    glVertex2d(-300,100);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(220,220,220);
    glVertex2d(-210,100);
    glVertex2d(0,900);
    glVertex2d(210,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex2d(-125,100);
    glVertex2d(0,900);
    glVertex2d(125,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(192,192,192);
    glVertex2d(-60,100);
    glVertex2d(0,900);
    glVertex2d(60,100);
    glEnd();
// Inside Shape
    glBegin(GL_POLYGON);
    glColor3ub(220,220,220);
    glVertex2d(0,900);
    glVertex2d(-25,450);
    glVertex2d(0,100);
    glVertex2d(25,450);
    glVertex2d(0,900);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2d(-25,445);
    glVertex2d(-25,455);
    glVertex2d(25,455);
    glVertex2d(25,445);
    glEnd();

    //flag///////ppppppiiiiiiiiuuuuuuuuuuuuuu////

       glColor3ub(0,102,0);
      GLfloat p[4],q1[4],q2[4];
      GLdouble pt[200],q1t[200],q2t[200],t;
      int i;
      p[0]=210; p[1]=325; p[2]=325; p[3]=440-pa;
      q1[0]=700; q1[1]=700+qa; q1[2]=700-qa; q1[3]=700;
      q2[0]=440; q2[1]=440+qa; q2[2]=440-qa; q2[3]=440;
      for (i=0,t=0;t<1;i++,t=t+0.01)

      {
          pt[i]=pow(1-t,3)*p[0]+3*t*pow(1-t,2)*p[1]+3*pow(t,2)*(1-t)*p[2]+pow(t,3)*p[3];
          q1t[i]=pow(1-t,3)*q1[0]+3*t*pow(1-t,2)*q1[1]+3*pow(t,2)*(1-t)*q1[2]+pow(t,3)*q1[3];
          q2t[i]=pow(1-t,3)*q2[0]+3*t*pow(1-t,2)*q2[1]+3*pow(t,2)*(1-t)*q2[2]+pow(t,3)*q2[3];

      }
      glEnd();
      glPointSize(3);
      glBegin(GL_QUAD_STRIP);
      for (i=0;i<100;i++)
      {
          glVertex2d(pt[i],q1t[i]);
           glVertex2d(pt[i],q2t[i]);

      }
      glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2d(200,100);
    glVertex2d(200,750);
    glVertex2d(210,750);
    glVertex2d(210,100);
    glEnd();

     circle(330, 560, 50, 100, 255,0,0);
     flagupdate();
    ////////flag end

}

void flower()
{
     //////
    //flower//
    circle(50, 50, 50, 100, 255,255,0);
    circle(150, 50, 50, 100, 127,255,0);
    circle(250, 50, 50, 100, 255,69,0);
    circle(350, 50, 50, 100, 0,0,139);
     circle(450, 50, 50, 100, 0,100,0);
     circle(550, 50, 50, 100, 0,250,154);
      circle(650, 50, 50, 100, 139,69,19);
      circle(750, 50, 50, 100, 255,0,0);
      circle(850, 50, 50, 100, 255,255,0);
       circle(950, 50, 50, 100, 255,69,0);
// Inner Circle

   circle(50, 50, 20, 100, 0,0,0);
circle(150, 50, 20, 100, 255,140,0);
circle(250, 50, 20, 100, 255,215,0);
circle(350, 50, 20, 100, 128,0,0);
circle(450, 50, 20, 100, 1,0,0);
circle(550, 50, 20, 100, 128,0,128);
circle(650, 50, 20, 100, 0,0,128);
circle(750, 50, 20, 100, 255,20,147);
circle(850, 50, 20, 100, 255,165,0);
circle(950, 50, 20, 100, 153,50,204);

circle(-50, 50, 50, 100, 255,20,147);
circle(-150, 50, 50, 100, 127,255,0);
circle(-250, 50, 50, 100, 255,69,0);
circle(-350, 50, 50, 100, 0,0,139);
circle(-450, 50, 50, 100, 0,100,0);
circle(-550, 50, 50, 100, 0,250,154);
circle(-650, 50, 50, 100, 139,69,19);
circle(-750, 50, 50, 100, 255,0,0);
circle(-850, 50, 50, 100, 255,255,0);
circle(-950, 50, 50, 100, 255,69,0);

// Inner Circle
circle(-50, 50, 20, 100, 250,235,215);
circle(-150, 50, 20, 100, 255,140,0);
circle(-250, 50, 20, 100, 255,215,0);
circle(-350, 50, 20, 100, 0,255,255);
circle(-450, 50, 20, 100, 0,255,0);
circle(-550, 50, 20, 100, 0,100,0);
circle(-650, 50, 20, 100, 0,0,128);
circle(-750, 50, 20, 100, 255,255,0);
circle(-850, 50, 20, 100, 25,25,112);
circle(-950, 50, 20, 100, 153,50,204);

}
void bird ()
{
    ////////birds/////
    // Green Bird
      glPushMatrix();
    glTranslated(birdposition1,birdposition1,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(843,729);
    glVertex2d(836,726);
    glVertex2d(829,722);
    glVertex2d(821,723);
    glVertex2d(804,730);
    glVertex2d(803,731);
    glVertex2d(801,728);
    glVertex2d(827,716);
    glVertex2d(865,708);
    glVertex2d(881,715);
    glVertex2d(885,717);
    glVertex2d(886,720);
    glVertex2d(886,724);
    glVertex2d(885,727);
    glVertex2d(883,729);
    glVertex2d(878,729);
    glVertex2d(869,727);
    glVertex2d(860,731);
    glEnd();
    // Wing
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(844,729);
    glVertex2d(862,730);
    glVertex2d(859,737);
    glVertex2d(858,748);
    glVertex2d(863,760);
    glVertex2d(871,777);
    glVertex2d(872,783);
    glVertex2d(871,785);
    glVertex2d(859,777);
    glVertex2d(851,772);
    glVertex2d(840,762);
    glVertex2d(836,753);
    glVertex2d(835,743);
    glVertex2d(839,734);
    glEnd();
    //Birds Eye
    glBegin(GL_QUADS);
    glColor3ub (64,64,64);
    glVertex2d(874,726);
    glVertex2d(880,720);
    glVertex2d(880,726);
    glVertex2d(874,720);
    glEnd();



    // Red Bird
    glBegin(GL_POLYGON);
    glColor3ub(51,51,255);
    glVertex2d(743,629);
    glVertex2d(736,626);
    glVertex2d(729,622);
    glVertex2d(721,623);
    glVertex2d(704,630);
    glVertex2d(703,631);
    glVertex2d(701,628);
    glVertex2d(727,616);
    glVertex2d(765,608);
    glVertex2d(781,615);
    glVertex2d(785,617);
    glVertex2d(786,620);
    glVertex2d(786,624);
    glVertex2d(785,627);
    glVertex2d(783,629);
    glVertex2d(778,629);
    glVertex2d(769,627);
    glVertex2d(760,631);
    glEnd();
    // Wing
    glBegin(GL_POLYGON);
    glColor3ub(51,51,255);
    glVertex2d(744,629);
    glVertex2d(762,630);
    glVertex2d(759,637);
    glVertex2d(758,648);
    glVertex2d(763,660);
    glVertex2d(771,677);
    glVertex2d(772,683);
    glVertex2d(771,685);
    glVertex2d(759,677);
    glVertex2d(751,672);
    glVertex2d(740,662);
    glVertex2d(736,653);
    glVertex2d(735,643);
    glVertex2d(739,634);
    glEnd();
    //Birds Eye
    glBegin(GL_QUADS);
    glColor3ub (0,0,0);
    glVertex2d(774,626);
    glVertex2d(780,620);
    glVertex2d(780,626);
    glVertex2d(774,620);
    glEnd();



    // Holudia Bird
     glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(743,829);
    glVertex2d(736,826);
    glVertex2d(729,822);
    glVertex2d(721,823);
    glVertex2d(704,830);
    glVertex2d(703,831);
    glVertex2d(701,828);
    glVertex2d(727,816);
    glVertex2d(765,808);
    glVertex2d(781,815);
    glVertex2d(785,817);
    glVertex2d(786,820);
    glVertex2d(786,824);
    glVertex2d(785,827);
    glVertex2d(783,829);
    glVertex2d(778,829);
    glVertex2d(769,827);
    glVertex2d(760,831);
    glEnd();
    // Wing
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(744,829);
    glVertex2d(762,830);
    glVertex2d(759,837);
    glVertex2d(758,848);
    glVertex2d(763,860);
    glVertex2d(771,877);
    glVertex2d(772,883);
    glVertex2d(771,885);
    glVertex2d(759,877);
    glVertex2d(751,872);
    glVertex2d(740,862);
    glVertex2d(736,853);
    glVertex2d(735,843);
    glVertex2d(739,834);
    glEnd();
    //Birds Eye
    glBegin(GL_QUADS);
    glColor3ub (0,0,0);
    glVertex2d(774,826);
    glVertex2d(780,820);
    glVertex2d(780,826);
    glVertex2d(774,820);
    glEnd();
    glPopMatrix();

}
void brick()
{


     /////1
     glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(500,0);
	glVertex2d(500,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub		(218,165,32);//2
	glVertex2d(700,0);
	glVertex2d(700,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-0);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(700,0);
	glVertex2d(700,-100);
	glVertex2d(800,-100);
	glVertex2d(800,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(800,0);
	glVertex2d(800,-100);
	glVertex2d(900,-100);
	glVertex2d(900,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(900,0);
	glVertex2d(900,-100);
	glVertex2d(1000,-100);
	glVertex2d(1000,-0);
	glEnd();


	///////2
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(500,-200);
	glVertex2d(500,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(700,-200);
	glVertex2d(700,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(700,-200);
	glVertex2d(700,-100);
	glVertex2d(800,-100);
	glVertex2d(800,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(800,-200);
	glVertex2d(800,-100);
	glVertex2d(900,-100);
	glVertex2d(900,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(900,-200);
	glVertex2d(900,-100);
	glVertex2d(1000,-100);
	glVertex2d(1000,-200);
	glEnd();


	////////////////////3

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(500,-300);
	glVertex2d(500,-200);
	glVertex2d(600,-200);
	glVertex2d(600,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(700,-300);
	glVertex2d(700,-200);
	glVertex2d(600,-200);
	glVertex2d(600,-300);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(700,-300);
	glVertex2d(700,-200);
	glVertex2d(800,-200);
	glVertex2d(800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(800,-300);
	glVertex2d(800,-200);
	glVertex2d(900,-200);
	glVertex2d(900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(900,-300);
	glVertex2d(900,-200);
	glVertex2d(1000,-200);
	glVertex2d(1000,-300);
	glEnd();


	////////////////4
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(500,-300);
	glVertex2d(500,-400);
	glVertex2d(600,-400);
	glVertex2d(600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(700,-300);
	glVertex2d(700,-400);
	glVertex2d(600,-400);
	glVertex2d(600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(700,-300);
	glVertex2d(700,-400);
	glVertex2d(800,-400);
	glVertex2d(800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(800,-300);
	glVertex2d(800,-400);
	glVertex2d(900,-400);
	glVertex2d(900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(900,-300);
	glVertex2d(900,-400);
	glVertex2d(1000,-400);
	glVertex2d(1000,-300);
	glEnd();

	////////////////////5
	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(500,-400);
	glVertex2d(500,-500);
	glVertex2d(600,-500);
	glVertex2d(600,-400);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(700,-400);
	glVertex2d(700,-500);
	glVertex2d(600,-500);
	glVertex2d(600,-400);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(700,-500);
	glVertex2d(700,-400);
	glVertex2d(800,-400);
	glVertex2d(800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(800,-500);
	glVertex2d(800,-400);
	glVertex2d(900,-400);
	glVertex2d(900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(900,-400);
	glVertex2d(900,-500);
	glVertex2d(1000,-500);
	glVertex2d(1000,-400);
	glEnd();


	////////////////6
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(500,-500);
	glVertex2d(500,-600);
	glVertex2d(600,-600);
	glVertex2d(600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(700,-500);
	glVertex2d(700,-600);
	glVertex2d(600,-600);
	glVertex2d(600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(700,-500);
	glVertex2d(700,-600);
	glVertex2d(800,-600);
	glVertex2d(800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(800,-500);
	glVertex2d(800,-600);
	glVertex2d(900,-600);
	glVertex2d(900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(900,-500);
	glVertex2d(900,-600);
	glVertex2d(1000,-600);
	glVertex2d(1000,-500);
	glEnd();
////////////////////7
glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(500,-600);
	glVertex2d(500,-700);
	glVertex2d(600,-700);
	glVertex2d(600,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(700,-600);
	glVertex2d(700,-700);
	glVertex2d(600,-700);
	glVertex2d(600,-600);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(700,-600);
	glVertex2d(700,-700);
	glVertex2d(800,-700);
	glVertex2d(800,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(800,-600);
	glVertex2d(800,-700);
	glVertex2d(900,-700);
	glVertex2d(900,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(900,-600);
	glVertex2d(900,-700);
	glVertex2d(1000,-700);
	glVertex2d(1000,-600);
	glEnd();


	////////////////8
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(500,-700);
	glVertex2d(500,-800);
	glVertex2d(600,-800);
	glVertex2d(600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(700,-700);
	glVertex2d(700,-800);
	glVertex2d(600,-800);
	glVertex2d(600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(700,-700);
	glVertex2d(700,-800);
	glVertex2d(800,-800);
	glVertex2d(800,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(800,-700);
	glVertex2d(800,-800);
	glVertex2d(900,-800);
	glVertex2d(900,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(900,-700);
	glVertex2d(900,-800);
	glVertex2d(1000,-800);
	glVertex2d(1000,-700);
	glEnd();

	///////////9
	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(500,-800);
	glVertex2d(500,-900);
	glVertex2d(600,-900);
	glVertex2d(600,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(700,-800);
	glVertex2d(700,-900);
	glVertex2d(600,-900);
	glVertex2d(600,-800);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(700,-800);
	glVertex2d(700,-900);
	glVertex2d(800,-900);
	glVertex2d(800,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(800,-800);
	glVertex2d(800,-900);
	glVertex2d(900,-900);
	glVertex2d(900,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(900,-800);
	glVertex2d(900,-900);
	glVertex2d(1000,-900);
	glVertex2d(1000,-800);
	glEnd();


	////////////////10
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(500,-900);
	glVertex2d(500,-1000);
	glVertex2d(600,-1000);
	glVertex2d(600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(700,-900);
	glVertex2d(700,-1000);
	glVertex2d(600,-1000);
	glVertex2d(600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(700,-900);
	glVertex2d(700,-1000);
	glVertex2d(800,-1000);
	glVertex2d(800,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(800,-900);
	glVertex2d(800,-1000);
	glVertex2d(900,-1000);
	glVertex2d(900,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(900,-900);
	glVertex2d(900,-1000);
	glVertex2d(1000,-1000);
	glVertex2d(1000,-900);
	glEnd();

	/////////left

	     glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-500,0);
	glVertex2d(-500,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub		(218,165,32);//2
	glVertex2d(-700,0);
	glVertex2d(-700,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-0);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-700,0);
	glVertex2d(-700,-100);
	glVertex2d(-800,-100);
	glVertex2d(-800,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-800,0);
	glVertex2d(-800,-100);
	glVertex2d(-900,-100);
	glVertex2d(-900,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-900,0);
	glVertex2d(-900,-100);
	glVertex2d(-1000,-100);
	glVertex2d(-1000,-0);
	glEnd();


	///////2
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-500,-200);
	glVertex2d(-500,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-700,-200);
	glVertex2d(-700,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-700,-200);
	glVertex2d(-700,-100);
	glVertex2d(-800,-100);
	glVertex2d(-800,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-800,-200);
	glVertex2d(-800,-100);
	glVertex2d(-900,-100);
	glVertex2d(-900,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-900,-200);
	glVertex2d(-900,-100);
	glVertex2d(-1000,-100);
	glVertex2d(-1000,-200);
	glEnd();


	////////////////////3

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-500,-300);
	glVertex2d(-500,-200);
	glVertex2d(-600,-200);
	glVertex2d(-600,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-700,-300);
	glVertex2d(-700,-200);
	glVertex2d(-600,-200);
	glVertex2d(-600,-300);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-700,-300);
	glVertex2d(-700,-200);
	glVertex2d(-800,-200);
	glVertex2d(-800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-800,-300);
	glVertex2d(-800,-200);
	glVertex2d(-900,-200);
	glVertex2d(-900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-900,-300);
	glVertex2d(-900,-200);
	glVertex2d(-1000,-200);
	glVertex2d(-1000,-300);
	glEnd();


	////////////////4
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-500,-300);
	glVertex2d(-500,-400);
	glVertex2d(-600,-400);
	glVertex2d(-600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-700,-300);
	glVertex2d(-700,-400);
	glVertex2d(-600,-400);
	glVertex2d(-600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-700,-300);
	glVertex2d(-700,-400);
	glVertex2d(-800,-400);
	glVertex2d(-800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-800,-300);
	glVertex2d(-800,-400);
	glVertex2d(-900,-400);
	glVertex2d(-900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-900,-300);
	glVertex2d(-900,-400);
	glVertex2d(-1000,-400);
	glVertex2d(-1000,-300);
	glEnd();

	////////////////////5
	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-500,-400);
	glVertex2d(-500,-500);
	glVertex2d(-600,-500);
	glVertex2d(-600,-400);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-700,-400);
	glVertex2d(-700,-500);
	glVertex2d(-600,-500);
	glVertex2d(-600,-400);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-700,-500);
	glVertex2d(-700,-400);
	glVertex2d(-800,-400);
	glVertex2d(-800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-800,-500);
	glVertex2d(-800,-400);
	glVertex2d(-900,-400);
	glVertex2d(-900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-900,-400);
	glVertex2d(-900,-500);
	glVertex2d(-1000,-500);
	glVertex2d(-1000,-400);
	glEnd();


	////////////////6
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-500,-500);
	glVertex2d(-500,-600);
	glVertex2d(-600,-600);
	glVertex2d(-600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-700,-500);
	glVertex2d(-700,-600);
	glVertex2d(-600,-600);
	glVertex2d(-600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-700,-500);
	glVertex2d(-700,-600);
	glVertex2d(-800,-600);
	glVertex2d(-800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-800,-500);
	glVertex2d(-800,-600);
	glVertex2d(-900,-600);
	glVertex2d(-900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-900,-500);
	glVertex2d(-900,-600);
	glVertex2d(-1000,-600);
	glVertex2d(-1000,-500);
	glEnd();
////////////////////7
glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-500,-600);
	glVertex2d(-500,-700);
	glVertex2d(-600,-700);
	glVertex2d(-600,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-700,-600);
	glVertex2d(-700,-700);
	glVertex2d(-600,-700);
	glVertex2d(-600,-600);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-700,-600);
	glVertex2d(-700,-700);
	glVertex2d(-800,-700);
	glVertex2d(-800,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-800,-600);
	glVertex2d(-800,-700);
	glVertex2d(-900,-700);
	glVertex2d(-900,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-900,-600);
	glVertex2d(-900,-700);
	glVertex2d(-1000,-700);
	glVertex2d(-1000,-600);
	glEnd();


	////////////////8
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-500,-700);
	glVertex2d(-500,-800);
	glVertex2d(-600,-800);
	glVertex2d(-600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-700,-700);
	glVertex2d(-700,-800);
	glVertex2d(-600,-800);
	glVertex2d(-600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-700,-700);
	glVertex2d(-700,-800);
	glVertex2d(-800,-800);
	glVertex2d(-800,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-800,-700);
	glVertex2d(-800,-800);
	glVertex2d(-900,-800);
	glVertex2d(-900,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-900,-700);
	glVertex2d(-900,-800);
	glVertex2d(-1000,-800);
	glVertex2d(-1000,-700);
	glEnd();

	///////////9
	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-500,-800);
	glVertex2d(-500,-900);
	glVertex2d(-600,-900);
	glVertex2d(-600,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-700,-800);
	glVertex2d(-700,-900);
	glVertex2d(-600,-900);
	glVertex2d(-600,-800);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-700,-800);
	glVertex2d(-700,-900);
	glVertex2d(-800,-900);
	glVertex2d(-800,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//2
	glVertex2d(-800,-800);
	glVertex2d(-800,-900);
	glVertex2d(-900,-900);
	glVertex2d(-900,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//1
	glVertex2d(-900,-800);
	glVertex2d(-900,-900);
	glVertex2d(-1000,-900);
	glVertex2d(-1000,-800);
	glEnd();


	////////////////10
	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-500,-900);
	glVertex2d(-500,-1000);
	glVertex2d(-600,-1000);
	glVertex2d(-600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-700,-900);
	glVertex2d(-700,-1000);
	glVertex2d(-600,-1000);
	glVertex2d(-600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-700,-900);
	glVertex2d(-700,-1000);
	glVertex2d(-800,-1000);
	glVertex2d(-800,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(184,134,11);//2
	glVertex2d(-800,-900);
	glVertex2d(-800,-1000);
	glVertex2d(-900,-1000);
	glVertex2d(-900,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(218,165,32);//1
	glVertex2d(-900,-900);
	glVertex2d(-900,-1000);
	glVertex2d(-1000,-1000);
	glVertex2d(-1000,-900);
	glEnd();
}

char text[] = "Joy Bangla";

void Sprint( float x, float y, char *st)
{
    int l,i;
    l=strlen( st );
    glColor3f(1.0,0.0,0.0);

    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

    }
}



void day(){
	glClear(GL_COLOR_BUFFER_BIT);



//////////sky//////////////
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2d(-1000,1000);
    glColor3ub(173,216,230);
    glVertex2d(-1000,500);
    glColor3ub(135,206,250);
    glVertex2d(1000,500);
    glColor3ub(0,0,255);
    glVertex2d(1000,1000);
    glEnd();





    //////cloud1

     glPushMatrix();
    glTranslated(skyposition1,0.0, 0.0);
    circle(780, 900, 50, 100, 255,255,255);

    //cloud1
    circle(840, 940, 50, 100, 255,255,255);


     //cloud1
     circle(860, 900, 50, 100, 255,255,255);


     //cloud1
     circle(800, 850, 50, 100, 255,255,255);
     glPopMatrix();


     ///////sun
      circle(-870, 860, 90, 100, 255,215,0);


      glPushMatrix();
    glTranslated(skyposition,0.0, 0.0);
    //cloud2
    circle(350, 950, 90, 95, 255,255,255);

    //cloud2
    circle(250, 970, 65, 100, 255,255,255);

     //cloud2
     circle(440, 970, 65, 100, 255,255,255);

// cloud 3..right
    circle(-400, 850, 60, 100, 255,255,255);


    //cloud 3...upper...
     circle(-470, 910, 50, 100, 255,255,255);


    //cloud 3....left....
     circle(-520, 850, 60, 100, 255,255,255);

    //cloud3.....down
     circle(-460, 800, 50, 100, 255,255,255);

    glPopMatrix();


// Cloud end//

    ////diganto////....
    glBegin(GL_QUADS);
    glColor3ub(102,204,0);
    glVertex2d(-1000,500);
    glVertex2d(1000,500);
    glVertex2d(1000,600);
    glVertex2d(-1000,600);
    glEnd();
     circle(150, 580, 50, 100, 102,204,0);
    circle(450, 580, 65, 100, 102,204,0);
    circle(550, 580, 60, 100, 102,204,0);
     circle(650, 580, 75, 100, 102,204,0);
     circle(750, 600, 75, 100, 102,204,0);
     circle(850, 580, 65, 100, 102,204,0);
    circle(950, 580, 65, 100, 102,204,0);

    
    circle(-150, 580, 50, 100, 102,204,0);
    circle(-450, 580, 65, 100, 102,204,0);
    circle(-550, 580, 60, 100, 102,204,0);
    circle(-650, 580, 75, 100, 102,204,0);

   circle(-750, 600, 75, 100, 102,204,0);
    circle(-850, 580, 65, 100, 102,204,0);
   circle(-950, 580, 65, 100, 102,204,0);
   circle(-250, 630, 65, 100, 102,204,0);
   circle(-350, 600, 70, 100, 102,204,0);


 
    glBegin(GL_QUADS);

    glVertex2d(-1000,100);
    glColor3ub(189,183,107);
    glVertex2d(1000,100);
    glColor3ub(218,165,32);
    glVertex2d(1000,500);
    glColor3ub(218,165,32);
    glVertex2d(-1000,500);
    glColor3ub(218,165,32);
    glEnd();

    

    //small tree1//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(720,360);
    glVertex2d(720,450);
    glVertex2d(730,450);
    glVertex2d(730,360);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(685,450);
    glVertex2d(765,450);
    glVertex2d(725,500);
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(690,492);
    glVertex2d(760,492);
    glVertex2d(725,530);
    glEnd();
    //small tree2//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(325,220);
    glVertex2d(340,220);
    glVertex2d(340,300);
    glVertex2d(325,300);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(290,300);
    glVertex2d(370,300);
    glVertex2d(330,350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(300,340);
    glVertex2d(360,340);
    glVertex2d(330,390);
    glEnd();
    //small tree3//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(445,200);
    glVertex2d(460,200);
    glVertex2d(460,310);
    glVertex2d(445,310);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(418,300);
    glVertex2d(487,300);
    glVertex2d(450,360);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(420,345);
    glVertex2d(480,345);
    glVertex2d(450,397);
    glEnd();
     //small tree4//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(540,100);
    glVertex2d(553,100);
    glVertex2d(553,190);
    glVertex2d(540,190);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(505,190);
    glVertex2d(590,190);
    glVertex2d(545,260);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(510,245);
    glVertex2d(580,245);
    glVertex2d(545,310);
    glEnd();
     //small tree5//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(770,100);
    glVertex2d(785,100);
    glVertex2d(785,190);
    glVertex2d(770,190);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(740,190);
    glVertex2d(810,190);
    glVertex2d(775,260);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(745,240);
    glVertex2d(805,240);
    glVertex2d(775,290);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(280,100);
    glVertex2d(500,100);
    glVertex2d(500,170);
    glVertex2d(280,170);
    glEnd();
    circle(250, 130, 55, 100, 73,153,0);
    circle(360, 175, 50, 100, 73,153,0);
    circle(460, 140, 50, 100, 73,153,0);


   //small grass2//

    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(850,100);
    glVertex2d(1000,100);
    glVertex2d(1000,150);
    glVertex2d(850,150);
    glEnd();

    circle(850, 125, 26, 50, 73,153,0);
    circle(900, 150, 35, 90, 73,153,0);
    circle(960, 140, 30, 100,73,153,0);


    //small grass3//

    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(580,100);
    glVertex2d(730,100);
    glVertex2d(730,130);
    glVertex2d(580,130);
    glEnd();

    circle(650, 150, 40, 80, 73,153,0);
    circle(715, 130, 40, 80, 73,153,0);
    circle(605, 130, 40, 80, 73,153,0);



  //tree1//

  circle(930, 500, 60, 100, 0,128,0);
  circle(900, 450, 60, 100, 0,128,0);
    circle(980, 440, 60, 100, 0,128,0);

      circle(890, 380, 60, 100, 0,128,0);

      circle(955, 375, 65, 80, 0,128,0);


// tree...bar
 glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(900,100);
    glVertex2d(900,380);
    glVertex2d(930,380);
    glVertex2d(930,100);
    glEnd();
    // tree support
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(900,385);
    glVertex2d(910,400);
    glVertex2d(910,340);
    glVertex2d(900,380);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(935,380);
    glVertex2d(930,400);
    glVertex2d(920,400);
    glVertex2d(900,380);
    glEnd();//tree1 end//

    //tree2//
      circle(790, 345, 60, 100, 0,100,0);
      circle(820, 415, 55, 100, 0,100,0);

   circle(840, 340, 60, 100, 0,100,0);

// tree...bar
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(800,100);
    glVertex2d(800,340);
    glVertex2d(825,340);
    glVertex2d(825,100);
    glEnd();//treee2 end//


    //tree3//
    circle(600, 470, 55, 100, 0,100,0);
    circle(545, 410, 60, 100, 0,100,0);

     circle(650, 410, 60, 100, 0,100,0);
     circle(580, 350, 35, 100, 0,100,0);
     circle(625, 350, 35, 100, 0,100,0);

     // tree...bar
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(600,100);
    glVertex2d(600,340);
    glVertex2d(625,340);
    glVertex2d(625,100);
    glEnd();



     // tree support
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(625,345);
    glVertex2d(620,360);
    glVertex2d(615,360);
    glVertex2d(615,330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(600,340);
    glVertex2d(600,370);
    glVertex2d(608,370);
    glVertex2d(608,340);
    glEnd();
//grass field 01
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(720,250);
    glVertex2d(730,300);
    glVertex2d(710,250);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(710,250);
    glVertex2d(700,300);
    glVertex2d(690,250);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(690,250);
    glVertex2d(670,300);
    glVertex2d(680,250);
    glEnd();

   //grass field 02
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(270,350);
    glVertex2d(280,400);
    glVertex2d(260,350);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(260,350);
    glVertex2d(250,400);
    glVertex2d(240,350);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(240,350);
    glVertex2d(220,400);
    glVertex2d(230,350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-758,300);
    glVertex2d(-758,430);
    glVertex2d(-742,430);
    glVertex2d(-742,300);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-800,400);
    glVertex2d(-750,480);
    glVertex2d(-700,400);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-790,445);
    glVertex2d(-750,520);
    glVertex2d(-710,445);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-438,330);
    glVertex2d(-438,430);
    glVertex2d(-422,430);
    glVertex2d(-422,330);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-478,430);
    glVertex2d(-430,480);
    glVertex2d(-382,430);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-468,470);
    glVertex2d(-430,530);
    glVertex2d(-392,470);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-808,150);
    glVertex2d(-808,250);
    glVertex2d(-792,250);
    glVertex2d(-792,150);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-848,250);
    glVertex2d(-800,300);
    glVertex2d(-752,250);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-838,290);
    glVertex2d(-800,350);
    glVertex2d(-762,290);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-696,150);
    glVertex2d(-696,250);
    glVertex2d(-680,250);
    glVertex2d(-680,150);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-736,250);
    glVertex2d(-688,300);
    glVertex2d(-640,250);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-726,290);
    glVertex2d(-688,350);
    glVertex2d(-650,290);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-200,440);
    glVertex2d(-215,440);
    glVertex2d(-215,340);
    glVertex2d(-200,340);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-160,430);
    glVertex2d(-250,430);
    glVertex2d(-205,480);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(-170,470);
    glVertex2d(-240,470);
    glVertex2d(-203,515);
    glEnd();
    /////////////////////////


    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(-880,100);
    glVertex2d(-880,130);
    glVertex2d(-600,130);
    glVertex2d(-600,100);
    glEnd();
    circle(-860, 150, 50, 100,73,153,0);
     circle(-782, 150, 35, 100, 73,153,0);
     circle(-730, 140, 25, 100, 73,153,0);

     circle(-680, 130, 25, 100, 73,153,0);

     circle(-620, 150, 35, 100, 73,153,0);

      glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(-350,100);
    glVertex2d(-350,130);
    glVertex2d(-550,130);
    glVertex2d(-550,100);
    glEnd();

    circle(-386, 150, 35, 100, 73,153,0);
    circle(-450, 140, 40, 100, 73,153,0);
     circle(-782, 150, 35, 100,73,153,0);
     circle(-520, 140, 40, 100, 73,153,0);



    // main big tree ....leaf
     circle(-530, 410, 70, 100, 0,100,0);
     circle(-530, 320, 30, 100, 0,100,0);

    circle(-600, 480, 70, 100, 0,100,0);
    circle(-650, 400, 70, 100, 0,100,0);
    circle(-620, 320, 40, 100, 0,100,0);

// tree...bar
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-600,100);
    glVertex2d(-600,370);
    glVertex2d(-550,370);
    glVertex2d(-550,100);
    glEnd();
// tree support
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-600,330);
    glVertex2d(-620,370);
    glVertex2d(-620,400);
    glVertex2d(-600,370);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-600,370);
    glVertex2d(-580,420);
    glVertex2d(-580,380);
    glVertex2d(-550,350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2d(-550,370);
    glVertex2d(-530,410);
    glVertex2d(-550,290);

    glEnd();
// tree left of main tree


//left leaf

    circle(-950, 350, 60, 100, 0,100,0);

    //upper leaf
     circle(-900, 450, 75, 100, 0,100,0);
    // lower leaf
     circle(-850, 350, 60, 100, 0,100,0);


    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-920,100);
    glVertex2d(-920,330);
    glVertex2d(-880,330);
    glVertex2d(-880,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2d(-920,330);
    glVertex2d(-940,400);
    glVertex2d(-900,330);
    glVertex2d(-900,450);
    glVertex2d(-890,330);
    glVertex2d(-860,400);
    glVertex2d(-880,330);
    glVertex2d(-920,330);
    glEnd();

// tree behind monument
//left leaf
 circle(-380, 280, 60, 100, 0,128,0);
 circle(-330, 390, 75, 100, 0,128,0);


    // left leaf
    circle(-290, 300, 70, 100, 0,128,0);

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-350,100);
    glVertex2d(-350,280);
    glVertex2d(-310,280);
    glVertex2d(-310,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2d(-350,280);
    glVertex2d(-370,350);
    glVertex2d(-330,280);
    glVertex2d(-330,400);
    glVertex2d(-310,280);
    glVertex2d(-280,350);
    glVertex2d(-300,290);
    glVertex2d(-350,280);
    glEnd();
    /////////////////////////////////
//
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(-500,200);
    glVertex2d(-510,250);
    glVertex2d(-490,200);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(-495,200);
    glVertex2d(-480,250);
    glVertex2d(-465,200);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(-470,200);
    glVertex2d(-450,250);
    glVertex2d(-460,200);

    glEnd();

   
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(-970,150);
    glVertex2d(-980,200);
    glVertex2d(-960,150);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(-960,150);
    glVertex2d(-950,200);
    glVertex2d(-940,150);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(-940,150);
    glVertex2d(-920,200);
    glVertex2d(-930,150);

    glEnd();



    /////////1st stairs///////////
    glBegin(GL_QUADS);
    glColor3ub(220,220,220);
    glVertex2d(-1000,100);
    glVertex2d(1000,100);
    glVertex2d(1000,0);
    glVertex2d(-1000,0);
    glEnd();

    
    //flower//
   flower  ();

    

    /////////////lake
         glBegin(GL_QUADS);
    glColor3ub(240,230,140);
    glVertex2d(-500,0);
    glVertex2d(-500,-640);
    glVertex2d(500,-640);
    glVertex2d(500,0);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(1,1,1);
     glVertex2d(500,0);
    glVertex2d(-500,0);
    glVertex2d(-500,0);
    glVertex2d(-500,-640);

    glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2d(-460,-80);
	glColor3ub(30,144,255);
	glVertex2d(-460,-560);
	glVertex2d(460,-560);
	glColor3ub(51,51,255);
	glVertex2d(460,-80);

	glEnd();

	/////////////waves

	glPushMatrix();
    glTranslated(watermoves1,0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-450,-90);
	glVertex2d(-450,-100);
	glVertex2d(-460,-100);
	glVertex2d(-460,-90);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-300,-100);
	glVertex2d(-300,-110);
	glVertex2d(-380,-110);
	glVertex2d(-380,-100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-400,-200);
	glVertex2d(-400,-210);
	glVertex2d(-300,-210);
	glVertex2d(-300,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-400,-330);
	glVertex2d(-400,-320);
	glVertex2d(-300,-320);
	glVertex2d(-300,-330);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-460,-430);
	glVertex2d(-460,-420);
	glVertex2d(-360,-420);
	glVertex2d(-360,-430);
	glEnd();



	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-260,-430);
	glVertex2d(-260,-420);
	glVertex2d(-160,-420);
	glVertex2d(-160,-430);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-160,-230);
	glVertex2d(-160,-220);
	glVertex2d(-90,-220);
	glVertex2d(-90,-230);
	glEnd();
	//


	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(300,-100);
	glVertex2d(300,-110);
	glVertex2d(380,-110);
	glVertex2d(380,-100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(400,-200);
	glVertex2d(400,-210);
	glVertex2d(300,-210);
	glVertex2d(300,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(400,-330);
	glVertex2d(400,-320);
	glVertex2d(300,-320);
	glVertex2d(300,-330);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(460,-430);
	glVertex2d(460,-420);
	glVertex2d(360,-420);
	glVertex2d(360,-430);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(260,-430);
	glVertex2d(260,-420);
	glVertex2d(160,-420);
	glVertex2d(160,-430);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(160,-230);
	glVertex2d(160,-220);
	glVertex2d(90,-220);
	glVertex2d(90,-230);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-200,-120);
	glVertex2d(-200,-130);
	glVertex2d(150,-130);
	glVertex2d(150,-120);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-200,-500);
	glVertex2d(-200,-510);
	glVertex2d(150,-510);
	glVertex2d(150,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-100,-400);
	glVertex2d(-100,-410);
	glVertex2d(120,-410);
	glVertex2d(120,-400);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-300,-520);
	glVertex2d(-300,-510);
	glVertex2d(-350,-510);
	glVertex2d(-350,-520);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,10,205);
	glVertex2d(-280,-290);
	glVertex2d(-280,-280);
	glVertex2d(-230,-280);
	glVertex2d(-230,-290);
	glEnd();
	glPopMatrix();
	/////////////////
	////////shapla
    glPushMatrix();
    glTranslated(watermoves,0.0, 0.0);
    /////1
     circle(-400, -240, 40, 100, 107,142,35);

     glBegin(GL_POLYGON);

	glColor3ub(107,142,35);
	glVertex2d(-400,-200);
    glVertex2d(-440,-160);
    glVertex2d(-440,-230);
    glVertex2d(-360,-230);
    glVertex2d(-360,-160);
    glVertex2d(-400,-200);

	glEnd();

	/////2
	circle(0, -300, 40, 100, 107,142,35);

    glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(0,-260);
    glVertex2d(40,-220);
    glVertex2d(40,-290);
    glVertex2d(-40,-290);
    glVertex2d(-40,-220);
    glVertex2d(0,-260);

	glEnd();


	/////3
	circle(400, -500, 40, 100, 107,142,35);

     glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(400,-460);
    glVertex2d(440,-420);
    glVertex2d(440,-490);
    glVertex2d(360,-490);
    glVertex2d(360,-420);
    glVertex2d(400,-460);

	glEnd();
/////4
circle(200, -240, 40, 100, 107,142,35);

     glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(200,-200);
    glVertex2d(240,-160);
    glVertex2d(240,-230);
    glVertex2d(160,-230);
    glVertex2d(160,-160);
    glVertex2d(200,-200);

	glEnd();
	/////5
	circle(-200, -500, 40, 100, 107,142,35);


   glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(-200,-460);
    glVertex2d(-240,-420);
    glVertex2d(-240,-490);
    glVertex2d(-160,-490);
    glVertex2d(-160,-420);
    glVertex2d(-200,-460);
    glEnd();
	glPopMatrix();

///////////bricks////////////////

    ///////////bricks////////////////



    glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(-500,-640);
	glVertex2d(-500,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-640);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(-320,-640);
	glVertex2d(-320,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(-320,-640);
	glVertex2d(-320,-740);
	glVertex2d(-220,-740);
	glVertex2d(-220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(-220,-640);
	glVertex2d(-220,-740);
	glVertex2d(-120,-740);
	glVertex2d(-120,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(-120,-640);
	glVertex2d(-120,-740);
	glVertex2d(-20,-740);
	glVertex2d(-20,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(-20,-640);
	glVertex2d(-20,-740);
	glVertex2d(120,-740);
	glVertex2d(120,-640);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(120,-640);
	glVertex2d(120,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(320,-640);
	glVertex2d(320,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(420,-640);
	glVertex2d(420,-740);
	glVertex2d(320,-740);
	glVertex2d(320,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(500,-640);
	glVertex2d(500,-740);
	glVertex2d(420,-740);
	glVertex2d(420,-640);
	glEnd();

	///////


	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//1
	glVertex2d(-500,-840);
	glVertex2d(-500,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-840);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//2
	glVertex2d(-320,-840);
	glVertex2d(-320,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//1
	glVertex2d(-320,-840);
	glVertex2d(-320,-740);
	glVertex2d(-220,-740);
	glVertex2d(-220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//2
	glVertex2d(-220,-840);
	glVertex2d(-220,-740);
	glVertex2d(-120,-740);
	glVertex2d(-120,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//1
	glVertex2d(-120,-840);
	glVertex2d(-120,-740);
	glVertex2d(-20,-740);
	glVertex2d(-20,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//2
	glVertex2d(-20,-840);
	glVertex2d(-20,-740);
	glVertex2d(120,-740);
	glVertex2d(120,-840);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//1
	glVertex2d(120,-840);
	glVertex2d(120,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//2
	glVertex2d(320,-840);
	glVertex2d(320,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//1
	glVertex2d(420,-840);
	glVertex2d(420,-740);
	glVertex2d(320,-740);
	glVertex2d(320,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//2
	glVertex2d(500,-840);
	glVertex2d(500,-740);
	glVertex2d(420,-740);
	glVertex2d(420,-840);
	glEnd();
///////
     glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(-500,-840);
	glVertex2d(-500,-1000);
	glVertex2d(-420,-1000);
	glVertex2d(-420,-840);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(-320,-840);
	glVertex2d(-320,-1000);
	glVertex2d(-420,-1000);
	glVertex2d(-420,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(-320,-840);
	glVertex2d(-320,-1000);
	glVertex2d(-220,-1000);
	glVertex2d(-220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(-220,-840);
	glVertex2d(-220,-1000);
	glVertex2d(-120,-1000);
	glVertex2d(-120,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(-120,-840);
	glVertex2d(-120,-1000);
	glVertex2d(-20,-1000);
	glVertex2d(-20,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(-20,-840);
	glVertex2d(-20,-1000);
	glVertex2d(120,-1000);
	glVertex2d(120,-840);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(120,-840);
	glVertex2d(120,-1000);
	glVertex2d(220,-1000);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(320,-840);
	glVertex2d(320,-1000);
	glVertex2d(220,-1000);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,180,140);//1
	glVertex2d(420,-840);
	glVertex2d(420,-1000);
	glVertex2d(320,-1000);
	glVertex2d(320,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(245,222,179);//2
	glVertex2d(500,-840);
	glVertex2d(500,-1000);
	glVertex2d(420,-1000);
	glVertex2d(420,-840);
	glEnd();


	// side b
	// side brick end


    //////////


//////right side bricks

     /////1
     glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(500,0);
	glVertex2d(500,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub		(189,183,107);//2
	glVertex2d(700,0);
	glVertex2d(700,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-0);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(700,0);
	glVertex2d(700,-100);
	glVertex2d(800,-100);
	glVertex2d(800,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(800,0);
	glVertex2d(800,-100);
	glVertex2d(900,-100);
	glVertex2d(900,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(900,0);
	glVertex2d(900,-100);
	glVertex2d(1000,-100);
	glVertex2d(1000,-0);
	glEnd();


	///////2
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(500,-200);
	glVertex2d(500,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(700,-200);
	glVertex2d(700,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(700,-200);
	glVertex2d(700,-100);
	glVertex2d(800,-100);
	glVertex2d(800,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(800,-200);
	glVertex2d(800,-100);
	glVertex2d(900,-100);
	glVertex2d(900,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(900,-200);
	glVertex2d(900,-100);
	glVertex2d(1000,-100);
	glVertex2d(1000,-200);
	glEnd();


	////////////////////3

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(500,-300);
	glVertex2d(500,-200);
	glVertex2d(600,-200);
	glVertex2d(600,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(700,-300);
	glVertex2d(700,-200);
	glVertex2d(600,-200);
	glVertex2d(600,-300);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(700,-300);
	glVertex2d(700,-200);
	glVertex2d(800,-200);
	glVertex2d(800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(800,-300);
	glVertex2d(800,-200);
	glVertex2d(900,-200);
	glVertex2d(900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(900,-300);
	glVertex2d(900,-200);
	glVertex2d(1000,-200);
	glVertex2d(1000,-300);
	glEnd();


	////////////////4
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(500,-300);
	glVertex2d(500,-400);
	glVertex2d(600,-400);
	glVertex2d(600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(700,-300);
	glVertex2d(700,-400);
	glVertex2d(600,-400);
	glVertex2d(600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(700,-300);
	glVertex2d(700,-400);
	glVertex2d(800,-400);
	glVertex2d(800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(800,-300);
	glVertex2d(800,-400);
	glVertex2d(900,-400);
	glVertex2d(900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(900,-300);
	glVertex2d(900,-400);
	glVertex2d(1000,-400);
	glVertex2d(1000,-300);
	glEnd();

	////////////////////5
	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(500,-400);
	glVertex2d(500,-500);
	glVertex2d(600,-500);
	glVertex2d(600,-400);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(700,-400);
	glVertex2d(700,-500);
	glVertex2d(600,-500);
	glVertex2d(600,-400);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(700,-500);
	glVertex2d(700,-400);
	glVertex2d(800,-400);
	glVertex2d(800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(800,-500);
	glVertex2d(800,-400);
	glVertex2d(900,-400);
	glVertex2d(900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(900,-400);
	glVertex2d(900,-500);
	glVertex2d(1000,-500);
	glVertex2d(1000,-400);
	glEnd();


	////////////////6
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(500,-500);
	glVertex2d(500,-600);
	glVertex2d(600,-600);
	glVertex2d(600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(700,-500);
	glVertex2d(700,-600);
	glVertex2d(600,-600);
	glVertex2d(600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(700,-500);
	glVertex2d(700,-600);
	glVertex2d(800,-600);
	glVertex2d(800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(800,-500);
	glVertex2d(800,-600);
	glVertex2d(900,-600);
	glVertex2d(900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(900,-500);
	glVertex2d(900,-600);
	glVertex2d(1000,-600);
	glVertex2d(1000,-500);
	glEnd();
////////////////////7
glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(500,-600);
	glVertex2d(500,-700);
	glVertex2d(600,-700);
	glVertex2d(600,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(700,-600);
	glVertex2d(700,-700);
	glVertex2d(600,-700);
	glVertex2d(600,-600);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(700,-600);
	glVertex2d(700,-700);
	glVertex2d(800,-700);
	glVertex2d(800,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(800,-600);
	glVertex2d(800,-700);
	glVertex2d(900,-700);
	glVertex2d(900,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(900,-600);
	glVertex2d(900,-700);
	glVertex2d(1000,-700);
	glVertex2d(1000,-600);
	glEnd();


	////////////////8
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(500,-700);
	glVertex2d(500,-800);
	glVertex2d(600,-800);
	glVertex2d(600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(700,-700);
	glVertex2d(700,-800);
	glVertex2d(600,-800);
	glVertex2d(600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(700,-700);
	glVertex2d(700,-800);
	glVertex2d(800,-800);
	glVertex2d(800,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(800,-700);
	glVertex2d(800,-800);
	glVertex2d(900,-800);
	glVertex2d(900,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(900,-700);
	glVertex2d(900,-800);
	glVertex2d(1000,-800);
	glVertex2d(1000,-700);
	glEnd();

	///////////9
	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(500,-800);
	glVertex2d(500,-900);
	glVertex2d(600,-900);
	glVertex2d(600,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(700,-800);
	glVertex2d(700,-900);
	glVertex2d(600,-900);
	glVertex2d(600,-800);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(700,-800);
	glVertex2d(700,-900);
	glVertex2d(800,-900);
	glVertex2d(800,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(800,-800);
	glVertex2d(800,-900);
	glVertex2d(900,-900);
	glVertex2d(900,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(900,-800);
	glVertex2d(900,-900);
	glVertex2d(1000,-900);
	glVertex2d(1000,-800);
	glEnd();


	////////////////10
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(500,-900);
	glVertex2d(500,-1000);
	glVertex2d(600,-1000);
	glVertex2d(600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(700,-900);
	glVertex2d(700,-1000);
	glVertex2d(600,-1000);
	glVertex2d(600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(700,-900);
	glVertex2d(700,-1000);
	glVertex2d(800,-1000);
	glVertex2d(800,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(800,-900);
	glVertex2d(800,-1000);
	glVertex2d(900,-1000);
	glVertex2d(900,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(900,-900);
	glVertex2d(900,-1000);
	glVertex2d(1000,-1000);
	glVertex2d(1000,-900);
	glEnd();
//////////////////left side bricks
    /////1

 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-500,0);
	glVertex2d(-500,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub		(189,183,107);//2
	glVertex2d(-700,0);
	glVertex2d(-700,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-0);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-700,0);
	glVertex2d(-700,-100);
	glVertex2d(-800,-100);
	glVertex2d(-800,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-800,0);
	glVertex2d(-800,-100);
	glVertex2d(-900,-100);
	glVertex2d(-900,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-900,0);
	glVertex2d(-900,-100);
	glVertex2d(-1000,-100);
	glVertex2d(-1000,-0);
	glEnd();


	///////2
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-500,-200);
	glVertex2d(-500,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-700,-200);
	glVertex2d(-700,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-700,-200);
	glVertex2d(-700,-100);
	glVertex2d(-800,-100);
	glVertex2d(-800,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-800,-200);
	glVertex2d(-800,-100);
	glVertex2d(-900,-100);
	glVertex2d(-900,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-900,-200);
	glVertex2d(-900,-100);
	glVertex2d(-1000,-100);
	glVertex2d(-1000,-200);
	glEnd();


	////////////////////3

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-500,-300);
	glVertex2d(-500,-200);
	glVertex2d(-600,-200);
	glVertex2d(-600,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-700,-300);
	glVertex2d(-700,-200);
	glVertex2d(-600,-200);
	glVertex2d(-600,-300);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-700,-300);
	glVertex2d(-700,-200);
	glVertex2d(-800,-200);
	glVertex2d(-800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-800,-300);
	glVertex2d(-800,-200);
	glVertex2d(-900,-200);
	glVertex2d(-900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-900,-300);
	glVertex2d(-900,-200);
	glVertex2d(-1000,-200);
	glVertex2d(-1000,-300);
	glEnd();


	////////////////4
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-500,-300);
	glVertex2d(-500,-400);
	glVertex2d(-600,-400);
	glVertex2d(-600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-700,-300);
	glVertex2d(-700,-400);
	glVertex2d(-600,-400);
	glVertex2d(-600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-700,-300);
	glVertex2d(-700,-400);
	glVertex2d(-800,-400);
	glVertex2d(-800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-800,-300);
	glVertex2d(-800,-400);
	glVertex2d(-900,-400);
	glVertex2d(-900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-900,-300);
	glVertex2d(-900,-400);
	glVertex2d(-1000,-400);
	glVertex2d(-1000,-300);
	glEnd();

	////////////////////5
	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-500,-400);
	glVertex2d(-500,-500);
	glVertex2d(-600,-500);
	glVertex2d(-600,-400);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-700,-400);
	glVertex2d(-700,-500);
	glVertex2d(-600,-500);
	glVertex2d(-600,-400);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-700,-500);
	glVertex2d(-700,-400);
	glVertex2d(-800,-400);
	glVertex2d(-800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-800,-500);
	glVertex2d(-800,-400);
	glVertex2d(-900,-400);
	glVertex2d(-900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-900,-400);
	glVertex2d(-900,-500);
	glVertex2d(-1000,-500);
	glVertex2d(-1000,-400);
	glEnd();


	////////////////6
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-500,-500);
	glVertex2d(-500,-600);
	glVertex2d(-600,-600);
	glVertex2d(-600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-700,-500);
	glVertex2d(-700,-600);
	glVertex2d(-600,-600);
	glVertex2d(-600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-700,-500);
	glVertex2d(-700,-600);
	glVertex2d(-800,-600);
	glVertex2d(-800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-800,-500);
	glVertex2d(-800,-600);
	glVertex2d(-900,-600);
	glVertex2d(-900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-900,-500);
	glVertex2d(-900,-600);
	glVertex2d(-1000,-600);
	glVertex2d(-1000,-500);
	glEnd();
////////////////////7
glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-500,-600);
	glVertex2d(-500,-700);
	glVertex2d(-600,-700);
	glVertex2d(-600,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-700,-600);
	glVertex2d(-700,-700);
	glVertex2d(-600,-700);
	glVertex2d(-600,-600);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-700,-600);
	glVertex2d(-700,-700);
	glVertex2d(-800,-700);
	glVertex2d(-800,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-800,-600);
	glVertex2d(-800,-700);
	glVertex2d(-900,-700);
	glVertex2d(-900,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-900,-600);
	glVertex2d(-900,-700);
	glVertex2d(-1000,-700);
	glVertex2d(-1000,-600);
	glEnd();


	////////////////8
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-500,-700);
	glVertex2d(-500,-800);
	glVertex2d(-600,-800);
	glVertex2d(-600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-700,-700);
	glVertex2d(-700,-800);
	glVertex2d(-600,-800);
	glVertex2d(-600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-700,-700);
	glVertex2d(-700,-800);
	glVertex2d(-800,-800);
	glVertex2d(-800,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-800,-700);
	glVertex2d(-800,-800);
	glVertex2d(-900,-800);
	glVertex2d(-900,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-900,-700);
	glVertex2d(-900,-800);
	glVertex2d(-1000,-800);
	glVertex2d(-1000,-700);
	glEnd();

	///////////9
	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-500,-800);
	glVertex2d(-500,-900);
	glVertex2d(-600,-900);
	glVertex2d(-600,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-700,-800);
	glVertex2d(-700,-900);
	glVertex2d(-600,-900);
	glVertex2d(-600,-800);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-700,-800);
	glVertex2d(-700,-900);
	glVertex2d(-800,-900);
	glVertex2d(-800,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-800,-800);
	glVertex2d(-800,-900);
	glVertex2d(-900,-900);
	glVertex2d(-900,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//1
	glVertex2d(-900,-800);
	glVertex2d(-900,-900);
	glVertex2d(-1000,-900);
	glVertex2d(-1000,-800);
	glEnd();


	////////////////10
	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-500,-900);
	glVertex2d(-500,-1000);
	glVertex2d(-600,-1000);
	glVertex2d(-600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-700,-900);
	glVertex2d(-700,-1000);
	glVertex2d(-600,-1000);
	glVertex2d(-600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-700,-900);
	glVertex2d(-700,-1000);
	glVertex2d(-800,-1000);
	glVertex2d(-800,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(238,232,170);//2
	glVertex2d(-800,-900);
	glVertex2d(-800,-1000);
	glVertex2d(-900,-1000);
	glVertex2d(-900,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-900,-900);
	glVertex2d(-900,-1000);
	glVertex2d(-1000,-1000);
	glVertex2d(-1000,-900);
	glEnd();
	

//*** Right Side Field ***//





// First row shell  #########
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-164);
    glVertex2d(539,-197);
    glVertex2d(547,-197);
    glVertex2d(547,-164);
    glVertex2d(544,-166);
    glVertex2d(541,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-164);
    glVertex2d(546,-164);
    glVertex2d(545,-158);
    glVertex2d(543,-156);
    glVertex2d(542,-156);
    glVertex2d(541,-157);
    glVertex2d(539,-162);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-164);
    glVertex2d(550,-197);
    glVertex2d(558,-197);
    glVertex2d(558,-164);
    glVertex2d(555,-166);
    glVertex2d(552,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-164);
    glVertex2d(558,-164);
    glVertex2d(556,-158);
    glVertex2d(554,-156);
    glVertex2d(553,-156);
    glVertex2d(552,-157);
    glVertex2d(550,-162);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-164);
    glVertex2d(560,-197);
    glVertex2d(568,-197);
    glVertex2d(568,-164);
    glVertex2d(565,-166);
    glVertex2d(562,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-164);
    glVertex2d(568,-164);
    glVertex2d(566,-158);
    glVertex2d(564,-156);
    glVertex2d(563,-156);
    glVertex2d(562,-157);
    glVertex2d(560,-162);
    glEnd();

//1st Arty Gun//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-136);
    glVertex2d(751,-149);
    glVertex2d(853,-139);
    glVertex2d(851,-108);
    glVertex2d(842,-97);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-173);
    glVertex2d(624,-186);
    glVertex2d(624,-197);
    glVertex2d(637,-197);
    glVertex2d(647,-183);
    glVertex2d(796,-159);
    glVertex2d(800,-141);
    glVertex2d(645,-168);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-93);
    glVertex2d(788,-101);
    glVertex2d(794,-117);
    glVertex2d(842,-98);
    glVertex2d(831,-81);
    glVertex2d(809,-89);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-81);
    glVertex2d(835,-90);
    glVertex2d(909,-63);
    glVertex2d(908,-55);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-89);
    glVertex2d(842,-99);
    glVertex2d(958,-57);
    glVertex2d(954,-47);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-98);
    glVertex2d(850,-108);
    glVertex2d(919,-85);
    glVertex2d(914,-74);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(823,-122);
    glVertex2d(817,-124);
    glVertex2d(812,-124);
    glVertex2d(808,-126);
    glVertex2d(803,-130);
    glVertex2d(798,-134);
    glVertex2d(796,-139);
    glVertex2d(793,-144);
    glVertex2d(794,-153);
    glVertex2d(794,-161);
    glVertex2d(795,-168);
    glVertex2d(798,-175);
    glVertex2d(805,-184);
    glVertex2d(814,-193);
    glVertex2d(820,-196);
    glVertex2d(838,-196);
    glVertex2d(846,-195);
    glVertex2d(858,-188);
    glVertex2d(868,-178);
    glVertex2d(871,-171);
    glVertex2d(873,-162);
    glVertex2d(873,-152);
    glVertex2d(870,-145);
    glVertex2d(866,-139);
    glVertex2d(862,-133);
    glVertex2d(857,-129);
    glVertex2d(853,-125);
    glVertex2d(843,-121);
    glVertex2d(836,-120);
    glVertex2d(830,-120);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-133);
    glVertex2d(824,-135);
    glVertex2d(820,-138);
    glVertex2d(815,-144);
    glVertex2d(813,-148);
    glVertex2d(812,-154);
    glVertex2d(812,-160);
    glVertex2d(815,-169);
    glVertex2d(817,-173);
    glVertex2d(823,-180);
    glVertex2d(832,-183);
    glVertex2d(845,-180);
    glVertex2d(851,-175);
    glVertex2d(859,-168);
    glVertex2d(862,-161);
    glVertex2d(859,-146);
    glVertex2d(857,-142);
    glVertex2d(850,-136);
    glVertex2d(845,-133);
    glVertex2d(839,-131);
    glVertex2d(836,-131);
    glEnd();

// 2nd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-464);
    glVertex2d(539,-497);
    glVertex2d(547,-497);
    glVertex2d(547,-464);
    glVertex2d(544,-466);
    glVertex2d(541,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-464);
    glVertex2d(546,-464);
    glVertex2d(545,-458);
    glVertex2d(543,-456);
    glVertex2d(542,-456);
    glVertex2d(541,-457);
    glVertex2d(539,-462);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-464);
    glVertex2d(550,-497);
    glVertex2d(558,-497);
    glVertex2d(558,-464);
    glVertex2d(555,-466);
    glVertex2d(552,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-464);
    glVertex2d(558,-464);
    glVertex2d(556,-458);
    glVertex2d(554,-456);
    glVertex2d(553,-456);
    glVertex2d(552,-457);
    glVertex2d(550,-462);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-464);
    glVertex2d(560,-497);
    glVertex2d(568,-497);
    glVertex2d(568,-464);
    glVertex2d(565,-466);
    glVertex2d(562,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-464);
    glVertex2d(568,-464);
    glVertex2d(566,-458);
    glVertex2d(564,-456);
    glVertex2d(563,-456);
    glVertex2d(562,-457);
    glVertex2d(560,-462);
    glEnd();

//******* 2nd Arty Gun ******//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-436);
    glVertex2d(751,-449);
    glVertex2d(853,-439);
    glVertex2d(851,-408);
    glVertex2d(842,-397);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-473);
    glVertex2d(624,-486);
    glVertex2d(624,-497);
    glVertex2d(637,-497);
    glVertex2d(647,-483);
    glVertex2d(796,-459);
    glVertex2d(800,-441);
    glVertex2d(645,-468);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-393);
    glVertex2d(788,-401);
    glVertex2d(794,-417);
    glVertex2d(842,-398);
    glVertex2d(831,-381);
    glVertex2d(809,-389);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-381);
    glVertex2d(835,-390);
    glVertex2d(909,-363);
    glVertex2d(908,-355);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-389);
    glVertex2d(842,-399);
    glVertex2d(958,-357);
    glVertex2d(954,-347);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-398);
    glVertex2d(850,-408);
    glVertex2d(919,-385);
    glVertex2d(914,-374);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(823,-422);
    glVertex2d(817,-424);
    glVertex2d(812,-424);
    glVertex2d(808,-426);
    glVertex2d(803,-430);
    glVertex2d(798,-434);
    glVertex2d(796,-439);
    glVertex2d(793,-444);
    glVertex2d(794,-453);
    glVertex2d(794,-461);
    glVertex2d(795,-468);
    glVertex2d(798,-475);
    glVertex2d(805,-484);
    glVertex2d(814,-493);
    glVertex2d(820,-496);
    glVertex2d(838,-496);
    glVertex2d(846,-495);
    glVertex2d(858,-488);
    glVertex2d(868,-478);
    glVertex2d(871,-471);
    glVertex2d(873,-462);
    glVertex2d(873,-452);
    glVertex2d(870,-445);
    glVertex2d(866,-439);
    glVertex2d(862,-433);
    glVertex2d(857,-429);
    glVertex2d(853,-425);
    glVertex2d(843,-421);
    glVertex2d(836,-420);
    glVertex2d(830,-420);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-433);
    glVertex2d(824,-435);
    glVertex2d(820,-438);
    glVertex2d(815,-444);
    glVertex2d(813,-448);
    glVertex2d(812,-454);
    glVertex2d(812,-460);
    glVertex2d(815,-469);
    glVertex2d(817,-473);
    glVertex2d(823,-480);
    glVertex2d(832,-483);
    glVertex2d(845,-480);
    glVertex2d(851,-475);
    glVertex2d(859,-468);
    glVertex2d(862,-461);
    glVertex2d(859,-446);
    glVertex2d(857,-442);
    glVertex2d(850,-436);
    glVertex2d(845,-433);
    glVertex2d(839,-431);
    glVertex2d(836,-431);
    glEnd();



// 3rd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-764);
    glVertex2d(539,-797);
    glVertex2d(547,-797);
    glVertex2d(547,-764);
    glVertex2d(544,-766);
    glVertex2d(541,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-764);
    glVertex2d(546,-764);
    glVertex2d(545,-758);
    glVertex2d(543,-756);
    glVertex2d(542,-756);
    glVertex2d(541,-757);
    glVertex2d(539,-762);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-764);
    glVertex2d(550,-797);
    glVertex2d(558,-797);
    glVertex2d(558,-764);
    glVertex2d(555,-766);
    glVertex2d(552,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-764);
    glVertex2d(558,-764);
    glVertex2d(556,-758);
    glVertex2d(554,-756);
    glVertex2d(553,-756);
    glVertex2d(552,-757);
    glVertex2d(550,-762);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-764);
    glVertex2d(560,-797);
    glVertex2d(568,-797);
    glVertex2d(568,-764);
    glVertex2d(565,-766);
    glVertex2d(562,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-764);
    glVertex2d(568,-764);
    glVertex2d(566,-758);
    glVertex2d(564,-756);
    glVertex2d(563,-756);
    glVertex2d(562,-757);
    glVertex2d(560,-762);
    glEnd();

//***** 3rd Arty Gun *******//


    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-736);
    glVertex2d(751,-749);
    glVertex2d(853,-739);
    glVertex2d(851,-708);
    glVertex2d(842,-697);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-773);
    glVertex2d(624,-786);
    glVertex2d(624,-797);
    glVertex2d(637,-797);
    glVertex2d(647,-783);
    glVertex2d(796,-759);
    glVertex2d(800,-741);
    glVertex2d(645,-768);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-693);
    glVertex2d(788,-701);
    glVertex2d(794,-717);
    glVertex2d(842,-698);
    glVertex2d(831,-681);
    glVertex2d(809,-689);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-681);
    glVertex2d(835,-690);
    glVertex2d(909,-663);
    glVertex2d(908,-655);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-689);
    glVertex2d(842,-699);
    glVertex2d(958,-657);
    glVertex2d(954,-647);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-698);
    glVertex2d(850,-708);
    glVertex2d(919,-685);
    glVertex2d(914,-674);
    glEnd();
  glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(823,-722);
    glVertex2d(817,-724);
    glVertex2d(812,-724);
    glVertex2d(808,-726);
    glVertex2d(803,-730);
    glVertex2d(798,-734);
    glVertex2d(796,-739);
    glVertex2d(793,-744);
    glVertex2d(794,-753);
    glVertex2d(794,-761);
    glVertex2d(795,-768);
    glVertex2d(798,-775);
    glVertex2d(805,-784);
    glVertex2d(814,-793);
    glVertex2d(820,-796);
    glVertex2d(838,-796);
    glVertex2d(846,-795);
    glVertex2d(858,-788);
    glVertex2d(868,-778);
    glVertex2d(871,-771);
    glVertex2d(873,-762);
    glVertex2d(873,-752);
    glVertex2d(870,-745);
    glVertex2d(866,-739);
    glVertex2d(862,-733);
    glVertex2d(857,-729);
    glVertex2d(853,-725);
    glVertex2d(843,-721);
    glVertex2d(836,-720);
    glVertex2d(830,-720);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-733);
    glVertex2d(824,-735);
    glVertex2d(820,-738);
    glVertex2d(815,-744);
    glVertex2d(813,-748);
    glVertex2d(812,-754);
    glVertex2d(812,-760);
    glVertex2d(815,-769);
    glVertex2d(817,-773);
    glVertex2d(823,-780);
    glVertex2d(832,-783);
    glVertex2d(845,-780);
    glVertex2d(851,-775);
    glVertex2d(859,-768);
    glVertex2d(862,-761);
    glVertex2d(859,-746);
    glVertex2d(857,-742);
    glVertex2d(850,-736);
    glVertex2d(845,-733);
    glVertex2d(839,-731);
    glVertex2d(836,-731);
    glEnd();

    //Army Right after 1st Gun *****************************
glBegin(GL_POLYGON);//fig
    glColor3ub(51,102,0);
    glVertex2d(735,-161);
    glVertex2d(720,-168);
    glVertex2d(720,-226);
    glVertex2d(761,-226);
    glVertex2d(761,-168);
    glVertex2d(749,-161);
    glEnd();
    glBegin(GL_POLYGON);//Pant
    glColor3ub(0,51,0);
    glVertex2d(720,-226);
    glVertex2d(721,-260);
    glVertex2d(732,-259);
    glVertex2d(737,-235);
    glVertex2d(736,-225);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,51,0);
    glVertex2d(733,-226);
    glVertex2d(733,-236);
    glVertex2d(760,-237);
    glVertex2d(760,-225);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,51,0);
    glVertex2d(747,-236);
    glVertex2d(748,-261);
    glVertex2d(760,-260);
    glVertex2d(760,-235);
    glEnd();
    glBegin(GL_POLYGON);//L Boot
    glColor3ub(0,0,0);
    glVertex2d(731,-272);
    glVertex2d(731,-259);
    glVertex2d(720,-259);
    glVertex2d(720,-282);
    glVertex2d(742,-282);
    glVertex2d(742,-272);
    glEnd();
    glBegin(GL_POLYGON);//L Boot
    glColor3ub(0,0,0);
    glVertex2d(760,-272);
    glVertex2d(760,-259);
    glVertex2d(747,-259);
    glVertex2d(747,-282);
    glVertex2d(770,-282);
    glVertex2d(770,-272);
    glEnd();
    glBegin(GL_POLYGON);//head
    glColor3ub(255,128,0);
    glVertex2d(758,-140);
    glVertex2d(764,-140);
    glVertex2d(757,-128);
    glVertex2d(734,-134);
    glVertex2d(735,-162);
    glVertex2d(746,-162);
    glVertex2d(747,-149);
    glVertex2d(758,-150);
    glEnd();
     glBegin(GL_POLYGON);//Helmet
    glColor3ub(25,51,0);
    glVertex2d(768,-124);
    glVertex2d(765,-119);
    glVertex2d(754,-112);
    glVertex2d(743,-109);
    glVertex2d(726,-117);
    glVertex2d(721,-126);
    glVertex2d(721,-139);
    glEnd();
    glBegin(GL_QUADS); //Cross Belt
    glColor3ub(224,224,224);
    glVertex2d(722,-167);
    glVertex2d(760,-217);
    glVertex2d(761,-209);
    glVertex2d(731,-163);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2d(753,-162);
    glVertex2d(720,-214);
    glVertex2d(724,-217);
    glVertex2d(759,-165);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(102,0,0);
    glVertex2d(721,-215);
    glVertex2d(761,-215);
    glVertex2d(761,-223);
    glVertex2d(720,-223);
    glEnd();
    glBegin(GL_QUADS); //Fita
    glColor3ub(0,51,0);
    glVertex2d(747,-153);
    glVertex2d(735,-134);
    glVertex2d(740,-133);
    glVertex2d(750,-151);
    glEnd();
    glBegin(GL_QUADS); //EYE
    glColor3ub(0,0,0);
    glVertex2d(752,-134);
    glVertex2d(757,-133);
    glVertex2d(758,-134);
    glVertex2d(753,-135);
    glEnd();
     glBegin(GL_POLYGON);//Rifle
    glColor3ub(55,28,0);
    glVertex2d(795,-201);
    glVertex2d(789,-249);
    glVertex2d(788,-254);
    glVertex2d(790,-262);
    glVertex2d(786,-275);
    glVertex2d(776,-277);
    glVertex2d(780,-254);
    glVertex2d(784,-251);
    glVertex2d(786,-208);
    glVertex2d(792,-206);
    glVertex2d(792,-181);
    glVertex2d(796,-181);
    glEnd();
      glBegin(GL_QUADS); //Mag
    glColor3ub(53,76,0);
    glVertex2d(786,-228);
    glVertex2d(778,-227);
    glVertex2d(777,-233);
    glVertex2d(785,-235);
    glEnd();
     glBegin(GL_QUADS); //Left Hand
    glColor3ub(51,102,0);
    glVertex2d(720,-168);
    glVertex2d(711,-174);
    glVertex2d(709,-219);
    glVertex2d(719,-219);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2d(709,-218);
    glVertex2d(709,-227);
    glVertex2d(719,-227);
    glVertex2d(720,-218);
    glEnd();
    glBegin(GL_QUADS); //Right Hand
    glColor3ub(51,102,0);
    glVertex2d(760,-165);
    glVertex2d(790,-188);
    glVertex2d(786,-196);
    glVertex2d(762,-180);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2d(790,-188);
    glVertex2d(788,-198);
    glVertex2d(794,-200);
    glVertex2d(797,-191);
    glEnd();

    //After Gun 2 ********************Army Right 2
glBegin(GL_POLYGON);//fig
    glColor3ub(51,102,0);
    glVertex2d(735,-461);
    glVertex2d(720,-468);
    glVertex2d(720,-526);
    glVertex2d(761,-526);
    glVertex2d(761,-468);
    glVertex2d(749,-461);
    glEnd();
    glBegin(GL_POLYGON);//Pant
    glColor3ub(0,51,0);
    glVertex2d(720,-526);
    glVertex2d(721,-560);
    glVertex2d(732,-559);
    glVertex2d(737,-535);
    glVertex2d(736,-525);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,51,0);
    glVertex2d(733,-526);
    glVertex2d(733,-536);
    glVertex2d(760,-537);
    glVertex2d(760,-525);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,51,0);
    glVertex2d(747,-536);
    glVertex2d(748,-561);
    glVertex2d(760,-560);
    glVertex2d(760,-535);
    glEnd();
    glBegin(GL_POLYGON);//L Boot
    glColor3ub(0,0,0);
    glVertex2d(731,-572);
    glVertex2d(731,-559);
    glVertex2d(720,-559);
    glVertex2d(720,-582);
    glVertex2d(742,-582);
    glVertex2d(742,-572);
    glEnd();
    glBegin(GL_POLYGON);//L Boot
    glColor3ub(0,0,0);
    glVertex2d(760,-572);
    glVertex2d(760,-559);
    glVertex2d(747,-559);
    glVertex2d(747,-582);
    glVertex2d(770,-582);
    glVertex2d(770,-572);
    glEnd();
    glBegin(GL_POLYGON);//head
    glColor3ub(255,128,0);
    glVertex2d(758,-440);
    glVertex2d(764,-440);
    glVertex2d(757,-428);
    glVertex2d(734,-434);
    glVertex2d(735,-462);
    glVertex2d(746,-462);
    glVertex2d(747,-449);
    glVertex2d(758,-450);
    glEnd();
     glBegin(GL_POLYGON);//Helmet
    glColor3ub(25,51,0);
    glVertex2d(768,-424);
    glVertex2d(765,-419);
    glVertex2d(754,-412);
    glVertex2d(743,-409);
    glVertex2d(726,-417);
    glVertex2d(721,-426);
    glVertex2d(721,-439);
    glEnd();
    glBegin(GL_QUADS); //Cross Belt
    glColor3ub(224,224,224);
    glVertex2d(722,-467);
    glVertex2d(760,-517);
    glVertex2d(761,-509);
    glVertex2d(731,-463);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2d(753,-462);
    glVertex2d(720,-514);
    glVertex2d(724,-517);
    glVertex2d(759,-465);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(102,0,0);
    glVertex2d(721,-515);
    glVertex2d(761,-515);
    glVertex2d(761,-523);
    glVertex2d(720,-523);
    glEnd();
    glBegin(GL_QUADS); //Fita
    glColor3ub(0,51,0);
    glVertex2d(747,-453);
    glVertex2d(735,-434);
    glVertex2d(740,-433);
    glVertex2d(750,-451);
    glEnd();
    glBegin(GL_QUADS); //EYE
    glColor3ub(0,0,0);
    glVertex2d(752,-434);
    glVertex2d(757,-433);
    glVertex2d(758,-434);
    glVertex2d(753,-435);
    glEnd();
     glBegin(GL_POLYGON);//Rifle
    glColor3ub(55,28,0);
    glVertex2d(795,-501);
    glVertex2d(789,-549);
    glVertex2d(788,-554);
    glVertex2d(790,-562);
    glVertex2d(786,-575);
    glVertex2d(776,-577);
    glVertex2d(780,-554);
    glVertex2d(784,-551);
    glVertex2d(786,-508);
    glVertex2d(792,-506);
    glVertex2d(792,-481);
    glVertex2d(796,-481);
    glEnd();
      glBegin(GL_QUADS); //Mag
    glColor3ub(53,76,0);
    glVertex2d(786,-528);
    glVertex2d(778,-527);
    glVertex2d(777,-533);
    glVertex2d(785,-535);
    glEnd();
     glBegin(GL_QUADS); //Left Hand
    glColor3ub(51,102,0);
    glVertex2d(720,-468);
    glVertex2d(711,-474);
    glVertex2d(709,-519);
    glVertex2d(719,-519);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2d(709,-518);
    glVertex2d(709,-527);
    glVertex2d(719,-527);
    glVertex2d(720,-518);
    glEnd();
    glBegin(GL_QUADS); //Right Hand
    glColor3ub(51,102,0);
    glVertex2d(760,-465);
    glVertex2d(790,-488);
    glVertex2d(786,-496);
    glVertex2d(762,-480);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2d(790,-488);
    glVertex2d(788,-498);
    glVertex2d(794,-500);
    glVertex2d(797,-491);
    glEnd();

       //Army Right 3 ************************************** After gun 3
    glBegin(GL_POLYGON);//fig
    glColor3ub(51,102,0);
    glVertex2d(735,-761);
    glVertex2d(720,-768);
    glVertex2d(720,-826);
    glVertex2d(761,-826);
    glVertex2d(761,-768);
    glVertex2d(749,-761);
    glEnd();
    glBegin(GL_POLYGON);//Pant
    glColor3ub(0,51,0);
    glVertex2d(720,-826);
    glVertex2d(721,-860);
    glVertex2d(732,-859);
    glVertex2d(737,-835);
    glVertex2d(736,-825);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,51,0);
    glVertex2d(733,-826);
    glVertex2d(733,-836);
    glVertex2d(760,-837);
    glVertex2d(760,-825);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,51,0);
    glVertex2d(747,-836);
    glVertex2d(748,-861);
    glVertex2d(760,-860);
    glVertex2d(760,-835);
    glEnd();
    glBegin(GL_POLYGON);//L Boot
    glColor3ub(0,0,0);
    glVertex2d(731,-872);
    glVertex2d(731,-859);
    glVertex2d(720,-859);
    glVertex2d(720,-882);
    glVertex2d(742,-882);
    glVertex2d(742,-872);
    glEnd();
    glBegin(GL_POLYGON);//L Boot
    glColor3ub(0,0,0);
    glVertex2d(760,-872);
    glVertex2d(760,-859);
    glVertex2d(747,-859);
    glVertex2d(747,-882);
    glVertex2d(770,-882);
    glVertex2d(770,-872);
    glEnd();
    glBegin(GL_POLYGON);//head
    glColor3ub(255,128,0);
    glVertex2d(758,-740);
    glVertex2d(764,-740);
    glVertex2d(757,-728);
    glVertex2d(734,-734);
    glVertex2d(735,-762);
    glVertex2d(746,-762);
    glVertex2d(747,-749);
    glVertex2d(758,-750);
    glEnd();
     glBegin(GL_POLYGON);//Helmet
    glColor3ub(25,51,0);
    glVertex2d(768,-724);
    glVertex2d(765,-719);
    glVertex2d(754,-712);
    glVertex2d(743,-709);
    glVertex2d(726,-717);
    glVertex2d(721,-726);
    glVertex2d(721,-739);
    glEnd();
    glBegin(GL_QUADS); //Cross Belt
    glColor3ub(224,224,224);
    glVertex2d(722,-767);
    glVertex2d(760,-817);
    glVertex2d(761,-809);
    glVertex2d(731,-763);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2d(753,-762);
    glVertex2d(720,-814);
    glVertex2d(724,-817);
    glVertex2d(759,-765);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(102,0,0);
    glVertex2d(721,-815);
    glVertex2d(761,-815);
    glVertex2d(761,-823);
    glVertex2d(720,-823);
    glEnd();
    glBegin(GL_QUADS); //Fita
    glColor3ub(0,51,0);
    glVertex2d(747,-753);
    glVertex2d(735,-734);
    glVertex2d(740,-733);
    glVertex2d(750,-751);
    glEnd();
    glBegin(GL_QUADS); //EYE
    glColor3ub(0,0,0);
    glVertex2d(752,-734);
    glVertex2d(757,-733);
    glVertex2d(758,-734);
    glVertex2d(753,-735);
    glEnd();
     glBegin(GL_POLYGON);//Rifle
    glColor3ub(55,28,0);
    glVertex2d(795,-801);
    glVertex2d(789,-849);
    glVertex2d(788,-854);
    glVertex2d(790,-862);
    glVertex2d(786,-875);
    glVertex2d(776,-877);
    glVertex2d(780,-854);
    glVertex2d(784,-851);
    glVertex2d(786,-808);
    glVertex2d(792,-806);
    glVertex2d(792,-781);
    glVertex2d(796,-781);
    glEnd();
      glBegin(GL_QUADS); //Mag
    glColor3ub(53,76,0);
    glVertex2d(786,-828);
    glVertex2d(778,-827);
    glVertex2d(777,-833);
    glVertex2d(785,-835);
    glEnd();
     glBegin(GL_QUADS); //Left Hand
     glColor3ub(51,102,0);
    glVertex2d(720,-768);
    glVertex2d(711,-774);
    glVertex2d(709,-819);
    glVertex2d(719,-819);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2d(709,-818);
    glVertex2d(709,-827);
    glVertex2d(719,-827);
    glVertex2d(720,-818);
    glEnd();
    glBegin(GL_QUADS); //Right Hand
    glColor3ub(51,102,0);
    glVertex2d(760,-765);
    glVertex2d(790,-788);
    glVertex2d(786,-796);
    glVertex2d(762,-780);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2d(790,-788);
    glVertex2d(788,-798);
    glVertex2d(794,-800);
    glVertex2d(797,-791);
    glEnd();



//****************** Left Side field *****************/////



     glPushMatrix();
    glTranslated(0.0,manmoving, 0.0);

////***** Man Figure 2 *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-846,-85);
    glVertex2d(-851,-78);
    glVertex2d(-856,-79);
    glVertex2d(-861,-89);
    glVertex2d(-862,-103);
    glVertex2d(-862,-118);
    glVertex2d(-859,-125);
    glVertex2d(-855,-129);
    glVertex2d(-850,-129);
    glVertex2d(-845,-122);
    glVertex2d(-844,-107);
    glVertex2d(-844,-93);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-858,-127);
    glVertex2d(-858,-146);
    glVertex2d(-848,-146);
    glVertex2d(-848,-127);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,150,0);
    glVertex2d(-841,-148);
    glVertex2d(-849,-145);
    glVertex2d(-856,-145);
    glVertex2d(-866,-147);
    glVertex2d(-866,-293);
    glVertex2d(-863,-299);
    glVertex2d(-860,-293);
    glVertex2d(-857,-247);
    glVertex2d(-849,-246);
    glVertex2d(-845,-296);
    glVertex2d(-841,-296);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(204,0,0);
    glVertex2d(-866,-216);
    glVertex2d(-867,-301);
    glVertex2d(-861,-301);
    glVertex2d(-854,-249);
    glVertex2d(-848,-248);
    glVertex2d(-844,-298);
    glVertex2d(-840,-298);
    glVertex2d(-841,-216);
    glVertex2d(-850,-222);
    glVertex2d(-859,-221);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,204,0);
    glVertex2d(-868,-221);
    glVertex2d(-865,-148);
    glVertex2d(-871,-163);
    glVertex2d(-873,-221);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,204,0);
    glVertex2d(-842,-147);
    glVertex2d(-840,-216);
    glVertex2d(-836,-215);
    glVertex2d(-838,-154);
    glEnd();

    ////***** Man Figure 5 *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-736,-85);
    glVertex2d(-741,-78);
    glVertex2d(-746,-79);
    glVertex2d(-751,-89);
    glVertex2d(-752,-103);
    glVertex2d(-752,-118);
    glVertex2d(-749,-125);
    glVertex2d(-745,-129);
    glVertex2d(-740,-129);
    glVertex2d(-735,-122);
    glVertex2d(-734,-107);
    glVertex2d(-734,-93);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-748,-127);
    glVertex2d(-748,-146);
    glVertex2d(-738,-146);
    glVertex2d(-738,-127);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-731,-148);
    glVertex2d(-739,-145);
    glVertex2d(-746,-145);
    glVertex2d(-756,-147);
    glVertex2d(-756,-293);
    glVertex2d(-753,-299);
    glVertex2d(-750,-293);
    glVertex2d(-747,-247);
    glVertex2d(-739,-246);
    glVertex2d(-735,-296);
    glVertex2d(-731,-296);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(255,0,0);
    glVertex2d(-756,-216);
    glVertex2d(-757,-301);
    glVertex2d(-751,-301);
    glVertex2d(-744,-249);
    glVertex2d(-738,-248);
    glVertex2d(-734,-298);
    glVertex2d(-730,-298);
    glVertex2d(-731,-216);
    glVertex2d(-740,-222);
    glVertex2d(-749,-221);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,0,255);
    glVertex2d(-758,-221);
    glVertex2d(-755,-148);
    glVertex2d(-761,-163);
    glVertex2d(-763,-221);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-732,-147);
    glVertex2d(-730,-216);
    glVertex2d(-726,-215);
    glVertex2d(-728,-154);
    glEnd();

//// Woman Figure 3////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-798,-85);
    glVertex2d(-802,-97);
    glVertex2d(-804,-114);
    glVertex2d(-804,-136);
    glVertex2d(-803,-158);
    glVertex2d(-798,-177);
    glVertex2d(-791,-189);
    glVertex2d(-785,-179);
    glVertex2d(-781,-141);
    glVertex2d(-780,-109);
    glVertex2d(-783,-90);
    glVertex2d(-790,-84);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(102,0,0);
    glVertex2d(-803,-151);
    glVertex2d(-809,-162);
    glVertex2d(-810,-232);
    glVertex2d(-807,-235);
    glVertex2d(-809,-274);
    glVertex2d(-796,-282);
    glVertex2d(-782,-280);
    glVertex2d(-780,-239);
    glVertex2d(-778,-237);
    glVertex2d(-776,-162);
    glVertex2d(-782,-151);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-809,-158);
    glVertex2d(-780,-232);
    glVertex2d(-780,-249);
    glVertex2d(-809,-187);
    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-804,-280);
    glVertex2d(-804,-302);
    glVertex2d(-799,-303);
    glVertex2d(-799,-282);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-792,-282);
    glVertex2d(-792,-304);
    glVertex2d(-786,-304);
    glVertex2d(-786,-283);
    glEnd();

    //// Woman Fig 1////    Left side upper
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-948,-85);
    glVertex2d(-952,-97);
    glVertex2d(-954,-114);
    glVertex2d(-954,-136);
    glVertex2d(-953,-158);
    glVertex2d(-948,-177);
    glVertex2d(-941,-189);
    glVertex2d(-935,-179);
    glVertex2d(-931,-141);
    glVertex2d(-930,-109);
    glVertex2d(-933,-90);
    glVertex2d(-940,-84);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-953,-151);
    glVertex2d(-959,-162);
    glVertex2d(-960,-232);
    glVertex2d(-957,-235);
    glVertex2d(-959,-274);
    glVertex2d(-946,-282);
    glVertex2d(-932,-280);
    glVertex2d(-930,-239);
    glVertex2d(-928,-237);
    glVertex2d(-926,-162);
    glVertex2d(-932,-151);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-959,-158);
    glVertex2d(-930,-232);
    glVertex2d(-930,-249);
    glVertex2d(-959,-187);
    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-954,-280);
    glVertex2d(-954,-302);
    glVertex2d(-949,-303);
    glVertex2d(-949,-282);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-942,-282);
    glVertex2d(-942,-304);
    glVertex2d(-936,-304);
    glVertex2d(-936,-283);
    glEnd();

      //// Woman Fig 4////    Left side upper
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-548,-85);
    glVertex2d(-552,-97);
    glVertex2d(-554,-114);
    glVertex2d(-554,-136);
    glVertex2d(-553,-158);
    glVertex2d(-548,-177);
    glVertex2d(-541,-189);
    glVertex2d(-535,-179);
    glVertex2d(-531,-141);
    glVertex2d(-530,-109);
    glVertex2d(-533,-90);
    glVertex2d(-540,-84);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,153,0);
    glVertex2d(-553,-151);
    glVertex2d(-559,-162);
    glVertex2d(-560,-232);
    glVertex2d(-557,-235);
    glVertex2d(-559,-274);
    glVertex2d(-546,-282);
    glVertex2d(-532,-280);
    glVertex2d(-530,-239);
    glVertex2d(-528,-237);
    glVertex2d(-526,-162);
    glVertex2d(-532,-151);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-559,-158);
    glVertex2d(-530,-232);
    glVertex2d(-530,-249);
    glVertex2d(-559,-187);
    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-554,-280);
    glVertex2d(-554,-302);
    glVertex2d(-549,-303);
    glVertex2d(-549,-282);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-542,-282);
    glVertex2d(-542,-304);
    glVertex2d(-536,-304);
    glVertex2d(-536,-283);
    glEnd();

////***** Man fig 8 *****//// Right down theke 2nd
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-546,-520);
    glVertex2d(-551,-513);
    glVertex2d(-556,-514);
    glVertex2d(-561,-524);
    glVertex2d(-562,-538);
    glVertex2d(-562,-538);
    glVertex2d(-559,-560);
    glVertex2d(-555,-564);
    glVertex2d(-550,-564);
    glVertex2d(-545,-557);
    glVertex2d(-544,-542);
    glVertex2d(-544,-528);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-558,-562);
    glVertex2d(-558,-581);
    glVertex2d(-548,-581);
    glVertex2d(-548,-562);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-541,-583);
    glVertex2d(-549,-580);
    glVertex2d(-556,-580);
    glVertex2d(-566,-582);
    glVertex2d(-566,-728);
    glVertex2d(-563,-734);
    glVertex2d(-560,-682);
    glVertex2d(-557,-682);
    glVertex2d(-549,-681);
    glVertex2d(-545,-731);
    glVertex2d(-541,-731);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(255,0,0);
    glVertex2d(-566,-651);
    glVertex2d(-567,-736);
    glVertex2d(-561,-736);
    glVertex2d(-554,-684);
    glVertex2d(-548,-683);
    glVertex2d(-544,-733);
    glVertex2d(-540,-733);
    glVertex2d(-541,-651);
    glVertex2d(-550,-657);
    glVertex2d(-559,-656);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,0,255);
    glVertex2d(-568,-656);
    glVertex2d(-565,-583);
    glVertex2d(-571,-598);
    glVertex2d(-573,-656);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-542,-582);
    glVertex2d(-540,-651);
    glVertex2d(-536,-650);
    glVertex2d(-538,-589);
    glEnd();

//// Woman fig 7////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-698,-485);
    glVertex2d(-702,-497);
    glVertex2d(-704,-514);
    glVertex2d(-704,-536);
    glVertex2d(-703,-558);
    glVertex2d(-698,-577);
    glVertex2d(-691,-589);
    glVertex2d(-685,-579);
    glVertex2d(-681,-541);
    glVertex2d(-680,-509);
    glVertex2d(-683,-490);
    glVertex2d(-690,-484);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,153,153);
    glVertex2d(-703,-551);
    glVertex2d(-709,-562);
    glVertex2d(-710,-632);
    glVertex2d(-707,-635);
    glVertex2d(-709,-674);
    glVertex2d(-696,-682);
    glVertex2d(-682,-680);
    glVertex2d(-680,-639);
    glVertex2d(-678,-637);
    glVertex2d(-676,-562);
    glVertex2d(-682,-551);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-709,-558);
    glVertex2d(-680,-632);
    glVertex2d(-680,-649);
    glVertex2d(-709,-587);
    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-704,-680);
    glVertex2d(-704,-702);
    glVertex2d(-699,-703);
    glVertex2d(-699,-682);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-692,-682);
    glVertex2d(-692,-704);
    glVertex2d(-686,-704);
    glVertex2d(-686,-683);
    glEnd();

////***** Man fig 9 *****//// Right side down one
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-546,-720);
    glVertex2d(-551,-713);
    glVertex2d(-556,-714);
    glVertex2d(-561,-724);
    glVertex2d(-562,-738);
    glVertex2d(-562,-738);
    glVertex2d(-559,-760);
    glVertex2d(-555,-764);
    glVertex2d(-550,-764);
    glVertex2d(-545,-757);
    glVertex2d(-544,-742);
    glVertex2d(-544,-728);
    glEnd();
glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-558,-762);
    glVertex2d(-558,-781);
    glVertex2d(-548,-781);
    glVertex2d(-548,-762);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,153,153);
    glVertex2d(-541,-783);
    glVertex2d(-549,-780);
    glVertex2d(-556,-780);
    glVertex2d(-566,-782);
    glVertex2d(-566,-928);
    glVertex2d(-563,-934);
    glVertex2d(-560,-882);
    glVertex2d(-557,-882);
    glVertex2d(-549,-881);
    glVertex2d(-545,-931);
    glVertex2d(-541,-931);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(102,0,102);
    glVertex2d(-566,-851);
    glVertex2d(-567,-936);
    glVertex2d(-561,-936);
    glVertex2d(-554,-884);
    glVertex2d(-548,-883);
    glVertex2d(-544,-933);
    glVertex2d(-540,-933);
    glVertex2d(-541,-851);
    glVertex2d(-550,-857);
    glVertex2d(-559,-856);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,0,255);
    glVertex2d(-568,-856);
    glVertex2d(-565,-783);
    glVertex2d(-571,-798);
    glVertex2d(-573,-856);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-542,-782);
    glVertex2d(-540,-851);
    glVertex2d(-536,-850);
    glVertex2d(-538,-789);
    glEnd();


 ////***** Man fig 13 *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-946,-720);
    glVertex2d(-951,-713);
    glVertex2d(-956,-714);
    glVertex2d(-961,-724);
    glVertex2d(-962,-738);
    glVertex2d(-962,-738);
    glVertex2d(-959,-760);
    glVertex2d(-955,-764);
    glVertex2d(-950,-764);
    glVertex2d(-945,-757);
    glVertex2d(-944,-742);
    glVertex2d(-944,-728);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-958,-762);
    glVertex2d(-958,-781);
    glVertex2d(-948,-781);
    glVertex2d(-948,-762);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-941,-783);
    glVertex2d(-949,-780);
    glVertex2d(-956,-780);
    glVertex2d(-966,-782);
    glVertex2d(-966,-928);
    glVertex2d(-963,-934);
    glVertex2d(-960,-882);
    glVertex2d(-957,-882);
    glVertex2d(-949,-881);
    glVertex2d(-945,-931);
    glVertex2d(-941,-931);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(255,0,0);
    glVertex2d(-966,-851);
    glVertex2d(-967,-936);
    glVertex2d(-961,-936);
    glVertex2d(-954,-884);
    glVertex2d(-948,-883);
    glVertex2d(-944,-933);
    glVertex2d(-940,-933);
    glVertex2d(-941,-851);
    glVertex2d(-950,-857);
    glVertex2d(-959,-856);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,0,255);
    glVertex2d(-968,-856);
    glVertex2d(-965,-783);
    glVertex2d(-971,-798);
    glVertex2d(-973,-856);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-942,-782);
    glVertex2d(-940,-851);
    glVertex2d(-936,-850);
    glVertex2d(-938,-789);
    glEnd();

     ////***** Man fig 16 *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-946,-320);
    glVertex2d(-951,-313);
    glVertex2d(-956,-314);
    glVertex2d(-961,-324);
    glVertex2d(-962,-338);
    glVertex2d(-962,-338);
    glVertex2d(-959,-360);
    glVertex2d(-955,-364);
    glVertex2d(-950,-364);
    glVertex2d(-945,-357);
    glVertex2d(-944,-342);
    glVertex2d(-944,-328);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-958,-362);
    glVertex2d(-958,-381);
    glVertex2d(-948,-381);
    glVertex2d(-948,-362);
    glEnd();
     glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-941,-383);
    glVertex2d(-949,-380);
    glVertex2d(-956,-380);
    glVertex2d(-966,-382);
    glVertex2d(-966,-528);
    glVertex2d(-963,-534);
    glVertex2d(-960,-482);
    glVertex2d(-957,-482);
    glVertex2d(-949,-481);
    glVertex2d(-945,-531);
    glVertex2d(-941,-531);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(102,0,102);
    glVertex2d(-966,-451);
    glVertex2d(-967,-536);
    glVertex2d(-961,-536);
    glVertex2d(-954,-484);
    glVertex2d(-948,-483);
    glVertex2d(-944,-533);
    glVertex2d(-940,-533);
    glVertex2d(-941,-451);
    glVertex2d(-950,-457);
    glVertex2d(-959,-456);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,0,255);
    glVertex2d(-968,-456);
    glVertex2d(-965,-383);
    glVertex2d(-971,-398);
    glVertex2d(-973,-456);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-942,-382);
    glVertex2d(-940,-451);
    glVertex2d(-936,-450);
    glVertex2d(-938,-389);
    glEnd();



     ////***** Man fig 15 *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-826,-620);
    glVertex2d(-831,-613);
    glVertex2d(-836,-614);
    glVertex2d(-841,-624);
    glVertex2d(-842,-638);
    glVertex2d(-842,-638);
    glVertex2d(-839,-660);
    glVertex2d(-835,-664);
    glVertex2d(-830,-664);
    glVertex2d(-825,-657);
    glVertex2d(-824,-642);
    glVertex2d(-824,-628);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-838,-662);
    glVertex2d(-838,-681);
    glVertex2d(-828,-681);
    glVertex2d(-828,-662);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-821,-683);
    glVertex2d(-829,-680);
    glVertex2d(-836,-680);
    glVertex2d(-846,-682);
    glVertex2d(-846,-828);
    glVertex2d(-843,-834);
    glVertex2d(-840,-782);
    glVertex2d(-837,-782);
    glVertex2d(-829,-781);
    glVertex2d(-825,-831);
    glVertex2d(-821,-831);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(255,0,0);
    glVertex2d(-846,-751);
    glVertex2d(-847,-836);
    glVertex2d(-841,-836);
    glVertex2d(-834,-784);
    glVertex2d(-828,-783);
    glVertex2d(-824,-833);
    glVertex2d(-820,-833);
    glVertex2d(-821,-751);
    glVertex2d(-830,-757);
    glVertex2d(-839,-756);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,0,255);
    glVertex2d(-848,-756);
    glVertex2d(-845,-683);
    glVertex2d(-851,-698);
    glVertex2d(-853,-756);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-822,-682);
    glVertex2d(-820,-751);
    glVertex2d(-816,-750);
    glVertex2d(-818,-689);
    glEnd();

     //// Woman fig 14////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-630,-385);
    glVertex2d(-632,-397);
    glVertex2d(-634,-414);
    glVertex2d(-634,-436);
    glVertex2d(-633,-458);
    glVertex2d(-628,-477);
    glVertex2d(-621,-489);
    glVertex2d(-615,-479);
    glVertex2d(-611,-441);
    glVertex2d(-610,-409);
    glVertex2d(-613,-390);
    glVertex2d(-620,-384);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(102,0,0);
    glVertex2d(-633,-451);
    glVertex2d(-639,-462);
    glVertex2d(-640,-532);
    glVertex2d(-637,-535);
    glVertex2d(-639,-574);
    glVertex2d(-626,-582);
    glVertex2d(-612,-580);
    glVertex2d(-610,-539);
    glVertex2d(-608,-537);
    glVertex2d(-606,-462);
    glVertex2d(-612,-451);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(0,102,0);
    glVertex2d(-639,-458);
    glVertex2d(-610,-532);
    glVertex2d(-610,-549);
    glVertex2d(-639,-487);
    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-634,-580);
    glVertex2d(-634,-602);
    glVertex2d(-629,-603);
    glVertex2d(-629,-582);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-622,-582);
    glVertex2d(-622,-604);
    glVertex2d(-616,-604);
    glVertex2d(-616,-583);
    glEnd();

//// Woman fig 10////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-650,-685);
    glVertex2d(-652,-697);
    glVertex2d(-654,-714);
    glVertex2d(-654,-736);
    glVertex2d(-653,-758);
    glVertex2d(-648,-777);
    glVertex2d(-641,-789);
    glVertex2d(-635,-779);
    glVertex2d(-631,-741);
    glVertex2d(-630,-709);
    glVertex2d(-633,-690);
    glVertex2d(-640,-684);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-653,-751);
    glVertex2d(-659,-762);
    glVertex2d(-660,-832);
    glVertex2d(-657,-835);
    glVertex2d(-659,-874);
    glVertex2d(-646,-882);
    glVertex2d(-632,-880);
    glVertex2d(-630,-839);
    glVertex2d(-628,-837);
    glVertex2d(-626,-762);
    glVertex2d(-632,-751);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-659,-758);
    glVertex2d(-630,-832);
    glVertex2d(-630,-849);
    glVertex2d(-659,-787);
    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-654,-880);
    glVertex2d(-654,-902);
    glVertex2d(-649,-903);
    glVertex2d(-649,-882);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-642,-882);
    glVertex2d(-642,-904);
    glVertex2d(-636,-904);
    glVertex2d(-636,-883);
    glEnd();





 //// Woman fig 12////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-898,-685);
    glVertex2d(-902,-697);
    glVertex2d(-904,-714);
    glVertex2d(-904,-736);
    glVertex2d(-903,-758);
    glVertex2d(-898,-777);
    glVertex2d(-891,-789);
    glVertex2d(-885,-779);
    glVertex2d(-881,-741);
    glVertex2d(-880,-709);
    glVertex2d(-883,-690);
    glVertex2d(-890,-684);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,102,55);
    glVertex2d(-903,-751);
    glVertex2d(-909,-762);
    glVertex2d(-910,-832);
    glVertex2d(-907,-835);
    glVertex2d(-909,-874);
    glVertex2d(-896,-882);
    glVertex2d(-882,-880);
    glVertex2d(-880,-839);
    glVertex2d(-878,-837);
    glVertex2d(-876,-762);
    glVertex2d(-882,-751);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-909,-758);
    glVertex2d(-880,-832);
    glVertex2d(-880,-849);
    glVertex2d(-909,-787);
    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-904,-880);
    glVertex2d(-904,-902);
    glVertex2d(-899,-903);
    glVertex2d(-899,-882);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-892,-882);
    glVertex2d(-892,-904);
    glVertex2d(-886,-904);
    glVertex2d(-886,-883);
    glEnd();


//// Banner 2 //////////
    ////***** Man Banner *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-928,-569);
    glVertex2d(-931,-585);
    glVertex2d(-926,-605);
    glVertex2d(-917,-606);
    glVertex2d(-913,-589);
    glVertex2d(-917,-568);
    glEnd();

    glBegin(GL_QUADS);//neck
    glColor3ub(255,229,204);
    glVertex2d(-926,-606);
    glVertex2d(-925,-622);
    glVertex2d(-917,-623);
    glVertex2d(-918,-606);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,102,55);
    glVertex2d(-925,-621);
    glVertex2d(-934,-623);
    glVertex2d(-934,-675);
    glVertex2d(-930,-674);
    glVertex2d(-932,-682);
    glVertex2d(-912,-680);
    glVertex2d(-911,-624);
    glVertex2d(-917,-622);

    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(102,0,0);
    glVertex2d(-919,-705);
    glVertex2d(-916,-741);
    glVertex2d(-911,-741);
    glVertex2d(-912,-677);
    glVertex2d(-933,-677);
    glVertex2d(-931,-743);
    glVertex2d(-926,-743);
    glVertex2d(-925,-705);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-913,-623);
    glVertex2d(-903,-589);
    glVertex2d(-899,-592);
    glVertex2d(-911,-634);
    glEnd();

//// Woman 1  Banner////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-757,-570);
    glVertex2d(-765,-570);
    glVertex2d(-767,-589);
    glVertex2d(-767,-589);
    glVertex2d(-766,-609);
    glVertex2d(-763,-636);
    glVertex2d(-757,-638);
    glVertex2d(-752,-637);
    glVertex2d(-751,-627);
    glVertex2d(-750,-612);
    glVertex2d(-748,-579);
    glVertex2d(-752,-567);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,102,55);
    glVertex2d(-746,-615);
    glVertex2d(-765,-613);
    glVertex2d(-765,-702);
    glVertex2d(-757,-708);
    glVertex2d(-748,-703);

    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-762,-706);
    glVertex2d(-763,-723);
    glVertex2d(-758,-724);
    glVertex2d(-757,-707);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-754,-706);
    glVertex2d(-755,-723);
    glVertex2d(-750,-723);
    glVertex2d(-751,-706);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-765,-617);
    glVertex2d(-747,-660);
    glVertex2d(-747,-669);
    glVertex2d(-766,-635);
    glEnd();
    glBegin(GL_QUADS);//left tHand
    glColor3ub(0,0,255);
    glVertex2d(-766,-615);
    glVertex2d(-778,-588);
    glVertex2d(-781,-594);
    glVertex2d(-766,-629);
    glEnd();


    ////***** Man fig 11 *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-746,-720);
    glVertex2d(-751,-713);
    glVertex2d(-756,-714);
    glVertex2d(-761,-724);
    glVertex2d(-762,-738);
    glVertex2d(-762,-738);
    glVertex2d(-759,-760);
    glVertex2d(-755,-764);
    glVertex2d(-750,-764);
    glVertex2d(-745,-757);
    glVertex2d(-744,-742);
    glVertex2d(-744,-728);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(255,229,204);
    glVertex2d(-758,-762);
    glVertex2d(-758,-781);
    glVertex2d(-748,-781);
    glVertex2d(-748,-762);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(0,0,255);
    glVertex2d(-741,-783);
    glVertex2d(-749,-780);
    glVertex2d(-756,-780);
    glVertex2d(-766,-782);
    glVertex2d(-766,-928);
    glVertex2d(-763,-934);
    glVertex2d(-760,-882);
    glVertex2d(-757,-882);
    glVertex2d(-749,-881);
    glVertex2d(-745,-931);
    glVertex2d(-741,-931);
    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(255,0,255);
    glVertex2d(-766,-851);
    glVertex2d(-767,-936);
    glVertex2d(-761,-936);
    glVertex2d(-754,-884);
    glVertex2d(-748,-883);
    glVertex2d(-744,-933);
    glVertex2d(-740,-933);
    glVertex2d(-741,-851);
    glVertex2d(-750,-857);
    glVertex2d(-759,-856);
    glEnd();
    glBegin(GL_QUADS);//leftHand
    glColor3ub(0,0,255);
    glVertex2d(-768,-856);
    glVertex2d(-765,-783);
    glVertex2d(-771,-798);
    glVertex2d(-773,-856);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(0,0,255);
    glVertex2d(-742,-782);
    glVertex2d(-740,-851);
    glVertex2d(-736,-850);
    glVertex2d(-738,-789);
    glEnd();

////**** Banner ****////
    glBegin(GL_QUADS);//frame
    glColor3ub(204,204,0);
    glVertex2d(-901,-396);
    glVertex2d(-901,-523);
    glVertex2d(-779,-523);
    glVertex2d(-779,-396);
    glEnd();
     glColor3f(204,204,0); //Text
    glBegin(GL_QUADS);
    glVertex2d(-701,-146);
    glVertex2d(-701,-273);
    glVertex2d(-579,-273);
    glVertex2d(-579,-146);
	glEnd();


    glPushMatrix();
    glTranslatef(0,-50, 0);
    Sprint(-901,-396,text);
    glPopMatrix();
    glBegin(GL_QUADS);//Handle L
    glColor3ub(102,51,0);
    glVertex2d(-902,-523);
    glVertex2d(-898,-523);
    glVertex2d(-898,-594);
    glVertex2d(-902,-594);
    glEnd();
    glBegin(GL_QUADS);//Handle R
    glColor3ub(102,51,0);
    glVertex2d(-779,-520);
    glVertex2d(-782,-520);
    glVertex2d(-782,-591);
    glVertex2d(-779,-591);
    glEnd();

    ////***** Man Banner *****////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-728,-319);
    glVertex2d(-731,-335);
    glVertex2d(-726,-355);
    glVertex2d(-717,-356);
    glVertex2d(-713,-339);
    glVertex2d(-717,-318);
    glEnd();

    glBegin(GL_QUADS);//neck
    glColor3ub(255,229,204);
    glVertex2d(-726,-356);
    glVertex2d(-725,-372);
    glVertex2d(-717,-373);
    glVertex2d(-718,-356);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(255,0,255);
    glVertex2d(-725,-371);
    glVertex2d(-734,-373);
    glVertex2d(-734,-425);
    glVertex2d(-730,-424);
    glVertex2d(-732,-432);
    glVertex2d(-712,-430);
    glVertex2d(-711,-374);
    glVertex2d(-717,-372);

    glEnd();
    glBegin(GL_POLYGON);// pant
    glColor3ub(0,0,255);
    glVertex2d(-719,-455);
    glVertex2d(-716,-491);
    glVertex2d(-711,-491);
    glVertex2d(-712,-427);
    glVertex2d(-733,-427);
    glVertex2d(-731,-493);
    glVertex2d(-726,-493);
    glVertex2d(-725,-455);
    glEnd();
    glBegin(GL_QUADS);//Right tHand
    glColor3ub(204,204,0);
    glVertex2d(-713,-373);
    glVertex2d(-703,-339);
    glVertex2d(-699,-342);
    glVertex2d(-711,-384);
    glEnd();

//// Woman 1  Banner////
    glBegin(GL_POLYGON);//Head
    glColor3ub(32,32,32);
    glVertex2d(-557,-320);
    glVertex2d(-565,-320);
    glVertex2d(-567,-339);
    glVertex2d(-567,-339);
    glVertex2d(-566,-359);
    glVertex2d(-563,-386);
    glVertex2d(-557,-388);
    glVertex2d(-552,-387);
    glVertex2d(-551,-377);
    glVertex2d(-550,-362);
    glVertex2d(-548,-329);
    glVertex2d(-552,-317);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(255,0,255);
    glVertex2d(-546,-365);
    glVertex2d(-565,-363);
    glVertex2d(-565,-452);
    glVertex2d(-557,-458);
    glVertex2d(-548,-453);

    glEnd();
    glBegin(GL_QUADS);//  L Feet
    glColor3ub(255,255,204);
    glVertex2d(-562,-456);
    glVertex2d(-563,-473);
    glVertex2d(-558,-474);
    glVertex2d(-557,-457);
    glEnd();
     glBegin(GL_QUADS);//  r Feet
    glColor3ub(255,255,204);
    glVertex2d(-554,-456);
    glVertex2d(-555,-473);
    glVertex2d(-550,-473);
    glVertex2d(-551,-456);
    glEnd();
    glBegin(GL_QUADS);// veil
    glColor3ub(255,0,0);
    glVertex2d(-565,-367);
    glVertex2d(-547,-410);
    glVertex2d(-547,-419);
    glVertex2d(-566,-385);
    glEnd();
    glBegin(GL_QUADS);//left tHand
    glColor3ub(0,0,255);
    glVertex2d(-566,-365);
    glVertex2d(-578,-338);
    glVertex2d(-581,-344);
    glVertex2d(-566,-379);
    glEnd();
////**** Banner ****////

    glColor3f(204,204,0); //Text
    glBegin(GL_QUADS);
    glVertex2d(-701,-146);
    glVertex2d(-701,-273);
    glVertex2d(-579,-273);
    glVertex2d(-579,-146);
	glEnd();


    glPushMatrix();
    glTranslatef(0,-50, 0);
    Sprint(-701,-146,text);
    glPopMatrix();

    glBegin(GL_QUADS);//Handle L
    glColor3ub(102,51,0);
    glVertex2d(-702,-273);
    glVertex2d(-698,-273);
    glVertex2d(-698,-344);
    glVertex2d(-702,-344);
    glEnd();
    glBegin(GL_QUADS);//Handle R
    glColor3ub(102,51,0);
    glVertex2d(-579,-270);
    glVertex2d(-582,-270);
    glVertex2d(-582,-341);
    glVertex2d(-579,-341);
    glEnd();

    glPopMatrix();


 bird();
	monuent();







    glFlush();
	glutSwapBuffers();
}



void evening()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //////////sky//////////////
    glBegin(GL_QUADS);
    glColor3ub(255,165,0);
    glVertex2d(-1000,1000);
    glColor3ub(221,160,221);
    glVertex2d(-1000,500);
    glColor3ub(128,0,0);
    glVertex2d(1000,500);
    glColor3ub(255,165,0);
    glVertex2d(1000,1000);
    glEnd();
     // sun

     circle(430, 680, 90, 100,255,69,0);


    // sun end//

    ////cloud1

     glPushMatrix();
    glTranslated(skyposition1,0.0, 0.0);
    circle(780, 900, 50, 100,255,255,0);

    //cloud1

    circle(840, 940, 50, 100, 255,255,0);


     //cloud1
     circle(860, 900, 50, 100, 255,255,0);


     //cloud1
     circle(800, 850, 50, 100, 255,255,0);
     glPopMatrix();

      glPushMatrix();
    glTranslated(skyposition,0.0, 0.0);
    //cloud2
    circle(350, 950, 90, 95, 255,255,0);

    //cloud2
    circle(250, 970, 65, 100, 255,255,0);

     //cloud2
     circle(440, 970, 65, 100, 255,255,0);


    circle(-400, 850, 60, 100, 255,255,0);


    //cloud 3...upper...
     circle(-470, 910, 50, 100, 255,255,0);


    //cloud 3....left....
     circle(-520, 850, 60, 100, 255,255,0);

    //cloud3.....down
     circle(-460, 800, 50, 100, 255,255,0);

    glPopMatrix();


//Cloud end//

    ////diganto////
    glBegin(GL_QUADS);
    glColor3ub(85,107,47);
    glVertex2d(-1000,500);
    glVertex2d(1000,500);
    glVertex2d(1000,600);
    glVertex2d(-1000,600);
    glEnd();
     circle(150, 580, 50, 100,85,107,47);
    circle(450, 580, 65, 100,85,107,47);
    circle(550, 580, 60, 100,85,107,47);
     circle(650, 580, 75, 100,85,107,47);
     circle(750, 600, 75, 100,85,107,47);
     circle(850, 580, 65, 100,85,107,47);
    circle(950, 580, 65, 100,85,107,47);

    

 
    circle(-150, 580, 50, 100,85,107,47);
    circle(-450, 580, 65, 100,85,107,47 );
    circle(-550, 580, 60, 100,85,107,47);
    circle(-650, 580, 75, 100,85,107,47 );

   circle(-750, 600, 75, 100, 85,107,47);
    circle(-850, 580, 65, 100,85,107,47);
   circle(-950, 580, 65, 100,85,107,47);
   circle(-250, 630, 65, 100,85,107,47);
   circle(-350, 600, 70, 100,85,107,47);


    
    glBegin(GL_QUADS);
    glColor3ub(160,82,45);
    glVertex2d(-1000,100);
    glColor3ub(160,82,45);
    glVertex2d(1000,100);
    glColor3ub(218,165,32);
    glVertex2d(1000,500);
    glColor3ub(218,165,32);
    glVertex2d(-1000,500);
    glEnd();

   

    //small tree1//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(720,360);
    glVertex2d(720,450);
    glVertex2d(730,450);
    glVertex2d(730,360);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(685,450);
    glVertex2d(765,450);
    glVertex2d(725,500);
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(690,492);
    glVertex2d(760,492);
    glVertex2d(725,530);
    glEnd();
    //small tree2//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(325,220);
    glVertex2d(340,220);
    glVertex2d(340,300);
    glVertex2d(325,300);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(290,300);
    glVertex2d(370,300);
    glVertex2d(330,350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(300,340);
    glVertex2d(360,340);
    glVertex2d(330,390);
    glEnd();
    //small tree3//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(445,200);
    glVertex2d(460,200);
    glVertex2d(460,310);
    glVertex2d(445,310);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(418,300);
    glVertex2d(487,300);
    glVertex2d(450,360);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(420,345);
    glVertex2d(480,345);
    glVertex2d(450,397);
    glEnd();
     //small tree4//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(540,100);
    glVertex2d(553,100);
    glVertex2d(553,190);
    glVertex2d(540,190);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(505,190);
    glVertex2d(590,190);
    glVertex2d(545,260);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(510,245);
    glVertex2d(580,245);
    glVertex2d(545,310);
    glEnd();
     //small tree5//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(770,100);
    glVertex2d(785,100);
    glVertex2d(785,190);
    glVertex2d(770,190);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(740,190);
    glVertex2d(810,190);
    glVertex2d(775,260);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(745,240);
    glVertex2d(805,240);
    glVertex2d(775,290);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(280,100);
    glVertex2d(500,100);
    glVertex2d(500,170);
    glVertex2d(280,170);
    glEnd();
    circle(250, 130, 55, 100, 73,153,0);
    circle(360, 175, 50, 100, 73,153,0);
    circle(460, 140, 50, 100, 73,153,0);


   //small grass2//

    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(850,100);
    glVertex2d(1000,100);
    glVertex2d(1000,150);
    glVertex2d(850,150);
    glEnd();

    circle(850, 125, 26, 50, 73,153,0);
    circle(900, 150, 35, 90, 73,153,0);
    circle(960, 140, 30, 100, 73,153,0);


    //small grass3//

    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(580,100);
    glVertex2d(730,100);
    glVertex2d(730,130);
    glVertex2d(580,130);
    glEnd();

    circle(650, 150, 40, 80, 73,153,0);
    circle(715, 130, 40, 80, 73,153,0);
    circle(605, 130, 40, 80, 73,153,0);



  //tree1//

  circle(930, 500, 60, 100, 0,128,0);
  circle(900, 450, 60, 100, 0,128,0);
    circle(980, 440, 60, 100, 0,128,0);

      circle(890, 380, 60, 100, 0,128,0);

      circle(955, 375, 65, 80, 0,128,0);


// tree...bar
 glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(900,100);
    glVertex2d(900,380);
    glVertex2d(930,380);
    glVertex2d(930,100);
    glEnd();
    // tree support
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(900,385);
    glVertex2d(910,400);
    glVertex2d(910,340);
    glVertex2d(900,380);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(935,380);
    glVertex2d(930,400);
    glVertex2d(920,400);
    glVertex2d(900,380);
    glEnd();//tree1 end//

    //tree2//
      circle(790, 345, 60, 100, 0,100,0);
      circle(820, 415, 55, 100, 0,100,0);

   circle(840, 340, 60, 100, 0,100,0);





// tree...bar
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(800,100);
    glVertex2d(800,340);
    glVertex2d(825,340);
    glVertex2d(825,100);
    glEnd();//treee2 end//


    //tree3//
    circle(600, 470, 55, 100, 0,100,0);
    circle(545, 410, 60, 100, 0,100,0);

     circle(650, 410, 60, 100, 0,100,0);
     circle(580, 350, 35, 100, 0,100,0);
     circle(625, 350, 35, 100, 0,100,0);

     // tree...bar
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(600,100);
    glVertex2d(600,340);
    glVertex2d(625,340);
    glVertex2d(625,100);
    glEnd();



     // tree support
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(625,345);
    glVertex2d(620,360);
    glVertex2d(615,360);
    glVertex2d(615,330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(600,340);
    glVertex2d(600,370);
    glVertex2d(608,370);
    glVertex2d(608,340);
    glEnd();
//grass field 01
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(720,250);
    glVertex2d(730,300);
    glVertex2d(710,250);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(710,250);
    glVertex2d(700,300);
    glVertex2d(690,250);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(690,250);
    glVertex2d(670,300);
    glVertex2d(680,250);
    glEnd();

   //grass field 02
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(270,350);
    glVertex2d(280,400);
    glVertex2d(260,350);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(260,350);
    glVertex2d(250,400);
    glVertex2d(240,350);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(240,350);
    glVertex2d(220,400);
    glVertex2d(230,350);
    glEnd();


//tree ////////////////////////////////////////////
 
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-758,300);
    glVertex2d(-758,430);
    glVertex2d(-742,430);
    glVertex2d(-742,300);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-800,400);
    glVertex2d(-750,480);
    glVertex2d(-700,400);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-790,445);
    glVertex2d(-750,520);
    glVertex2d(-710,445);
    glEnd();
    //Small tree  middle r upper right 02
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-438,330);
    glVertex2d(-438,430);
    glVertex2d(-422,430);
    glVertex2d(-422,330);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-478,430);
    glVertex2d(-430,480);
    glVertex2d(-382,430);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-468,470);
    glVertex2d(-430,530);
    glVertex2d(-392,470);
    glEnd();
    //Small tree  middle lower left 03 
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-808,150);
    glVertex2d(-808,250);
    glVertex2d(-792,250);
    glVertex2d(-792,150);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-848,250);
    glVertex2d(-800,300);
    glVertex2d(-752,250);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-838,290);
    glVertex2d(-800,350);
    glVertex2d(-762,290);
    glEnd();
//Small tree  middle lower left 04 
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-696,150);
    glVertex2d(-696,250);
    glVertex2d(-680,250);
    glVertex2d(-680,150);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-736,250);
    glVertex2d(-688,300);
    glVertex2d(-640,250);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-726,290);
    glVertex2d(-688,350);
    glVertex2d(-650,290);
    glEnd();
//small tree5 sufian //
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-200,440);
    glVertex2d(-215,440);
    glVertex2d(-215,340);
    glVertex2d(-200,340);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-160,430);
    glVertex2d(-250,430);
    glVertex2d(-205,480);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(-170,470);
    glVertex2d(-240,470);
    glVertex2d(-203,515);
    glEnd();
    /////////////////////////
// small grass 

    glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(-880,100);
    glVertex2d(-880,130);
    glVertex2d(-600,130);
    glVertex2d(-600,100);
    glEnd();
    circle(-860, 150, 50, 100,73,153,0);
     circle(-782, 150, 35, 100, 73,153,0);
     circle(-730, 140, 25, 100, 73,153,0);

     circle(-680, 130, 25, 100, 73,153,0);

     circle(-620, 150, 35, 100, 73,153,0);

      glBegin(GL_QUADS);
    glColor3ub(73,153,0);
    glVertex2d(-350,100);
    glVertex2d(-350,130);
    glVertex2d(-550,130);
    glVertex2d(-550,100);
    glEnd();

    circle(-386, 150, 35, 100, 73,153,0);
    circle(-450, 140, 40, 100, 73,153,0);
     circle(-782, 150, 35, 100, 73,153,0);
     circle(-520, 140, 40, 100, 73,153,0);



    // main big tree ....leaf
     circle(-530, 410, 70, 100, 0,100,0);
     circle(-530, 320, 30, 100, 0,100,0);

    circle(-600, 480, 70, 100, 0,100,0);
    circle(-650, 400, 70, 100, 0,100,0);
    circle(-620, 320, 40, 100, 0,100,0);

// tree...bar
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-600,100);
    glVertex2d(-600,370);
    glVertex2d(-550,370);
    glVertex2d(-550,100);
    glEnd();
// tree support
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-600,330);
    glVertex2d(-620,370);
    glVertex2d(-620,400);
    glVertex2d(-600,370);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-600,370);
    glVertex2d(-580,420);
    glVertex2d(-580,380);
    glVertex2d(-550,350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2d(-550,370);
    glVertex2d(-530,410);
    glVertex2d(-550,290);

    glEnd();
// tree left of main tree


//left leaf

    circle(-950, 350, 60, 100, 0,100,0);

    //upper leaf
     circle(-900, 450, 75, 100, 0,100,0);
    // lower leaf
     circle(-850, 350, 60, 100, 0,100,0);


    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-920,100);
    glVertex2d(-920,330);
    glVertex2d(-880,330);
    glVertex2d(-880,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2d(-920,330);
    glVertex2d(-940,400);
    glVertex2d(-900,330);
    glVertex2d(-900,450);
    glVertex2d(-890,330);
    glVertex2d(-860,400);
    glVertex2d(-880,330);
    glVertex2d(-920,330);
    glEnd();

// tree behind monument
//left leaf
 circle(-380, 280, 60, 100, 0,128,0);
 circle(-330, 390, 75, 100, 0,128,0);


    // left leaf
    circle(-290, 300, 70, 100, 0,128,0);

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-350,100);
    glVertex2d(-350,280);
    glVertex2d(-310,280);
    glVertex2d(-310,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2d(-350,280);
    glVertex2d(-370,350);
    glVertex2d(-330,280);
    glVertex2d(-330,400);
    glVertex2d(-310,280);
    glVertex2d(-280,350);
    glVertex2d(-300,290);
    glVertex2d(-350,280);
    glEnd();
    /////////////////////////////////

//grass field 01 
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(-500,200);
    glVertex2d(-510,250);
    glVertex2d(-490,200);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(-495,200);
    glVertex2d(-480,250);
    glVertex2d(-465,200);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(-470,200);
    glVertex2d(-450,250);
    glVertex2d(-460,200);

    glEnd();

    //grass field 02 
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(-970,150);
    glVertex2d(-980,200);
    glVertex2d(-960,150);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(-960,150);
    glVertex2d(-950,200);
    glVertex2d(-940,150);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(-940,150);
    glVertex2d(-920,200);
    glVertex2d(-930,150);

    glEnd();




    /////////1st stairs///////////
    glBegin(GL_QUADS);
    glColor3ub(220,220,220);
    glVertex2d(-1000,100);
    glVertex2d(1000,100);
    glVertex2d(1000,0);
    glVertex2d(-1000,0);
    glEnd();
     flower();
     

    /////////////lake
     glBegin(GL_QUADS);
	glColor3ub(205,133,63);
	glVertex2d(-500,0);
	glColor3ub(222,184,135);
	glVertex2d(-500,-1000);
	glColor3ub(244,164,96);
	glVertex2d(500,-1000);
	glColor3ub(210,105,30);
	glVertex2d(500,0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(65,105,225);
	glVertex2d(-460,-80);
	glColor3ub(25,25,112);
	glVertex2d(-460,-560);
	glColor3ub(65,105,225);
	glVertex2d(460,-560);
	glColor3ub(255,140,0);
	glVertex2d(460,-80);

	glEnd();

	/////////////waves

	glPushMatrix();
    glTranslated(watermoves1,0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3ub(135,206,235);
	glVertex2d(-450,-90);
	glVertex2d(-450,-100);
	glVertex2d(-460,-100);
	glVertex2d(-460,-90);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-300,-100);
	glVertex2d(-300,-110);
	glVertex2d(-380,-110);
	glVertex2d(-380,-100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-400,-200);
	glVertex2d(-400,-210);
	glVertex2d(-300,-210);
	glVertex2d(-300,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-400,-330);
	glVertex2d(-400,-320);
	glVertex2d(-300,-320);
	glVertex2d(-300,-330);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-460,-430);
	glVertex2d(-460,-420);
	glVertex2d(-360,-420);
	glVertex2d(-360,-430);
	glEnd();



	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-260,-430);
	glVertex2d(-260,-420);
	glVertex2d(-160,-420);
	glVertex2d(-160,-430);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-160,-230);
	glVertex2d(-160,-220);
	glVertex2d(-90,-220);
	glVertex2d(-90,-230);
	glEnd();
	//


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(300,-100);
	glVertex2d(300,-110);
	glVertex2d(380,-110);
	glVertex2d(380,-100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(400,-200);
	glVertex2d(400,-210);
	glVertex2d(300,-210);
	glVertex2d(300,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(400,-330);
	glVertex2d(400,-320);
	glVertex2d(300,-320);
	glVertex2d(300,-330);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(460,-430);
	glVertex2d(460,-420);
	glVertex2d(360,-420);
	glVertex2d(360,-430);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(260,-430);
	glVertex2d(260,-420);
	glVertex2d(160,-420);
	glVertex2d(160,-430);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(160,-230);
	glVertex2d(160,-220);
	glVertex2d(90,-220);
	glVertex2d(90,-230);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-200,-120);
	glVertex2d(-200,-130);
	glVertex2d(150,-130);
	glVertex2d(150,-120);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-200,-500);
	glVertex2d(-200,-510);
	glVertex2d(150,-510);
	glVertex2d(150,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-100,-400);
	glVertex2d(-100,-410);
	glVertex2d(120,-410);
	glVertex2d(120,-400);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-300,-520);
	glVertex2d(-300,-510);
	glVertex2d(-350,-510);
	glVertex2d(-350,-520);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-280,-290);
	glVertex2d(-280,-280);
	glVertex2d(-230,-280);
	glVertex2d(-230,-290);
	glEnd();
	glPopMatrix();
	////////shapla
    glPushMatrix();
    glTranslated(watermoves,0.0, 0.0);
    /////1
     circle(-400, -240, 40, 100, 107,142,35);

     glBegin(GL_POLYGON);

	glColor3ub(107,142,35);
	glVertex2d(-400,-200);
    glVertex2d(-440,-160);
    glVertex2d(-440,-230);
    glVertex2d(-360,-230);
    glVertex2d(-360,-160);
    glVertex2d(-400,-200);

	glEnd();

	/////2
	circle(0, -300, 40, 100, 107,142,35);

    glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(0,-260);
    glVertex2d(40,-220);
    glVertex2d(40,-290);
    glVertex2d(-40,-290);
    glVertex2d(-40,-220);
    glVertex2d(0,-260);

	glEnd();


	/////3
	circle(400, -500, 40, 100, 107,142,35);

     glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(400,-460);
    glVertex2d(440,-420);
    glVertex2d(440,-490);
    glVertex2d(360,-490);
    glVertex2d(360,-420);
    glVertex2d(400,-460);

	glEnd();
/////4
circle(200, -240, 40, 100, 107,142,35);

     glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(200,-200);
    glVertex2d(240,-160);
    glVertex2d(240,-230);
    glVertex2d(160,-230);
    glVertex2d(160,-160);
    glVertex2d(200,-200);

	glEnd();
	/////5
	circle(-200, -500, 40, 100, 107,142,35);


   glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(-200,-460);
    glVertex2d(-240,-420);
    glVertex2d(-240,-490);
    glVertex2d(-160,-490);
    glVertex2d(-160,-420);
    glVertex2d(-200,-460);
    glEnd();
	glPopMatrix();

///////////bricks////////////////
      glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(-500,-640);
	glVertex2d(-500,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-640);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-320,-640);
	glVertex2d(-320,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(-320,-640);
	glVertex2d(-320,-740);
	glVertex2d(-220,-740);
	glVertex2d(-220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-220,-640);
	glVertex2d(-220,-740);
	glVertex2d(-120,-740);
	glVertex2d(-120,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(-120,-640);
	glVertex2d(-120,-740);
	glVertex2d(-20,-740);
	glVertex2d(-20,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-20,-640);
	glVertex2d(-20,-740);
	glVertex2d(120,-740);
	glVertex2d(120,-640);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(120,-640);
	glVertex2d(120,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(320,-640);
	glVertex2d(320,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(420,-640);
	glVertex2d(420,-740);
	glVertex2d(320,-740);
	glVertex2d(320,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(500,-640);
	glVertex2d(500,-740);
	glVertex2d(420,-740);
	glVertex2d(420,-640);
	glEnd();

	///////


	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-500,-840);
	glVertex2d(-500,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-840);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//2
	glVertex2d(-320,-840);
	glVertex2d(-320,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-320,-840);
	glVertex2d(-320,-740);
	glVertex2d(-220,-740);
	glVertex2d(-220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//2
	glVertex2d(-220,-840);
	glVertex2d(-220,-740);
	glVertex2d(-120,-740);
	glVertex2d(-120,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(-120,-840);
	glVertex2d(-120,-740);
	glVertex2d(-20,-740);
	glVertex2d(-20,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//2
	glVertex2d(-20,-840);
	glVertex2d(-20,-740);
	glVertex2d(120,-740);
	glVertex2d(120,-840);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(120,-840);
	glVertex2d(120,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//2
	glVertex2d(320,-840);
	glVertex2d(320,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//1
	glVertex2d(420,-840);
	glVertex2d(420,-740);
	glVertex2d(320,-740);
	glVertex2d(320,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//2
	glVertex2d(500,-840);
	glVertex2d(500,-740);
	glVertex2d(420,-740);
	glVertex2d(420,-840);
	glEnd();
///////
     glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(-500,-840);
	glVertex2d(-500,-1000);
	glVertex2d(-420,-1000);
	glVertex2d(-420,-840);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-320,-840);
	glVertex2d(-320,-1000);
	glVertex2d(-420,-1000);
	glVertex2d(-420,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(-320,-840);
	glVertex2d(-320,-1000);
	glVertex2d(-220,-1000);
	glVertex2d(-220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-220,-840);
	glVertex2d(-220,-1000);
	glVertex2d(-120,-1000);
	glVertex2d(-120,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(-120,-840);
	glVertex2d(-120,-1000);
	glVertex2d(-20,-1000);
	glVertex2d(-20,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(-20,-840);
	glVertex2d(-20,-1000);
	glVertex2d(120,-1000);
	glVertex2d(120,-840);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(120,-840);
	glVertex2d(120,-1000);
	glVertex2d(220,-1000);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(320,-840);
	glVertex2d(320,-1000);
	glVertex2d(220,-1000);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(240,230,140);//1
	glVertex2d(420,-840);
	glVertex2d(420,-1000);
	glVertex2d(320,-1000);
	glVertex2d(320,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(189,183,107);//2
	glVertex2d(500,-840);
	glVertex2d(500,-1000);
	glVertex2d(420,-1000);
	glVertex2d(420,-840);
	glEnd();


	//////////human 1
	////////head
	circle(140, -500, 60, 100, 64,64,64);
    ////human1 body/////
    glBegin(GL_QUADS);
	glColor3ub	(210,105,30);//neck
	glVertex2d(150,-560);
	glVertex2d(150,-600);
	glVertex2d(130,-600);
	glVertex2d(130,-560);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(169,169,169);//shirt
	glVertex2d(90,-800);
	glVertex2d(90,-580);
	glColor3ub(128,128,128);
	glVertex2d(200,-580);
	glVertex2d(200,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,0,0);//belt
	glVertex2d(90,-800);
	glVertex2d(90,-810);
	glVertex2d(200,-810);
	glVertex2d(200,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(119,136,153);//pant1
	glVertex2d(90,-1000);
	glVertex2d(90,-810);
	glVertex2d(140,-810);
	glVertex2d(140,-1000);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(119,136,153);//pant2
	glVertex2d(200,-1000);
	glVertex2d(200,-810);
	glVertex2d(150,-810);
	glVertex2d(150,-1000);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(119,136,153);//pant3
	glVertex2d(140,-860);
	glVertex2d(140,-810);
	glVertex2d(150,-810);
	glVertex2d(150,-860);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(128,128,128);//hand1
	glVertex2d(200,-582);
	glVertex2d(200,-630);
	glVertex2d(215,-660);
	glVertex2d(235,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(128,128,128);//hand2
	glVertex2d(236,-800);
	glVertex2d(236,-640);
	glVertex2d(215,-620);
	glVertex2d(215,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);//hand3
	glVertex2d(90,-582);
	glVertex2d(90,-630);
	glVertex2d(75,-660);
	glVertex2d(55,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(169,169,169);//hand4
	glVertex2d(56,-800);
	glVertex2d(56,-640);
	glVertex2d(75,-620);
	glVertex2d(75,-800);
	glEnd();

	/////////flower
    glBegin(GL_TRIANGLES);
	glColor3ub(128,0,128);
	glVertex2d(225,-810);
	glVertex2d(205,-890);
	glVertex2d(245,-890);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(210,105,30);
	glVertex2d(236,-800);
	glVertex2d(236,-830);
	glVertex2d(215,-830);
	glVertex2d(215,-800);
	glEnd();

	circle(225, -920, 40, 100, 199,21,133);


    ///////human1 done/////

    ////////human2 start

     glBegin(GL_QUADS);
	glColor3ub	(210,105,30);//neck
	glVertex2d(-10,-720);
	glVertex2d(-10,-750);
	glVertex2d(-30,-750);
	glVertex2d(-30,-720);
	glEnd();
	circle(-20, -680, 50, 100, 0,0,0);

    glBegin(GL_TRIANGLES);
	glColor3ub(0,0,0);
	glVertex2d(-70,-680);
    glVertex2d(-90,-740);
    glVertex2d(-50,-710);
   	glEnd();

   	glBegin(GL_TRIANGLES);
	glColor3ub(0,0,0);
	glVertex2d(30,-680);
    glVertex2d(50,-740);
    glVertex2d(10,-710);
   	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(255,0,0);//body
	glVertex2d(20,-900);
	glVertex2d(20,-750);
	glVertex2d(-60,-750);
	glVertex2d(-60,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(0,100,0);//body
	glVertex2d(20,-900);
	glVertex2d(70,-1000);
	glVertex2d(-110,-1000);
	glVertex2d(-60,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,0,0);//hand1
	glVertex2d(20,-752);
	glVertex2d(20,-810);
	glVertex2d(55,-840);
	glVertex2d(30,-820);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,0,0);//hand2
	glVertex2d(50,-840);
	glVertex2d(30,-820);
	glVertex2d(56,-800);
	glVertex2d(75,-800);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,0,0);//hand3
	glVertex2d(-60,-752);
	glVertex2d(-60,-810);
	glVertex2d(-95,-840);
	glVertex2d(-70,-820);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,0,0);//hand4
	glVertex2d(-95,-840);
	glVertex2d(-80,-820);
	glVertex2d(-80,-720);
	glVertex2d(-95,-720);

	glEnd();

	//////human flag
	glBegin(GL_QUADS);
	glColor3ub(0,0,0);//1
	glVertex2d(-90,-550);
	glVertex2d(-85,-550);
	glVertex2d(-85,-720);
	glVertex2d(-90,-720);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(34,139,34);//2
	glVertex2d(-20,-550);
	glVertex2d(-85,-550);
	glVertex2d(-85,-630);
	glVertex2d(-20,-630);
	glEnd();

	circle(-52, -590, 20, 100, 255,0,0);





    //////////


	brick();
	

//*** right Side Field ***//





// First row shell  #########
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-164);
    glVertex2d(539,-197);
    glVertex2d(547,-197);
    glVertex2d(547,-164);
    glVertex2d(544,-166);
    glVertex2d(541,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-164);
    glVertex2d(546,-164);
    glVertex2d(545,-158);
    glVertex2d(543,-156);
    glVertex2d(542,-156);
    glVertex2d(541,-157);
    glVertex2d(539,-162);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-164);
    glVertex2d(550,-197);
    glVertex2d(558,-197);
    glVertex2d(558,-164);
    glVertex2d(555,-166);
    glVertex2d(552,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-164);
    glVertex2d(558,-164);
    glVertex2d(556,-158);
    glVertex2d(554,-156);
    glVertex2d(553,-156);
    glVertex2d(552,-157);
    glVertex2d(550,-162);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-164);
    glVertex2d(560,-197);
    glVertex2d(568,-197);
    glVertex2d(568,-164);
    glVertex2d(565,-166);
    glVertex2d(562,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-164);
    glVertex2d(568,-164);
    glVertex2d(566,-158);
    glVertex2d(564,-156);
    glVertex2d(563,-156);
    glVertex2d(562,-157);
    glVertex2d(560,-162);
    glEnd();

//1st Arty Gun//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-136);
    glVertex2d(751,-149);
    glVertex2d(853,-139);
    glVertex2d(851,-108);
    glVertex2d(842,-97);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-173);
    glVertex2d(624,-186);
    glVertex2d(624,-197);
    glVertex2d(637,-197);
    glVertex2d(647,-183);
    glVertex2d(796,-159);
    glVertex2d(800,-141);
    glVertex2d(645,-168);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-93);
    glVertex2d(788,-101);
    glVertex2d(794,-117);
    glVertex2d(842,-98);
    glVertex2d(831,-81);
    glVertex2d(809,-89);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-81);
    glVertex2d(835,-90);
    glVertex2d(909,-63);
    glVertex2d(908,-55);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-89);
    glVertex2d(842,-99);
    glVertex2d(958,-57);
    glVertex2d(954,-47);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-98);
    glVertex2d(850,-108);
    glVertex2d(919,-85);
    glVertex2d(914,-74);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(823,-122);
    glVertex2d(817,-124);
    glVertex2d(812,-124);
    glVertex2d(808,-126);
    glVertex2d(803,-130);
    glVertex2d(798,-134);
    glVertex2d(796,-139);
    glVertex2d(793,-144);
    glVertex2d(794,-153);
    glVertex2d(794,-161);
    glVertex2d(795,-168);
    glVertex2d(798,-175);
    glVertex2d(805,-184);
    glVertex2d(814,-193);
    glVertex2d(820,-196);
    glVertex2d(838,-196);
    glVertex2d(846,-195);
    glVertex2d(858,-188);
    glVertex2d(868,-178);
    glVertex2d(871,-171);
    glVertex2d(873,-162);
    glVertex2d(873,-152);
    glVertex2d(870,-145);
    glVertex2d(866,-139);
    glVertex2d(862,-133);
    glVertex2d(857,-129);
    glVertex2d(853,-125);
    glVertex2d(843,-121);
    glVertex2d(836,-120);
    glVertex2d(830,-120);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-133);
    glVertex2d(824,-135);
    glVertex2d(820,-138);
    glVertex2d(815,-144);
    glVertex2d(813,-148);
    glVertex2d(812,-154);
    glVertex2d(812,-160);
    glVertex2d(815,-169);
    glVertex2d(817,-173);
    glVertex2d(823,-180);
    glVertex2d(832,-183);
    glVertex2d(845,-180);
    glVertex2d(851,-175);
    glVertex2d(859,-168);
    glVertex2d(862,-161);
    glVertex2d(859,-146);
    glVertex2d(857,-142);
    glVertex2d(850,-136);
    glVertex2d(845,-133);
    glVertex2d(839,-131);
    glVertex2d(836,-131);
    glEnd();

// 2nd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-464);
    glVertex2d(539,-497);
    glVertex2d(547,-497);
    glVertex2d(547,-464);
    glVertex2d(544,-466);
    glVertex2d(541,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-464);
    glVertex2d(546,-464);
    glVertex2d(545,-458);
    glVertex2d(543,-456);
    glVertex2d(542,-456);
    glVertex2d(541,-457);
    glVertex2d(539,-462);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-464);
    glVertex2d(550,-497);
    glVertex2d(558,-497);
    glVertex2d(558,-464);
    glVertex2d(555,-466);
    glVertex2d(552,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-464);
    glVertex2d(558,-464);
    glVertex2d(556,-458);
    glVertex2d(554,-456);
    glVertex2d(553,-456);
    glVertex2d(552,-457);
    glVertex2d(550,-462);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-464);
    glVertex2d(560,-497);
    glVertex2d(568,-497);
    glVertex2d(568,-464);
    glVertex2d(565,-466);
    glVertex2d(562,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-464);
    glVertex2d(568,-464);
    glVertex2d(566,-458);
    glVertex2d(564,-456);
    glVertex2d(563,-456);
    glVertex2d(562,-457);
    glVertex2d(560,-462);
    glEnd();

//******* 2nd Arty Gun ******//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-436);
    glVertex2d(751,-449);
    glVertex2d(853,-439);
    glVertex2d(851,-408);
    glVertex2d(842,-397);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-473);
    glVertex2d(624,-486);
    glVertex2d(624,-497);
    glVertex2d(637,-497);
    glVertex2d(647,-483);
    glVertex2d(796,-459);
    glVertex2d(800,-441);
    glVertex2d(645,-468);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-393);
    glVertex2d(788,-401);
    glVertex2d(794,-417);
    glVertex2d(842,-398);
    glVertex2d(831,-381);
    glVertex2d(809,-389);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-381);
    glVertex2d(835,-390);
    glVertex2d(909,-363);
    glVertex2d(908,-355);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-389);
    glVertex2d(842,-399);
    glVertex2d(958,-357);
    glVertex2d(954,-347);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-398);
    glVertex2d(850,-408);
    glVertex2d(919,-385);
    glVertex2d(914,-374);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(823,-422);
    glVertex2d(817,-424);
    glVertex2d(812,-424);
    glVertex2d(808,-426);
    glVertex2d(803,-430);
    glVertex2d(798,-434);
    glVertex2d(796,-439);
    glVertex2d(793,-444);
    glVertex2d(794,-453);
    glVertex2d(794,-461);
    glVertex2d(795,-468);
    glVertex2d(798,-475);
    glVertex2d(805,-484);
    glVertex2d(814,-493);
    glVertex2d(820,-496);
    glVertex2d(838,-496);
    glVertex2d(846,-495);
    glVertex2d(858,-488);
    glVertex2d(868,-478);
    glVertex2d(871,-471);
    glVertex2d(873,-462);
    glVertex2d(873,-452);
    glVertex2d(870,-445);
    glVertex2d(866,-439);
    glVertex2d(862,-433);
    glVertex2d(857,-429);
    glVertex2d(853,-425);
    glVertex2d(843,-421);
    glVertex2d(836,-420);
    glVertex2d(830,-420);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-433);
    glVertex2d(824,-435);
    glVertex2d(820,-438);
    glVertex2d(815,-444);
    glVertex2d(813,-448);
    glVertex2d(812,-454);
    glVertex2d(812,-460);
    glVertex2d(815,-469);
    glVertex2d(817,-473);
    glVertex2d(823,-480);
    glVertex2d(832,-483);
    glVertex2d(845,-480);
    glVertex2d(851,-475);
    glVertex2d(859,-468);
    glVertex2d(862,-461);
    glVertex2d(859,-446);
    glVertex2d(857,-442);
    glVertex2d(850,-436);
    glVertex2d(845,-433);
    glVertex2d(839,-431);
    glVertex2d(836,-431);
    glEnd();



// 3rd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-764);
    glVertex2d(539,-797);
    glVertex2d(547,-797);
    glVertex2d(547,-764);
    glVertex2d(544,-766);
    glVertex2d(541,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-764);
    glVertex2d(546,-764);
    glVertex2d(545,-758);
    glVertex2d(543,-756);
    glVertex2d(542,-756);
    glVertex2d(541,-757);
    glVertex2d(539,-762);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-764);
    glVertex2d(550,-797);
    glVertex2d(558,-797);
    glVertex2d(558,-764);
    glVertex2d(555,-766);
    glVertex2d(552,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-764);
    glVertex2d(558,-764);
    glVertex2d(556,-758);
    glVertex2d(554,-756);
    glVertex2d(553,-756);
    glVertex2d(552,-757);
    glVertex2d(550,-762);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-764);
    glVertex2d(560,-797);
    glVertex2d(568,-797);
    glVertex2d(568,-764);
    glVertex2d(565,-766);
    glVertex2d(562,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-764);
    glVertex2d(568,-764);
    glVertex2d(566,-758);
    glVertex2d(564,-756);
    glVertex2d(563,-756);
    glVertex2d(562,-757);
    glVertex2d(560,-762);
    glEnd();

//***** 3rd Arty Gun *******//


    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-736);
    glVertex2d(751,-749);
    glVertex2d(853,-739);
    glVertex2d(851,-708);
    glVertex2d(842,-697);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-773);
    glVertex2d(624,-786);
    glVertex2d(624,-797);
    glVertex2d(637,-797);
    glVertex2d(647,-783);
    glVertex2d(796,-759);
    glVertex2d(800,-741);
    glVertex2d(645,-768);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-693);
    glVertex2d(788,-701);
    glVertex2d(794,-717);
    glVertex2d(842,-698);
    glVertex2d(831,-681);
    glVertex2d(809,-689);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-681);
    glVertex2d(835,-690);
    glVertex2d(909,-663);
    glVertex2d(908,-655);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-689);
    glVertex2d(842,-699);
    glVertex2d(958,-657);
    glVertex2d(954,-647);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-698);
    glVertex2d(850,-708);
    glVertex2d(919,-685);
    glVertex2d(914,-674);
    glEnd();
  glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(823,-722);
    glVertex2d(817,-724);
    glVertex2d(812,-724);
    glVertex2d(808,-726);
    glVertex2d(803,-730);
    glVertex2d(798,-734);
    glVertex2d(796,-739);
    glVertex2d(793,-744);
    glVertex2d(794,-753);
    glVertex2d(794,-761);
    glVertex2d(795,-768);
    glVertex2d(798,-775);
    glVertex2d(805,-784);
    glVertex2d(814,-793);
    glVertex2d(820,-796);
    glVertex2d(838,-796);
    glVertex2d(846,-795);
    glVertex2d(858,-788);
    glVertex2d(868,-778);
    glVertex2d(871,-771);
    glVertex2d(873,-762);
    glVertex2d(873,-752);
    glVertex2d(870,-745);
    glVertex2d(866,-739);
    glVertex2d(862,-733);
    glVertex2d(857,-729);
    glVertex2d(853,-725);
    glVertex2d(843,-721);
    glVertex2d(836,-720);
    glVertex2d(830,-720);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-733);
    glVertex2d(824,-735);
    glVertex2d(820,-738);
    glVertex2d(815,-744);
    glVertex2d(813,-748);
    glVertex2d(812,-754);
    glVertex2d(812,-760);
    glVertex2d(815,-769);
    glVertex2d(817,-773);
    glVertex2d(823,-780);
    glVertex2d(832,-783);
    glVertex2d(845,-780);
    glVertex2d(851,-775);
    glVertex2d(859,-768);
    glVertex2d(862,-761);
    glVertex2d(859,-746);
    glVertex2d(857,-742);
    glVertex2d(850,-736);
    glVertex2d(845,-733);
    glVertex2d(839,-731);
    glVertex2d(836,-731);
    glEnd();

    /////////////left/////////////////////


// First row shell  #########
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-539,-164);
    glVertex2d(-539,-197);
    glVertex2d(-547,-197);
    glVertex2d(-547,-164);
    glVertex2d(-544,-166);
    glVertex2d(-541,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-539,-164);
    glVertex2d(-546,-164);
    glVertex2d(-545,-158);
    glVertex2d(-543,-156);
    glVertex2d(-542,-156);
    glVertex2d(-541,-157);
    glVertex2d(-539,-162);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-550,-164);
    glVertex2d(-550,-197);
    glVertex2d(-558,-197);
    glVertex2d(-558,-164);
    glVertex2d(-555,-166);
    glVertex2d(-552,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-550,-164);
    glVertex2d(-558,-164);
    glVertex2d(-556,-158);
    glVertex2d(-554,-156);
    glVertex2d(-553,-156);
    glVertex2d(-552,-157);
    glVertex2d(-550,-162);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-560,-164);
    glVertex2d(-560,-197);
    glVertex2d(-568,-197);
    glVertex2d(-568,-164);
    glVertex2d(-565,-166);
    glVertex2d(-562,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-560,-164);
    glVertex2d(-568,-164);
    glVertex2d(-566,-158);
    glVertex2d(-564,-156);
    glVertex2d(-563,-156);
    glVertex2d(-562,-157);
    glVertex2d(-560,-162);
    glEnd();

//1st Arty Gun//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(-746,-136);
    glVertex2d(-751,-149);
    glVertex2d(-853,-139);
    glVertex2d(-851,-108);
    glVertex2d(-842,-97);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(-608,-173);
    glVertex2d(-624,-186);
    glVertex2d(-624,-197);
    glVertex2d(-637,-197);
    glVertex2d(-647,-183);
    glVertex2d(-796,-159);
    glVertex2d(-800,-141);
    glVertex2d(-645,-168);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(-811,-93);
    glVertex2d(-788,-101);
    glVertex2d(-794,-117);
    glVertex2d(-842,-98);
    glVertex2d(-831,-81);
    glVertex2d(-809,-89);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-830,-81);
    glVertex2d(-835,-90);
    glVertex2d(-909,-63);
    glVertex2d(-908,-55);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(-836,-89);
    glVertex2d(-842,-99);
    glVertex2d(-958,-57);
    glVertex2d(-954,-47);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-842,-98);
    glVertex2d(-850,-108);
    glVertex2d(-919,-85);
    glVertex2d(-914,-74);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(-823,-122);
    glVertex2d(-817,-124);
    glVertex2d(-812,-124);
    glVertex2d(-808,-126);
    glVertex2d(-803,-130);
    glVertex2d(-798,-134);
    glVertex2d(-796,-139);
    glVertex2d(-793,-144);
    glVertex2d(-794,-153);
    glVertex2d(-794,-161);
    glVertex2d(-795,-168);
    glVertex2d(-798,-175);
    glVertex2d(-805,-184);
    glVertex2d(-814,-193);
    glVertex2d(-820,-196);
    glVertex2d(-838,-196);
    glVertex2d(-846,-195);
    glVertex2d(-858,-188);
    glVertex2d(-868,-178);
    glVertex2d(-871,-171);
    glVertex2d(-873,-162);
    glVertex2d(-873,-152);
    glVertex2d(-870,-145);
    glVertex2d(-866,-139);
    glVertex2d(-862,-133);
    glVertex2d(-857,-129);
    glVertex2d(-853,-125);
    glVertex2d(-843,-121);
    glVertex2d(-836,-120);
    glVertex2d(-830,-120);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(-830,-133);
    glVertex2d(-824,-135);
    glVertex2d(-820,-138);
    glVertex2d(-815,-144);
    glVertex2d(-813,-148);
    glVertex2d(-812,-154);
    glVertex2d(-812,-160);
    glVertex2d(-815,-169);
    glVertex2d(-817,-173);
    glVertex2d(-823,-180);
    glVertex2d(-832,-183);
    glVertex2d(-845,-180);
    glVertex2d(-851,-175);
    glVertex2d(-859,-168);
    glVertex2d(-862,-161);
    glVertex2d(-859,-146);
    glVertex2d(-857,-142);
    glVertex2d(-850,-136);
    glVertex2d(-845,-133);
    glVertex2d(-839,-131);
    glVertex2d(-836,-131);
    glEnd();

// 2nd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-539,-464);
    glVertex2d(-539,-497);
    glVertex2d(-547,-497);
    glVertex2d(-547,-464);
    glVertex2d(-544,-466);
    glVertex2d(-541,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-539,-464);
    glVertex2d(-546,-464);
    glVertex2d(-545,-458);
    glVertex2d(-543,-456);
    glVertex2d(-542,-456);
    glVertex2d(-541,-457);
    glVertex2d(-539,-462);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-550,-464);
    glVertex2d(-550,-497);
    glVertex2d(-558,-497);
    glVertex2d(-558,-464);
    glVertex2d(-555,-466);
    glVertex2d(-552,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-550,-464);
    glVertex2d(-558,-464);
    glVertex2d(-556,-458);
    glVertex2d(-554,-456);
    glVertex2d(-553,-456);
    glVertex2d(-552,-457);
    glVertex2d(-550,-462);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-560,-464);
    glVertex2d(-560,-497);
    glVertex2d(-568,-497);
    glVertex2d(-568,-464);
    glVertex2d(-565,-466);
    glVertex2d(-562,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-560,-464);
    glVertex2d(-568,-464);
    glVertex2d(-566,-458);
    glVertex2d(-564,-456);
    glVertex2d(-563,-456);
    glVertex2d(-562,-457);
    glVertex2d(-560,-462);
    glEnd();

//******* 2nd Arty Gun ******//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(-746,-436);
    glVertex2d(-751,-449);
    glVertex2d(-853,-439);
    glVertex2d(-851,-408);
    glVertex2d(-842,-397);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(-608,-473);
    glVertex2d(-624,-486);
    glVertex2d(-624,-497);
    glVertex2d(-637,-497);
    glVertex2d(-647,-483);
    glVertex2d(-796,-459);
    glVertex2d(-800,-441);
    glVertex2d(-645,-468);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(-811,-393);
    glVertex2d(-788,-401);
    glVertex2d(-794,-417);
    glVertex2d(-842,-398);
    glVertex2d(-831,-381);
    glVertex2d(-809,-389);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-830,-381);
    glVertex2d(-835,-390);
    glVertex2d(-909,-363);
    glVertex2d(-908,-355);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(-836,-389);
    glVertex2d(-842,-399);
    glVertex2d(-958,-357);
    glVertex2d(-954,-347);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-842,-398);
    glVertex2d(-850,-408);
    glVertex2d(-919,-385);
    glVertex2d(-914,-374);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(-823,-422);
    glVertex2d(-817,-424);
    glVertex2d(-812,-424);
    glVertex2d(-808,-426);
    glVertex2d(-803,-430);
    glVertex2d(-798,-434);
    glVertex2d(-796,-439);
    glVertex2d(-793,-444);
    glVertex2d(-794,-453);
    glVertex2d(-794,-461);
    glVertex2d(-795,-468);
    glVertex2d(-798,-475);
    glVertex2d(-805,-484);
    glVertex2d(-814,-493);
    glVertex2d(-820,-496);
    glVertex2d(-838,-496);
    glVertex2d(-846,-495);
    glVertex2d(-858,-488);
    glVertex2d(-868,-478);
    glVertex2d(-871,-471);
    glVertex2d(-873,-462);
    glVertex2d(-873,-452);
    glVertex2d(-870,-445);
    glVertex2d(-866,-439);
    glVertex2d(-862,-433);
    glVertex2d(-857,-429);
    glVertex2d(-853,-425);
    glVertex2d(-843,-421);
    glVertex2d(-836,-420);
    glVertex2d(-830,-420);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(-830,-433);
    glVertex2d(-824,-435);
    glVertex2d(-820,-438);
    glVertex2d(-815,-444);
    glVertex2d(-813,-448);
    glVertex2d(-812,-454);
    glVertex2d(-812,-460);
    glVertex2d(-815,-469);
    glVertex2d(-817,-473);
    glVertex2d(-823,-480);
    glVertex2d(-832,-483);
    glVertex2d(-845,-480);
    glVertex2d(-851,-475);
    glVertex2d(-859,-468);
    glVertex2d(-862,-461);
    glVertex2d(-859,-446);
    glVertex2d(-857,-442);
    glVertex2d(-850,-436);
    glVertex2d(-845,-433);
    glVertex2d(-839,-431);
    glVertex2d(-836,-431);
    glEnd();



// 3rd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-539,-764);
    glVertex2d(-539,-797);
    glVertex2d(-547,-797);
    glVertex2d(-547,-764);
    glVertex2d(-544,-766);
    glVertex2d(-541,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-539,-764);
    glVertex2d(-546,-764);
    glVertex2d(-545,-758);
    glVertex2d(-543,-756);
    glVertex2d(-542,-756);
    glVertex2d(-541,-757);
    glVertex2d(-539,-762);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-550,-764);
    glVertex2d(-550,-797);
    glVertex2d(-558,-797);
    glVertex2d(-558,-764);
    glVertex2d(-555,-766);
    glVertex2d(-552,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-550,-764);
    glVertex2d(-558,-764);
    glVertex2d(-556,-758);
    glVertex2d(-554,-756);
    glVertex2d(-553,-756);
    glVertex2d(-552,-757);
    glVertex2d(-550,-762);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-560,-764);
    glVertex2d(-560,-797);
    glVertex2d(-568,-797);
    glVertex2d(-568,-764);
    glVertex2d(-565,-766);
    glVertex2d(-562,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-560,-764);
    glVertex2d(-568,-764);
    glVertex2d(-566,-758);
    glVertex2d(-564,-756);
    glVertex2d(-563,-756);
    glVertex2d(-562,-757);
    glVertex2d(-560,-762);
    glEnd();

//***** 3rd Arty Gun *******//


    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(-746,-736);
    glVertex2d(-751,-749);
    glVertex2d(-853,-739);
    glVertex2d(-851,-708);
    glVertex2d(-842,-697);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(-608,-773);
    glVertex2d(-624,-786);
    glVertex2d(-624,-797);
    glVertex2d(-637,-797);
    glVertex2d(-647,-783);
    glVertex2d(-796,-759);
    glVertex2d(-800,-741);
    glVertex2d(-645,-768);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(-811,-693);
    glVertex2d(-788,-701);
    glVertex2d(-794,-717);
    glVertex2d(-842,-698);
    glVertex2d(-831,-681);
    glVertex2d(-809,-689);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-830,-681);
    glVertex2d(-835,-690);
    glVertex2d(-909,-663);
    glVertex2d(-908,-655);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(-836,-689);
    glVertex2d(-842,-699);
    glVertex2d(-958,-657);
    glVertex2d(-954,-647);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-842,-698);
    glVertex2d(-850,-708);
    glVertex2d(-919,-685);
    glVertex2d(-914,-674);
    glEnd();
  glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(-823,-722);
    glVertex2d(-817,-724);
    glVertex2d(-812,-724);
    glVertex2d(-808,-726);
    glVertex2d(-803,-730);
    glVertex2d(-798,-734);
    glVertex2d(-796,-739);
    glVertex2d(-793,-744);
    glVertex2d(-794,-753);
    glVertex2d(-794,-761);
    glVertex2d(-795,-768);
    glVertex2d(-798,-775);
    glVertex2d(-805,-784);
    glVertex2d(-814,-793);
    glVertex2d(-820,-796);
    glVertex2d(-838,-796);
    glVertex2d(-846,-795);
    glVertex2d(-858,-788);
    glVertex2d(-868,-778);
    glVertex2d(-871,-771);
    glVertex2d(-873,-762);
    glVertex2d(-873,-752);
    glVertex2d(-870,-745);
    glVertex2d(-866,-739);
    glVertex2d(-862,-733);
    glVertex2d(-857,-729);
    glVertex2d(-853,-725);
    glVertex2d(-843,-721);
    glVertex2d(-836,-720);
    glVertex2d(-830,-720);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(-830,-733);
    glVertex2d(-824,-735);
    glVertex2d(-820,-738);
    glVertex2d(-815,-744);
    glVertex2d(-813,-748);
    glVertex2d(-812,-754);
    glVertex2d(-812,-760);
    glVertex2d(-815,-769);
    glVertex2d(-817,-773);
    glVertex2d(-823,-780);
    glVertex2d(-832,-783);
    glVertex2d(-845,-780);
    glVertex2d(-851,-775);
    glVertex2d(-859,-768);
    glVertex2d(-862,-761);
    glVertex2d(-859,-746);
    glVertex2d(-857,-742);
    glVertex2d(-850,-736);
    glVertex2d(-845,-733);
    glVertex2d(-839,-731);
    glVertex2d(-836,-731);
    glEnd();

      bird();
	monuent();



    glFlush();
	glutSwapBuffers();
}



void nights()
{
    glClear(GL_COLOR_BUFFER_BIT);


//////////sky//////////////
    glBegin(GL_QUADS);
    glColor3ub(25,25,112);
    glVertex2d(-1000,1000);
    glColor3ub(221,160,221);
    glVertex2d(-1000,500);
    glColor3ub(0,0,205);
    glVertex2d(1000,500);
    glColor3ub(25,25,112);
    glVertex2d(1000,1000);
    glEnd();
     // sun

     circle(960, 760, 80, 110,245,245,245);
     circle(1000, 760, 80, 50,0,0,205);


    // sun end//

    //  Cloud////cloud1
    glPushMatrix();
    glTranslated(skyposition,0.0, 0.0);
    circle(780, 900, 50, 100,220,220,220);

    //cloud1
    circle(840, 940, 50, 100,220,220,220);


     //cloud1
     circle(860, 900, 50, 100,220,220,220);


     //cloud1
     circle(800, 850, 50, 100, 220,220,220);

    //cloud2
    circle(350, 950, 90, 95,220,220,220);

    //cloud2
    circle(250, 970, 65, 100,220,220,220);

     //cloud2
     circle(440, 970, 65, 100,220,220,220);

//cloud 3..right
    circle(-400, 850, 60, 100,211,211,211);


    //cloud 3...upper...
     circle(-470, 910, 50, 100,211,211,211);


    //cloud 3....left....
     circle(-520, 850, 60, 100,211,211,211);

    //cloud3.....down
     circle(-460, 800, 50, 100,211,211,211);

    glPopMatrix();



    ////diganto////
    glBegin(GL_QUADS);
    glColor3ub(85,107,47);
    glVertex2d(-1000,500);
    glVertex2d(1000,500);
    glVertex2d(1000,600);
    glVertex2d(-1000,600);
    glEnd();
     circle(150, 580, 50, 100,85,107,47);
    circle(450, 580, 65, 100,85,107,47);
    circle(550, 580, 60, 100,85,107,47);
     circle(650, 580, 75, 100,85,107,47);
     circle(750, 600, 75, 100,85,107,47);
     circle(850, 580, 65, 100,85,107,47);
    circle(950, 580, 65, 100,85,107,47);

    circle(-150, 580, 50, 100,85,107,47);
    circle(-450, 580, 65, 100,85,107,47 );
    circle(-550, 580, 60, 100,85,107,47);
    circle(-650, 580, 75, 100,85,107,47 );

   circle(-750, 600, 75, 100, 85,107,47);
    circle(-850, 580, 65, 100,85,107,47);
   circle(-950, 580, 65, 100,85,107,47);
   circle(-250, 630, 65, 100,85,107,47);
   circle(-350, 600, 70, 100,85,107,47);


   
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-1000,100);
    glColor3ub(139,69,19);
    glVertex2d(1000,100);
    glColor3ub(218,165,32);
    glVertex2d(1000,500);
    glColor3ub(160,82,45);
    glVertex2d(-1000,500);
    glEnd();





    //small tree1//
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(720,360);
    glVertex2d(720,450);
      glColor3ub(139,69,19);
    glVertex2d(730,450);
    glVertex2d(730,360);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(685,450);
    glVertex2d(765,450);
    glVertex2d(725,500);
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(690,492);
    glVertex2d(760,492);
    glVertex2d(725,530);
    glEnd();
    //small tree2//
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(325,220);
     glColor3ub(139,69,19);
    glVertex2d(340,220);
    glVertex2d(340,300);
     glColor3ub(0,0,0);
    glVertex2d(325,300);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(290,300);
    glVertex2d(370,300);
    glVertex2d(330,350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(300,340);
    glVertex2d(360,340);
    glVertex2d(330,390);
    glEnd();
    //small tree3//
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(445,200);
     glColor3ub(0,0,0);
    glVertex2d(460,200);
    glVertex2d(460,310);
     glColor3ub(139,69,19);
    glVertex2d(445,310);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(418,300);
    glVertex2d(487,300);
    glVertex2d(450,360);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(420,345);
    glVertex2d(480,345);
    glVertex2d(450,397);
    glEnd();
     //small tree4//
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(540,100);
     glColor3ub(139,69,19);
    glVertex2d(553,100);
    glVertex2d(553,190);
     glColor3ub(0,0,0);
    glVertex2d(540,190);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(505,190);
    glVertex2d(590,190);
    glVertex2d(545,260);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(510,245);
    glVertex2d(580,245);
    glVertex2d(545,310);
    glEnd();
     //small tree5//
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(770,100);
     glColor3ub(139,69,19);
    glVertex2d(785,100);
    glVertex2d(785,190);
     glColor3ub(0,0,0);
    glVertex2d(770,190);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(740,190);
    glVertex2d(810,190);
    glVertex2d(775,260);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(745,240);
    glVertex2d(805,240);
    glVertex2d(775,290);
    glEnd();


//small grass before monument//
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2d(280,100);
    glVertex2d(500,100);
    glVertex2d(500,170);
    glVertex2d(280,170);
    glEnd();
    circle(250, 130, 55, 100,0,100,0);
    circle(360, 175, 50, 100,0,100,0);
    circle(460, 140, 50, 100,0,100,0);


   //small grass2//

    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2d(850,100);
    glVertex2d(1000,100);
    glVertex2d(1000,150);
    glVertex2d(850,150);
    glEnd();

    circle(850, 125, 26, 50, 0,100,0);
    circle(900, 150, 35, 90,0,100,0);
    circle(960, 140, 30, 100, 0,100,0);


    //small grass3//

    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2d(580,100);
    glVertex2d(730,100);
    glVertex2d(730,130);
    glVertex2d(580,130);
    glEnd();

    circle(650, 150, 40, 80,0,100,0);
    circle(715, 130, 40, 80, 0,100,0);
    circle(605, 130, 40, 80,0,100,0);



  //tree1//

  circle(930, 500, 60, 100, 0,128,0);
  circle(900, 450, 60, 100, 0,128,0);
    circle(980, 440, 60, 100, 0,128,0);

      circle(890, 380, 60, 100, 0,128,0);

      circle(955, 375, 65, 80, 0,128,0);


// tree...bar
 glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(900,100);
    glVertex2d(900,380);
    glColor3ub(139,69,19);
    glVertex2d(930,380);
    glVertex2d(930,100);
    glEnd();
    // tree support
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(900,385);
    glVertex2d(910,400);
    glVertex2d(910,340);
      glColor3ub(139,69,19);
    glVertex2d(900,380);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(935,380);
    glVertex2d(930,400);
    glVertex2d(920,400);
    glVertex2d(900,380);
    glEnd();//tree1 end//

    //tree2//
      circle(790, 345, 60, 100, 0,100,0);
      circle(820, 415, 55, 100, 0,100,0);

   circle(840, 340, 60, 100, 0,100,0);





// tree...bar
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(800,100);
    glVertex2d(800,340);
      glColor3ub(139,69,19);
    glVertex2d(825,340);
    glVertex2d(825,100);
    glEnd();//treee2 end//


    //tree3//
    circle(600, 470, 55, 100, 0,100,0);
    circle(545, 410, 60, 100, 0,100,0);

     circle(650, 410, 60, 100, 0,100,0);
     circle(580, 350, 35, 100, 0,100,0);
     circle(625, 350, 35, 100, 0,100,0);

     // tree...bar
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(600,100);
    glVertex2d(600,340);
       glColor3ub(0,0,0);
    glVertex2d(625,340);
    glVertex2d(625,100);
    glEnd();



     // tree support
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(625,345);
    glVertex2d(620,360);
    glVertex2d(615,360);
    glVertex2d(615,330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(600,340);
    glVertex2d(600,370);
    glVertex2d(608,370);
    glVertex2d(608,340);
    glEnd();
//grass field 01
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(720,250);
    glVertex2d(730,300);
    glVertex2d(710,250);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(710,250);
    glVertex2d(700,300);
    glVertex2d(690,250);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(690,250);
    glVertex2d(670,300);
    glVertex2d(680,250);
    glEnd();

   //grass field 02
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(270,350);
    glVertex2d(280,400);
    glVertex2d(260,350);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(260,350);
    glVertex2d(250,400);
    glVertex2d(240,350);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(240,350);
    glVertex2d(220,400);
    glVertex2d(230,350);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-758,300);
    glVertex2d(-758,430);
     glColor3ub(0,0,0);
    glVertex2d(-742,430);
    glVertex2d(-742,300);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-800,400);
    glVertex2d(-750,480);
    glVertex2d(-700,400);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-790,445);
    glVertex2d(-750,520);
    glVertex2d(-710,445);
    glEnd();
    //Small tree  middle r upper right 02 
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-438,330);
    glVertex2d(-438,430);
     glColor3ub(0,0,0);
    glVertex2d(-422,430);
    glVertex2d(-422,330);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-478,430);
    glVertex2d(-430,480);
    glVertex2d(-382,430);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-468,470);
    glVertex2d(-430,530);
    glVertex2d(-392,470);
    glEnd();
    //Small tree  middle lower left 03 
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-808,150);
    glVertex2d(-808,250);
     glColor3ub(0,0,0);
    glVertex2d(-792,250);
    glVertex2d(-792,150);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-848,250);
    glVertex2d(-800,300);
    glVertex2d(-752,250);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-838,290);
    glVertex2d(-800,350);
    glVertex2d(-762,290);
    glEnd();
//Small tree  middle lower left 04 
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-696,150);
    glVertex2d(-696,250);
     glColor3ub(0,0,0);
    glVertex2d(-680,250);
    glVertex2d(-680,150);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-736,250);
    glVertex2d(-688,300);
    glVertex2d(-640,250);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,136,34);
    glVertex2d(-726,290);
    glVertex2d(-688,350);
    glVertex2d(-650,290);
    glEnd();
//small tree5  //
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(-200,440);
     glColor3ub(139,69,19);
    glVertex2d(-215,440);
    glVertex2d(-215,340);
     glColor3ub(0,0,0);
    glVertex2d(-200,340);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(85,107,47);
    glVertex2d(-160,430);
    glVertex2d(-250,430);
    glVertex2d(-205,480);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(34,139,34);
    glVertex2d(-170,470);
    glVertex2d(-240,470);
    glVertex2d(-203,515);
    glEnd();
    /////////////////////////
// small grass 

    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2d(-880,100);
    glVertex2d(-880,130);
    glVertex2d(-600,130);
    glVertex2d(-600,100);
    glEnd();
    circle(-860, 150, 50, 100,0,100,0);
     circle(-782, 150, 35, 100,0,100,0);
     circle(-730, 140, 25, 100,0,100,0);

     circle(-680, 130, 25, 100,0,100,0);

     circle(-620, 150, 35, 100, 0,100,0);

      glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2d(-350,100);
    glVertex2d(-350,130);
    glVertex2d(-550,130);
    glVertex2d(-550,100);
    glEnd();

    circle(-386, 150, 35, 100, 0,100,0);
    circle(-450, 140, 40, 100, 0,100,0);
     circle(-782, 150, 35, 100, 0,100,0);
     circle(-520, 140, 40, 100, 0,100,0);



    // main big tree ....leaf
     circle(-530, 410, 70, 100, 0,100,0);
     circle(-530, 320, 30, 100, 0,100,0);

    circle(-600, 480, 70, 100, 0,100,0);
    circle(-650, 400, 70, 100, 0,100,0);
    circle(-620, 320, 40, 100, 0,100,0);

// tree...bar
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(-600,100);

    glVertex2d(-600,370);
 glColor3ub(139,69,19);
    glVertex2d(-550,370);

    glVertex2d(-550,100);
    glEnd();
// tree support
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(-600,330);
    glColor3ub(139,69,19);
    glVertex2d(-620,370);

    glVertex2d(-620,400);
    glVertex2d(-600,370);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2d(-600,370);
    glVertex2d(-580,420);
    glVertex2d(-580,380);
    glVertex2d(-550,350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2d(-550,370);
    glVertex2d(-530,410);
     glColor3ub(0,0,0);
    glVertex2d(-550,290);

    glEnd();
// tree left of main tree


//left leaf

    circle(-950, 350, 60, 100, 0,100,0);

    //upper leaf
     circle(-900, 450, 75, 100, 0,100,0);
    // lower leaf
     circle(-850, 350, 60, 100, 0,100,0);


    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(-920,100);
    glVertex2d(-920,330);
     glColor3ub(139,69,19);
    glVertex2d(-880,330);
    glVertex2d(-880,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-920,330);
     glColor3ub(139,69,19);
    glVertex2d(-940,400);
    glVertex2d(-900,330);
    glVertex2d(-900,450);
    glVertex2d(-890,330);
    glVertex2d(-860,400);
    glVertex2d(-880,330);
    glVertex2d(-920,330);
    glEnd();

// tree behind monument
//left leaf
 circle(-380, 280, 60, 100, 0,128,0);
 circle(-330, 390, 75, 100, 0,128,0);


    // left leaf
    circle(-290, 300, 70, 100, 0,128,0);

        glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(-350,100);
    glVertex2d(-350,280);
     glColor3ub(139,69,19);
    glVertex2d(-310,280);
    glVertex2d(-310,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-350,280);
    glVertex2d(-370,350);
      glColor3ub(139,69,19);
    glVertex2d(-330,280);
    glVertex2d(-330,400);
    glVertex2d(-310,280);
    glVertex2d(-280,350);
    glVertex2d(-300,290);
    glVertex2d(-350,280);
    glEnd();

    /////////////////////////////////







//grass field 01 
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(-500,200);
    glVertex2d(-510,250);
    glVertex2d(-490,200);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(-495,200);
    glVertex2d(-480,250);
    glVertex2d(-465,200);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(-470,200);
    glVertex2d(-450,250);
    glVertex2d(-460,200);

    glEnd();

    //grass field 02 
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(-970,150);
    glVertex2d(-980,200);
    glVertex2d(-960,150);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(34,139,34);
    glVertex2d(-960,150);
    glVertex2d(-950,200);
    glVertex2d(-940,150);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(-940,150);
    glVertex2d(-920,200);
    glVertex2d(-930,150);

    glEnd();






    /////////1st stairs///////////
    glBegin(GL_QUADS);
    glColor3ub(220,220,220);
    glVertex2d(-1000,100);
    glVertex2d(1000,100);
    glVertex2d(1000,0);
    glVertex2d(-1000,0);
    glEnd();

   
    //flower//
    circle(50, 50, 50, 100, 255,255,0);
    circle(150, 50, 50, 100, 127,255,0);

    GLdouble x87=250;
    GLdouble y87=50;
    GLdouble radius87=50;
    int triangleAmount87 = 100;
    GLfloat twicePi87 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,69,0);
    glVertex2f(x87, y87); // center of circle
    for(int i = 0; i <= triangleAmount87; i++)
    {

        glVertex2f( x87+ (radius87* cos(i *  twicePi87 / triangleAmount87)),
                    y87 + (radius87 * sin(i * twicePi87 / triangleAmount87)));
    }
    glEnd();
     GLdouble x88 =350;
    GLdouble y88=50;
    GLdouble radius88=50;
    int triangleAmount88 = 100;
    GLfloat twicePi88= 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,139);
    glVertex2f(x88, y88); // center of circle
    for(int i = 0; i <= triangleAmount88; i++)
    {

        glVertex2f( x88+ (radius88 * cos(i *  twicePi88/ triangleAmount88)),
                    y88 + (radius88 * sin(i * twicePi88 / triangleAmount88)));
    }
    glEnd();
    GLdouble x89=450;
    GLdouble y89=50;
    GLdouble radius89=50;
    int triangleAmount89 = 100;
    GLfloat twicePi89 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,100,0);
    glVertex2f(x89, y89); // center of circle
    for(int i = 0; i <= triangleAmount89; i++)
    {

        glVertex2f( x89+ (radius89 * cos(i *  twicePi89 / triangleAmount89)),
                    y89 + (radius89 * sin(i * twicePi89 / triangleAmount89)));
    }
    glEnd();
    GLdouble x90=550;
    GLdouble y90=50;
    GLdouble radius90=50;
    int triangleAmount90 = 100;
    GLfloat twicePi90 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,250,154);
    glVertex2f(x90, y90); // center of circle
    for(int i = 0; i <= triangleAmount90; i++)
    {

        glVertex2f( x90+ (radius90 * cos(i *  twicePi90/ triangleAmount90)),
                    y90 + (radius90 * sin(i * twicePi90 / triangleAmount90)));
    }
    glEnd();
    GLdouble x91=650;
    GLdouble y91=50;
    GLdouble radius91=50;
    int triangleAmount91 = 100;
    GLfloat twicePi91 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139,69,19);
    glVertex2f(x91, y91); // center of circle
    for(int i = 0; i <= triangleAmount91; i++)
    {

        glVertex2f( x91+ (radius91 * cos(i *  twicePi91 / triangleAmount91)),
                    y91 + (radius91 * sin(i * twicePi91 / triangleAmount91)));
    }
    glEnd();
    GLdouble x92=750;
    GLdouble y92=50;
    GLdouble radius92=50;
    int triangleAmount92 = 100;
    GLfloat twicePi92 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,0,0);
    glVertex2f(x92, y92); // center of circle
    for(int i = 0; i <= triangleAmount92; i++)
    {

        glVertex2f( x92+ (radius92 * cos(i *  twicePi92 / triangleAmount92)),
                    y92 + (radius92 * sin(i * twicePi92 / triangleAmount92)));
    }
    glEnd();
    GLdouble x93=850;
    GLdouble y93=50;
    GLdouble radius93=50;
    int triangleAmount93 = 100;
    GLfloat twicePi93 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,0);
    glVertex2f(x93, y93); // center of circle
    for(int i = 0; i <= triangleAmount93; i++)
    {

        glVertex2f( x93+ (radius93 * cos(i *  twicePi93 / triangleAmount93)),
                    y93 + (radius93 * sin(i * twicePi93 / triangleAmount93)));
    }
    glEnd();
    GLdouble x94=950;
    GLdouble y94=50;
    GLdouble radius94=50;
    int triangleAmount94 = 100;
    GLfloat twicePi94 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,69,0);
    glVertex2f(x94, y94); // center of circle
    for(int i = 0; i <= triangleAmount94; i++)
    {

        glVertex2f( x94+ (radius94 * cos(i *  twicePi94 / triangleAmount94)),
                    y94 + (radius94* sin(i * twicePi94 / triangleAmount94)));
    }
    glEnd();
    GLdouble x95=50;
    GLdouble y95=50;
    GLdouble radius95=20;
    int triangleAmount95 = 100;
    GLfloat twicePi95 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(x95, y95); // center of circle
    for(int i = 0; i <= triangleAmount95; i++)
    {

        glVertex2f( x95+ (radius95 * cos(i *  twicePi95/ triangleAmount95)),
                    y95 + (radius95 * sin(i * twicePi95 / triangleAmount95)));
    }
    glEnd();
    GLdouble x96=150;
    GLdouble y96=50;
    GLdouble radius96=20;
    int triangleAmount96 = 100;
    GLfloat twicePi96 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,140,0);
    glVertex2f(x96, y96); // center of circle
    for(int i = 0; i <= triangleAmount96; i++)
    {

        glVertex2f( x96+ (radius96 * cos(i *  twicePi96 / triangleAmount96)),
                    y96 + (radius96 * sin(i * twicePi96 / triangleAmount96)));
    }
    glEnd();
    GLdouble x97=250;
    GLdouble y97=50;
    GLdouble radius97=20;
    int triangleAmount97 = 100;
    GLfloat twicePi97 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,215,0);
    glVertex2f(x97, y97); // center of circle
    for(int i = 0; i <= triangleAmount97; i++)
    {

        glVertex2f( x97+ (radius97 * cos(i *  twicePi97 / triangleAmount97)),
                    y97 + (radius97 * sin(i * twicePi97 / triangleAmount97)));
    }
    glEnd();
    GLdouble x98=350;
    GLdouble y98=50;
    GLdouble radius98=20;
    int triangleAmount98 = 100;
    GLfloat twicePi98 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128,0,0);
    glVertex2f(x98, y98); // center of circle
    for(int i = 0; i <= triangleAmount98; i++)
    {

        glVertex2f( x98+ (radius98 * cos(i *  twicePi98 / triangleAmount98)),
                    y98 + (radius98 * sin(i * twicePi98 / triangleAmount98)));
    }
    glEnd();
    GLdouble x99=450;
    GLdouble y99=50;
    GLdouble radius99=20;
    int triangleAmount99 = 100;
    GLfloat twicePi99 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1,0,0);
    glVertex2f(x99, y99); // center of circle
    for(int i = 0; i <= triangleAmount99; i++)
    {

        glVertex2f( x99+ (radius99 * cos(i *  twicePi99 / triangleAmount99)),
                    y99 + (radius99 * sin(i * twicePi99 / triangleAmount99)));
    }
    glEnd();
    GLdouble x100=550;
    GLdouble y100=50;
    GLdouble radius100=20;
    int triangleAmount100 = 100;
    GLfloat twicePi100 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128,0,128);
    glVertex2f(x100, y100); // center of circle
    for(int i = 0; i <= triangleAmount100; i++)
    {

        glVertex2f( x100+ (radius100 * cos(i *  twicePi100 / triangleAmount100)),
                    y100+ (radius100 * sin(i * twicePi100 / triangleAmount100)));
    }
    glEnd();
    GLdouble x101=650;
    GLdouble y101=50;
    GLdouble radius101=20;
    int triangleAmount101 = 100;
    GLfloat twicePi101 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,128);
    glVertex2f(x101, y101); // center of circle
    for(int i = 0; i <= triangleAmount101; i++)
    {

        glVertex2f( x101+ (radius101* cos(i *  twicePi101/ triangleAmount101)),
                    y101 + (radius101 * sin(i * twicePi101 / triangleAmount101)));
    }
    glEnd();
    GLdouble x102=750;
    GLdouble y102=50;
    GLdouble radius102=20;
    int triangleAmount102 = 100;
    GLfloat twicePi102 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,20,147);
    glVertex2f(x102, y102); // center of circle
    for(int i = 0; i <= triangleAmount102; i++)
    {

        glVertex2f( x102+ (radius102 * cos(i *  twicePi102 / triangleAmount102)),
                    y102+ (radius102 * sin(i * twicePi102 / triangleAmount102)));
    }
    glEnd();
    GLdouble x103=850;
    GLdouble y103=50;
    GLdouble radius103=20;
    int triangleAmount103 = 100;
    GLfloat twicePi103 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,165,0);
    glVertex2f(x103, y103); // center of circle
    for(int i = 0; i <= triangleAmount103; i++)
    {

        glVertex2f( x103+ (radius103* cos(i *  twicePi103/ triangleAmount103)),
                    y103+ (radius103* sin(i * twicePi103 / triangleAmount103)));
    }
    glEnd();
    GLdouble x104=950;
    GLdouble y104=50;
    GLdouble radius104=20;
    int triangleAmount104 = 100;
    GLfloat twicePi104 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153,50,204);
    glVertex2f(x104, y104); // center of circle
    for(int i = 0; i <= triangleAmount104; i++)
    {

        glVertex2f( x104+ (radius104 * cos(i *  twicePi104 / triangleAmount104)),
                    y104 + (radius104 * sin(i * twicePi104 / triangleAmount104)));
    }
    glEnd();
    ///////////////Flower ////////////////////




     //flower// // 
    GLdouble x105=-50;
    GLdouble y105=50;
    GLdouble radius105=50;
    int triangleAmount105 = 100;
    GLfloat twicePi105 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,20,147);
    glVertex2f(x105, y105); // center of circle
    for(int i = 0; i <= triangleAmount105; i++)
    {

        glVertex2f( x105+ (radius105 * cos(i *  twicePi105 / triangleAmount105)),
                    y105 + (radius105 * sin(i * twicePi105 / triangleAmount105)));
    }
    glEnd();
    GLdouble x106=-150;
    GLdouble y106=50;
    GLdouble radius106=50;
    int triangleAmount106 = 100;
    GLfloat twicePi106 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(127,255,0);
    glVertex2f(x106, y106); // center of circle
    for(int i = 0; i <= triangleAmount106; i++)
    {

        glVertex2f( x106+ (radius106 * cos(i *  twicePi106 / triangleAmount106)),
                    y106 + (radius106 * sin(i * twicePi106 / triangleAmount106)));
    }
    glEnd();
   GLdouble x107=-250;
    GLdouble y107=50;
    GLdouble radius107=50;
    int triangleAmount107 = 100;
    GLfloat twicePi107 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,69,0);
    glVertex2f(x107, y107); // center of circle
    for(int i = 0; i <= triangleAmount107; i++)
    {

        glVertex2f( x107+ (radius107* cos(i *  twicePi107 / triangleAmount107)),
                    y107 + (radius107 * sin(i * twicePi107 / triangleAmount107)));
    }
    glEnd();
      GLdouble x108 =-350;
    GLdouble y108=50;
    GLdouble radius108=50;
    int triangleAmount108 = 100;
    GLfloat twicePi108= 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,139);
    glVertex2f(x108, y108); // center of circle
    for(int i = 0; i <= triangleAmount108; i++)
    {

        glVertex2f( x108+ (radius108 * cos(i *  twicePi108/ triangleAmount108)),
                    y108 + (radius108 * sin(i * twicePi108 / triangleAmount108)));
    }
   glEnd();
     GLdouble x109=-450;
    GLdouble y109=50;
    GLdouble radius109=50;
    int triangleAmount109 = 100;
    GLfloat twicePi109 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,100,0);
    glVertex2f(x109, y109); // center of circle
    for(int i = 0; i <= triangleAmount109; i++)
    {

        glVertex2f( x109+ (radius109 * cos(i *  twicePi109 / triangleAmount109)),
                    y109 + (radius109 * sin(i * twicePi109 / triangleAmount109)));
    }
    glEnd();
    GLdouble x110=-550;
    GLdouble y110=50;
    GLdouble radius110=50;
    int triangleAmount110 = 100;
    GLfloat twicePi110 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,250,154);
    glVertex2f(x110, y110); // center of circle
    for(int i = 0; i <= triangleAmount110; i++)
    {

        glVertex2f( x110+ (radius110 * cos(i *  twicePi110/ triangleAmount110)),
                    y110 + (radius110 * sin(i * twicePi110 / triangleAmount110)));
    }
    glEnd();
    GLdouble x111=-650;
    GLdouble y111=50;
    GLdouble radius111=50;
    int triangleAmount111 = 100;
    GLfloat twicePi111 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139,69,19);
    glVertex2f(x111, y111); // center of circle
    for(int i = 0; i <= triangleAmount111; i++)
    {

        glVertex2f( x111+ (radius111 * cos(i *  twicePi111 / triangleAmount111)),
                    y111 + (radius111 * sin(i * twicePi111 / triangleAmount111)));
    }
    glEnd();
    GLdouble x112=-750;
    GLdouble y112=50;
    GLdouble radius112=50;
    int triangleAmount112 = 100;
    GLfloat twicePi112 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,0,0);
    glVertex2f(x112, y112); // center of circle
    for(int i = 0; i <= triangleAmount112; i++)
    {

        glVertex2f( x112+ (radius112 * cos(i *  twicePi112 / triangleAmount112)),
                    y112 + (radius112 * sin(i * twicePi112 / triangleAmount112)));
    }
    glEnd();
    GLdouble x113=-850;
    GLdouble y113=50;
    GLdouble radius113=50;
    int triangleAmount113 = 100;
    GLfloat twicePi113 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,0);
    glVertex2f(x113, y113); // center of circle
    for(int i = 0; i <= triangleAmount113; i++)
    {

        glVertex2f( x113+ (radius113 * cos(i *  twicePi113 / triangleAmount113)),
                    y113 + (radius113 * sin(i * twicePi113 / triangleAmount113)));
    }
    glEnd();
    GLdouble x114=-950;
    GLdouble y114=50;
    GLdouble radius114=50;
    int triangleAmount114 = 100;
    GLfloat twicePi114 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,69,0);
    glVertex2f(x114, y114); // center of circle
    for(int i = 0; i <= triangleAmount114; i++)
    {

        glVertex2f( x114+ (radius114 * cos(i *  twicePi114 / triangleAmount114)),
                    y114 + (radius114* sin(i * twicePi114 / triangleAmount114)));
    }
    glEnd();
    GLdouble x115=-50;
    GLdouble y115=50;
    GLdouble radius115=20;
    int triangleAmount115 = 100;
    GLfloat twicePi115 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250,235,215);
    glVertex2f(x115, y115); // center of circle
    for(int i = 0; i <= triangleAmount115; i++)
    {

        glVertex2f( x115+ (radius115 * cos(i *  twicePi115/ triangleAmount115)),
                    y115 + (radius115 * sin(i * twicePi115 / triangleAmount115)));
    }
    glEnd();
   GLdouble x116=-150;
    GLdouble y116=50;
    GLdouble radius116=20;
    int triangleAmount116 = 100;
    GLfloat twicePi116 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,140,0);
    glVertex2f(x116, y116); // center of circle
    for(int i = 0; i <= triangleAmount116; i++)
    {

        glVertex2f( x116+ (radius116 * cos(i *  twicePi116 / triangleAmount116)),
                    y116 + (radius116 * sin(i * twicePi116 / triangleAmount116)));
    }
    glEnd();
   GLdouble x117=-250;
    GLdouble y117=50;
    GLdouble radius117=20;
    int triangleAmount117 = 100;
    GLfloat twicePi117 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,215,0);
    glVertex2f(x117, y117); // center of circle
    for(int i = 0; i <= triangleAmount117; i++)
    {

        glVertex2f( x117+ (radius117 * cos(i *  twicePi117 / triangleAmount117)),
                    y117 + (radius117 * sin(i * twicePi117 / triangleAmount117)));
    }
    glEnd();
     GLdouble x118=-350;
    GLdouble y118=50;
    GLdouble radius118=20;
    int triangleAmount118 = 100;
    GLfloat twicePi118 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,255,255);
    glVertex2f(x118, y118); // center of circle
    for(int i = 0; i <= triangleAmount118; i++)
    {

        glVertex2f( x118+ (radius118 * cos(i *  twicePi118 / triangleAmount118)),
                    y118 + (radius118 * sin(i * twicePi118 / triangleAmount118)));
    }
    glEnd();
 GLdouble x119=-450;
    GLdouble y119=50;
    GLdouble radius119=20;
    int triangleAmount119 = 100;
    GLfloat twicePi119 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,255,0);
    glVertex2f(x119, y119); // center of circle
    for(int i = 0; i <= triangleAmount119; i++)
    {

        glVertex2f( x119+ (radius119 * cos(i *  twicePi119 / triangleAmount119)),
                    y119 + (radius119 * sin(i * twicePi119 / triangleAmount119)));
    }
    glEnd();
       GLdouble x120=-550;
    GLdouble y120=50;
    GLdouble radius120=20;
    int triangleAmount120 = 100;
    GLfloat twicePi120 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,100,0);
    glVertex2f(x120, y120); // center of circle
    for(int i = 0; i <= triangleAmount120; i++)
    {

        glVertex2f( x120+ (radius120 * cos(i *  twicePi120 / triangleAmount120)),
                    y120+ (radius120 * sin(i * twicePi120 / triangleAmount120)));
    }
    glEnd();
    GLdouble x121=-650;
    GLdouble y121=50;
    GLdouble radius121=20;
    int triangleAmount121 = 100;
    GLfloat twicePi121 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,128);
    glVertex2f(x121, y121); // center of circle
    for(int i = 0; i <= triangleAmount121; i++)
    {

        glVertex2f( x121+ (radius121* cos(i *  twicePi121/ triangleAmount121)),
                    y121 + (radius121 * sin(i * twicePi121 / triangleAmount121)));
    }
    glEnd();
    GLdouble x122=-750;
    GLdouble y122=50;
    GLdouble radius122=20;
    int triangleAmount122 = 100;
    GLfloat twicePi122 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,0);
    glVertex2f(x122, y122); // center of circle
    for(int i = 0; i <= triangleAmount122; i++)
    {

        glVertex2f( x122+ (radius122 * cos(i *  twicePi122 / triangleAmount122)),
                    y122+ (radius122 * sin(i * twicePi122 / triangleAmount122)));
    }
    glEnd();
    GLdouble x123=-850;
    GLdouble y123=50;
    GLdouble radius123=20;
    int triangleAmount123 = 100;
    GLfloat twicePi123 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(25,25,112);
    glVertex2f(x123, y123); // center of circle
    for(int i = 0; i <= triangleAmount123; i++)
    {

        glVertex2f( x123+ (radius123* cos(i *  twicePi123/ triangleAmount123)),
                    y123+ (radius123* sin(i * twicePi123 / triangleAmount123)));
    }
    glEnd();
   GLdouble x124=-950;
    GLdouble y124=50;
    GLdouble radius124=20;
    int triangleAmount124 = 100;
    GLfloat twicePi124 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153,50,204);
    glVertex2f(x124, y124); // center of circle
    for(int i = 0; i <= triangleAmount124; i++)
    {

        glVertex2f( x124+ (radius124 * cos(i *  twicePi124 / triangleAmount124)),
                    y124 + (radius124 * sin(i * twicePi124 / triangleAmount124)));
    }
    glEnd();

    

    /////////////lake
      glBegin(GL_QUADS);
	glColor3ub(139,0,0);
	glVertex2d(-500,0);
	glColor3ub(139,0,0);
	glVertex2d(-500,-1000);
	glColor3ub(139,0,0);
	glVertex2d(500,-1000);
	glColor3ub(139,0,0);
	glVertex2d(500,0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(25,25,112);
	glVertex2d(-460,-80);
	glColor3ub(25,25,112);
	glVertex2d(-460,-560);
	glColor3ub(25,25,112);
	glVertex2d(460,-560);
	glColor3ub(230,230,250);
	glVertex2d(460,-80);

	glEnd();

	/////////////waves

	glPushMatrix();
    glTranslated(watermoves1,0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3ub(135,206,235);
	glVertex2d(-450,-90);
	glVertex2d(-450,-100);
	glVertex2d(-460,-100);
	glVertex2d(-460,-90);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-300,-100);
	glVertex2d(-300,-110);
	glVertex2d(-380,-110);
	glVertex2d(-380,-100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-400,-200);
	glVertex2d(-400,-210);
	glVertex2d(-300,-210);
	glVertex2d(-300,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-400,-330);
	glVertex2d(-400,-320);
	glVertex2d(-300,-320);
	glVertex2d(-300,-330);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-460,-430);
	glVertex2d(-460,-420);
	glVertex2d(-360,-420);
	glVertex2d(-360,-430);
	glEnd();



	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-260,-430);
	glVertex2d(-260,-420);
	glVertex2d(-160,-420);
	glVertex2d(-160,-430);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-160,-230);
	glVertex2d(-160,-220);
	glVertex2d(-90,-220);
	glVertex2d(-90,-230);
	glEnd();
	//


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(300,-100);
	glVertex2d(300,-110);
	glVertex2d(380,-110);
	glVertex2d(380,-100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(400,-200);
	glVertex2d(400,-210);
	glVertex2d(300,-210);
	glVertex2d(300,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(400,-330);
	glVertex2d(400,-320);
	glVertex2d(300,-320);
	glVertex2d(300,-330);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(460,-430);
	glVertex2d(460,-420);
	glVertex2d(360,-420);
	glVertex2d(360,-430);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(260,-430);
	glVertex2d(260,-420);
	glVertex2d(160,-420);
	glVertex2d(160,-430);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(160,-230);
	glVertex2d(160,-220);
	glVertex2d(90,-220);
	glVertex2d(90,-230);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-200,-120);
	glVertex2d(-200,-130);
	glVertex2d(150,-130);
	glVertex2d(150,-120);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-200,-500);
	glVertex2d(-200,-510);
	glVertex2d(150,-510);
	glVertex2d(150,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-100,-400);
	glVertex2d(-100,-410);
	glVertex2d(120,-410);
	glVertex2d(120,-400);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-300,-520);
	glVertex2d(-300,-510);
	glVertex2d(-350,-510);
	glVertex2d(-350,-520);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(135,206,235);
	glVertex2d(-280,-290);
	glVertex2d(-280,-280);
	glVertex2d(-230,-280);
	glVertex2d(-230,-290);
	glEnd();
	glPopMatrix();
	////////shapla
    glPushMatrix();
    glTranslated(watermoves,0.0, 0.0);
    /////1
     GLdouble a=-400;
    GLdouble b=-240;
     GLdouble radi =40;
    int ta = 100;
    GLfloat twicePiee = 2 * PI;
    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(107,142,35);
        glVertex2f(a, b); // center of circle
        for(int i = 0; i <= ta;i++)
         {
                glVertex2f( a + (radi * cos(i *  twicePiee / ta)),
                           b + (radi * sin(i * twicePiee / ta)));

        }
    glEnd();
     glBegin(GL_POLYGON);

	glColor3ub(107,142,35);
	glVertex2d(-400,-200);
    glVertex2d(-440,-160);
    glVertex2d(-440,-230);
    glVertex2d(-360,-230);
    glVertex2d(-360,-160);
    glVertex2d(-400,-200);

	glEnd();

	/////2
     GLdouble a1=0;
    GLdouble b1=-300;
     GLdouble radi1 =40;
    int ta1 = 100;
    GLfloat twicePiee1 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(107,142,35);
        glVertex2f(a1, b1); // center of circle
        for(int i = 0; i <= ta1;i++)
         {
                glVertex2f( a1 + (radi1 * cos(i *  twicePiee1 / ta1)),
                           b1 + (radi1 * sin(i * twicePiee1 / ta1)));

        }
    glEnd();
     glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(0,-260);
    glVertex2d(40,-220);
    glVertex2d(40,-290);
    glVertex2d(-40,-290);
    glVertex2d(-40,-220);
    glVertex2d(0,-260);

	glEnd();


	/////3
     GLdouble a3=400;
    GLdouble b3=-500;
     GLdouble radi3 =40;
    int ta3 = 100;
    GLfloat twicePiee3 = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(107,142,35);
        glVertex2f(a3, b3); // center of circle
        for(int i = 0; i <= ta3;i++)
         {
                glVertex2f( a3 + (radi3 * cos(i *  twicePiee3 / ta3)),
                           b3 + (radi3 * sin(i * twicePiee3 / ta3)));

        }
    glEnd();
     glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(400,-460);
    glVertex2d(440,-420);
    glVertex2d(440,-490);
    glVertex2d(360,-490);
    glVertex2d(360,-420);
    glVertex2d(400,-460);

	glEnd();


	/////4
     GLdouble a4=200;
    GLdouble b4=-240;
     GLdouble radi4 =40;
    int ta4 = 100;
    GLfloat twicePiee4 = 2 * PI;
    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(107,142,35);
        glVertex2f(a4, b4); // center of circle
        for(int i = 0; i <= ta4;i++)
         {
                glVertex2f( a4 + (radi4 * cos(i *  twicePiee4 / ta4)),
                           b4 + (radi4 * sin(i * twicePiee4 / ta4)));

        }
    glEnd();
     glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(200,-200);
    glVertex2d(240,-160);
    glVertex2d(240,-230);
    glVertex2d(160,-230);
    glVertex2d(160,-160);
    glVertex2d(200,-200);

	glEnd();


	/////5
     GLdouble a5=-200;
    GLdouble b5=-500;
     GLdouble radi5 =40;
    int ta5 = 100;
    GLfloat twicePiee5 = 2 * PI;
    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(107,142,35);
        glVertex2f(a5, b5); // center of circle
        for(int i = 0; i <= ta5;i++)
         {
                glVertex2f( a5 + (radi5 * cos(i *  twicePiee5 / ta5)),
                           b5 + (radi5 * sin(i * twicePiee5 / ta5)));

        }
    glEnd();

   glBegin(GL_POLYGON);
	glColor3ub(107,142,35);
	glVertex2d(-200,-460);
    glVertex2d(-240,-420);
    glVertex2d(-240,-490);
    glVertex2d(-160,-490);
    glVertex2d(-160,-420);
    glVertex2d(-200,-460);

	glEnd();
	glPopMatrix();

///////////bricks////////////////

    glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(-500,-640);
	glVertex2d(-500,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-640);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(-320,-640);
	glVertex2d(-320,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(-320,-640);
	glVertex2d(-320,-740);
	glVertex2d(-220,-740);
	glVertex2d(-220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(-220,-640);
	glVertex2d(-220,-740);
	glVertex2d(-120,-740);
	glVertex2d(-120,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(-120,-640);
	glVertex2d(-120,-740);
	glVertex2d(-20,-740);
	glVertex2d(-20,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(-20,-640);
	glVertex2d(-20,-740);
	glVertex2d(120,-740);
	glVertex2d(120,-640);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(120,-640);
	glVertex2d(120,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(320,-640);
	glVertex2d(320,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(420,-640);
	glVertex2d(420,-740);
	glVertex2d(320,-740);
	glVertex2d(320,-640);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(500,-640);
	glVertex2d(500,-740);
	glVertex2d(420,-740);
	glVertex2d(420,-640);
	glEnd();

	///////


	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//1
	glVertex2d(-500,-840);
	glVertex2d(-500,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-840);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//2
	glVertex2d(-320,-840);
	glVertex2d(-320,-740);
	glVertex2d(-420,-740);
	glVertex2d(-420,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//1
	glVertex2d(-320,-840);
	glVertex2d(-320,-740);
	glVertex2d(-220,-740);
	glVertex2d(-220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//2
	glVertex2d(-220,-840);
	glVertex2d(-220,-740);
	glVertex2d(-120,-740);
	glVertex2d(-120,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//1
	glVertex2d(-120,-840);
	glVertex2d(-120,-740);
	glVertex2d(-20,-740);
	glVertex2d(-20,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//2
	glVertex2d(-20,-840);
	glVertex2d(-20,-740);
	glVertex2d(120,-740);
	glVertex2d(120,-840);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//1
	glVertex2d(120,-840);
	glVertex2d(120,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//2
	glVertex2d(320,-840);
	glVertex2d(320,-740);
	glVertex2d(220,-740);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//1
	glVertex2d(420,-840);
	glVertex2d(420,-740);
	glVertex2d(320,-740);
	glVertex2d(320,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//2
	glVertex2d(500,-840);
	glVertex2d(500,-740);
	glVertex2d(420,-740);
	glVertex2d(420,-840);
	glEnd();
///////
     glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(-500,-840);
	glVertex2d(-500,-1000);
	glVertex2d(-420,-1000);
	glVertex2d(-420,-840);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(-320,-840);
	glVertex2d(-320,-1000);
	glVertex2d(-420,-1000);
	glVertex2d(-420,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(-320,-840);
	glVertex2d(-320,-1000);
	glVertex2d(-220,-1000);
	glVertex2d(-220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(-220,-840);
	glVertex2d(-220,-1000);
	glVertex2d(-120,-1000);
	glVertex2d(-120,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(-120,-840);
	glVertex2d(-120,-1000);
	glVertex2d(-20,-1000);
	glVertex2d(-20,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(-20,-840);
	glVertex2d(-20,-1000);
	glVertex2d(120,-1000);
	glVertex2d(120,-840);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(120,-840);
	glVertex2d(120,-1000);
	glVertex2d(220,-1000);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(320,-840);
	glVertex2d(320,-1000);
	glVertex2d(220,-1000);
	glVertex2d(220,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(165,42,42);//1
	glVertex2d(420,-840);
	glVertex2d(420,-1000);
	glVertex2d(320,-1000);
	glVertex2d(320,-840);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,69,19);//2
	glVertex2d(500,-840);
	glVertex2d(500,-1000);
	glVertex2d(420,-1000);
	glVertex2d(420,-840);
	glEnd();





    //bricks start//
    //right//
        /////1
     glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(500,0);
	glVertex2d(500,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(700,0);
	glVertex2d(700,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-0);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(700,0);
	glVertex2d(700,-100);
	glVertex2d(800,-100);
	glVertex2d(800,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(800,0);
	glVertex2d(800,-100);
	glVertex2d(900,-100);
	glVertex2d(900,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(900,0);
	glVertex2d(900,-100);
	glVertex2d(1000,-100);
	glVertex2d(1000,-0);
	glEnd();


	///////2
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(500,-200);
	glVertex2d(500,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(700,-200);
	glVertex2d(700,-100);
	glVertex2d(600,-100);
	glVertex2d(600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(700,-200);
	glVertex2d(700,-100);
	glVertex2d(800,-100);
	glVertex2d(800,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(800,-200);
	glVertex2d(800,-100);
	glVertex2d(900,-100);
	glVertex2d(900,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(900,-200);
	glVertex2d(900,-100);
	glVertex2d(1000,-100);
	glVertex2d(1000,-200);
	glEnd();


	////////////////////3

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(500,-300);
	glVertex2d(500,-200);
	glVertex2d(600,-200);
	glVertex2d(600,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(700,-300);
	glVertex2d(700,-200);
	glVertex2d(600,-200);
	glVertex2d(600,-300);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(700,-300);
	glVertex2d(700,-200);
	glVertex2d(800,-200);
	glVertex2d(800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(800,-300);
	glVertex2d(800,-200);
	glVertex2d(900,-200);
	glVertex2d(900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(900,-300);
	glVertex2d(900,-200);
	glVertex2d(1000,-200);
	glVertex2d(1000,-300);
	glEnd();


	////////////////4
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(500,-300);
	glVertex2d(500,-400);
	glVertex2d(600,-400);
	glVertex2d(600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(700,-300);
	glVertex2d(700,-400);
	glVertex2d(600,-400);
	glVertex2d(600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(700,-300);
	glVertex2d(700,-400);
	glVertex2d(800,-400);
	glVertex2d(800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(800,-300);
	glVertex2d(800,-400);
	glVertex2d(900,-400);
	glVertex2d(900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(900,-300);
	glVertex2d(900,-400);
	glVertex2d(1000,-400);
	glVertex2d(1000,-300);
	glEnd();

	////////////////////5
	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(500,-400);
	glVertex2d(500,-500);
	glVertex2d(600,-500);
	glVertex2d(600,-400);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(700,-400);
	glVertex2d(700,-500);
	glVertex2d(600,-500);
	glVertex2d(600,-400);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(700,-500);
	glVertex2d(700,-400);
	glVertex2d(800,-400);
	glVertex2d(800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(800,-500);
	glVertex2d(800,-400);
	glVertex2d(900,-400);
	glVertex2d(900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(900,-400);
	glVertex2d(900,-500);
	glVertex2d(1000,-500);
	glVertex2d(1000,-400);
	glEnd();


	////////////////6
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(500,-500);
	glVertex2d(500,-600);
	glVertex2d(600,-600);
	glVertex2d(600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(700,-500);
	glVertex2d(700,-600);
	glVertex2d(600,-600);
	glVertex2d(600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(700,-500);
	glVertex2d(700,-600);
	glVertex2d(800,-600);
	glVertex2d(800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(800,-500);
	glVertex2d(800,-600);
	glVertex2d(900,-600);
	glVertex2d(900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(900,-500);
	glVertex2d(900,-600);
	glVertex2d(1000,-600);
	glVertex2d(1000,-500);
	glEnd();
////////////////////7
glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(500,-600);
	glVertex2d(500,-700);
	glVertex2d(600,-700);
	glVertex2d(600,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(700,-600);
	glVertex2d(700,-700);
	glVertex2d(600,-700);
	glVertex2d(600,-600);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(700,-600);
	glVertex2d(700,-700);
	glVertex2d(800,-700);
	glVertex2d(800,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(800,-600);
	glVertex2d(800,-700);
	glVertex2d(900,-700);
	glVertex2d(900,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(900,-600);
	glVertex2d(900,-700);
	glVertex2d(1000,-700);
	glVertex2d(1000,-600);
	glEnd();


	////////////////8
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(500,-700);
	glVertex2d(500,-800);
	glVertex2d(600,-800);
	glVertex2d(600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(700,-700);
	glVertex2d(700,-800);
	glVertex2d(600,-800);
	glVertex2d(600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(700,-700);
	glVertex2d(700,-800);
	glVertex2d(800,-800);
	glVertex2d(800,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(800,-700);
	glVertex2d(800,-800);
	glVertex2d(900,-800);
	glVertex2d(900,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(900,-700);
	glVertex2d(900,-800);
	glVertex2d(1000,-800);
	glVertex2d(1000,-700);
	glEnd();

	///////////9
	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(500,-800);
	glVertex2d(500,-900);
	glVertex2d(600,-900);
	glVertex2d(600,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(700,-800);
	glVertex2d(700,-900);
	glVertex2d(600,-900);
	glVertex2d(600,-800);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(700,-800);
	glVertex2d(700,-900);
	glVertex2d(800,-900);
	glVertex2d(800,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(800,-800);
	glVertex2d(800,-900);
	glVertex2d(900,-900);
	glVertex2d(900,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(900,-800);
	glVertex2d(900,-900);
	glVertex2d(1000,-900);
	glVertex2d(1000,-800);
	glEnd();


	////////////////10
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(500,-900);
	glVertex2d(500,-1000);
	glVertex2d(600,-1000);
	glVertex2d(600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(700,-900);
	glVertex2d(700,-1000);
	glVertex2d(600,-1000);
	glVertex2d(600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(700,-900);
	glVertex2d(700,-1000);
	glVertex2d(800,-1000);
	glVertex2d(800,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(800,-900);
	glVertex2d(800,-1000);
	glVertex2d(900,-1000);
	glVertex2d(900,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(900,-900);
	glVertex2d(900,-1000);
	glVertex2d(1000,-1000);
	glVertex2d(1000,-900);
	glEnd();

    //left//
    /////////////////left side bricks
    /////1
     glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-500,0);
	glVertex2d(-500,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-700,0);
	glVertex2d(-700,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-0);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-700,0);
	glVertex2d(-700,-100);
	glVertex2d(-800,-100);
	glVertex2d(-800,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-800,0);
	glVertex2d(-800,-100);
	glVertex2d(-900,-100);
	glVertex2d(-900,-0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-900,0);
	glVertex2d(-900,-100);
	glVertex2d(-1000,-100);
	glVertex2d(-1000,-0);
	glEnd();


	///////2
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-500,-200);
	glVertex2d(-500,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-700,-200);
	glVertex2d(-700,-100);
	glVertex2d(-600,-100);
	glVertex2d(-600,-200);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-700,-200);
	glVertex2d(-700,-100);
	glVertex2d(-800,-100);
	glVertex2d(-800,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-800,-200);
	glVertex2d(-800,-100);
	glVertex2d(-900,-100);
	glVertex2d(-900,-200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-900,-200);
	glVertex2d(-900,-100);
	glVertex2d(-1000,-100);
	glVertex2d(-1000,-200);
	glEnd();


	////////////////////3

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-500,-300);
	glVertex2d(-500,-200);
	glVertex2d(-600,-200);
	glVertex2d(-600,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-700,-300);
	glVertex2d(-700,-200);
	glVertex2d(-600,-200);
	glVertex2d(-600,-300);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-700,-300);
	glVertex2d(-700,-200);
	glVertex2d(-800,-200);
	glVertex2d(-800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-800,-300);
	glVertex2d(-800,-200);
	glVertex2d(-900,-200);
	glVertex2d(-900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-900,-300);
	glVertex2d(-900,-200);
	glVertex2d(-1000,-200);
	glVertex2d(-1000,-300);
	glEnd();


	////////////////4
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-500,-300);
	glVertex2d(-500,-400);
	glVertex2d(-600,-400);
	glVertex2d(-600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-700,-300);
	glVertex2d(-700,-400);
	glVertex2d(-600,-400);
	glVertex2d(-600,-300);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-700,-300);
	glVertex2d(-700,-400);
	glVertex2d(-800,-400);
	glVertex2d(-800,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-800,-300);
	glVertex2d(-800,-400);
	glVertex2d(-900,-400);
	glVertex2d(-900,-300);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-900,-300);
	glVertex2d(-900,-400);
	glVertex2d(-1000,-400);
	glVertex2d(-1000,-300);
	glEnd();

	////////////////////5
	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-500,-400);
	glVertex2d(-500,-500);
	glVertex2d(-600,-500);
	glVertex2d(-600,-400);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-700,-400);
	glVertex2d(-700,-500);
	glVertex2d(-600,-500);
	glVertex2d(-600,-400);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-700,-500);
	glVertex2d(-700,-400);
	glVertex2d(-800,-400);
	glVertex2d(-800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-800,-500);
	glVertex2d(-800,-400);
	glVertex2d(-900,-400);
	glVertex2d(-900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-900,-400);
	glVertex2d(-900,-500);
	glVertex2d(-1000,-500);
	glVertex2d(-1000,-400);
	glEnd();


	////////////////6
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-500,-500);
	glVertex2d(-500,-600);
	glVertex2d(-600,-600);
	glVertex2d(-600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-700,-500);
	glVertex2d(-700,-600);
	glVertex2d(-600,-600);
	glVertex2d(-600,-500);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-700,-500);
	glVertex2d(-700,-600);
	glVertex2d(-800,-600);
	glVertex2d(-800,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-800,-500);
	glVertex2d(-800,-600);
	glVertex2d(-900,-600);
	glVertex2d(-900,-500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-900,-500);
	glVertex2d(-900,-600);
	glVertex2d(-1000,-600);
	glVertex2d(-1000,-500);
	glEnd();
////////////////////7
glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-500,-600);
	glVertex2d(-500,-700);
	glVertex2d(-600,-700);
	glVertex2d(-600,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-700,-600);
	glVertex2d(-700,-700);
	glVertex2d(-600,-700);
	glVertex2d(-600,-600);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-700,-600);
	glVertex2d(-700,-700);
	glVertex2d(-800,-700);
	glVertex2d(-800,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-800,-600);
	glVertex2d(-800,-700);
	glVertex2d(-900,-700);
	glVertex2d(-900,-600);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-900,-600);
	glVertex2d(-900,-700);
	glVertex2d(-1000,-700);
	glVertex2d(-1000,-600);
	glEnd();


	////////////////8
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-500,-700);
	glVertex2d(-500,-800);
	glVertex2d(-600,-800);
	glVertex2d(-600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-700,-700);
	glVertex2d(-700,-800);
	glVertex2d(-600,-800);
	glVertex2d(-600,-700);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-700,-700);
	glVertex2d(-700,-800);
	glVertex2d(-800,-800);
	glVertex2d(-800,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-800,-700);
	glVertex2d(-800,-800);
	glVertex2d(-900,-800);
	glVertex2d(-900,-700);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-900,-700);
	glVertex2d(-900,-800);
	glVertex2d(-1000,-800);
	glVertex2d(-1000,-700);
	glEnd();

	///////////9
	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-500,-800);
	glVertex2d(-500,-900);
	glVertex2d(-600,-900);
	glVertex2d(-600,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-700,-800);
	glVertex2d(-700,-900);
	glVertex2d(-600,-900);
	glVertex2d(-600,-800);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-700,-800);
	glVertex2d(-700,-900);
	glVertex2d(-800,-900);
	glVertex2d(-800,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//2
	glVertex2d(-800,-800);
	glVertex2d(-800,-900);
	glVertex2d(-900,-900);
	glVertex2d(-900,-800);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//1
	glVertex2d(-900,-800);
	glVertex2d(-900,-900);
	glVertex2d(-1000,-900);
	glVertex2d(-1000,-800);
	glEnd();


	////////////////10
	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-500,-900);
	glVertex2d(-500,-1000);
	glVertex2d(-600,-1000);
	glVertex2d(-600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-700,-900);
	glVertex2d(-700,-1000);
	glVertex2d(-600,-1000);
	glVertex2d(-600,-900);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-700,-900);
	glVertex2d(-700,-1000);
	glVertex2d(-800,-1000);
	glVertex2d(-800,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(139,0,0);//2
	glVertex2d(-800,-900);
	glVertex2d(-800,-1000);
	glVertex2d(-900,-1000);
	glVertex2d(-900,-900);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub	(178,34,34);//1
	glVertex2d(-900,-900);
	glVertex2d(-900,-1000);
	glVertex2d(-1000,-1000);
	glVertex2d(-1000,-900);
	glEnd();





//////////////


// *** Grass Mush ***//
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(700,-300);
    glVertex2d(710,-250);
    glVertex2d(690,-300);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(0,128,0);
    glVertex2d(695,-300);
    glVertex2d(680,-250);
    glVertex2d(665,-300);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(670,-300);
    glVertex2d(650,-250);
    glVertex2d(660,-300);
    glEnd();



// First row shell  #########
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-164);
    glVertex2d(539,-197);
    glVertex2d(547,-197);
    glVertex2d(547,-164);
    glVertex2d(544,-166);
    glVertex2d(541,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-164);
    glVertex2d(546,-164);
    glVertex2d(545,-158);
    glVertex2d(543,-156);
    glVertex2d(542,-156);
    glVertex2d(541,-157);
    glVertex2d(539,-162);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-164);
    glVertex2d(550,-197);
    glVertex2d(558,-197);
    glVertex2d(558,-164);
    glVertex2d(555,-166);
    glVertex2d(552,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-164);
    glVertex2d(558,-164);
    glVertex2d(556,-158);
    glVertex2d(554,-156);
    glVertex2d(553,-156);
    glVertex2d(552,-157);
    glVertex2d(550,-162);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-164);
    glVertex2d(560,-197);
    glVertex2d(568,-197);
    glVertex2d(568,-164);
    glVertex2d(565,-166);
    glVertex2d(562,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-164);
    glVertex2d(568,-164);
    glVertex2d(566,-158);
    glVertex2d(564,-156);
    glVertex2d(563,-156);
    glVertex2d(562,-157);
    glVertex2d(560,-162);
    glEnd();

//1st Arty Gun//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-136);
    glVertex2d(751,-149);
    glVertex2d(853,-139);
    glVertex2d(851,-108);
    glVertex2d(842,-97);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-173);
    glVertex2d(624,-186);
    glVertex2d(624,-197);
    glVertex2d(637,-197);
    glVertex2d(647,-183);
    glVertex2d(796,-159);
    glVertex2d(800,-141);
    glVertex2d(645,-168);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-93);
    glVertex2d(788,-101);
    glVertex2d(794,-117);
    glVertex2d(842,-98);
    glVertex2d(831,-81);
    glVertex2d(809,-89);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-81);
    glVertex2d(835,-90);
    glVertex2d(909,-63);
    glVertex2d(908,-55);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-89);
    glVertex2d(842,-99);
    glVertex2d(958,-57);
    glVertex2d(954,-47);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-98);
    glVertex2d(850,-108);
    glVertex2d(919,-85);
    glVertex2d(914,-74);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(796,-157);
    glVertex2d(820,-196);
    glVertex2d(845,-196);
    glVertex2d(874,-174);
    glVertex2d(873,-138);
    glVertex2d(844,-119);
    glVertex2d(829,-120);
    glVertex2d(800,-140);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-133);
    glVertex2d(824,-135);
    glVertex2d(820,-138);
    glVertex2d(815,-144);
    glVertex2d(813,-148);
    glVertex2d(812,-154);
    glVertex2d(812,-160);
    glVertex2d(815,-169);
    glVertex2d(817,-173);
    glVertex2d(823,-180);
    glVertex2d(832,-183);
    glVertex2d(845,-180);
    glVertex2d(851,-175);
    glVertex2d(859,-168);
    glVertex2d(862,-161);
    glVertex2d(859,-146);
    glVertex2d(857,-142);
    glVertex2d(850,-136);
    glVertex2d(845,-133);
    glVertex2d(839,-131);
    glVertex2d(836,-131);
    glEnd();

// 2nd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-464);
    glVertex2d(539,-497);
    glVertex2d(547,-497);
    glVertex2d(547,-464);
    glVertex2d(544,-466);
    glVertex2d(541,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-464);
    glVertex2d(546,-464);
    glVertex2d(545,-458);
    glVertex2d(543,-456);
    glVertex2d(542,-456);
    glVertex2d(541,-457);
    glVertex2d(539,-462);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-464);
    glVertex2d(550,-497);
    glVertex2d(558,-497);
    glVertex2d(558,-464);
    glVertex2d(555,-466);
    glVertex2d(552,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-464);
    glVertex2d(558,-464);
    glVertex2d(556,-458);
    glVertex2d(554,-456);
    glVertex2d(553,-456);
    glVertex2d(552,-457);
    glVertex2d(550,-462);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-464);
    glVertex2d(560,-497);
    glVertex2d(568,-497);
    glVertex2d(568,-464);
    glVertex2d(565,-466);
    glVertex2d(562,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-464);
    glVertex2d(568,-464);
    glVertex2d(566,-458);
    glVertex2d(564,-456);
    glVertex2d(563,-456);
    glVertex2d(562,-457);
    glVertex2d(560,-462);
    glEnd();

//******* 2nd Arty Gun ******//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-436);
    glVertex2d(751,-449);
    glVertex2d(853,-439);
    glVertex2d(851,-408);
    glVertex2d(842,-397);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-473);
    glVertex2d(624,-486);
    glVertex2d(624,-497);
    glVertex2d(637,-497);
    glVertex2d(647,-483);
    glVertex2d(796,-459);
    glVertex2d(800,-441);
    glVertex2d(645,-468);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-393);
    glVertex2d(788,-401);
    glVertex2d(794,-417);
    glVertex2d(842,-398);
    glVertex2d(831,-381);
    glVertex2d(809,-389);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-381);
    glVertex2d(835,-390);
    glVertex2d(909,-363);
    glVertex2d(908,-355);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-389);
    glVertex2d(842,-399);
    glVertex2d(958,-357);
    glVertex2d(954,-347);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-398);
    glVertex2d(850,-408);
    glVertex2d(919,-385);
    glVertex2d(914,-374);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(796,-457);
    glVertex2d(820,-496);
    glVertex2d(845,-496);
    glVertex2d(874,-474);
    glVertex2d(873,-438);
    glVertex2d(844,-419);
    glVertex2d(829,-420);
    glVertex2d(800,-440);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-433);
    glVertex2d(824,-435);
    glVertex2d(820,-438);
    glVertex2d(815,-444);
    glVertex2d(813,-448);
    glVertex2d(812,-454);
    glVertex2d(812,-460);
    glVertex2d(815,-469);
    glVertex2d(817,-473);
    glVertex2d(823,-480);
    glVertex2d(832,-483);
    glVertex2d(845,-480);
    glVertex2d(851,-475);
    glVertex2d(859,-468);
    glVertex2d(862,-461);
    glVertex2d(859,-446);
    glVertex2d(857,-442);
    glVertex2d(850,-436);
    glVertex2d(845,-433);
    glVertex2d(839,-431);
    glVertex2d(836,-431);
    glEnd();



// 3rd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(539,-764);
    glVertex2d(539,-797);
    glVertex2d(547,-797);
    glVertex2d(547,-764);
    glVertex2d(544,-766);
    glVertex2d(541,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(539,-764);
    glVertex2d(546,-764);
    glVertex2d(545,-758);
    glVertex2d(543,-756);
    glVertex2d(542,-756);
    glVertex2d(541,-757);
    glVertex2d(539,-762);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(550,-764);
    glVertex2d(550,-797);
    glVertex2d(558,-797);
    glVertex2d(558,-764);
    glVertex2d(555,-766);
    glVertex2d(552,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(550,-764);
    glVertex2d(558,-764);
    glVertex2d(556,-758);
    glVertex2d(554,-756);
    glVertex2d(553,-756);
    glVertex2d(552,-757);
    glVertex2d(550,-762);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(560,-764);
    glVertex2d(560,-797);
    glVertex2d(568,-797);
    glVertex2d(568,-764);
    glVertex2d(565,-766);
    glVertex2d(562,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(560,-764);
    glVertex2d(568,-764);
    glVertex2d(566,-758);
    glVertex2d(564,-756);
    glVertex2d(563,-756);
    glVertex2d(562,-757);
    glVertex2d(560,-762);
    glEnd();

//***** 3rd Arty Gun *******//


    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(746,-736);
    glVertex2d(751,-749);
    glVertex2d(853,-739);
    glVertex2d(851,-708);
    glVertex2d(842,-697);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(608,-773);
    glVertex2d(624,-786);
    glVertex2d(624,-797);
    glVertex2d(637,-797);
    glVertex2d(647,-783);
    glVertex2d(796,-759);
    glVertex2d(800,-741);
    glVertex2d(645,-768);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(811,-693);
    glVertex2d(788,-701);
    glVertex2d(794,-717);
    glVertex2d(842,-698);
    glVertex2d(831,-681);
    glVertex2d(809,-689);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(830,-681);
    glVertex2d(835,-690);
    glVertex2d(909,-663);
    glVertex2d(908,-655);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(836,-689);
    glVertex2d(842,-699);
    glVertex2d(958,-657);
    glVertex2d(954,-647);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(842,-698);
    glVertex2d(850,-708);
    glVertex2d(919,-685);
    glVertex2d(914,-674);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(796,-757);
    glVertex2d(820,-796);
    glVertex2d(845,-796);
    glVertex2d(874,-774);
    glVertex2d(873,-738);
    glVertex2d(844,-719);
    glVertex2d(829,-720);
    glVertex2d(800,-740);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(830,-733);
    glVertex2d(824,-735);
    glVertex2d(820,-738);
    glVertex2d(815,-744);
    glVertex2d(813,-748);
    glVertex2d(812,-754);
    glVertex2d(812,-760);
    glVertex2d(815,-769);
    glVertex2d(817,-773);
    glVertex2d(823,-780);
    glVertex2d(832,-783);
    glVertex2d(845,-780);
    glVertex2d(851,-775);
    glVertex2d(859,-768);
    glVertex2d(862,-761);
    glVertex2d(859,-746);
    glVertex2d(857,-742);
    glVertex2d(850,-736);
    glVertex2d(845,-733);
    glVertex2d(839,-731);
    glVertex2d(836,-731);
    glEnd();
/////////////////////////////////leftttttttttttttttt



 ///////Grass Mush ***//
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2d(-700,-300);
    glVertex2d(-710,-250);
    glVertex2d(-690,-300);
    glEnd();
    glBegin(GL_POLYGON);//2
    glColor3ub(0,128,0);
    glVertex2d(-695,-300);
    glVertex2d(-680,-250);
    glVertex2d(-665,-300);
    glEnd();
    glBegin(GL_POLYGON);//3
    glColor3ub(0,128,0);
    glVertex2d(-670,-300);
    glVertex2d(-650,-250);
    glVertex2d(-660,-300);
    glEnd();



// First row shell  #########
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-539,-164);
    glVertex2d(-539,-197);
    glVertex2d(-547,-197);
    glVertex2d(-547,-164);
    glVertex2d(-544,-166);
    glVertex2d(-541,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-539,-164);
    glVertex2d(-546,-164);
    glVertex2d(-545,-158);
    glVertex2d(-543,-156);
    glVertex2d(-542,-156);
    glVertex2d(-541,-157);
    glVertex2d(-539,-162);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-550,-164);
    glVertex2d(-550,-197);
    glVertex2d(-558,-197);
    glVertex2d(-558,-164);
    glVertex2d(-555,-166);
    glVertex2d(-552,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-550,-164);
    glVertex2d(-558,-164);
    glVertex2d(-556,-158);
    glVertex2d(-554,-156);
    glVertex2d(-553,-156);
    glVertex2d(-552,-157);
    glVertex2d(-550,-162);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-560,-164);
    glVertex2d(-560,-197);
    glVertex2d(-568,-197);
    glVertex2d(-568,-164);
    glVertex2d(-565,-166);
    glVertex2d(-562,-166);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-560,-164);
    glVertex2d(-568,-164);
    glVertex2d(-566,-158);
    glVertex2d(-564,-156);
    glVertex2d(-563,-156);
    glVertex2d(-562,-157);
    glVertex2d(-560,-162);
    glEnd();

//1st Arty Gun//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(-746,-136);
    glVertex2d(-751,-149);
    glVertex2d(-853,-139);
    glVertex2d(-851,-108);
    glVertex2d(-842,-97);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(-608,-173);
    glVertex2d(-624,-186);
    glVertex2d(-624,-197);
    glVertex2d(-637,-197);
    glVertex2d(-647,-183);
    glVertex2d(-796,-159);
    glVertex2d(-800,-141);
    glVertex2d(-645,-168);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(-811,-93);
    glVertex2d(-788,-101);
    glVertex2d(-794,-117);
    glVertex2d(-842,-98);
    glVertex2d(-831,-81);
    glVertex2d(-809,-89);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-830,-81);
    glVertex2d(-835,-90);
    glVertex2d(-909,-63);
    glVertex2d(-908,-55);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(-836,-89);
    glVertex2d(-842,-99);
    glVertex2d(-958,-57);
    glVertex2d(-954,-47);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-842,-98);
    glVertex2d(-850,-108);
    glVertex2d(-919,-85);
    glVertex2d(-914,-74);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(-796,-157);
    glVertex2d(-820,-196);
    glVertex2d(-845,-196);
    glVertex2d(-874,-174);
    glVertex2d(-873,-138);
    glVertex2d(-844,-119);
    glVertex2d(-829,-120);
    glVertex2d(-800,-140);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(-830,-133);
    glVertex2d(-824,-135);
    glVertex2d(-820,-138);
    glVertex2d(-815,-144);
    glVertex2d(-813,-148);
    glVertex2d(-812,-154);
    glVertex2d(-812,-160);
    glVertex2d(-815,-169);
    glVertex2d(-817,-173);
    glVertex2d(-823,-180);
    glVertex2d(-832,-183);
    glVertex2d(-845,-180);
    glVertex2d(-851,-175);
    glVertex2d(-859,-168);
    glVertex2d(-862,-161);
    glVertex2d(-859,-146);
    glVertex2d(-857,-142);
    glVertex2d(-850,-136);
    glVertex2d(-845,-133);
    glVertex2d(-839,-131);
    glVertex2d(-836,-131);
    glEnd();

// 2nd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-539,-464);
    glVertex2d(-539,-497);
    glVertex2d(-547,-497);
    glVertex2d(-547,-464);
    glVertex2d(-544,-466);
    glVertex2d(-541,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-539,-464);
    glVertex2d(-546,-464);
    glVertex2d(-545,-458);
    glVertex2d(-543,-456);
    glVertex2d(-542,-456);
    glVertex2d(-541,-457);
    glVertex2d(-539,-462);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-550,-464);
    glVertex2d(-550,-497);
    glVertex2d(-558,-497);
    glVertex2d(-558,-464);
    glVertex2d(-555,-466);
    glVertex2d(-552,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-550,-464);
    glVertex2d(-558,-464);
    glVertex2d(-556,-458);
    glVertex2d(-554,-456);
    glVertex2d(-553,-456);
    glVertex2d(-552,-457);
    glVertex2d(-550,-462);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-560,-464);
    glVertex2d(-560,-497);
    glVertex2d(-568,-497);
    glVertex2d(-568,-464);
    glVertex2d(-565,-466);
    glVertex2d(-562,-466);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-560,-464);
    glVertex2d(-568,-464);
    glVertex2d(-566,-458);
    glVertex2d(-564,-456);
    glVertex2d(-563,-456);
    glVertex2d(-562,-457);
    glVertex2d(-560,-462);
    glEnd();

//******* 2nd Arty Gun ******//

    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(-746,-436);
    glVertex2d(-751,-449);
    glVertex2d(-853,-439);
    glVertex2d(-851,-408);
    glVertex2d(-842,-397);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(-608,-473);
    glVertex2d(-624,-486);
    glVertex2d(-624,-497);
    glVertex2d(-637,-497);
    glVertex2d(-647,-483);
    glVertex2d(-796,-459);
    glVertex2d(-800,-441);
    glVertex2d(-645,-468);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(-811,-393);
    glVertex2d(-788,-401);
    glVertex2d(-794,-417);
    glVertex2d(-842,-398);
    glVertex2d(-831,-381);
    glVertex2d(-809,-389);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-830,-381);
    glVertex2d(-835,-390);
    glVertex2d(-909,-363);
    glVertex2d(-908,-355);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(-836,-389);
    glVertex2d(-842,-399);
    glVertex2d(-958,-357);
    glVertex2d(-954,-347);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-842,-398);
    glVertex2d(-850,-408);
    glVertex2d(-919,-385);
    glVertex2d(-914,-374);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(-796,-457);
    glVertex2d(-820,-496);
    glVertex2d(-845,-496);
    glVertex2d(-874,-474);
    glVertex2d(-873,-438);
    glVertex2d(-844,-419);
    glVertex2d(-829,-420);
    glVertex2d(-800,-440);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(-830,-433);
    glVertex2d(-824,-435);
    glVertex2d(-820,-438);
    glVertex2d(-815,-444);
    glVertex2d(-813,-448);
    glVertex2d(-812,-454);
    glVertex2d(-812,-460);
    glVertex2d(-815,-469);
    glVertex2d(-817,-473);
    glVertex2d(-823,-480);
    glVertex2d(-832,-483);
    glVertex2d(-845,-480);
    glVertex2d(-851,-475);
    glVertex2d(-859,-468);
    glVertex2d(-862,-461);
    glVertex2d(-859,-446);
    glVertex2d(-857,-442);
    glVertex2d(-850,-436);
    glVertex2d(-845,-433);
    glVertex2d(-839,-431);
    glVertex2d(-836,-431);
    glEnd();



// 3rd row ammo ///
    //Shell 1
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-539,-764);
    glVertex2d(-539,-797);
    glVertex2d(-547,-797);
    glVertex2d(-547,-764);
    glVertex2d(-544,-766);
    glVertex2d(-541,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-539,-764);
    glVertex2d(-546,-764);
    glVertex2d(-545,-758);
    glVertex2d(-543,-756);
    glVertex2d(-542,-756);
    glVertex2d(-541,-757);
    glVertex2d(-539,-762);
    glEnd();

    //Shell 2
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-550,-764);
    glVertex2d(-550,-797);
    glVertex2d(-558,-797);
    glVertex2d(-558,-764);
    glVertex2d(-555,-766);
    glVertex2d(-552,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-550,-764);
    glVertex2d(-558,-764);
    glVertex2d(-556,-758);
    glVertex2d(-554,-756);
    glVertex2d(-553,-756);
    glVertex2d(-552,-757);
    glVertex2d(-550,-762);
    glEnd();

    //Shell 3
    glBegin(GL_POLYGON); //Down golden part
    glColor3ub(204,204,0);
    glVertex2d(-560,-764);
    glVertex2d(-560,-797);
    glVertex2d(-568,-797);
    glVertex2d(-568,-764);
    glVertex2d(-565,-766);
    glVertex2d(-562,-766);
    glEnd();
    glBegin(GL_POLYGON); //Upper Black
    glColor3ub(64,64,64);
    glVertex2d(-560,-764);
    glVertex2d(-568,-764);
    glVertex2d(-566,-758);
    glVertex2d(-564,-756);
    glVertex2d(-563,-756);
    glVertex2d(-562,-757);
    glVertex2d(-560,-762);
    glEnd();

//***** 3rd Arty Gun *******//


    glBegin(GL_POLYGON); //MainHaul
    glColor3ub(25,60,0);
    glVertex2d(-746,-736);
    glVertex2d(-751,-749);
    glVertex2d(-853,-739);
    glVertex2d(-851,-708);
    glVertex2d(-842,-697);
    glEnd();
    glBegin(GL_POLYGON);//support tow
    glColor3ub (0,51,0);
    glVertex2d(-608,-773);
    glVertex2d(-624,-786);
    glVertex2d(-624,-797);
    glVertex2d(-637,-797);
    glVertex2d(-647,-783);
    glVertex2d(-796,-759);
    glVertex2d(-800,-741);
    glVertex2d(-645,-768);
    glEnd();
    glBegin(GL_POLYGON);//Upper haul
    glColor3ub(28,50,0);
    glVertex2d(-811,-693);
    glVertex2d(-788,-701);
    glVertex2d(-794,-717);
    glVertex2d(-842,-698);
    glVertex2d(-831,-681);
    glVertex2d(-809,-689);
    glEnd();
    //upper turret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-830,-681);
    glVertex2d(-835,-690);
    glVertex2d(-909,-663);
    glVertex2d(-908,-655);
    glEnd();
    //Main Turret
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2d(-836,-689);
    glVertex2d(-842,-699);
    glVertex2d(-958,-657);
    glVertex2d(-954,-647);
    glEnd();
    //BotTurret
    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2d(-842,-698);
    glVertex2d(-850,-708);
    glVertex2d(-919,-685);
    glVertex2d(-914,-674);
    glEnd();
    glBegin(GL_POLYGON);//FWheel
    glColor3ub(32,32,32);
    glVertex2d(-796,-757);
    glVertex2d(-820,-796);
    glVertex2d(-845,-796);
    glVertex2d(-874,-774);
    glVertex2d(-873,-738);
    glVertex2d(-844,-719);
    glVertex2d(-829,-720);
    glVertex2d(-800,-740);
    glEnd();
    glBegin(GL_POLYGON);//insideWheel
    glColor3ub(192,192,192);
    glVertex2d(-830,-733);
    glVertex2d(-824,-735);
    glVertex2d(-820,-738);
    glVertex2d(-815,-744);
    glVertex2d(-813,-748);
    glVertex2d(-812,-754);
    glVertex2d(-812,-760);
    glVertex2d(-815,-769);
    glVertex2d(-817,-773);
    glVertex2d(-823,-780);
    glVertex2d(-832,-783);
    glVertex2d(-845,-780);
    glVertex2d(-851,-775);
    glVertex2d(-859,-768);
    glVertex2d(-862,-761);
    glVertex2d(-859,-746);
    glVertex2d(-857,-742);
    glVertex2d(-850,-736);
    glVertex2d(-845,-733);
    glVertex2d(-839,-731);
    glVertex2d(-836,-731);
    glEnd();




      ///////monument//////////
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex2d(-300,100);
    glVertex2d(0,900);
    glVertex2d(300,100);
    glVertex2d(-300,100);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(220,220,220);
    glVertex2d(-210,100);
    glVertex2d(0,900);
    glVertex2d(210,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex2d(-125,100);
    glVertex2d(0,900);
    glVertex2d(125,100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(192,192,192);
    glVertex2d(-60,100);
    glVertex2d(0,900);
    glVertex2d(60,100);
    glEnd();
// Inside Shape
    glBegin(GL_POLYGON);
    glColor3ub(220,220,220);
    glVertex2d(0,900);
    glVertex2d(-25,450);
    glVertex2d(0,100);
    glVertex2d(25,450);
    glVertex2d(0,900);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2d(-25,445);
    glVertex2d(-25,455);
    glVertex2d(25,455);
    glVertex2d(25,445);
    glEnd();













    glFlush();
	glutSwapBuffers();






}




void Rain(int value){

if(rainday){

    rain += 100;


    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=-rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);

        glVertex2d(x,y);

        glVertex2d(x+10,y+10);
        glEnd();
    }
    for(int i=1;i<=1000;i++)
    {
        int x=-rand(),y=-rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);

        glVertex2d(x,y);

        glVertex2d(x+10,y+10);
        glEnd();
    }
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);

        glVertex2d(x,y);

        glVertex2d(x+10,y+10);
        glEnd();
    }
      for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=-rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);

        glVertex2d(x,y);

        glVertex2d(x+10,y+10);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(1, Rain, 0);

    glFlush();

}
}


void myKeyboard(unsigned char key,int x, int y){
	switch (key)
	{


    case 'r':
        rainday = true;
        Rain(rain);
       sndPlaySound("rain.wav",SND_ASYNC);
       //sndPlaySound(TEXT("rain.wav"),SND_MEMORY|SND_ASYNC);
        glutPostRedisplay();
        break;

    case 's':
        rainday = false;
		sndPlaySound(NULL,SND_ASYNC);
		glutPostRedisplay();
        break;


       case 'd':

        glutDisplayFunc(day);
        sndPlaySound("1.wav",SND_ASYNC);
        glutPostRedisplay();

        break;

        case 'e':
     glutDisplayFunc(evening);
     sndPlaySound("Bird.wav",SND_ASYNC);
     glutPostRedisplay();

        break;


       case 'n':

      glutDisplayFunc(nights);
      sndPlaySound("night.wav",SND_ASYNC);
      glutPostRedisplay();

        break;


    case 27:     // ESC key
        exit(0);
        glutPostRedisplay();
        break;

	default:
	break;
	}
}






int main(int argc,char **argv)
{



    cout << endl << "*********** VICTORY DAY ********************" << endl << endl;



    cout << "Press r : For Rain " << endl << endl;
    cout << "Press s : For Stop Rain" << endl << endl;

    cout << "Press n : For Night " << endl << endl;
    cout << "Press d : For Day" << endl << endl;
    cout << "Press e : For Evening" << endl << endl;

    cout << "**************THANK YOU********************" << endl << endl;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("VICTORY DAY");     // creating the window
	//glutFullScreen();       // making the window full screen
	//glutInitWindowPosition(0,0);
	glutDisplayFunc(day);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(1, update, 0);
    glutIdleFunc(Idle);
	init();
	glutMainLoop();
	return 0;
}

