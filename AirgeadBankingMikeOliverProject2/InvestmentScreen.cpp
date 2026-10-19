#include "InvestmentScreen.h"

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// input functions

double InvestmentScreen::readDbl(const string& t_prompt) const {
    double inval;
    // loop until valid input is entered
    while (true) {
        cout << t_prompt;
        if (cin >> inval) { // check if input is a double
            return inval;
        }
        cin.clear(); // clear cin
        cin.ignore(1000, '\n'); // ignore rest of line  
        cout << "Retry" << endl; // prompt user to try again
    }
}

int InvestmentScreen::readInt(const string& t_prompt) const {
    int inval;
    // loop until valid input is entered
    while (true) {
        cout << t_prompt;
        if (cin >> inval) { // check if input is an integer
            return inval;
        }
        cin.clear(); // clear cin
        cin.ignore(1000, '\n'); // ignore rest of line
        cout << "Retry" << endl; // prompt user to try again
    }
}

// read user input
void InvestmentScreen::readUserInput(InvestmentCalculator& t_calculator) {
    // display header
    cout << "**********************************" << endl;
    cout << "*********** Data Input ***********" << endl;

    // read initial investment amount
    double initialInvestment = readDbl("Initial Investment Amount: ");
    // read monthly deposit
    double monthlyDeposit = readDbl("Monthly Deposit: ");
    // read annual interest
    double annualInterest = readDbl("Annual Interest: ");
    // read number of years
    int numberOfYears = readInt("Number of years: ");

    // set data in investment calculator
    t_calculator.setData(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);
}

// wait for user to press a key
void InvestmentScreen::waitForKey() const {
    // prompt user to press a key
    cout << "Press any key to continue . . .";
    cin.ignore(1000, '\n'); // ignore the rest of the line
    cin.get(); // wait for user to press a key
}

// output functions for displaying input and reports

// format double as dollar amount
string InvestmentScreen::makeDollarFormat(double t_value) const {
    ostringstream out; // create string stream  
    out << fixed << setprecision(2) << "$" << t_value; // format double as dollar amount
    return out.str();
}

// display complete input
void InvestmentScreen::displayCompleteInput(const InvestmentCalculator& t_calculator) const {
    cout << endl;
    cout << "**********************************" << endl; // display header
    cout << "*********** Data Input ***********" << endl; // display header
    cout << fixed << setprecision(2); // set precision to 2 decimal places
    cout << "Initial Investment Amount: $" << t_calculator.getInitialInvestment() << endl; // display initial investment amount
    cout << "Monthly Deposit: $" << t_calculator.getMonthlyDeposit() << endl; // display monthly deposit
    cout << "Annual Interest: %" << t_calculator.getAnnualInterest() << endl; // display annual interest
    cout << "Number of years: " << t_calculator.getNumberOfYears() << endl; // display number of years
}

// print report with or without monthly deposits
void InvestmentScreen::printReport(const InvestmentCalculator& t_calculator,
                                   bool t_includeMonthlyDeposits) const {
    if (t_includeMonthlyDeposits) { // if monthly deposits are included in the report
        cout << "    Balance and Interest With Additional Monthly Deposits" << endl;
    }
    else { // if monthly deposits are not included in the report
        cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
    }

    cout << "==============================================================" << endl; // display header
    cout << " Year          Year End Balance          Year End Earned Interest" << endl; // display header
    cout << "--------------------------------------------------------------" << endl; // display header

    double openingAmount = t_calculator.getInitialInvestment(); // get initial investment amount
    double deposit = 0.0; // initialize deposit to 0
    if (t_includeMonthlyDeposits) { // if monthly deposits are included in the report
        deposit = t_calculator.getMonthlyDeposit(); // get monthly deposit
    }

    cout << fixed << setprecision(2); // set precision to 2 decimal places

    for (int year = 1; year <= t_calculator.getNumberOfYears(); ++year) {
        double yearEndEarnedInterest = t_calculator.calculateYear(openingAmount, deposit); // calculate year end earned interest

        cout << setw(5) << year // format year
             << setw(26) << makeDollarFormat(openingAmount) // format opening amount
             << setw(32) << makeDollarFormat(yearEndEarnedInterest) // format year end earned interest
             << endl; // display year end earned interest
    }

    cout << endl; // display new line
}

// display reports
void InvestmentScreen::displayReports(const InvestmentCalculator& t_calculator) const {
    // display header
    cout << endl;
    printReport(t_calculator, false); // display report without monthly deposits    
    printReport(t_calculator, true); // display report with monthly deposits
}
