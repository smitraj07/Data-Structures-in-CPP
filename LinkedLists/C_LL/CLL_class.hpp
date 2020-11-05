#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class Node{
    public:
    T _data;
    Node *_next;
    Node(T data) : _data(data), _next(this) {};
};

template <class T>
class CLL{
    private:
    Node<T> *_header;
    Node<T> *_tail;
    size_t _size;

    public:
    // constructor
    CLL() : _header(nullptr), _tail(nullptr), _size(0) {};
    ~CLL();

    // Select
    size_t get_size() const;
    void print_LL() const;
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
CLL<T>::~CLL()
{
    Node<T> *temp = this->_header;

    if(temp == nullptr)
        return;

    bool flag;

    if(this->_header != nullptr)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    

    while(flag == true)
    {
        if (temp == this->_tail)
            flag = false;

        this->_header = this->_header->_next;
        delete temp;
        temp = this->_header;   
    }
    this->_header = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
}

template <class T>
size_t 
CLL<T>::get_size() const
{
        return this->_size;
}

template <class T>
void 
CLL<T>::print_LL() const
{
    Node<T> *temp;
    temp = this->_header;
    bool flag;

    if (this->_header != nullptr)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    

    while(flag == true)
    {
        if (temp == this->_tail)
            flag = false;
        cout << temp->_data << " -> ";
        temp = temp->_next;
    }
    cout << endl;
    cout << "size of LL is: " << this->get_size() << endl;
}


// TODO: Add exception
template <class T>
T 
CLL<T>::select_at(int index) const
{
    if (index >= this->get_size())
        return T(0);

    Node<T> *temp = this->_header;
    while (index-- > 0)
        temp = temp->_next;

    return temp->_data;
}

// TODO: Add exception
template <class T>
T 
CLL<T>::front() const
{
    if (this->_header == nullptr)
        return T(0);
    return this->_header->_data;
}

// TODO: Add exception
template <class T>
T 
CLL<T>::back() const
{
    if (this->_header == nullptr)
        return T(0);
    return this->_tail->_data;
}

template <class T>
void 
CLL<T>::push_front(T data)
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
        this->_header = n;
        this->_tail->_next = n;
    }
    this->_size++;
}

template <class T>
void 
CLL<T>::push_back(T data)
{
    if (this->_header == nullptr)
    {
        this->push_front(data);
    }
    else
    {
        Node<T> *n = new Node<T>(data);

        n->_next = this->_tail->_next;
        this->_tail->_next = n;
        this->_tail = n;

        this->_size++;
    }
}

// TODO: Add exception
template <class T>
void 
CLL<T>::insert_at(int index, T data)
{
    if (index >= (this->get_size() + 1))
        return;

    Node<T> *temp1 = this->_header;
    Node<T> *temp2 = nullptr;

    while (index-- > 0)
    {
        temp2 = temp1;
        temp1 = temp1->_next;
    }

    if(temp2 == nullptr)
    {
        this->push_front(data);
    }
    else if(temp1 == this->_header)
    {
        this->push_back(data);
    }
    else
    {
        Node<T> *n = new Node<T>(data);
        temp2->_next = n;
        n->_next = temp1;
        this->_size++;
    }
}

// Update

// TODO: Add exception
template <class T>
void 
CLL<T>::update_at(int index, T data)
{
    if (index >= this->get_size())
        return;

    Node<T> *n = this->_header;
    while(index-- > 0)
    {
        n = n->_next;
    }
    n->_data = data;
}

// Delete

template <class T>
void 
CLL<T>::delete_front()
{
    if (this->_header == nullptr)
        return;
    
    Node<T> *temp = this->_header;
    this->_header = this->_header->_next;
    if (temp == this->_header)
    {
        this->_tail = nullptr;
        this->_header = nullptr;
    }
    this->_size--;
    delete temp;
}

template <class T>
void
CLL<T>::delete_back()
{
    if (this->_header == nullptr)
        return;
    
    Node<T> *temp = this->_header;

    while (temp != this->_tail && temp->_next != this->_tail)
    {
        temp = temp->_next;
    }

    if(temp == this->_tail)
    {
        this->_header = nullptr;
        this->_tail = nullptr;
    }
    else
    {
        temp->_next = this->_tail->_next;
        Node<T> *q = temp;
        temp = this->_tail;
        this->_tail = q;
    }
    this->_size--;
    delete temp;
}

// TODO: Add exception
template <class T>
void 
CLL<T>::delete_at(int index)
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

    if(temp2 == nullptr)
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
        this->_size--;
        delete temp1;
    }
}