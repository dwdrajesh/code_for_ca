#include <iostream>
#include <vector>
#include <string>
#include "rapidcsv.h"

int main()
{
  rapidcsv::Document doc("C4C-dev-challenge-2018.csv");

//  std::vector<float> close = doc.GetColumn<float>("Close");
//  std::cout << "Read " << close.size() << " values." << std::endl;
//
//  long long volume = doc.GetCell<long long>("Volume", "2017-02-22");
//  std::cout << "Volume " << volume << " on 2017-02-22." << std::endl;

std::vector<std::string> violation_categories = doc.GetColumn<std::string>("violation_category");
std::vector<std::string> violation_dates = doc.GetColumn<std::string>("violation_date");
std::vector<std::string> dates;
for (int i = 0; i < violation_dates.size(); i++)
{
	dates.push_back(violation_dates.at(i));
}

std::cout << "Total number of rows: " << doc.GetRowCount() << std::endl;
std::map<std::string, int> count;
std::map<std::string, std::string> earliest;

for (int i = 0; i < doc.GetRowCount(); i++)
{
	
	std::string cat = violation_categories.at(i);
	std::string date = dates.at(i);
	std::map<std::string, int>::iterator it;
	std::map<std::string, std::string>::iterator it_date;
	it_date = violation_dates.find(cat);
	it = count.find(cat);	
	if (it != count.end())
		{
		count[cat] += 1;
		if (date.compare(violation_dates[cat]) < 0)
			{
			earliest[cat] = date;
			}
		
		}
	else
		count[cat] = 1;


	
}
for (std::map<std::string, int>::const_iterator it = count.begin(); it != count.end(); ++it)
{
	std::cout << it->first << ' ' << it->second << std::endl;

}

for (std::map<std::string, std::string>::const_iterator it = earliest.begin(); it != earliest.end(); ++it)
{
	std::cout << it->first << ' ' << it->second << std::endl;

}
}
