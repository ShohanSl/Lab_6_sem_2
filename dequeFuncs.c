#include <stdio.h>
#include <stdlib.h>
#include "./headers/dequeFuncs.h"
#include "./headers/inputFuncs.h"

void pushBack(DEQUELEMENT **deque, int maxLength, int *curLength) {  // Добавление в конец
    if (*curLength == maxLength) {
        printf("\nDeque is full\n");
        return;
    }
    DEQUELEMENT *newElem = (DEQUELEMENT*)calloc(1, sizeof(DEQUELEMENT));
    if (!newElem) {
        printf("\nMEMORY ALLOCATION ERROR\n");
        return;
    }
    printf("\nInput the element:\n");
    newElem->data = intInput();
    newElem->next = *deque;
    newElem->prev = NULL;
    
    if (*deque) {
        (*deque)->prev = newElem;
    }
    
    *deque = newElem;
    (*curLength)++;
    printf("\n'%d' added to back\n", newElem->data);
}

void pushFront(DEQUELEMENT **deque, int maxLength, int *curLength) {  // Добавление в начало
    if (*curLength == maxLength) {
        printf("\nDeque is full\n");
        return;
    }
    DEQUELEMENT *newElem = (DEQUELEMENT*)calloc(1, sizeof(DEQUELEMENT));
    if (!newElem) {
        printf("\nMEMORY ALLOCATION ERROR\n");
        return;
    }
    printf("\nInput the element:\n");
    newElem->data = intInput();
    newElem->next = NULL;
    if (!*deque) {
        newElem->prev = NULL;
        *deque = newElem;
    } else {
        DEQUELEMENT *last = *deque;
        while (last->next) {
            last = last->next;
        }
        last->next = newElem;
        newElem->prev = last;
    }
    (*curLength)++;
    printf("\n'%d' added to front\n", newElem->data);
}

void popBack(DEQUELEMENT **deque, int *curLength) {  // Удаление с конца
    if (*curLength == 0) {
        printf("\nDeque is empty\n");
        return;
    }
    DEQUELEMENT *temp = *deque;
    *deque = (*deque)->next;
    if (*deque) {
        (*deque)->prev = NULL;
    }
    printf("\n'%d' removed from back\n", temp->data);
    free(temp);
    (*curLength)--;
}

void popFront(DEQUELEMENT **deque, int *curLength) {  // Удаление с начала
    if (*curLength == 0) {
        printf("\nDeque is empty\n");
        return;
    }
    DEQUELEMENT *last = *deque;
    while (last->next) {
        last = last->next;
    }
    if (last->prev) {
        last->prev->next = NULL;
    } else {
        *deque = NULL;
    }
    printf("\n'%d' removed from front\n", last->data);
    free(last);
    (*curLength)--;
}

void seeDeque(DEQUELEMENT *deque) {  // Просмотр дека
    if (!deque) {
        printf("\nDeque is empty\n");
        return;
    }
    printf("\nDeque contents:\n");
    while (deque) {
        printf("%d\n", deque->data);
        deque = deque->next;
    }
    printf("\n");
}

void clearDeque(DEQUELEMENT **deque, int *curLength) {  // Очистка дека
    if (!*deque) {
        printf("\nDeque is already empty\n");
        return;
    }
    DEQUELEMENT *current = *deque;
    while (current) {
        DEQUELEMENT *next = current->next;
        free(current);
        current = next;
    }
    *deque = NULL;
    *curLength = 0;
    printf("\nDeque cleared\n");
}

int getFront(DEQUELEMENT *deque) {  // Считывание элемента из начала
    while (deque->next) {
        deque = deque->next;
    }
    return deque->data;
}

void pushBackNoInput(DEQUELEMENT **deque, int *maxLength, int *curLength, int data){  // Добавление введенного элемента в конец
    DEQUELEMENT *newElem = (DEQUELEMENT*)calloc(1, sizeof(DEQUELEMENT));
    if (!newElem) {
        printf("\nMEMORY ALLOCATION ERROR\n");
        return;
    }
    newElem->data = data;
    newElem->next = *deque;
    newElem->prev = NULL;
    
    if (*deque) {
        (*deque)->prev = newElem;
    }
    
    *deque = newElem;
    (*curLength)++;
    (*maxLength)++;
    printf("\n'%d' added to back\n", newElem->data);
}

void checkFirstDequeElement(DEQUELEMENT **deque, int *maxLength, int *curLength){  // Сравнение введенного элемента и первого в списке
    if (*curLength == 0) {
        printf("\nDeque is empty\n");
        return;
    }
    int checkData;
    printf("\nEnter an integer:\n");
    checkData=intInput();
    if (getFront((*deque))==checkData){
        printf("\nThe first element of queue is '%d'\n", checkData);
    }
    else pushBackNoInput(deque, maxLength, curLength, checkData);
}
