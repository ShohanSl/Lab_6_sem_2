#ifndef QUEFUNCS_H
#define QUEFUNCS_H

typedef struct queElement{
    int data;
    struct queElement *next;
}QUEELEMENT;

void addToQue();

void seeQue();

void deleteQueElement();

void addToQueNoInput();

void checkFirstElement();

void clearQueue();

#endif