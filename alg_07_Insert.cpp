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

void insert(int n, int mas[]){
int i, j, z, k, sakartots=0;
   
for(i=1; i<n && sakartots==0; i++){

    for(j=i; j>0 && mas[j]<mas[j-1]; j--){
            if (mas[j]<mas[j-1])
            {
                z = mas[j];
                mas[j] = mas[j-1];
                mas[j-1] = z;
            }//if
            izvads(mas, n);        
        }//j
    
    for (k = 0; k < n && mas[k]<=mas[k+1]; k++);//sakartots
       if (k==n-1) sakartots=1; else sakartots=0;
    
    }//i

}//function

//--------------------------------    


int main(){
    int mas[N];
    int n;

    srand(time(NULL));
    cout<<"Masīva izmērs: ";cin>>n;
    cout<<"Insert";
    ievads_gen(mas, n);
    insert(n, mas);
    cout<<endl<<"----------------"<<endl;
    izvads(mas, n);

    //system("pause>nul");
    return 0;
}