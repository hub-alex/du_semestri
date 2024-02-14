#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 200
#define A 20


using namespace std;
void save_file(){

int i;
char file_name[A] = "kontr.txt";
ofstream(f1);
if (f1){
cout<<"Rakstam failā: "<<file_name<<endl<<endl;

f1.open(file_name, ios::out);
f1<<1<<" "<<100<<" ";
for (i=1; i<=20; i++){
    if (i==20)
    {
        f1<<i*5<<" ";
        f1<<(20-i)*5;
    }
    else{
    f1<<i*5<<" ";
    f1<<(20-i)*5<<" ";
    }
}

f1.close();
}

else
{
   cout<<"Kļūda!";
}
}

void open_file(){

int i;
char file_name[A] = "kontr.txt";
ifstream(f2);
if (f2){
cout<<"Atveram failu: "<<file_name<<endl;

f2.open(file_name, ios::in);
do
{
    f2>>i;
    cout<<i<<" ";
} while (!f2.eof());

f2.close();
}

else
{
   cout<<"Kļūda!";
}
}


void open_file_with_zero(){

int i, x;
char file_name1[A] = "kontr.txt";
char file_name2[A] = "kontr_0_cipari.txt";
int mas[N];
ifstream(f3);
ofstream(f4);

if (f3){
cout<<endl<<"Atveram failu "<<file_name1<<endl;

f3.open(file_name1, ios::in);
f4.open(file_name2, ios::out);
cout<<"Rakstam failā "<<file_name2<<" ciparus ar 0"<<endl;
do
{
    f3>>i;
    if (i%10==0)
    {
        f4<<i<<" ";
        cout<<i<<" "; 
    }
    
} while (!f3.eof());

f3.close();
f4.close();

}
else
{
   cout<<"Kļūda!";
}
}


int main(){

save_file();
open_file();
open_file_with_zero();


system("pause>nul");
return 0;
}