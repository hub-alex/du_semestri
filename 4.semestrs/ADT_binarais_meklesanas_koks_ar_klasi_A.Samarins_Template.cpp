#include<iostream>
#include<cstdlib>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* left, * right;
};

template <typename T>
class Tree {
    private:
        Node<T>* root;

    public:
        Tree(){
            root = NULL;
        }
    
        Node<T>* CreateNode() {
            Node<T>* newNode = new Node<T>;
            cout << "\nIevadiet skaitli, kuru pievienot: ";
            cin >> newNode->data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        void AddNode() {
            Node<T>* newNode = CreateNode();
            if (!root) {
                root = newNode;
            } else {
                Node<T>* cur = root;
                while (true) {
                    if (newNode->data <= cur->data) {
                        if (!cur->left) {
                            cur->left = newNode;
                            break;
                        }
                        cur = cur->left;
                    } else {
                        if (!cur->right) {
                            cur->right = newNode;
                            break;
                        }
                        cur = cur->right;
                    }
                }
            }
        }

        void FindNode() {
            if (!root) {
                cout << "\nKoks ir tukss!";
                return;
            }
            
            T x;
            cout << "\nKuru skaitli meklesim?: ";
            cin >> x;
            
            Node<T>* cur = root;
            while (cur) {
                if (cur->data == x) {
                    cout << "\nRezultats: atrada";
                    return;
                }
                if (x < cur->data) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }
            cout << "\nRezultats: neatrada";
        }

        Node<T>* DeleteNodeHelper(Node<T>* node, T x) {
            if (!node) return node;

            if (x < node->data) {
                node->left = DeleteNodeHelper(node->left, x);
            }
            else if (x > node->data) {
                node->right = DeleteNodeHelper(node->right, x);
            }
            else {
                if (!node->left && !node->right) {
                    delete node;
                    return NULL;
                }
                else if (!node->left) {
                    Node<T>* cur = node->right;
                    delete node;
                    return cur;
                }
                else if (!node->right) {
                    Node<T>* cur = node->left;
                    delete node;
                    return cur;
                }
                else {
                    Node<T>* cur = node->right;
                    while (cur->left) cur = cur->left;
                    node->data = cur->data;
                    node->right = DeleteNodeHelper(node->right, cur->data);
                }
            }
            return node;
        }

        void DeleteNode() {
            if (!root) {
                cout << "\nKoks ir tukšs!";
                return;
            }
            
            T x;
            cout << "\nKuru skaitli dzēst?: ";
            cin >> x;
            root = DeleteNodeHelper(root, x);
            cout << "\nSkaitlis " << x << " dzēsts!";
        }

        void PrintTreeHelper(Node<T>* node, T depth) {
            if (!node) return;

            PrintTreeHelper(node->right, depth + 1);

            for (int i = 0; i < depth * 4; ++i) cout << " ";
            cout << node->data << endl;

            PrintTreeHelper(node->left, depth + 1);
        }

        void PrintTree() {
            if (!root) {
                cout << "\nKoks ir tukšs!";
                return;
            }
            cout << "\nKoka struktura:\n";
            PrintTreeHelper(root, 0);
        }

        void PreorderHelper(Node<T>* node) {
            if (!node) return;
            cout << node->data << " ";
            PreorderHelper(node->left);
            PreorderHelper(node->right);
        }

        void Preorder() {
            if (!root) {
                cout << "\nKoks ir tukšs!";
                return;
            }
            cout << "\nPreorder (tieša secība): ";
            PreorderHelper(root);
        }

        void PostorderHelper(Node<T>* node) {
            if (!node) return;
            PostorderHelper(node->left);
            PostorderHelper(node->right);
            cout << node->data << " ";
        }

        void Postorder() {
            if (!root) {
                cout << "\nKoks ir tukšs!";
                return;
            }
            cout << "\nPostorder (preteja secība): ";
            PostorderHelper(root);
        }

        void InorderHelper(Node<T>* node) {
            if (!node) return;
            InorderHelper(node->left);
            cout << node->data << " ";
            InorderHelper(node->right);
        }

        void PrintInorder() {
            if (!root) {
                cout << "\nKoks ir tukšs!";
                return;
            }
            cout << "\nKoks (inorder): ";
            InorderHelper(root);
        }

        int CountNodesHelper(Node<T>* node) {
            if (!node) return 0;
            return 1 + CountNodesHelper(node->left) + CountNodesHelper(node->right);
        }

        void CountNodes() {
            int count = CountNodesHelper(root);
            cout << "\nKoka elementu skaits: " << count;
        }

        void DeleteAll() {
            DeleteAllHelper(root);
            root = NULL;
            cout << "\nKoks ir izdzests!";
        }

    private:
        void DeleteAllHelper(Node<T>* node) {
            if (!node) return;
            DeleteAllHelper(node->left);
            DeleteAllHelper(node->right);
            delete node;
        }
};

int main() {
    Tree <int> koks;
    int darbiba;
    do {
        cout << "\nADT binaras meklesanas koks ar klasi\n";
        cout << "1. Pievienot skaitli (AddNode)\n";
        cout << "2. Meklet skaitli (FindNode)\n";
        cout << "3. Dzest skaitli (DeleteNode)\n";
        cout << "4. Grafiska koka izvade (PrintTree)\n";
        cout << "5. Preorder (tiesais) izvads\n";
        cout << "6. Postorder (pretejais) izvads\n";
        cout << "7. Elementu skaits (CountNodes)\n";
        cout << "8. Izvadit koku (PrintInorder)\n";
        cout << "9. Dzest visu koku (DeleteAll)\n";
        cout << "100. Par lietotni\n";
        cout << "0. Iziet\n";
        cout << "Izveleties darbibu: ";
        cin >> darbiba;

        switch (darbiba) {
        case 1: system("clear"); koks.AddNode(); break;
        case 2: system("clear"); koks.FindNode(); break;
        case 3: system("clear"); koks.DeleteNode(); break;
        case 4: system("clear"); koks.PrintTree(); break;
        case 5: system("clear"); koks.Preorder(); break;
        case 6: system("clear"); koks.Postorder(); break;
        case 7: system("clear"); koks.CountNodes(); break;
        case 8: system("clear"); koks.PrintInorder(); break;
        case 9: system("clear"); koks.DeleteAll(); break;
        case 100: 
            system("clear");
            cout << "Binary Search Tree, lietotni izveidoja Aleksandrs Samarins, 2. kurss, DU\n";
            break;
        case 0: cout << "Lietotne pabeigta."; break;
        default: cout << "Nepareiza izvele!";
        }
    } while (darbiba != 0);

    return 0;
}