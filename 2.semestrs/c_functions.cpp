#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cstdarg>
#define N 100

using namespace std;


int input(){
    int x;
    cout<<"Input int number: "<<endl; cin>>x;
    return x;
}
//------------------
int summa(int x, int y){
    return x + y;
}

int summa2(int x, int y=7){
    return x + y;
}

int summa3(int count, ...){
    int summm = 0;
    va_list tt; //def. obj. as list
    va_start(tt, count); //inic. list
    for (int j = 1; j <= count; j++)
        summm += va_arg(tt, int);
    va_end(tt);
    return summm;
}
//---------------

long factorial (long a){
    if (a > 1) 
    return (a * factorial (a -1));
else return (1); 
}

//------------------
 
int main(){
    int x, y;
    /*x = input();
    y = input();
    
    //cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"Result of summa: "<<summa(x, y)<<endl;
    cout<<"Result of summa2, where default y = 7: "<<summa2(x)<<endl;*/
    cout<<"Result of summa3: "<<summa3(2, 13, 5)<<endl;
    //cout<<"Factorial = "<<factorial(5)<<endl;
    //system("pause>nul");
    return 0;
}