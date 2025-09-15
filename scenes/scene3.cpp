#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


float move_trainScene3 = 1200.0f;
float speed_trainScene3 = -2.2f;
float move_car1Scene3 = 0.0f;
float speed_car1Scene3 = 2.0f;
float move_car2Scene3 = 1200.0f;
float speed_car2Scene3 = -2.5f;
float move_flycar1Scene3 = 0.0f;
float speed_flycar1Scene3 = 3.0f;
float move_flycar2Scene3 = 1200.0f;
float speed_flycar2Scene3 = -2.8f;
float move_cloud1Scene3 = 0.0f;
float speed_cloud1Scene3 = 0.3f;
float move_cloud2Scene3 = 200.0f;
float speed_cloud2Scene3 = 0.4f;
int window_widthScene3 = 1200;
int window_heightScene3 = 800;

// Variables for interaction
GLfloat building_colorScene3[3] = {0.75f, 0.75f, 0.78f};

// Forward declarations for animation functions
void train_animationScene3(int);
void cars_animationScene3(int);
void clouds_animationScene3(int);

//                              DRAWING FUNCTIONS



//ID1
void SkyScene3() {
    glBegin(GL_POLYGON);
        glColor3f(0.53f, 0.81f, 0.98f);
         glVertex2f(0, window_heightScene3);

        glColor3f(0.68f, 0.92f, 1.0f);
         glVertex2f(window_widthScene3, window_heightScene3);

        glColor3f(0.68f, 0.92f, 1.0f);
        glVertex2f(window_widthScene3, 0);

        glColor3f(0.53f, 0.81f, 0.98f);
         glVertex2f(0, 0);
    glEnd();
}

//ID2
void GroundScene3() {
    // Green Area
    glColor3f(0.6f, 0.8f, 0.6f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(window_widthScene3, 0);
        glVertex2f(window_widthScene3, 100);
        glVertex2f(0, 100);
    glEnd();


    // Road
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 40);
        glVertex2f(window_widthScene3, 40);
        glVertex2f(window_widthScene3, 80);
        glVertex2f(0, 80);
    glEnd();


    // Road Lines
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        for (int i = 0; i < window_widthScene3; i += 60)
        {
            glVertex2f(i, 60);
            glVertex2f(i + 30, 60);
        }
    glEnd();
}

//ID3
void Cloud1Scene3() {
    glPushMatrix();
    glTranslatef(move_cloud1Scene3, 650, 0);
    glColor3f(0.95f, 0.95f, 0.95f);

    // Each circle is a GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0,0);
        for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
        glVertex2f(0+20*cos(a), 0+20*sin(a));}
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(15,10);
        for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
        glVertex2f(15+15*cos(a), 10+15*sin(a));}
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-15,5);
        for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
        glVertex2f(-15+18*cos(a), 5+18*sin(a));}
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(30,0);
        for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
        glVertex2f(30+12*cos(a), 0+12*sin(a));}
    glEnd();


    glPopMatrix();
}

//ID4
void Cloud2Scene3() {
    glPushMatrix();
    glTranslatef(move_cloud2Scene3, 600, 0);
    glColor3f(0.95f, 0.95f, 0.95f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0,0);
        for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
        glVertex2f(0+20*cos(a), 0+20*sin(a));}
     glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(15,10);
     for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
        glVertex2f(15+15*cos(a), 10+15*sin(a));}
     glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-15,5);
    for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
         glVertex2f(-15+18*cos(a), 5+18*sin(a));}
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(30,0);
    for(int i=0;i<=36;i++)
        { float a=i*M_PI/18.0;
        glVertex2f(30+12*cos(a), 0+12*sin(a));}
    glEnd();

    glPopMatrix();
}

//ID5
void PillarsScene3() {
    // Pillar 1
    glColor3f(0.45f,0.45f,0.48f);
    glBegin(GL_POLYGON);
    glVertex2f(220,100);
    glVertex2f(246,100);
    glVertex2f(246,518);
    glVertex2f(220,518);
    glEnd();

    glColor3f(0.38f,0.38f,0.41f);
     glBegin(GL_POLYGON);
     glVertex2f(225,108);
     glVertex2f(241,108);
     glVertex2f(241,510);
     glVertex2f(225,510);
     glEnd();


    // Pillar 2
    glColor3f(0.45f,0.45f,0.48f);
    glBegin(GL_POLYGON);
    glVertex2f(520,100);
    glVertex2f(546,100);
    glVertex2f(546,518);
    glVertex2f(520,518);
    glEnd();

    glColor3f(0.38f,0.38f,0.41f);
    glBegin(GL_POLYGON);
    glVertex2f(525,108);
    glVertex2f(541,108);
    glVertex2f(541,510);
    glVertex2f(525,510);
    glEnd();


    // Pillar 3
    glColor3f(0.45f,0.45f,0.48f);
    glBegin(GL_POLYGON);
    glVertex2f(820,100);
    glVertex2f(846,100);
    glVertex2f(846,518);
    glVertex2f(820,518);
    glEnd();

    glColor3f(0.38f,0.38f,0.41f);
    glBegin(GL_POLYGON);
    glVertex2f(825,108);
    glVertex2f(841,108);
    glVertex2f(841,510);
    glVertex2f(825,510);
    glEnd();
}

//ID6
void HoverTrackScene3() {
    glColor3f(0.12f,0.12f,0.12f);
    glBegin(GL_POLYGON);
    glVertex2f(0,518);
    glVertex2f(window_widthScene3,518);
    glVertex2f(window_widthScene3,536);
    glVertex2f(0,536);
    glEnd();

    glColor3f(0.18f,0.18f,0.18f);
    glBegin(GL_POLYGON);
    glVertex2f(6,524);
    glVertex2f(window_widthScene3-12,524);
    glVertex2f(window_widthScene3-12,530);
    glVertex2f(6,530);
    glEnd();
}

//ID7 - ID11
void BuildingsScene3() {
    // Building 1 (x=60, h=300)
    glColor3fv(building_colorScene3);
    glBegin(GL_POLYGON);
    glVertex2f(60,100);
    glVertex2f(220,100);
    glVertex2f(220,400);
    glVertex2f(60,400);
    glEnd();



    glColor3f(0.3f,0.2f,0.1f);
    glBegin(GL_POLYGON);
     glVertex2f(120,100);
     glVertex2f(160,100);
     glVertex2f(160,160);
     glVertex2f(120,160);
     glEnd(); // Door


    for(int i=0;i<3;i++)
        { for(int j=0;j<4;j++)
        { glColor3f(0.9f,0.95f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(75+i*50, 180+j*50);
     glVertex2f(105+i*50, 180+j*50);
     glVertex2f(105+i*50, 210+j*50);
     glVertex2f(75+i*50, 210+j*50);
     glEnd();}} // Windows



    // Building 2 (x=300, h=320)
    glColor3fv(building_colorScene3);
    glBegin(GL_POLYGON);
     glVertex2f(300,100);
     glVertex2f(480,100);
     glVertex2f(480,420);
     glVertex2f(300,420);
     glEnd();


    glColor3f(0.3f,0.2f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(370,100);
    glVertex2f(410,100);
    glVertex2f(410,160);
    glVertex2f(370,160);
    glEnd(); // Door


    for(int i=0;i<3;i++)
        { for(int j=0;j<4;j++)
        { glColor3f(0.9f,0.95f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(315+i*50, 180+j*50);
    glVertex2f(345+i*50, 180+j*50);
    glVertex2f(345+i*50, 210+j*50);
    glVertex2f(315+i*50, 210+j*50);
    glEnd();}} // Windows




    // Building 3 (x=660, h=260)
    glColor3fv(building_colorScene3);
    glBegin(GL_POLYGON);
    glVertex2f(660,100);
    glVertex2f(900,100);
    glVertex2f(900,360);
    glVertex2f(660,360);
    glEnd();



    glColor3f(0.3f,0.2f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(760,100);
    glVertex2f(800,100);
    glVertex2f(800,160);
    glVertex2f(760,160);
    glEnd(); // Door

    for(int i=0;i<4;i++)
        { for(int j=0;j<3;j++)
            { glColor3f(0.9f,0.95f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(675+i*50, 180+j*50);
    glVertex2f(705+i*50, 180+j*50);
    glVertex2f(705+i*50, 210+j*50);
    glVertex2f(675+i*50, 210+j*50);
    glEnd();}} // Windows


    // Building 4 (x=960, h=160)
    glColor3fv(building_colorScene3);
    glBegin(GL_POLYGON);
    glVertex2f(960,100);
    glVertex2f(1060,100);
    glVertex2f(1060,260);
    glVertex2f(960,260);
    glEnd();


    glColor3f(0.3f,0.2f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(990,100);
    glVertex2f(1030,100);
     glVertex2f(1030,160);
     glVertex2f(990,160);
     glEnd(); // Door


    for(int i=0;i<1;i++)
        { for(int j=0;j<1;j++)
        { glColor3f(0.9f,0.95f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(975+i*50, 180+j*50);
    glVertex2f(1005+i*50, 180+j*50);
    glVertex2f(1005+i*50, 210+j*50);
    glVertex2f(975+i*50, 210+j*50);
    glEnd();}} // Windows



    // Building 5 (x=1100, h=140)
    glColor3fv(building_colorScene3);
    glBegin(GL_POLYGON);
    glVertex2f(1100,100);
    glVertex2f(1190,100);
    glVertex2f(1190,240);
    glVertex2f(1100,240);
    glEnd();

    glColor3f(0.3f,0.2f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(1125,100);
    glVertex2f(1165,100);
    glVertex2f(1165,160);
    glVertex2f(1125,160);
    glEnd(); // Door
}

//ID12 - ID15
void TreesScene3() {
    // Tree 1
    glPushMatrix();
    glTranslatef(20,100,0);
    glColor3f(0.35f,0.2f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(18,0);
    glVertex2f(18,48);
    glVertex2f(0,48);
    glEnd();


    glColor3f(0.13f,0.65f,0.21f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(9,72);
    for(int i=0;i<=24;i++)
        {float a=i*M_PI/12.0;
    glVertex2f(9+28*cos(a),72+28*sin(a));}
    glEnd();

    glPopMatrix();


    // Tree 2
    glPushMatrix();
    glTranslatef(240,100,0);
    glColor3f(0.35f,0.2f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(18,0);
    glVertex2f(18,48);
    glVertex2f(0,48);
    glEnd();


    glColor3f(0.13f,0.65f,0.21f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(9,72);
    for(int i=0;i<=24;i++)
        {float a=i*M_PI/12.0;
    glVertex2f(9+28*cos(a),72+28*sin(a));}
    glEnd();

    glPopMatrix();


    // Tree 3
    glPushMatrix();

    glTranslatef(620,100,0);
    glColor3f(0.35f,0.2f,0.1f);

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(18,0);
    glVertex2f(18,48);
    glVertex2f(0,48);
    glEnd();


    glColor3f(0.13f,0.65f,0.21f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(9,72);
    for(int i=0;i<=24;i++)
        {float a=i*M_PI/12.0;
    glVertex2f(9+28*cos(a),72+28*sin(a));}
    glEnd();

     glPopMatrix();

    // Tree 4
    glPushMatrix();

    glTranslatef(980,100,0);
    glColor3f(0.35f,0.2f,0.1f);

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(18,0);
    glVertex2f(18,48);
    glVertex2f(0,48);
    glEnd();

    glColor3f(0.13f,0.65f,0.21f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(9,72);
    for(int i=0;i<=24;i++)
        {float a=i*M_PI/12.0;
    glVertex2f(9+28*cos(a),72+28*sin(a));}
    glEnd();

    glPopMatrix();
}

//ID16
void GroundCar_RedScene3()
 {
    glPushMatrix();
    glTranslatef(move_car1Scene3, 45, 0);

    // Body
    glColor3f(0.85f, 0.10f, 0.15f);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(155,0);
    glVertex2f(155,33);
    glVertex2f(110,48);
    glVertex2f(50,48);
    glVertex2f(20,39);
    glVertex2f(0,33);
    glEnd();


    // Windows
    glColor3f(0.35f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(30,33);
    glVertex2f(120,33);
    glVertex2f(120,52);
    glVertex2f(30,52);
    glEnd();


    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2f(40,38);
    glVertex2f(72,38);
    glVertex2f(72,55);
    glVertex2f(40,55);
    glEnd();


    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2f(75,38);
    glVertex2f(108,38);
    glVertex2f(108,55);
    glVertex2f(75,55);
    glEnd();

    // Wheels
    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(35,5);
    for(int i=0;i<=32;i++)
        {float a=i*M_PI/16.0;
    glVertex2f(35+17*cos(a),5+17*sin(a));}
    glEnd();


    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(130,5);
    for(int i=0;i<=32;i++)
        {float a=i*M_PI/16.0;
    glVertex2f(130+17*cos(a),5+17*sin(a));}
    glEnd();


    glPopMatrix();
}

//ID17
void GroundCar_BlueScene3() {
    glPushMatrix();
    glTranslatef(move_car2Scene3, 45, 0);

    // Body
    glColor3f(0.13f,0.36f,0.87f);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(160,0);
    glVertex2f(160,33);
    glVertex2f(120,48);
    glVertex2f(37,48);
    glVertex2f(0,33);
    glEnd();

    // Windows
    glColor3f(0.23f, 0.39f, 0.81f);
     glBegin(GL_POLYGON);
     glVertex2f(30,33);
     glVertex2f(120,33);
     glVertex2f(120,52);
     glVertex2f(30,52);
     glEnd();


    glColor3f(0.96f,0.96f,0.97f);
    glBegin(GL_POLYGON);
    glVertex2f(40,38);
    glVertex2f(72,38);
    glVertex2f(72,55);
    glVertex2f(40,55);
    glEnd();


    glColor3f(0.96f,0.96f,0.97f);
    glBegin(GL_POLYGON);
    glVertex2f(75,38);
    glVertex2f(108,38);
    glVertex2f(108,55);
    glVertex2f(75,55);
    glEnd();


    // Wheels
    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(35,5);
    for(int i=0;i<=32;i++)
        {float a=i*M_PI/16.0;
    glVertex2f(35+17*cos(a),5+17*sin(a));}
    glEnd();


    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(130,5);
    for(int i=0;i<=32;i++)
        {float a=i*M_PI/16.0;
    glVertex2f(130+17*cos(a),5+17*sin(a));}
    glEnd();

    glPopMatrix();
}

//ID18
void FlyingCar_OrangeScene3() {
    glPushMatrix();

    glTranslatef(move_flycar1Scene3, 700, 0);
    glColor3f(0.97f, 0.46f, 0.14f);

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(57,0);
    glVertex2f(54,18);
    glVertex2f(35,25);
    glVertex2f(12,18);
    glEnd();

    glColor3f(0.91f, 0.98f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15,8);
    glVertex2f(37,8);
    glVertex2f(37,18);
    glVertex2f(15,18);
    glEnd();


    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(15,-2);
    for(int i=0;i<=16;i++)
        {float a=i*M_PI/8.0;
    glVertex2f(15+8*cos(a),-2+8*sin(a));}
    glEnd();


    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(42,-2);
    for(int i=0;i<=16;i++)
        {float a=i*M_PI/8.0;
    glVertex2f(42+8*cos(a),-2+8*sin(a));}
    glEnd();

    glPopMatrix();
}

//ID19
void FlyingCar_GreenScene3() {
    glPushMatrix();

    glTranslatef(move_flycar2Scene3, 650, 0);
    glColor3f(0.19f, 0.67f, 0.19f);

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(57,0);
    glVertex2f(54,18);
    glVertex2f(35,25);
    glVertex2f(12,18);
    glEnd();

    glColor3f(0.91f, 0.98f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15,8);
    glVertex2f(37,8);
    glVertex2f(37,18);
    glVertex2f(15,18);
    glEnd();


    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(15,-2);
    for(int i=0;i<=16;i++)
        {float a=i*M_PI/8.0;
    glVertex2f(15+8*cos(a),-2+8*sin(a));}
    glEnd();


    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(42,-2);
    for(int i=0;i<=16;i++)
        {float a=i*M_PI/8.0;
    glVertex2f(42+8*cos(a),-2+8*sin(a));}
    glEnd();


    glPopMatrix();
}

//ID20
void HoverTrainScene3() {
    glPushMatrix();
    glTranslatef(move_trainScene3, 518, 0);
    float w=80,h=48,g=10;
    for(int i=0;i<5;i++){
        float X = i*(w+g);
        glColor3f(i==0?0.85f:0.13f, i==0?0.17f:0.36f, i==0?0.19f:0.87f);
        glBegin(GL_POLYGON);
        glVertex2f(X,0);
        glVertex2f(X+w,0);
        glVertex2f(X+w,h);
        glVertex2f(X,h);
        glEnd();


        // Windows
        glColor3f(0.9f,0.95f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(X+10,h-25);
        glVertex2f(X+35,h-25);
        glVertex2f(X+35,h-10);
        glVertex2f(X+10,h-10);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(X+w-35,h-25);
        glVertex2f(X+w-10,h-25);
        glVertex2f(X+w-10,h-10);
        glVertex2f(X+w-35,h-10);
        glEnd();
    }
    glPopMatrix();
}


//                              MAIN DISPLAY FUNCTION


void displayScene3() {
    // glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, window_widthScene3, 0, window_heightScene3);
    glClear(GL_COLOR_BUFFER_BIT);

    // This calls every drawing function in the correct order to build the scene.
    SkyScene3();           //ID1
    GroundScene3();           //ID2
    Cloud1Scene3();           //ID3
    Cloud2Scene3();           //ID4
    PillarsScene3();          //ID5
    HoverTrackScene3();       //ID6
    BuildingsScene3();        //ID7 - ID11
    TreesScene3();            //ID12 - ID15
    GroundCar_RedScene3();    //ID16
    GroundCar_BlueScene3();   //ID17
    FlyingCar_OrangeScene3(); //ID18
    FlyingCar_GreenScene3();  //ID19
    HoverTrainScene3();       //ID20

    glutSwapBuffers(); // Render now
}


//                              INTERACTION HANDLERS


void handleMouseScene3(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            speed_flycar1Scene3 += 1.5f;
            speed_flycar2Scene3 -= 1.5f;
        }
        if (button == GLUT_RIGHT_BUTTON) {
            building_colorScene3[0] = (float)rand() / RAND_MAX;
            building_colorScene3[1] = (float)rand() / RAND_MAX;
            building_colorScene3[2] = (float)rand() / RAND_MAX;
        }
    }
    glutPostRedisplay();
}

void handleKeypressScene3(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            speed_trainScene3 -= 0.5f;
            break;

        case 's':
            if (speed_flycar1Scene3 > 0.2f)
                speed_flycar1Scene3 -= 0.2f;
            if (speed_flycar2Scene3 < -0.2f)
                speed_flycar2Scene3 += 0.2f;
            break;
        case 'a':
            speed_car1Scene3 += 0.5f;
            speed_car2Scene3 -= 0.5f;
            break;
        case 'd':
            if (speed_car1Scene3 > 0.5f)
                speed_car1Scene3 -= 0.5f;
            if (speed_car2Scene3 < -0.5f)
             speed_car2Scene3 += 0.5f;

            break;
        case ' ':
                // Decrease speed of the hover TRAIN only
            if (speed_trainScene3 < -0.2f)
                speed_trainScene3 += 0.2f;
            break;

    }
    glutPostRedisplay();
}



//                              ANIMATION FUNCTIONS


void train_animationScene3(int value)
 {
    move_trainScene3 += speed_trainScene3;
    if (move_trainScene3 < -500) move_trainScene3 = window_widthScene3 + 100;
    glutPostRedisplay();
    glutTimerFunc(16, train_animationScene3, 0);
}

void cars_animationScene3(int value)
 {
    move_car1Scene3 += speed_car1Scene3;
    if(move_car1Scene3 > window_widthScene3 + 160) move_car1Scene3 = -160;

    move_car2Scene3 += speed_car2Scene3;
    if(move_car2Scene3 < -160) move_car2Scene3 = window_widthScene3 + 160;

    move_flycar1Scene3 += speed_flycar1Scene3;
    if(move_flycar1Scene3 > window_widthScene3 + 60) move_flycar1Scene3 = -60;

    move_flycar2Scene3 += speed_flycar2Scene3;
    if(move_flycar2Scene3 < -60) move_flycar2Scene3 = window_widthScene3 + 60;

    glutPostRedisplay();
    glutTimerFunc(25, cars_animationScene3, 0);
}

void clouds_animationScene3(int value)
{
    move_cloud1Scene3 += speed_cloud1Scene3;
    if(move_cloud1Scene3 > window_widthScene3 + 50) move_cloud1Scene3 = -100;

    move_cloud2Scene3 += speed_cloud2Scene3;
    if(move_cloud2Scene3 > window_widthScene3 + 50) move_cloud2Scene3 = -100;


    glutPostRedisplay();
    glutTimerFunc(50, clouds_animationScene3, 0);
}

void initScene3() {
    glutReshapeWindow(window_widthScene3, window_heightScene3);
    glutSetWindowTitle("Scene 3: Futuristic City");
}


//                              MAIN FUNCTION
/*
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(window_widthScene3, window_heightScene3);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - window_widthScene3)/2, (glutGet(GLUT_SCREEN_HEIGHT) - window_heightScene3)/2);
    glutCreateWindow("Futuristic City View");

    // Register display and input callbacks
    glutDisplayFunc(displayScene3);
    glutKeyboardFunc(handleKeypressScene3);
    glutMouseFunc(handleMouseScene3);

    // Register animation timers
    glutTimerFunc(25, train_animationScene3, 0);
    glutTimerFunc(25, cars_animationScene3, 0);
    glutTimerFunc(25, clouds_animationScene3, 0);

    // Seed random number generator
    srand(time(NULL));

    // Set coordinate system
    gluOrtho2D(0, window_widthScene3, 0, window_heightScene3);

    glutMainLoop();
    return 0;
}
*/