#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100

using namespace std;


void ievads_gen(int mas[], int n){
int i, min, max;    
cout<<endl<<"Masīva ievads: ";
cout<<endl<<"Ievadiet MIN robezu :";cin>>min;
cout<<"Ievadiet MAX robezu :";cin>>max;
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

void Shell_alg(int n, int mas[]){
int i, j, k, solis, z;

izvads(mas, n);
for(solis=1; solis<=n/2-solis; solis=solis*2);
for (solis=solis; solis>=1; solis=solis/2){

    cout<<"\n solis="<<solis<<endl;


for(i=0; i<solis; i++){

for (j=i; j<n-solis; j=j+solis)//kr. uz labo
{
    if(mas[j+solis]<mas[j]) //apmaiņa
    {
        z=mas[j+solis];
        mas[j+solis]=mas[j];
        mas[j]=z;
        izvads(mas, n);

        for(k=j; k>=solis; k=k-solis){//uz kr.
            if (mas[k]<mas[k-solis])
            {
                z=mas[k];
                mas[k]=mas[k-solis];
                mas[k-solis]=z;
            }//if
        izvads(mas, n);    
        }//k

    }//if
    izvads(mas, n);
}//j
}//i
}//solis
}

//--------------------------------    



int main(){
    int mas[N];
    int n;

    srand(time(NULL));
    cout<<"Masīva izmērs: ";cin>>n;
    cout<<"Shella algoritms";

    
    ievads_gen(mas, n);
    Shell_alg(n, mas);

    cout<<endl<<"----------------"<<endl;
    izvads(mas, n);

    system("pause>nul");
    return 0;
}