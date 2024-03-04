#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <fstream>
#define N 100

using namespace std;

void ievads(int mas[], int n) {
    cout << "Masīva ievads:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }
}

// Функция линейного поиска с барьером
int linearais_ar_barjeru(int mas[], int n, int key) {
    int pedejais = mas[n - 1];
    mas[n - 1] = key; // Установка барьера
    int i = 0;

    while (mas[i] != key) {
        i++;
    }

    mas[n - 1] = pedejais; // Восстановление последнего элемента

    if (i < n - 1 || mas[n - 1] == key) {
        return i; // Элемент найден
    } else {
        return -1; // Элемент не найден
    }
}

int main() {
    int mas[N];
    int n;
    int key;

    cout << "Masīva izmērs: " << endl;
    cin >> n;

    ievads(mas, n);

    cout << "Meklejamais cipars: ";
    cin >> key;

    int result = linearais_ar_barjeru(mas, n + 1, key); // Используем n+1, так как добавляем барьер
        if (result != -1) {
            cout << "Atradam elementu pēc indeksa: " << result << endl;
        } else {
            cout << "Neatradam masivā ciparu" << endl;
        }

        cout << "----------------" << endl << endl;
        return 0;
}