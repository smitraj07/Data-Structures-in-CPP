#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class Node{
    public:
    T _data;
    Node *_next;
    Node *_prev;
    Node(T data) : _data(data), _next(nullptr), _prev(nullptr) {};
};

template <class T>
class DLL{
    private:
    Node<T> *_header;
    Node<T> *_tail;
    size_t _size;

    public:
    // constructor
    DLL() : _header(nullptr), _tail(nullptr), _size(0) {};
    ~DLL();

    // Select
    size_t get_size() const;
    void print_DLL() const;
    void print_DLL_reverse() const;
    T select_at(int index) const;
    T front() const;
    T back() const;

    // Insert
    void push_front(T data);
    void push_back(T data);
    void insert_at(int index, T data);

    // Update
    void update_at(int index, T data);

    // Delete
    void delete_front();
    void delete_back();
    void delete_at(int index);
};

template <class T>
DLL<T>::~DLL()
{
    Node<T> *temp = this->_header;

    while(this->_header != nullptr)
    {
        temp = this->_header;
        this->_header = this->_header->_next;
        delete temp;
    }
    this->_header = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
}

template <class T>
size_t
DLL<T>::get_size() const
{
    return this->_size;
}

template <class T>
void
DLL<T>::print_DLL() const
{
    Node<T> *temp = this->_header;

    while(temp != nullptr)
    {
        cout << temp->_data << "<->";
        temp = temp->_next;
    }
    cout << endl;
    cout << "size: " << this->get_size() << endl;
}

template <class T>
void
DLL<T>::print_DLL_reverse() const
{
    Node<T> *temp = this->_tail;

    while(temp != nullptr)
    {
        cout << temp->_data << "<->";
        temp = temp->_prev;
    }
    cout << endl;
    cout << "size: " << this->get_size() << endl;
}

// TODO: ADD exception handling
template <class T>
T 
DLL<T>::select_at(int index) const
{
    if (index >= this->get_size())
        return T(0);

    Node<T> *temp = this->_header;
    while(index-- > 0)
    {
        temp = temp->_next;
    }
    return temp->_data;
}

// TODO: ADD exception handling
template <class T>
T
DLL<T>::front() const
{
    if (this->_header == nullptr)
        return T(0);
 
    return this->_header->_data;
}

// TODO: ADD exception handling
template <class T>
T
DLL<T>::back() const
{
    if (this->_header == nullptr)
        return T(0);
 
    return this->_tail->_data;
}

template <class T>
void 
DLL<T>::push_front(T data)
{
    Node<T> *n = new Node<T>(data);

    if (this->_header == nullptr)
    {
        this->_header = n;
        this->_tail = n;
    }
    else
    {
        n->_next = this->_header;
        this->_header->_prev = n;
        this->_header = n;
    }
    this->_size++;
}

template <class T>
void 
DLL<T>::push_back(T data)
{
    if (this->_header == nullptr)
    {
        this->push_front(data);
    }
    else
    {
        Node<T> *n = new Node<T>(data);
        n->_prev = this->_tail;
        this->_tail->_next = n;
        this->_tail = n;
        this->_size++;
    }
}

// TODO: Add exception.
template <class T>
void
DLL<T>::insert_at(int index, T data)
{
    if (index >= (this->get_size() + 1))
        return;

    Node<T> *temp1 = this->_header;
    Node<T> *temp2 = nullptr;

    while(index-- > 0)
    {
        temp2 = temp1;
        temp1 = temp1->_next;
    }

    if (temp2 == nullptr)
    {
        this->push_front(data);
    }
    else if (temp1 == nullptr)
    {
        this->push_back(data);
    }
    else
    {
        Node<T> *n = new Node<T>(data);
        n->_next = temp1;
        n->_prev = temp2;
        temp1->_prev = n;
        temp2->_next = n;
        this->_size++;
    }
}

// TODO: Add exception
template <class T>
void 
DLL<T>::update_at(int index, T data)
{
    if (index >= this->get_size())
        return;

    Node<T> *temp = this->_header;

    while (index-- > 0)
    {
        temp = temp->_next;
    }

    temp->_data = data;
}

template <class T>
 void 
 DLL<T>::delete_front()
 {
     if (this->_header == nullptr)
        return;
    
    Node<T> *temp = this->_header;
    this->_header = this->_header->_next;
    if (this->_header == nullptr)
    {
        this->_tail = nullptr;
    }
    else
    {
        this->_header->_prev = nullptr;
    }
    delete temp;
    this->_size--;
 }
 
 template <class T>
 void 
 DLL<T>::delete_back()
 {
     if (this->_header == this->_tail)
     {
        this->delete_front();
        return;
     }
    
    Node<T> *temp = this->_tail;
    this->_tail = this->_tail->_prev;
    this->_tail->_next = nullptr;
    delete temp;
    this->_size--;
 }
 
 // TODO: Add exception 
 template <class T>
 void 
 DLL<T>::delete_at(int index)
 {
     if (index >= this->get_size())
        return;

    Node<T> *temp1 = this->_header;
    Node<T> *temp2 = nullptr;

    while (index-- > 0)
    {
        temp2 = temp1;
        temp1 = temp1->_next;
    }

    if (temp2 == nullptr)
    {
        this->delete_front();
    }
    else if (temp1 == this->_tail)
    {
        this->delete_back();
    }
    else
    {
        temp2->_next = temp1->_next;
        temp1->_next->_prev = temp2;
        delete temp1;
        this->_size--;
    }
 }