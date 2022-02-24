/* date = September 29th 2021 0:30 pm */

#ifndef _NODE_H
#define _NODE_H

#endif //_NODE_H

#define INIT_NODE(X) ; Node X = { .mData = 0 , .mNextObj  = NULL , .setData = &setData, .getData = &getData, .setNextObj = &setNextObj, .getNextObj = &getNextObj} 

typedef struct tagNODE {
    
    int mData ; 
    struct tagNODE* mNextObj ; 
    
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