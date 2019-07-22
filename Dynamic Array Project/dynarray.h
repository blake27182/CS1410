//
//  dynarray.h
//  Dynamic Array Project
//
//  Created by Blake Williams on 3/26/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#ifndef dynarray_h
#define dynarray_h

#include <iostream>
#include <stdio.h>
#include <stdexcept>
using namespace std;

template<typename type>
class DynArray{
public:
    DynArray();
    DynArray(int n);
    ~DynArray();
    DynArray(const DynArray& origObject);
    DynArray& operator=(const DynArray& origObject);
    
    int capacity() const;
    int size() const;
    type& at(int idx) const;
    void push_back(type num);
    void pop_back();
    void clear();
    type& back();
    type& front();
    
private:
    int siz;    // current size
    int cap;    // current capacity
    type* head;  // data head node
    const int DEFAULT_CAPACITY = 2;
};


template<typename type>
DynArray<type>::DynArray(){
    siz = 0;    // current size
    cap = DEFAULT_CAPACITY;
    head = new type [cap];
}

template<typename type>
DynArray<type>::DynArray(int n){  // n - initial capacity
    siz = 0;
    cap = n;
    head = new type [n];
}

template<typename type>
DynArray<type>::~DynArray(){  // ~destructor
    delete [] head;
    siz = cap = 0;
    head = nullptr;
}

template<typename type>
DynArray<type>::DynArray(const DynArray& origObject){
    siz = origObject.siz;
    cap = origObject.cap;
    head = new type[cap];
    for (int i=0;i<origObject.size();i++){
        head[i] = origObject.at(i);
    }
    cout << "copy" << endl;
}

template<typename type>
DynArray<type>& DynArray<type>::operator=(const DynArray<type> &origObject){
    if(this != &origObject){
        cout << "assign" << endl;
        siz = origObject.siz;
        cap = origObject.cap;
        delete head;
        head = new type[cap];
        for (int i=0;i<origObject.size();i++){
            head[i] = origObject.at(i);
        }
    }
    return *this;
}




template<typename type>
int DynArray<type>::capacity()const{
    return cap;
}

template<typename type>
int DynArray<type>::size()const{
    return siz;
}

template<typename type>
type& DynArray<type>::at(int idx)const{
    if ((idx >= siz)||(idx<0)){
        throw runtime_error("invalid index");
    }else{
        return head[idx];
    }
}


template<typename type>
void DynArray<type>::push_back(type num){
    if (siz >= cap){
        type* temp = head;
        head = new type[2*cap];
        for(int i=0;i<siz;i++){
            head[i] = temp[i];
        }
        delete temp;
        cap *= 2;
        cout << "grow" << endl;
    }
    head[siz] = num;
    siz++;
}

template<typename type>
void DynArray<type>::pop_back(){
    if(cap>0)
        siz--;
}

template<typename type>
void DynArray<type>::clear(){
    delete [] head;
    siz = 0;
    cap = DEFAULT_CAPACITY;
    head = new type[cap];
}

template<typename type>
type& DynArray<type>::back(){
    if(siz<=0)
        throw runtime_error("Array is empty");
    return head[siz-1];
}

template<typename type>
type& DynArray<type>::front(){
    if (siz<=0)
        throw runtime_error("Array is empty");
    return head[0];
}


#endif /* dynarray_h */
