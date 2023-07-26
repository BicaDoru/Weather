#pragma once

#include <vector>
#include "Day.h"
#include <algorithm>
#include <fstream>
#include <sstream>

class Service
{

private:
	vector<Day> days;

public:

	Service();

	static bool compareDays(Day&, Day&);
	Day parseDay(string);
	void sortDays();

	vector<Day> filterByProb(int);

	vector<Day> getDays();

	int nrHours(int, string);

};

