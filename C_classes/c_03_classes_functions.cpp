#include <iostream>
#include "c_03_classes_my_class.cpp"

using namespace std;

myClass::myClass() {a=5; b=10;}
myClass::myClass(int x, int y) {a=x; b=y;}
myClass::myClass(int x) {a=x; b=15;}
myClass::~myClass() {cout<<endl<<"It`s time for destructions!!!"<<endl;}
void myClass::set_a(int num) {a=num;}
int myClass::get_a() {return a;}

void myClass::set_b(int num) {b=num;}
int myClass::get_b() {return b;}