#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SinglyLinkedListAPI.h"
           


int main(void){

    
    EmptyList *eList = createEmptyList(printFunc);
    
    int *num = NULL;
    int i = 0;
    if(eList == NULL){
        return 1;
    } 
   printf("List being inserted to the front\n");


  for(i = 1;i<=3;i++){

    num = malloc(sizeof(int));
    *num = i;
    insertFront(eList,num);
    
  }
  printForward(eList);

  printf("Deleting the list\n");
  deleteList(eList);
  printf("Printing out list: \n");
  printForward(eList);
  
  printf("\n");
  printf("List being inserted to the back\n");

  
  for(i = 1;i<=3;i++){

    num = malloc(sizeof(int));
    *num = i;
    insertBack(eList,num);
    
  }
  printForward(eList);

  printf("Deleting the list\n");
  deleteList(eList);
  printf("Printing out list: \n");
  printForward(eList);

  printf("\n");
  printf("Testing getFromFront function\n");
  for(i = 1;i<=3;i++){

    num = malloc(sizeof(int));
    *num = i;
    insertBack(eList,num);
    
  }
  printForward(eList);
  int *ptr;
  ptr = getFromFront(eList);
  printf("The front integer is: %d\n",*ptr );

	return EXIT_SUCCESS;
    
}



