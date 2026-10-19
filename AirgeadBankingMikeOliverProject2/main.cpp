/*
 * Mike Oliver
 * Airgead Banking App
 * 09/30/26
 */

#include <iostream>
#include <cctype>
#include <stdexcept>

#include "InvestmentCalculator.h"
#include "InvestmentScreen.h"

using namespace std;

int main() {
    InvestmentCalculator calculator; // create investment calculator object
    InvestmentScreen screen; // create investment screen object 
    char userChoice = 'Y';

    // main loop
    while (tolower(userChoice) == 'y') { // continue loop if user chooses to test different values
        try { // try to read user input
            screen.readUserInput(calculator); // read user input
            screen.displayCompleteInput(calculator); // display complete input
            screen.waitForKey(); // wait for user to press a key
            screen.displayReports(calculator); // display reports
        }
        catch (const exception& t_error) { // catch exception and display any error messages
            cout << t_error.what() << endl; // display error message
            cin.clear(); // clear cin
            cin.ignore(1000, '\n'); // ignore rest of line
        }

        cout << "Do you want to test different values? Y/N: "; // prompt user to test different values
        cin >> userChoice; // read user choice
        cout << endl; // add a new line
    }

    return 0; // return 0 to indicate success   
}
