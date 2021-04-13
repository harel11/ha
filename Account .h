#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "clock.h"
using namespace std;


class Account
{
public:
	Account();

	Account(long ac, int co, float ba, char* ma);
	~Account();

	long get_accountNumber();
	int get_code();
	float get_balance();
	char* get_mail();

	void set_balance(float ba);
	void set_mail(char* ma);

	void withdraw(float nis);
	void deposit(float n);

	

	float static getSumWithdraw();
	float static getSumDeposit();

	friend istream& operator>> (istream& o, Account& c);

private:
	long accountNumber;
	int code;
	float balance;
	char* mail;

	float static sumWithdraw;
	float static sumDeposit;
};
