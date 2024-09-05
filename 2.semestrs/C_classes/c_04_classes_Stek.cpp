#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define Size 30


using namespace std;

class Steks
{
char st[Size]; //steka saturs
int vir; //steka virsotnes indeks
public:
void init(); //steka inicializaacija
void push(char ch); //simbola ievietošana stekaa
char pop(); //simbola izņemšana no steka
};


void Steks::init()
{
vir=0;
}


void Steks::push(char ch)
{
if (vir==Size) {cout<< "Stack is full";
return;}
st[vir]=ch;
vir++;
}

char Steks::pop()
{
if (vir==0) {cout<< "Stack is empty"; return
0;}
vir--;
return st[vir];
}




int main()
{
    int i;
    Steks s1,s2;
    s1.init(); s2.init();
    for (i=0;i<27;i++)
    s1.push(i);
    
    s2.push('1');
    cout<<"Steka s1 elementi:\n";
    for (i=0;i<27;i++)
    cout<<s1.pop()<<" "; cout<<"\n";
    cout<<"Steka s2 elementi:\n";
    for (i=0;i<1;i++)
    cout<<s2.pop()<<" "; cout<<"\n";
    system("Pause");


    return 0; 
}