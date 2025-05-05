#include <stdio.h>
#include "./headers/taskFuncs.h"
#include "./headers/queFuncs.h"
#include "./headers/inputFuncs.h"
#include "./headers/dequeFuncs.h"

void queueCheck(){  // Первое задание
    QUEELEMENT *queBack=NULL;
    int command, queMaxLength, queCurLength=0;
    printf("\nInput queue length:\n");
    queMaxLength=positiveIntInput();
    while(1){
        printf("\nQUEUE MENU\n\nChoose operation:\n\n1 - add an element to the queue\
\n2 - delete the first element in the queue\
\n3 - see the queue contents\
\n4 - compare the first element with the inputed one\
\n0 - exit\n");
        command=positiveIntInput();
        if (command==1) addToQue(&queBack, queMaxLength, &queCurLength);
        else if (command==2) deleteQueElement(&queBack, &queCurLength);
        else if (command==3) seeQue(queBack);
        else if (command==4) checkFirstElement(&queBack, &queMaxLength, &queCurLength);
        else if (command==0){
            clearQueue(&queBack, &queCurLength);
            return;
        }
        else printf("\nInput error. Please try again\n");
    }
}

void dequeCheck() {  // Второе задание
    DEQUELEMENT *dequeBack = NULL;
    int command, dequeMaxLength, dequeCurLength = 0;
    printf("\nInput deque length:\n");
    dequeMaxLength = positiveIntInput();
    while(1) {
        printf("\nDEQUE MENU\n\nChoose operation:\
\n1 - Add element to back\
\n2 - Add element to front\
\n3 - Remove element from back\
\n4 - Remove element from front\
\n5 - Display deque contents\
\n6 - Compare front element with the inputed one\
\n0 - Exit\n");
        command = positiveIntInput();
        if (command==1) pushBack(&dequeBack, dequeMaxLength, &dequeCurLength);
        else if (command==2) pushFront(&dequeBack, dequeMaxLength, &dequeCurLength);
        else if (command==3) popBack(&dequeBack, &dequeCurLength);
        else if (command==4) popFront(&dequeBack, &dequeCurLength);
        else if (command==5) seeDeque(dequeBack);
        else if (command==6) checkFirstDequeElement(&dequeBack, &dequeMaxLength, &dequeCurLength);
        else if (command==0){
            clearDeque(&dequeBack, &dequeCurLength);
            return;
        }
        else printf("\nInput error. Please try again\n");
    }
}

