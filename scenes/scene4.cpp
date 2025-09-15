#include <windows.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

void building1Scene4() {
    glColor3ub(120, 120, 120);
    glBegin(GL_POLYGON);
        glVertex2f(-8.00f, 0.00f);
        glVertex2f(-8.00f, 4.00f);
        glVertex2f(-6.00f, 6.00f);
        glVertex2f(-6.00f, 0.00f);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-8.00f, 0.00f);
        glVertex2f(-8.00f, 4.00f);
        glVertex2f(-6.00f, 6.00f);
        glVertex2f(-6.00f, 0.00f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-7.7f, 0.7f);
        glVertex2f(-7.7f, 1.7f);
        glVertex2f(-7.2f, 1.7f);
        glVertex2f(-7.2f, 0.7f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-7.7f, 0.7f);
        glVertex2f(-7.7f, 1.7f);
        glVertex2f(-7.2f, 1.7f);
        glVertex2f(-7.2f, 0.7f);
    glEnd();
    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-7.6f, 2.2f);
        glVertex2f(-7.6f, 3.2f);
        glVertex2f(-7.1f, 3.2f);
        glVertex2f(-7.1f, 2.2f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-7.6f, 2.2f);
        glVertex2f(-7.6f, 3.2f);
        glVertex2f(-7.1f, 3.2f);
        glVertex2f(-7.1f, 2.2f);
    glEnd();
}

void building2Scene4() {
    glColor3ub(150, 120, 120);
    glBegin(GL_POLYGON);
        glVertex2f(-12.00f, 0.00f);
        glVertex2f(-12.00f, 10.00f);
        glVertex2f(-10.00f, 10.00f);
        glVertex2f(-10.00f, 6.00f);
        glVertex2f(-10.57f, 4.03f);
        glVertex2f(-10.17f, 3.04f);
        glVertex2f(-10.00f, 0.00f);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-12.00f, 0.00f);
        glVertex2f(-12.00f, 10.00f);
        glVertex2f(-10.00f, 10.00f);
        glVertex2f(-10.00f, 6.00f);
        glVertex2f(-10.57f, 4.03f);
        glVertex2f(-10.17f, 3.04f);
        glVertex2f(-10.00f, 0.00f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-11.8f, 1.0f);
        glVertex2f(-11.8f, 2.0f);
        glVertex2f(-11.3f, 2.0f);
        glVertex2f(-11.3f, 1.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-11.8f, 1.0f);
        glVertex2f(-11.8f, 2.0f);
        glVertex2f(-11.3f, 2.0f);
        glVertex2f(-11.3f, 1.0f);
    glEnd();
    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-11.2f, 1.0f);
        glVertex2f(-11.2f, 2.0f);
        glVertex2f(-10.7f, 2.0f);
        glVertex2f(-10.7f, 1.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-11.2f, 1.0f);
        glVertex2f(-11.2f, 2.0f);
        glVertex2f(-10.7f, 2.0f);
        glVertex2f(-10.7f, 1.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-11.8f, 3.5f);
        glVertex2f(-11.8f, 4.5f);
        glVertex2f(-11.3f, 4.5f);
        glVertex2f(-11.3f, 3.5f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-11.8f, 3.5f);
        glVertex2f(-11.8f, 4.5f);
        glVertex2f(-11.3f, 4.5f);
        glVertex2f(-11.3f, 3.5f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-11.2f, 3.5f);
        glVertex2f(-11.2f, 4.5f);
        glVertex2f(-10.7f, 4.5f);
        glVertex2f(-10.7f, 3.5f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-11.2f, 3.5f);
        glVertex2f(-11.2f, 4.5f);
        glVertex2f(-10.7f, 4.5f);
        glVertex2f(-10.7f, 3.5f);
    glEnd();
}

void building3Scene4() {
    glColor3ub(100, 100, 150);
    glBegin(GL_POLYGON);
        glVertex2f(-4.00f, 0.00f);
        glVertex2f(-4.00f, 14.00f);
        glVertex2f(-2.49f, 13.06f);
        glVertex2f(-2.08f, 10.81f);
        glVertex2f(-1.81f, 7.62f);
        glVertex2f(-2.00f, 0.00f);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-4.00f, 0.00f);
        glVertex2f(-4.00f, 14.00f);
        glVertex2f(-2.49f, 13.06f);
        glVertex2f(-2.08f, 10.81f);
        glVertex2f(-1.81f, 7.62f);
        glVertex2f(-2.00f, 0.00f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-3.8f, 1.0f);
        glVertex2f(-3.8f, 2.0f);
        glVertex2f(-3.3f, 2.0f);
        glVertex2f(-3.3f, 1.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-3.8f, 1.0f);
        glVertex2f(-3.8f, 2.0f);
        glVertex2f(-3.3f, 2.0f);
        glVertex2f(-3.3f, 1.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-3.8f, 3.0f);
        glVertex2f(-3.8f, 4.0f);
        glVertex2f(-3.3f, 4.0f);
        glVertex2f(-3.3f, 3.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-3.8f, 3.0f);
        glVertex2f(-3.8f, 4.0f);
        glVertex2f(-3.3f, 4.0f);
        glVertex2f(-3.3f, 3.0f);
    glEnd();
    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-3.8f, 5.0f);
        glVertex2f(-3.8f, 6.0f);
        glVertex2f(-3.3f, 6.0f);
        glVertex2f(-3.3f, 5.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-3.8f, 5.0f);
        glVertex2f(-3.8f, 6.0f);
        glVertex2f(-3.3f, 6.0f);
        glVertex2f(-3.3f, 5.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-3.8f, 7.0f);
        glVertex2f(-3.8f, 8.0f);
        glVertex2f(-3.3f, 8.0f);
        glVertex2f(-3.3f, 7.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-3.8f, 7.0f);
        glVertex2f(-3.8f, 8.0f);
        glVertex2f(-3.3f, 8.0f);
        glVertex2f(-3.3f, 7.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(-3.8f, 9.0f);
        glVertex2f(-3.8f, 10.0f);
        glVertex2f(-3.3f, 10.0f);
        glVertex2f(-3.3f, 9.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-3.8f, 9.0f);
        glVertex2f(-3.8f, 10.0f);
        glVertex2f(-3.3f, 10.0f);
        glVertex2f(-3.3f, 9.0f);
    glEnd();
}

void building4Scene4() {
    glColor3ub(180, 120, 90);
    glBegin(GL_POLYGON);
        glVertex2f(2.0f, 0.0f);
        glVertex2f(2.0f, 12.0f);
        glVertex2f(3.5f, 11.0f);
        glVertex2f(4.0f, 9.0f);
        glVertex2f(4.0f, 5.0f);
        glVertex2f(4.0f, 0.0f);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(2.00f, 0.00f);
        glVertex2f(2.00f, 12.00f);
        glVertex2f(3.50f, 11.00f);
        glVertex2f(4.00f, 9.00f);
        glVertex2f(4.00f, 5.00f);
        glVertex2f(4.00f, 0.00f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(2.2f, 1.0f);
        glVertex2f(2.2f, 2.0f);
        glVertex2f(2.6f, 2.0f);
        glVertex2f(2.6f, 1.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(2.2f, 1.0f);
        glVertex2f(2.2f, 2.0f);
        glVertex2f(2.6f, 2.0f);
        glVertex2f(2.6f, 1.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(3.0f, 1.0f);
        glVertex2f(3.0f, 2.0f);
        glVertex2f(3.4f, 2.0f);
        glVertex2f(3.4f, 1.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.0f, 1.0f);
        glVertex2f(3.0f, 2.0f);
        glVertex2f(3.4f, 2.0f);
        glVertex2f(3.4f, 1.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(2.2f, 3.0f);
        glVertex2f(2.2f, 4.0f);
        glVertex2f(2.6f, 4.0f);
        glVertex2f(2.6f, 3.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(2.2f, 3.0f);
        glVertex2f(2.2f, 4.0f);
        glVertex2f(2.6f, 4.0f);
        glVertex2f(2.6f, 3.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(3.0f, 3.0f);
        glVertex2f(3.0f, 4.0f);
        glVertex2f(3.4f, 4.0f);
        glVertex2f(3.4f, 3.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.0f, 3.0f);
        glVertex2f(3.0f, 4.0f);
        glVertex2f(3.4f, 4.0f);
        glVertex2f(3.4f, 3.0f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(2.2f, 5.5f);
        glVertex2f(2.2f, 6.5f);
        glVertex2f(2.6f, 6.5f);
        glVertex2f(2.6f, 5.5f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(2.2f, 5.5f);
        glVertex2f(2.2f, 6.5f);
        glVertex2f(2.6f, 6.5f);
        glVertex2f(2.6f, 5.5f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(3.0f, 5.5f);
        glVertex2f(3.0f, 6.5f);
        glVertex2f(3.4f, 6.5f);
        glVertex2f(3.4f, 5.5f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.0f, 5.5f);
        glVertex2f(3.0f, 6.5f);
        glVertex2f(3.4f, 6.5f);
        glVertex2f(3.4f, 5.5f);
    glEnd();
}

void building5Scene4() {
    glColor3ub(120, 150, 120);
    glBegin(GL_POLYGON);
        glVertex2f(6.00f, 0.00f);
        glVertex2f(6.00f, 8.00f);
        glVertex2f(7.00f, 7.00f);
        glVertex2f(8.00f, 6.00f);
        glVertex2f(8.00f, 0.00f);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.00f, 0.00f);
        glVertex2f(6.00f, 8.00f);
        glVertex2f(7.00f, 7.00f);
        glVertex2f(8.00f, 6.00f);
        glVertex2f(8.00f, 0.00f);
    glEnd();

    glColor3ub(200, 220, 255);
    glBegin(GL_QUADS);
        glVertex2f(6.2f, 1.0f);
        glVertex2f(6.2f, 2.0f);
        glVertex2f(6.6f, 2.0f);
        glVertex2f(6.6f, 1.0f);

        glVertex2f(6.8f, 2.2f);
        glVertex2f(6.8f, 3.2f);
        glVertex2f(7.2f, 3.2f);
        glVertex2f(7.2f, 2.2f);

        glVertex2f(7.4f, 3.5f);
        glVertex2f(7.4f, 4.5f);
        glVertex2f(7.8f, 4.5f);
        glVertex2f(7.8f, 3.5f);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.2f, 1.0f);
        glVertex2f(6.2f, 2.0f);
        glVertex2f(6.6f, 2.0f);
        glVertex2f(6.6f, 1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(6.8f, 2.2f);
        glVertex2f(6.8f, 3.2f);
        glVertex2f(7.2f, 3.2f);
        glVertex2f(7.2f, 2.2f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(7.4f, 3.5f);
        glVertex2f(7.4f, 4.5f);
        glVertex2f(7.8f, 4.5f);
        glVertex2f(7.8f, 3.5f);
    glEnd();
}

void building6Scene4() {
    glColor3ub(200, 100, 100);
    glBegin(GL_POLYGON);
        glVertex2f(10.00f, 0.00f);
        glVertex2f(10.00f, 6.00f);
        glVertex2f(11.50f, 5.00f);
        glVertex2f(12.00f, 3.00f);
        glVertex2f(12.00f, 0.00f);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(10.00f, 0.00f);
        glVertex2f(10.00f, 6.00f);
        glVertex2f(11.50f, 5.00f);
        glVertex2f(12.00f, 3.00f);
        glVertex2f(12.00f, 0.00f);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(10.2f, 1.0f);
        glVertex2f(10.2f, 2.0f);
        glVertex2f(10.6f, 2.0f);
        glVertex2f(10.6f, 1.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(10.2f, 1.0f);
        glVertex2f(10.2f, 2.0f);
        glVertex2f(10.6f, 2.0f);
        glVertex2f(10.6f, 1.0f);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
        glVertex2f(10.8f, 2.2f);
        glVertex2f(10.8f, 3.2f);
        glVertex2f(11.2f, 3.2f);
        glVertex2f(11.2f, 2.2f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(10.8f, 2.2f);
        glVertex2f(10.8f, 3.2f);
        glVertex2f(11.2f, 3.2f);
        glVertex2f(11.2f, 2.2f);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
        glVertex2f(11.0f, 3.5f);
        glVertex2f(11.0f, 4.5f);
        glVertex2f(11.4f, 4.5f);
        glVertex2f(11.4f, 3.5f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(11.0f, 3.5f);
        glVertex2f(11.0f, 4.5f);
        glVertex2f(11.4f, 4.5f);
        glVertex2f(11.4f, 3.5f);
    glEnd();
}

void moonScene4(float x, float y, float radius, int r, int g, int b) {
    glColor3ub(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.1416 / 180;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

void brokenHighwayScene4() {
    glColor3ub(60, 60, 60);
    glBegin(GL_QUADS);
        glVertex2f(-15, -1);
        glVertex2f(-7, -1);
        glVertex2f(-7, -3);
        glVertex2f(-15, -3);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-5, -1);
        glVertex2f(2, -1);
        glVertex2f(2, -3);
        glVertex2f(-5, -3);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(4, -1);
        glVertex2f(15, -1);
        glVertex2f(15, -3);
        glVertex2f(4, -3);
    glEnd();
    glColor3ub(255, 255, 0);

    glBegin(GL_QUADS);
        glVertex2f(-14, -1.9);
        glVertex2f(-13, -1.9);
        glVertex2f(-13, -2.1);
        glVertex2f(-14, -2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-11, -1.9);
        glVertex2f(-10, -1.9);
        glVertex2f(-10, -2.1);
        glVertex2f(-11, -2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-4, -1.9);
        glVertex2f(-3, -1.9);
        glVertex2f(-3, -2.1);
        glVertex2f(-4, -2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-1, -1.9);
        glVertex2f(0, -1.9);
        glVertex2f(0, -2.1);
        glVertex2f(-1, -2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(5, -1.9);
        glVertex2f(6, -1.9);
        glVertex2f(6, -2.1);
        glVertex2f(5, -2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(8, -1.9);
        glVertex2f(9, -1.9);
        glVertex2f(9, -2.1);
        glVertex2f(8, -2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(11, -1.9);
        glVertex2f(12, -1.9);
        glVertex2f(12, -2.1);
        glVertex2f(11, -2.1);
    glEnd();
}

void backgroundScene4() {
    glBegin(GL_QUADS);
        glColor3ub(255, 180, 50);
         glVertex2f(-15, 15);
        glColor3ub(255, 180, 50);
          glVertex2f( 15, 15);
        glColor3ub(255, 100, 0);
         glVertex2f( 15,  0);
        glColor3ub(255, 100, 0);
         glVertex2f(-15,  0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(210, 190, 140);
         glVertex2f(-15, 0);
        glColor3ub(210, 190, 140);
         glVertex2f( 15, 0);
        glColor3ub(160, 140, 100);
        glVertex2f( 15, -5);
        glColor3ub(160, 140, 100);
         glVertex2f(-15, -5);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(-15, 0);
        glVertex2f( 15, 0);
    glEnd();
}
void nightBackgroundScene4() {
    glBegin(GL_QUADS);
        glColor3ub(20, 20, 70);
        glVertex2f(-15, 15);
        glVertex2f( 15, 15);
        glColor3ub(10, 10, 40);
        glVertex2f( 15, 0);
        glVertex2f(-15, 0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(80, 70, 50);
        glVertex2f(-15, 0);
        glVertex2f( 15, 0);
        glColor3ub(40, 30, 20);
        glVertex2f( 15, -5);
        glVertex2f(-15, -5);
    glEnd();

    glColor3ub(255, 255, 255);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-15, 0);
        glVertex2f( 15, 0);
    glEnd();
}

void TreeScene4(float x, float y) {
    glColor3f(0.6f, 0.3f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(x - 0.2f, y);
        glVertex2f(x + 0.2f, y);
        glVertex2f(x + 0.2f, y + 1.2f);
        glVertex2f(x - 0.2f, y + 1.2f);
    glEnd();

    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 1.0f, y + 1.2f);
        glVertex2f(x + 1.0f, y + 1.2f);
        glVertex2f(x, y + 2.5f);

        glVertex2f(x - 0.8f, y + 2.0f);
        glVertex2f(x + 0.8f, y + 2.0f);
        glVertex2f(x, y + 3.5f);
        glVertex2f(x - 0.6f, y + 3.0f);
        glVertex2f(x + 0.6f, y + 3.0f);
        glVertex2f(x, y + 4.2f);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - 0.2f, y);
        glVertex2f(x + 0.2f, y);
        glVertex2f(x + 0.2f, y + 1.2f);
        glVertex2f(x - 0.2f, y + 1.2f);
    glEnd();
}

void lampPostScene4(float x, float y) {
    glColor3ub(80, 80, 80);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 0.2f, y);
        glVertex2f(x + 0.2f, y + 3.0f);
        glVertex2f(x, y + 3.0f);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + 0.2f, y);
        glVertex2f(x + 0.2f, y + 3.0f);
        glVertex2f(x, y + 3.0f);
    glEnd();

    glColor3ub(200, 200, 100);
    glBegin(GL_POLYGON);
        glVertex2f(x - 0.1f, y + 2.5f);
        glVertex2f(x + 0.1f, y + 2.5f);
        glVertex2f(x + 0.1f, y + 2.2f);
        glVertex2f(x - 0.1f, y + 2.2f);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - 0.1f, y + 2.5f);
        glVertex2f(x + 0.1f, y + 2.5f);
        glVertex2f(x + 0.1f, y + 2.2f);
        glVertex2f(x - 0.1f, y + 2.2f);
    glEnd();
}
float satelliteX1Scene4 = -15;
float satelliteX2Scene4 = 15;
float satelliteX3Scene4 = -10;
float satelliteX4Scene4 = 10;
float satelliteX5Scene4 = 1;
void drawSatelliteScene4(float x, float y) {
    glColor3ub(200, 200, 200);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 0.8, y);
        glVertex2f(x + 0.8, y - 0.5);
        glVertex2f(x, y - 0.5);
    glEnd();

    glColor3ub(150, 150, 150);
    glBegin(GL_POLYGON);
        glVertex2f(x - 0.4, y);
        glVertex2f(x, y);
        glVertex2f(x, y - 0.5);
        glVertex2f(x - 0.4, y - 0.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(x + 0.8, y);
        glVertex2f(x + 1.2, y);
        glVertex2f(x + 1.2, y - 0.5);
        glVertex2f(x + 0.8, y - 0.5);
    glEnd();
}
void timerScene4(int value) {
    satelliteX1Scene4 += 0.05f;
    satelliteX2Scene4 -= 0.05f;

    if (satelliteX1Scene4 > 15) satelliteX1Scene4 = -15;
    if (satelliteX2Scene4 < -15) satelliteX2Scene4 = 15;

    satelliteX3Scene4 += 0.03f;
    if (satelliteX3Scene4 > 15) satelliteX3Scene4 = -15;

    satelliteX4Scene4 -= 0.04f;
    if (satelliteX4Scene4 < -15) satelliteX4Scene4 = 15;

    satelliteX5Scene4 += 0.02f;
    if (satelliteX5Scene4 > 15) satelliteX5Scene4 = -15;

    glutPostRedisplay();
    glutTimerFunc(20, timerScene4, 0);
}

void circleScene4(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float angle = 2 * 3.1416 * i / 200;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glColor3f(r, g, b);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void drawMoonScene4() {
    float moonX = 10.0f;
    float moonY = 12.0f;
    float radius = 2.0f;
    glColor3ub(255, 255, 200);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 200;
        float x = radius * cos(angle) + moonX;
        float y = radius * sin(angle) + moonY;
        glVertex2f(x, y);
    }
    glEnd();

    glColor3ub(200, 200, 150);
    float craterRadius = 0.3f;

    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 100;
        float x = craterRadius * cos(angle) + (moonX + 0.5f);
        float y = craterRadius * sin(angle) + (moonY + 0.5f);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 100;
        float x = craterRadius * cos(angle) + (moonX - 0.7f);
        float y = craterRadius * sin(angle) + (moonY - 0.3f);
        glVertex2f(x, y);
    }
    glEnd();
}

void StarsScene4() {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2f(-14, 13);
        glVertex2f(-12, 12);
        glVertex2f(-10, 14);
        glVertex2f(12, 13);
        glVertex2f(14, 12);
        glVertex2f(8, 14);
        glVertex2f(-5, 8);
        glVertex2f(0, 9);
        glVertex2f(5, 8);
    glEnd();
}

void satellitesScene4() {
    drawSatelliteScene4(satelliteX1Scene4, 13.0f);
    drawSatelliteScene4(satelliteX2Scene4, 11.0f);
    drawSatelliteScene4(satelliteX3Scene4, 14.0f);
    drawSatelliteScene4(satelliteX4Scene4, 12.0f);
    drawSatelliteScene4(satelliteX5Scene4, 15.0f);
}

float rocketYScene4 = 0.0f;
bool launchScene4 = false;
void drawRocketScene4(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    glColor3ub(200, 200, 200);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(0.6f, 2.5f);
        glVertex2f(-0.6f, 2.5f);
    glEnd();

    glColor3ub(220, 50, 50);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6f, 2.5f);
        glVertex2f(0.6f, 2.5f);
        glVertex2f(0.0f, 3.5f);
    glEnd();
    glColor3ub(50, 50, 220);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6f, 1.0f);
        glVertex2f(-1.2f, 0.3f);
        glVertex2f(-0.6f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.6f, 1.0f);
        glVertex2f(1.2f, 0.3f);
        glVertex2f(0.6f, 0.0f);
    glEnd();
    if (launchScene4) {
        glColor3ub(255, 150, 0);
        glBegin(GL_TRIANGLES);
            glVertex2f(-0.4f, 0.0f);
            glVertex2f(0.4f, 0.0f);
            glVertex2f(0.0f, -1.0f);
        glEnd();
    }

    glPopMatrix();
}

bool isDayScene4 = true;
void handleKeypressScene4(unsigned char key, int x, int y) {
    switch (key) {
        case 'n':
        case 'N':
            isDayScene4 = !isDayScene4;
            glutPostRedisplay();
            break;
    }
}

float carMoveScene4 = -15.0f;
float carAngleScene4 = 0.0f;
void drawWheelScene4(float cx, float cy, float radius, float angle, bool broken = false) {
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glRotatef(angle, 0, 0, 1);

    if (broken) glScalef(1.2f, 0.6f, 1.0f);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float theta = (2 * 3.1416 * i) / 200;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glColor3f(0.1, 0.1, 0.1);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();
}

void drawBrokenCarScene4() {
    glPushMatrix();
    glTranslatef(carMoveScene4, -2.5f, 0);
    glScalef(3.0f, 2.0f, 1.0f);
    glColor3ub(120, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(2.0f, 0.2f);
        glVertex2f(2.0f, 1.0f);
        glVertex2f(0.0f, 0.8f);
    glEnd();

    drawWheelScene4(0.5f, 0.0f, 0.25f, carAngleScene4);
    drawWheelScene4(1.6f, 0.0f, 0.25f, carAngleScene4, true);
    glPopMatrix();
}

void CarScene4(int value) {
    carMoveScene4 += 0.05f;
    if (carMoveScene4 > 15.0f) {
        carMoveScene4 = -15.0f;
    }

    carAngleScene4 -= 5.0f;
    if (carAngleScene4 < 0.0f) carAngleScene4 += 360.0f;

    glutPostRedisplay();
    glutTimerFunc(50, CarScene4, 0);
}
void idleScene4() {
    if (launchScene4) {
        rocketYScene4 += 0.0009f;
        if (rocketYScene4 > 25.0f) {
            rocketYScene4 = 0.0f;
            launchScene4 = false;
        }
        glutPostRedisplay();
    }
}

void mouseScene4(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        launchScene4 = true;
    }
}

void displayScene4() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -5, 15);

    glClear(GL_COLOR_BUFFER_BIT);

    if (isDayScene4) {
        backgroundScene4();
        moonScene4(5, 13, 1.5, 200, 200, 220);
    } else {
        nightBackgroundScene4();
        drawMoonScene4();
        moonScene4(-10, 15, 2, 240, 240, 240);
        StarsScene4();
    }

    building1Scene4();
    building2Scene4();
    building3Scene4();
    building4Scene4();
    building5Scene4();
    building6Scene4();
    brokenHighwayScene4();
    lampPostScene4(-8.8f, 0.0f);
    lampPostScene4(8.5f, 0.0f);

    TreeScene4(14.0f, 0.0f);
    TreeScene4(-14.0f, 0.0f);
    drawBrokenCarScene4();

    drawRocketScene4(0.0f, rocketYScene4);

    satellitesScene4();
    
    glutSwapBuffers();
}

void initScene4() {
    glutReshapeWindow(800, 600);
    glutSetWindowTitle("Scene 4: Post-Apocalyptic");
}

/*
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Post-Apocalyptic Scene");
    gluOrtho2D(-15, 15, -5, 15);
    glutDisplayFunc(displayScene4);
    glutTimerFunc(20, timerScene4, 0);
    glutTimerFunc(10, CarScene4, 0);
    glutIdleFunc(idleScene4);
    glutMouseFunc(mouseScene4);
    glutKeyboardFunc(handleKeypressScene4);
    glutMainLoop();
    return 0;
}
*/