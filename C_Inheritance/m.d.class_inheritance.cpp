#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#define N 100

using namespace std;

class Building {
    private:
    string address;
    int yearBuilt;

    public:
    Building() {} // Konstruktors

    Building(string street, int year) : address(street), yearBuilt(year) {} // mans konstruktors

    
    void set_address (string street);
    void set_yearBuilt (int year);
    string get_address();
    int get_year();
};

void Building::set_address (string street){address = street;}
void Building::set_yearBuilt (int year){ yearBuilt = year;}
string Building::get_address(){return address;}
int Building::get_year(){return yearBuilt;}

class PrivateHouse : public Building {
    private:
    double area;
    
    public:
    PrivateHouse(){}
    PrivateHouse(string street, int year, double sqMeters) : Building(street, year), area(sqMeters){}

    void set_area(double sqMeters);
    double get_area();
};


void PrivateHouse::set_area(double sqMeters){
    cout << "Jūsu mājas platība: " << sqMeters << " m²" << endl;
    area = sqMeters;
    }
double PrivateHouse::get_area(){ return area;}


class Hotel : public Building{
    private:
    int roomCount;
    int stars;
    string hotelName;
    public:
    
    Hotel(){}
    Hotel (string street, int year, string name, int room_numbers, int star_numbers) : Building(street, year), 
    hotelName(name), roomCount(room_numbers), stars(star_numbers){}


    void set_roomCount(int room_numbers);
    void set_stars(int star_numbers);
    void set_hotelName(string name);
    int get_roomCount();
    int get_stars();
    string get_hotelName();

};

void Hotel::set_roomCount(int room_numbers){ roomCount = room_numbers;}
void Hotel::set_stars(int star_numbers){ stars = star_numbers;}
void Hotel::set_hotelName(string name){ hotelName = name;}
int Hotel::get_roomCount() {return roomCount;}
int Hotel::get_stars() {return stars;}
string Hotel::get_hotelName(){return hotelName;}


class PublicBuilding : public Building{
    private:
    string purpose;
    int phoneNumber;

    public:
    PublicBuilding(){}
    PublicBuilding(string street, int year, string name, int numbers):Building(street, year), purpose(name), phoneNumber(numbers){}
    
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
    PrivateHouse maja1("Puškina iela 238, Daugavpils", 2005, 136.4);
    cout << "Prīvatmāja atrodas pēc adreses: " << maja1.get_address() << endl;
    cout << "Būvniecības gads: " << maja1.get_year() << endl;
    cout << "Mājas platība: " << maja1.get_area() << " m²" << endl;


    Hotel latgola("Ģimnāzijas iela 46, Daugavpils, LV-5401", 1990, "Hotel Latgola", 125, 3);
    cout << "\nMana viesnīca atrodas adresē: " << latgola.get_address() << endl;
    cout << "Būvniecības gads: " << latgola.get_year() << endl;
    cout << "Viesnīvas nosaukums: " << latgola.get_hotelName() << endl;
    cout << "Numuru skaits: " << latgola.get_roomCount() << endl;
    cout << "Zvaigžņu skaits: " << latgola.get_stars() << endl;


    PublicBuilding DKP("Smilšu iela 127, Daugavpils", 1971, "Daugavpils Kultūras pils", 65437892);
    cout << "\nSabiedriskā ēka atrodas pēs adreses: " << DKP.get_address() << endl;
    cout << "Būvniecības gads: " << DKP.get_year() << endl;
    cout << "Mērķis: " << DKP.get_purpose() << endl;
    cout << "Tālrunis: " << DKP.get_phoneNumber() << endl;


   //system("Pause>>null");
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