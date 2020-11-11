#ifndef __LIST_HPP_INCLUDED__
#define __LIST_HPP_INCLUDED__

#include <string>
#include <iostream>
#include <cstdio>

template <class T>
struct ListElem
// Linked list's element class
{
  ListElem<T>* next;
  ListElem<T>* prev;
  T key;

  ListElem();
  ListElem(T k);

  operator std::string() const;

  bool is_head() const;
  bool is_tail() const;
};



template <class T>
class List
// Linked list base class
{
  ListElem<T>* _head;

public:
  List();
  List(T* start, T* end);
 
  T operator[](std::size_t) const;
  T operator[](std::size_t);

  bool is_empty() const;
  ListElem<T>* head();
  ListElem<T>* search(T& key) const;
  void insert(ListElem<T>* x);
  void erase(ListElem<T>& x);
};


// Linked list's element class

template <class T>
ListElem<T>::ListElem() {}


template <class T>
ListElem<T>::ListElem(T k)
  : key(k) {}//, next(nullptr), prev(nullptr) {}

// ????????????????????????
template <class T>
ListElem<T>::operator std::string() const
{
  return "something";
}

template <class T>
bool ListElem<T>::is_head() const
{
  return (prev == nullptr);
}


template <class T>
bool ListElem<T>::is_tail() const
{
  return (next == nullptr);
}




// Linked list base class

template <class T>
List<T>::List()
  : _head(nullptr) {}


template <class T>
List<T>::List(T* start, T* end)
  : _head(nullptr) 
{
  T* ptr = start;
  ListElem<T>* el;
  
  while(ptr != end){
    el = new ListElem<T>(*ptr);
    this->insert(el);
    ptr++;
  }
}


template <class T>
T List<T>::operator[](std::size_t idx) const
{
  std::size_t i = 0;
  ListElem<T>* ptr = head();
  while(ptr == nullptr and i < idx)
    {
      ptr = ptr->next;
      i++;
    }
    
  return ptr->key;
}


template <class T>
T List<T>::operator[](std::size_t idx)
{
  std::size_t i = 0;
  ListElem<T>* ptr = head();
  while(ptr != nullptr and i < idx)
    {
      ptr = ptr->next;
      i++;
    }
    
  return ptr->key;
}

template <class T>
bool List<T>::is_empty() const
{
  return (_head == nullptr);
}


template <class T>
ListElem<T>* List<T>::head()
{
  return _head;
}


template <class T>
ListElem<T>* List<T>::search(T& key) const
{
  ListElem<T> x = head();
  while( (x != nullptr) && (x.key != key) )
    x = x.next;
  return x;
}


template <class T>
void List<T>::insert(ListElem<T>* x)
{
  x->next = head();
  if( not is_empty() )
    _head->prev = x;
  _head = x;
  x->prev = nullptr;
}


template <class T>
void List<T>::erase(ListElem<T>& x)
{
  if( not x.is_head() )
    (x.prev).next = &(x.next);
  else
    _head = x.next;
  if( not x.is_tail() )
    (x.next).prev = &(x.prev);
  x.next = x.prev = nullptr;
}


#endif // __LIST_HPP_INCLUDED__
