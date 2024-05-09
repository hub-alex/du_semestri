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


class AppartmentHouse : public Building {
    private:
    int apartments;
    int floors; 

    public:
    AppartmentHouse() {}
    AppartmentHouse(string street, int year, int aparts, int flrs) : Building(street, year), apartments(aparts), floors(flrs) {}

    void set_apartments(int aparts);
    void set_floors(int flrs);
    int get_apartments();
    int get_floors();
};

void AppartmentHouse::set_apartments(int aparts) { apartments = aparts; }
void AppartmentHouse::set_floors(int flrs) { floors = flrs; }
int AppartmentHouse::get_apartments() { return apartments; }
int AppartmentHouse::get_floors() { return floors; }


int main()
{
    PrivateHouse pushkina238("Puškina iela 238, Daugavpils", 2005, 136.4);
    cout << "Prīvatmāja atrodas pēc adreses: " << pushkina238.get_address() << endl;
    cout << "Būvniecības gads: " << pushkina238.get_year() << ". gads"<< endl;
    cout << "Mājas platība: " << pushkina238.get_area() << " m²" << endl;


    Hotel latgola("Ģimnāzijas iela 46, Daugavpils, LV-5401", 2005, "Hotel Latgola", 117, 3);
    cout << endl << "Viesnīcas nosaukums: " << latgola.get_hotelName() << endl;
    cout << latgola.get_hotelName() <<" atrodas pēc adreses: " << latgola.get_address() << endl;
    cout << "Būvniecības gads: " << latgola.get_year() << ". gads" << endl;
    cout << "Numuru skaits: " << latgola.get_roomCount() << endl;
    cout << "Zvaigžņu skaits: " << latgola.get_stars() << endl;


    PublicBuilding DKP("Smilšu iela 127, Daugavpils", 1972, "Daugavpils Kultūras pils", 65437892);
    cout << "\nSabiedriskā ēka atrodas pēs adreses: " << DKP.get_address() << endl;
    cout << "Būvniecības gads: " << DKP.get_year() << ". gads" << endl;
    cout << "Sabiedriska ēka: " << DKP.get_purpose() << endl;
    cout << "Tālrunis: " << DKP.get_phoneNumber() << endl;

    AppartmentHouse vienibas8("Vienības iela 20, Daugavpils", 1965, 24, 3);
    cout << endl << "Daudzdzīvokļu mājas adrese: " << vienibas8.get_address() << endl;
    cout << "Būvniecības gads: " << vienibas8.get_year() << ". gads" << endl;
    cout << "Dzīvokļu skaits: " << vienibas8.get_apartments() << endl;
    cout << "Stāvu skaits: " << vienibas8.get_floors() << endl;


   //system("Pause>>null");
	return 0;
}



/*
// Ваши классы и их методы

// Функция для записи информации о зданиях в файл
void writeBuildingInfoToFile(const string& filename, PrivateHouse& house, Hotel& hotel, PublicBuilding& building, AppartmentHouse& appartmentHouse) {
    // Открываем файл для записи
    ofstream outputFile(filename);

    // Проверяем, успешно ли открыт файл
    if (outputFile.is_open()) {
        // Записываем информацию о каждом объекте в файл
        outputFile << "Prīvatmāja informācija:" << endl;
        outputFile << "Adrese: " << house.get_address() << endl;
        outputFile << "Būvniecības gads: " << house.get_year() << endl;
        outputFile << "Mājas platība: " << house.get_area() << " m²" << endl << endl;

        outputFile << "Viesnīcas informācija:" << endl;
        outputFile << "Nosaukums: " << hotel.get_hotelName() << endl;
        outputFile << "Adrese: " << hotel.get_address() << endl;
        outputFile << "Būvniecības gads: " << hotel.get_year() << endl;
        outputFile << "Numuru skaits: " << hotel.get_roomCount() << endl;
        outputFile << "Zvaigžņu skaits: " << hotel.get_stars() << endl << endl;

        outputFile << "Sabiedriskā ēka informācija:" << endl;
        outputFile << "Adrese: " << building.get_address() << endl;
        outputFile << "Būvniecības gads: " << building.get_year() << endl;
        outputFile << "Nolūks: " << building.get_purpose() << endl;
        outputFile << "Telefona numurs: " << building.get_phoneNumber() << endl << endl;

        outputFile << "Daudzdzīvokļu mājas informācija:" << endl;
        outputFile << "Adrese: " << appartmentHouse.get_address() << endl;
        outputFile << "Būvniecības gads: " << appartmentHouse.get_year() << endl;
        outputFile << "Dzīvokļu skaits: " << appartmentHouse.get_apartments() << endl;
        outputFile << "Stāvu skaits: " << appartmentHouse.get_floors() << endl;
        
        // Закрываем файл
        outputFile.close();
        cout << "Informācija ir ierakstīta failā " << filename << endl;
    } else {
        cout << "Nevarēja atvērt failu " << filename << "!" << endl;
    }
}

int main() {
    PrivateHouse pushkina238("Puškina iela 238, Daugavpils", 2005, 136.4);
    Hotel latgola("Ģimnāzijas iela 46, Daugavpils, LV-5401", 2005, "Hotel Latgola", 117, 3);
    PublicBuilding DKP("Smilšu iela 127, Daugavpils", 1972, "Daugavpils Kultūras pils", 65437892);
    AppartmentHouse vienibas8("Vienības iela 20, Daugavpils", 1965, 24, 3);

    // Вызываем функцию для записи информации в файл
    writeBuildingInfoToFile("building_info.txt", pushkina238, latgola, DKP, vienibas8);

    return 0;
}
*/