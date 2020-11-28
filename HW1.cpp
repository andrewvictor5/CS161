/****************************************************************************************************************************************************************************************
** Program Filename: Homework 1
** Author: Andrew Victor
** Date: January 12th, 2018
** Description: Math and Variables
****************************************************************************************************************************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;
int main () {

	int c1 = 2;
	int c2 = 3;
	float result1 = cos(c1/c2);
	cout << "cos (2/3) is " << result1 <<endl;

	float result2 = (2 * sin(c1/c2));
	cout << "2sin(2/3) is " << result2 <<endl;

	c1 = -3;
	c2 = 4;
	float result3 = tan(c1/c2);
	cout << "tan(-3/4) is " << result3 <<endl;

	c1 = 55;
	float result4 = log10(c1);
	cout << "The common log of 55 is " << result4 <<endl;

	c1 = 60;
	float result5 = log(c1);
	cout << "The natural log of 60 is " << result5 <<endl;

	c1 = 2;
	c2 = 15;
	float log1 = log(c1);
	float log2 = log(c2);
	float result6 = ((log1)/(log2));
	cout << "Log base 2 of 15 is " << result6 <<endl;

	c1 = 4;
	c2 = 40;
	log1 = log(c1);
	log2 = log(c2);
	float result7 = ((log1)/(log2));
	cout << "Log base 4 of 40 is " << result7 <<endl;
        
	/* Let 3*exp(sin(x)) = f(x) **
 * 	** Let log2(x^2 + 1) = g(x) */
	c1 = 1;
	float equation1 = 3*exp(sin(c1));
	cout << "f(1) is " << equation1 << endl;
	c2 = 2;
	float equation2 = log((c1)^2+1)/log(c2);
	cout << "g(1) is " << equation2 << endl;

	c1 = 10;
	equation1 = 3*exp(sin(c1));
	cout << "f(10) is " << equation1 <<endl;
	equation2 = log((c1)^2+1)/log(c2);
	cout << "g(10) is " << equation2 <<endl;

	c1 = 100;	
	equation1 = 3*exp(sin(c1));
	cout << "f(100) is " << equation1 <<endl;
	equation2 = log((c1)^2+1)/log(c2);
	cout << "g(100) is " << equation2 <<endl;
}
