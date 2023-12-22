//****************************************************
// File: ClassDepartment.h
//
// Purpose: Contains the ClassDepartment that'll be used in program
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
// Date: 4/27/2021
// Description: All department functions
// are defined and constructors/operator
// overloads are defined in ClassDepartment.cpp.
//
//****************************************************

#include "ClassDepartment.h"

//****************************************************
// Function: Department()
//
// Purpose: Default constructor is utilized and member variables are set to default variables for the class of department.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: The default variable
// was changed to "Billing" for initialization.
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: The default constructor uses a for loop to initialize
// default variiables to the instance of the array.
//
//****************************************************

Department::Department()
{
    Emp = new Employee[4];
    //The default name is set to billing.
    SetName("Billing");
    for (int i = 0; i < 4; i++)
    {
        Emp[i].SetFirst("No");
        Emp[i].SetLast("Name");
        Emp[i].SetPayRate(0);
        Emp[i].SetHours(0);
    }
}

//****************************************************
// Function: Department(const Department& eCopy)
//
// Purpose: Copy constructor is added to perform deep copies
// of the member variables within main.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: The employee array instance is
// added and member variables
// are used to make a new object from a previous
// object's copy.
//
//****************************************************
Department::Department(const Department& depCopy)
{
    Emp = new Employee[4];
    for (int i = 0; i < 4; i++)
    {
        //Array of Employee is used and a new object is made.
        Emp[i] = depCopy.Emp[i];
    }
}

//****************************************************
// Function: const department& operator=(const Department&
// departmentCopy)
//
// Purpose: The operator= overload is added to make a deep copy of the data in the member variables and will be called in main.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: departmentCopy is used as
// a parameter and member variables are used
// to copy to the right hand side.
//
//****************************************************
const Department& Department::operator=(const Department& departmentCopy)
{

    if (this == &departmentCopy)
    {
        return *this;
    }

    for (int i = 0; i < 4; i++)
    {
        Emp[i] = departmentCopy.Emp[i];

    }
    return *this;
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
// to the Emp instance as it is a dynamic
// array, nullptr is also utilized
// to avoid a dangling pointer.
//
//****************************************************
Department::~Department()
{
    //Delete is used on instance Emp.
    delete[] Emp;
    Emp = nullptr;
}

//****************************************************
// Function: ostream& operator<<(ostream& os, Employee& departmentPrint)
//
// Purpose: The operator<< overload is added to write out member variable data and will be called in main.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Emp array instance is utilized
// and Get methods are used to access member variables
// from within private for operator<< overload.
//
//****************************************************
ostream& operator<<(ostream& os, Department& departmentPrint)
{
    //This will get the name and print it out.
    os << departmentPrint.GetName() << endl;
    for (int i = 0; i < 4; i++)
    {
        //ostream os is used to output data using the get methods.
        os << departmentPrint.Emp[i].GetFirst() << endl;
        os << departmentPrint.Emp[i].GetLast() << endl;
        os << departmentPrint.Emp[i].GetPayRate() << endl;
        os << departmentPrint.Emp[i].GetHours() << endl;
    }
    //os is returned.
    return os;
}

//****************************************************
// Function: GetName()
//
// Purpose: The GetName method is used to get the department name and return it.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: GetName() is
// used to return the department
// name for later use in main.
//
//****************************************************
string Department::GetName()
{
    return name;
}

//****************************************************
// Function: SetName(string n)
//
// Purpose: The SetName method is used to set the department name to the parameter string n.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: SetName() is
// used to set the department
// name use in main to string n.
//
//****************************************************
void Department::SetName(string n)
{
    name = n;
}

//****************************************************
// Function: Employee GetHighestHoursEmployee()
//
// Purpose: The function will check the populated array and return the employee with the
// most hours
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: Employee Department::
// is added to the function definition
// to access the instance from department.
//
//****************************************************
Employee Department::GetHighestHoursEmployee()
{
    //maxHoursEmployee is set for it to be returned later.
    Employee maxHoursEmployee;
    //String l is used as the last name of the employee is a string.
    string l;
    //maxHours is set for the comparison to be made.
    double maxHours = Emp[0].GetHours();
    for (int i = 0; i < 4; i++)
    {
        //l is set to the last name of the employee from the array.
        l = Emp[i].GetLast();
        //double highestHours is used to get the hours of the employees from the array.
        double highestHours = Emp[i].GetHours();

        //Checks to see if the hours from the array is greater than default maxHours.
        if (highestHours > maxHours)
        {
            //maxHours is set to the hours from the array.
            maxHours = Emp[i].GetHours();
            //maxHoursEmployee will refer to the employee with the highest hours.
            maxHoursEmployee = Emp[i];
        }
    }
    //maxHoursEmployee is returned for use in the main function.
    return maxHoursEmployee;
}

//****************************************************
// Function: void Read(string filename)
//
// Purpose: The function will check the input file referred by the user and populate data into the Employee Emp[4] array instance.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: Set methods are organized
// next to their respective locations and
// department name is taken before the for loop.
//
//****************************************************
void Department::Read(string filename)
{
    ifstream infile;
    infile.open(filename);
    //string name is used to take in the department name after the file opens.
    string name;
    //name is read from the input file.
    infile >> name;
    //name is set to string n with the SetName() function.
    Department::SetName(name);
    string first;
    string last;
    double payRate;
    double hours;
    for (int i = 0; i < 4; i++)
    {
        //All data is read into the employee array instance Emp[4] for later use.
        infile >> first;
        Emp[i].SetFirst(first);
        infile >> last;
        Emp[i].SetLast(last);
        infile >> payRate;
        Emp[i].SetPayRate(payRate);
        infile >> hours;
        Emp[i].SetHours(hours);
    }
}

//****************************************************
// Function: void Read(string filename)
//
// Purpose: The function will check the input file referred by the user and populate data
// into the Employee Emp[4] array instance.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: Set methods are organized
// next to their respective locations and
// department name is taken before the for loop.
//
//****************************************************
void Department::Write(string filename)
{
    ofstream outfile;
    outfile.open(filename);
    //GetName() is used as it had been set and GetName() will return the department name.
    outfile << Department::GetName() << endl;
    for (int i = 0; i < 4; i++)
    {
        //The for loop is used and data from the array is output 4 times.
        outfile << Emp[i].GetFirst() << endl;
        outfile << Emp[i].GetLast() << endl;
        outfile << Emp[i].GetPayRate() << endl;
        outfile << Emp[i].GetHours() << endl;
    }
}

//****************************************************
// Function: void Report()
//
// Purpose: The function will write data to the console with descriptive text and organize
// all data based on the user choice in main.
//
// Update Information
// ------------------
//
// Name: Piyush Malik
// Date: 4/6/2021
// Description: A for loop is used to gather
// all array data and will be passed on to the
// console with setw & setprecision manipulators.
//
//****************************************************
void Department::Report()
{
    //The Department Name is returned at this part, which was obtained from the input file.
    cout << "Department Name: " << Department::GetName() << endl << endl;

    //Pieces of data will go under this based on their respective member variables.
    cout << "First" << setw(10) << "Last" << setw(12) << "Pay Rate" << setw(10) <<
        "Hours" << setw(10) << "Pay" << endl;

    //A foor loop is used to output 4 rows of data from the array instance of Emp[4].
    for (int i = 0; i < 4; i++)
    {
        //Pay will be evaluated based on the values held in the array for hours/payRate.
        double pay = Emp[i].GetPayRate() * Emp[i].GetHours();
        //Get methods are used to return each member variable to the console.
        cout << setprecision(2) << fixed << setw(5) << Emp[i].GetFirst() << setw(10) << Emp[i].GetLast() << setw(12) << Emp[i].GetPayRate() << setw(10) << Emp[i].GetHours() << setw(10) << pay << endl;
    }
}
