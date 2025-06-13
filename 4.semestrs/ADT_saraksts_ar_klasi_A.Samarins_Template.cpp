#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
struct Node {
        T data;
        Node<T>* link;
    };

template <typename T>
class NodeList {
    private:
        Node<T>* head;

    public:
        NodeList() {
            head = NULL;
        }

        Node<T>* CreateNode() {
            Node<T>* newNode = new Node<T>;
            cout << "\nIevadiet skaitli, kuru pievienot: ";
            cin >> newNode->data;
            newNode->link = NULL;
            return newNode;
        }

        void AddFirst() {
            Node<T>* newNode = CreateNode();
            newNode->link = head;
            head = newNode;
        }

        void AddLast() {
            Node<T>* newNode = CreateNode();
            if (!head) {
                head = newNode;
            } else {
                Node<T>* cur = head;
                while (cur->link) {
                    cur = cur->link;
                }
                cur->link = newNode;
            }
        }

        Node<T>* FindNode(T x) {
            Node<T>* cur = head;
            while (cur && cur->data != x) {
                cur = cur->link;
            }
            return cur;
        }

        Node<T>* FindPrevNode(T x) {
            Node<T>* cur = head;
            Node<T>* prev = NULL;
            while (cur && cur->data != x) {
                prev = cur;
                cur = cur->link;
            }
            return prev;
        }

        void AddAfter() {
            T x;
            cout << "\nPec kura pievienot: ";
            cin >> x;
            Node<T>* cur = FindNode(x);
            if (!cur) {
                cout << "\nTada skaitļa nav!";
                return;
            }
            Node<T>* newNode = CreateNode();
            newNode->link = cur->link;
            cur->link = newNode;
        }

        void AddBefore() {
            T x;
            cout << "\nPirms kura pievienot: ";
            cin >> x;
            Node<T>* cur = FindNode(x);
            if (!cur) {
                cout << "\nTada skaitļa nav!";
                return;
            }

            Node<T>* newNode = CreateNode();

            if (cur == head) {
                newNode->link = head;
                head = newNode;
            } else {
                Node<T>* prev = FindPrevNode(x);
                newNode->link = cur;
                prev->link = newNode;
            }
        }

        void DeleteFirst() {
            if (!head) {
                cout << "\nNav ko dzēst!";
                return;
            }
            Node<T>* tmp = head;
            head = head->link;
            delete tmp;
            cout << "\nPirmais mezgls dzēsts!";
        }

        void DeleteLast() {
            if (!head) {
                cout << "\nSaraksts ir tukšs!";
                return;
            }
            if (!head->link) {
                DeleteFirst();
                return;
            }

            Node<T>* cur = head;
            Node<T>* prev = NULL;
            while (cur->link) {
                prev = cur;
                cur = cur->link;
            }
            prev->link = NULL;
            delete cur;
            cout << "\nPedejais mezgls dzēsts!";
        }

        void DeleteAfter() {
            T x;
            cout << "\nPec kura skaitļa dzēst: ";
            cin >> x;
            Node<T>* cur = FindNode(x);
            if (cur && cur->link) {
                Node<T>* tmp = cur->link;
                cur->link = tmp->link;
                delete tmp;
                cout << "\nMezgls pēc " << x << " dzēsts!";
            } else {
                cout << "\nNav ko dzēst pēc si skaitļa!";
            }
        }

        void DeleteBefore() {
            T x;
            cout << "\nPirms kura skaitļa dzēst: ";
            cin >> x;

            if (!head || head->data == x) {
                cout << "\nNav ko dzēst pirms!";
                return;
            }

            Node<T>* cur = FindNode(x);
            Node<T>* prev = FindPrevNode(x);

            if (prev == head) {
                delete head;
                head = cur;
            } else {
                Node<T>* prePrev = FindPrevNode(prev->data);
                prePrev->link = cur;
                delete prev;
            }
            cout << "\nMezgls pirms " << x << " dzēsts!";
        }

        void DeleteAll() {
            Node<T>* cur;
            while (head) {
                cur = head;
                head = head->link;
                delete cur;
            }
            cout << "\nSaraksts ir izdzēsts!";
        }

        void PrintList() {
            Node<T>* cur = head;
            cout << "\nSaraksts: ";
            while (cur) {
                cout << cur->data << " ";
                cur = cur->link;
            }
            cout << "\n";
        }

        void List() {
            int count = 0;
            Node<T>* cur = head;
            while (cur) {
                count++;
                cur = cur->link;
            }
            cout << "\nElementu skaits sarakstā: " << count;
        }
};

int main() {
    NodeList<int> saraksts;
    int darbiba;
    do {
        cout << "\nADT saistitais vienvirziena saraksts ar klasi\n";
        cout << "1. Pievienot sakuma (AddFirst)\n";
        cout << "2. Pievienot beigas (AddLast)\n";
        cout << "3. Pievienot pec (AddAfter)\n";
        cout << "4. Pievienot pirms (AddBefore)\n";
        cout << "5. Dzest no sakuma (DeleteFirst)\n";
        cout << "6. Dzest no beigam (DeleteLast)\n";
        cout << "7. Dzest pec (DeleteAfter)\n";
        cout << "8. Dzest pirms (DeleteBefore)\n";
        cout << "9. Izvadit saraksta garumu (List)\n";
        cout << "10. Izvadit sarakstu (PrintList)\n";
        cout << "11. Dzest visu sarakstu (DeleteAll)\n";
        cout << "100. Par lietotni\n";
        cout << "0. Iziet\n";
        cout << "Izveleties darbibu: ";
        cin >> darbiba;

        switch (darbiba) {
        case 1: system("clear"); saraksts.AddFirst(); break;
        case 2: system("clear"); saraksts.AddLast(); break;
        case 3: system("clear"); saraksts.AddAfter(); break;
        case 4: system("clear"); saraksts.AddBefore(); break;
        case 5: system("clear"); saraksts.DeleteFirst(); break;
        case 6: system("clear"); saraksts.DeleteLast(); break;
        case 7: system("clear"); saraksts.DeleteAfter(); break;
        case 8: system("clear"); saraksts.DeleteBefore(); break;
        case 9: system("clear"); saraksts.List(); system("pause>nul"); break;
        case 10: system("clear"); saraksts.PrintList(); system("pause>nul"); break;
        case 11: system("clear"); saraksts.DeleteAll(); system("pause>nul"); break;
        case 100: 
            system("clear");
            cout << "Lietotni izveidoja Aleksandrs Samarins, 2. kurss, DU\n";
            break;
        case 0: cout << "Lietotne pabeigta."; break;
        default: cout << "Nepareiza izvele!"; system("pause>nul");
        }
    } while (darbiba != 0);

    return 0;
}