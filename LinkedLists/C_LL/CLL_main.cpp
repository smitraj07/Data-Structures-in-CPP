#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "CLL_class.hpp"

using namespace std;


// SLL example.
void
create_LL(CLL<int> &list)
{
    list.insert_at(0, 34);
    list.insert_at(0,44);
    list.insert_at(0, 4);
    list.insert_at(3,14);
}

void do_LL()
{
    CLL<int> list;
    create_LL(list);
    list.print_LL();
    list.delete_at(2);
    list.delete_at(1);
    list.delete_at(1);
    list.delete_front();
   
    list.print_LL();
    cout << list.front() << endl;
}

int main()
{
    cout << "This is main begining." << endl;
    do_LL();
    cout << "This is main exiting." << endl;
    return 0;
}
