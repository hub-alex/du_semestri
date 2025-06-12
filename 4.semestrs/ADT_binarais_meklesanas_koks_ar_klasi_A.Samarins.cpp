#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};


class Tree {
    private:
        Node* root;

    public:
        Tree(){
            root = NULL;
        }
    
        Node* CreateNode()
            {
                if (!root) {
                Node* newNode = new Node;
                cout << "\nIevadiet skaitli, kuru pievienot:  ";
                cin >> newNode->data;
                newNode->left = NULL;
                newNode->right = NULL;
                return newNode;
                }
                else {
                    system("clear");
                    cout << "\nSakne jau eksiste";
        }
            }

        //------------------------------
        void PrintTree(Node* cur)
            {
                if (!cur) return;
                PrintTree(cur->left);
                cout << cur->data << " ";
                PrintTree(cur->right);
                PrintTree(root);
            }


        //--------------------------------
        Node* AddNode(Node* root)
        {
            Node* newNode, * cur;
            if (!root) root = CreateNode();
            else {
                newNode = CreateNode();
                cur = root;
                while ((newNode->data <= cur->data && cur->left != NULL) or (newNode->data > cur->data && cur->right != NULL)) {
                    while (newNode->data <= cur->data && cur->left != NULL) {
                        cur = cur->left;
                    }
                    while (newNode->data > cur->data && cur->right != NULL) {
                        cur = cur->right;
                    }
                }
                if (newNode->data <= cur->data) cur->left = newNode;
                else cur->right = newNode;
            }

            return root;
        }
        //---------------------------

        void FindNode(Node* root)
        {
            Node* cur;
            int x;
            cout << "Kuru skaitli meklesim?: "; cin >> x;
            cur = root;
            while (cur && cur->data != x && cur->left != NULL && cur->right != NULL) {
                if (cur->data > x && cur->left != NULL) {
                    cur = cur->left;
                }
                else if (cur->data < x && cur->right != NULL) {
                    cur = cur->right;
                }
            }
            if (cur->data == x) cout << "Rezultāts: atrada";
            else if (!cur || cur->data!=x) cout << "Rezultāts: neatrada";
        }
            
        //---------------------------

        Node* DeleteNode(Node* root, int x) {
            if (!root) return root; 

            if (x < root->data) {
                root->left = DeleteNode(root->left, x);
            }
            else if (x > root->data) {
                root->right = DeleteNode(root->right, x);
            }
            else {
                if (!root->left && !root->right) {
                    delete root;
                    return NULL;
                }
                else if (!root->left) {
                    Node* cur = root->right;
                    delete root;
                    return cur;
                }
                else if (!root->right) {
                    Node* cur = root->left;
                    delete root;
                    return cur;
                }
                else {
                    Node* cur = root->right;
                    while (cur->left) cur = cur->left;
                    root->data = cur->data; 
                    root->right = DeleteNode(root->right, cur->data); 
                }
            }
            return root;
        }

        //----------------------------
        void PrintTree1(Node* node, int depth = 0) {
            if (node == NULL) return;

            PrintTree1(node->right, depth + 1);

            for (int i = 0; i < depth * 4; ++i) cout << " ";
            cout << node->data << endl;

            PrintTree1(node->left, depth + 1);
        }

        //-----------------------------
        void Preorder(Node* root) {
            if (root == NULL) return;

            cout << root->data << " ";
            Preorder(root->left);
            Preorder(root->right);
        }

        //-----------------------------
        void Postorder(Node* root) {
            if (root == NULL) return;

            Postorder(root->left);
            Postorder(root->right);
            cout << root->data << " ";
        }

        //-----------------------------
        int CountNodes(Node* root)
        {
            if (root == NULL) return 0; 
            else  return 1 + CountNodes(root->left) + CountNodes(root->right);  
        }

        };


int main() {
    Tree koks;
    int darbiba;
    do {
        cout << "\n\nBinaras meklesanas koks";
        cout << "\n1. Izveidot sakni";
        cout << "\n2. Izvadit sakni";
        cout << "\n3. Pievienot skaitli";
        cout << "\n4. Meklet skaitli";
        cout << "\n5. Dzest skaitli";
        cout << "\n6. Grafiska koka izvade";
        cout << "\n7. Preorder (tiesais) izvads";
        cout << "\n8. Postorder (pretejais) izvads";
        cout << "\n9. Elementu skaits";
        cout << "\n10. Izvadit koku";
        cout << "\n100. Par lietotni";
        cout << "\n0. Pabeigt lietotni\n\n";
        cin >> darbiba;
        switch (darbiba) {
        case 1: if (!root) {
            system("clear");
            root = koks.CreateNode();
        }
            else {
                system("clear");
                cout << "\nSakne jau eksiste";
                //system("pause>nul");
        }
              break;
        case 2: if (root){
            system("clear");
            cout << "\nSaknes vertiba: " << root->data;
            }
              else cout << "\nIzveidojiet sakni";
            //system("pause>nul");
            break;
        
            case 3:  root = koks.AddNode(root);
            break;
        
            case 4: if (root){
            system("clear");
            
            koks.FindNode(root);
            }
              else cout << "\nIzveidojiet sakni";
            //system("pause>nul");
            break;
        case 5:
            if (root) {
                system("clear");
                int x;
                cout << "Kuru skaitli dzest? ";
                cin >> x;
                root = koks.DeleteNode(root, x);
            }
            else {
                cout << "Koks ir tukss!";
            }
            //system("pause>nul");
            break;
        case 6:
            if (root == NULL){
                
                cout << "\nKoks ir tukšs!";
            }
            else {
                
                cout << "\nKoka struktura:\n";
                koks.PrintTree1(root); 
            }
            //system("pause>nul");
            break;
        case 7:
            system("clear");
            cout << "Preorder (tiesa seciba)\n\n ";
            koks.Preorder(root);
            system("pause>nul");
            break;
        case 8:
            system("clear");
            cout << "Postorder (preteja seciba)\n\n ";
            koks.Postorder(root);
            //system("pause>nul");
            break;
        case 9:
            if (root) {
                system("clear");
                cout << "\nKoka elementu skaits: " << koks.CountNodes(root);
            }
            else {
                cout << "\nKoks ir tukss!";
            }
            //system("pause>nul");
            break;
        case 10: if (root) {
            system("clear");
            koks.PrintTree(root);
        }
               else cout << "\nIzveidojiet sakni";
            //system("pause>nul");
            break;
        case 100: 
            system("clear");
            cout << "Binary Search Tree, lietotni izveidoja Aleksandrs Samarins, 2. kurss, DU";
            //system("pause>nul");
            break;
        case 0: cout << "Lietotnes beigas"; break;
        }
    } while (darbiba != 0);


    system("pause>nul");

    return 0;
}