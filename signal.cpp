#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.1416
#include <math.h>
#include <time.h>

GLint i;
float _angle = 0.0;
GLint flag=0;

float pixel(float point){
    return point/25.0;
}
float clr(float x)
{
    float color = x/255;
    return color;
}


bool tp_to_bttm=false;
bool lft_to_right=false;

bool orange_light_comes = false;


void SignalPost(float x,float y);



float carmove_lft_to_rit = 25;


















void circle(GLdouble rad)
{
    GLint points= 50;
    GLdouble delTheta = (2.0* PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for(i = 0; i<=50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}




void lineCirle(){
    glBegin(GL_LINES);
	for(int i=0;i<300;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.95;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
}


void sun(){

    glColor3f(clr(249),clr(215),clr(28));//(R,G,B)
    circle(2);


}
void car()
{


    // car body

    glColor3f(clr(0.0),clr(0.0),clr(205.0));
    glBegin(GL_POLYGON);
    glVertex2f(-2.0f,1.0f);
    glVertex2f(-0.14f,1.0f);
    glVertex2f(-0.14f,2.0f);
    glVertex2f(1.19f,2.0f);
    glVertex2f(1.50f,1.0f);
    glVertex2f(4.50f,1.0f);
    glVertex2f(5.50f,2.0f);
    glVertex2f(6.65f,2.0f);
    glVertex2f(6.83f,1.0f);
    glVertex2f(8.83f,1.0f);


    glVertex2f(8.80f,2.0f);
    glVertex2f(5.95f,3.0f);
    glVertex2f(4.00f,4.80f);
    glVertex2f(-0.40f,4.80f);
    glVertex2f(-1.40f,3.0f);
    glVertex2f(-2.0f,2.30f);

    glEnd();


    //car bampar

      glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.0f,2.0f);
     glVertex2f(8.70f,2.0f);
     glVertex2f(8.70f,1.70f);
     glVertex2f(-2.0f,1.50f);
    glEnd();

//    // car tiars //

    glColor3f(clr(190),clr(190),clr(190));
    glPushMatrix();
    glTranslatef(0.20f,0.80f,0.0f);
    circle(.52);
    glPopMatrix();


    glColor3f(clr(190),clr(190),clr(190));
    glPushMatrix();
    glTranslatef(6.70f,0.80f,0.0f);
    circle(.52);
    glPopMatrix();



    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(0.20f,0.80f,0.0f);
    glScalef(.29,.29,.29);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	lineCirle();
	glPopMatrix();


	glColor3f(0,0,0);
	glPushMatrix();
    glTranslatef(6.70f,0.80f,0.0f);
	glScalef(.29,.29,.29);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	lineCirle();
	glPopMatrix();

    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.20f,0.80f,0.0f);
    circle(.32);
    glPopMatrix();


    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(6.70f,0.80f,0.0f);
    circle(.32);
    glPopMatrix();




//////car windows
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
    glVertex2f(-0.30f,4.0f);
    glVertex2f(1.70f,4.0f);
    glVertex2f(1.70f,2.7f);
    glVertex2f(-0.80f,2.7f);

glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
    glVertex2f(2.30f,4.0f);
    glVertex2f(3.90f,4.0f);
    glVertex2f(4.95f,2.70f);
    glVertex2f(2.30f,2.75f);
    //glVertex2f(-3.80f,2.7f);

glEnd();



}





void road(){



    glColor3f(0.0,0.0,0.0);
  

    //left road();// right road

    glBegin(GL_POLYGON);
        glVertex2f(40.0f,5.25f);
        glVertex2f(-40.0f,5.25f);
        glVertex2f(-40.0f,-8.25f);
        glVertex2f(40.0f,-8.25f);
       // glVertex2f(3.0f,0.0f);

    glEnd();

	 glColor3f(1.0,1.0,1.0);
    
	glLineWidth(5.5f);
      
	  glEnable(GL_LINE_STIPPLE);
		  glLineStipple(1,0X00FF);
	  
	  glBegin(GL_LINES);
	  glVertex2f(-40.0f,-1.50f);
      glVertex2f(40.0f,-1.50f);
    glEnd();
	glDisable(GL_LINE_STIPPLE);


}

void zebra_crossing(){

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(5.0f,4.50f);
        glVertex2f(10.0f,4.50f);
        glVertex2f(10.0f,2.50f);
        glVertex2f(5.0f,2.50f);
    glEnd();

     glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(5.0f,2.0f);
        glVertex2f(10.0f,2.0f);
        glVertex2f(10.0f,0.0f);
        glVertex2f(5.0f,0.0f);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(5.0f,-0.50f);
        glVertex2f(10.0f,-0.50f);
        glVertex2f(10.0f,-2.50f);
        glVertex2f(5.0f,-2.50f);
    glEnd();


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(5.0f,-3.0f);
        glVertex2f(10.0f,-3.0f);
        glVertex2f(10.0f,-5.0f);
        glVertex2f(5.0f,-5.0f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(5.0f,-4.0f);
        glVertex2f(10.0f,-4.0f);
        glVertex2f(10.0f,-5.20f);
        glVertex2f(5.0f,-5.20f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(5.0f,-5.80f);
        glVertex2f(10.0f,-5.80f);
        glVertex2f(10.0f,-7.80f);
        glVertex2f(5.0f,-7.80f);
    glEnd();

}




void sky(){
    glColor3f(0.0,0.8,1.0);//(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2d(40,40);
    glVertex2d(-40,40);
    glVertex2f(-30,10);
    glVertex2f(30,15);


glEnd();
}



void field(){


  glColor3f(0.1333333f,0.5450980392f,0.133333333f);
 // glColor3f(0.0,0.2,0.0);
  glBegin(GL_POLYGON);
    glVertex3f(-683.0,-386,0.0);
    glVertex3f(683.0,-386.0,0.0);
    glVertex3f(683.0,200.0,0.0);
    glVertex3f(-683.0,200.0,0);
glEnd();

}
void init(){

    glClearColor(0.0, 0.0, 0.0, 1.0);
     glOrtho(-25,25,-25,25,-25,25);

}

bool redsignal = false;
bool green_signal = false;
bool orange_light = false;

bool start = true;

void alltransports_move(int value){

    if(start){
            if(orange_light_comes){
                green_signal = false;
                redsignal = false;
                orange_light = true;
            }
            else{
                green_signal = true;
                redsignal = false;
                orange_light = false;
            }


            if(lft_to_right){
                _angle -= 2.0f;
                carmove_lft_to_rit += .040f;
                if (carmove_lft_to_rit > pixel(900.0)) {
                    carmove_lft_to_rit = pixel(-800.0);
                } 
            }

        glutPostRedisplay();
        glutTimerFunc(15, alltransports_move, 0);
    }
    else{
            orange_light_comes = false;
            green_signal = false;
            redsignal = true;
            orange_light = false;
            carmove_lft_to_rit += 0.0f;
            glutPostRedisplay();
            glutTimerFunc(15, alltransports_move, 0);
    }
}



void signal1(float x,float y){
	
//    SetSignalStandColor();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x),pixel(y),0.0);
    glVertex3f(pixel(x+5.0),pixel(y),0.0);
    glVertex3f(pixel(x+5.0),pixel(y+25.0),0.0);
    glVertex3f(pixel(x),pixel(y+25.0),0.0);
    glEnd();

	// signalbox
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-20.0),pixel(y+20.0),0.0);
    glVertex3f(pixel(x+25.0),pixel(y+20.0),0.0);
    glVertex3f(pixel(x+25.0),pixel(y+80.0),0.0);
    glVertex3f(pixel(x-20.0),pixel(y+80.0),0.0);
    glEnd();

	// signal stand line
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+20.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+20.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+23.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+23.0),0.0);
    glEnd();

    if(lft_to_right=true){
    if(green_signal){
        glColor3f(0.0,1.0,0.0);
        redsignal = false;
        orange_light = false;
    }
    else{
        glColor3f(0.0,0.0,0.0);
    }
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+45.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+45.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+58.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+58.0),0.0);
    glEnd();
    }

    if(tp_to_bttm==false){
		if(redsignal){
        glColor3f(1.0,0.0,0.0);
        green_signal = false;
        orange_light = false;
    }
    else{
        glColor3f(0.0,0.0,0.0);
    }
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+60.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+60.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+73.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+73.0),0.0);
    glEnd();
	}

    if(orange_light){
        glColor3f(1.0,0.5,0.0);
        green_signal = false;
        redsignal = false;
    }
    else{
        glColor3f(0.0,0.0,0.0);
    }
    glBegin(GL_POLYGON);
    glVertex3f(pixel(x-8.0),pixel(y+42.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+42.0),0.0);
    glVertex3f(pixel(x+12.0),pixel(y+30.0),0.0);
    glVertex3f(pixel(x-8.0),pixel(y+30.0),0.0);
    glEnd();

}


void display1(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    field();
    sky();

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glTranslatef(0.0,0.0,0.0);
    road();
    zebra_crossing();

    glPushMatrix();
    glTranslatef(-20.0,20.0,0.0);
    sun();
    glPopMatrix();

   glPushMatrix();
    signal1(0.0,125.0);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(carmove_lft_to_rit,2.0,0);
    car();
    glPopMatrix();

    glFlush();
}


void mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    display1();
    glFlush();
}


void my_keyboard(unsigned char key, int x, int y)
{
    if(key == 27){
        exit(0);
    }
    if(key == 'r'){
        start = false;
    }
    if(key == 'g'){
        start = true;
    }
	if(key == 'o'){
        start = true;
        orange_light_comes = true;
	}
}


int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1366, 768);
	glutInitWindowPosition (20, 40 );
	glutCreateWindow ("Traffic Signal System");
	glutTimerFunc(15, alltransports_move, 1);
	init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(mydisplay);
	glutTimerFunc(15, alltransports_move, 0);
	glutMainLoop();
	return 0;
}