/*
Harel Yehiel
316334259
introduction of computers science
Exercise 3 question 3
Get two string and add the first string to second string in index I will get too.
print the ratio between the strings.
change the index (I will get too) to char (I will get too).
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account .h"
#include "clock.h"
#include <time.h>
#include <cstring>
using namespace std;

float Account::sumWithdraw = 0;
float Account::sumDeposit = 0;
float  Account::getSumWithdraw() { return sumWithdraw; }
float Account::getSumDeposit() { return sumDeposit; }

ostream& operator<<(ostream& o, Clock& c)
{
	(c.hour < 10) ? cout << "0" << c.hour : cout << c.hour;
	(c.minute < 10) ? cout << ":0" << c.minute : cout << ":" << c.minute;
	(c.second < 10) ? cout << ":0" << c.second : cout << ":" << c.second;
	cout << endl;

	return o;
}

istream& operator>> (istream& o, Clock& c)
{
	bool flag = true;
	// If one of the inputs don't in the correct area, so put 0 in hour, minute, second.
	// It change the flag to false and in the end of function in 'if(flag)' we go to the 'else'.

	int h, m, s;
	cin >> h >> m >> s;

	c.set_hour(h);
	c.set_minute(m);
	c.set_second(s);

	if (h > 23 || h < 0)
	{
		(h > 23) ? cout << "Invalid time - more than 24 hours.\n" : cout << "Invalid time - negative number of hours.\n";
		flag = false;
	}

	if ((m > 59 || m < 0) || (s > 59 || s < 0))
	{
		(m > 59) ? cout << "Invalid time - more than 60 minutes.\n" : cout << "Invalid time - negative number of minutes.\n";
		flag = false;
	}

	if (s > 59 || s < 0)
	{
		(s > 59) ? cout << "Invalid time - more than 60 seconds.\n" : cout << "Invalid time - negative number of seconds.\n";
		flag = false;
	}

	if (flag) // If flag true, so we don't enter to the other 'ifs' in above 
	{
		c.hour = h;
		c.minute = m;
		c.second = s;
	}
	else
	{
		c.hour = 0;
		c.minute = 0;
		c.second = 0;
	}

	return o;
}

istream& operator>> (istream& o, Account& a)
{
	long ac;
	int co;
	char* ma = new char(81);

	//cin >> ac >> co;

	srand((unsigned)time(NULL));
	ac = rand() % 900000 + 100000;
	co = rand() % 9000 + 1000;
	cout << ac << endl << co << endl;

	cin.getline(ma, 80, '\n');
	ma[strlen(ma)] = '\0';

	a.accountNumber = ac;

	if (co <= 9999 && co >= 1000)
		a.code = co;
	else
	{
		cout << "ERROR: code must be of 4 digits!\n";
		a.code = 0;
	}

	a.set_mail(ma);
	cout << " i hare 2\n";
	a.balance = 0;

	cout << " i hare 3\n";
	return o;
}

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].get_accountNumber() != number)
		i++;
	cout << "please enter the code: ";
	cin >> code;
	if (i < size && bank[i].get_code() == code)
		return i;
	return -1;
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";

	switch (ac)
	{
	case balance: cout << "account #: " << a.get_accountNumber() << "\t";
		cout << "balance: " << a.get_balance() << endl;
		break;

	case deposit: cout << "account #: " << a.get_accountNumber() << "\t";
		cout << "new balance: " << a.get_balance() << endl;
		break;

	case withdraw:
		cout << "account #: " << a.get_accountNumber() << "\t";
		cout << "new balance: " << a.get_balance() << endl;
		break;

	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;

	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	if (i < 0) // Don't find the account.
		return;

	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	if (i < 0) // Don't find the account.
		return;
	
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	if (i < 0) // Don't find the account.
		return;

	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}
int main()
{
	Clock c(8);
	Account bank[10];

	cout << "enter account number, code and email for 10 accounts:\n";
	for (int i = 0; i < 10; i++)
	{
		try {
			cout << " i hare asd \n";
			cin >> bank[i];
			cout << " i hare 4\n";

			for (int j = 0; j < i; j++)
			{
				if (bank[i].get_accountNumber() == bank[j].get_accountNumber())
					throw "ERROR: account number must be unique!\n";
			}
			cout << " i hare 5\n";
		}
		
		catch (const char* msg)
		{
			cout << " i hare 6\n";
			cout << c << '\t' << msg;
			i--;
		}
	}
	cout << " i hare 7\n";
	action ac = menu();
	while (ac)
	{
		cout << " i hare 8\n";
		switch (ac)
		{
		case balance: getBalance(bank, 10, c);
			break;
		case withdraw:cashWithdraw(bank, 10, c);
			break;
		case deposit:cashDeposit(bank, 10, c);
			break;
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithdraw:c += 60;
			printTransaction(bank[0], sumWithdraw, c);

		}
		ac = menu();
	}
	return 0;
}
/*
harel@m.com
uwe@.co.il
asd@qw.co.il
asdsa@as.com
asd@ee.com
fes@we.com
ytey@sd.com
uytu@sd.co.il
kyuk@as.co.il
awds@ww.co.il
*/