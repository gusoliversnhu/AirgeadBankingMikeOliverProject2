# Airgead Banking App

Console program Project Two. It shows how an investment grows with compound interest, with and without monthly deposits.

## Summary

Airgead Banking needed a way to show investment growth without making the customer do the math by hand. The user enters an initial amount, a monthly deposit, an annual interest rate, and a number of years. The program prints two yearly reports: one with no extra deposits, and one that includes them. The user can change the inputs and run it again.

## What went well

The math and the screen are separate.

- `InvestmentCalculator` stores the four values and runs the 12-month interest loop.
- `InvestmentScreen` handles prompts, the input summary, and both reports.
- `main` creates those two objects and loops until the user says no keeping main small.



## Possible enhancements

Monthly interest stays a `double` for the whole run. The requirements example rounds to the nearest cent each month. Rounding inside `calculateYear` would keep year-end balances closer to a bank statement and avoid small drift over many years.

A year count of zero should be rejected, and a large upper limit would stop a huge year value from running the loop for a long time. This is a local console program, so the security concern is bad input. The retry loops and the negative-value check already cover most of that. Clearing the rest of the line after a bad entry would make those checks harder to skip.

## Hardest parts

The monthly compound formula was the hardest piece. Interest is charged on the opening balance plus that month's deposit, and the result becomes next month's opening balance. I used the formula from the requirements, `(interest rate / 100) / 12`, and checked a short example by hand before trusting the loop.

Splitting one class into a calculator and a screen was the other hard part. I wrote the flow in pseudocode first, then moved only the input and print functions into `InvestmentScreen`.

Resources I will keep using:

- Visual Studio
- The Airgead standards PDF has some good reminders

## Transferable skills

- Header and `.cpp` split
- Keeping `main` small and putting the work in classes
- Passing objects by reference, and using `const` when a function only reads data
- Reusing one calculation for two reports
- Input validation and `try`/`catch`, so bad input prints a message instead of crashing

## Maintainable, readable, adaptable

Each class has one job, and the names say what that job is. `calculateYear` is the only place that knows how a year of interest works, so a formula change does not have to be made twice. Dollar amounts go through `makeDollarFormat`, so the `$` and two decimal places stay consistent. `MONTHS_PER_YEAR` replaces a bare `12`. A new report can call `calculateYear` again without rewriting the monthly loop.

## Files

| File | Role |
| --- | --- |
| `main.cpp` | Creates the objects and repeats until the user quits |
| `InvestmentCalculator.h` / `.cpp` | Stored values and monthly interest |
| `InvestmentScreen.h` / `.cpp` | Prompts, summary, and both reports |
