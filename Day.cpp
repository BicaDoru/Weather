#include "Day.h"

Day::Day(int start, int end, int temperature, int probability, string description) : start(start), end(end),
temperature(temperature), probability(probability), description(description)
{
}

int Day::getStart()
{
	return this->start;
}

int Day::getEnd()
{
	return this->end;
}

int Day::getTemp()
{
	return this->temperature;
}

int Day::getProb()
{
	return this->probability;
}

string Day::getDescription()
{
	return this->description;
}

string Day::toString()
{
	string string;
	string = to_string(this->start) + "-" + to_string(this->end) + ";" + to_string(this->temperature) + ";"
		+ to_string(this->probability) + ";" + this->description;
	return string;
}
