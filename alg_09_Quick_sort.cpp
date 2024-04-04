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

void quick_sort(int n, int mas[], int kreisa, int laba){
int i, j, vid, z;
bool apmaina=true;
izvads(mas, n);
vid=(laba+kreisa)/2;
cout<<endl<<"vid="<<mas[vid];

while(apmaina==true){
    apmaina=false;
    for(i=kreisa; i<=vid && mas[i]<=mas[vid]; i++);
    for(j=laba; j>=vid && mas[j]>=mas[vid]; j--);
    
    cout<<endl<<"kreisa: "<<mas[i];
    cout<<endl<<"laba: "<<mas[j];
        
        if (i!=j){
            z=mas[i];
            mas[i]=mas[j];
            mas[j]=z;
            apmaina=true;
        }
        
        izvads(mas, n);
}


}

//--------------------------------    



int main(){
    int mas[N];
    int n;

    srand(time(NULL));
    cout<<"Masīva izmērs: ";cin>>n;
    cout<<"Quick Sort algoritms";

    
    ievads_gen(mas, n);
    quick_sort(n, mas, 0, n-1);

    cout<<endl<<"----------------"<<endl;
    izvads(mas, n);

    system("pause>nul");
    return 0;
}