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

void select_sort(int n, int mas[]){
int i, j, min, index;
   
for(i=0; i<n; i++){
    min=mas[i];
    index = i; 

        for (j=1+i; j<n; j++){
            if (mas[j]<min){
                    min = mas[j];
                    index = j;

            }//if
        }//for
        

    mas[index]=mas[i];
    mas[i]=min;
    }

}//function

//--------------------------------    


int main(){
    int mas[N];
    int n;

    srand(time(NULL));
    cout<<"Masīva izmērs: ";cin>>n;
    cout<<"Select Sort";
    ievads_gen(mas, n);
    select_sort(n, mas);
    cout<<endl<<"----------------"<<endl;
    izvads(mas, n);

    //system("pause>nul");
    return 0;
}