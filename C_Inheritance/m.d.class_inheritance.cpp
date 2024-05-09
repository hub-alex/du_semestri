#include <iostream>
#include <fstream>
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
    Building() {}

    Building(string street, int year) : address(street), yearBuilt(year) {}

    
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


void writeToFile(const string& filename, PrivateHouse& house, Hotel& hotel, PublicBuilding& building, AppartmentHouse& appartmentHouse, int flag) {
    ofstream outputFile;
    outputFile.open(filename, ios_base::app);
    
    if (outputFile.is_open()) {
        if (flag == 2){
            outputFile << endl << "Prīvatmāja informācija:" << endl;
            outputFile << "Adrese: " << house.get_address() << endl;
            outputFile << "Būvniecības gads: " << house.get_year() << endl;
            outputFile << "Mājas platība: " << house.get_area() << " m²" << endl << endl;
        }
        if (flag == 3){
            outputFile << "Viesnīcas informācija:" << endl;
            outputFile << "Nosaukums: " << hotel.get_hotelName() << endl;
            outputFile << "Adrese: " << hotel.get_address() << endl;
            outputFile << "Būvniecības gads: " << hotel.get_year() << endl;
            outputFile << "Numuru skaits: " << hotel.get_roomCount() << endl;
            outputFile << "Zvaigžņu skaits: " << hotel.get_stars() << endl << endl;}
        if (flag == 4){
            outputFile << "Sabiedriskā ēka informācija:" << endl;
            outputFile << "Adrese: " << building.get_address() << endl;
            outputFile << "Būvniecības gads: " << building.get_year() << endl;
            outputFile << "Nolūks: " << building.get_purpose() << endl;
            outputFile << "Telefona numurs: " << building.get_phoneNumber() << endl << endl;}
        if (flag == 5){
            outputFile << "Daudzdzīvokļu mājas informācija:" << endl;
            outputFile << "Adrese: " << appartmentHouse.get_address() << endl;
            outputFile << "Būvniecības gads: " << appartmentHouse.get_year() << endl;
            outputFile << "Dzīvokļu skaits: " << appartmentHouse.get_apartments() << endl;
            outputFile << "Stāvu skaits: " << appartmentHouse.get_floors() << endl;}
        
        outputFile.close();
        cout << "Informācija ir ierakstīta failā " << filename << endl;
    } else {
        cout << "Nevarēja atvērt failu " << filename << "!" << endl;
    }
};


void readFromFile(const string& filename) {
string line;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {

        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Nevarēja atvērt failu: " << filename << endl;
    }
};

PrivateHouse funcPrivatHouse(){
    int year;
    double area;
    string adrese;
    //PrivateHouse house("Puškina iela 238, Daugavpils", 2005, 136.4);
    cout << "Prīvatmāja informācija:" << endl;
    cout << "Adrese: ";  
    cin.ignore(); 
    getline(cin, adrese);
    cout << "Būvniecības gads: "; cin.ignore(); cin >> year;
    cout << "Mājas platība: "; cin >> area;
    
    cin.ignore();
    PrivateHouse house(adrese, year, area);
    return house;
    
};

Hotel funcHotel() {
    string address;
    int year, roomCount, stars;
    string hotelName;

    cout << "Viesnīcas informācija:" << endl;
    cout << "Nosaukums: "; cin.ignore(); getline(cin, hotelName);
    cout << "Adrese: "; getline(cin, address);
    cout << "Būvniecības gads: "; cin >> year;
    cout << "Numuru skaits: "; cin >> roomCount;
    cout << "Zvaigžņu skaits: "; cin >> stars;
    
    cin.ignore();
    Hotel hotel(address, year, hotelName, roomCount, stars);
    
    return hotel;
}

PublicBuilding funcPublicBuilding() {
    string address;
    int year, phoneNumber;
    string purpose;

    cout << "Sabiedriskās ēkas informācija:" << endl;
    cout << "Adrese: "; cin.ignore(); getline(cin, address);
    cout << "Būvniecības gads: "; cin >> year;
    cout << "Nolūks: "; cin.ignore(); getline(cin, purpose);
    cout << "Tālrunis: "; cin >> phoneNumber;
    
    cin.ignore();
    PublicBuilding publicB(address, year, purpose, phoneNumber);

    return publicB;
}

AppartmentHouse funcAppartmentHouse() {
    string address;
    int year, apartments, floors;

    cout << "Daudzdzīvokļu mājas informācija:" << endl;
    cout << "Adrese: "; cin.ignore(); getline(cin, address);
    cout << "Būvniecības gads: "; cin >> year;
    cout << "Dzīvokļu skaits: "; cin >> apartments;
    cout << "Stāvu skaits: "; cin >> floors;
    
    cin.ignore();
    AppartmentHouse appart(address, year, apartments, floors);
    
    return appart;
    }

void makeChoice(const string& filename, PrivateHouse& house, Hotel& hotel, PublicBuilding& building, AppartmentHouse& appartmentHouse) {
    
    int choice;
    do {
        cout << "Izvēlieties darbību:" << endl;
        cout << "1. Lasīt informāciju no faila" << endl;
        cout << "2. Ierakstīt informāciju par prīvatmāju" << endl;
        cout << "3. Ierakstīt informāciju par viesnīcu" << endl;
        cout << "4. Ierakstīt informāciju par publisko eku" << endl;
        cout << "5. Ierakstīt informāciju daudzdzīvokļu māju" << endl;
        cout << "6. Iziet no programmas" << endl;
        cout << "Jūsu izvēle: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1:
                readFromFile(filename);
                break;
            case 2:
                writeToFile(filename, house, hotel, building, appartmentHouse, 2);
                break;
            case 3:
                writeToFile(filename, house, hotel, building, appartmentHouse, 3);
                break;
            case 4:
                writeToFile(filename, house, hotel, building, appartmentHouse, 4);
                break;
            case 5:
                writeToFile(filename, house, hotel, building, appartmentHouse, 5);
                break;
            case 6:
                cout << "Izeja no programmas..." << endl;
                break;
            default:
                cout << "Nepareiza darbības izvēle!" << endl;
                break;
        }
        cin.ignore();
    } while (choice != 6);
};

int main()
{
    string filename = "building_info.txt";



    PrivateHouse house = funcPrivatHouse(); 

    Hotel hotel = funcHotel();

    PublicBuilding publicB = funcPublicBuilding();

    AppartmentHouse appart = funcAppartmentHouse();

    
    PrivateHouse objHouse("Puškina iela 238, Daugavpils", 2005, 136.4);
    Hotel objHotel("Ģimnāzijas iela 46, Daugavpils, LV-5401", 2005, "Hotel objHotel", 117, 3);
    PublicBuilding objPublic("Smilšu iela 127, Daugavpils", 1972, "Daugavpils Kultūras pils", 65437892);
    AppartmentHouse objAppart("Vienības iela 20, Daugavpils", 1965, 24, 3);
    
    //writeToFile(filename, objHouse, objHotel, objPublic, objAppart, 2);
    makeChoice(filename, house, hotel, publicB, appart);
    
	return 0;
}

    


    //makeChoice(filename, objHouse, objHotel, objPublic, objAppart);
    
    /*cout << "Prīvatmāja atrodas pēc adreses: " << objPrivateHouse.get_address() << endl;
    cout << "Būvniecības gads: " << objPrivateHouse.get_year() << ". gads"<< endl;
    cout << "Mājas platība: " << objPrivateHouse.get_area() << " m²" << endl;

    
    cout << endl << "Viesnīcas nosaukums: " << objHotel.get_hotelName() << endl;
    cout << objHotel.get_hotelName() <<" atrodas pēc adreses: " << objHotel.get_address() << endl;
    cout << "Būvniecības gads: " << objHotel.get_year() << ". gads" << endl;
    cout << "Numuru skaits: " << objHotel.get_roomCount() << endl;
    cout << "Zvaigžņu skaits: " << objHotel.get_stars() << endl;

    
    cout << "\nSabiedriskā ēka atrodas pēs adreses: " << objPublic.get_address() << endl;
    cout << "Būvniecības gads: " << objPublic.get_year() << ". gads" << endl;
    cout << "Sabiedriska ēka: " << objPublic.get_purpose() << endl;
    cout << "Tālrunis: " << objPublic.get_phoneNumber() << endl;

    
    cout << endl << "Daudzdzīvokļu mājas adrese: " << objAppart.get_address() << endl;
    cout << "Būvniecības gads: " << objAppart.get_year() << ". gads" << endl;
    cout << "Dzīvokļu skaits: " << objAppart.get_apartments() << endl;
    cout << "Stāvu skaits: " << objAppart.get_floors() << endl;*/

    

    //readFromFile(filename);
    //
    //system("Pause>>null");
