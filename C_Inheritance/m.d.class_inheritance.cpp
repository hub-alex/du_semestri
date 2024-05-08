#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#define N 100

using namespace std;

class Building {
    string address;
    int yearBuilt;

    public:
    void set_address (string name);
    void set_yearBuilt (int year);
    string get_address();
    int get_year();
};

void Building::set_address (string name){address = name;}
void Building::set_yearBuilt (int year){ yearBuilt = year;}
string Building::get_address(){return address;}
int Building::get_year(){return yearBuilt;}

class PrivateHouse : public Building {
    private:
    double area;
    
    public:
    void set_area(double squareMeters);
    double get_area();
};

void PrivateHouse::set_area(double squareMeters){
    cout << "Jūsu mājas platība: " << squareMeters << " m²" << endl;
    area = squareMeters;
    }
double PrivateHouse::get_area(){ return area;}


class Hotel : public Building{
    private:
    int rooms;
    int stars;
    public:
    void setRoomCount(int room_numbers);
    void set_stars(int star_numbers);
    int getRoomCount();
    int get_stars();

};

void Hotel::setRoomCount(int room_numbers){ rooms = room_numbers;}
void Hotel::set_stars(int star_numbers){ stars = star_numbers;}
int Hotel::getRoomCount() {return rooms;}
int Hotel::get_stars() {return stars;}



class PublicBuilding : public Building{
    private:
    string purpose;
    int phoneNumber;
    public:
    void set_purpose(string name);
    void set_phoneNumber(int numbers);
    string get_purpose();
    int get_phoneNumber();
};

void PublicBuilding::set_purpose(string name){purpose = name;}
void PublicBuilding::set_phoneNumber(int numbers){phoneNumber = numbers;}
string PublicBuilding::get_purpose(){return purpose;}
int PublicBuilding::get_phoneNumber(){return phoneNumber;}


int main()
{
    int x;
    /*
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
    */
	return 0;
}



/*
// Базовый класс "Здание"
class Building {
public:
Building(const std::string& address, int yearBuilt)
: address(address), yearBuilt(yearBuilt) {}


virtual void displayInfo() const {
    std::cout << "Адрес: " << address << std::endl;
    std::cout << "Год постройки: " << yearBuilt << std::endl;
}

virtual void saveToFile(const std::string& filename) const {
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        outfile << "Базовое здание: " << address << ", " << yearBuilt << std::endl;
        outfile.close();
    } else {
        std::cout << "Ошибка открытия файла для записи." << std::endl;
    }
}

protected:
std::string address;
int yearBuilt;
};


// Подкласс "Частный дом"
class PrivateHouse : public Building {
public:
PrivateHouse(const std::string& address, int yearBuilt, int numBedrooms)
: Building(address, yearBuilt), numBedrooms(numBedrooms) {}


void displayInfo() const override {
    Building::displayInfo();
    std::cout << "Количество спален: " << numBedrooms << std::endl;
}

void saveToFile(const std::string& filename) const override {
    Building::saveToFile(filename);
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        outfile << "Частный дом: " << numBedrooms << " спален" << std::endl;
        outfile.close();
    } else {
        std::cout << "Ошибка открытия файла для записи." << std::endl;
    }
}

private:
int numBedrooms;
};


// Подкласс "Публичное здание"
class PublicBuilding : public Building {
public:
PublicBuilding(const std::string& address, int yearBuilt, const std::string& type)
: Building(address, yearBuilt), type(type) {}


void displayInfo() const override {
    Building::displayInfo();
    std::cout << "Тип публичного здания: " << type << std::endl;
}

void saveToFile(const std::string& filename) const override {
    Building::saveToFile(filename);
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        outfile << "Публичное здание: " << type << std::endl;
        outfile.close();
    } else {
        std::cout << "Ошибка открытия файла для записи." << std::endl;
    }
}

private:
std::string type;
};


// Подкласс "Многоквартирный дом"
class ApartmentBuilding : public Building {
public:
ApartmentBuilding(const std::string& address, int yearBuilt, int numApartments)
: Building(address, yearBuilt), numApartments(numApartments) {}


void displayInfo() const override {
    Building::displayInfo();
    std::cout << "Количество квартир: " << numApartments << std::endl;
}

void saveToFile(const std::string& filename) const override {
    Building::saveToFile(filename);
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        outfile << "Многоквартирный дом: " << numApartments << " квартир" << std::endl;
        outfile.close();
    } else {
        std::cout << "Ошибка открытия файла для записи." << std::endl;
    }
}

private:
int numApartments;
};


// Подкласс "Гостиница"
class Hotel : public Building {
public:
Hotel(const std::string& address, int yearBuilt, int numRooms)
: Building(address, yearBuilt), numRooms(numRooms) {}


void displayInfo() const override {
    Building::displayInfo();
    std::cout << "Количество номеров: " << numRooms << std::endl;
}

void saveToFile(const std::string& filename) const override {
    Building::saveToFile(filename);
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        outfile << "Гостиница: " << numRooms << " номеров" << std::endl;
        outfile.close();
    } else {
        std::cout << "Ошибка открытия файла для записи." << std::endl;
    }
}

private:
int numRooms;
};


int main() {
PrivateHouse house("Улица Солнечная, 123", 2005, 3);
PublicBuilding publicBuilding("Центральная площадь, 5", 1980, "Музей");
ApartmentBuilding apartmentBuilding("Проспект Мира, 42", 2018, 50);
Hotel hotel("Набережная, 7", 2021, 200);


house.displayInfo();
house.saveToFile("buildings.txt");

publicBuilding.displayInfo();
publicBuilding.saveToFile("buildings.txt");

apartmentBuilding.displayInfo();
apartmentBuilding.saveToFile("buildings.txt");

hotel.displayInfo();
hotel.saveToFile("buildings.txt");

return 0;

}
*/