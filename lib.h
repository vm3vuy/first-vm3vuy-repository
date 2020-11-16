#ifndef HELLO_H
#define HELLO_H

#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
//using std::string;

void Delay(time_t nSecond);

class PrintName{
public:
	char name1[50],name2[50];	
	void print_name(void);
};


class InvestCal{
public:
	double capital,yearRate,years,sum,capsum;	

	void InitCapInvestCal(void);	
	void PeriodCapInvestCal(void);	

};


#define N    26
#define DIFF 97
class Encrypt{
public:
	string EnstrTable;

	//依現在時間產生一個初始EnstrTable值
	Encrypt();

	void setEnstrTable(void);
	string enstring(string);
	string destring(string);

};




#endif
