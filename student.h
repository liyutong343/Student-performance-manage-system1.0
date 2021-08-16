#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;

class s
{
public:
	char name[10];
	char cur[20];
private:
	int credit;
	int score;
};

class student								
{
public:
	student();
	student(int n);
	student(int n, int m);
	friend ostream& operator << (ostream&, student&);
	friend istream& operator >> (istream&, student&);
	friend fstream& operator << (fstream&, student&);
	friend fstream& operator >> (fstream&, student&);
	int credit_get();
	float gp_get();
	int score_get();
	int num;							
	char name[10];	
	char cur[20];							//cur for curriculum
private:
	int credit;
	int score;
	char grade[3] = { "" };
	float gp;								//gp for grade point
};
