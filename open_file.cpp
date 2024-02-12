#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;


int main(){
int n, i; //sk.skaits
cout<<"Cik skait'lu..?"<<"\n";cin>>n;
srand(time(NULL));
ofstream f1;

f1.open("skaitli_30.01.2024_1-2.txt", ios::out);
    if (f1) {//ja fails atveerts
        
        for (i=1; i<=n; i++)
        {
            if (i==n) f1<<rand()%10+1;
            else f1<<rand()%10+1<<" ";
        }
        
        cout<<"Fails ir izveidots!!";    
        cout<<"\n";    
        f1.close();

    }

else cout<<"Kl'uda!!!";
//------------------------------
//Failu nolasisana

ifstream f2;
int summa=0, x;
f2.open("skaitli_30.01.2024_1-2.txt");
    if (f2) {//ja fails atveerts
        do
        {
            f2>>x;
            cout<<x<<" ";
            summa = summa+x;
            }
        
        while (!f2.eof());
        cout<<"Fails ir nolasit!!"<<"\n";

        cout<<"Skaitlu summa ir: "<<summa;
        f2.close();
    }


system("pause>nul");
return 0;
}