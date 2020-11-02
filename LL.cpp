#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "gen_class.hpp"

using namespace std;


// SLL example.
void
create_LL(LL<int> &list)
{
    list.push_front(3);
    list.push_back(31);
    list.push_front(13);
    list.insert_at(2, 34);
    list.update_at(2,44);
}

void do_LL()
{
    LL<int> list;
    create_LL(list);
    list.print_LL();
    list.delete_back();
    list.delete_back();
    list.delete_back();
    list.delete_at(0);
    list.print_LL();
}

int main()
{
    do_LL();
    return 0;
}
