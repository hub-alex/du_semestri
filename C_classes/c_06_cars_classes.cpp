#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include <stdio.h>
#include <ctime>
#define N 100

using namespace std;

class truck{
    int weight_kg;
    int speed;
public:
    void set_weight_kg(int x);
    void set_speed(int x);
    int get_weight_kg();
    int get_speed();
};
void truck::set_weight_kg(int x){weight_kg=x;}
void truck::set_speed(int x){speed=x;}
int truck::get_weight_kg(){return weight_kg;}
int truck::get_speed(){return speed;}


class car{
    int passenger_count;
    int speed;
public:
    void set_passenger_count(int x);
    void set_speed(int x);
    int get_passenger_count();
    int get_speed();
};
void car::set_passenger_count(int x){passenger_count=x;}
void car::set_speed(int x){speed=x;}
int car::get_passenger_count(){return passenger_count;}
int car::get_speed(){return speed;}
//****************************************



//Home finish with friendly function

//---------------------main
int main()
{
    int x;
    truck truck1;
    car car1;
    printf("Input truck weight (kg): "); cin>>x; truck1.set_weight_kg(x);
    printf("Input truck speed (km/h): "); cin>>x; truck1.set_speed(x);
    printf("Input car passenger count: "); cin>>x; car1.set_passenger_count(x);
    printf("Input car speed (kg): "); cin>>x; car1.set_speed(x);
    cout<<endl;
    //get
    printf("Truck weight (kg): %i", truck1.get_weight_kg()); 
    printf("Truck truck speed (km/h): %i", truck1.get_speed()); 
    printf("Truck car passenger count: %i", car1.get_passenger_count()); 
    printf("Truck car speed (kg): %i", car1.get_speed()); 

	return 0;
}