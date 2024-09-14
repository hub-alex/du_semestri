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

int main() {
    Node *head = NULL;
    int darbiba;

    do {
        system("clear");
        cout << "\nLineārais saraksts\n";
        cout << "1. Izveidot head\n";
        cout << "2. Izvadīt head vērtību\n";
        cout << "3. Pievienot sākumā\n";
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