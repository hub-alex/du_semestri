#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100
#define A 20

using namespace std;

void save_file(int x){
int i;    
srand(time(NULL));
ofstream(f1);
f1.open("name_of_file.txt", ios::out);
    if (f1){
    for (i=1;i<=x;i++){
        cout<<i<<endl;
        f1<<rand()%10+1<<" ";
}
cout<<"Fails ir izveidots!"<<endl;
f1.close();
}
else cout<<"Kļūda!";
}

void open_file(int x){
    int i, info;
    char name[A]="name_of_file.txt";
    cout<<"Atveram failu: "<<name<<endl;
    ifstream (f2);
    f2.open(name, ios::in);
        for (i = 1; i <= x; i++)
        {
        f2>>info;
        cout<<info<<endl;
        }
    f2.close();

}



int main(){
int x;
cout<<"Ievadiet skaitļus: "<<endl;cin>>x;

save_file(x);
open_file(x);


system("pause>nul");
return 0;

}