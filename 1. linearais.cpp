#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <fstream>
#define N 100

using namespace std;

void ievads(int mas[], int n){
int i;
    cout<<"Masīva ievads:"<<endl;

    for(i=0;i<n;i++){
    cout<<"mas["<<i<<"] = ";
    cin>>mas[i];

    }
}


int main()
{
    int mas[N];
    int n;

    cout<<"Masīva izmērs: "<<endl;
    cin>>n;
    
    ievads(mas, n);
    
    
    cout<"----------------";
    cout<<endl<<endl;
    return 0;
}
