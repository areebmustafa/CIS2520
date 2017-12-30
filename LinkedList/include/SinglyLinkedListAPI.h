
/**
 * @file SinglyLinkedListAPI.h
 * @author Michael Ellis
 * @modified Areeb Mustafa
 * @date December 2017
 * @brief File containing the function definitions of a singly linked list
 */
#ifndef SINGLYLINKEDLISHAPI_H
#define SINGLYLINKEDLISHAPI_H

/**
*Node of a singly linked list. This list is singly linked, meaning that it has points to the node immediately in front 
of it only.
**/
typedef struct Node{
   void *data;
   struct Node *next;
  
}Node;

/**
 *Dummy head of the list. Contains no actual data on it beyond a pointer to the front of the list.
 **/
typedef struct EmptyList{

    Node *head;
    void (*printData)(void *toBePrinted);

}EmptyList;
/**
 *Dummy head of the list. Contains no actual data on it beyond a pointer to the front of the list. 
 *Also include function pointers for 
 **/
typedef struct List{

   Node *head;
   void (*deleteNode)(void *toBeDeleted);
   int (*compare)(const void *first,const void *second);
   void (*printNode)(void *toBePrinted);
}List;

/*
*Function to point the list head to the appropriate functions. Allocates memory to the struct.
@param printFunction function pointer to print a single node of the list
*@return pointer to the EmptyList head
*/
EmptyList * createEmptyList(void (*printData)(void *toBePrinted));

/**Function to point the list head to the appropriate functions. Allocates memory to the struct.
*@return pointer to the list head
*@param printFunction function pointer to print a single node of the list
*@param deleteFunction function pointer to delete a single piece of data from the list
*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order
**/
List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

/**Function for creating a node for a linked list. This node contains generic data and may be connected to 
other notes in a list.
*@pre data should be of same size of void pointer on the users machine to avoid size conflicts. data must be valid.
*data must be cast to void pointer before being added.
*@post data is valid to be added to a linked list
*@return On success returns a node that can be added to a linked list. On failure, returns NULL.
*@param data - is a generic pointer to any data type.
**/
Node *initializeNode(void *data);

/**Inserts a Node to the front of a linked list. The list then updates accordingly to adhere to the ADT.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the dummy head of the list
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertFront(EmptyList *eList, void *toBeAdded);

/**Inserts a Node to the back of a linked list. The list then updates accordingly to adhere to the ADT.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the dummy head of the list
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertBack(EmptyList *eList, void *toBeAdded);

/** Deletes the entire linked list head to tail, starting with the nodes, followed by the list itself.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the List-type dummy node
**/
void deleteList(EmptyList *eList);


/**Function to print list from head to tail. This will utilize the list's printNode function pointer to print.
 *@pre List must exist, but does not have to have elements.
 *@param list Pointer to linked list dummy head.
 **/
void printForward(EmptyList *eList);

/**Function to return the data at the front of the list.
 *@pre The list exists and has memory allocated to it
 *@param list pointer to the dummy head of the list containing the head of the list
 *@return pointer to the data located at the head of the list
 **/
void *getFromFront(EmptyList *eList);

void printFunc(void *toBePrinted);
#endif

