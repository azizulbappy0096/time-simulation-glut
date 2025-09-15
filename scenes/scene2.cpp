#include <windows.h>
#include <GL/glut.h>
#include<math.h>
#include <cmath>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#define PI 3.14159265358979323846

bool isSoundOn = false;
bool showInstructions = true;
int toggle = 0;
int trigger = 0;
GLfloat speed = 0.01f;
GLfloat speed1 = 0.01f;
GLfloat busX = -1.2f;
GLfloat busX1 = -1.5f;
GLfloat trainX = -1.2f;
GLfloat busSpeed = 0.005f;
GLfloat busSpeed1 = 0.008f;
GLfloat trainSpeed = 0.018f;
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat cloudOffset = 0.0f;


void drawText(GLfloat x, GLfloat y, const char* text) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *text);
        text++;
    }
}

void showInstructionScreen() {
    glColor3f(0.0f, 0.0f, 0.0f); // Black text

    // Title block (centered and larger)
    drawText(-0.25f, 0.8f, "MODERN CITY");
    drawText(-0.25f, 0.72f, "--------------------------------");
    drawText(-0.25f, 0.66f, "WINDOW: 2");
    drawText(-0.25f, 0.60f, "NAME: AHANAF TAHMID");
    drawText(-0.25f, 0.54f, "ID: 21-45447-3 | SL:01");
    drawText(-0.25f, 0.48f, "--------------------------------");

    // Section header
    drawText(-0.25f, 0.40f, "CONTROLS INSTRUCTIONS");

    // Instruction blocks with better alignment
    // Train controls
    drawText(-0.25f, 0.32f, "1. TRAIN SPEED CONTROL:");
    drawText(-0.23f, 0.27f, "W Key      Increase");
    drawText(-0.23f, 0.22f, "Q Key      Decrease");

    // Bus controls
    drawText(-0.25f, 0.14f, "2. BUS SPEED CONTROL:");
    drawText(-0.23f, 0.09f, "'<' Left Arrow      Decrease");
    drawText(-0.23f, 0.04f, "'>'Right Arrow     Increase");

    // Background toggle
    drawText(-0.25f, -0.04f, "3. BACKGROUND TOGGLE:");
    drawText(-0.23f, -0.09f, "Left Mouse Click    Day/Afternoon");

    // Menu toggle
    drawText(-0.25f, -0.17f, "4. INSTRUCTION MENU:");
    drawText(-0.23f, -0.22f, "Enter Key       Show/Hide");

    // Sound control
    drawText(-0.25f, -0.30f, "5. SOUND CONTROL:");
    drawText(-0.23f, -0.35f, "S Key           Sound On/Off");

    // Footer
    drawText(-0.25f, -0.45f, "--------------------------------");
    drawText(-0.25f, -0.55f, "PRESS ENTER TO BEGIN");
}
void afterNoonView()
{
    glColor3f(141.0f / 255.0f, 102.0f / 255.0f, 156.0f / 255.0f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glColor3f(240.0f / 255.0f, 146.0f / 255.0f, 121.0f / 255.0f);

    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glEnd();
    glFlush();
}


void handleMouseScene2(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        toggle = 1 - toggle;   // Flip between 0 and 1
        trigger = 1;         // Set flag to trigger tr() in display
        glutPostRedisplay(); // Request display update
    }
}
void updateScene2(int value) {
    busX += busSpeed;
    if (busX > 1.5f) {
        busX = -1.5f; // Reset when off-screen
    }

    busX1 += speed1;
    if (busX1 > 1.5f) {
        busX1 = -1.5f; // Reset when off-screen
    }

    trainX += speed;
    if (trainX > 2.5f) {
        trainX = -1.8f; // Reset when off-screen
    }

    glutPostRedisplay();           // Refresh display
    glutTimerFunc(16, updateScene2, 0);  // ~60 FPS
}

void drawWheels(float cx, float cy, float radius, int segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);                // centre
    for (int i = 0; i <= segments; ++i)
    {
        float ang = 2.0f * 3.1415926f * i / segments;
        glVertex2f(cx + radius * cosf(ang),
                   cy + radius * sinf(ang));
    }
    glEnd();
}




void keyboardScene2(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':  // Increase speed
        case 'W':
            speed += 0.002f;
            break;
        case 'q':  // Decrease speed
        case 'Q':
            speed -= 0.002f;
            if (speed < 0.0f) speed = 0.0f;  // Prevent negative speed
            break;
    }

    if (key == 13) { // ENTER key
        showInstructions = !showInstructions;
        glutPostRedisplay();
    }
        switch (key) {
        case 's':
        case 'S':
            if (!isSoundOn) {
                PlaySound("train_V3.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                isSoundOn = true;
            } else {
                PlaySound(NULL, 0, 0);  // Stop the sound
                isSoundOn = false;
            }
            break;

    }
}

void drawSeaWithFullWaves() {
    float startX = -1.2f;
    float endX = 1.3f;
    float baseYTop = -0.64f;
    float baseYBottom = -1.3f;
    float amplitudeTop = 0.025f;
    float amplitudeBottom = 0.015f;
    float frequency = 25.0f;
    float step = 0.01f;

    glBegin(GL_QUAD_STRIP);
    for (float x = startX; x <= endX; x += step) {
        // Top wave
        float yTop = baseYTop + amplitudeTop * sinf(frequency * x);

        // Bottom wave (inverse or random phase)
        float yBottom = baseYBottom + amplitudeBottom * sinf(frequency * x + 1.5f);

        glColor3f(16.0f / 255.0f, 118.0f / 255.0f, 171.0f / 255.0f); // Top color
        glVertex2f(x, yTop);

        glColor3f(28.0f / 255.0f, 46.0f / 255.0f, 72.0f / 255.0f);   // Bottom darker
        glVertex2f(x, yBottom);
    }
    glEnd();
}

void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    const int segments = 64; // Higher quality circle
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2 * M_PI * i / segments;
        glVertex2f(cx + radius * cosf(angle), cy + radius * sinf(angle));
    }
    glEnd();
}

void train()
{
    glColor3f(33.0f / 255.0f, 101.0f / 255.0f, 205.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.1350034997893, -0.1709128737848);
    glVertex2f(-0.663653875868, -0.1731650270102);
    glVertex2f(-0.672419821652, -0.1675586091967);
    glVertex2f(-0.6711778158601, -0.0235470772408);
    glVertex2f(-0.662217568289, -0.0125504097672);
    glVertex2f(0.0730395501287, -0.0130359164763);
    glVertex2f(0.0836048363264, -0.0181229061271);
    glVertex2f(0.0934285114714, -0.0359617555258);
glEnd();
glFlush();

glColor3f(70.0f / 255.0f, 99.0f / 255.0f, 188.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.672419821652, -0.1675586091967);
    glVertex2f(-0.663653875868, -0.1731650270102);
    glVertex2f(-0.6726222946205, -0.1894950480424);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.663653875868, -0.1731650270102);
    glVertex2f(-0.6726222946205, -0.1894950480424);
    glVertex2f(-0.6716678995321, -0.1980846038385);
    glVertex2f(-0.6676033761315, -0.2041433437953);
    glVertex2f(-0.6004647520734, -0.2031462355172);
    glVertex2f(-0.6001323826474, -0.189851458476);
    glVertex2f(-0.6021265992036, -0.1725682483225);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.6001323826474, -0.189851458476);
    glVertex2f(-0.6021265992036, -0.1725682483225);
    glVertex2f(-0.4990056470299, -0.1726708401538);
    glVertex2f(-0.501254235113, -0.1895352507768);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.501254235113, -0.1895352507768);
    glVertex2f(-0.4992378490169, -0.1925765696545);
    glVertex2f(-0.4988023699251, -0.202429284107);
    glVertex2f(-0.4844698513919, -0.202461688988);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.4844698513919, -0.202461688988);
    glVertex2f(-0.501254235113, -0.1895352507768);
    glVertex2f(-0.4990056470299, -0.1726708401538);
    glVertex2f(-0.1442751214515, -0.1720305881822);
    glVertex2f(-0.1440068534334, -0.1936054646578);
    glVertex2f(-0.1434715090311, -0.2033000430044);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.1442751214515, -0.1720305881822);
    glVertex2f(-0.1440068534334, -0.1936054646578);
    glVertex2f(-0.1403105826612, -0.1893811661562);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.1403105826612, -0.1893811661562);
    glVertex2f(-0.1442751214515, -0.1720305881822);
    glVertex2f(-0.045527692726, -0.1723204409061);
    glVertex2f(-0.0451715611998, -0.1890821802631);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.045527692726, -0.1723204409061);
    glVertex2f(-0.0451715611998, -0.1890821802631);
    glVertex2f(-0.0428608301554, -0.1913546019395);
    glVertex2f(0.0340683190012, -0.204012298053);
    glVertex2f(0.0333980683167, -0.1728155627993);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.0428608301554, -0.1913546019395);
    glVertex2f(-0.0422816957353, -0.2026422879883);
    glVertex2f(0.0340683190012, -0.204012298053);
glEnd();
glFlush();

glColor3f(220.0f / 255.0f, 85.0f / 255.0f, 69.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.0333980683167, -0.1728155627993);
    glVertex2f(0.0340683190012, -0.204012298053);
    glVertex2f(0.1323104330942, -0.2038317008656);
    glVertex2f(0.1323104330942, -0.2038317008656);
    glVertex2f(0.1386981987919, -0.1793712322184);
    glVertex2f(0.1341708234848, -0.1731653805914);
glEnd();
glFlush();

glColor3f(18.0f / 255.0f, 70.0f / 255.0f, 111.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.6001323826474, -0.189851458476);
    glVertex2f(-0.6004647520734, -0.2031462355172);
    glVertex2f(-0.5972034339553, -0.2070345057055);
    glVertex2f(-0.5034226752894, -0.2070345057055);
    glVertex2f(-0.4988023699251, -0.202429284107);
    glVertex2f(-0.4992378490169, -0.1925765696545);
    glVertex2f(-0.501254235113, -0.1895352507768);
glEnd();
glFlush();

glColor3f(165.0f / 255.0f, 162.0f / 255.0f, 82.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.5749430701066, -0.1920985196393);
    glVertex2f(-0.5752303006079, -0.2027260481864);
    glVertex2f(-0.5258266543888, -0.2033005091889);
    glVertex2f(-0.5269755763939, -0.1920985196393);
glEnd();
glFlush();

glColor3f(18.0f / 255.0f, 70.0f / 255.0f, 111.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.1395375408537, -0.1888419250419);
    glVertex2f(-0.1440068534334, -0.1936054646578);
    glVertex2f(-0.1434715090311, -0.2033000430044);
    glVertex2f(-0.1387415801581, -0.2075845665863);
    glVertex2f(-0.0440137546271, -0.2076108443375);
    glVertex2f(-0.0422816957353, -0.2026422879883);
    glVertex2f(-0.0428608301554, -0.1913546019395);
    glVertex2f(-0.0451715611998, -0.1890821802631);
glEnd();
glFlush();

glColor3f(165.0f / 255.0f, 162.0f / 255.0f, 82.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.1140948203055, -0.1927348616661);
    glVertex2f(-0.1151217800618, -0.2033467791476);
    glVertex2f(-0.0685662711106, -0.2024909793507);
    glVertex2f(-0.0689085910293, -0.191365581991);
glEnd();
glFlush();

glColor3f(31.0f / 255.0f, 104.0f / 255.0f, 201.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-1.0121005403361, -0.1720982056166);
    glVertex2f(-1.0106908978733, -0.0249820990945);
    glVertex2f(-0.9991920807769, -0.0124379349893);
    glVertex2f(-0.6918600602003, -0.0145286290068);
    glVertex2f(-0.6824519371214, -0.0244594255901);
    glVertex2f(-0.6798722801047, -0.1676363933231);
    glVertex2f(-0.685105057256, -0.1731918359948);
glEnd();
glFlush();

glColor3f(70.0f / 255.0f, 99.0f / 255.0f, 188.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.6798722801047, -0.1676363933231);
    glVertex2f(-0.6796867217499, -0.1984390802314);
    glVertex2f(-0.685105057256, -0.1731918359948);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.685105057256, -0.1731918359948);
    glVertex2f(-0.6796867217499, -0.1984390802314);
    glVertex2f(-0.6848630436646, -0.2031084492211);
    glVertex2f(-1.0086205828803, -0.2037006328129);
    glVertex2f(-1.0122949732048, -0.1992913644235);
    glVertex2f(-1.0121005403361, -0.1720982056166);
glEnd();
glFlush();

glColor3f(18.0f / 255.0f, 70.0f / 255.0f, 111.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.850338750978, -0.1942606338307);
    glVertex2f(-0.8465905715115, -0.1913323686225);
    glVertex2f(-0.7562017296144, -0.1905661346563);
    glVertex2f(-0.7531138152649, -0.1941234282388);
    glVertex2f(-0.7529797052253, -0.2047851763872);
    glVertex2f(-0.7547901907599, -0.2069309370208);
    glVertex2f(-0.8489524297825, -0.2067818731997);
    glVertex2f(-0.8508293186658, -0.2043488690917);
glEnd();
glFlush();

glColor3f(165.0f / 255.0f, 162.0f / 255.0f, 82.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.8228646369994, -0.1934403398042);
    glVertex2f(-0.8229659519909, -0.2026600040351);
    glVertex2f(-0.7767663158448, -0.202457374052);
    glVertex2f(-0.7765594988811, -0.1937188343348);
glEnd();
glFlush();

glColor3f(198.0f / 255.0f, 148.0f / 255.0f, 70.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-1.0106908978733, -0.0249820990945);
    glVertex2f(-1.0096390068771, -0.040585803666);
    glVertex2f(-0.6830255570267, -0.0396912369075);
    glVertex2f(-0.6824519371214, -0.0244594255901);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.6718699591986, -0.0426932616589);
    glVertex2f(-0.6650962528336, -0.0361800824618);
    glVertex2f(-0.6711778158601, -0.0235470772408);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.6711778158601, -0.0235470772408);
    glVertex2f(-0.6650962528336, -0.0361800824618);
    glVertex2f(-0.0459449592458, -0.0383722208556);
    glVertex2f(-0.0380196739386, -0.0250781938887);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.0380196739386, -0.0250781938887);
    glVertex2f(-0.0294935594728, -0.0271300038974);
    glVertex2f(-0.021993684383, -0.0346298789871);
    glVertex2f(-0.0459449592458, -0.0383722208556);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.0459449592458, -0.0383722208556);
    glVertex2f(-0.021993684383, -0.0346298789871);
    glVertex2f(0.0239786612549, -0.1653821107518);
    glVertex2f(0.0032804980851, -0.1631444714902);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.0032804980851, -0.1631444714902);
    glVertex2f(0.0239786612549, -0.1653821107518);
    glVertex2f(0.0239786612549, -0.1732138481674);
    glVertex2f(0.0028454907605, -0.167365053722);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.0028454907605, -0.167365053722);
    glVertex2f(0.0239786612549, -0.1732138481674);
    glVertex2f(-0.0039918295151, -0.1729341432597);
glEnd();
glFlush();

glColor3f(29.0f / 255.0f, 183.0f / 255.0f, 217.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.6334531746583, -0.1558067742943);
    glVertex2f(-0.6000130568089, -0.1553837829931);
    glVertex2f(-0.6, -0.06);
    glVertex2f(-0.6337879668993, -0.0590924311956);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.4361172271898, -0.0587155193332);
    glVertex2f(-0.4021137670264, -0.0585189675403);
    glVertex2f(-0.4011310080622, -0.1538465870735);
    glVertex2f(-0.435920675397, -0.1544362424521);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.3350963355938, -0.0584489684123);
    glVertex2f(-0.33410616375, -0.155005519191);
    glVertex2f(-0.2971636535257, -0.154768708228);
    glVertex2f(-0.2982834793716, -0.0585553140597);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.1329993268228, -0.0606022147701);
    glVertex2f(-0.1, -0.06);
    glVertex2f(-0.0991400061348, -0.1544742624704);
    glVertex2f(-0.1335597935594, -0.1547694799733);
glEnd();
glFlush();

glColor3f(88.0f / 255.0f, 147.0f / 255.0f, 201.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.5933614895912, -0.0594866088112);
    glVertex2f(-0.5937799653455, -0.1538860044743);
    glVertex2f(-0.5581255354512, -0.1536923662689);
    glVertex2f(-0.557370190754, -0.0596854557661);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.5387676390502, -0.0725024470014);
    glVertex2f(-0.5387676390502, -0.0725024470014);
    glVertex2f(-0.4705528154455, -0.0635268123166);
    glVertex2f(-0.4644942620332, -0.0700341474631);
    glVertex2f(-0.4633723076976, -0.1131171939502);
    glVertex2f(-0.4714503789139, -0.1223172195022);
    glVertex2f(-0.5286700500297, -0.1220928286351);
    glVertex2f(-0.5380944664488, -0.1158098843557);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.3951536170536, -0.0584153610789);
    glVertex2f(-0.3933977517984, -0.1538173732783);
    glVertex2f(-0.3588657351127, -0.1536222771389);
    glVertex2f(-0.3594510235311, -0.0578300726605);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.2933319976219, -0.0583934412736);
    glVertex2f(-0.2915595680492, -0.1540640486527);
    glVertex2f(-0.2579499213085, -0.1543019419287);
    glVertex2f(-0.2580019250821, -0.0586297628291);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.2362681800976, -0.072020350739);
    glVertex2f(-0.2301561382272, -0.0640481222124);
    glVertex2f(-0.1697382139825, -0.062809534794);
    glVertex2f(-0.1623136060578, -0.0689967080646);
    glVertex2f(-0.1598387367495, -0.1137211319923);
    glVertex2f(-0.164788475366, -0.1209689635378);
    glVertex2f(-0.2261298789348, -0.1229135037086);
    glVertex2f(-0.2349686978929, -0.1165495540588);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.0930313656421, -0.0605460760963);
    glVertex2f(-0.0930475522475, -0.1546194022291);
    glVertex2f(-0.0591722837204, -0.1543573608052);
    glVertex2f(-0.06, -0.06);
glEnd();
glFlush();

glColor3f(79.0f / 255.0f, 65.0f / 255.0f, 120.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.6716678995321, -0.1980846038385);
    glVertex2f(-0.6804230206078, -0.1980954326706);
    glVertex2f(-0.6821187221498, -0.0341970484246);
    glVertex2f(-0.6726316166764, -0.0340186297379);
glEnd();
glFlush();

glColor3f(79.0f / 255.0f, 65.0f / 255.0f, 120.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.6284026671463, -0.0709896301233);
    glVertex2f(-0.6222941649366, -0.0644644211843);
    glVertex2f(-0.6101113707379, -0.0646294833505);
    glVertex2f(-0.6049816575298, -0.0702721678794);
    glVertex2f(-0.6044707060345, -0.1122083047273);
    glVertex2f(-0.6077325642788, -0.1181405211242);
    glVertex2f(-0.6232531465324, -0.1190625359115);
    glVertex2f(-0.6287852352565, -0.1124547632689);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.5886700577868, -0.0692485945782);
    glVertex2f(-0.5836442252518, -0.064595801563);
    glVertex2f(-0.5702653124446, -0.0641063291432);
    glVertex2f(-0.5647179583537, -0.068348423448);
    glVertex2f(-0.5634126985677, -0.1153377757467);
    glVertex2f(-0.568633737712, -0.1203956574177);
    glVertex2f(-0.5834810677786, -0.120558814891);
    glVertex2f(-0.5888652643961, -0.1159904056397);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.4314965585816, -0.0719342494135);
    glVertex2f(-0.423568119673, -0.0654216031671);
    glVertex2f(-0.4119586198426, -0.0651384446347);
    glVertex2f(-0.406578607726, -0.0713679323486);
    glVertex2f(-0.4060122906611, -0.1141248707485);
    glVertex2f(-0.4136575710373, -0.1212038340598);
    glVertex2f(-0.4244175952704, -0.1209206755273);
    glVertex2f(-0.4309302415167, -0.1138417122161);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.3288130439348, -0.0705733457147);
    glVertex2f(-0.322214678663, -0.0646135319207);
    glVertex2f(-0.3081665461487, -0.0641878309354);
    glVertex2f(-0.3036966858032, -0.0714247476852);
    glVertex2f(-0.3024195828474, -0.1127177432576);
    glVertex2f(-0.3081665461487, -0.1201675105);
    glVertex2f(-0.32, -0.12);
    glVertex2f(-0.3281744924569, -0.114207696706);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.0892836732076, -0.0718699773967);
    glVertex2f(-0.0842944268722, -0.0658828817943);
    glVertex2f(-0.0685284084525, -0.0648850325272);
    glVertex2f(-0.0635391621172, -0.0712712678364);
    glVertex2f(-0.0625413128501, -0.1111852385193);
    glVertex2f(-0.0661335702116, -0.1179706135353);
    glVertex2f(-0.0818995886313, -0.1183697532422);
    glVertex2f(-0.0880862540871, -0.1119835179329);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.2368273742128, -0.1422376156921);
    glVertex2f(-0.2368273742128, -0.1447957929406);
    glVertex2f(-0.1608000049094, -0.1443836179112);
    glVertex2f(-0.1609490641881, -0.1420810240986);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.1609261492239, -0.1499339677486);
    glVertex2f(-0.1608000049094, -0.1528352869818);
    glVertex2f(-0.2373273815841, -0.1529121916653);
    glVertex2f(-0.2372111008001, -0.1504702952008);
glEnd();
glFlush();

glColor3f(88.0f / 255.0f, 147.0f / 255.0f, 201.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.9430868518139, -0.1552868113166);
    glVertex2f(-0.9083709543237, -0.154717698243);
    glVertex2f(-0.9088896146924, -0.0616857402958);
    glVertex2f(-0.9426742358103, -0.0608657252201);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.8861037632391, -0.0702623670788);
    glVertex2f(-0.8806447934814, -0.065299667299);
    glVertex2f(-0.8229120527106, -0.0641417040171);
    glVertex2f(-0.8136483464551, -0.0709240603827);
    glVertex2f(-0.8133174998032, -0.1142649717923);
    glVertex2f(-0.8196035861908, -0.1220398681139);
    glVertex2f(-0.8786597135695, -0.1220398681139);
    glVertex2f(-0.8870963031951, -0.1152575117482);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.7427563799708, -0.0610159477725);
    glVertex2f(-0.7090650701458, -0.0614243272856);
    glVertex2f(-0.7087383665354, -0.152329606886);
    glVertex2f(-0.7413066326995, -0.1532280418147);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.8893404085619, -0.1430334745668);
    glVertex2f(-0.8893404085619, -0.1452364453233);
    glVertex2f(-0.8118287483798, -0.1462581503938);
    glVertex2f(-0.8120045404289, -0.1439610412011);
glEnd();
glFlush();

glColor3f(24.0f / 255.0f, 182.0f / 255.0f, 218.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.7844110902998, -0.0601991887465);
    glVertex2f(-0.7507197804749, -0.0610159477725);
    glVertex2f(-0.7496988316923, -0.1549432357694);
    glVertex2f(-0.7842069005433, -0.1539222869868);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.9830564271331, -0.0596608765778);
    glVertex2f(-0.9477101589978, -0.0601353231299);
    glVertex2f(-0.948535508957, -0.154335396395);
    glVertex2f(-0.9844740230543, -0.1540035331632);
glEnd();
glFlush();

glColor3f(76.0f / 255.0f, 66.0f / 255.0f, 123.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.9383739377764, -0.0710206155469);
    glVertex2f(-0.9145307451309, -0.0708579966006);
    glVertex2f(-0.9145492049903, -0.1156735630729);
    glVertex2f(-0.9388177488355, -0.115188192196);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.7792512789475, -0.0697082583524);
    glVertex2f(-0.7544532071357, -0.0699639085773);
    glVertex2f(-0.7541094527302, -0.1164442472969);
    glVertex2f(-0.7792330617327, -0.1167663448482);
glEnd();
glFlush();

glColor3f(241.0f / 255.0f, 233.0f / 255.0f, 183.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.0259594423073, -0.140775583802);
    glVertex2f(0.028771952653, -0.1374943217321);
    glVertex2f(0.0333255408316, -0.1395702222253);
    glVertex2f(0.0354684058569, -0.1435211296156);
    glVertex2f(0.0375443063501, -0.1482086468584);
    glVertex2f(0.0362050157093, -0.1529631286332);
    glVertex2f(0.0331916117676, -0.1576506458759);
    glVertex2f(0.027164803884, -0.1565792133633);
    glVertex2f(0.0244862226024, -0.1488782921788);
glEnd();
glFlush();

glColor3f(241.0f / 255.0f, 233.0f / 255.0f, 183.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.1118812654008, -0.1429171236519);
    glVertex2f(0.115, -0.14);
    glVertex2f(0.12, -0.14);
    glVertex2f(0.1222895558501, -0.1424134966946);
    glVertex2f(0.1236325610693, -0.1470020978604);
    glVertex2f(0.1233527683153, -0.1541088338124);
    glVertex2f(0.1213942190372, -0.159312979037);
    glVertex2f(0.1167496593206, -0.1597606474435);
    glVertex2f(0.1130004364168, -0.1571865541065);
    glVertex2f(0.1112097627912, -0.1501917352562);
glEnd();
glFlush();

glColor3f(146.0f / 255.0f, 129.0f / 255.0f, 158.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.0412719368907, -0.1375187653607);
    glVertex2f(0.0418671414714, -0.1418835989524);
    glVertex2f(0.1011891980129, -0.1422804020061);
    glVertex2f(0.1020998635417, -0.137050527676);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.0439162295579, -0.1449793809557);
    glVertex2f(0.0441232908693, -0.1487064845602);
    glVertex2f(0.1046887244439, -0.1490170765273);
    glVertex2f(0.1049993164109, -0.1444617276772);
glEnd();
glFlush();


glBegin(GL_POLYGON);
    glVertex2f(0.0471231448798, -0.1533381424659);
    glVertex2f(0.0472905231405, -0.1570204642008);
    glVertex2f(0.1067121439077, -0.1570781008503);
    glVertex2f(0.1070221277403, -0.1525316713051);
glEnd();
glFlush();


glBegin(GL_POLYGON);
    glVertex2f(0.05, -0.16);
    glVertex2f(0.05, -0.165);
    glVertex2f(0.1107098140348, -0.1648777802536);
    glVertex2f(0.1110677463276, -0.1597933951853);
glEnd();
glFlush();

glColor3f(140.0f / 255.0f, 187.0f / 255.0f, 220.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.0040678005632, -0.0472931798261);
    glVertex2f(0.0247170630047, -0.131880278907);
    glVertex2f(0.120919107034, -0.1311227824973);
    glVertex2f(0.0961742243178, -0.0475456786293);
glEnd();
glFlush();

glColor3f(239.0f / 255.0f, 226.0f / 255.0f, 102.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.0081175216889, -0.0378078712846);
    glVertex2f(0.0873921889508, -0.0368877053971);
    glVertex2f(0.0771348413815, -0.0196121726489);
    glVertex2f(-0.0173407283354, -0.0200170679477);
glEnd();
glFlush();
}
void bus()
{
        glPushMatrix();
        glColor3f(255.0f / 255.0f, 114.0f / 255.0f, 92.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5672019377311, -0.5822555467175);
    glVertex2f(-0.5251137002698, -0.588444993403);
    glVertex2f(-0.1797933074284, -0.5815239397477);
    glVertex2f(-0.1745696693527, -0.5739941724924);
    glVertex2f(-0.1765830047504, -0.4635495585046);
    glVertex2f(-0.18, -0.46);
    glVertex2f(-0.562220221393, -0.4659586496848);
    glVertex2f(-0.5659829212825, -0.469930388457);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.529257504861, -0.4665575025648);
    glVertex2f(-0.4849803470441, -0.465626440835);
    glVertex2f(-0.4920150356692, -0.4603504243662);
    glVertex2f(-0.5242918423021, -0.4608676808827);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.3392412125968, -0.4647896721905);
    glVertex2f(-0.2147579218922, -0.4635412605554);
    glVertex2f(-0.2225779578785, -0.4542993998443);
    glVertex2f(-0.3351322883081, -0.4565718236131);
    glEnd();
    glFlush();

    glColor3f(26.0f / 255.0f, 46.0f / 255.0f, 53.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35739341705, -0.463776346119);
    glVertex2f(-0.3572405526888, -0.4789950348653);
    glVertex2f(-0.4247820007165, -0.4791896788078);
    glVertex2f(-0.4255432051833, -0.4644494304463);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.4234325779156, -0.48482820249);
    glVertex2f(-0.3588497839184, -0.4836161929511);
    glVertex2f(-0.3573395088637, -0.5846412015479);
    glVertex2f(-0.421475234986, -0.5856998380176);
    glEnd();
    glFlush();

            glBegin(GL_POLYGON);
    glVertex2f(-0.353583018299, -0.4767967656245);
    glVertex2f(-0.2334144721161, -0.4739379362303);
    glVertex2f(-0.2326544087812, -0.5339829396843);
    glVertex2f(-0.3523401379787, -0.5356990878917);
    glEnd();
    glFlush();

                glBegin(GL_POLYGON);
    glVertex2f(-0.2268520765469, -0.4811560144437);
    glVertex2f(-0.1886528139787, -0.4813581269441);
    glVertex2f(-0.1871359739196, -0.5809603804793);
    glVertex2f(-0.2251410269592, -0.5818783769295);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.4270209319746, -0.5378503610917);
    glVertex2f(-0.4286547365182, -0.4792984370988);
    glVertex2f(-0.56, -0.48);
    glVertex2f(-0.5587523914621, -0.532679593523);
    glVertex2f(-0.552104261731, -0.5398201773083);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.1836713104816, -0.4716596946395);
    glVertex2f(-0.1766736091856, -0.4711634547147);
    glVertex2f(-0.1757880552097, -0.5456236801604);
    glVertex2f(-0.1822670044269, -0.5459836217835);
    glEnd();
    glFlush();

    glColor3f(56.0f / 255.0f, 90.0f / 255.0f, 100.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.554207260697, -0.4842957370729);
    glVertex2f(-0.5540117815281, -0.5124447373827);
    glVertex2f(-0.545606177269, -0.5173317166031);
    glVertex2f(-0.4939996767011, -0.516354320759);
    glVertex2f(-0.4947815933763, -0.4833183412288);
    glEnd();
    glFlush();

    glColor3f(56.0f / 255.0f, 90.0f / 255.0f, 100.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4899810134883, -0.4834067669212);
    glVertex2f(-0.4383631827804, -0.5200267446741);
    glVertex2f(-0.49, -0.52);
    glEnd();
    glFlush();

    glColor3f(56.0f / 255.0f, 90.0f / 255.0f, 100.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4899810134883, -0.4834067669212);
    glVertex2f(-0.4298528069679, -0.5335432239057);
    glVertex2f(-0.431004031605, -0.4816856487728);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.4197837044982, -0.4917490397194);
    glVertex2f(-0.3956326429126, -0.4912398367645);
    glVertex2f(-0.3936941362549, -0.5712196143027);
    glVertex2f(-0.417760416417, -0.5718065967456);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.3874329901965, -0.4917813236866);
    glVertex2f(-0.3639536924775, -0.4911943412436);
    glVertex2f(-0.3618014235199, -0.570241310231);
    glVertex2f(-0.3854763820533, -0.5710239534883);
    glEnd();
    glFlush();

            glBegin(GL_POLYGON);
    glVertex2f(-0.3516680491718, -0.4794425448131);
    glVertex2f(-0.3493875195922, -0.5323508310596);
    glVertex2f(-0.2952249420769, -0.5323508310596);
    glVertex2f(-0.2959091009508, -0.4783022800233);
    glEnd();
    glFlush();

                glBegin(GL_POLYGON);
    glVertex2f(-0.2920142811532, -0.4782260088239);
    glVertex2f(-0.2910421137774, -0.5327237759755);
    glVertex2f(-0.2353757415213, -0.5310865297327);
    glVertex2f(-0.2369740910169, -0.4785786995592);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.2233786664441, -0.4886450888687);
    glVertex2f(-0.2215051715542, -0.5682862964527);
    glVertex2f(-0.1911064463055, -0.5675493576588);
    glVertex2f(-0.1922311246392, -0.4879034807305);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.1766736091856, -0.4711634547147);
    glVertex2f(-0.1812956409956, -0.4742551171992);
    glVertex2f(-0.18, -0.54);
    glVertex2f(-0.1757880552097, -0.5456236801604);
    glEnd();
    glFlush();

   // ---------- WHEELS ----------
float rearX  = -0.48f;
float frontX = -0.23f;
float wheelY = -0.59f;   // just below the bus base
float R      = 0.030f;   // outer radius (black tyre)
float r      = 0.015f;   // inner radius (white hub)

// � outer tyre �
glColor3f(0.0f, 0.0f, 0.0f);      // black
drawWheels(rearX,  wheelY, R, 100);
drawWheels(frontX, wheelY, R, 100);

// � hubcap �
glColor3f(1.0f, 1.0f, 1.0f);      // white
drawWheels(rearX,  wheelY, r, 60);
drawWheels(frontX, wheelY, r, 60);
    glPopMatrix();
}

void blackBus()
{
     glPushMatrix();
        glColor3f(255.0f / 255.0f, 245.0f / 255.0f, 92.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5672019377311, -0.5822555467175);
    glVertex2f(-0.5251137002698, -0.588444993403);
    glVertex2f(-0.1797933074284, -0.5815239397477);
    glVertex2f(-0.1745696693527, -0.5739941724924);
    glVertex2f(-0.1765830047504, -0.4635495585046);
    glVertex2f(-0.18, -0.46);
    glVertex2f(-0.562220221393, -0.4659586496848);
    glVertex2f(-0.5659829212825, -0.469930388457);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.529257504861, -0.4665575025648);
    glVertex2f(-0.4849803470441, -0.465626440835);
    glVertex2f(-0.4920150356692, -0.4603504243662);
    glVertex2f(-0.5242918423021, -0.4608676808827);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.3392412125968, -0.4647896721905);
    glVertex2f(-0.2147579218922, -0.4635412605554);
    glVertex2f(-0.2225779578785, -0.4542993998443);
    glVertex2f(-0.3351322883081, -0.4565718236131);
    glEnd();
    glFlush();

    glColor3f(26.0f / 255.0f, 46.0f / 255.0f, 53.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35739341705, -0.463776346119);
    glVertex2f(-0.3572405526888, -0.4789950348653);
    glVertex2f(-0.4247820007165, -0.4791896788078);
    glVertex2f(-0.4255432051833, -0.4644494304463);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.4234325779156, -0.48482820249);
    glVertex2f(-0.3588497839184, -0.4836161929511);
    glVertex2f(-0.3573395088637, -0.5846412015479);
    glVertex2f(-0.421475234986, -0.5856998380176);
    glEnd();
    glFlush();

            glBegin(GL_POLYGON);
    glVertex2f(-0.353583018299, -0.4767967656245);
    glVertex2f(-0.2334144721161, -0.4739379362303);
    glVertex2f(-0.2326544087812, -0.5339829396843);
    glVertex2f(-0.3523401379787, -0.5356990878917);
    glEnd();
    glFlush();

                glBegin(GL_POLYGON);
    glVertex2f(-0.2268520765469, -0.4811560144437);
    glVertex2f(-0.1886528139787, -0.4813581269441);
    glVertex2f(-0.1871359739196, -0.5809603804793);
    glVertex2f(-0.2251410269592, -0.5818783769295);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.4270209319746, -0.5378503610917);
    glVertex2f(-0.4286547365182, -0.4792984370988);
    glVertex2f(-0.56, -0.48);
    glVertex2f(-0.5587523914621, -0.532679593523);
    glVertex2f(-0.552104261731, -0.5398201773083);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.1836713104816, -0.4716596946395);
    glVertex2f(-0.1766736091856, -0.4711634547147);
    glVertex2f(-0.1757880552097, -0.5456236801604);
    glVertex2f(-0.1822670044269, -0.5459836217835);
    glEnd();
    glFlush();

    glColor3f(56.0f / 255.0f, 90.0f / 255.0f, 100.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.554207260697, -0.4842957370729);
    glVertex2f(-0.5540117815281, -0.5124447373827);
    glVertex2f(-0.545606177269, -0.5173317166031);
    glVertex2f(-0.4939996767011, -0.516354320759);
    glVertex2f(-0.4947815933763, -0.4833183412288);
    glEnd();
    glFlush();

    glColor3f(56.0f / 255.0f, 90.0f / 255.0f, 100.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4899810134883, -0.4834067669212);
    glVertex2f(-0.4383631827804, -0.5200267446741);
    glVertex2f(-0.49, -0.52);
    glEnd();
    glFlush();

    glColor3f(56.0f / 255.0f, 90.0f / 255.0f, 100.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4899810134883, -0.4834067669212);
    glVertex2f(-0.4298528069679, -0.5335432239057);
    glVertex2f(-0.431004031605, -0.4816856487728);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.4197837044982, -0.4917490397194);
    glVertex2f(-0.3956326429126, -0.4912398367645);
    glVertex2f(-0.3936941362549, -0.5712196143027);
    glVertex2f(-0.417760416417, -0.5718065967456);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(-0.3874329901965, -0.4917813236866);
    glVertex2f(-0.3639536924775, -0.4911943412436);
    glVertex2f(-0.3618014235199, -0.570241310231);
    glVertex2f(-0.3854763820533, -0.5710239534883);
    glEnd();
    glFlush();

            glBegin(GL_POLYGON);
    glVertex2f(-0.3516680491718, -0.4794425448131);
    glVertex2f(-0.3493875195922, -0.5323508310596);
    glVertex2f(-0.2952249420769, -0.5323508310596);
    glVertex2f(-0.2959091009508, -0.4783022800233);
    glEnd();
    glFlush();

                glBegin(GL_POLYGON);
    glVertex2f(-0.2920142811532, -0.4782260088239);
    glVertex2f(-0.2910421137774, -0.5327237759755);
    glVertex2f(-0.2353757415213, -0.5310865297327);
    glVertex2f(-0.2369740910169, -0.4785786995592);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.2233786664441, -0.4886450888687);
    glVertex2f(-0.2215051715542, -0.5682862964527);
    glVertex2f(-0.1911064463055, -0.5675493576588);
    glVertex2f(-0.1922311246392, -0.4879034807305);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.1766736091856, -0.4711634547147);
    glVertex2f(-0.1812956409956, -0.4742551171992);
    glVertex2f(-0.18, -0.54);
    glVertex2f(-0.1757880552097, -0.5456236801604);
    glEnd();
    glFlush();

   // ---------- WHEELS ----------
float rearX  = -0.48f;
float frontX = -0.23f;
float wheelY = -0.59f;   // just below the bus base
float R      = 0.030f;   // outer radius (black tyre)
float r      = 0.015f;   // inner radius (white hub)

// � outer tyre �
glColor3f(0.0f, 0.0f, 0.0f);      // black
drawWheels(rearX,  wheelY, R, 100);
drawWheels(frontX, wheelY, R, 100);

// � hubcap �
glColor3f(1.0f, 1.0f, 1.0f);      // white
drawWheels(rearX,  wheelY, r, 60);
drawWheels(frontX, wheelY, r, 60);
    glPopMatrix();
}
void drawTree(float x, float y) {
    // Elegant tapered trunk with subtle gradient
    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.2f, 0.07f); // Base color
        glVertex2f(x - 0.018f, y);
        glVertex2f(x + 0.018f, y);
        glColor3f(0.3f, 0.15f, 0.05f); // Darker at top
        glVertex2f(x + 0.012f, y + 0.18f);
        glVertex2f(x - 0.012f, y + 0.18f);
    glEnd();

    // Main foliage composition - 3 tiers of circles

    // Bottom tier (largest circles)
    drawCircle(x - 0.07f, y + 0.22f, 0.11f, 0.15f, 0.35f, 0.12f);
    drawCircle(x + 0.07f, y + 0.22f, 0.11f, 0.15f, 0.35f, 0.12f);
    drawCircle(x, y + 0.2f, 0.13f, 0.12f, 0.32f, 0.1f);

    // Middle tier (medium circles)
    drawCircle(x - 0.05f, y + 0.28f, 0.09f, 0.25f, 0.45f, 0.15f);
    drawCircle(x + 0.05f, y + 0.28f, 0.09f, 0.25f, 0.45f, 0.15f);
    drawCircle(x, y + 0.3f, 0.1f, 0.22f, 0.42f, 0.14f);

    // Top tier (smaller circles)
    drawCircle(x - 0.03f, y + 0.36f, 0.07f, 0.35f, 0.55f, 0.2f);
    drawCircle(x + 0.03f, y + 0.36f, 0.07f, 0.35f, 0.55f, 0.2f);
    drawCircle(x, y + 0.38f, 0.08f, 0.4f, 0.6f, 0.25f);

    // Accent circles for depth and richness
    drawCircle(x - 0.09f, y + 0.25f, 0.06f, 0.18f, 0.38f, 0.13f);
    drawCircle(x + 0.09f, y + 0.25f, 0.06f, 0.18f, 0.38f, 0.13f);
    drawCircle(x - 0.11f, y + 0.3f, 0.05f, 0.28f, 0.48f, 0.18f);
    drawCircle(x + 0.11f, y + 0.3f, 0.05f, 0.28f, 0.48f, 0.18f);

    // Highlight circles (brightest)
    drawCircle(x - 0.02f, y + 0.32f, 0.04f, 0.45f, 0.65f, 0.3f);
    drawCircle(x + 0.02f, y + 0.32f, 0.04f, 0.45f, 0.65f, 0.3f);
    drawCircle(x, y + 0.34f, 0.05f, 0.5f, 0.7f, 0.35f);
}


void drawCircle(float x, float y, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * float(i) / float(segments);
        float dx = radius * cosf(angle);
        float dy = radius * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawCloud(float x, float y, float size) {
    glColor3f(1.0f, 1.0f, 1.0f); // White color for clouds

    // Cloud is made of several overlapping circles
    drawCircle(x, y, size * 0.5f, 20);
    drawCircle(x + size * 0.4f, y + size * 0.1f, size * 0.4f, 20);
    drawCircle(x + size * 0.7f, y, size * 0.35f, 20);
    drawCircle(x + size * 0.3f, y - size * 0.1f, size * 0.35f, 20);
    drawCircle(x - size * 0.2f, y, size * 0.4f, 20);
}

void drawClouds() {
    // Draw several clouds at different positions
    drawCloud(-0.8f + cloudOffset, 0.7f, 0.15f);
    drawCloud(-0.4f + cloudOffset * 0.8f, 0.8f, 0.12f);
    drawCloud(0.0f + cloudOffset * 0.6f, 0.65f, 0.18f);
    drawCloud(0.5f + cloudOffset * 0.4f, 0.75f, 0.14f);
    drawCloud(0.8f + cloudOffset * 0.3f, 0.7f, 0.16f);

    // Some smaller distant clouds
    drawCloud(-0.9f + cloudOffset * 0.5f, 0.5f, 0.1f);
    drawCloud(-0.2f + cloudOffset * 0.7f, 0.55f, 0.08f);
    drawCloud(0.3f + cloudOffset * 0.6f, 0.45f, 0.09f);
    drawCloud(0.9f + cloudOffset * 0.4f, 0.5f, 0.11f);
}

void sky()
{
    glColor3f(9.0f / 255.0f, 221.0f / 255.0f, 245.0f / 255.0f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glColor3f(172.0f / 255.0f, 235.0f / 255.0f, 228.0f / 255.0f);

    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glEnd();
    glFlush();

}
void cityBuilding()
{
        glPushMatrix();
     glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9165551075862f, 0.3299784835584f);
    glVertex2f(-0.9240548496061f, -0.5525364414272f);
    glVertex2f(-0.7183019878658f, -0.5566188394776f);
    glVertex2f(-0.7020075890435f, 0.3291304696511f);
    glEnd();
    glFlush();
        glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8891644156834f, 0.3271369786236f);
    glVertex2f(-0.7597081554481f, 0.3276129207568f);
    glVertex2f(-0.7592322133149f, 0.3699717706133f);
    glVertex2f(-0.888212531417f, 0.36949582848f);
    glEnd();
    glFlush();

        glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6866933736163f, 0.2020009413475f);
    glVertex2f(-0.4732417088864f, 0.2718578498046f);
    glVertex2f(-0.4868249966419f, -0.5586631729629f);
    glVertex2f(-0.6944552523338f, -0.5567227032836f);
    glEnd();
    glFlush();

            glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4452670604313f, 0.3315723061369f);
    glVertex2f(-0.2269652712555f, 0.3315723061369f);
    glVertex2f(-0.2348729285514f, -0.5472967100592f);
    glVertex2f(-0.4458434790875f, -0.5503542542699f);
    glEnd();
    glFlush();

                glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4120574315271f, 0.3684974205607f);
    glVertex2f(-0.2827431560154f, 0.3694038767643f);
    glVertex2f(-0.2827431560154f, 0.3080879251785f);
    glVertex2f(-0.4120574315271f, 0.3096428818473f);
    glEnd();
    glFlush();


                    glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2107971942833f, 0.268941344189f);
    glVertex2f(0.003270783055f, 0.2213706825582f);
    glVertex2f(0.0052528939563f, -0.5437241253362f);
    glVertex2f(-0.2180564353927f, -0.5595268869019f);
    glEnd();
    glFlush();

                        glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0284404814737f, 0.3387420996324f);
    glVertex2f(0.2418031220802f, 0.1667969127908f);
    glVertex2f(0.2331893190512f, -0.5529918150577f);
    glVertex2f(0.0316650802774f, -0.5561103804765f);
    glEnd();
    glFlush();

                            glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.2647210540119f, 0.2702908745339f);
    glVertex2f(0.4718011715158f, 0.2204867956405f);
    glVertex2f(0.4693239829293f, -0.5551359797074f);
    glVertex2f(0.2565709254164f, -0.5572376006196f);
    glEnd();
    glFlush();

                            glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.4972220346737f, 0.3336691273783f);
    glVertex2f(0.7150641291566f, 0.3336691273783f);
    glVertex2f(0.6910838447224f, -0.575443243912f);
    glVertex2f(0.4935659498468f, -0.5845594544448f);
    glEnd();
    glFlush();

    glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5295844832327f, 0.3304091127252f);
    glVertex2f(0.6523735496478f, 0.3283961772102f);
    glVertex2f(0.6537155066578f, 0.3713388015302f);
    glVertex2f(0.5269005692127f, 0.3726807585402f);
    glEnd();
    glFlush();

    glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.7380007466471f, 0.2672377290805f);
    glVertex2f(0.9261938773781f, 0.2266470538248f);
    glVertex2f(0.9209675282814f, -0.5891948655964f);
    glVertex2f(0.7190061904525f, -0.5923019631014f);
    glEnd();
    glFlush();

    glColor3f(173.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.92, 0.2);
    glVertex2f(0.9466197653753, 0.2014711670211);
    glVertex2f(0.9522201793967, -0.5913621304238);
    glVertex2f(0.9209675282814, -0.5891948655964);
    glEnd();
    glFlush();

// Building code
glColor3f(140.0f / 255.0f, 211.0f / 255.0f, 226.0f / 255.0f);
glBegin(GL_POLYGON);
glVertex2f(-0.7778522242043f, 0.1430806256088f);
glVertex2f(-0.4086364593232f, 0.1430806256088f);
glVertex2f(-0.409961164317f, -0.5530465694392f);
glVertex2f(-0.7802353187657f, -0.5548689365131f);
glEnd();

// Window pattern - now with 4 columns
glColor3f(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);

// First row of windows (aligned left)
for (float y = 0.03f; y > -0.05f; y -= 0.02f) {
    // Column 1
    glBegin(GL_POLYGON);
    glVertex2f(-0.71f, y);
    glVertex2f(-0.693f, y);
    glVertex2f(-0.693f, y - 0.0085f);
    glVertex2f(-0.71f, y - 0.0085f);
    glEnd();

    // Column 2
    glBegin(GL_POLYGON);
    glVertex2f(-0.65f, y);
    glVertex2f(-0.633f, y);
    glVertex2f(-0.633f, y - 0.0085f);
    glVertex2f(-0.65f, y - 0.0085f);
    glEnd();

    // Column 3
    glBegin(GL_POLYGON);
    glVertex2f(-0.59f, y);
    glVertex2f(-0.573f, y);
    glVertex2f(-0.573f, y - 0.0085f);
    glVertex2f(-0.59f, y - 0.0085f);
    glEnd();

    // NEW Column 4 (extra column)
    glBegin(GL_POLYGON);
    glVertex2f(-0.53f, y);
    glVertex2f(-0.513f, y);
    glVertex2f(-0.513f, y - 0.0085f);
    glVertex2f(-0.53f, y - 0.0085f);
    glEnd();
}

// Second row of windows (offset right)
for (float y = -0.03f; y > -0.45f; y -= 0.02f) {
    // Column 1
    glBegin(GL_POLYGON);
    glVertex2f(-0.68f, y);
    glVertex2f(-0.663f, y);
    glVertex2f(-0.663f, y - 0.0085f);
    glVertex2f(-0.68f, y - 0.0085f);
    glEnd();

    // Column 2
    glBegin(GL_POLYGON);
    glVertex2f(-0.62f, y);
    glVertex2f(-0.603f, y);
    glVertex2f(-0.603f, y - 0.0085f);
    glVertex2f(-0.62f, y - 0.0085f);
    glEnd();

    // Column 3
    glBegin(GL_POLYGON);
    glVertex2f(-0.56f, y);
    glVertex2f(-0.543f, y);
    glVertex2f(-0.543f, y - 0.0085f);
    glVertex2f(-0.56f, y - 0.0085f);
    glEnd();

    // NEW Column 4 (extra column)
    glBegin(GL_POLYGON);
    glVertex2f(-0.50f, y);
    glVertex2f(-0.483f, y);
    glVertex2f(-0.483f, y - 0.0085f);
    glVertex2f(-0.50f, y - 0.0085f);
    glEnd();
}

// Third row of windows (aligned with first row)
for (float y = -0.09f; y > -0.45f; y -= 0.02f) {
    // Column 1
    glBegin(GL_POLYGON);
    glVertex2f(-0.71f, y);
    glVertex2f(-0.693f, y);
    glVertex2f(-0.693f, y - 0.0085f);
    glVertex2f(-0.71f, y - 0.0085f);
    glEnd();

    // Column 2
    glBegin(GL_POLYGON);
    glVertex2f(-0.65f, y);
    glVertex2f(-0.633f, y);
    glVertex2f(-0.633f, y - 0.0085f);
    glVertex2f(-0.65f, y - 0.0085f);
    glEnd();

    // Column 3
    glBegin(GL_POLYGON);
    glVertex2f(-0.59f, y);
    glVertex2f(-0.573f, y);
    glVertex2f(-0.573f, y - 0.0085f);
    glVertex2f(-0.59f, y - 0.0085f);
    glEnd();

    // NEW Column 4 (extra column)
    glBegin(GL_POLYGON);
    glVertex2f(-0.53f, y);
    glVertex2f(-0.513f, y);
    glVertex2f(-0.513f, y - 0.0085f);
    glVertex2f(-0.53f, y - 0.0085f);
    glEnd();
}

glFlush();
                    glColor3f(85.0f / 255.0f,149.0f / 255.0f, 196.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8080875742622f, 0.1199156816554f);
    glVertex2f(-0.3878418160996f, 0.1180938069813f);
    glVertex2f(-0.3878418160996f, 0.1041261011464f);
    glVertex2f(-0.8086948658202f, 0.1041261011464f);
    glEnd();
    glFlush();

                        glColor3f(85.0f / 255.0f,149.0f / 255.0f, 196.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3987730641443f, 0.0725469401284f);
    glVertex2f(-0.3975584810282f, 0.0597938174096f);
    glVertex2f(-0.7983709093336f, 0.0597938174096f);
    glVertex2f(-0.7989782008916f, 0.0737615232445f);
    glEnd();
    glFlush();

        glColor3f(24.0f / 255.0f,181.0f / 255.0f, 223.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6678515941379f, 0.156946214237f);
    glVertex2f(-0.6295413937075f, 0.1556469540328f);
    glVertex2f(-0.6340523999875f, -0.5292807146483f);
    glVertex2f(-0.6748604582112f, -0.5312239555161f);
    glEnd();
    glFlush();




    glColor3f(24.0f / 255.0f,181.0f / 255.0f, 223.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5626548606533f, 0.1521820208384f);
    glVertex2f(-0.5271398523085f, 0.1537722450927f);
    glVertex2f(-0.5213444296554f, -0.5370536781195f);
    glVertex2f(-0.5647885586098f, -0.5353965598743f);
    glEnd();
    glFlush();

        glColor3f(85.0f / 255.0f,149.0f / 255.0f, 196.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8355058681035, -0.3924291069909);
    glVertex2f(-0.3687862759945, -0.3892826827744);
    glVertex2f(-0.3677374679223, -0.5392622370926);
    glVertex2f(-0.8376034842478, -0.5413598532369);
    glEnd();
    glFlush();

            glColor3f(85.0f / 255.0f,149.0f / 255.0f, 196.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8355058681035, -0.3924291069909);
    glVertex2f(-0.3687862759945, -0.3892826827744);
    glVertex2f(-0.3677374679223, -0.5392622370926);
    glVertex2f(-0.8376034842478, -0.5413598532369);
    glEnd();
    glFlush();

                glColor3f(85.0f / 255.0f,149.0f / 255.0f, 196.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8094087372461f, 0.1562490116758f);
    glVertex2f(-0.3866809748474f, 0.1550531764215f);
    glVertex2f(-0.3872788924746f, 0.1407031533697f);
    glVertex2f(-0.8093058958036f, 0.1436927226196f);
    glEnd();
    glFlush();

    glColor3f(255.0f / 255.0f,255.0f / 255.0f, 255.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.64891756272f, 0.1082218083678f);
    glVertex2f(-0.548203643539f, 0.107880405252f);
    glVertex2f(-0.548203643539f, 0.0614495814939f);
    glVertex2f(-0.6482347564883f, 0.0617909846098f);
    glEnd();
    glFlush();

    glColor3f(255.0f / 255.0f,255.0f / 255.0f, 255.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6312842235338f, 0.1010164327646f);
    glVertex2f(-0.56f, 0.1f);
    glVertex2f(-0.598638614476f, 0.1294647492293f);
    glEnd();
    glFlush();

glColor3f(140.0f / 255.0f, 211.0f / 255.0f, 226.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.3780287774307, -0.4033439879658);
    glVertex2f(-0.3771235975905, -0.5382157841555);
    glVertex2f(-0.5135040268472, -0.5388192373823);
    glVertex2f(-0.5150126599142, -0.404249167806);
    glEnd();
    glFlush();

glColor3f(140.0f / 255.0f, 211.0f / 255.0f, 226.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.5243661849296, -0.4036457145792);
    glVertex2f(-0.5255730913832, -0.5373106043153);
    glVertex2f(-0.64, -0.54);
    glVertex2f(-0.6411343843153, -0.404249167806);
    glEnd();
    glFlush();

glColor3f(140.0f / 255.0f, 211.0f / 255.0f, 226.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.7068001098475, -0.4036061856398);
    glVertex2f(-0.7045822578628, -0.5391674820657);
    glVertex2f(-0.8162834839316, -0.5370650633226);
    glVertex2f(-0.8151505653011, -0.4032101679198);
    glEnd();
    glFlush();

    glColor3f(88.0f / 255.0f, 147.0f / 255.0f, 203.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.1116502554775, 0.1514911689587);
    glVertex2f(0.1917517233389, 0.1519744749426);
    glVertex2f(0.1917517233389, -0.5412693053477);
    glVertex2f(-0.1226020629189, -0.5391874921936);
    glEnd();
    glFlush();

        glColor3f(21.0f / 255.0f, 184.0f / 255.0f, 224.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.110201492607, 0.0938146251114);
    glVertex2f(0.1917687167781, 0.0961197412136);
    glVertex2f(0.1917517233389, -0.5412693053477);
    glVertex2f(-0.1226020629189, -0.5391874921936);
    glEnd();
    glFlush();

    glColor3f(139.0f / 255.0f, 208.0f / 255.0f, 228.0f / 255.0f);
        glBegin(GL_POLYGON);
    glVertex2f(-0.0652816964257, 0.0914838823547);
    glVertex2f(0.1525623270498, 0.0966706448184);
    glVertex2f(0.1542912478711, -0.5274697716471);
    glVertex2f(-0.0670106172469, -0.5309276132896);
    glEnd();
    glFlush();
            glColor3f(21.0f / 255.0f, 184.0f / 255.0f, 224.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.1378628858331, -0.0421872249169);
    glVertex2f(0.2217352261064, -0.0421872249169);
    glVertex2f(0.2217352261064, -0.5423974190891);
    glVertex2f(-0.1332526536287, -0.5377871868848);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-0.1470833502418, -0.3349369698933);
    glVertex2f(0.2355659227194, -0.3395472020976);
    glVertex2f(0.2309556905151, -0.5377871868848);
    glVertex2f(-0.1447782341396, -0.5377871868848);
    glEnd();
    glFlush();

        glColor3f(139.0f / 255.0f, 208.0f / 255.0f, 228.0f / 255.0f);
        glBegin(GL_POLYGON);
    glVertex2f(0.0086703138847, -0.3279266425065);
    glVertex2f(0.071340751966, -0.3263980952363);
    glVertex2f(0.0721050256011, -0.447917603223);
    glVertex2f(0.0109631347902, -0.4494461504933);
    glEnd();
    glFlush();

            glColor3f(139.0f / 255.0f, 208.0f / 255.0f, 228.0f / 255.0f);
        glBegin(GL_POLYGON);
    glVertex2f(0.0312484638443, -0.3372863786906);
    glVertex2f(0.0490530984104, -0.3339352549189);
    glVertex2f(0.0460846815239, -0.0118620227291);
    glVertex2f(0.0312425970912, -0.0088936058425);
    glEnd();
    glFlush();

// Draw white windows
glColor3f(1.0f, 1.0f, 1.0f);

// Window dimensions (calculated from your window code)
const float window_w = 0.1324224569582f - 0.1088140982991f; // Width = ~0.0236
const float window_h = 0.0655572045027f - 0.0544937263143f; // Height = ~0.011

// Building boundaries (using your vertex coordinates)
const float left = -0.112f;  // Slightly beyond leftmost point for margin
const float right = 0.191f;  // Slightly before rightmost point
const float top = 0.093f;    // Slightly below top point
const float bottom = -0.49f;// Slightly above bottom point

// Calculate optimal window grid (more windows vertically)
const int cols = 5;  // Horizontal windows
const int rows = 15; // Vertical windows (fills full height)

// Calculate dynamic spacing with edge margins
const float margin_x = 0.008f;
const float margin_y = 0.005f;
const float spacing_x = (right - left - cols*window_w - 2*margin_x)/(cols - 1);
const float spacing_y = (top - bottom - rows*window_h - 2*margin_y)/(rows - 1);

// Draw complete window grid
for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
        float x = left + margin_x + col*(window_w + spacing_x);
        float y = bottom + margin_y + row*(window_h + spacing_y);

        // Skip windows that would extend beyond building edges
        if (x + window_w > right || y + window_h > top) continue;

        glBegin(GL_POLYGON);
            glVertex2f(x, y + window_h);         // Top-left
            glVertex2f(x + window_w, y + window_h); // Top-right
            glVertex2f(x + window_w, y);           // Bottom-right
            glVertex2f(x, y);                      // Bottom-left
        glEnd();
    }
}

glFlush();


    glColor3f(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.0130954629344, 0.1963377300308);
    glVertex2f(0.0925502526955, 0.1970055863402);
    glVertex2f(0.0928720790162, 0.0936993373993);
    glVertex2f(-0.0117214752075, 0.0927338584372);
    glEnd();
    glFlush();

    glColor3f(81.0f / 255.0f, 148.0f / 255.0f, 213.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.8451011343818, -0.1027089536387);
    glVertex2f(0.8471816585857, -0.6024386461898);
    glVertex2f(0.6, -0.6);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(0.8451011343818, -0.1027089536387);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.6012068597155, 0.025865745506);
    glVertex2f(0.6886906756284, 0.0232147207814);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(0.6012068597155, 0.025865745506);
    glVertex2f(0.6886906756284, 0.0232147207814);
    glVertex2f(0.6043762338948, 0.1144522047601);
    glEnd();
    glFlush();

    glColor3f(169.0f / 255.0f, 217.0f / 255.0f, 252.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.6147660467305, 0.0815092203969);
    glVertex2f(0.6144891350063, 0.0558948859148);
    glVertex2f(0.6406572929367, 0.0568640769493);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(0.6189697017817, 0.0514730784566);
    glVertex2f(0.643486520284, 0.0524537511967);
    glVertex2f(0.6425058475439, 0.027119705411);
    glEnd();
    glFlush();

            glBegin(GL_POLYGON);
    glVertex2f(0.6493705567245, 0.0462428238427);
    glVertex2f(0.6487167748978, 0.020418441687);
    glVertex2f(0.6755218297936, 0.020418441687);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(0.6145566744512, 0.0454255965593);
    glVertex2f(0.6137394471678, 0.020418441687);
    glVertex2f(0.64, 0.02);
    glEnd();
    glFlush();

    glColor3f(215.0f / 255.0f, 225.0f / 255.0f, 240.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5960260679108, -0.107807302137);
    glVertex2f(0.5961857285313, -0.1162881019158);
    glVertex2f(0.8525545401926, -0.1181409343944);
    glVertex2f(0.852671513456, -0.1087576200765);
    glEnd();
    glFlush();

        glBegin(GL_POLYGON);
    glVertex2f(0.8523718108624, -0.1616997585895);
    glVertex2f(0.8523718108624, -0.1737369388436);
    glVertex2f(0.594374914083, -0.1761443748944);
    glVertex2f(0.5951773927667, -0.1653109126657);
    glEnd();
    glFlush();

            glBegin(GL_POLYGON);
    glVertex2f(0.5953319520218, -0.2826147770475);
    glVertex2f(0.5953319520218, -0.2954653951543);
    glVertex2f(0.8504405188819, -0.2892780605103);
    glVertex2f(0.8504405188819, -0.2773793400411);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(0.5951754999167, -0.3438123009907);
    glVertex2f(0.8522472554248, -0.3396157812482);
    glVertex2f(0.8523599748165, -0.351476496908);
    glVertex2f(0.5951754999167, -0.3567668719196);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(0.5969124229061, -0.40389372117);
    glVertex2f(0.8487531164369, -0.3982639052691);
    glVertex2f(0.8501673774746, -0.413820776683);
    glVertex2f(0.5972189610092, -0.4176397237161);
    glEnd();
    glFlush();

        glColor3f(136.0f / 255.0f, 212.0f / 255.0f, 232.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.6354722973325, -0.1315621827636);
    glVertex2f(0.897015656109, -0.1304655649071);
    glVertex2f(0.8989173560959, -0.5633880707456);
    glVertex2f(0.6326200837438, -0.56791996416);
    glEnd();
    glFlush();

    // Draw windows
// Window parameters
float buildingLeft = 0.635f;
float buildingRight = 0.897f;
float buildingTop = -0.13f;
float buildingBottom = -0.567f;

// ====== MAIN WINDOWS ====== (smaller, more numerous)
float windowWidth = 0.02f;  // Smaller width for more windows
float windowHeight = 0.03f; // Smaller height
float spacingX = 0.015f;    // Reduced spacing between windows
float spacingY = 0.02f;

int windowColumns = (int)((buildingRight - buildingLeft - spacingX) / (windowWidth + spacingX));
int windowRows = (int)((buildingTop - buildingBottom - spacingY*2) / (windowHeight + spacingY));

float startX = buildingLeft + spacingX;
float startY = buildingTop - spacingY - windowHeight;

// Draw grid of small windows (some lit, some dark)
for (int i = 0; i < windowRows; i++) {
    for (int j = 0; j < windowColumns; j++) {
        float x = startX + j * (windowWidth + spacingX);
        float y = startY - i * (windowHeight + spacingY);

        // Randomly make some windows lit (yellow)
        if (rand() % 4 == 0) {  // 25% chance of being lit
            glColor3f(0.9f, 0.8f, 0.3f); // Yellow (light on)
        } else {
            glColor3f(0.9f, 0.8f, 0.3f);  // Dark blue (light off)
        }

        glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + windowWidth, y);
        glVertex2f(x + windowWidth, y + windowHeight);
        glVertex2f(x, y + windowHeight);
        glEnd();
    }
}
glFlush();

glColor3f(88.0f / 255.0f, 149.0f / 255.0f, 205.0f / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0206957957274, -0.5396522035708);
    glVertex2f(1.0570892329888, -0.5374156211933);
    glVertex2f(1.0570892329888, -0.6559544872019);
    glVertex2f(-1.0497713666352, -0.6492447400693);
    glEnd();
    glFlush();

// Draw the filled polygon (original box)
glColor3f(146.0f / 255.0f, 209.0f / 255.0f, 219.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(1.0423257724835, -0.5624623909192);
    glVertex2f(1.0430201147764, -0.5996354880988);
    glVertex2f(-1.0511492195355, -0.6025103133419);
    glVertex2f(-1.0040618180714, -0.5674476939879);
glEnd();

// Draw the dotted line (diagonal from bottom-left to top-right)
glEnable(GL_LINE_STIPPLE);
glLineStipple(1, 0x00FF);
glColor3f(1.0f, 1.0f, 1.0f); // Black color
glBegin(GL_LINE_STRIP);
    glVertex2f(-1.0055189369873, -0.5838123976263); // Top-left
    glVertex2f(1.0050540172682, -0.5842274341996);  // Bottom-right
glEnd();
glDisable(GL_LINE_STIPPLE);
glFlush();




glColor3f(88.0f / 255.0f, 147.0f / 255.0f, 203.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.7048834688229, -0.2904908334376);
    glVertex2f(-0.639995281781, -0.2912633118548);
    glVertex2f(-0.64, -0.54);
    glVertex2f(-0.70565594724, -0.5407738405992);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.7048834688229, -0.2904908334376);
    glVertex2f(-0.6245457134376, -0.2912633118548);
    glVertex2f(-0.6114135803458, -0.2348723874017);
    glVertex2f(-0.6855715083937, -0.2379623010703);
glEnd();
glFlush();

glColor3f(54.0f / 255.0f, 112.0f / 255.0f, 158.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-0.7365550839267, -0.5392288837649);
    glVertex2f(-0.70565594724, -0.5407738405992);
    glVertex2f(-0.7048834688229, -0.2904908334376);
    glVertex2f(-0.738100040761, -0.2889458766033);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(-0.7048834688229, -0.2904908334376);
    glVertex2f(-0.738100040761, -0.2889458766033);
    glVertex2f(-0.7543220875215, -0.2827660492659);
    glVertex2f(-0.7635918285275, -0.2395072579047);
    glVertex2f(-0.6855715083937, -0.2379623010703);
glEnd();
glFlush();



glColor3f(88.0f / 255.0f, 147.0f / 255.0f, 203.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.5192014641649, -0.5388091470784);
    glVertex2f(0.5840447371727, -0.5412023397535);
    glVertex2f(0.5805273602567, -0.2902650926403);
    glVertex2f(0.5197685464273, -0.2902650926403);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.5197685464273, -0.2902650926403);
    glVertex2f(0.5805273602567, -0.2902650926403);
    glVertex2f(0.5967297106112, -0.2870246225694);
    glVertex2f(0.6129320609657, -0.2319366313641);
    glVertex2f(0.5367810142996, -0.235177101435);
glEnd();
glFlush();

glColor3f(54.0f / 255.0f, 112.0f / 255.0f, 158.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.4834656657879, -0.2897071487693);
    glVertex2f(0.5197685464273, -0.2902650926403);
    glVertex2f(0.5192014641649, -0.5388091470784);
    glVertex2f(0.4891897196425, -0.5387978531615);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.4671109077752, -0.2813537999453);
    glVertex2f(0.4834656657879, -0.2897071487693);
    glVertex2f(0.5197685464273, -0.2902650926403);
    glVertex2f(0.5367810142996, -0.235177101435);
    glVertex2f(0.4565793800448, -0.2359872189527);
glEnd();
glFlush();

glColor3f(69.0f / 255.0f, 128.0f / 255.0f, 184.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(-1.0047646657432, -0.2110509817792);
    glVertex2f(-1.1177426813574, -0.2467472100113);
    glVertex2f(1.1523840967451, -0.2496365264842);
    glVertex2f(1.1499310283231, -0.2106589078957);
glEnd();
glFlush();
    glPopMatrix();
}
void lampTower()
{
    glColor3f(245.0f / 255.0f, 212.0f / 255.0f, 26.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7677558789309, 0.2529325779234);
    glVertex2f(0.7722729543287, 0.24164482977);
    glVertex2f(0.7755373148739, 0.3066253109327);
    glVertex2f(0.7683615314725, 0.291492456408);
    glVertex2f(0.7671502263893, 0.2700927332699);
glEnd();
glFlush();

glColor3f(245.0f / 255.0f, 212.0f / 255.0f, 26.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7755373148739, 0.3066253109327);
    glVertex2f(0.7792856071414, 0.3178208441699);
    glVertex2f(0.781659241027, 0.3075767400321);
    glVertex2f(0.7853975040185, 0.2919049788188);
    glVertex2f(0.7722729543287, 0.24164482977);
glEnd();
glFlush();



glColor3f(245.0f / 255.0f, 212.0f / 255.0f, 26.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7671502263893, 0.2700927332699);
    glVertex2f(0.7683615314725, 0.291492456408);
    glVertex2f(0.7638398347467, 0.261555968426);
glEnd();
glFlush();

glColor3f(124.0f / 255.0f, 118.0f / 255.0f, 60.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7638398347467, 0.261555968426);
    glVertex2f(0.7671502263893, 0.2700927332699);
    glVertex2f(0.7677558789309, 0.2529325779234);
    glVertex2f(0.7664108430674, 0.2424763803619);
    glVertex2f(0.7614041426534, 0.2496481404144);
glEnd();
glFlush();

glColor3f(245.0f / 255.0f, 212.0f / 255.0f, 26.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7677558789309, 0.2529325779234);
    glVertex2f(0.7722729543287, 0.24164482977);
    glVertex2f(0.7664108430674, 0.2424763803619);
glEnd();
glFlush();


glColor3f(233.0f / 255.0f, 195.0f / 255.0f, 10.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7853975040185, 0.2919049788188);
    glVertex2f(0.7856731867369, 0.2704017267857);
    glVertex2f(0.7815146434835, 0.2549957527972);
    glVertex2f(0.7722729543287, 0.24164482977);
glEnd();
glFlush();

glColor3f(245.0f / 255.0f, 212.0f / 255.0f, 26.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7853975040185, 0.2919049788188);
    glVertex2f(0.7856731867369, 0.2704017267857);
    glVertex2f(0.791292585766, 0.2703364956979);
glEnd();
glFlush();

glColor3f(245.0f / 255.0f, 212.0f / 255.0f, 26.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7856731867369, 0.2704017267857);
    glVertex2f(0.791292585766, 0.2703364956979);
    glVertex2f(0.7932034560937, 0.2587143276505);
    glVertex2f(0.789955866636, 0.2533016785543);
    glVertex2f(0.7815146434835, 0.2549957527972);
glEnd();
glFlush();

glColor3f(230.0f / 255.0f, 195.0f / 255.0f, 62.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7815146434835, 0.2549957527972);
    glVertex2f(0.789955866636, 0.2533016785543);
    glVertex2f(0.7940153534581, 0.2468064996389);
    glVertex2f(0.7917149775922, 0.240176004496);
    glVertex2f(0.7787246197613, 0.2370637312657);
    glVertex2f(0.7722729543287, 0.24164482977);
glEnd();
glFlush();

glColor3f(230.0f / 255.0f, 195.0f / 255.0f, 62.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7932034560937, 0.2587143276505);
    glVertex2f(0.7959097806418, 0.2527604136447);
    glVertex2f(0.7940153534581, 0.2468064996389);
    glVertex2f(0.789955866636, 0.2533016785543);
glEnd();
glFlush();


glColor3f(100.0f / 255.0f, 99.0f / 255.0f, 119.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7275547803562, 0.2312075272035);
    glVertex2f(0.7330332179781, 0.2110774540813);
    glVertex2f(0.8140631325711, 0.2089115601378);
    glVertex2f(0.8232363304496, 0.2257290895816);
    glVertex2f(0.7815146434835, 0.2549957527972);
glEnd();
glFlush();


glColor3f(213.0f / 255.0f, 211.0f / 255.0f, 192.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7224150441626, 0.2141577768867);
    glVertex2f(0.7205433529315, 0.2073020197756);
    glVertex2f(0.7820149637371, 0.2336469958351);
    glVertex2f(0.7826653199234, 0.2398974600664);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.7826653199234, 0.2398974600664);
    glVertex2f(0.7820149637371, 0.2336469958351);
    glVertex2f(0.8262065364821, 0.2039026680259);
    glVertex2f(0.8262432749202, 0.2093278498447);
glEnd();
glFlush();

glColor3f(150.0f / 255.0f, 150.0f / 255.0f, 150.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7205433529315, 0.2073020197756);
    glVertex2f(0.7307414081804, 0.1962541265893);
    glVertex2f(0.78, 0.22);
    glVertex2f(0.7820149637371, 0.2336469958351);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.7820149637371, 0.2336469958351);
    glVertex2f(0.78, 0.22);
    glVertex2f(0.8219573467951, 0.1908718196524);
    glVertex2f(0.8262065364821, 0.2039026680259);
glEnd();
glFlush();

glColor3f(105.0f / 255.0f, 105.0f / 255.0f, 105.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.7307414081804, 0.1962541265893);
    glVertex2f(0.75049678806, 0.1838298034692);
    glVertex2f(0.7772727694389, 0.2007285619801);
    glVertex2f(0.78, 0.22);
glEnd();
glFlush();

glBegin(GL_POLYGON);
    glVertex2f(0.78, 0.22);
    glVertex2f(0.7772727694389, 0.2007285619801);
    glVertex2f(0.8025750245143, 0.1837245862605);
    glVertex2f(0.8219573467951, 0.1908718196524);
glEnd();
glFlush();

glColor3f(178.0f / 255.0f, 179.0f / 255.0f, 175.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.75049678806, 0.1838298034692);
    glVertex2f(0.7772727694389, 0.2007285619801);
    glVertex2f(0.7691349045583, -0.5834534971062);
    glVertex2f(0.7196961559906, -0.5812062812623);
glEnd();
glFlush();
glColor3f(241.0f / 255.0f, 241.0f / 255.0f, 240.0f / 255.0f);

glBegin(GL_POLYGON);
    glVertex2f(0.7691349045583, -0.5834534971062);
    glVertex2f(0.818573653126, -0.5857007129502);
    glVertex2f(0.8025750245143, 0.1837245862605);
    glVertex2f(0.7772727694389, 0.2007285619801);
glEnd();
glFlush();

glColor3f(179.0f / 255.0f, 178.0f / 255.0f, 179.0f / 255.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.5718808531534, -0.585900848447);
    glVertex2f(0.5713617910833, -0.6142131595303);
    glVertex2f(0.9445955008777, -0.6131961739451);
    glVertex2f(0.9445955008777, -0.5882800271059);
    glVertex2f(0.7616871397828, -0.5726110007296);
glEnd();
}

void specialKeysScene2(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:  // Increase speed
            speed1 += 0.002f;
            break;
        case GLUT_KEY_LEFT:   // Decrease speed
            speed1 -= 0.002f;
            if (speed1 < 0.0f) speed1 = 0.0f;  // Prevent going backward
            break;
    }
}

void displayScene2()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    showInstructionScreen();
    if (showInstructions) {
        showInstructionScreen();  // Show instructions
    } else {
                  // My main display function (e.g., moving train, bus)


    /**........................................ Sky Section ...........................................**/



sky();

    if (trigger == 1) {
        if (toggle == 0) {
            afterNoonView();        // Call tr()
        } else {
            sky();       // Call tr2()
        }
    }

        /**........................................ city Building ...........................................**/

cityBuilding();

glPushMatrix();
    glTranslatef(trainX, -0.005f, 0.0f);  // Move bus based on busX
train();
glPopMatrix();

drawClouds();


glPushMatrix();
    glTranslatef(busX, 0.05f, 0.0f);  // Move bus based on busX
    bus();
glPopMatrix();


glPushMatrix();
glTranslatef(-busX, 0.0f, 0.0f);     // Move bus along X-axis
glScalef(-1.0f, 1.0f, 1.0f);        // Mirror on X-axis (flip vertically)
bus();                              // Draw the bus
glPopMatrix();

glPushMatrix();
glTranslatef(-busX1, 0.0f, 0.0f);
glScalef(-1.0f, 1.0f, 1.0f);      // Move bus along X-axis
blackBus();
glPopMatrix();

drawTree(0.3704561865567f, -0.635);
drawTree(-0.7261164791055, -0.635);



glPushMatrix();
glTranslatef(0.0f, -0.01f,0.0f);     // Move bus along X-axis
lampTower();                              // Draw the bus
glPopMatrix();



//water
glColor3f(16.0f / 255.0f, 118.0f / 255.0f, 171.0f / 255.0f);
glBegin(GL_POLYGON);
glVertex2f(-1.0775004767049, -0.6469033496693);
glVertex2f(-1.1959550986862, -1.1282827709127);
glColor3f(28.0f / 255.0f, 46.0f / 255.0f, 72.0f / 255.0f);
glVertex2f(0.8631390749045, -1.2895826816958);
glVertex2f(1.2789904073922, -0.6368221052454);
glEnd();
drawSeaWithFullWaves();
    }
glFlush();
glutSwapBuffers();

}

void initScene2() {
    glutReshapeWindow(1080, 720);
    glutSetWindowTitle("Scene 2: Modern Era");
}



/*int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1080, 720);   // Set the window's initial width & height
    glutInitWindowPosition(300, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Sea view"); // Create a window with the given title
    glutDisplayFunc(displayScene2); // Register display callback handler for window re-paint
    glutMouseFunc(handleMouseScene2);
    glutSpecialFunc(specialKeysScene2);
    glutKeyboardFunc(keyboardScene2);
    glutTimerFunc(0, updateScene2, 0);  // Start animation
        glutMainLoop();
    return 0;
}*/
