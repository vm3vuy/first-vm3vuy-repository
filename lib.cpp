#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>


#include "lib.h"


void Delay(time_t nSecond)
{
	for (time_t tStart = time(0); time(0) - tStart < nSecond; ){
		// Nothing to do
	}
}




// PrintName  member func
void PrintName::print_name(void){

	int i;

	cout << "第一個名子=" << name1 << endl;
	cout << "第二個名子=" << name2 << endl;

	cout << "第一個名子的UTF8字串碼為" << endl;
	i=0;
	while(1){

		if(name1[i]!=0)
			printf("%x ",name1[i++]);
		else{
			printf("\n");
			break;
		}
	}

}


// InvetCal  member func
void InvestCal::InitCapInvestCal(void){

	sum = capital * pow( 1+yearRate , years);

}

void InvestCal::PeriodCapInvestCal(void){

	int i;

	sum=0;
	capsum=0;
	for(i=0; i<years; i++){
		capsum = capsum + capital;

		sum = capital + sum;
		sum = sum * (1+yearRate);
	}

}	


// Encrypt  member func
Encrypt::Encrypt(){

	setEnstrTable();

}



void Encrypt::setEnstrTable(void){

	char c;
	string s = "";

	// Delay(sec) ,delay n sec
	Delay(1);
	srand(time(0));
	for (int i = 0; i < N; i++) {

		while(1){
			c = rand()%26 + 'a';

			if ( s.find(c) == std::string::npos )
				break;	
		}
	
		s += c ; 
	}
     
	EnstrTable = s;

}

string Encrypt::enstring(string ostr){

	string estr="";

	for (int i = 0; i < (int)ostr.size(); i++) {
		if ( (ostr.at(i) >= DIFF) && (ostr.at(i) <= (DIFF+N-1)) ) {

			estr += EnstrTable.at( ostr.at(i)-DIFF );
		}
		else{
			estr += ostr.at(i);
		}
	}
     
	return estr;
}

string Encrypt::destring(string estr){

	string ostr;

	for (int i = 0; i < (int)estr.size(); i++) {
		if ( (estr.at(i) >= DIFF) && (estr.at(i) <= (DIFF+N-1)) ) {
			for (int j = 0; j < N; j++) {
				if (estr.at(i) == EnstrTable.at(j)) {
					ostr += (char) (j + DIFF);
					break;
				}
			}
		}
		else {
			ostr += estr.at(i);
		}
	}

	return ostr;

}




