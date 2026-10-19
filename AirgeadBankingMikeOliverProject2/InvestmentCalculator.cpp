#include "InvestmentCalculator.h"

#include <stdexcept>

using namespace std;

const int MONTHS_PER_YEAR = 12; // number of months in a year

InvestmentCalculator::InvestmentCalculator() {
    m_initialInvestment = 0.0; // initialize initial investment amount to 0
    m_monthlyDeposit = 0.0; // initialize monthly deposit to 0
    m_annualInterest = 0.0; // initialize annual interest to 0
    m_numberOfYears = 0; // initialize number of years to 0
}

// set data
void InvestmentCalculator::setData(double t_initialInvestment, double t_monthlyDeposit,
                                   double t_annualInterest, int t_numberOfYears) {
    m_initialInvestment = t_initialInvestment; // set initial investment amount
    m_monthlyDeposit = t_monthlyDeposit; // set monthly deposit
    m_annualInterest = t_annualInterest; // set annual interest
    m_numberOfYears = t_numberOfYears; // set number of years

    // if initial investment amount, monthly deposit, annual interest, or number of years is less than 0, throw an error
    if (m_initialInvestment < 0 || m_monthlyDeposit < 0 ||
        m_annualInterest < 0 || m_numberOfYears < 0) {
        throw runtime_error("Values must be zero or greater. Try again."); // throw error
    }
}

// get initial investment amount
double InvestmentCalculator::getInitialInvestment() const {
    return m_initialInvestment;
}

// get monthly deposit
double InvestmentCalculator::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

// get annual interest
double InvestmentCalculator::getAnnualInterest() const {
    return m_annualInterest;
}

// get number of years
int InvestmentCalculator::getNumberOfYears() const {
    return m_numberOfYears;
}

// calculate monthly interest rate
double InvestmentCalculator::monthlyInterestRate() const {
    // PDF: (interest rate / 100) / 12
    return (m_annualInterest / 100.0) / MONTHS_PER_YEAR;
}

// calculate year end earned interest
double InvestmentCalculator::calculateYear(double& t_openingAmount, double t_deposit) const {
    double yearEndEarnedInterest = 0.0;

    for (int month = 1; month <= MONTHS_PER_YEAR; ++month) {
        double total = t_openingAmount + t_deposit; // calculate total
        double interest = total * monthlyInterestRate(); // calculate interest
        t_openingAmount = total + interest; // update opening amount
        yearEndEarnedInterest = yearEndEarnedInterest + interest; // update year end earned interest
    }

    return yearEndEarnedInterest; // return year end earned interest
}
