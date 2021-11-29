/* date = September 29th 2021 0:30 pm */

#ifndef _NODE_H
#define _NODE_H

#endif //_NODE_H

#define INIT_NODE (X) Node X = { .mData = 0 , .mNextObj  = NULL}

typedef struct tagNODE {
    
    int mData ; 
    struct tagNODE* mNextObj ; 
    
    void (*setData)(struct tagNODE*,int) ; 
    void (*setNextObj) (struct tagNODE*, struct tagNODE*) ; 
    
    
    int (*getData)(struct tagNODE*) ; 
    struct tagNODE* (*getNextObj)(struct tagNODE*);
    
}Node, *pNode ; 

void setData(struct tagNODE* nodeObj ,int data){
    nodeObj->mData = data ; 
}

void setNextObj(struct tagNODE* nodeObj, struct tagNODE* nextNodeObj) {
    nodeObj->mNextObj = nextNodeObj ; 
}

int getData(struct tagNODE* nodeObj){
    return nodeObj->mData ; 
} 

struct tagNODE* getNextObj(struct tagNODE* nodeObj){
    return nodeObj->mNextObj ; 
}