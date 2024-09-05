#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100


using namespace std;

void ievads(int mas[], int n){
int i;    
cout<<"\nMas'iva ievads: ";
for (i=0;i<n;i++) {
cout<<"mas["<<i<<"]=";
cin>>mas[i];}
    }

//-------------    



void izvads(int mas[], int n){
int i;
cout<<"\nMas'iva izvads: ";
for (i=0;i<n;i++) cout<<mas[i]<<" ";
    }

//-------------    


void linearais(int mas[], int n, int x){
int i, index;    
for (i=0; i<n && mas[i]!=x; i++);
if (mas[i]==x){
    index = i;
    cout<<"\nAtrada pēc indeksa: "<<index;}
else
    cout<<"\nNeatrada!";



}

//----------------
int main(){
int mas[N];
int n, x;
cout<<"Mas'iva izm'ers: "; cin>>n;
cout<<"\nMeklejamais cipars: "; cin>>x;

ievads(mas, n);
izvads(mas, n);
linearais(mas, n, x);
system("pause>nul");
return 0;
}