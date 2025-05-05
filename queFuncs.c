#include <stdio.h>
#include <stdlib.h>
#include "./headers/queFuncs.h"
#include "./headers/inputFuncs.h"

void addToQue(QUEELEMENT **queBack, int queMaxLength, int *queCurLenght){  // Добавление элемента
    if (*queCurLenght==queMaxLength){
        printf ("\nThe queue is full\n");
        return;
    }
    QUEELEMENT *newElement;
    newElement=(QUEELEMENT*)calloc(1, sizeof(QUEELEMENT));
    if (newElement==NULL){
        printf("\nMEMORY ALLOCATION ERROR\n");
        return;
    }
    printf("\nInput the element:\n");
    newElement->data=intInput();
    if (*queBack==NULL) *queBack=newElement;
    else{
        newElement->next=*queBack;
        *queBack=newElement;
    }
    (*queCurLenght)++;
    printf("\n'%d' is added to the queue\n", (*queBack)->data);
}

void seeQue(QUEELEMENT *queBack){  // Просмотр очереди
    if (queBack==NULL){
        printf("\nThe queue is empty\n");
        return;
    }
    printf("\nQueue contents:\n\n");
    while (queBack){
        printf("%d\n", queBack->data);
        queBack=queBack->next;
    }
    return;
}

void deleteQueElement(QUEELEMENT **queBack, int *queCurLength){  // Удаление из очереди
    if (*queCurLength==0){
        printf("\nThe queue is empty\n");
        return;
    }
    else if (*queCurLength==1){
        free(*queBack);
        *queBack=NULL;
        (*queCurLength)--;
        return;
    }
    QUEELEMENT *curElement;
    curElement=*queBack;
    while (curElement->next->next != NULL) {
        curElement = curElement->next;
    }
    free(curElement->next);
    curElement->next=NULL;
    (*queCurLength)--;
    printf("\nThe first element has been deleted\n");
    return;
}

void addToQueNoInput(QUEELEMENT **queBack, int *queMaxLength, int *queCurLenght, int newData){  // Добавление введенного элемента
    QUEELEMENT *newElement;
    newElement=(QUEELEMENT*)calloc(1, sizeof(QUEELEMENT));
    if (newElement==NULL){
        printf("\nMEMORY ALLOCATION ERROR\n");
        return;
    }
    newElement->data=newData;
    if (*queBack==NULL) *queBack=newElement;
    else{
        newElement->next=*queBack;
        *queBack=newElement;
    }
    (*queCurLenght)++;
    (*queMaxLength)++;
    printf("\n'%d' is added to the queue\n", newData);
}

void checkFirstElement(QUEELEMENT **queBack, int *queMaxLength, int *queCurLength){  // Сравнение первого элемента с введенным
    if (*queCurLength==0){
        printf("\nThe queue is empty\n");
        return;
    }
    int newData;
    printf("\nEnter an integer:\n");
    newData=intInput();
    if (*queCurLength==1){
        if ((*queBack)->data==newData){
            printf("\nThe first element of queue is '%d'\n", newData);
            return;
        }
        else{
            addToQueNoInput(queBack, queMaxLength, queCurLength, newData);
            return;
        }
    }
    QUEELEMENT *curElement;
    curElement=*queBack;
    while (curElement->next != NULL) {
        curElement = curElement->next;
    }
    if (curElement->data==newData){
        printf("\nThe first element of queue is '%d'\n", newData);
        return;
    }
    else{
        addToQueNoInput(queBack, queMaxLength, queCurLength, newData);
        return;
    }
}

void clearQueue(QUEELEMENT **queBack, int *queCurLength) {  // Очистка очереди
    if (*queBack == NULL) return;
    QUEELEMENT *current = *queBack, *nextElement;
    while (current != NULL) {
        nextElement = current->next;
        free(current);
        current = nextElement;
    }
}
