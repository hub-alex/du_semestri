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


void burbulits(int mas[], int n){
int i, j, z, apmaina=1;
for (i = 1; i < n && apmaina == 1; i++)
{
    cout<<"\nk = "<<i;
    apmaina = 0;
    for(j=0; j<n-i; j++){
        if (mas[j+1]<mas[j])
        {z = mas[j+1];
        mas[j+1]=mas[j];
        mas[j]=z;
        apmaina = 1;
          
        }
        }
    izvads(mas, n); 
}

}


//-------------------------
int main(){
int mas[N];
int n;
cout<<"Masīva izmērs: "; cin>>n;
ievads(mas, n);
burbulits(mas, n);
izvads(mas, n); 
system("pause>nul");
return 0;
}