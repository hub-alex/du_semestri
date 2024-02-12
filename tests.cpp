#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100

using namespace std;

int main(){
int mas[N];
int x, i;
srand(time(NULL));

ofstream(f1);
cout<<"Ievadiet skaitļus: "<<endl;cin>>x;

f1.open("name_of_file.txt", ios::out);
    if (f1){
    for (i=1;i<=x;i++){
        cout<<i<<endl;
        f1<<rand()%10+1<<" ";
}
f1.close();
}
else cout<<"Kļūda!";

system("pause>nul");
return 0;

}