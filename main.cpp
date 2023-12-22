//****************************************************
// File: main.cpp
//
// Purpose: All functions within public of Class Employee and Class Department will be
// called and the user will be prompted to select options from a menu.
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
// Description: Functions are called and
// a switch statement is used to check the
// user selection and execute a menu option
// simutaneously.
//
// Name: Piyush Malik
// Date: 4/27/2021
// Description: Default constructors, copy
// constructors, and operator overloads are
// called on case 5 of the program.
//
//****************************************************

#include "ClassDepartment.h"

int main()
{
    //An instance of Class Department is called within main.
    Department a;

    //This declaration will be used to set it to the GetHighestHoursEmployee() function.
    Employee highestHours;

    //Used to get the choice the user wants as an input statement (switch comparison).
    int choice;
    //Will be used as a parameter for getting the input file from the user.
    string keys;
    //Will be used as a parameter for setting the output file as an input statement.
    string watch;


    //Checks to see if the condition is true.
    while (true)
    {
        cout << "Department Application" << endl;
        cout << "----------------------" << endl;
        cout << "1 - Read department info from a file" << endl;
        cout << "2 - Write department info to a file" << endl;
        cout << "3 - Show department report on screen" << endl;
        cout << "4 - Show highest hours employee on screen" << endl;
        cout << "5 - Main testing code for constructors and operator overloads" << endl;
        cout << "6 - Exit" << endl;
        cout << "Enter Choice: ";
        //The user enters an int number from 1-5.
        cin >> choice;

        //The choice has to be greater or equal to 1 or less than or equal to 5.
        if (choice >= 1 && choice <= 6)
        {
            cout << endl;

            //Switch is used to check the user selection and execute based on the case.
            switch (choice)
            {
                //Reads data from an input file.
            case 1:
                cout << "Enter input filename: ";
                cin >> keys;
                a.Read(keys);
                cout << endl;
                break;
                //Outputs data to a file that the user chooses.
            case 2:
                cout << "Enter output filename: " << endl;
                cin >> watch;
                a.Write(watch);
                cout << endl;
                break;
                //Displays the report onto the console or in terminal.
            case 3:
                a.Report();
                cout << endl;
                break;
                //Displays the employee with the highest hours if option 4 is selected.
            case 4:
                //highestHours is set to the function loctated within department
                highestHours = a.GetHighestHoursEmployee();
                cout << "Highest Hour Employee" << endl;
                cout << highestHours.GetLast() << " : " << highestHours.GetHours() << endl;
                cout << endl;
                break;
                //The program enters case 5 for constructors and operator overloading tests.
            case 5:
                cout << endl;
                //Employee class is used in this function block for constructor/operator overload calls.
                {
                    //Calls an instance of the employee default constructor.
                    Employee a;

                    //Employee b is added to be used later with operator= overload.
                    Employee b;
                    b.SetFirst("John");
                    b.SetLast("Smith");
                    b.SetPayRate(25);
                    b.SetHours(20);
                    //Employee c is added to be used later with operator= overload.
                    Employee c;
                    c.SetFirst("Mat");
                    c.SetLast("Miller");
                    c.SetPayRate(15);
                    c.SetHours(40);
                    //Operator= overload is called from the employee class.
                    b = c;
                    //Operator<< overload is called from the employee class.
                    cout << "Operator << overload is called from the employee class." << endl;
                    cout << b << endl;

                    Employee d;
                    //Set methods are used to initialize data for the member variables.
                    d.SetFirst("Will");
                    d.SetLast("Baker");
                    d.SetPayRate(40);
                    d.SetHours(30);
                    //Copy constructor from the employee class is called.
                    Employee e(d);
                    //Operator<< overload is used to output class employee instance e.
                    cout << "Operator << overload is called from the employee class." << endl;
                    cout << e << endl;
                }
                //Department class is used in this function block for constructor/operator overload calls.
                {
                    //Calls class department default constructor.
                    Department d1;

                    Department d2;
                    d2.Read("Input.txt");
                    Department d3;
                    d3.Read("Inputtwo.txt");
                    //Calls the operator= overload from the department class.
                    d2 = d3;
                    Department d4;
                    d4.Read("input.txt");
                    //Calls the class department copy constructor.
                    Department d5(d4);

                    //Calls the operator<< overload from the department class (prints d2).
                    cout << "Operator << overload is called from the department class." << endl;
                    cout << d2 << endl;
                }
                break;
                //The program is done if the user enters 6.
            case 6:
                cout << "Program done." << endl;
                cout << "Press any key to continue . . . " << endl;
                exit(0);
                break;
            }
        }
        //****************************************************
        // Used to tell the user that they have entered an
        // incorrect choice if choice > 5 or choice < 1.
        //****************************************************
        else
        {
            cout << "You have entered a wrong choice." << endl << endl;
        }
    }
    return 0;
}
