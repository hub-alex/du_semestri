#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100
#include "c_03_classes_functions.cpp"


using namespace std;


int main(){
    //vesels_sk x=5;
    //cout<<"Vesels skaitlis="<<x; 
    //myClass obj1;
    myClass obj1(2);
    cout<<"Skaitlis = "<<obj1.get_a()<<endl; 
    cout<<"Skaitlis = "<<obj1.get_b()<<endl; 

    cout<<endl; 
//system("pause>nul");
return 0;
}