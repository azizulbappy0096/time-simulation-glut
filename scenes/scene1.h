#ifndef SCENE1_H
#define SCENE1_H

void updateTimerScene1(int value);
void volcanoEruptionTimerScene1(int value);

void keyboardHandlerScene1(unsigned char key, int x, int y);
void mouseHandlerScene1(int button, int state, int x, int y);
void mouseMotionHandlerScene1(int x, int y);

void displayScene1();
void initScene1();

#endif