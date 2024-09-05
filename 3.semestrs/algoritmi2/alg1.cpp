#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node *link;
};

Node *CreateNode (){
    Node *newNode;
    newNode = new Node;
    cout<<"\nIevadiet skaitļi, kuru pievienot: "; 
    cin>>newNode->data;
    newNode->link=NULL;
    return newNode;
}

void PrintList (Node *head){
    Node *cur;
    cout<<"Saraksta elementi: \n";
    cur=head;
    while (cur!=NULL)
        {
            cout<<cur->data<<" ";
            cur = cur->link;
        }
}

int main (){
    Node *head, *newNode, *tresais, *nultais;
    head = CreateNode();
    newNode = CreateNode();
    tresais = CreateNode();
    head->link = newNode; //1 ar 2
    newNode->link = tresais;//2 ar 3
    nultais->link = head;
    PrintList(nultais);


/*
    cout<<"\nhead data="<<head->data;
    cout<<"\nhead link="<<head->link;
    cout<<"\nsizeof_link = "<<sizeof(head->link);
    cout<<"\nsizeof_data = "<<sizeof(head->data);
    */
    //systems("pause>null");
    return 0;
}