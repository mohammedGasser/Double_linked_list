#include "Double_linked_list.hpp"
#include <iostream>
int Double_linked_list::get_length(){
return length;
}
Double_linked_list::Double_linked_list()
    : head(nullptr), tail(nullptr), length(0)
{
}
void Double_linked_list::view_length()
{

    std::cout<<length;
}
Double_linked_list::~Double_linked_list()
{
    if (length == 0)
        return;
    if (length == 1)
      {
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;
        return;
      }
  for(Node *temp1=head, *temp2=tail ;  ;   )
    {

        
        Node *temp1_1=temp1->next;
        Node *temp2_2=temp2->prev;

        delete temp1;
        delete temp2;
        temp1=temp1_1;
        temp2=temp2_2;
        length-=2;
        if (length ==2)
        {
            delete temp1;
            delete temp2;
            length =0;
            break;
        }
        
        else if(length ==1)
        {
            delete temp1;
            length =0;
            break;
        
        }

    }
    head = nullptr;
    tail = nullptr;
}
void Double_linked_list::print(){
Node * temp=head;
for(;temp!=nullptr;temp=temp->next)
{
    std::cout<<temp->data;
}

}
void Double_linked_list::Reverse_print(){
Node * temp=tail;
    for(;temp!=nullptr;temp=temp->prev)
        {
            std::cout<<temp->data;
        }
}

void Double_linked_list::insert_front(int value){
    Node * n=new Node(value);
    if(head==nullptr)
    {   
        head=n;
        tail=head;
        return;
    }
    else
    {
       
        n->next=head;
        head->prev=n;
        head=n;
        n->prev=nullptr;
    }
    length++;
    //debug_insert();
}
void Double_linked_list::insert_end(int value)
{
    Node *n=new Node(value);

    if (tail == nullptr)
    {
        head = tail = n;
    }
    else
    {
        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    length++;
}


void Double_linked_list::insert_before_index(int value , int index){




}


void Double_linked_list:: link(Node* First,Node *second)
    {
        if(First)
            First->next=second;

        if(second)
            second->prev=First;
    }

void Double_linked_list::insert_sorted(int value)
{
    Node * n=new Node(value);
    if(head==nullptr)
    {
      head=tail=n;
      length++;
      return;
    }
    if(n->data <= head->data)
    {
        // n->next=head;
        // head->prev=n;
        // head=n;
        link(n, head);
        head = n;
        length++;
        return;
    }
    else if((n->data >= tail->data))
    {
        // tail->next=n;
        // n->prev=tail;
        // n->next=nullptr;
        // tail=n;
        link(tail,n);
        tail=n;
        length++;
        return;
    }
    else if(n->data < tail->data  && tail->prev->data <=n->data)
    {
        n->prev=tail->prev;
        tail->prev=n;
        n->prev->next=n;
        n->next=tail;
        
        length++;
        return;
    }
     // Insert before the first node whose data >= value
    Node* cur = head->next;
    for(;cur;)
    {    if (value <= cur->data)
        {
            Node* prv = cur->prev;
            //you handle next,prev of n 
            link(prv, n);
            link(n,cur);
            length++;
            return;
        }
        cur = cur->next;
    }    
}

//insert at index or place
void Double_linked_list::embedded_after( Node * before_node,int value)
{
     
      Node * after_node=new Node(value);
      for( Node * cur=head;cur ;cur=cur->next )
      {
        if(cur==before_node )
        { 
 
        after_node->next=before_node->next;
        before_node->next->prev=after_node;
        link(before_node,after_node);
         return;
        }
      }
}

void Double_linked_list::delete_front()
{
    if(!head)
    {
    
      return;
    } 
    Node * temp= head->next;
    delete head;
    head=temp;
    length--; 
//after delete the last element Dangling pointer 
//solve this pointer  
    if (head)
        head->prev = nullptr;
    else
        head=tail = nullptr;

} 
void Double_linked_list::delet_end()
{
   if(!head)
    return ;
  
    Node * T_=tail->prev;
    delete tail;
    tail=T_;
    tail->next=nullptr;
    length--;
  
   if(!length)
    head=tail=nullptr;

}


void Double_linked_list::delete_and_link_utility()
{




}

void Double_linked_list::delete_with_key(int key)
{

    Node * n =head;
    for (;n;n=n->next)
    {
         Node* next = n->next;
        if(key==n->data)
        {
            if(n==head)
                {
                head=head->next;
               
               if (head)
               {
                head->prev=nullptr;
               }
                else
                head=tail;
            
                }
            else if(n==tail)
                {
                tail=tail->prev;
                if(tail)
                tail->next=nullptr;
                else
                head=tail;

                }
            else
            {   n->next->prev=n->prev;
                n->prev->next=n->next;
            }


            delete n;
            length--;
        }
        n=next;
    }
}

 
void Double_linked_list::delete_even_Position()
{
      if (!head)
        return;
     
       
    for (Node* n = head->next; n ;)
    {
        Node *temp = n->next  ;
              
        cout << "Deleting node: " << n->data << endl;

        n->prev->next = temp;

        if (temp)
            temp->prev = n->prev;
        else
            tail = n->prev;

        delete n;
        //  n = temp ? temp->next : nullptr;
        if (temp != nullptr)
             n = temp->next;
        else
             n = nullptr;

        length--;
      
    }
}
    
 

 