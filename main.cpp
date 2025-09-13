#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

// color codes
struct Color {
    unsigned int r, g, b;
};

struct Coordinate {
    float x = 0.0f, y = 0.0f, z = 0.0f;
};

Color woodColor = {138, 80, 53};
Color house1BodyColor = {242, 236, 230};
Color house1BodyColor2 = {219, 219, 219};
Coordinate _move_cloud = {0.0f, 0.0f, 0.0f};
Coordinate _move_boat = {0.0f, 0.0f, 0.0f};
float _speed = 1.0f;
bool stopAnimation = false;
bool isDay = true;
bool _volcano_erupting = false;
float _window_mill_angle = 0.0f;
Coordinate _move_horse_cart = {0.0f, 0.0f, 0.0f};
float _horse_cart_angle = 0.0f;
float _horse_legs_angle = 0.0f;
float _current_offset = 0.0f;
Coordinate _prev_mouse_pos = {0.0f, 0.0f, 0.0f};


void drawCircle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

void drawCircleOutlined(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

void drawWindMill1() {
    // body
    glBegin(GL_QUADS);
    glColor3ub(168, 167, 149);
    glVertex2f(-206.91, 274.55);
    glVertex2f(-1.67, 273.09);
    glColor3ub(206, 206, 194);
    glVertex2f(-8.78, -32.92);
    glVertex2f(-207.35, -30.14);
    glEnd();

    // roof
    glBegin(GL_QUADS);
    glColor3ub(120, 85, 55);
    glVertex2f(-237.45, 271.61);
    glVertex2f(-114.71, 393.87);
    glColor3ub(94, 62, 37);
    glVertex2f(-98.85, 393.58);
    glVertex2f(21.54, 270.82);
    glEnd();

        // door
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glBegin(GL_QUADS);
    glVertex2f(-143.13, 73.21);
    glVertex2f(-139.75, -35.07);
    glVertex2f(-76.73, -35.31);
    glVertex2f(-76.06, 73.21);
    glEnd();

    for(int i = 1; i < 7; i++) {
        glColor3ub(41, 41, 41);
        glLineWidth(0.5);
        glBegin(GL_LINES);
        glVertex2f(-76.06 - i*10, 73.21);
        glVertex2f(-76.73 - i*10, -35.31);
        glEnd();
    }

    glLineWidth(4.0);
    glColor3ub(201, 173, 145);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-143.13, 73.21);
    glVertex2f(-139.75, -35.07);
    glVertex2f(-76.73, -35.31);
    glVertex2f(-76.06, 73.21);
    glEnd();

    // window
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glBegin(GL_QUADS);
    glVertex2f(-132.39, 190.40);
    glVertex2f(-88.22, 190.40);
    glVertex2f(-88.66, 141.47);
    glVertex2f(-131.96, 141.90);
    glEnd();

    for(int i = 1; i < 6; i++) {
        glColor3ub(41, 41, 41);
        glLineWidth(0.5);
        glBegin(GL_LINES);
        glVertex2f(-88.22 - i*8, 190.40);
        glVertex2f(-88.66 - i*8, 141.47);
        glEnd();
    }

    // border
    glLineWidth(3.0);
    glColor3ub(201, 173, 145);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-132.39, 190.40);
    glVertex2f(-88.22, 190.40);
    glVertex2f(-88.66, 141.47);
    glVertex2f(-131.96, 141.90);
    glEnd();

    glLineWidth(6.0);
    glColor3ub(201, 173, 145);
    glBegin(GL_LINES);
    glVertex2f(-132.39, 190.40);
    glVertex2f(-88.66, 141.47);
    glEnd();

    glLineWidth(6.0);
    glColor3ub(201, 173, 145);
    glBegin(GL_LINES);
    glVertex2f(-88.22, 190.40);
    glVertex2f(-131.96, 141.90);
    glEnd();

    // fan
    drawCircle(15, -106.85, 272.80, 0.306f, 0.329f, 0.224f);
    drawCircle(8, -106.85, 272.80, 0.541f, 0.314f, 0.208f);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-106.85, 272.80, 0.0f);
    glRotatef(_window_mill_angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(106.85, -272.80, 0.0f);
    // fan plates
    // 1
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-245.34, 375.70);
    glVertex2f(-220.76, 402.76);
    glVertex2f(-128.66, 316.96);
    glVertex2f(-151.91, 291.49);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-106.85, 272.80);
    glVertex2f(-234.63, 389.19);
    glEnd();

    for(int i = 1; i < 9; i++) {
        glLineWidth(3.0);
        glBegin(GL_LINES);
        glVertex2f(-245.34 + i*10, 375.70 - i*10);
        glVertex2f(-220.76 + i*10, 402.76 - i*10);
        glEnd();
    }

    // 2
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-3.35, 410.68);
    glVertex2f(20.40, 387.25);
    glVertex2f(-64.07, 294.86);
    glVertex2f(-89.81, 318.29);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-106.85, 272.80);
    glVertex2f(8.20, 399.66);
    glEnd();

    for(int i = 1; i < 9; i++) {
        glLineWidth(3.0);
        glBegin(GL_LINES);
        glVertex2f(-3.35 - i*10, 410.68 - i*10);
        glVertex2f(20.40 - i*10, 387.25 - i*10);
        glEnd();
    }

    // 3
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(12.91, 142.90);
    glVertex2f(38.04, 169.20);
    glVertex2f(-62.29, 254.88);
    glVertex2f(-85.02, 229.51);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-106.85, 272.80);
    glVertex2f(26.35, 158.63);
    glEnd();

    for(int i = 1; i < 9; i++) {
        glLineWidth(3.0);
        glBegin(GL_LINES);
        glVertex2f(12.91 - i*10, 142.90 + i*10);
        glVertex2f(38.04 - i*10, 169.20 + i*10);
        glEnd();
    }


    // 4
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-149.87, 250.63);
    glVertex2f(-124.94, 228.57);
    glVertex2f(-210.76, 137.97);
    glVertex2f(-234.43, 158.34);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-106.85, 272.80);
    glVertex2f(-219.87, 148.51);
    glEnd();

    for(int i = 1; i < 9; i++) {
        glLineWidth(3.0);
        glBegin(GL_LINES);
        glVertex2f(-234.43 + i*10, 158.34 + i*10);
        glVertex2f(-210.76 + i*10, 137.97 + i*10);
        glEnd();
    }

    glPopMatrix();

}


void drawHouse1Window() {
    glBegin(GL_QUADS);
    glColor3ub(52, 52, 52);
    glVertex2f(-308.90, 115.27);
    glVertex2f(-276.63, 116.25);
    glColor3ub(102, 99, 99);
    glVertex2f(-276.63, 79.58);
    glVertex2f(-308.90, 79.58);
    glEnd();

    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-308.90, 115.27);
    glVertex2f(-276.63, 116.25);
    glVertex2f(-276.63, 79.58);
    glVertex2f(-308.90, 79.58);
    glEnd();

    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glBegin(GL_QUADS);
    glVertex2f(-308.90, 115.27);
    glVertex2f(-276.63, 116.25);
    glVertex2f(-256.412, 88.53);
    glVertex2f(-293.08, 88.82);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-299.10, 96.56);
    glVertex2f(-302.82, 79.58);
    glEnd();

}

void drawHouse1(Color roofColor = woodColor) {
    // body roof left
    glColor3ub(house1BodyColor.r, house1BodyColor.g, house1BodyColor.b);
    glBegin(GL_TRIANGLES);
    glVertex2f(-383.572, 230.66);
    glVertex2f(-439.65, 152.42);
    glColor3ub(house1BodyColor2.r, house1BodyColor2.g, house1BodyColor2.b);
    glVertex2f(-330.88, 151.24);
    glEnd();

    // body left
    glBegin(GL_QUADS);
    glColor3ub(house1BodyColor.r, house1BodyColor.g, house1BodyColor.b);
    glVertex2f(-423.55, 152.24);
    glVertex2f(-330.88, 151.24);
    glColor3ub(house1BodyColor2.r, house1BodyColor2.g, house1BodyColor2.b);
    glVertex2f(-344.273, -44.86);
    glVertex2f(-410.34, -44.12);
    glEnd();

    // body right
    glBegin(GL_QUADS);
    glColor3ub(house1BodyColor.r, house1BodyColor.g, house1BodyColor.b);
    glVertex2f(-320.656, 156.13);
    glVertex2f(-195.70, 150.95);
    glColor3ub(house1BodyColor2.r, house1BodyColor2.g, house1BodyColor2.b);
    glVertex2f(-211.545, -43.34);
    glVertex2f(-336.85, -40.85);
    glEnd();

    // house details - left side
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-429.22, 154.24);
    glVertex2f(-330.88, 153.24);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-425.14, 154.24);
    glVertex2f(-335.38, 153.24);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-414.87, 154.24);
    glVertex2f(-333.48, 153.24);
    glEnd();

    // house details - right side
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-327.83, 123.17);
    glVertex2f(-195.46, 126.00);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(-335.38, 48.10);
    glVertex2f(-199.51, 48.28);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-333.48, 30.99);
    glVertex2f(-203.15, 31.28);
    glEnd();

    //  house borders
    glColor3ub(168, 139, 138);
    glBegin(GL_QUADS);
    glVertex2f(-387.60, 250.91);
    glVertex2f(-381.11, 250.79);
    glVertex2f(-381.37, 242.42);
    glVertex2f(-387.75, 242.40);
    glEnd();

    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glBegin(GL_QUADS);
    glVertex2f(-443.49, 156.80);
    glVertex2f(-439.66, 152.42);
    glVertex2f(-383.57, 230.67);
    glVertex2f(-387.75, 242.40);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-387.74, 242.39);
    glVertex2f(-381.37, 242.42);
    glVertex2f(-380.00, 240.00);
    glVertex2f(-324.47, 156.52);
    glVertex2f(-330.88, 151.24);
    glVertex2f(-383.57, 230.66);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-381.11, 250.79);
    glVertex2f(-381.37, 242.42);
    glVertex2f(-223.86, 251.01);
    glVertex2f(-223.90, 243.35);
    glEnd();

    // roof
    glColor3ub(roofColor.r, roofColor.g, roofColor.b);
    glBegin(GL_QUADS);
    glVertex2f(-381.37, 242.42);
    glVertex2f(-324.47, 156.52);
    glVertex2f(-176.62, 152.27);
    glVertex2f(-226.57, 243.35);
    glEnd();

    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glBegin(GL_QUADS);
    glVertex2f(-429.22, 152.24);
    glVertex2f(-423.55, 152.24);
    glVertex2f(-409.981, -47.86);
    glVertex2f(-402.71, -48.32);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-330.88, 151.24);
    glVertex2f(-320.656, 156.13);
    glVertex2f(-337.21, -45.07);
    glVertex2f(-344.27, -44.86);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-410.34, -40.85);
    glVertex2f(-409.981, -47.86);
    glVertex2f(-402.71, -48.32);
    glVertex2f(-344.27, -44.86);
    glVertex2f(-337.21, -45.07);
    glVertex2f(-336.85, -40.85);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-336.85, -40.85);
    glVertex2f(-337.21, -45.07);
    glVertex2f(-205.58, -48.12);
    glVertex2f(-204.38, -44.47);
    glVertex2f(-211.55, -43.34);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-195.70, 150.95);
    glVertex2f(-188.16, 150.57);
    glVertex2f(-204.38, -44.47);
    glVertex2f(-211.55, -43.34);
    glEnd();

    // door
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glBegin(GL_QUADS);
    glVertex2f(-395.18, 20.05);
    glVertex2f(-354.38, 20.85);
    glVertex2f(-354.11, -43.57);
    glVertex2f(-392.76, -44.91);
    glEnd();

    for(int i = 1; i < 6; i++) {
        glColor3ub(41, 41, 41);
        glLineWidth(0.5);
        glBegin(GL_LINES);
        glVertex2f(-354.38 - i*7, 20.85);
        glVertex2f(-354.11 - i*7, -43.57);
        glEnd();
    }

    // door border
    glLineWidth(3.0);
    glColor3ub(201, 173, 145);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-395.18, 20.05);
    glVertex2f(-354.38, 20.85);
    glVertex2f(-354.11, -43.57);
    glVertex2f(-392.76, -44.91);
    glEnd();

    // door knob
    // glColor3ub(242, 0, 0);
    // glPointSize(8.0);
    // glBegin(GL_POINTS);
    // glVertex2f(-375.00, -11.00);
    // glEnd();


    // windows
    drawHouse1Window();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(60, 0, 0);
    drawHouse1Window();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0, -100, 0);
    drawHouse1Window();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(60, -100, 0);
    drawHouse1Window();
    glPopMatrix();
}

void drawHouse2() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(400, 0.0f, 0.0f);
    drawHouse1({78, 90, 88});
    glPopMatrix();
}

void drawHouse3() {
    Color bodyColor1 = {135, 149, 160};
    Color bodyColor2 = {110, 120, 128};

    // house body
    glBegin(GL_TRIANGLES);
    glColor3ub(bodyColor1.r, bodyColor1.g, bodyColor1.b);
    glVertex2f(130.71, 135.64);
    glVertex2f(74.52, 53.91);
    glColor3ub(bodyColor2.r, bodyColor2.g, bodyColor2.b);
    glVertex2f(183.07, 52.21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(bodyColor1.r, bodyColor1.g, bodyColor1.b);
    glVertex2f(90.2777, 53.0660);
    glVertex2f(183.0707, 52.2147);
    glColor3ub(bodyColor2.r, bodyColor2.g, bodyColor2.b);
    glVertex2f(178.8142, -44.8348);
    glVertex2f(95.3856, -43.1322);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(bodyColor1.r, bodyColor1.g, bodyColor1.b);
    glVertex2f(129.3524, 144.0175);
    glVertex2f(222.67, 51.66);
    glColor3ub(bodyColor2.r, bodyColor2.g, bodyColor2.b);
    glVertex2f(233.2386, -42.1181);
    glVertex2f(178.81, -44.83);
    glEnd();

    // house roof
    glBegin(GL_QUADS);
    glColor3ub(177, 115, 16);
    glVertex2f(129.35, 144.02);
    glVertex2f(214.86, 142.79);
    glColor3ub(247, 165, 57);
    glVertex2f(212.68, 51.66);
    glVertex2f(183.07, 52.21);
    glEnd();

    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    // house borders - outer lines
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glVertex2f(130.71, 135.64);
    glVertex2f(74.52, 53.91);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(130.71, 135.64);
    glVertex2f(183.07, 52.21);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(90.27, 53.06);
    glVertex2f(95.38, -43.13);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(90.27, 53.06);
    glVertex2f(183.07, 52.21);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(183.07, 52.21);
    glVertex2f(178.81, -44.83);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(95.38, -43.13);
    glVertex2f(178.81, -44.83);
    glEnd();

    glLineWidth(7.0);
    glBegin(GL_LINES);
    glVertex2f(129.35, 144.02);
    glVertex2f(194.86, 142.79);
    glEnd();

    // house details - inner lines
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(90.27, 53.06);
    glVertex2f(183.07, 52.21);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(89.27, 23.31);
    glVertex2f(181.80, 23.387);
    glEnd();

    // door
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glBegin(GL_QUADS);
    glVertex2f(113.73, 16.17);
    glVertex2f(154.02, 16.52);
    glVertex2f(154.02, -41.08);
    glVertex2f(115.14, -41.08);
    glEnd();

    for(int i = 1; i < 6; i++) {
        glColor3ub(41, 41, 41);
        glLineWidth(0.5);
        glBegin(GL_LINES);
        glVertex2f(154.02 - i*7, 16.52);
        glVertex2f(154.02 - i*7, -41.08);
        glEnd();
    }

    // door border
    glColor3ub(201, 173, 145);
    glBegin(GL_LINE_LOOP);
    glVertex2f(113.73, 16.17);
    glVertex2f(154.02, 16.52);
    glVertex2f(154.02, -41.08);
    glVertex2f(115.14, -41.08);
    glEnd();
}

void drawHouse4() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(600, 0.0f, 0.0f);
    drawHouse1({179, 166, 84});
    glPopMatrix();
}

void drawTree() {
    glColor3ub(woodColor.r, woodColor.g, woodColor.b);
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glVertex2f(-572.63, 380.20);
    glVertex2f(-568.01, -50.78);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(91, 114, 26);
    glVertex2f(-569.83, 141.04);
    glVertex2f(-599.10, -36.85);
    glColor3ub(63, 83, 13);
    glVertex2f(-500.00, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(91, 114, 26);
    glVertex2f(-570.87, 239.83);
    glVertex2f(-600.0, 36.22);
    glColor3ub(63, 83, 13);
    glVertex2f(-500.0, 50);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(91, 114, 26);
    glVertex2f(-571.65, 313.37);
    glVertex2f(-600, 162.56);
    glColor3ub(63, 83, 13);
    glVertex2f(-504.94, 168.46);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(91, 114, 26);
    glVertex2f(-572.63, 407.20);
    glVertex2f(-600,250);
    glColor3ub(63, 83, 13);
    glVertex2f(-521.78,250.94);
    glEnd();
}

void drawTrees() {
    // from left
    // tree 1
    drawTree();

    // tree 2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(100, 0, 0);
    drawTree();
    glPopMatrix();

     // tree 3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(150, 0, 0);
    drawTree();
    glPopMatrix();

     // tree 4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(700, 0, 0);
    drawTree();
    glPopMatrix();

     // tree 5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(750, 0, 0);
    drawTree();
    glPopMatrix();

      // tree 6
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1000, 0, 0);
    drawTree();
    glPopMatrix();

     // tree 7
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1050, 0, 0);
    drawTree();
    glPopMatrix();

}

void drawBoat() {
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(-537.19, -348.64);
    glVertex2f(-337.19, -348.64);
    glColor3ub(160, 82, 45);
    glVertex2f(-377.90, -397.92);
    glVertex2f(-499.31, -397.92);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(205, 133, 63);
    glVertex2f(-486.22, -327.40);
    glVertex2f(-385.90, -328.13);
    glColor3ub(222, 184, 135);
    glVertex2f(-387.19, -348.64);
    glVertex2f(-491.04, -348.64);
    glEnd();
}


void drawCurrent() {
    if(stopAnimation) return;
    glLineWidth(2.0);
    glColor3ub(200, 255, 255);
    glBegin(GL_LINES);
    for (float x = -600; x < 600; x += 50) {
        glVertex2f(x + _current_offset, -250);
        glVertex2f(x + 30 + _current_offset, -600);
    }
    glEnd();

    _current_offset += 0.5f;
    if (_current_offset > 50) _current_offset = 0;
}
void drawCanal() {
    glBegin(GL_QUADS);
    glColor3ub(0, 119, 190);
    glVertex2f(-600, -250);
    glVertex2f(600, -250);
    glColor3ub(0, 82, 132);
    glVertex2f(600, -600);
    glVertex2f(-600, -600);
    glEnd();

    drawCurrent();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_boat.x, _move_boat.y, _move_boat.z);
    // boat 1
    drawBoat();

    // boat 2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(400, -100, 0);
    drawBoat();
    glPopMatrix();
    glPopMatrix();
}

void drawHill() {
    // from right
    glBegin(GL_POLYGON);
    glColor3ub(194, 177, 159);
    glVertex2f(347.629, 72.90);
    glVertex2f(340.06, 355.50);
    glVertex2f(379.79, 467.59);
    glColor3ub(149, 132, 116);
    glVertex2f(422.36, 548.47);
    glVertex2f(500.40, 478.94);
    glColor3ub(117, 100, 82);
    glVertex2f(525.93, 358.34);
    glVertex2f(585.53, 297.33);
    glVertex2f(650, 100);
    glEnd();
    // 2
    glBegin(GL_POLYGON);
    glColor3ub(194, 177, 159);
    glVertex2f(226.48, 214.94);
    glVertex2f(254.44, 342.61);
    glColor3ub(149, 132, 116);
    glVertex2f(313.89, 421.51);
    glVertex2f(333.35, 431.24);
    glColor3ub(117, 100, 82);
    glVertex2f(346.86, 427.99);
    glVertex2f(391.27, 216.22);
    glEnd();

}

void drawSunAndClouds() {
    if(isDay) {
        // Sun
        drawCircle(60, 400, 600, 1.0f, 0.9f, 0.0f);
    } else {
        // Moon
        drawCircle(60, 400, 600, 1.0f, 1.0f, 1.0f);
    }

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_cloud.x, _move_cloud.y, _move_cloud.z);
    // Cloud 1
    drawCircle(50, -300, 650, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(40, -250, 670, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(45, -200, 650, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(35, -250, 630, 0.9059f, 0.9373f, 0.8824f);

    // Cloud 2
    drawCircle(40, 100, 700, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(50, 150, 720, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(45, 200, 700, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(35, 150, 680, 0.9059f, 0.9373f, 0.8824f);

    // Cloud 3
    drawCircle(30, -400, 700, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(20, -350, 720, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(15, -300, 700, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(10, -350, 680, 0.9059f, 0.9373f, 0.8824f);

     // Cloud 4
    drawCircle(40, 200, 500, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(50, 250, 520, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(45, 200, 500, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(35, 250, 480, 0.9059f, 0.9373f, 0.8824f);

     // Cloud 5
    drawCircle(50, -450, 500, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(55, -500, 520, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(45, -400, 500, 0.9059f, 0.9373f, 0.8824f);
    drawCircle(35, -450, 480, 0.9059f, 0.9373f, 0.8824f);
    glPopMatrix();
}

void drawVolcanoEruption() {
    if (!_volcano_erupting) return;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(-300, 533);

    glColor3ub(255, 215, 0);
    glVertex2f(-320, 580);
    glVertex2f(-280, 590);

    glColor3ub(255, 140, 0);
    glVertex2f(-260, 620);
    glVertex2f(-340, 620);

    glColor3ub(178, 34, 34);
    glVertex2f(-370, 650);
    glVertex2f(-230, 650);
    glEnd();


    glPointSize(4);
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; i++) {
        int px = -300 + (rand() % 120 - 60);
        int py = 540 + (rand() % 160);
        if (i % 3 == 0) glColor3ub(255, 69, 0);
        else if (i % 3 == 1) glColor3ub(255, 140, 0);
        else glColor3ub(255, 215, 0);
        glVertex2f(px, py);
    }
    glEnd();
}


void drawVolcano() {
    glBegin(GL_POLYGON);
    glColor3ub(105, 105, 105);
    glVertex2f(-459.16, -42.46);
    glVertex2f(-467.09, 152.57);
    glColor3ub(139, 137, 137);
    glVertex2f(-377.72, 454.90);
    // top left
    glVertex2f(-349.75, 533.14);
    // top right
    glVertex2f(-254.61, 533.14);
    glVertex2f(-111.89, -29.77);
    glEnd();

    drawVolcanoEruption();

    // // floating fire
    // glBegin(GL_POLYGON);
    // glColor3ub(255, 140, 0);
    // glVertex2f(-365.03, 438.04);
    // glVertex2f(-375.49, 482.23);
    // glColor3ub(178, 34, 34);
    // glVertex2f(-356.89, 541.53);
    // glVertex2f(-260.37, 546.76);
    // glColor3ub(255, 215, 0);
    // glVertex2f(-238.12, 509.83);
    // glVertex2f(-232.51, 483.18);
    // glColor3ub(255, 255, 255);
    // glVertex2f(-226.20, 445.31);
    // glEnd();
}

void drawHorseCart1() {
    // body
    glBegin(GL_QUADS);
    glColor3ub(79, 60, 34);
    glVertex2f(-577.88, -130.65);
    glVertex2f(-389.65, -130.65);
    glColor3ub(41, 30, 18);
    glVertex2f(-389.65, -187.56);
    glVertex2f(-577.27, -191.25);
    glEnd();

    for(int i = 1; i < 4; i++) {
        glColor3ub(212, 138, 138);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(-577.88, -130.65 - i*16);
        glVertex2f(-389.65, -130.65 - i*16);
        glEnd();
    }

    for(int i = 1; i < 10; i++) {
        glColor3ub(212, 138, 138);
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(-577.88 + i*20, -130.65);
        glVertex2f(-577.27 + i*20, -191.25);
        glEnd();
    }

    // wheels hanger
    glBegin(GL_QUADS);
    glColor3ub(79, 60, 34);
    glVertex2f(-557.54, -188.00);
    glVertex2f(-526.88, -188.49);
    glVertex2f(-537.74, -202.73);
    glVertex2f(-547.88, -202.73);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-420.04, -185.52);
    glVertex2f(-410.76, -184.19);
    glVertex2f(-411.72, -208.24);
    glVertex2f(-420.36, -208.56);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-538.80, -196.40);
    glVertex2f(-538.44, -200.20);
    glVertex2f(-417.29, -200.37);
    glVertex2f(-417.70, -196.83);
    glEnd();

    // horse tier
    glBegin(GL_QUADS);
    glVertex2f(-417.62, -172.71);
    glVertex2f(-417.36, -178.51);
    glVertex2f(-346.72, -175.07);
    glVertex2f(-347.08, -168.64);
    glEnd();


    // wheels
    // 1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-542.60, -200.38, 0);
    glRotatef(_horse_cart_angle, 0, 0, 1);
    glTranslatef(542.60, 200.38, 0);
    glLineWidth(4.0);
    glColor3ub(102, 96, 89);
    glBegin(GL_LINES);
    glVertex2f(-565.18, -182.31);
    glVertex2f(-542.60, -200.38);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-515.14, -193.28);
    glVertex2f(-542.60, -200.38);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-551.57, -228.64);
    glVertex2f(-542.60, -200.38);
    glEnd();

    glLineWidth(6.0);
    drawCircleOutlined(26, -542.60, -200.38, 0.400f, 0.376f, 0.349f);
    drawCircle(8, -542.60, -200.38, 0.400f, 0.376f, 0.349f);
    glPopMatrix();

    // 2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-416.26, -206.76, 0);
    glRotatef(_horse_cart_angle, 0, 0, 1);
    glTranslatef(416.26, 206.76, 0);
    glLineWidth(4.0);
    glColor3ub(102, 96, 89);
    glBegin(GL_LINES);
    glVertex2f(-435.67, -194.32);
    glVertex2f(-416.26, -206.76);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-397.02, -195.76);
    glVertex2f(-416.26, -206.76);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-415.57, -228.78);
    glVertex2f(-416.26, -206.76);
    glEnd();
    drawCircleOutlined(20, -416.26, -206.76, 0.400f, 0.376f, 0.349f);
    drawCircle(5, -416.26, -206.76, 0.400f, 0.376f, 0.349f);
    glPopMatrix();

    // horse
    // body
    glColor3ub(33, 33, 33);
    glBegin(GL_QUADS);
    glVertex2f(-350.36, -157.95);
    glVertex2f(-257.38, -159.47);
    glVertex2f(-256.24, -197.80);
    glVertex2f(-349.98, -197.80);
    glEnd();

    // legs
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    if(!stopAnimation) {
        glTranslatef(-300, -160, 0);
        glRotatef(10 * sin(glutGet(GLUT_ELAPSED_TIME) / 100.0), 0, 0, 1);
        glTranslatef(300, 160, 0);
    }
    glBegin(GL_QUADS);
    glVertex2f(-336.69, -192.48);
    glVertex2f(-325.69, -191.72);
    glVertex2f(-323.79, -231.95);
    glVertex2f(-335.93, -231.95);
    glEnd();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    if(!stopAnimation) {
        glTranslatef(-300, -160, 0);
        glRotatef(-10 * sin(glutGet(GLUT_ELAPSED_TIME) / 100.0), 0, 0, 1);
        glTranslatef(300, 160, 0);
    }
    glBegin(GL_QUADS);
    glVertex2f(-281.67, -192.87);
    glVertex2f(-269.52, -192.11);
    glVertex2f(-269.52, -231.96);
    glVertex2f(-281.67, -231.96);
    glEnd();
    glPopMatrix();

    // neck
    glBegin(GL_QUADS);
    glVertex2f(-264.20, -172.75);
    glVertex2f(-259.34, -186.10);
    glVertex2f(-218.96, -155.24);
    glVertex2f(-224.40, -147.08);
    glEnd();

    // head
    glBegin(GL_QUADS);
    glVertex2f(-229.62, -143.67);
    glVertex2f(-200.13, -143.45);
    glVertex2f(-200, -160);
    glVertex2f(-228.71, -164.32);
    glEnd();
}

void drawRoad() {
    glBegin(GL_QUADS);
    glColor3ub(160, 132, 84);
    glVertex2f(-600, -80.85);
    glVertex2f(600, -80.85);
    glColor3ub(176, 157, 123);
    glVertex2f(600, -250);
    glVertex2f(-600, -250);
    glEnd();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_horse_cart.x, _move_horse_cart.y, _move_horse_cart.z);
    drawHorseCart1();
    glPopMatrix();
}

void currentMode() {
    glBegin(GL_QUADS);
    if(isDay) glColor3ub(197, 225, 203);
    else glColor3ub(59, 59, 59);
    glVertex2f(-600, 800);
    glVertex2f(600, 800);
    if(isDay) glColor3ub(146, 218, 204);
    else glColor3ub(0, 0, 128);
    glVertex2f(600, -400);
    glVertex2f(-600, -400);
    glEnd();

    // grass
    glBegin(GL_QUADS);
    if(isDay) glColor3ub(34, 139, 34);
    else glColor3ub(0, 100, 0);
    glVertex2f(-598.68, -80.85);
    glVertex2f(598.01, -80.85);
    glVertex2f(600, 300);
    glVertex2f(-600, 300);
    glEnd();
}

void update(int value) {
    if(!stopAnimation) {
        _move_cloud.x += _speed;
        if(_move_cloud.x > 800) {
            _move_cloud.x = -800.0f;
        }

        _window_mill_angle -= _speed;
        if(_window_mill_angle < 0 || _window_mill_angle > 360) {
            _window_mill_angle += 360;
        }


        _move_horse_cart.x += _speed;
        if(_move_horse_cart.x > 800) {
            _move_horse_cart.x = 0.0f;
        }else if(_move_horse_cart.x < -400) {
            _move_horse_cart.x = 800.0f;
        }

        _horse_cart_angle -= _speed;
        if(_horse_cart_angle < 0 || _horse_cart_angle > 360) {
            _horse_cart_angle += 360;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void volcanoEruptionTimer(int value) {
    _volcano_erupting = false;
    glutPostRedisplay();
    glutTimerFunc(5000, volcanoEruptionTimer, 0);
}

void keyboardHandler(unsigned char key, int x, int y) {
    if(key == 'n' || key == 'N') {
        isDay = false;
    } else if(key == 'd' || key == 'D') {
        isDay = true;
    } else if(key == 's' || key == 'S') {
        stopAnimation = !stopAnimation;
    } else if(key == 'e' || key == 'E') {
        _speed -= 0.5f;
    } else if (key == 'r' || key == 'R') {
        _speed += 0.5f;
    }

     glutPostRedisplay();
}

void mouseHandler(int button, int state, int x, int y) {
    if(stopAnimation) return;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
          _volcano_erupting = !_volcano_erupting;
    }
}

void mouseMotionHandler(int x, int y) {
    float glX = (x / 1200.0f) * 1200 - 600; 
    float glY = 400 - (y / 800.0f) * 800; 


    if (glX >= -600 && glX <= 600 && glY >= -600 && glY <= -250) {
        if(_prev_mouse_pos.x > glX) {
            _move_boat.x -= _prev_mouse_pos.x - glX;
             if(_move_boat.x < -600) {
                _move_boat.x = 600.0f;
            }
        } else if(_prev_mouse_pos.x < glX) {
            _move_boat.x += glX - _prev_mouse_pos.x;
             if(_move_boat.x > 600) {
                _move_boat.x = -600.0f;
            }
        }

        if(_prev_mouse_pos.y > glY) {
            _move_boat.y -= _prev_mouse_pos.y - glY;
             if(_move_boat.y < -100) {
                _move_boat.y = 0.0f;
            }
        } else if(_prev_mouse_pos.y < glY) {
            _move_boat.y += glY - _prev_mouse_pos.y;
             if(_move_boat.y > 100) {
                _move_boat.y = 0.0f;
            }
        }
        

        glutPostRedisplay();
    }

    _prev_mouse_pos = {glX, glY, 0.0f};
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
    currentMode();
    drawSunAndClouds();

    drawRoad();
    drawCanal();

    drawHill();
    drawVolcano();

    drawWindMill1();

    drawTrees();

    drawHouse1();
    drawHouse2();
    drawHouse3();
    drawHouse4();
	glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -600, 800);

    cout << "Instructions to interact with the scene:\n";
    cout << "1. Press 'D' to switch to Day mode.\n";
    cout << "2. Press 'N' to switch to Night mode.\n";
    cout << "3. Press 'S' to Start/Stop the animation.\n";
    cout << "4. Press 'E' to decrease the speed of moving objects.\n";
    cout << "5. Press 'R' to increase the speed of moving objects.\n";
    cout << "6. Click the left mouse button on the volcano to toggle eruption.\n";
    cout << "7. Move the mouse cursor over the canal area to move the boats.\n";
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200, 800);   // Set the window's initial width & height
    glutCreateWindow("Scene 1"); // Create a window with the given title
	init();
	glutDisplayFunc(display); // Register display callback handler for window re-paint

    glutTimerFunc(25, update, 0);
    glutTimerFunc(5000, volcanoEruptionTimer, 0);

    glutKeyboardFunc(keyboardHandler);
    glutMouseFunc(mouseHandler);
    glutPassiveMotionFunc(mouseMotionHandler);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
