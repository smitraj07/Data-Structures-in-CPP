#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "DLL_class.hpp"

using namespace std;


void create_dll(DLL<int> &d_list)
{
    d_list.insert_at(0,5);
    d_list.push_front(3);
    d_list.push_back(33);
    d_list.push_back(13);
    d_list.push_front(30);
    d_list.insert_at(2,45);
}

void do_DLL()
{
    DLL<int> d_list;
    create_dll(d_list);
    d_list.print_DLL();
    d_list.print_DLL_reverse();
    d_list.delete_at(3);
    d_list.print_DLL();
    d_list.print_DLL_reverse();
}

int main()
{
    do_DLL();
    return 0;
}