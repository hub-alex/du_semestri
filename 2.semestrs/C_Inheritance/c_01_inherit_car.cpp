#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
    string get_brand();
    int get_year();
};

    void vehicle::set_brand(string name){
        brand = name;
    };

    void vehicle::set_year(int x){
        year = x;
    };

    string vehicle::get_brand(){
        return brand;
    }

    int vehicle::get_year(){
        return year;
    }
class truck : public vehicle {
    int weight_kg;
    int speed;
public:
    void set_weight_kg(int x);
    void set_speed(int x);
    int get_weight_kg();
    int get_speed();
};

void truck::set_weight_kg(int x) {
    weight_kg = x;
}

void truck::set_speed(int x) {
    speed = x;
}

int truck::get_weight_kg() {
    return weight_kg;
}

int truck::get_speed() {
    return speed;
}

class car : public vehicle {
    int passenger_count;
    int speed;
public:
    void set_passenger_count(int x);
    void set_speed(int x);
    int get_passenger_count();
    int get_speed();
};

void car::set_passenger_count(int x) {
    passenger_count = x;
}

void car::set_speed(int x) {
    speed = x;
}

int car::get_passenger_count() {
    return passenger_count;
}

int car::get_speed() {
    return speed;
}

int main() {
    int x;
    truck truck1;
    car car1;
    cout << "Input truck weight (kg): "; cin >> x; truck1.set_weight_kg(x);
    cout << "Input truck speed (km/h): "; cin >> x; truck1.set_speed(x);
    cout << "Input car passenger count: "; cin >> x; car1.set_passenger_count(x);
    cout << "Input car speed (km/h): "; cin >> x; car1.set_speed(x);
    cout << endl;
    //get
    cout << "Truck weight (kg): " << truck1.get_weight_kg() << endl;
    cout << "Truck speed (km/h): " << truck1.get_speed() << endl;
    cout << "Car passenger count: " << car1.get_passenger_count() << endl;
    cout << "Car speed (km/h): " << car1.get_speed() << endl;

    return 0;
}