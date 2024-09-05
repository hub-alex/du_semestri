#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100

using namespace std;

void ievads(int mas[], int n){
    int i;    
    cout << endl << "Masīva ievads: ";
    for (i = 0; i < n; i++) {
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }
}

void izvads(int mas[], int n){
    int i;
    cout << endl << "Masīva izvads: ";
    for (i = 0; i < n; i++) 
        cout << mas[i] << " ";
}

void interpolation(int mas[], int n, int x){
    int kreisa = 0;
    int laba = n - 1;

    int pos = kreisa + (((double)(laba - kreisa) / (mas[laba] - mas[kreisa])) * (x - mas[kreisa]));
    while (kreisa <= laba && mas[pos]!=x) {
  
        if (mas[pos] < x)
            kreisa = pos + 1;
        else
            laba = pos - 1;
            pos = kreisa + (((double)(laba - kreisa) / (mas[laba] - mas[kreisa])) * (x - mas[kreisa]));
    }
        if (mas[pos] == x) {
            cout << endl << "Atrada pēc indeksa: " << pos;
        }
        else cout << endl << "Neatrada!";
}

int main(){
    int mas[N];
    int n, x;
    char atbilde;
    cout << "Masīva izmērs: "; cin >> n;
    ievads(mas, n);
    cout << endl << "Meklejamais cipars: "; cin >> x;
    izvads(mas, n);
    interpolation(mas, n, x);
    system("pause>nul");
    return 0;
}