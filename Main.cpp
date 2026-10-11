
#include "Double_linked_list.hpp"
#include <iostream>
using namespace std;

int main()
{
    Double_linked_list list;
    cout << "Before add elements:\n";
    list.print();
    // Insert test values
    list.insert_end(10);
    cout << "after 10:\n";
    list.insert_end(20);
    cout << "after 20\n";
    list.insert_end(30);
    cout << "after 30:\n";
    list.insert_end(40);
    cout << "after 40:\n";
    list.insert_end(50);
    cout << "after 50:\n";
    cout << "Before deleting even positions:\n";
    list.print();

    list.delete_even_Position();

    cout << "\nAfter deleting even positions:\n";
    list.print();

    list.view_length();

    return 0;
}
