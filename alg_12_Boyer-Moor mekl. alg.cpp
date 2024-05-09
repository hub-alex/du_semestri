#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cstring>
#define N 1000


using namespace std;

void boyerMoorSearch(char teksts[], char vards[]){
char nobide[256];
int n,m,i,j,k;

n = strlen(teksts);
m = strlen(vards);
cout << endl << "Teksta garums: " << n;
cout << endl << "Vārda garums: " << m;

//nobīdes rēķināšana
for (i=m-1, k=0; i>=0; i--, k++)
    {
        cout<< endl << "k= " << k;
        for(j=0; j<k && nobide[j]!=vards[i]; j++)
        //kad mas nebija
        
        if (j==k) nobide[k] = vards[i];
    }
nobide[k++]='\0';
cout<< endl <<"Nobide: " << nobide;
//meklēšana


}



//----------------
int main(){
char teksts [N]= "Lorem Ipsum – tas ir teksta salikums, kuru izmanto poligrāfijā un maketēšanas darbos. Lorem Ipsum ir kļuvis par vispārpieņemtu teksta aizvietotāju...";
char vards[N];
char atbilde;

cout<<"Teksta meklēšanas algoritmi"<<endl<<endl;

cout<<"Dotais teksts: "<<teksts<<endl;
cout<<"Ievadiet meklējamo vārdu: ";
cin.getline(vards, N);

boyerMoorSearch(teksts, vards);
system("pause>nul");
return 0;
}


/*Boyer Moore algoritms
• Robert S. Boyer, J. Strother Moore 1977.
• Paraugs tiek bīdīts gar tekstu no kreisās uz labo pusi.
• Taču simbolu salīdzināšana notiek no labās uz kreiso pusi.*/
