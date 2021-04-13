#pragma once
#include <iostream>
using namespace std;

class Clock
{
private:
	int	hour; // 0 - 23
	int minute; // 0 - 59
	int second; // 0 - 59

public:

	Clock(int h = 0, int m = 0, int s = 0);
	Clock(const Clock& c);
	Clock();
	~Clock();

	int get_hour();
	int get_minute();
	int get_second();

	void set_hour(int t);
	void set_minute(int t);
	void set_second(int t);
		
	Clock& operator +=(int );

	friend ostream& operator<<(ostream& o, Clock& c);
	friend istream& operator>> (istream& o, Clock& c);
};
