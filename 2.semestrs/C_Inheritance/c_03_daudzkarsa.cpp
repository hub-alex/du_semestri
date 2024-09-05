#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdio.h>
#include <ctime>
#define N 100

using namespace std;
class Mammal {
  public:
    Mammal()
    {
      cout << "Mammals can give direct birth." << endl;
    }
};

class WingedAnimal {
  public:
    WingedAnimal()
    {
      cout << "Winged animal can flap." << endl;
    }
};

class Bat: public Mammal, public WingedAnimal {
private: string name;

public:
    void set_name(string x);
    string get_name();

};
    void Bat::set_name(string x){name = x;}
    string Bat::get_name(){return name;}




//-------------------------
int main()
{
    Bat b1;
    b1.set_name("Vampir1");
    cout<<"Bat name:"<<b1.get_name();
    //system("pause>>nul");
    return 0;
    }
