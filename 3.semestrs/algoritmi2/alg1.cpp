#include<iostream>
#include<cstdlib>
using namespace std; 
// lin. saraksts

struct Node {
    int data;
    Node *link;
};


Node* CreateNode (){
    Node *newNode;
    newNode = new Node;
    cout<<"\nIevadiet skaitļi, kuru pievienot: "; 
    cin>>newNode->data;
    newNode->link=NULL;
    return newNode;
}


void PrintList (Node *head){
    Node *cur = head;
    cout << "\nSaraksta elementi: "; 
    while (cur != NULL) {
        cout << cur->data << ", ";
        cur = cur->link;
    }
}


void AddFirst(Node *&head) {
    Node *create = CreateNode();
    create->link = head;
    head = create;
}


Node* AddLast(Node *&head) {
    Node *ped, *cur;
    if (!head) head=CreateNode();
    else{    ped = CreateNode();
    cur = head;
    while(cur->link!=NULL){
        cur = cur->link;
    }
    cur->link = ped;
    }
return head;
}
//===============

Node *FindNode(Node *head, int x){
Node *cur;
cur = head;
while(cur && cur->data!=x) cur = cur-> link;
return cur;
}

//===============

Node *FindNode2(Node *head, int x){
Node *cur, *prev;
cur = head;
while(cur && cur->data!=x) 
    prev = cur;
    cur = cur-> link;

return prev;
}

//===============


void *AddAfter(Node *&head) {
    Node *newNode, *cur;
    int x;
    cout<<"\nPēc kura pievienot:"; cin>>x;
    //fja

    cur = FindNode(head, x);
    if (!cur) {
        cout<<"\n Tada skaitļa nav!";
        cin.get();
                }
    else{
        newNode = CreateNode();
        newNode->link=cur->link;
        cur->link=newNode;
        }
    }

//===============

Node *AddBefore(Node *&head) {
    Node *newNode, *cur, *prev;
    int x;
    cur = FindNode(head, x);
    cur = head;
    if (!cur) {
        cout<<"\n Tada skaitļa nav!";
        cin.get();
        }
    
    else{
        newNode = CreateNode();
        //jauna f-ja
        prev = FindNode2(head, x);
        newNode->link = prev->link;
        prev->link = newNode;
        }

return head;
}


//===============


int main() {
    Node *head = NULL, *newNode, *cur;

    int darbiba, x;

    do {
        system("clear");
        cout << "\nLineārais saraksts\n";
        cout << "1. Izveidot head\n";
        cout << "2. Izvadīt head vērtību\n";
        cout << "3. Pievienot sākumā\n";
        cout << "4. Pievienot beigas\n";
        cout << "5. Pievienot pēc AddAfter\n";
        cout << "9. Sameklēt mezglu\n";
        cout << "0. Izvadīt sarakstu\n";
        cout << "99. Pabeigt programmu\n";
        cout << "Ievadiet darbību\n";
        cin >> darbiba;

        switch (darbiba) {
        case 1:
            if (!head) 
                head = CreateNode();
            else 
                cout << "Head jau eksistē!\n";
            cin.get();
            break;
        case 2:
            if (head)
                cout << "\nHead vērtība: " << head->data << "\n";
            else
                cout << "\nIzveidojiet Head!\n";
            cin.get(); 
            break;
        case 3:
            AddFirst(head);
            break;
        case 4:
            head = AddLast(head);
            cin.get();
            break;
        case 5:
            AddAfter(head);
            cin.get();
            break;
        case 9:
            cout<<"Kuru mezglu meklēt?"; cin>>x;
            cur = FindNode(head, x);
            if (!cur) {
                cout<<"\nNeatrada!";
                cin.get();
            }
            else cout<<"\nAtrada!";
            cin.get();
            break;    
        case 0:
            PrintList(head);
            cin.get();
            break;
        case 99:
            cout << "Programmas beigas!\n";
            break;
        default:
            cout << "Nepareizs ievads!\n";
            break;
        }
        cin.get();
    } while (darbiba != 99);

    return 0;
}