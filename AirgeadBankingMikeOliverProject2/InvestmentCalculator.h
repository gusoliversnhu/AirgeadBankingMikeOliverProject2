#ifndef PROJECT2_INVESTMENT_CALCULATOR_H_
#define PROJECT2_INVESTMENT_CALCULATOR_H_

// stores user's investment values and calculates monthly interest
class InvestmentCalculator {
public:
    InvestmentCalculator(); // constructor

    void setData(double t_initialInvestment, double t_monthlyDeposit,
                 double t_annualInterest, int t_numberOfYears); // set data

    double getInitialInvestment() const; // get initial investment amount
    double getMonthlyDeposit() const; // get monthly deposit
    double getAnnualInterest() const; // get annual interest
    int getNumberOfYears() const; // get number of years

    // calculate year end earned interest
    double calculateYear(double& t_openingAmount, double t_deposit) const; // calculate year end earned interest

private:
    double m_initialInvestment; // initial investment amount
    double m_monthlyDeposit; // monthly deposit
    double m_annualInterest; // annual interest
    int m_numberOfYears; // number of years

    double monthlyInterestRate() const; // calculate monthly interest rate  
};

#endif // PROJECT2_INVESTMENT_CALCULATOR_H_
