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

void ievads_gen(int mas[], int n){
int i, min, max;    
cout<<endl<<"Masīva ievads: ";
cout<<endl<<"Ievadiet MIN robezu :";cin>>min;
cout<<endl<<"Ievadiet MAX robezu :";cin>>max;
for (i=0;i<n;i++) {
mas[i] = rand()%(max-min+1)+min;
}
    }
//----------------------------------    

void izvads(int mas[], int n){
int i;
cout<<endl<<"Masīva izvads: ";
for (i=0;i<n;i++) cout<<mas[i]<<" ";
    }

//--------------------------------    


void burbulits(int mas[], int n){ //no kreisas uz labo pusi
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
        izvads(mas, n);   
        }
        }
//izvads(mas, n);    
}
}

//--------------------------------  


void burbulits2(int mas[], int n){ //no labas uz kreiso pusi
int i, j, z, apmaina=1;
for (i = 1; i < n && apmaina == 1; i++)
{
    cout<<"\nk = "<<i;
    apmaina = 0;
    for(j=n-1; j>i-1; j--){
        if (mas[j-1]>mas[j])
        {z = mas[j-1]; //5
        mas[j-1]=mas[j]; //4
        mas[j]=z; //4
        apmaina = 1;
        izvads(mas, n);   
        }
        }
//izvads(mas, n);    
}
}

//-------------------------

void sheikeris(int mas[], int n){
int i, j, z, k, apmaina=1;

for (k = 0; k < n/2 && apmaina == 1; k++)
{
    cout<<"\nk = "<<k;
    apmaina = 0;
    //no Kreisas uz labo puses
    for(i=k; i<n-k-1; i++){
        if (mas[i+1]<mas[i])
        {z = mas[i+1];
        mas[i+1]=mas[i];
        mas[i]=z;
        apmaina = 1;
        izvads(mas, n);   
        }
        } //i

    //no labas uz kreiso  
    for(j=n-1-k; j>k; j--){
    if (mas[j-1]>mas[j])
    {z = mas[j-1]; //5
    mas[j-1]=mas[j]; //4
    mas[j]=z; //4
    apmaina = 1;
    izvads(mas, n);   
    }
    }// j

}  
}

//-------------------------


int main(){
int mas[N];
int n;

srand(time(NULL));
cout<<"Masīva izmērs: "; cin>>n;
cout<<"Sheikeris";

ievads_gen(mas, n);
//ievads(mas, n);
//burbulits(mas, n);
//burbulits2(mas, n);
sheikeris(mas, n);


system("pause>nul");
return 0;
}