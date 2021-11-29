/* date = September 29th 2021 1:04 pm */

#ifndef _D_NODE_H
#define _D_NODE_H

#endif //_D_NODE_H


typedef struct tagDNODE {
    
    int mData ; 
    struct tagDNODE* mNextObj ;
    struct tagDNODE* mprevObj ;
    
    void (*setData)(struct tagDNODE*, int) ; 
    void (*setNextObj) (struct tagDNODE*, struct tagDNODE*) ; 
    void (*setPrevObj) (struct tagDNODE*, struct tagDNODE*) ; 
    
    
    int (*getData)(struct tagDNODE*) ; 
    struct tagDNODE* (*getNextObj)(struct tagDNODE*);
    struct tagDNODE* (*getPrevObj)(struct tagDNODE*);
    
}DNode, *pDNode ; 