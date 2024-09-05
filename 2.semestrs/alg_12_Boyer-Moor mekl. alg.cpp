#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cstring>
#define N 1000

using namespace std;

void boyerMoorSearch(char teksts[], char vards[]) {
    char nobide[256]; // Массив для хранения смещений
    int n, m, i, j, k;

    n = strlen(teksts);
    m = strlen(vards);
    cout << endl << "Teksta garums: " << n;
    cout << endl << "Vārda garums: " << m;

    // Вычисление смещений
    for (i = 0; i < 256; ++i)
        nobide[i] = m; // Инициализация смещений

    for (i = 0; i < m - 1; ++i)
        nobide[vards[i]] = m - 1 - i; // Установка смещений для каждого символа в слове

    // Поиск
    i = m - 1; // Начинаем с конца слова
    while (i < n) {
        k = i; // Используем k для проверки символов в слове
        j = m - 1; // Используем j для проверки символов в слове
        while (j >= 0 && teksts[k] == vards[j]) { // Пока символы совпадают, двигаемся к началу слова
            --k;
            --j;
        }
        if (j < 0) { // Если j < 0, значит, слово найдено
            cout << endl << "Vārds atrasts sākot no pozīcijas " << k + 1;
            i += nobide[teksts[i]]; // Сдвигаем i на следующую позицию после найденного слова
        } else {
            i += nobide[teksts[i]]; // Сдвигаем i на основе таблицы смещений
        }
    }
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

    boyerMoorSearch(teksts, vards);
    system("pause>nul");
    return 0;
}

/*Boyer Moore algoritms
• Robert S. Boyer, J. Strother Moore 1977.
• Paraugs tiek bīdīts gar tekstu no kreisās uz labo pusi.
• Taču simbolu salīdzināšana notiek no labās uz kreiso pusi.*/
