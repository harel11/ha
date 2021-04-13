#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "clock.h"
using namespace std;


Clock::Clock(int h, int m, int s)
{
	if ((h > 23 || h < 0) || (m > 59 || m < 0) || (s > 59 || s < 0))
	{
		set_hour(h);
		set_minute(m);
		set_second(s);
	}
	else
	{
		set_hour(0);
		set_minute(0);
		set_second(0);
	}

}

Clock::Clock(const Clock& c)
{
	set_hour(c.hour);
	set_minute(c.minute);
	set_second(c.second);
}

Clock::Clock() 
{
	hour = 0;
	minute = 0;
	second = 0;
} 
Clock:: ~Clock() {}

int Clock::get_hour() { return hour; }

int Clock::get_minute() { return minute; }

int Clock::get_second() { return second; }

void Clock::set_hour(int t) { if (t <= 23 && t >= 0) hour = t; }

void Clock::set_minute(int t) { if(t <= 59 && t >= 0) minute = t; }

void Clock::set_second(int t) { if (t <= 59 && t >= 0) second = t; }

Clock& Clock:: operator +=(int s)
{
	second += s;
	while (second > 59)
	{
		minute++;
		second -= 60; // if i have in second 61 so i need to be in 1 second, therefore 61 - 60.
	}

	while (minute > 59)
	{
		hour++;
		minute -= 60;
	}

	while (hour > 23)
	{
		hour -= 24;
	}

	return *this;
}