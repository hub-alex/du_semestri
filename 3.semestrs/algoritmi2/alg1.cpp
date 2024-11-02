#include<iostream>
#include<cstdlib>
using namespace std; 
// lin. saraksts

struct Node {
    int data;
    Node *link;
};

//========= CreateNode ============

Node* CreateNode (){
    Node *newNode;
    newNode = new Node;
    cout<<"\nIevadiet skaitļi, kuru pievienot: "; 
    cin>>newNode->data;
    newNode->link=NULL;
    return newNode;
}

//========= PrintList ============

void PrintList (Node *head){
    Node *cur = head;
    cout << "\nSaraksta elementi: "; 
    while (cur != NULL) {
        cout << cur->data << ", ";
        cur = cur->link;
    }
}

//========= AddFirst ============

void AddFirst(Node *&head) {
    Node *create = CreateNode();
    create->link = head;
    head = create;
}

//========= DeleteFirst ============

Node *DeleteFirst(Node *&head) {
    Node *cur;
    if (head) {
        cur = head->link;
        delete head;
        cout<<"\nMezgls ir izdzests.\n Nakamais kļūva par head";
        cin.get();
        return cur;
    }
    else {
        cout<<"\n Vel nav head mezgla";
        cin.get();
        return NULL;
        }
    }
    
//========= AddLast ==========

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

//======= FindNode ========

Node *FindNode(Node *head, int x){
Node *cur;
cur = head;
while(cur && cur->data!=x) cur = cur-> link;
return cur;
}

//======= FindNode2 ========

Node *FindNode2(Node *head, int x){
Node *cur, *prev;
cur = head;
while(cur && cur->data!=x) {
    prev = cur;
    cur = cur-> link;
    }

return prev;
}

//======= AddAfter ========

void AddAfter(Node *&head) {
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

//======= AddBefore ========

Node *AddBefore(Node *&head) {
    Node *newNode, *cur, *prev;
    int x;
    cout<<"\nPirms kura skaitļa pievienot: "; 
    cin>>x;
    
    if (!head) {
        cout<<"\nSaraksts tukšs!";
        cin.get();
        return head;
    }
    
    cur = FindNode(head, x);
    if (!cur) {
        cout<<"\n Tada skaitļa nav!";
        cin.get();
        return head;
    }
    
    newNode = CreateNode();
    prev = FindNode2(head, x);
    if (cur == head) {
        newNode->link = head;
        head = newNode;
    } else {
        newNode->link = prev->link;
        prev->link = newNode;
    }
    return head;
}

//======== DeleteLast ===========

Node *DeleteLast(Node *&head) {
    Node *cur, *prev;
    cur = head;
    if (!head) {
        cout<<"\nNav head";
        cin.get();
        return NULL;
    }
    //ja viens mezgls
    if (head->link==NULL) { 
        head = DeleteFirst(head);
        return head;
    } 
        //ja daudz mezglu
        while(cur->link!=NULL){
            prev = cur;
            cur = cur->link;
        }
        prev->link=NULL;
        delete cur;
        cout<<"\nMezgls ir izdzests";
        cin.get();
        return head;
}

//======== DeleteAfter ===========

void DeleteAfter (Node *head) {
    int x;
    Node *y, *cur;
    cout<<"\nPec kura skaitla dzest: "; cin>>x; 
    y = FindNode(head,x);
    if(y){
        if(y->link!=NULL) 
        {
            cur=y->link;
            y->link=cur->link;
            delete cur;
            cout<<"\nIzdzests.";                
            }
        else {
            cout<<"\nNav ko dzest!";
            cin.get();
        }
        }
    else cout<<"\nNav tada skaitla";
        cin.get();
}

//----------- DeleteBefore --------------
Node *DeleteBefore(Node *head) {
    if (!head || !head->link) {
        cout<<"\nSaraksts ir tukšs vai satur tikai vienu elementu!";
        cin.get();
        return head;
    }
    
    int x;
    Node *y, *cur, *prev;
    cout<<"\nPirms kura skaitļa dzest: "; 
    cin>>x;
    
    y = FindNode(head, x);
    if (!y) {
        cout<<"\nTāda skaitļa nav!";
        cin.get();
        return head;
    }
    
    if (y == head) {
        cout<<"\nPirms pirmā elementa nevar dzēst!";
        cin.get();
        return head;
    }
    
    cur = FindNode2(head, x);
    if (cur == head) {
        head = y;
        delete cur;
    } else {
        prev = FindNode2(head, cur->data);
        prev->link = y;
        delete cur;
    }
    
    cout<<"\nIzdzests.";
    cin.get();
    return head;
}



//======= main ========

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
        cout << "5. Pievienot pēc (AddAfter)\n";
        cout << "6. Pievienot pirms (AddBefore)\n";
        cout << "7. Delete first node\n";
        cout << "8. Delete last node Nodu\n";
        cout << "9. Delete after node\n";    
        cout << "10. Delete before node\n";
        cout << "11. Sameklēt mezglu\n";
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
        case 6:
            head = AddBefore(head);
            // cin.get();
            break;
        case 7:
            head = DeleteFirst(head);
            break;
        case 8:
            head = DeleteLast(head);
            break;
        case 9: 
            if(head) DeleteAfter(head); 
            else cout<<"\nSaraksts tukšs"; 
            break;
        case 10:
            if(head && head->link) 
                head = DeleteBefore(head); 
            else 
                cout<<"\nSaraksts tukšs vai satur tikai vienu elementu"; 
            break;

        case 11:
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