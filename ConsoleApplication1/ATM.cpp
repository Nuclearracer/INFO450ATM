// Rickey Morris INFO450 Allows user to input withdrawal amount to receive cash in $50, $20, $10, $5, and $1 denominations.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double displayInstructions() //Prompts for and checks user input to see if it is within the specified range.
{
	double withdraw;
	bool checkWithdraw = false;
	cout << "Please enter withdrawal amount. ";
	do
	{
		cin >> withdraw; 
		if (withdraw >= 1 && withdraw <= 300)
		{
			checkWithdraw = true;
		}
		else
		{
			cout << "Amount must be dollar amount between $1 and $300. Please try again. ";
		}
	} while (checkWithdraw == false);
	cout << "You have..." << endl;
	return withdraw;
}
void denomination(double withdraw) //Creates array of denominations from $1 to $50 and writes the amount of each denomination out to console.
{
	int array[5] = { 50, 20, 10, 5, 1 }; //An array of denominations from $1 to $50.
	int count;
	for (count = 0; count < 5; count++)
	{
		if ((withdraw / array[count]) >= 1)
		{
			int numOfBills = withdraw / array[count];
			cout << numOfBills << " $" << array[count] << ".00 bills." << endl;
			withdraw = (int)withdraw % array[count];
		}
	}
}
int main()
{
	char reRun;
	do
	{
		int withdraw = displayInstructions();
		denomination(withdraw);
		cout << "\n\nWould you like to make another transaction? Enter 'Y' or 'y' for yes, or enter '0' to exit. ";
		cin >> reRun;
	} while (((reRun == 'Y') || (reRun == 'y')) || (reRun != '0'));
    return 0;
}

