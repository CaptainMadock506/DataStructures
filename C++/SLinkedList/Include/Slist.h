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
        
        
        class Node{
            private :
            T mData ; 
            Node* mNextObj ;
            
            // public class constructor
            public : 
            
            Node();
            Node(const T& data, Node* nextObj = nullptr);
            ~Node() noexcept;
            
            // public member functions
            public : 
            
            // getter member function
            T getData() const ; 
            typename SList::Node* getNextObj() const ; 
            
            // setter member function
            void setData(const T& data);
            void setNextObj(Node* nextObj); 
            
            // operator overloading
            bool operator ==(const Node& operand) ; 
            typename SList::Node& operator = (const SList::Node& source) ;
            
            // swap functionality
            void swap(const Node& nodeObj) ; 
            
            
        };
        
        
        private:
        
        Node* mHead ; 
        Node* mTail ; 
        std::size_t mSize ;
        
        // public class constructor
        public: 
        
        SList();
        SList(const T& data, Node* nextObj = nullptr);
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
        void sort();
        T* getItem(const int& index);
        Node* search(const int& element);
        
        void displayList() const ;
        
        // swap fucntionality
        void swap(const SList& listObj);
        
        // getter member functions
        std::size_t getLength() const ; 
        
        // Operator overloading
        bool operator ==(const SList& operand);
        SList& operator =(const SList& source) ; 
        SList& operator +=(const SList& operand);
        SList& operator -=(const SList& operand);
        void operator <<(const SList& operand) const;
        
        
        // private member functions
        private:
        
        // functions for adding and removing from the head
        void addToHead(const T& data);
        void addToTail(const T& data);
        T* deleteFromHead();
        T* deleteFromTail();
        
        // fucntion to seacrh the Linked List and to delete a spacific object
        Node* searchItem(const T& element);
        T* deleteItem(const T& element);
        
        //algorithm for sorting a Linked List
        Node* getMiddle(Node* nodeObj);
        Node* sortedMerge(Node* lNode, Node* rNode);
        Node* MergeSort(Node* nodeObj);
        
    };
    
    /*------------------Defination for Node class------------------------*/
    
    /*
    
    functionName:- (constructor) Node
    
    Usage:- Initialize the Node object to => {mData = 0, mNextObj = nullptr}
    
    Return type:- NONE
    
    caution:- NONE
    
    */
    
    template <typename T>
        SList<T>::Node::Node():mData(),mNextObj(){}
    
    /*

functionName:- (Overloaded Constructor) Node 

Usage:- Initialize the Node object to the parameters passed to the constructor

=> {mData = data, mNextObj = nextObj}

Return type:- NONE

caution:- This function doesn't copy the node object it just points to the NodeObj passed to it.

*/
    
    template <typename T> 
        SList<T>::Node::Node(const T& data, Node* nextObj):mData(data),mNextObj(nextObj){}
    
    
    /*

functionName:- (Destructor) ~Node

Usage:- Destructor

Return type:- NONE

caution:- NONE

*/
    
    template <typename T>
        SList<T>::Node::~Node() noexcept{
        
        this->mData = 0;
        delete this->mNextObj;
        this->mNextObj = nullptr;
    }
    
    /*

functionName:- getData

Usage:- It returns the mData field of the node object.

Return type:- User Defined T datatype

caution:- NONE

*/
    
    template <typename T>
        T SList<T>::Node::getData() const{
        
        return this->mData; 
    }
    
    /*

functionName:- getNextObj

Usage:- returns the mNextObj data field of the Node object

Return type:- SList subclass Node<T>* (pointer to a Node object)

caution:- NONE

*/
    
    template <typename T>
        typename SList<T>::Node* SList<T>::Node::getNextObj() const{
        
        return this.mNextObj ;
    }
    
    /*

functionName:- setData

Usage:- set the mData field of the node object

Return type:- NONE

caution:- NONE

*/
    
    template <typename T>
        void SList<T>::Node::setData(const T& data){
        
        this->mData = data;
        
    }
    
    /*

functionName:- setNextObj

Usage:- sets the next object field of the node object0

Return type:- NONE

caution:- It doesn't copy node object it just points toward it.

*/
    
    template <typename T> 
        void SList<T>::Node::setNextObj(Node* nextObj){
        this->mNextObj = nextObj ; 
    }
    
    /*

functionName:- (Operator overloaded) ==

Usage:- to compare 2 node objects

Return type:- boolean

caution:- It is a loose checking of the mNextObj field.

*/
    
    template <typename T>
        bool SList<T>::Node::operator ==(const Node& operand){
        return ((this->mData == operand->getData() ) && (this->mNextObj == operand->getNextObj()) );
    }
    
    /*

functionName:- (operator overloading) =

Usage:- Assign a Node object to another Node object

Return type:- NONE

caution:- NONE

*/
    
    template <typename T>
        
        typename SList<T>::Node& SList<T>::Node::operator =(const Node& source){
        
        Node t_elem(source->getData());
        
        /*
1. The temp pointer is made to point at this object mNextObj field and 
curr pointer is made to point at source object mNextObj field.

2.A new node object is allocated in the memory and its mData field is 
initialized with the mData field of the currnet node object of source
node object.

*/
        
        for(Node* temp = t_elem->getNextObj(), curr = source->getNextObj(); curr->getNextObj() != nullptr; curr->setNextObj(curr->getNextObj)){
            
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
        void SList<T>::Node::swap(const Node& nodeObj){
        
        Node temp;
        
        temp.setData(nodeObj->getData());
        temp.setNextObj(nodeObj->getNextObj());
        
        nodeObj->setData(this->mData);
        nodeObj->setNextObj(this->mNextObj);
        
        this->mData = temp.getData();
        this->mNextObj = temp.getNextObj();
    }
    
    /*
        functionName:- (Constructor) SList
            
            Usage:- Initialize the Single Linked List
            
            Return type:- NONE
            
            caution:- NONE
            
            */
    
    template <typename T>
        SList<T>::SList():mHead(),mTail(),mSize(){}
    
    /*
        functionName:- (Constructor Overloaded) SList
            
            Usage:- Initialize the Single Linked List with data and nextObj
            
            Return type:- NONE
            
            caution:- NONE
            
            */
    
    template <typename T>
        SList<T>::SList(const T& data, Node* nextObj):mHead(),mTail(),mSize(){
        
        this->mHead = new Node(data,nextObj);
        this->mHead = this->mTail ; 
        this->mSize = 1 ;
    }
    
    /*
            functionName:- (copy Constructor) SList
                
                Usage:- Initialize the Single Linked List with another List object 
                
                Return type:- NONE
                
                caution:- NONE
                
                */
    
    template <typename T>
        SList<T>::SList(const SList& source):mHead(),mTail(),mSize(){
        
        // first dynamically allocate the mHead and set its mData field to the mData field of the
        // source list object .
        this->mHead =  new Node(source.mHead.getData());
        
        // this loop intend to move the current object pointed in the source List object and 
        // will create a deep copy of the souce list object.
        
        for(Node* temp = this->mHead->getNextObj() , curr = source.mHead.getNextObj(); curr != nullptr; curr = curr.getNextObj(),temp =temp->getNextObj() ){
            temp = new Node(curr.getData());
            if(curr = source.mTail)
                this->mTail = temp ; 
        }
        
    }
    
    /*Defination for SList private functions*/
    
    /*
                functionName:- addToHead
                    
                    Usage:- add an element at the front of the Linked List 
                    
                    Return type:- NONE
                    
                    caution:- NONE
                    
                    */
    
    template <typename T>
        void SList<T>::addToHead(const T& data){
        
        if(this->mHead == nullptr){
            
            this->mHead = new Node(data) ; 
            this->mHead = this->mTail ;
            
        }else{
            
            Node* temp = new Node(data,this->mHead);
            this->mHead = temp ;
        }
        
        this->mSize++;
    }
    
    
    /*
                functionName:- addToTail
                    
                    Usage:- add an element at the last of the Linked List 
                    
                    Return type:- NONE
                    
                    caution:- NONE
                    
                    */
    
    template <typename T>
        void SList<T>::addToTail(const T& data){
        
        if(this->mTail == nullptr){
            
            this->mHead = new Node(data) ; 
            this->mHead = this->mTail ;
            
        }else {
            
            Node* temp = new Node(data);
            this->mTail->setNextObj(temp);
            this->mTail = temp ; 
        }
        
        this->mSize++;
    }
    
    /*
                functionName:- deleteFromHead
                    
                    Usage:- delete an element from the front of the Linked List 
                    
                    Return type:- Pointer to the user Defined type
                    
                    caution:- The returned pointer must be deleted as it was dynamically allocated.
                    
                    */
    
    template <typename T>
        T* SList<T>::deleteFromHead(){
        
        T* t_data = nullptr ;
        
        if(this->mHead == nullptr)
            return t_data ; 
        
        if(this->mHead != nullptr && this->mHead->getNextObj == nullptr){
            
            t_data = new T();
            *t_data = this->mHead->getData();
            delete this->mHead ; 
            
        }else{
            
            Node* temp = this->mHead ; 
            this->mHead = this->mHead->getNextObj(); 
            
            t_data = new T(); 
            *t_data = temp->getData();
            delete temp ; 
            
        }
        
        this->mSize--;
        
        return t_data;
        
    }
    
    /*
                functionName:- deleteFromTail
                    
                    Usage:- delete an element from the end  of the Linked List 
                    
                    Return type:- Pointer to the user Defined type
                    
                    caution:- The returned pointer must be deleted as it was dynamically allocated.
                    
                    */
    
    template<typename T>
        T* SList<T>::deleteFromTail(){
        
        T* t_data = nullptr ;
        
        if(this->mHead == nullptr)
            return t_data ; 
        
        if(this->mHead != nullptr && this->mHead->getNextObj() == nullptr){
            
            t_data = new T();
            *t_data = this->mTail->getData();
            delete this->mTail ; 
            
        }else{
            
            Node* temp = nullptr ; 
            
            for(temp = this->mHead ; temp->getNextObj() != this->mTail; temp = temp->getNextObj());
            
            t_data = new T(); 
            
            *t_data = this->mTail->getData(); 
            delete this->mTail ; 
            
            this->mTail = temp ; 
            this->mTail->setNextObj(nullptr);
            
        }
        
        this->mSize--;
        
        return t_data;
        
    }
    
    /*
    
    functionName:- searchItem
    
    Usage:- search for item specified by the user
    
    Return type:- pointer to a Node
    
    caution:- do Not mess with the returned pointer or delete it
    
    */
    
    template <typename T>
        typename SList<T>::Node* SList<T>::searchItem(const T& element){
        
        if(this->mHead == nullptr)
            return nullptr ; 
        
        if(element == this->mHead->getData())
            
            return this->mHead ; 
        
        else if(this->mTail->getData() == element)
            
            return this->mTail ; 
        
        else{
            
            Node* temp = nullptr ; 
            for(temp = this->mHead->getNextObj(); (temp->getData() != element) && (temp->getNextObj() != this->mTail); temp = temp->getNextObj());
            return temp ; 
        }
        
    }
    
    /*
    
    functionName:- deleteItem
    
    Usage:- delete the item specified by the user
    
    Return type:- pointer to user-defined datatype
    
    caution:- must free the returned user datatype
    
    */
    
    template <typename T>
        T* SList<T>::deleteItem(const T& element){
        
        T* t_data = nullptr ; 
        
        if(this->mHead == nullptr)
            return t_data; 
        
        if(this->mHead->getData() == element)
            t_data = deleteFromHead() ; 
        else if(this->mTail->getData == element)
            t_data = deleteFromTail() ; 
        else{
            
            Node* temp = nullptr , curr = nullptr ; 
            for(temp = this->mHead , curr = this->mHead->getNextObj(); (curr->getData != element) && (curr->getNextObj != nullptr); temp = temp->getNextObj(), curr = curr->getNextObj());
            
            temp->setNextObj(curr->getNextObj());
            t_data = new T() ; 
            *t_data = curr->getData();
            delete curr ; 
            
        }
        
        if(t_data != nullptr)
            this->mSize--;
        
        return t_data ;
    }
    
    /*
    
    functionName:- getMiddle
    
    Usage:- Get the middle the of node object specified.
    
    Return type:- pointer to Node  datatype.
    
    caution:- must not be meddled with the returned pointer.
    
    */
    
    template <typename T>
        typename SList<T>::Node* SList<T>::getMiddle(Node* nodeObj){
        
        if(nodeObj == nullptr)
            return nodeObj ; 
        
        Node* fNode = nodeObj ; 
        Node* sNode = nodeObj ;
        
        if((fNode->getNextObj()->getNextObj() != nullptr) && (sNode->getNextObj() != nullptr)){
            fNode = fNode->getNextObj()->getNextObj(); 
            sNode = sNode->getNextObj();
        }
        
        return sNode ;
    }
    
    /*
    
    functionName:- sortedMerge
    
    Usage:- Sort and merge 2 node object provided to the function.
    
    Return type:- pointer to Node  datatype.
    
    caution:- must not be meddled with the returned pointer.
    
    */
    
    template <typename T>
        typename SList<T>::Node* SList<T>::sortedMerge(Node* lNode, Node* rNode){
        
        if(lNode == nullptr)
            return rNode ; 
        else if(rNode == nullptr)
            return lNode ; 
        
        Node* sortedList = nullptr ; 
        
        if(lNode->getData() >= rNode->getData()){
            
            sortedList = lNode ;
            this->mTail = rNode ; 
            lNode->setNextObj(sortedMerge(rNode->getNextObj(),lNode));
            this->mHead = lNode ; 
            
        }else{
            
            sortedList = rNode ; 
            this->mTail = lNode ; 
            rNode->setNextObj(sortedMerge(lNode->getNextObj(),rNode));
            this->mHead = rNode ;
        }
        
        return sortedList;
    }
    
    /*
    
    functionName:- mergeSort
    
    Usage:- Sort and merge the whole linked list.
    
    Return type:- pointer to Node  datatype.
    
    caution:- must not be meddled with the returned pointer.
    
    */
    
    template <typename T>
        typename SList<T>::Node* SList<T>::MergeSort(Node* nodeObj){
        
        if(nodeObj == nullptr)
            return nodeObj ; 
        
        Node* middle  = getMiddle(nodeObj);
        Node* middle_next = middle->getNextObj() ;
        
        middle->setNextObj(nullptr);
        
        Node* lNode = MergeSort(middle);
        Node* rNode = MergeSort(middle_next);
        
        Node* sortedMergedList = sortedList(lNode,rNode);
        
        return sortedMergedList;
        
        
    }
    
    /*
    
    functionName:- add
    
    Usage:- add Item to the list based on the head_flag.
    
    Return type:- NONE
    
    caution:- NONE
    
    */
    
    template <typename T>
        void SList<T>::add(const T& data, bool head_flag = false){
        if(head_flag)
            this->addToHead(data);
        else
            this->addToTail(data);
    }
    
    /*
    
    functionName:- (overloaded funtion) add
    
    Usage:- add Itme to the list at the position provided..
    
    Return type:- NONE
    
    caution:- NONE
    
    */
    
    template <typename T>
        void SList<T>::add(const T& data, const int& index){
        
        if(this->mHead == nullptr) 
            this->addToHead(data);
        else if(index <= this->mSize - 1){
            
            Node* temp  = nullptr ; 
            for(temp = this->mHead, int i = 0; i == index ; i++ ,temp= temp->getNextObj());
            temp->setData(data);
            
        }else
            this->addToTail(data);
        
    }
    
    /*
    
    functionName:- remove 
    
    Usage:- remove from the linked list based on the head_flag
    
    Return type:- pointer to user-defined datatype.
    
    caution:- the returned data must be freed.
    
    */
    
    T* SList<T>::remove(bool head_flag = false){
        if(head_flag)
            return this->deleteFromHead();
        else 
            return this->deleteFromTail();
    }
}
