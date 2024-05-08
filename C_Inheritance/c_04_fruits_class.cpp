#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <ctime>
#define N 100

using namespace std;

enum yn {no,yes};
enum color {red, yellow, green, orange};
//color c;
char *c[]={
  "red", "yellow", "green","orange"
};

void out (enum yn x);
//bazes klase ar visiem atvertajiem elementiem
class Fruit
{public:
enum yn annual; //viengadiigs
enum yn perennial; //daudzgadiigs
enum yn tree;
enum yn tropical;
enum color clr;
char name[40];
};

// Atvasinaata klase Abols
class Apple: public Fruit
{ enum yn cooking; //kulinaarijaa
enum yn crunchy; //kraukskigs
enum yn eating;
public:
void seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e);
void show();
};


// Atvasinaata klase Apelsiins
class Orange: public Fruit
{ enum yn juice;
enum yn sour; //skaabs
enum yn eating;
public:
void seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e);
void show();
};


void Apple::seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e)
{ strcpy(name,n);
annual=no;
perennial=yes;
tree=yes;
tropical=no;
clr=c;
cooking=ck;
crunchy=crchy;
eating=e;
}


void Orange::seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e)
{ strcpy(name,n);
annual=no;
perennial=yes;
tree=yes;
tropical=no;
clr=c;
juice=j;
sour=sr;
eating=e;
}


void Apple::show()
{cout<<name<<"\nabols - "<<"\n";
cout<<"Viengadiigs augs: "; out(annual);
cout<<"Daudzgadiigs augs: "; out(perennial);
cout<<"Koks: "; out(tree);
cout<<"Tropisks augs: "; out(tropical);
cout<<"Krasa: "<<c[clr]<<"\n";
cout<<"Viegli pagatavot: "; out(cooking);
cout<<"Uz zoba kraukskigs: "; out(crunchy);
cout<<"Edams: "; out(eating);
cout<<"\n\n";
}


void Orange::show()
{cout<<name<<"\napelsins - "<<"\n";
cout<<"Viengadiigs augs: "; out(annual);
cout<<"Daudzgadiigs augs: "; out(perennial);
cout<<"Koks: "; out(tree);
cout<<"Tropisks augs: "; out(tropical);
cout<<"Krasa: "<<c[clr]<<"\n";
cout<<"Sulas pagatavosana: "; out(juice);
cout<<"Skabs: "; out(sour);
cout<<"Edams: "; out(eating);
cout<<"\n\n";
}


void out (enum yn x)
{if (x==no) cout<<"nee\n";
else cout<<"jaa\n";
}


int main()
{
Apple a1,a2;
Orange o1,o2;
a1.seta("Sarkanais jaukums", red, no, yes, yes);
a2.seta("Dzonatans", red, yes, no, yes);
o1.seto("Tata", orange, no, no, yes);
o2.seto("Valensija", orange, yes, yes, no);
a1.show();
a2.show();
o1.show();
o2.show();
system("Pause>>null");
return 0;
}