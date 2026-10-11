#include <vector>
using namespace std;

struct  Node
{
    Node *next;
    Node *prev;
    int data;
    /* data */
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class Double_linked_list
{
private:

     Node *head;
     Node *tail;
     int length;
     vector<Node*>Debug;
public:
void print();
void Reverse_print();
void insert_front(int value);
void insert_end(int value);
void insert_before_index(int value , int index);
void insert_sorted(int value);
void link(Node* First,Node *second);
void embedded_after( Node * n,int value);
void delete_with_key(int key);
void delete_and_link_utility();
void delet_end();
void delete_front();
void delete_even_Position();
void view_length();
int get_length();
    Double_linked_list();
    ~Double_linked_list();
};

