/*
This is BMCC CSC 350 class project.
The original project's objective is to create a tax calculation web page using PHP and XHAMPP.
In this file, the original project is written in C++.
This code lets the user put the income and will give out the amout of tax due and the income after tax.
*/


#include <iostream>
using namespace std;

//single status tax calculation funciton
void single_calculate(double income) {
  double tax;

  if (income >= 0 && income <= 9275)
    tax = (income * 10 / 100);
  else if (income >= 9276 && income <= 37650)
    tax = (927.5 + ((income-9275) * 15 / 100));
  else if (income >= 37651 && income <= 91150)
    tax = (5183.75 + ((income-37650) * 25 / 100));
  else if (income >= 91151 && income <= 190150)
    tax = (18558.75 + ((income-91150) * 28 / 100));
  else if (income >= 190151 && income <= 413350)
    tax = (46278.75 + ((income-190150) * 33 / 100));
  else if (income >= 413351 && income <= 415050)
    tax = (119934.75 + ((income-413350) * 35 / 100));
  else
    tax = (120529.75  + ((income-415050) * 39.6 / 100));

  cout << "Status: Single" << endl;
  cout << "Income: $" << income << endl;
  cout << "Tax due: $" << tax << endl;
  cout << "Income after tax: $" << income - tax << endl;
}

//married status tax calculation function
void married_calculate(double income) {
  double tax;

  if (income >= 0 && income <= 18450)
    tax = (income * 10 / 100);
  else if (income >= 18451 && income <= 74900)
    tax = (1845 + ((income-18450) * 15 / 100));
  else if (income >= 74901 && income <= 151200)
    tax = (10312.5 + ((income-74900) * 25 / 100));
  else if (income >= 151201&& income <= 230450)
    tax = (29387.5 + ((income-151200) * 28 / 100));
  else if (income >= 230451 && income <= 411500)
    tax = (51577.5 + ((income-230450) * 33 / 100));
  else if (income >= 411501 && income <= 464850)
    tax = (111324 + ((income-411500) * 35 / 100));
  else if (income >= 464851)
    tax = (129996.5  + ((income-464850) * 39.6 / 100));

  cout << "Status: Married" << endl;
  cout << "Income: $" << income << endl;
  cout << "Tax due: $" << tax << endl;
  cout << "Income after tax: $" << income - tax << endl;
}

//This function shows the tax percentage on income according to the status of the user.
void status_check(char status) {

  double income;
  //'s' is for single status and 'm' is for married status
  if(status == 's') {
    cout << "Followings are the percentage for single status." << endl;
    cout << "From $0 to $9,275 => " << "10% of income" << endl;
    cout << "From $9,276 to $37,650 => " << "$927.5 plus 15% of amount over $9,275" << endl;
    cout << "From $37,651 to $91,150 => " << "$5,183.75 plus 25% of the amount over $37,650" << endl;
    cout << "From $91,151 to $190,150 => " << "$18,558.75 plus 28% of the amount over $91,150" << endl;
    cout << "From $190,151 to $ 413,350 => " << "$46,278.75 plus 33% of the amount over $190,150" << endl;
    cout << "From $413,351 to $415,050 => " << "$119,934.75 plus 35% of the amount over $413,350" << endl;
    cout << "$415,051 or more => " << "$120,529.75 plus 39.6% of the amount over $415,050" << endl;

    cout << "Please enter your income: ";
    cin >> income;
    single_calculate(income);
  }
  else if(status == 'm') {
    cout << "Followings are the percentage for married status." << endl;
    cout << "From $0 to $18,450 => " << "10% of income" << endl;
    cout << "From $18,451 to $74,900 => " << "$1,845.00 plus 15% of the amount over $18,450" << endl;
    cout << "From $74,901 to $151,200 => " << "$10,312.50 plus 25% of the amount over $74,900" << endl;
    cout << "From $151,201 to $230,450 => " << "$29,387.50 plus 28% of the amount over $151,200" << endl;
    cout << "From $230,451 to $411,500 => " << "$51,577.50 plus 33% of the amount over $230,450" << endl;
    cout << "From $411,501 to $464,850 => " << "$111,324.00 plus 35% of the amount over $411,500" << endl;
    cout << "$$464,851 or more => " << "$129,996.50 plus 39.6% of the amount over $464,850" << endl;

    cout << "Please enter your income: ";
    cin >> income;
    married_calculate(income);
  }
}

int main() {

  char status;

  cout << "Welcome to MTKo Tax Calculator!" << endl;
  cout << "Please select the menu." << endl;
  cout << "(a) Sigle Status Tax Calculatione" << endl;
  cout << "(b) Married Status Tax Calulation" << endl;
  cout << "(c) Exit!" << endl;
  cin >> status;
  switch(status) {
  case 'a':
    status_check('s');
    break;
  case 'b':
    status_check('m');
    break;
  default: break;
  }

  cout << "Thank you for using MTKo Tax Calculator!" << endl;

  return 0;
}
