/****************************************************************************************************************************************************************************************
** Program Filename: Homework Assignment 4
** Author: Andrew Victor
** Date: February 7th, 2018
** Description: Stndard Calculator, Binary Converter, and Grade Calculator
****************************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/****************************************************************************************************************************************************************************************
** Function: valid_equation
** Description: This function will determine if the equation to be entered into the standard calculator is valid
** Parameters: bool, string
** Pre-Conditions: Valid equation containing floats, operators, negative signs, and spaces. Function must be entered as follows: x + x / x
****************************************************************************************************************************************************************************************/
bool valid_equation(string equation){
	bool check = true;
	for(int i=0; i<equation.length(); i++){
		if(48 <= equation[i] && equation[i] <= 57)
			return true;
		else if(equation[i] == 45)
			return true;
		else if(equation[i] == 46)
			return true;
		else if(equation[i] == 32)
			return true;
		else
			return false;
	}
	return check;
}
/****************************************************************************************************************************************************************************************
** Function: get_equation
** Description: This function will make sure the user enters a valid equation to be calculated with the standard calculator
** Parameters: string
****************************************************************************************************************************************************************************************/
string get_equation() {
	string equation = "";
	do{
		cout << "Please enter a string to be calculated in the form of: 3 + -2 - 5 * 4" << endl;
		getline(cin, equation);
	}
	while(valid_equation(equation) == false);
	return equation;
}
/****************************************************************************************************************************************************************************************
** Function: get_values
** Description: This function will calculate the values of each string entered by the user
** Parameters: string, float
** Pre-Conditions: Valid string entered by the user
****************************************************************************************************************************************************************************************/
/*float get_values(string equation) {
	float var1, var2 = 0;
	int length = equation.length();
	for(int i=0; i<length; i++){
		if(equation[i] == 32)
			var1 = atoi(equation[i-1]);
			var2 = atoi(equation
			*/
/****************************************************************************************************************************************************************************************
** Function: calculator
** Description: This function will calculate the values given in the string
** Parameters: float, string
** Pre-Conditions: Valid string
****************************************************************************************************************************************************************************************/
float calculator() {
	int op = 0; 
	float result, var1, var2 = 0;
	switch(op) {
		case 1 : op = '+';
		result = var1 + var2; break;
		case 2 : op = '-';
		result = var1 - var2; break;
		case 3 : op = '*';
		result = var1 * var2; break;
		case 4 : op = '/';
		result = var1 / var2; break;
		default :
		break; 
	return result;
	}
}
/****************************************************************************************************************************************************************************************
** Function: check_binary
** Description: This function will determine if the string is a valid binary number
** Parameters: bool, string
** Pre-Conditions: 8-Bit Unsigned Binary Number
****************************************************************************************************************************************************************************************/
bool check_binary(string binary){
	for(int i=0; i<binary.length(); i++){
		if((binary[i] != '0') && (binary[i] != '1'))
			return false;
	}
	return true;
}
/****************************************************************************************************************************************************************************************
** Function: get_binary
** Description: This function will run until the user has entered valid input for the binary to decimal converter
** Parameters: string, string
****************************************************************************************************************************************************************************************/
string get_binary(){
	string binary = " ";
	do{
		cout << "Please enter an unsigned binary number" << endl;
		getline(cin, binary);
	}
	while(check_binary(binary) == false);
	return binary;
}
/****************************************************************************************************************************************************************************************
** Function: binary2decimal
** Description: This function will take the binary string and convert it into a decimal
** Parameters: string, int
** Pre-Conditions: Input is a valid, 8-bit, unsigned binary number
** Credit to Shannon Ernst for this function **
****************************************************************************************************************************************************************************************/
int binary2decimal(string binary) {
	int length = binary.length();
	int result = 0;
	for(int i=0; i<length; i++) {
		if(binary[i] == '1') {
			result += pow(2, (length-i-1));
		}
	}
	return result;
}
/****************************************************************************************************************************************************************************************
** Function: binary_runner
** Description: This function will run the binary2decimal function
** Parameters: void
****************************************************************************************************************************************************************************************/
int binary_runner() {
	int x = 0;
	do{
	string binary = "";
	binary = get_binary();
	int result = binary2decimal(binary);
	cout << result << endl;
	cout << "To convert another number, enter 1, to exit the program, enter any other key." << endl;
	cin >> x; cin.ignore(); cin.clear();
	}
	while(x==1);
}
/****************************************************************************************************************************************************************************************
** Function: bool check_int
** Description: This function will determine if the integer that will be converted into binary is valid
** Parameters: void, int
** Pre-Conditions: The input must be a positive integer 
****************************************************************************************************************************************************************************************/
void check_int(int &decimal) {
	while(decimal < 0) {
		cout << "Please enter a valid integer" << endl;
		cin >> decimal;
	}
	return;
}
/****************************************************************************************************************************************************************************************
** Function: decimal2binary
** Description: This function takes in an integer and returns its binary form
** Parameters: int, string
** Pre-Conditions: Valid integer
****************************************************************************************************************************************************************************************/
string decimal2binary(int decimal){
	check_int(decimal);	
	if(decimal < 0.000001)
		return "0";
	else if(decimal == 1)
		return "1";
	else {
		if(decimal % 2 == 1)
			return decimal2binary(decimal / 2) + "1";
		else
			return decimal2binary(decimal / 2) + "0";
	}
}
/****************************************************************************************************************************************************************************************
** Function: decimal_runner
** Description: This function will run the decimal2binary function
** Parameters: string
****************************************************************************************************************************************************************************************/
string decimal_runner() {
	int x = 0;
	do{
	int decimal = -2;
	string result = decimal2binary(decimal);
	cout << result << endl;
	cout << "To convert another decimal into its binary form, enter 1, to exit the program, enter any other key." << endl;
	cin >> x; cin.ignore(); cin.clear();
	}
	while(x==1);
}
/****************************************************************************************************************************************************************************************
** Function: average_grade
** Description: This function will calculate the average grade for each grade a user inputs
** Parameters: float
** Pre-Conditions: The grade being input is a valid float
****************************************************************************************************************************************************************************************/
float average_grade() {
	int counter = 0;
	float grade, total = 0;
	while(grade != -1) {
		cout << "Please enter a the grades that you wish to have calculated\n" << "when you wish to find out the completed average, enter -1" << endl;
		cin >> grade;
		if(grade >= 0) {
			total += grade;
			counter++;
		}
	}
	cout << total/counter << endl;
}
/****************************************************************************************************************************************************************************************
** Function: grade_runner
** Description: This function will run the average_grade function
** Parameters: float, float
****************************************************************************************************************************************************************************************/
float grade_runner() {
	int x = 0;
	do{
	float result = average_grade();
	cout << result << endl;
	cout << "To calculate another average grade, enter 1, to exit the program, enter any other key" << endl;
	}
	while(x==1);
}
/****************************************************************************************************************************************************************************************
** Function: grade_weight
** Description: This function will take in user grades and weights and return the weighted average
** Parameters: float
** Pre-Conditions: SUM OF GRADE WEIGHT MUST EQUAL 1!
****************************************************************************************************************************************************************************************/
float grade_weight() {
	float grade = 0, total = 0, weight = 0, counter = 0;
	while(grade != -1) {
		cout << "Please enter the grade you wish to be calculated\n" << "if you wish to find your weighted average and your weight EQUALS 1.0, enter -1"  << endl;
		cin >> grade;
		if(grade >= 0) {
		cout << "Please enter the weight of the grade in decimal (0.x) form" << endl;
		cin >> weight;
		counter+= weight;
		cout << "Weight: " << counter << endl;
			total += grade*weight;
		}
	}
	cout << total << endl;
}
/****************************************************************************************************************************************************************************************
** Function: weight_runner
** Description: This function will run the grade_weight function
** Parameters: float, float
****************************************************************************************************************************************************************************************/
float weight_runner(){
	int x = 0;
	do{
	float result = grade_weight();
	cout << result << endl;
	cout << "To calculate another weighted grade, enter 1, to exit the program, enter any other key." << endl;
	cin >> x; cin.ignore(); cin.clear();
	}
	while(x==1);
}
/****************************************************************************************************************************************************************************************
** Function: menu
** Description: This function will serve as the menu function and call all of the different calculators
** Parameters: int
****************************************************************************************************************************************************************************************/
int menu() {
	cout << "Welcome to the calculator program\n" << "To use the binary to decimal calculator, enter 2\n" << "To use the decimal to binary calculator, enter 3\n" << "To use the average grade calculator, enter 4\n" << "To use the weighted grade calculator, enter 5\n" << endl;
	int answer, result = 0;
	cin >> answer; cin.ignore(); cin.clear();
	if(answer == 2){
		binary_runner();	
	}
	else if(answer == 3) {
		int x = 0; do { int decimal = -2; string result = decimal2binary(decimal); cout << result << endl; cout << "To convert another number into its binary form, enter 1, to exit the program, enter any other key" << endl; cin >> x; cin.ignore(); cin.clear(); } while(x==1); 
	}
	else if(answer == 4) {
		int x = 0; do{ float result = average_grade(); cout << result << endl; cout << "To calculate another average grade, enter 1, to exit the program, enter any other key" << endl; } while(x==1);
	}
	else if(answer == 5) {
		weight_runner();
	}
}
int main(){
	menu();
	return 0;
}
