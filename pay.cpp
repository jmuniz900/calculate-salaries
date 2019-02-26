#include "person.h"
#include <iostream>
#include <fstream>

using namespace std;

void readData(Person (&employees)[20], int nEmployee);
void writeData(Person (&employees)[20], int nEmployee);

void writeData(Person (&employees)[20], int nEmployee){
  fstream file;
   file.open("output.txt");
   if(file.is_open()){
     for(int i = 0; i < nEmployee; i++){
       file << employees[i].fullName() << " " << employees[i].totalPay();
       file << endl;
     }
   }
   file.close();
}
void readData(Person (&employees)[20], int nEmployee){
  fstream file;
  string fName;
  string lName;
  float pRate;
  float hWorked;

  file.open("input.txt");
  if(file.is_open()){
    while(!file.eof()){
    for(int i = 0; i < nEmployee; i++){
      file >> fName >> lName >> pRate >> hWorked;
      employees[i].setFirstName(fName);
      employees[i].setLastName(lName);
      employees[i].setPayRate(pRate);
      employees[i].setHoursWorked(hWorked);
      //cout << employees[i].getFirstName() << endl;
      }
    }
  }
  else{
    cout << "Error: Could not open file!" << endl;
  }
  file.close();
}

int main(){
  Person employee[20];
  int maxEmployees = 6;

  readData(employee, maxEmployees);
  writeData(employee, maxEmployees);
}
