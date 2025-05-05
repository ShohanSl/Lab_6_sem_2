#include <stdio.h>
#include "./headers/taskFuncs.h"
#include "./headers/inputFuncs.h"

void main(){  // Меню
    int command;
    while(1){
        printf("\nMENU\n\nChoose operation:\n\n1 - work with a queue\n2 - work with a dequeue\n0 - exit\n");
        command=positiveIntInput();
        if (command==1) queueCheck();
        else if (command==2) dequeCheck();
        else if (command==0) return;
        else printf("\nInput error. Please try again\n");
    }
}
