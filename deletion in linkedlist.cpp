#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void traversal(Node* ptr){
while(ptr!=NULL){
    cout<<ptr->data<<" ";
    ptr=ptr->next;
}

}
//case 1 
Node* deletionAtFirst(Node* head){
    Node* ptr=head;
    head=head->next;
    delete ptr;
    return head;
}
// case 2
Node* deletionAtIndex(Node* head,int index){
   int i=0;
    Node* ptr=head;
   while(i<(index-1)){
       ptr=ptr->next;
       i++;
   }
    Node* q=ptr->next;
    ptr->next=q->next;
    delete q;
    return head;
}
//case 3
Node* deletionAtEnd(Node* head){
    Node* ptr=head;
    Node* q=head->next;
    while(q->next!=NULL){
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    delete q;
    return head;
}
//case 4
Node* insertionAfterNode(Node* head,Node* prevNode,int data){
    Node* ptr=new Node;
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}

int main()
{
    Node* head;
    Node* second;
    Node* third;
    Node* fourth;
    head=new Node;
    second=new Node;
    third=new Node;
    fourth=new Node;
    head->data=7;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=9;
    third->next=fourth;

    fourth->data=10;
    fourth->next=NULL;


    // head=deletionAtFirst(head);
    deletionAtIndex(head,1);
    // deletionAtEnd(head);
    // insertionAfterNode(head,second,45);
    traversal(head);
    return 0;
}