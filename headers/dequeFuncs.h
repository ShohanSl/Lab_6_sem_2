#ifndef DEUEFUNCS_H
#define DEUEFUNCS_H

typedef struct DequeElement {
    int data;
    struct DequeElement *next;
    struct DequeElement *prev;
} DEQUELEMENT;

void pushBack();

void pushFront();

void popBack();

void popFront();

void seeDeque();

void clearDeque();

int getFront();

void pushBackNoInput();

void checkFirstDequeElement();

#endif