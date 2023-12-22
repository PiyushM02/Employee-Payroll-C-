//****************************************************
// File: ClassEmployee.h
//
// Purpose: Contains the ClassEmployee and ClassDepartmenr that'll be used in program
// execution.
//
// Written By: Piyush Malik
//
// Compiler: Xcode 12.4
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: Get and Set methods
// written for class Employee within
// public and private member variables added.
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Member variables first and
// payRate within private are changed to
// pointers, along with the additions of
// the operator overloads and copy constructor
// in private.
//
//****************************************************

#ifndef ClassEmployee_h
#define ClassEmployee_h

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


class Employee
{
private:
    //Private member variables for employee are set.
    string* first;
    string last;
    double* payRate;
    double hours;

public:
    //A default constructor for Employee is added within public for default variables.
    Employee();
    //Copy constructor is called to make a deep copy of the data within the member variables.
    Employee(const Employee& eCopy);
    //Destructor is called which will go on to cleanups of the first and payRate member variables.
    ~Employee();

    //GetFirst is set within public as it will return the first string.
    string GetFirst();
    //SetFirst is set within public as first will be set to datatype string "f".
    void SetFirst(string f);

    //GetLast is set within public as it will return the last name.
    string GetLast();
    //SetLast is set within public as first will be set to datatype string "l".
    void SetLast(string l);

    //GetPayRate is set within public as it will return the payRate.
    double GetPayRate();
    //SetPayRate is set within public as payRate will be set to datatype double "p".
    void SetPayRate(double p);

    //GetHours is set within public as it will return the hours of the employee.
    double GetHours();
    //SetHours is set within public as hours will be set to datatype double "h".
    void SetHours(double h);

    //An operator= overload is added to make a deep copy of the data in the member variables.
    const Employee& operator=(const Employee& rhs);
    //An operator<< is added to write out member variable data and will be called in main.
    friend ostream& operator<<(ostream& out, Employee& rhs);
};

#endif /* ClassEmployee_h */
#pragma once
