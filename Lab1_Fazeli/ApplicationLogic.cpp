#include "ApplicationHeader.h"
#include <string>
#include <iostream>

using namespace std;

void greet()
{
	cout << "Weighted Average Calculator\n" <<
		"------------------------------------------\n" <<
		"This program will help you determine your overall average based\n" <<
		"on the weights of each category and your current grades\n" <<
		"You must enter each category's weight. Then you must enter\n" <<
		"the grades for that category.The final grade will then be displayed\n" <<
		"------------------------------------------\n" << endl;
}

void categoryInput(map<string, int> & categoryWeightMap, map<int, int> & weightAvgMap)
{
	int limit = -1;
	double weightTotal = 0;

	string category = "";
	double weight = -1;
	bool totalLessThanLimit = false;

	do
	{
		do
		{
			cout << "How many categories? ";
			cin >> limit;
		} while (limit > 5 || limit < 1);

		for (int i = 0; i < limit; i++)
		{
			cout << "\nEnter category " << i + 1 << " name: ";
			cin.ignore();
			getline(cin, category);
			cout << "Enter category weight: ";
			cin >> weight;
			weightTotal += weight;

			while (weight < 0 || weight > 1)
			{
				weightTotal -= weight;
				cout << "Invalid number. Enter a number between 0 and 1." << endl;
				cout << "Enter category weight: ";
				cin >> weight;
				weightTotal += weight;
			}

			if ((abs(weightTotal-1) > .0000001) && i + 1 == limit)
			{
				cout << "\nSum of weights must be equal to 1.";
				categoryWeightMap.clear();
				weightAvgMap.clear();
				totalLessThanLimit = false;
				i = -1;
			}
			else if ((abs(weightTotal-1) < .00000001) && i + 1 < limit)
			{
				cout << "\nSum of weights have been met, but categories entered do not add up to "
					<< limit << "." << endl;
				categoryWeightMap.clear();
				weightAvgMap.clear();
				totalLessThanLimit = true;
				break;
			}
			else
			{
				categoryWeightMap[category] = weight;
				weightAvgMap[weight];
				totalLessThanLimit = false;
			}
		}
	} while (totalLessThanLimit);
}

void collectAndDisplay(map<string, int> & categoryWeightMap, map<int, int> & weightAvgMap)
{
	double sum = 0, input = 0, average;
	bool done = false;
	map<int, int>::iterator it_W_A = weightAvgMap.begin();
	for (map<string, int>::const_iterator it_C_W = categoryWeightMap.cbegin(); 
		it_C_W != categoryWeightMap.cend(); ++it_C_W, ++it_W_A) 
	{
		cout << "\nEnter all grades for " << it_C_W->first << ".";
		while (abs(input + 1) > .000001)
		{
			cout << "Enter grade or -1 to quit: ";
			cin >> input;
			if (input >= 0 && input < 101) sum += input;
			else if (abs(input + 1) < .000001) break;
			else cout << "Invalid grade. Grade must be between 0 and 100." << endl;
		}

		it_W_A->second = calculateCategoryAverage(it_C_W->second, sum);
		cout << it_C_W->first << " average: " << it_W_A->second << endl;

	}
}

int calculateCategorAverage(int weight, int sum)
{

}