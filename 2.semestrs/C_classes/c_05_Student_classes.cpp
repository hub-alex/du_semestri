#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include <stdio.h>
#include <ctime>
#define N 100

using namespace std;
class students{
    //----------------mainiigie----------------
private:

string vards;
string uzvards;
int kurss;

    //--------------functions---------------------

public:

void set_vards(string x);
string get_vards();

void set_uzvards(string x);
string get_uzvards();

void set_kurss(int x);
int get_kurss();
};

void students::set_vards(string x){
    vards=x;
}
string students::get_vards(){
    return vards;
}

void students::set_uzvards(string x){
    uzvards=x;
}
string students::get_uzvards(){
    return uzvards;
}

void students::set_kurss(int x){
    kurss=x;
}
int students::get_kurss(){
    return kurss;
}

//----------------------ievads-----------------------------
void input(students &st1, int i){
    string vards;
    cout<<"ievadi studenta vardu: \n";
    cin>>vards;
    st1.set_vards(vards);
    cout<<"ievadi studenta uzvārdu: \n";
    cin>>vards;
    st1.set_uzvards(vards);
    cout<<"ievadi studenta kursu: \n";
    cin>>vards;
    st1.set_kurss(stoi(vards));
}
//------------------------izvads------------------------------
void output(students st1, int i){

    cout<<"\n--------------\nInfo about student" <<i<<": ";
    printf("\n--------------\nInfo about student%i: ", i);
    cout<<"\nvaards: "<<st1.get_vards();
    cout<<"\nuzvaards: "<<st1.get_uzvards();
    cout<<"\nkurss: "<<st1.get_kurss();
}

//--------------
void students_in_course(int n, students mas[], int course_number){
int i, amount=0;
for (i=0;i<n; i++){
    if(mas[i].get_kurss()==course_number) amount++;
}
printf("\nStudents amount in course %i is %i", course_number, amount);
}
//-------------


int main()
{
    int n,i, course_number;
    students st[N];
    
    cout<<"\nHow many students?\n"; cin>>n;
    for(i=0;i<n;i++)//ievads
    input(st[i], i+1);

    for(i=0;i<n;i++)//izvads
    output(st[i], i+1); //masīva pirmais elements, jo laika nepietika uztaisiit

    cout<<("\nInput Course number: "); cin>>course_number;
    students_in_course(n, st, course_number);

    //system("pause>nul");
	return 0;
}