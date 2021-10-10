#include "csl102_lab6.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE_STACK 1024
#define TRUE 1
#define FALSE 0

nodeQ_t* stack[MAX_SIZE_STACK] = {0};
short tos = -1;

void push(nodeQ_t* p_nd){
    if(MAX_SIZE_STACK == tos + 1) return;
    stack[++tos] = p_nd;
    //printf("%d\n", p_nd->data);
}

unsigned short isEmpty(){
    if(-1 == tos)
        return TRUE;

    return FALSE;
}

nodeQ_t* pop(){
    if(FALSE == isEmpty()) return stack[tos--];
    return EMPTYNODE;
}

nodeQ_t* peek(){
    if(FALSE == isEmpty()) return stack[tos];
    return EMPTYNODE;
}


void getInorder(nodeQ_t* node, short **out_array, short *out_size){
 
    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;
    tos = -1;

    nodeQ_t* curr = node;
    short counter = 0;
 
    while(TRUE){
        if(EMPTYNODE != curr){
            push(curr);                                              
            curr = curr->left; 
        }    
        else{
            curr = pop();
            if(EMPTYNODE != curr){
                (*out_array)[counter++] = curr->data;
                // this will work too: *(*out_array + counter) = curr->data;
                // this will not work: *out_array[counter]
                curr = curr->right;
            }
            else{
                *out_size = counter;
                tos = -1;
                return;
            }
        }
    } 
}

void getPreorder(nodeQ_t* node, short **out_array, short *out_size){

    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;

    tos = -1;
    short counter = 0;

    nodeQ_t* curr = node;
    push(curr);

    while(TRUE){

        if(TRUE == isEmpty()){
            *out_size = counter;
            tos = -1;
            return;
        }

        curr = pop();
        if(EMPTYNODE != curr){
            (*out_array)[counter++] = curr->data;
            // this will work too: *(*out_array + counter) = curr->data;
            // this will not work: *out_array[counter]
        }        

        if(EMPTYNODE != curr->right) push(curr->right);
        if(EMPTYNODE != curr->left) push(curr->left);
    }

    return;
}

void getPostorder(nodeQ_t* node, short **out_array, short *out_size){
    
    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;

    tos = -1;
    short counter = 0;
    nodeQ_t* curr = node;

    while(TRUE){ 

        while (EMPTYNODE != curr){
            if (EMPTYNODE != curr->right) push(curr->right);
            push(curr);
            curr = curr->left;
         }

         curr = pop();

        if(EMPTYNODE == curr){ 
            // this case should not happen ideally
            *out_size = counter;
            tos = -1;
            return;
        } 

        if(EMPTYNODE != curr->right && peek() == curr->right){
            pop();
            push(curr);
            curr = curr->right;
        }
        else{
            (*out_array)[counter++] = curr->data;
            // this will work too: *(*out_array + counter) = curr->data;
            // this will not work: *out_array[counter]
            curr = EMPTYNODE;
        }

        if(TRUE == isEmpty()){
            *out_size = counter;
            tos = -1;
            return;
        }
      } 
}