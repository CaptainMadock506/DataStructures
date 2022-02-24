/* date = February 23rd 2022 0:48 pm */

#ifndef _SLIST_H
#define _SLIST_H

#endif //_SLIST_H
#include <cstddef> 

/*

functionName:-

Usage:-

Return type:-

caution:-

*/
namespace DataStruct{
    
    template <typename T>
        class SList{
        
        private :
        
        template <typename U>
            class Node{
            private :
            U mData ; 
            Node* mNextObj ;
            
            // public class constructor
            public : 
            
            Node();
            Node(const U& data, Node* nextObj = nullptr);
            Node(const Node& source); //copy constructor
            ~Node() noexcept;
            
            // public member functions
            public : 
            
            // getter member function
            U getData() const ; 
            Node* getNextObj() const ; 
            
            // setter member function
            void setData(const U& data);
            void setNextObj(Node* nextObj); 
            
            // operator overloading
            bool operator ==(const Node& operand) ; 
            Node& operator = (const Node& source) ;
            
            // swap functionality
            void swap(const Node& nodeObj) ; 
            
        } Node, pNode*;
        
        private:
        
        pNode<T> mHead ; 
        pNode<T> mTail ; 
        std::size_t mSize ;
        
        // public class constructor
        public: 
        
        SList();
        SList(const T& data, pNode nextObj = nullptr);
        SList(const SList& source); //copy constructor
        ~SList() noexcept;
        
        // public memeber functions
        public: 
        
        // setter memeber functions
        void add(const T& data, bool head_flag = false);
        void add(const T& data, const int& index);
        T* remove(bool head_flag = false);
        T* remove(const int& element);
        T* removeAt(const int& index);
        pNode sort(pNode node);
        pNode getItem(cosnt int& index);
        pNode search(const int& element);
        
        // swap fucntionality
        void swap(const SList& listObj);
        
        // getter member functions
        std::size_t getLength() const ; 
        
        // Operator overloading
        bool operator ==(const SList& operand);
        SList& operator =(const SList& source) ; 
        SList& operator +=(const SList& operand);
        SList& operator -=(const SList& operand); 
        
        
        // private member functions
        private:
        
        // functions for adding and removing from the head
        void addToHead(const T& data);
        void addToTail(const T& data);
        T* deleteFromHead();
        T* deleteFromTail();
        
        // fucntion to seacrh the Linked List and to delete a spacific object
        pNode searchItem(const T& element);
        T* deleteItem(const T& element);
        
        //algorithm for sorting a Linked List
        pNode getMiddle(pNode nodeObj);
        pNode sortedMerge(pNode lNode, pNode rNode);
        pNode MergeSort(pNode nodeObj);
        
        //algorith to iterate the Linked List
        pNode iterateLinkedList();
        
    };
    
    /*------------------Defination for Node class------------------------*/
    
    /*
    
    functionName:- (constructor) Node
    
    Usage:- Initialize the Node object to => {mData = 0, mNextObj = nullptr}
    
    Return type:- NONE
    
    caution:- NONE
    
    */
    
    template <typename T>
        SList<T>::Node<T>::Node():mData(),mNextObj(){}
    
    /*

functionName:- (Overloaded Constructor) Node 

Usage:- Initialize the Node object to the parameters passed to the constructor

=> {mData = data, mNextObj = nextObj}

Return type:- NONE

caution:- This function doesn't copy the node object it just points to the NodeObj passed to it.

*/
    
    template <typename T> 
        SList<T>::Node<T>::Node(const T& data, pNode nextObj):mData(data),mNextObj(nextObj){}
    
    /*

functionName:- (Overloaded Copy constructor) Node 

Usage:- Copy Node objtects till nullptr.

Return type:- NONE

caution:- Generates a complete copy of the Node object source passed.

*/
    
    template <typename T>
        SList<T>::Node<T>::Node(const Node& source):mData(),mNextObj(){
        
        // Sets the mData field of the this node object to the mData field 
        // of the source mData field .
        this->mData = source->getData();
        
        /*
1. The temp pointer is made to point at this object mNextObj field and 
curr pointer is made to point at source object mNextObj field.

2.A new node object is allocated in the memory and its mData field is 
initialized with the mData field of the currnet node object of source
node object.

*/
        
        for(pNode temp = this->mNextObj, curr = source->getNextObj(); cur->getNextObj() != nullptr; curr->setNextObj(curr->getNextObj)){
            
            temp = new Node(curr->getData());
            temp->setNextObj(temp->getNextObj());
            
        }
        
    }
    
    /*

functionName:- (Destructor) ~Node

Usage:- Destructor

Return type:- NONE

caution:- NONE

*/
    
    template <typename T>
        SList<T>::Node<T>::~Node() noexcept{
        
        this->mData = 0;
        this->mNextObj = nullptr;
    }
    
    /*

functionName:- getData

Usage:- It returns the mData field of the node object.

Return type:- User Defined T datatype

caution:- NONE

*/
    
    template <typename T>
        T SList<T>::Node<T>::getData() const{
        
        return this->mData; 
    }
    
    /*

functionName:- getNextObj

Usage:- returns the mNextObj data field of the Node object

Return type:- SList subclass pNode (pointer to a Node object)

caution:- NONE

*/
    
    template <typename T>
        SList<T>::pNode<T> SList<T>::Node<T>::getNextObj() const{
        
        return this.mNextObj ;
    }
    
    /*

functionName:- setData

Usage:- set the mData field of the node object

Return type:- NONE

caution:- NONE

*/
    
    template <typename T>
        void SList<T>::Node<T>::setData(const T& data){
        
        this->mData = data;
        
    }
    
    /*

functionName:- setNextObj

Usage:- sets the next object field of the node object0

Return type:- NONE

caution:- It doesn't copy node object it just points toward it.

*/
    
    template <typename T> 
        void SList<T>::Node<T>::setNextObj(pNode nextObj){
        this->mNextObj = nextObj ; 
    }
    
    /*

functionName:- (Operator overloaded) ==

Usage:- to compare 2 node objects

Return type:- boolean

caution:- It is a loose checking of the mNextObj field.

*/
    
    template <typename T>
        bool SList<T>::Node<T>::operator ==(const Node& operand){
        return ((this->mData == operand->getData() ) && (this->mNextObj == operand->getNextObj()) );
    }
    
    /*

functionName:- (operator overloading) =

Usage:- Assign a Node object to another Node object

Return type:- NONE

caution:- NONE

*/
    
    template <typename T>
        
        SList<T>::Node<T>& SList<T>::Node<T>::operator =(const Node& source){
        
        Node t_elem(source->getData());
        
        /*
1. The temp pointer is made to point at this object mNextObj field and 
curr pointer is made to point at source object mNextObj field.

2.A new node object is allocated in the memory and its mData field is 
initialized with the mData field of the currnet node object of source
node object.

*/
        
        for(pNode temp = t_elem->getNextObj(), curr = source->getNextObj(); cur->getNextObj() != nullptr; curr->setNextObj(curr->getNextObj)){
            
            temp = new Node(curr->getData());
            temp->setNextObj(temp->getNextObj());
            
        }
        
        return t_elem;
    }
    
    /*

functionName:- swap

Usage:- swap 2 node objects.

Return type:- NONE

caution:- NONE

*/
    
    template <typename T>
        void SList<T>::Node<T>:: swap(const Node& nodeObj){
        
        Node temp;
        
        temp.setData(nodeObj->getData());
        temp.setNextObj(nodeObj->getNextObj());
        
        nodeObj->setData(this->mData);
        nodeObj->setNextObj(this->mNextObj);
        
        this->mData = temp.getData();
        this->mNextObj = temp.getNextObj();
    }
}
