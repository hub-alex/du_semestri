#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cstring>
#define N 1000

using namespace std;

void naiva_search(char teksts[], char vards[]) {
    int i, j, n, m;
    bool atrada = false; 
    n = strlen(teksts);
    m = strlen(vards);
    cout << "Teksta garums:" << n << endl;
    cout << "Vārda garums:" << m << endl;

    for(i = 0; i <= n - m && !atrada; i++) {
        for (j = 0; j < m && teksts[i + j] == vards[j]; j++);
        if (j == m) {
            atrada = true;
        }
    }

    if (atrada)
        cout << "Atrada!!" << endl;
    else
        cout << "Neatrada!!" << endl;
}

//----------------
int main() {
    char teksts[N] = "Lorem Ipsum – tas ir teksta salikums, kuru izmanto poligrāfijā un maketēšanas darbos. Lorem Ipsum ir kļuvis par vispārpieņemtu teksta aizvietotāju...";
    char vards[N];
    char atbilde;

    cout << "Teksta meklēšanas algoritmi" << endl << endl;

    cout << "Dotais teksts: " << teksts << endl;
    cout << "Ievadiet meklējamo vārdu: ";
    cin.getline(vards, N);

    naiva_search(teksts, vards);
    system("pause>nul");
    return 0;
}