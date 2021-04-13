#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account .h"
#include "clock.h"
using namespace std;

Account::Account()
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail = NULL;
}

Account::Account(long ac, int co, float ba, char* ma)
{
	(co <= 9999 && co >= 1000) ? code = co : puts("ERROR: wrong code!\0");

	accountNumber = ac;
	balance = ba;
	set_mail(ma);
}

Account:: ~Account() {}

long Account::get_accountNumber() { return accountNumber; }
int Account::get_code() { return code; }
float Account::get_balance() { return balance; }
char* Account::get_mail() { return mail; }

void Account::set_balance(float ba) { balance = ba; }

void Account::set_mail(char* ma)
{
	if (ma[0] == '@')
	{
		cout << "ERROR: wrong email!\n";
		return;
	}

	int len_ma = strlen(ma);
	int i;
	for (i = 1; i < len_ma; i++) // Find the index with '@'
	{
		if (ma[i] == '@')
			break;
	}

	if (i == len_ma && ma[i] != '@') cout << "ERROR: email must contain @!\n"; //Don't have char '@'.

	i++;
	for (int j = i; j < len_ma; j++) // Check if have char ' '
	{
		if (ma[j] == ' ') // Have char ' '
		{
			cout << "ERROR: wrong email!\n";
			return;
		}
	}

	if (ma[i] == '.')// don't have at least one char after char '@'.
	{
		cout << "ERROR: email must end at .com or .co.il!\n";
		return;
	}

	else if (ma[len_ma - 4] == '.' && ma[len_ma - 3] == 'c' && ma[len_ma - 2] == 'o' && ma[len_ma - 1] == 'm')
		// Check if have ".com" in the end.
		mail = ma;

	else if (ma[len_ma - 6] == '.' && ma[len_ma - 5] == 'c' && ma[len_ma - 4] == 'o' && ma[len_ma - 3] == '.' && ma[len_ma - 2] == 'i' && ma[len_ma - 1] == 'l')
		// Check if have ".co.il" in the end.
		mail = ma;
	
	else
		cout << "ERROR: email must end at .com or .co.il!\n";
	
	cout << " i hare 1\n";
	return;
}

void Account::withdraw(float nis)
{
	if (nis > 2500) /* Exceeded credit limit*/
	{
		cout << "ERROR: cannot withdraw more than 2500 NIS!\n";
		return;
	}

	else if (balance - nis < 6000)
	{
		cout << "ERROR: cannot have less than - 6000 NIS!\n";
		return;
	}

	balance -= nis; // cash withdrawal
	sumWithdraw += nis;
}

void Account::deposit(float n)
{
	if (n > 10000)
	{
		cout << "ERROR: cannot deposit more than 10000 NIS!\n";
		return;
	}

	balance += n;
	sumDeposit += n;
}

