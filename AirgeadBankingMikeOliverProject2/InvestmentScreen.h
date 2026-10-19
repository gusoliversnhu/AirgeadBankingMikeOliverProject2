#ifndef PROJECT2_INVESTMENT_SCREEN_H_
#define PROJECT2_INVESTMENT_SCREEN_H_

#include "InvestmentCalculator.h"

#include <string>
using namespace std;

// handles input and output for the investment calculator
class InvestmentScreen {
public:
    void readUserInput(InvestmentCalculator& t_calculator); // read user input
    void displayCompleteInput(const InvestmentCalculator& t_calculator) const; // display complete input
    void displayReports(const InvestmentCalculator& t_calculator) const; // display reports
    void waitForKey() const; // wait for user to press a key

private:
    double readDbl(const string& t_prompt) const; // read double
    int readInt(const string& t_prompt) const; // read integer
    string makeDollarFormat(double t_value) const; // format double as dollar amount
    // print report with or without monthly deposits
    void printReport(const InvestmentCalculator& t_calculator, bool t_includeMonthlyDeposits) const; 
                     
};

#endif // PROJECT2_INVESTMENT_SCREEN_H_
