#include <cstring>
#include <iostream>
#include <fstream>
#define N 50

using namespace std;

struct Valsts {
    char pilseta[60];
    int iedzivotajuSkaits;
    int year;
    float platiba;
};

Valsts Latvija[N];
Valsts db2[N];


void ievads() {
    Valsts valsts;

    cout << "Ievadiet Latvijas pilsētas nosaukumu: ";
    cin >> valsts.pilseta;
    cout << "Statistika par kādu gadu? ";
    cin >> valsts.year;
    cout << "Ievadiet iedzīvotāju skaitu šajā pilsētā " << valsts.year << ". gadā: ";
    cin >> valsts.iedzivotajuSkaits;
    cout << "Ievadiet pilsētas platību: ";
    cin >> valsts.platiba;

    ofstream fout("dbase.txt", ios::app);
    if (!fout) {
        cout << "Faila atveršanas kluda\n";
        return;
    }

        fout << valsts.pilseta << " "
         << valsts.iedzivotajuSkaits << " "
         << valsts.year << " "
         << valsts.platiba << endl;

    fout.close();
}


int lasit_failu() {
    ifstream fin("dbase.txt");
    if (!fin) {
        cout << "Faila atversanas kluda\n";
        cin.get();  // Izpildes apturēšana
        return -1;
    }

    int i = 0;
    while (i < N && fin >> Latvija[i].pilseta >> Latvija[i].iedzivotajuSkaits >> Latvija[i].year >> Latvija[i].platiba) {
        i++;
    }

    fin.close(); 
    return i;  // Atgriež nolasīto ierakstu skaitu
}


void izvadit_informaciju(int n_record) {
    if (n_record <= 0) {
        cout << "Nav datu, ko rādīt.\n";
        return;
    }

    cout << endl<<"Informācija par pilsētām:\n";
    for (int i = 0; i < n_record; i++) {
        cout << "Pilsēta: " << Latvija[i].pilseta << "\n";
        cout << "Gads: " << Latvija[i].year << " g.\n";
        cout << "Iedzīvotāju skaits: " << Latvija[i].iedzivotajuSkaits << " cilv. \n";
        cout << "Platība: " << Latvija[i].platiba << " km2\n\n";
    }
}


// Funkcija pilsētas meklēšanai un vidējā iedzīvotāju skaita aprēķināšana
void get_avarage(int n_record) {
    char buf[60];
    cout << "\nIevadiet pilsētas nosaukumu vai \"end\", lai beigtu: ";
    while (true) {
        cin >> buf;
        if (strcmp(buf, "end") == 0) break;

        int n_city = 0;
        int total_population = 0;
        bool not_found = true;

        for (int i = 0; i < n_record; i++) {
            if (strcmp(Latvija[i].pilseta, buf) == 0) {  // Pārbauda, vai nosaukums pilnībā sakrīt
                cout << Latvija[i].pilseta << ": "<< Latvija[i].year << ". gadā dzīvoja " << Latvija[i].iedzivotajuSkaits << " iedzīvotāju." << endl; 
                n_city++;
                total_population += Latvija[i].iedzivotajuSkaits;
                not_found = false;
            }
        }

        if (not_found) {
            cout << "Tāda pilsēta nav atrasta!!!\n";
        } else if (n_city > 0) {
            cout <<endl<< "Vidējais iedzīvotāju skaits pilsētā " << buf << " ir " << total_population / n_city << "\n";
        }

        cout << "\nIevadiet pilsētas nosaukumu vai \"end\", lai beigtu: ";
    }
}


int save_bin() {
    ifstream fin("dbase.txt", ios::in); 
    if (!fin) {
        cout << "Faila atversanas kluda\n";
        system("Pause>nul");
        return 1;
    }

    ofstream fout("dbase.bin", ios::binary);
    if (!fout) {
        cout << "Faila atversanas kluda\n";
        system("Pause>nul");
        return 1;
    }

    int i = 0;
    // Teksta faila datu lasīšana un to saglabāšana struktūrā
    while (i < N && fin >> Latvija[i].pilseta >> Latvija[i].iedzivotajuSkaits >> Latvija[i].year >> Latvija[i].platiba) {
        // Struktūras saglabāšana binārajā failā
        fout.write((char *)&Latvija[i], sizeof(Latvija[i]));
        i++;
    }

    fin.close(); 
    fout.close();
    cout << "Binārais fails ierakstīts\n";

    return 0;
}



int read_from_bin(){
    ifstream fin("dbase.bin", ios::binary);
    if (!fin) {
        cout << "Faila atversanas kluda\n";
        system("Pause>nul");
        return 1; // Kļūdas atgriešana
    }

    int i = 0;
    // Dati no binārā faila ierakstīti struktūru masīvā db2
    while (fin.read((char *)&db2[i], sizeof(db2[i]))) { // Cikla nosacījums pārbauda lasīšanas veiksmi

        cout << "Pilsēta: "<< db2[i].pilseta<<endl;
        cout << "Iedzīvotāju skaits: " << db2[i].iedzivotajuSkaits << " cilv. \n";
        cout << "Gads: " << db2[i].year << " g.\n";
        cout << "Platība: " << db2[i].platiba << " km2\n\n";

        i++;
        // Pārliecinās, ka i nesasniedz masīva db2 izmēru
        if (i >= N) break;
    }

    fin.close(); 
    return 0;
}


int main() {
    int action;
    char buf[10];

    cout << "\nIzvēlieties darbību: vai \"end\", lai beigtu: \n";
    
    while (true) {
        cout << "0 - Pievienot jaunu ierakstu tekstā failā\n";
        cout << "1 - Izvadīt informāciju no teksta faila\n";
        cout << "2 - Uzzināt vidējo iedzīvotāju skaitu pilsētā\n";
        cout << "3 - Lasīt datus no binārā faila\n";
        cout << "4 - Saglabāt datus binārā failā\n";
        cout << "Ievadiet izvēles numuru: ";
        cin >> buf;
        if (strcmp(buf, "end") == 0) break;
    

        action = stoi(buf);

        int n_record = 0;



        switch (action) {
            case 0:
                ievads();
                break;
            case 1:
                n_record = lasit_failu();
                izvadit_informaciju(n_record);
                break;
            case 2:
                n_record = lasit_failu();
                get_avarage(n_record);
                break;
            case 3:
                read_from_bin();
                break;
            case 4:
                n_record = lasit_failu(); 
                if (n_record > 0) {
                    save_bin();
                }
                break;
            default:
                cout << "Nepareiza izvēle. Lūdzu, ievadiet numuru no 0 līdz 4.\n";
                break;
        }
        cout << "\nIzvēlieties darbību: vai \"end\", lai beigtu: \n";
        
    }
    return 0;
}