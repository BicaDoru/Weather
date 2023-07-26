#include "Service.h"


Day Service::parseDay(string line)
{
	stringstream ss(line);
	string strStart, strEnd, strTemp, strProb, descrp;

	getline(ss, strStart, ';');
	getline(ss, strEnd, ';');
	getline(ss, strTemp, ';');
	getline(ss, strProb, ';');
	getline(ss, descrp, '\n');

	int start = stoi(strStart);
	int end = stoi(strEnd);
	int temp = stoi(strTemp);
	int prob = stoi(strProb);

	return Day(start, end, temp, prob, descrp);
}


Service::Service()
{
	ifstream fileIn("data.txt");

	if (fileIn.is_open())
	{
		string line;

		while (getline(fileIn, line))
		{
			Day day = this->parseDay(line);
			this->days.push_back(day);

		}
	}

}

bool Service::compareDays(Day& lhs, Day& rhs)
{
	return (lhs.getEnd() - lhs.getStart()) < (rhs.getEnd() - rhs.getStart());
}

void Service::sortDays()
{
	sort(this->days.begin(), this->days.end(), compareDays);
}

vector<Day> Service::getDays()
{
	return this->days;
}

vector<Day> Service::filterByProb(int prob)
{
	vector<Day> intervals;

	for (auto& day : this->getDays())
	{
		if (day.getProb() < prob)
			intervals.push_back(day);
	}

	return intervals;

}

int Service::nrHours(int start, string description)
{
	int total = 0;

	for (auto& day : this->days)
	{
		if (day.getDescription() == description && (day.getStart() <= start && day.getEnd() >= start))
		{
			total += day.getEnd() - start;
		}
	}

	return total;
}