#include "ApplicationHeader.h"

using namespace std;

int main()
{
	greet();

	map<string, int> catAndWeightMap;
	map<int, int> weightAndAvgMap;
	categoryInput(catAndWeightMap, weightAndAvgMap);
	collectAndDisplay(catAndWeightMap, weightAndAvgMap);
	system("pause");
	return 0;
}