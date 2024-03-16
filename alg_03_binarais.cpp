#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100


using namespace std;

void ievads(int mas[], int n){
int i;    
cout<<endl<<"Masīva ievads: ";
for (i=0;i<n;i++) {
cout<<"mas["<<i<<"]=";
cin>>mas[i];
}
    }
//----------------------------------    

void izvads(int mas[], int n){
int i;
cout<<endl<<"Masīva izvads: ";
for (i=0;i<n;i++) cout<<mas[i]<<" ";
    }

//--------------------------------    


void binarais(int mas[], int n, int x){
int i, kreisa=0, laba=n-1;

    for(i=(kreisa+laba)/2;kreisa<=laba && mas[i]!=x;i=(kreisa+laba)/2){
    if (mas[i]< x) kreisa = i+1;
             else laba=i-1;
        }
cout<<endl<<endl;
if (mas[i]==x)
    cout<<endl<<"Atrada pēc indeksa: "<<i;
else
    cout<<endl<<"Neatrada!";

}


//-------------------------
int main(){
int mas[N];
int n, x, alg;
char atbilde;
cout<<"Masīva izmērs: "; cin>>n;
ievads(mas, n);
cout<<endl<<"Meklejamais cipars: "; cin>>x;

izvads(mas, n);
binarais(mas, n, x);

system("pause>nul");
return 0;
}