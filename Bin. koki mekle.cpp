#include<iostream>
#include<cstdlib>
using namespace std; 
// Binarais meklesanas koks 

struct Node {
    int data;
    Node *left, *right;
};


Node* CreateNode (){
    Node *newNode;
    newNode = new Node;
    cout<<"\nIevadiet skaitļi, kuru pievienot: "; 
    cin>>newNode->data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

// //========= PrintTree============

void PrintTree (Node *cur){
   //LVR
   if (!cur) return;
   PrintTree (cur->left);
   cout<<cur->data;
   PrintTree(cur->right);
    }


//========= AddNode ============

Node* Addnode(Node *root) {
    Node *newNode, *cur;
    if (!root) root=CreateNode();

    else {//ja bija sakne
    newNode = CreateNode();
    cur=root;
    while(newNode->data<=cur->data && cur->left!=NULL && newNode->data>=cur->data && cur->right!=NULL){//palabot
        while(newNode->data<=cur->data && cur->left!=NULL)
        {
            cur=cur->left;
        }

        while(newNode->data>=cur->data && cur->right!=NULL)
        {
        cur=cur->right;
        }}
        
        if(newNode->data<=cur->data) cur->left=newNode;
        else cur->right=newNode;
}


    return root;
    }

int main() {
    Node *root = NULL;
    int darbiba;

    do {
        system("clear");
        cout << "\nBinārais meklēšanais koks\n";
        cout << "1. Izveidot sakni\n";
        cout << "2. Izvadīt sakni\n";
        cout << "3. Pievienot skaitli\n";
        cout << "Ievadiet darbību\n";

        cin >> darbiba;

        switch (darbiba) {
        case 1:
            if (!root) 
                root = CreateNode();
            else 
                cout << "Root jau eksistē!\n";
            cin.get();
            break;
        case 2:
            if (root)
                cout << "\nRoot vērtība: " << root->data << "\n";
            else
                cout << "\nIzveidojiet Root!\n";
            cin.get(); 
            break;
        case 3:
            root = Addnode(root);
            break;
        // case 0:
        //     PrintList(root);
        //     cin.get();
        //     break;
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