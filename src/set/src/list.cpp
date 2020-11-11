// #include "list.hpp"



// // Linked list's element class

// template <class T>
// ListElem<T>::ListElem() {}


// template <class T>
// ListElem<T>::ListElem(T k)
//   : key(k), next(nullptr), prev(nullptr) {}


// template <class T>
// bool ListElem<T>::is_head() const
// {
//   return (prev == nullptr);
// }


// template <class T>
// bool ListElem<T>::is_tail() const
// {
//   return (next == nullptr);
// }




// // Linked list base class

// template <class T>
// List<T>::List() {}


// template <class T>
// bool List<T>::is_empty() const
// {
//   return (head() == nullptr);
// }


// template <class T>
// ListElem<T>* List<T>::head()
// {
//   return _head;
// }


// template <class T>
// ListElem<T>* List<T>::search(T& key) const
// {
//   ListElem<T> x = head();
//   while( (x != nullptr) && (x.key != key) )
//     x = x.next;
//   return x;
// }


// template <class T>
// void List<T>::insert(ListElem<T>& x)
// {
//   x.next = head();
//   if( not is_empty() )
//     (head()).prev = &x;
//   head() = &x;
//   x.prev = nullptr;
// }


// template <class T>
// void List<T>::erase(ListElem<T>& x)
// {
//   if( not x.is_head() )
//     (x.prev).next = &(x.next);
//   else
//     head() = x.next;
//   if( not x.is_tail() )
//     (x.next).prev = &(x.prev);
//   x.next = x.prev = nullptr;
// }
