#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;


void printItinerary(map<string, string> dataSet)
{
	map <string, string > reversemap;
	map<string, string> ::iterator it;


	//To fill reverse map, iterate through the given map
	for (it=dataSet.begin() ; it!= dataSet.end() ; it++ )
	{
		reversemap[it->second] = it->first;
	}

	string start;
	for (it = dataSet.begin() ; it != dataSet.end() ; it++)
	{
		// find it ->first is not exit reversemap->second
		if (reversemap.find(it->first)== reversemap.end()) 
		{
			start = it->first;
			break;
		}
	}


	// If we could not find a starting point, then something wrong with input 
	if (start.empty())
	{
		cout << "Invalid Input" << endl;
		return;
	}

	
	it = dataSet.find(start);
	while (it != dataSet.end())
	{
		cout << it->first << " " << it->second << endl;
		it = dataSet.find(it->second);
	}


}



int main() 
{
	map<string, string> dataSet;
	dataSet["Chennai"] = "Banglore";
	dataSet["Bombay"] = "Delhi";
	dataSet["Goa"] = "Chennai";
	dataSet["Delhi"] = "Goa";

	printItinerary(dataSet);
	system("pause"); 
	return 0;
}




