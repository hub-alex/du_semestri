#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
//#define N 100

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
        outputFile << "Bezsubklases ēka:" << endl;
        outputFile << "Adrese: " << address << endl;
        outputFile << "Būvniecības gads: " << yearBuilt << endl << endl;
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
    PrivateHouse(string address, int year, double sqMeters) : Building(address, year), area(sqMeters){}

    void set_area(double sqMeters);
    double get_area();

    PrivateHouse() {
        cout << "Prīvatmāja informācija:" << endl;
        cout << "Adrese: "; cin.ignore(); getline(cin, address);
        cout << "Būvniecības gads: "; cin >> yearBuilt;
        cout << "Mājas platība: "; cin >> area;
    }


    void writeData(ofstream& outputFile) const override {
        outputFile << "Prīvatmāja informācija:" << endl;
        outputFile << "Adrese: " << address << endl;
        outputFile << "Būvniecības gads: " << yearBuilt << endl;
        outputFile << "Mājas platība: " << area << endl << endl;
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
    
    Hotel(){
    cout << "Viesnīcas informācija:" << endl;
    cout << "Nosaukums: "; cin.ignore(); getline(cin, hotelName);
    cout << "Adrese: "; cin.ignore(); getline(cin, address);
    cout << "Būvniecības gads: "; cin >> yearBuilt;
    cout << "Numuru skaits: "; cin >> roomCount;
    cout << "Zvaigžņu skaits: "; cin >> stars;
    }

    Hotel (string street, int year, string name, int room_numbers, int star_numbers) : Building(street, year), 
    hotelName(name), roomCount(room_numbers), stars(star_numbers){}

    void writeData(ofstream& outputFile) const override {
        outputFile << "Viesnīcas informācija:" << endl;
        outputFile << "Nosaukums: " << hotelName << endl;
        outputFile << "Adrese: "<< address << endl;
        outputFile << "Būvniecības gads: " << yearBuilt << endl;
        outputFile << "Numuru skaits: " << roomCount << endl;
        outputFile << "Zvaigžņu skaits: " << stars << endl << endl;
    }

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
    PublicBuilding()
    {
        cout << "Sabiedriskās ēkas informācija:" << endl;
        cout << "Adrese: "; cin.ignore(); getline(cin, address);
        cout << "Būvniecības gads: "; cin >> yearBuilt;
        cout << "Nolūks: "; cin.ignore(); getline(cin, purpose);
        cout << "Tālrunis: "; cin >> phoneNumber;
    }
    
    PublicBuilding(string street, int year, string name, int numbers):Building(street, year), purpose(name), phoneNumber(numbers){}
    
    void writeData(ofstream& outputFile) const override {
        outputFile << "Sabiedriskās ēkas informācija:" << endl;
        outputFile << "Adrese: " << address << endl;
        outputFile << "Būvniecības gads: " << yearBuilt << endl;
        outputFile << "Tipa veids: " << purpose << endl;
        outputFile << "Tālrunis: " << phoneNumber << endl << endl;
    }

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
    AppartmentHouse() {    
    cout << "Daudzdzīvokļu mājas informācija:" << endl;
    cout << "Adrese: "; cin.ignore(); getline(cin, address);
    cout << "Būvniecības gads: "; cin >> yearBuilt;
    cout << "Dzīvokļu skaits: "; cin >> apartments;
    cout << "Stāvu skaits: "; cin >> floors;
    }
    AppartmentHouse(string street, int year, int aparts, int flrs) : Building(street, year), apartments(aparts), floors(flrs) {}
    
    void writeData(ofstream& outputFile) const override {
        outputFile << "Daudzdzīvokļu mājas informācija:" << endl;
        outputFile << "Adrese: "<< address << endl;
        outputFile << "Būvniecības gads: " << yearBuilt << endl;
        outputFile << "Dzīvokļu skaits: " << apartments << endl;
        outputFile << "Stāvu skaits: " << floors << endl << endl;
        }


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
        cout << "Informācija ierakstītā failā: " << filename << endl;
    } else {
        cout << "Nevarēja atvērt failu: " << filename << "!" << endl;
    }
}


void readFromFile(const string& filename) {
string line;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        cout << "---------------------" << endl << endl;
        
        while (getline(inputFile, line)) 
        {
            cout << line << endl;
        }
        
        cout << "---------------------" << endl << endl;
        
        inputFile.close();
    } else {
        cout << "Nevarēja atvērt failu: " << filename << endl;
    }
};



void makeChoice(const string& filename) {
    int choice;
    
    do {
        cout << "Izvēlieties darbību:" << endl;
        cout << "1. Lasīt informāciju no faila" << endl;
        cout << "2. Ierakstīt informāciju par prīvatmāju" << endl;
        cout << "3. Ierakstīt informāciju par viesnīcu" << endl;
        cout << "4. Ierakstīt informāciju par publisko eku" << endl;
        cout << "5. Ierakstīt informāciju daudzdzīvokļu māju" << endl;
        cout << "6. Iziet no programmas" << endl;
        cout << "Jūsu izvēle:   ";
        
        
        cin >> choice; cout << endl;
        //cin.ignore();

        switch(choice) {
            case 1:
                readFromFile(filename);
                break;
            case 2: {
                PrivateHouse house;
                writeToFile(filename, house);
                break;
            }
            case 3: {
                Hotel hotel;
                writeToFile(filename, hotel);
                break;
            }
            case 4: {
                PublicBuilding publicB;
                writeToFile(filename, publicB);
                break;
            }
            case 5: {
                AppartmentHouse appartment;
                writeToFile(filename, appartment);
                break;
            }
            case 6:
                cout << "Izeja no programmas..." << endl;
                break;
            default:
                cout << "Nepareiza darbības izvēle!" << endl;
                break;
        }
    } while (choice != 6);
}

void automat(const string& filename){
    PrivateHouse objHouse("Puškina iela 238, Daugavpils", 2005, 136.4);
    writeToFile(filename, objHouse);

    Hotel objHotel("Ģimnāzijas iela 46, Daugavpils, LV-5401", 2005, "Hotel Latgola", 117, 3);
    writeToFile(filename, objHotel);
    
    PublicBuilding objPublic("Smilšu iela 127, Daugavpils", 1972, "Daugavpils Kultūras pils", 65437892);
    writeToFile(filename, objPublic);
    
    AppartmentHouse objAppart("Vienības iela 20, Daugavpils", 1965, 24, 3);
    writeToFile(filename, objAppart);
    }

int main()
{
    string filename = "building_info.txt";
    makeChoice(filename);
    //automat(filename);

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
    }*/