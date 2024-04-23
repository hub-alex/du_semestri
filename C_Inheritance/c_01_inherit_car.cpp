#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include <stdio.h>
#include <ctime>
#define N 100

using namespace std;

class vehicle{
    string brand;
    int year;
public:
    void set_brand(string name);
    void set_year(int x);
    string get_brand(){return name};
    int get_year();
};

    void vehicle::set_brand(string name);
    void vehicle::set_year(int x);
    string vehicle::get_brand();
    int vehicle::get_year();


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