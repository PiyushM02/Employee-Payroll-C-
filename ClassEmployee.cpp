//****************************************************
// File: ClassEmployee.h
//
// Purpose: Contains the ClassEmployee that'll be used in program
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
// Description: Copy constructors and operator
// overloads were added for utilization as calls
// in the main function.
//
//****************************************************

#include "ClassEmployee.h"

//****************************************************
// Function: Employee()
//
// Purpose: Default constructor is utilized and member variables are set to default
// variables.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: The default variables
// were changed to "No", "Name" and
// double variables were initialized to 0.
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: first and payRate
// were updated as pointers and the
// new keywoard was utilized.
//
//****************************************************
Employee::Employee()
{
    //All member variables within class Employee are set to default variables, new keyword used.
    first = new string;
    payRate = new double;
    *first = "No";
    last = "Name";
    *payRate = 0;
    hours = 0;
}

//****************************************************
// Function: Employee(const Employee& eCopy)
//
// Purpose: Copy constructor is added to perform deep copies
// of the member variables within main.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Pointers first and
// payRate are added and member variables
// are used to make a new object from a previous
// object's copy.
//
//****************************************************
Employee::Employee(const Employee& eCopy) //Copy constructor
{
    first = new string;
    payRate = new double;
    *first = *eCopy.first;
    last = eCopy.last;
    *payRate = *eCopy.payRate;
    hours = eCopy.hours;
}

//****************************************************
// Function: ~Employee()
//
// Purpose: A destructor is added to
// make the necessary cleanups.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: delete is assigned
// to the first and payRate variables as
// they are pointers, nullptr is also utilized
// to avoid a dangling pointer.
//
//****************************************************
Employee::~Employee() //Destructor
{
    delete first;
    delete payRate;
    first = nullptr;
    payRate = nullptr;
}

//****************************************************
// Function: GetFirst()
//
// Purpose: The GetFirst method is used to get the first name and return first.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: GetFirst() is
// used to return first for later execution
// in main.
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Updated GetFirst()
// to accomodate the pointer.
//
//****************************************************
string Employee::GetFirst()
{
    return *first;
}

//****************************************************
// Function: SetFirst(string f)
//
// Purpose: The SetFirst method is used to set the first name to the parameter string f.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: SetFirst() is
// used to set first for later execution
// in main to string f;
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Updated SetFirst()
// to accomodate the pointer.
//
//****************************************************
void Employee::SetFirst(string f)
{
    *first = f;
}

//****************************************************
// Function: GetLast()
//
// Purpose: The GetLast method is used to get the last name and return last.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: GetLast() is
// used to return last for later execution
// in main.
//
//****************************************************
string Employee::GetLast()
{
    return last;
}

//****************************************************
// Function: SetLast(string l)
//
// Purpose: The SetLast method is used to set the first name to the parameter string l.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: SetFirst() is
// used to set first for later execution
// in main to string f;
//
//****************************************************
void Employee::SetLast(string l)
{
    last = l;
}

//****************************************************
// Function: GetPayRate()
//
// Purpose: The GetPayRate method is used to get the payRate.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: GetPayRate() is
// used to return first for later execution
// in main.
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Updated GetPayRate()
// to accomodate for the pointer.
//
//****************************************************
double Employee::GetPayRate()
{
    return *payRate;
}

//****************************************************
// Function: SetPayRate(double p)
//
// Purpose: The SetPayRate method is used to set the pay rate to the parameter double p.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: SetPayRate() is
// used to set the payRate for later execution
// in main to double p.
//
// Name: Piyush Malik
// Date: 4/6/2021
// Descriiption: SetPayRate() is updated
// to accomodate for the pointer member variable.
//
//****************************************************
void Employee::SetPayRate(double p)
{
    *payRate = p;
}

//****************************************************
// Function: GetHours()
//
// Purpose: The GetHours method is used to get the hours and return it later on.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: GetHours() is
// used to return the hours for later execution
// in main.
//
//****************************************************
double Employee::GetHours()
{
    return hours;
}

//****************************************************
// Function: SetHours(double h)
//
// Purpose: The SetHours method is used to set hours to the parameter double h.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: SetHours() is
// used to set the hours for later execution
// in main to double h.
//
//****************************************************
void Employee::SetHours(double h)
{
    hours = h;
}

//****************************************************
// Function: Employee& operator=(const Employee& rhs)
//
// Purpose: The operator= overload is added to make a deep copy of the data in the member variables and will be called in main.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Pointers for first and payrate
// are used and member variables are used
// for the right hand side parameter.
//
//****************************************************
const Employee& Employee::operator=(const Employee& rhs)
{

    //The member variables are set to the member variables of the rhs parameter.
    *first = *rhs.first;
    last = rhs.last;
    *payRate = *rhs.payRate;
    hours = rhs.hours;

    //this pointer is dereferenced.
    return *this;
}

//****************************************************
// Function: ostream& operator<<(ostream& out, Employee& rhs)
//
// Purpose: The operator<< overload is added to write out member variable data and will be called in main.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Pointers for first and payRate
// are used and member variables are used
// for the right hand side parameter.
//
//****************************************************
ostream& operator<<(ostream& out, Employee& rhs)
{
    //ostream is used with the rhs parameter and member variables.
    out << *rhs.first << endl;
    out << rhs.last << endl;
    out << *rhs.payRate << endl;
    out << rhs.hours << endl;
    return out;
}
