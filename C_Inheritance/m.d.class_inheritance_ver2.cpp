#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#define N 100

using namespace std;

class Building {
    protected:
    string address;
    int yearBuilt;

    public:
    Building() {}

    Building(string address, int year) : address(address), yearBuilt(year) {}

    void set_address (string street);
    void set_yearBuilt (int year);
    string get_address();
    int get_year();

    virtual void writeData(ofstream& outputFile) const {
        outputFile << "Adrese: " << address << endl;
        outputFile << "Būvniecības gads: " << yearBuilt << endl;
    }

};

void Building::set_address (string street){address = street;}
void Building::set_yearBuilt (int year){ yearBuilt = year;}
string Building::get_address(){return address;}
int Building::get_year(){return yearBuilt;}

class PrivateHouse : public Building {
    private:
    double area;
    
    public:
    //PrivateHouse(){}
    PrivateHouse(string address, int year, double sqMeters) : Building(address, year), area(sqMeters){}

    void set_area(double sqMeters);
    double get_area();

    PrivateHouse() {
        cout << "Prīvatmāja informācija:" << endl;
        cout << "Adrese: ";
        cin.ignore();
        getline(cin, address);
        cout << "Būvniecības gads: ";
        cin >> yearBuilt;
        cout << "Mājas platība: ";
        cin >> area;
    }


    void writeData(ofstream& outputFile) const override {
        outputFile << "Prīvatmāja informācija:" << endl;
        outputFile << "Adrese: " << address << endl;
        outputFile << "Būvniecības gads: " << yearBuilt << endl;
        outputFile << "Mājas platība: " << area << endl;
    }
};


void PrivateHouse::set_area(double sqMeters){area = sqMeters;}
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


void writeToFile(const string& filename, const Building& building) {
    ofstream outputFile;
    outputFile.open(filename, ios_base::app);
    if (outputFile.is_open()) {
        building.writeData(outputFile);
        outputFile.close();
        cout << "Information has been written to file " << filename << endl;
    } else {
        cout << "Unable to open file " << filename << "!" << endl;
    }
}



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

/*PrivateHouse funcPrivatHouse(){
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
    
};*/

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

void makeChoice(const string& filename) {
    



                PrivateHouse house;
                writeToFile(filename, house);
}
int main()
{
    string filename = "building_info.txt";



    //PrivateHouse house = funcPrivatHouse(); 
    //PublicBuilding publicB = funcPublicBuilding();
    //AppartmentHouse appart = funcAppartmentHouse();

    
    //PrivateHouse objHouse("Puškina iela 238, Daugavpils", 2005, 136.4);
    //Hotel objHotel("Ģimnāzijas iela 46, Daugavpils, LV-5401", 2005, "Hotel objHotel", 117, 3);
    //PublicBuilding objPublic("Smilšu iela 127, Daugavpils", 1972, "Daugavpils Kultūras pils", 65437892);
    //AppartmentHouse objAppart("Vienības iela 20, Daugavpils", 1965, 24, 3);
    
    //writeToFile(filename, objHouse, objHotel, objPublic, objAppart, 2);
    makeChoice(filename);
    
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
