//----------------------------------------------------------------------------
// EGR 126 ELI Fall 2017
//----------------------------------------------------------------------------
// Student Name : Rich MURPHY
// Assignment : Assignment # 7 on 1-D arrays
// Submission Date: 10/20/17
// Complier Info : MacOS, Xcode
// Purpose : This program searchs an array for a user entered value.
//----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// These are our variables.
int i = 0, key, flag = 0, attempt = 1;

// This function reads the file into an array which we then check a user entered value against.
// If the keyed in value is equal to the first array value we set a flag and break from the loop,
// if not we iterate to the next value in the array until we find it or don't.
void mySequentialSearch()
    {
    int codes[300];
    ifstream codefile("SystemAccessCodes.txt");
        
    if (codefile.is_open())
        {
        for (int i = 0; i < 300; ++i)
            {
            codefile >> codes[i];
            
            if (codes[i] == key)
                {
                flag = 1;
                }
            }
        }
    }

int main()
    {
    while (attempt > 0)
        {
        cout << "=====ENTER YOUR CODE TO ACCESS INTO THE SYSTEM=====" << endl;
        cout << endl;
        
        do
            {
            cout << "Attempt " << attempt << "/3 : ENTER 4 DIGIT CODE: ";
            cin >> key;
            
            mySequentialSearch();
            
                if (flag == 1) // This is our output message if we find the users entry in the array.
                        {
                        cout << "==================================================" << endl;
                        cout << "ACCESS GRANTED \n WELCOME" << endl;
                        cout << "==================================================" << endl;
                        }
            
                        else // If we dont find it we increment the number of attempts.
                            {
                            attempt++;
                            }
            
                if (attempt < 4 && flag !=1) // This is our output message for the first two failed attempts.
                        {
                        cout << "NOT MATCHING! TRY AGAIN" << endl << endl;
                        }
            
                if (attempt > 3) // This is our output message if a third attempt fails.
                        {
                        cout << "==================================================" << endl;
                        cout << "ACCESS DENIED \n BYE" << endl;
                        cout << "==================================================" << endl;
                        return 0;
                        }
            
            } while (flag != 1);
    
          system("pause");
        
        return 0;
        }
    }
