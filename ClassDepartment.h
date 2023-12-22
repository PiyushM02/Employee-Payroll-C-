//****************************************************
// File: ClassDepartment.h
//
// Purpose: Contains the ClassDepartment that'll be used in program execution.
//
// Written By: Piyush Malik
//
// Compiler: Xcode 12.4
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Class Department is
// added as a seperate file and constructors
// /operator overloads are used for the calls
// to main.
//
//****************************************************
#ifndef ClassDepartment_h
#define ClassDepartment_h

#include "ClassEmployee.h"

class Department
{
private:
    //Private member variable name for department is set.
    string name;
    //An instance of employee is set within private of Department as a dynamic array.
    Employee* Emp = new Employee[4];

public:

    //A default constructor for Department is added within public for default variables.
    Department();
    //A copy constructor is added to perform deep copies of the member variables.
    Department(const Department& depCopy);
    //Destructor is called which will go on to do the cleanup of the dynamic array.
    ~Department();

    //GetName is set within public as it will return the department name.
    string GetName();
    //SetName is set within public as name will be set to datatype string "n".
    void SetName(string n);

    //Employee GetHighestHoursEmployee() is used to return the person with the most hours.
    Employee GetHighestHoursEmployee();
    //void Read(string filename) is declared in public to read input data from a file.
    void Read(string filename);
    //void Write(string filename) is declared in public for simple output to an output file.
    void Write(string filename);
    //void Report() is declared in public to write Employee data to the console itself.
    void Report();

    //An operator= overload is added to make a deep copy of the data in the member variables.
    const Department& operator=(const Department& departmentCopy);
    //An operator<< is added to write out member variable data and will be called in main.
    friend ostream& operator<<(ostream& os, Department& departmentPrint); //operator <<
};


#endif /* ClassDepartment_h */
#pragma once
