#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#define N 100

using namespace std;

struct car {
    int year;
    float price;
    char brand[N];
    
};

void ievads(car &car1){
    cout<<"Write the brand of car: "; cin>>car1.brand;
    cout<<"Write the price of car: "; cin>>car1.price;
    cout<<"Write the year of car: "; cin>>car1.year;

}

void ievads1(car *car1){
    cout<<"Write the brand of car: "; cin>>car1->brand;
    cout<<"Write the price of car: "; cin>>car1->price;
    cout<<"Write the year of car: "; cin>>car1->year;

}


void izvads(car &car1){
    cout<<"Brand of car: "<<car1.brand<<endl;
    cout<<"Price of car: "<<car1.price<<" eur"<<endl;
    cout<<"Year of car: "<<car1.year<<" year"<<endl;

}


int main(){
    car car1;
    ievads(car1);
    izvads(car1);
    
    //ievads1(&car1);

//-------------------

system("pause>nul");
return 0;
}