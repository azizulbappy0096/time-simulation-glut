#include <windows.h>
#include <GL/glut.h>
#include <math.h>

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

bool isDay = true;
bool _volcano_erupting = false;
float _window_mill_angle = 0.0f;

float _currentOffset = 0.0f;


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
    glVertex2f(-500, -200);
    glVertex2f(-300, -200);
    glColor3ub(160, 82, 45);
    glVertex2f(-340.71, -249.27);
    glVertex2f(-462.12, -249.27);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(205, 133, 63);
    glVertex2f(-449.03, -178.75);
    glVertex2f(-348.71, -179.48);
    glColor3ub(222, 184, 135);
    glVertex2f(-350,-200);
    glVertex2f(-450, -200);
    glEnd();
}


void drawCurrent() {
    glLineWidth(2.0);
    glColor3ub(200, 255, 255);


    glBegin(GL_LINES);
    for (float x = -600; x < 600; x += 50) {
        glVertex2f(x + _currentOffset, -100);
        glVertex2f(x + 30 + _currentOffset, -600);
    }
    glEnd();

    _currentOffset += 0.5f;
    if (_currentOffset > 50) _currentOffset = 0;
}
void drawCanal() {
    glBegin(GL_QUADS);
    glColor3ub(0, 119, 190);
    glVertex2f(-600, -100);
    glVertex2f(600, -100);
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
    glVertex2f(-598.68, -80.55);
    glVertex2f(598.01, -80.62);
    glVertex2f(600, 300);
    glVertex2f(-600, 300);
    glEnd();
}

void update(int value) {
    _move_cloud.x += 1.0f;
    if(_move_cloud.x > 800) {
        _move_cloud.x = -800.0f;
    }
    _move_boat.x += 0.5f;
    if(_move_boat.x > 800) {
        _move_boat.x = -800.0f;
    }

    _window_mill_angle -= 0.5f;
    if(_window_mill_angle < 0) {
        _window_mill_angle += 360;
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
    if (key == 'a' || key == 'A') {
        _volcano_erupting = !_volcano_erupting;
    }else if(key == 'n' || key == 'N') {
        isDay = false;
    } else if(key == 'd' || key == 'D') {
        isDay = true;

    }

     glutPostRedisplay();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
    currentMode();
    drawSunAndClouds();
    drawHill();
    drawVolcano();

    drawWindMill1();

    drawTrees();

    drawHouse1();
    drawHouse2();
    drawHouse3();
    drawHouse4();

    drawCanal();
	glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -400, 800);
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

    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
