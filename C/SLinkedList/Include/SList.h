/* date = September 29th 2021 11:48 am */

#ifndef _S_LIST_H
#define _S_LIST_H

#endif //_S_LIST_H

#include "Node.h"
#include <stdio.h> 
#include <stdlib.h> 


// Must use this to create a Linked List object.
#define INIT_SLIST(X) ; List X = { .mHead = NULL, .mTail = NULL , .mSize = 0}

typedef struct tagLINKEDLIST {
    
    pNode mHead ; 
    pNode mTail ; 
    int mSize ; 
    
    // function pointers 
    
}List, *pList;

pNode iterateList(struct tagLINKEDLIST* self){
    pNode temp = self->mHead ;
    if(self->mHead == NULL || self->mHead->mNextObj == NULL)
        return temp ;
    else
        for(; temp != self->mTail ; temp = temp->mNextObj);
    return temp ; 
}

pNode getHead(struct tagLINKEDLIST* self){
    return self->mHead ; 
}

pNode getTail(struct tagLINKEDLIST* self){
    return self->mTail ; 
}

void addToHead(struct tagLINKEDLIST* self, int data){
    pNode temp = NULL ; 
    if(getHead(self) == NULL && getTail(self) == NULL){
        
        temp = (pNode) malloc(sizeof(Node)) ;
        setData(temp , data);
        setNextObj(temp , NULL);
        self->mHead = self->mTail = temp ;
        self->mSize = 1;
        
    }
    else{
        
        temp = (pNode) malloc(sizeof(Node));
        setData(temp , data);
        setNextObj(temp,self->mHead);
        self->mHead = temp ;
        self->mSize++ ; 
    }
}

void addToTail(struct tagLINKEDLIST* self, int data){
    pNode temp = NULL ; 
    if(getHead(self) == NULL && getTail(self) == NULL){
        
        temp = (pNode) malloc(sizeof(Node));
        setData(temp, data) ; 
        setNextObj(temp , NULL); 
        self->mHead = self->mTail = temp ;
        self->mSize = 1 ; 
        
    }else{
        
        temp = (pNode) malloc(sizeof(Node)) ; 
        setData(temp , data);
        setNextObj(self->mTail, temp); 
        self->mTail = temp ;
        setNextObj(temp ,NULL);
        self->mSize++;
    }
}

int* deleteFromHead(struct tagLINKEDLIST* self){
    if (getHead(self) == NULL && getTail(self) == NULL)
        return NULL ;
    
    int* t_data = NULL ; 
    if(getNextObj(getHead(self)) == NULL && getHead(self) == getTail(self)){
        
        t_data = (int*) malloc (sizeof(int)) ; 
        *t_data = self->mHead->mData ; 
        free(self->mHead);
        self->mHead = self->mTail = NULL ; 
        self->mSize = 0 ;
        
    }else{
        
        t_data = (int*) malloc (sizeof(int));
        pNode temp = self->mHead->mNextObj ; 
        *t_data = getData(self->mHead) ; 
        free(self->mHead);
        self->mHead = temp ; 
        self->mSize-- ; 
    }
    
    return t_data ; 
}

int* deleteFromTail(struct tagLINKEDLIST* self){
    int* t_data = NULL ;
    
    if (getTail(self) == NULL)
        return t_data ;
    
    if(getNextObj(getHead(self)) == NULL && getHead(self) == getTail(self)){
        
        t_data = (int*) malloc (sizeof(int)) ; 
        *t_data = getData(getHead(self)) ; 
        free(getHead(self));
        self->mHead = self->mTail = NULL ; 
        self->mSize = 0 ;
        
    }else{
        
        t_data = (int*) malloc (sizeof(int));
        pNode temp = NULL ; 
        
        for(temp = getHead(self)  ; temp->mNextObj  != getTail(self) ; temp =  getNextObj(temp));
        
        *t_data = getData(getTail(self)); 
        free(getNextObj(temp));
        self->mTail = temp ;
        setNextObj(getTail(self), NULL);
        self->mSize-- ; 
    }
    
    return t_data ; 
}

pNode searchNode(struct tagLINKEDLIST* self, int q_data){
    
    pNode temp = NULL ; 
    if(getHead(self) == NULL )
        return temp ;
    
    for(temp = getHead(self) ; temp  != NULL ; temp = getNextObj(temp)){
        if(getData(temp) == q_data)
            return temp;
    }
    
    return temp ; 
}

int* deleteNode(struct tagLINKEDLIST* self, int q_data){
    int* t_data = NULL ; 
    
    if(getHead(self) == NULL)
        return t_data ; 
    
    pNode d_temp = searchNode(self, q_data);
    
    if(d_temp == NULL){
        return t_data ; 
    }
    else if(d_temp == getHead(self)){
        
        t_data = deleteFromHead(self);
        return t_data ;
        
    }else if(d_temp == getTail(self)){
        
        t_data = deleteFromTail(self) ; 
        return t_data ;
        
    }else{
        
        pNode temp = NULL ; 
        for(temp = getHead(self); getNextObj(temp) != d_temp; temp = getNextObj(temp));
        t_data = (int*) malloc(sizeof(int));
        setNextObj(temp,getNextObj(d_temp));
        *t_data = getData(d_temp);
        free(d_temp) ;
        return t_data ; 
    }
}

pNode getMiddle(pNode node ){
    
    if(node  == NULL || getNextObj(node))
        return node ; 
    
    pNode ptr_fast = NULL ; 
    pNode ptr_slow = NULL ; 
    
    ptr_fast = ptr_slow  = node  ;
    
    while(getNextObj(ptr_slow) != NULL && getNextObj(getNextObj(ptr_fast)) != NULL){
        ptr_fast = getNextObj(getNextObj(ptr_fast)) ; 
        ptr_slow = getNextObj(ptr_slow); 
    }
    
    return ptr_slow ; 
}

pNode sortedMerge(struct tagLINKEDLIST* self, pNode fNode, pNode sNode){
    
    if(fNode = NULL)
        return sNode ; 
    if(sNode = NULL)
        return fNode ; 
    
    pNode sortedList = NULL ; 
    
    if(getData(fNode) <= getData(sNode)){
        sortedList = sNode ; 
        self->mTail = fNode ; 
        setNextObj(sNode,sortedMerge(self, getNextObj(fNode), sNode)) ; 
        self->mHead = sNode ; 
    }else{
        sortedList = fNode ; 
        self->mTail = sNode ; 
        setNextObj(fNode,sortedMerge(self, getNextObj(sNode), fNode)) ; 
        self->mHead = fNode ; 
    }
    
    return sortedList ; 
}

pNode MergeSort(struct tagLINKEDLIST* self, pNode node ){
    
    if(node  == NULL)
        return node  ; 
    
    pNode middle = getMiddle(node) ; 
    pNode next_Middle  = getNextObj(middle) ; 
    
    setNextObj(middle, NULL) ; 
    
    pNode lNode = MergeSort(self, node) ; 
    pNode rNode = MergeSort(self, next_Middle);
    
    pNode sortedList = sortedMerge(self, lNode, rNode);
    return sortedList ; 
}

int getSize( struct tagLINKEDLIST* self){
    return self->mSize;
}

void displayList(struct tagLINKEDLIST* self){
    for(pNode temp = self->mHead; temp != NULL ; temp = temp->mNextObj){
        printf("element : %d ,",temp->mData);
        printf("next node: %p ;", temp->mNextObj);
        printf("\n");
        printf("\n");
        
    }
}