#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Professor
{
private:
	string course_id;
	string name;
	double rating;
	int start_time;
	int end_time;
	vector <char> day_taught;
public:
	Professor();
	Professor(string c_id, string name, double rating, int start_time, int end_time, vector <char> days);
	void AddNode(string c_id, int course_id_num, string name, double rating, int start_time, int end_time, vector <char> days, vector <Professor*>& list);
	void Display();
	string getCourseID();
	string getName();
	double getRating();
	int getStartTime();
	int getEndTime();
	string getDay();
};

#endif

