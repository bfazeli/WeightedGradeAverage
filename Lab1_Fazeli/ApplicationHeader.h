#pragma once
#include <map>

/*
Greets the user and welcomes him/her to the program.
*/

void greet();

/* 
Collect user's input for a map's key-value pairs.

@param A map reference to populate category and weight.
@param A map reference to populate the category's weight.
*/
void categoryInput(std::map<std::string, int> &, std::map<int, int> &);

/*
Collects an input for a specific category

@param A map of category and weight.
@param A map weights and averages.
*/
void collectAndDisplay(std::map<std::string, int> &, std::map<int, int> &);

/*
Calculates the weight of a category

@param The weight of the category.
@param The sum of values for that category.
*/
int calculateCategoryAverage(int, int);

/*
Calculates the students average

@param A map of a category's weight and it's avg.
*/
int calculateStudentAvg(const std::map<int, int> &);



