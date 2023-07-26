#pragma once

#include <string>

using namespace std;

class Day
{
private:
	int start;
	int end;
	int temperature;
	int probability;
	string description;
public:

	Day(int, int, int, int, string);

	int getStart();
	int getEnd();
	int getTemp();
	int getProb();
	string getDescription();

	string toString();


};

