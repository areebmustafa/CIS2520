
#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedListAPI.h"

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){

  
	List *list = malloc(sizeof(List));
	list->head = NULL;
	list->deleteNode = deleteFunction;
	list->printNode = printFunction;
	list->compare = compareFunction;
    return list;
}
Node *initializeNode(void *data){

	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(node != NULL){

	   return node;
	}
	else{
		return NULL;
	}
}
EmptyList * createEmptyList(void (*printData)(void *toBePrinted)){

	EmptyList *emptyList = malloc(sizeof(EmptyList));
	emptyList->printData = printData;
	emptyList->head = NULL;
	return emptyList;
}


void insertFront(EmptyList *eList, void *toBeAdded){

    if(eList == NULL){
    	return;
    }
	Node *newNode = initializeNode(toBeAdded);

	if(eList->head == NULL){

		eList->head = newNode;
	}
	else{

		newNode->next = eList->head;
		eList->head = newNode;
	}
}
void insertBack(EmptyList *eList, void *toBeAdded){

    if(eList == NULL){
    	return;
    }
	Node *newNode = initializeNode(toBeAdded);

    if(eList->head == NULL){
    	eList->head = newNode;
    }
    else{
    	Node *temp = eList->head;
    	while(temp->next != NULL){
    		temp = temp->next;
    	}
    	temp->next = newNode;
    	newNode->next = NULL;
    }
}
void deleteList(EmptyList *eList){

	Node *itr;

	while(eList->head != NULL){
		itr= eList->head;
		eList->head = eList->head->next;
		free(itr);
    }
}
void printForward(EmptyList *eList){

    if(eList->head == NULL){
    	printf("List is empty\n");
    	return;
    }
	Node *temp = eList->head;

	while(temp != NULL){

		eList->printData(temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void *getFromFront(EmptyList *eList){

	if(eList != NULL && eList->head != NULL){
		return eList->head->data;
	}
	return NULL;
}

void printFunc(void *toBePrinted){

	int num = *(int*)toBePrinted;
	printf("%d ", num);
}

