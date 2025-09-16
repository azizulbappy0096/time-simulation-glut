#include <windows.h>
#include <GL/glut.h>

#include "scenes/scene1.h"
#include "scenes/scene2.h"
#include "scenes/scene3.h"
#include "scenes/scene4.h"

int currentScene = 1;

void init() {
    switch(currentScene) {
        case 1:
            initScene1();
            break;
        case 2:
            initScene2();
            break;
        case 3:
            initScene3();
            break;
        case 4:
            initScene4();
            break;
        default:
            break;
    }

}

void keyBoardHandler(unsigned char key, int x, int y) {
    switch(key) {
        case '1':
            glutDisplayFunc(displayScene1);
            currentScene = 1;
            init();
            break;
        case '2':
            glutDisplayFunc(displayScene2);
            currentScene = 2;
            init();
            break;
        case '3':
            glutDisplayFunc(displayScene3);
            currentScene = 3;
            init();
            break;
        case '4':
            glutDisplayFunc(displayScene4);
            currentScene = 4;
            init();
            break;
        default:
            break;
    }

    switch (currentScene) {
        case 1:
            keyboardHandlerScene1(key, x, y);
            break;
        case 2:
            keyboardScene2(key, x, y);
            break;
        case 3:
            handleKeypressScene3(key, x, y);
            break;
        case 4:
            handleKeypressScene4(key, x, y);
            break;
        default:
            break;
    }

    glutPostRedisplay();
}

void specialKeyHandler(int key, int x, int y) {
    if (currentScene == 2) {
        specialKeysScene2(key, x, y);
        glutPostRedisplay();
    }
}

void mouseHandler(int button, int state, int x, int y) {
    switch(currentScene) {
        case 1:
            mouseHandlerScene1(button, state, x, y);
            break;
        case 2:
            handleMouseScene2(button, state, x, y);
            break;
        case 3:
            handleMouseScene3(button, state, x, y);
            break;
        case 4:
            mouseScene4(button, state, x, y);
            break;
        default:
            break;
    }

    glutPostRedisplay();
}

void mouseMotionHandler(int x, int y) {
    switch(currentScene) {
        case 1:
            mouseMotionHandlerScene1(x, y);
            break;
        default:
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200, 800);
    glutCreateWindow("Time Travel Simulator");

    init();
	glutDisplayFunc(displayScene1);

    // scene 1 timer functions
    glutTimerFunc(25, updateTimerScene1, 0);
    glutTimerFunc(5000, volcanoEruptionTimerScene1, 0);

    // scene 2 timer function
    glutTimerFunc(0, updateScene2, 0);

    // scene 3 timer functions
    glutTimerFunc(25, train_animationScene3, 0);
    glutTimerFunc(25, cars_animationScene3, 0);
    glutTimerFunc(25, clouds_animationScene3, 0);

    // scene 4 timer & idle function
    glutTimerFunc(20, timerScene4, 0);
    glutTimerFunc(10, CarScene4, 0);
    glutIdleFunc(idleScene4);

    glutKeyboardFunc(keyBoardHandler);
    glutSpecialFunc(specialKeyHandler);
    glutMouseFunc(mouseHandler);
    glutPassiveMotionFunc(mouseMotionHandler);

    glutMainLoop();
    return 0;
}
