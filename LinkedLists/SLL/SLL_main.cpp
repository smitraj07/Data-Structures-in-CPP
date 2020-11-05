#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "SLL_class.hpp"

using namespace std;


// SLL example.
void
create_LL(LL<int> &list)
{
    list.insert_at(0, 34);
    list.insert_at(0,44);
    list.insert_at(0, 4);
    list.insert_at(3,14);
}

void do_LL()
{
    LL<int> list;
    create_LL(list);
    list.print_LL();
    list.delete_at(2);
    list.delete_at(1);
    list.delete_at(1);
    list.delete_at(0);
    list.print_LL();
}

int main()
{
    cout << "This is main begining." << endl;
    do_LL();
    cout << "This is main exiting." << endl;
    return 0;
}
