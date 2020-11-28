/****************************************************************************************************************************************************************************************** Program Filename: Homework Assignment 3
** Author: Andrew Victor
** Date: February 1st, 2018
** Description: Various User Made Mini Functions
****************************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/****************************************************************************************************************************************************************************************** Function: check_range 
** Description: Indicates if number is in provided range
** Parameters: int lower_bound, int upper_bound, int test_value
** Pre-Conditions: 3 valid integers
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/

bool check_range(int lower_bound, int upper_bound, int test_value) {
	if (lower_bound <= test_value && test_value <= upper_bound) {
		return true;
	}
	else {
		return false;
	}
}

/****************************************************************************************************************************************************************************************** Function: is_int
** Description: Determines if a given string is an integer
** Parameters: string num
** Pre-Conditions: Valid string
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool is_int(string num) {
	if ("48" < num && num < "57") {
		return true;
	}
	else {
		return false;
	}
}

/****************************************************************************************************************************************************************************************** Function: is_float
** Description: Determines if a given string is a float
** Parameters: string num
** Pre-Conditions: Valid string
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool is_float(string num) {
	for(int i=0; i<num.length(); i++) {
		if(num[i] == '.') {
			return true;
		}
	}
	return false;	
}
/****************************************************************************************************************************************************************************************** Function: is_capital
** Description: Determines if a given character is a capital letter
** Parameters: char letter
** Pre-Conditions: Valid character
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool is_capital(char letter) {
	if(64 < letter && letter < 89) {
		return true;
	}
	else {
		return false;
	}
}

/****************************************************************************************************************************************************************************************** Function: is_even
** Description: Determines if a given integer is even
** Parameters: int num
** Pre-Conditions: Valid integer
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool is_even(int num) {
	if(num %2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

/****************************************************************************************************************************************************************************************** Function: is_odd
** Description: Determines if a given integer is odd
** Parameters: int num
** Pre-Conditions: Valid integer
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool is_odd(int num) {
	if(num %2 != 0) {
		return true;
	}
	else {
		return false;
	}
}
/****************************************************************************************************************************************************************************************** Function: equality_test
** Description: Tests two numbers and compares their values
** Parameters: int num1, int num2
** Pre-Conditions: Two valid integers
** Post-Conditions: Integer
****************************************************************************************************************************************************************************************/
int equality_test(int a, int b) {
	if(a > b)
		return 1;
	if(a < b)
		return -1;
	if(a == b)
		return 0;
}
/****************************************************************************************************************************************************************************************** Function: float_is_equal
** Description: Tests to see if two numbers are within a certain percision
** Parameters: float num1, float num2, float precision
** Pre-Conditions: Three valid floats
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool float_is_equal(float num1, float num2, float precision) {
	if(abs(num2-num1) < precision){
		return false;
	}
	return true;
}
/****************************************************************************************************************************************************************************************** Function: numbers_present
** Description: Determines if a given string has numbers
** Parameters: string sentence
** Pre-Conditions: Valid string
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool numbers_present(string sentence) {
	for(int i=0; i<sentence.length(); i++) {
		if(48 <= sentence[i] && sentence[i] <= 57) {
			return true;
		}
	}
	return false;
}

/****************************************************************************************************************************************************************************************** Function: letters_present 
** Description: Determines if a given strings has letters
** Parameters: string sentence
** Pre-Conditions: Valid string
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool letters_present(string sentence) {
	for(int i=0; i<sentence.length(); i++) {
		if(65 <= sentence[i] && sentence[i] <= 122) {
			return true;
		}
	}
	return false;
}
/****************************************************************************************************************************************************************************************** Function: contains_sub_string
** Description: Determines if a sub string exists in a given sentence 
** Parameters: string sentence, string sub_string
** Pre-Conditions: Two valid strings
** Post-Conditions: Boolean
****************************************************************************************************************************************************************************************/
bool contains_sub_string(string sentence, string sub_string) {
bool check = false;
for(int i = 0; i < sentence.length(); i++){
	int n = 0;
	for(int j = 0; j < sub_string.length(); j++){
		if(sentence[i + n] == sub_string[j + n]){
		   check = true;
		   n++;
		   continue;
		}
		else{
		break;	}
		}
	}
return check;
}
/****************************************************************************************************************************************************************************************** Function: word_count
** Description: Provides the given number of words in a string
** Parameters: string sentence
** Pre-Conditions: Valid string
** Post-Conditions: Integer
****************************************************************************************************************************************************************************************/
int word_count(string sentence) {
	int words = 0;
	for(int i=0; i<sentence.length(); i++) {
		if(sentence[i] == 32) {
			words++;
		}
		else if(sentence[i] == 46) {
			words++;
		}
	}
	return words;
}
/****************************************************************************************************************************************************************************************** Function: to_upper
** Description: Capitalizes all given letters in a string and leaves all non letters unchanged
** Parameters: string sentence
** Pre-Conditions: Valid string
** Post-Conditions: String
****************************************************************************************************************************************************************************************/
string to_upper(string sentence) {
	for(int i=0; i<sentence.length(); i++) {
		if(97 <= sentence[i] && sentence[i] <= 122) {
			int upper = sentence[i] - 32;
			sentence[i] = upper;
		}
	}
	return sentence;
}
/****************************************************************************************************************************************************************************************** Function: to_lower 
** Description: Changes all letters in a string to lowercase and leaves all non letters unchanged
** Parameters: string sentence
** Pre-Conditions: Valid string
** Post-Conditions: String
****************************************************************************************************************************************************************************************/
string to_lower(string sentence) {
	for(int i=0; i<sentence.length(); i++) {
		if(65 <= sentence[i] && sentence[i] <= 90) {
			int lower = sentence[i] +32;
			sentence[i] = lower;
		}
	}
	return sentence;
}
/****************************************************************************************************************************************************************************************** Function: get_int
** Description: Takes a string in from the user, checks to see if it is a valid integer, then returns the integer
** Parameters: string prompt
** Pre-Conditions: Valid string
** Post-Conditions: Integer
****************************************************************************************************************************************************************************************/
bool check_int(string prompt) {
	bool check = true;
	for(int i=0; i<prompt.length(); i++) {
		if(48 <= prompt[i] && prompt[i] <= 57) {
			check = true;
		}
		else if(prompt[i] == 45) {
			check = true;
		}
		else if(0 <= prompt[i] && prompt[i] <= 127) {
			return false;
		}
	}
	return check;
}
string get_int() {
	string prompt = "";
	do {
		cout << "Please provide an integer: " << endl;
		getline(cin, prompt);
	} while(check_int(prompt) == false);
	return prompt;
}
/****************************************************************************************************************************************************************************************** Function: get_float
** Description: Takes a string in from the user, checks to see if it is a valid float, then returns the provided float
** Parameters: string prompt
** Pre-Conditions: Valid string
** Post-Conditions: Float
****************************************************************************************************************************************************************************************/
bool check_float(string prompt) {
	bool check = true;
	for(int i=0; i<prompt.length(); i++) {
		if(prompt[i] == 46) {
			check = true;
		}
		else if(48 <= prompt[i] && prompt[i] <= 57) {
			check = true;
		}
		else if(prompt[i] == 45) {
			check = true;
		}
		else if(0 <= prompt[i] && prompt[i] <= 127) {
			return false;
		}
	}
	return check;
}
string get_float() {
	string prompt = "";
	do {
		cout << "Please provide a float: " << endl;
		getline(cin, prompt);
	} while(check_float(prompt) == false);
	return prompt;
}

int main() {

	//Testing for check_range
	cout << "Testing check_range" << endl;
	cout << "Input: lower_bound = 3, upper_bound = 10, test_value = 5. Expected Output: true. Actual Output: " << endl;
	
	if(check_range(3, 10, 5) == true) { 
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	
	cout << "Input: lower_bound = 1, upper_bound = 100, test value = -5. Expected Output: false. Actual Output: " << endl;
	
	if(check_range(1, 100, -5) == true) { 
		cout << "True, FAIL" << endl;
	}
	else{
		cout << "False, PASS" << endl;
	}

	//Testing for is_int
	cout << "Testing is_int" << endl;
	cout << "Input: 55. Expected Output: true. Actual Output: " << endl;
	
	if(is_int("55") == true) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}

	cout << "Input: 69. Expected Output: false. Actual Output: " << endl;

	if(is_int("69") == true) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}

	//Testing for is_float
	cout << "Testing is_float" << endl;
	cout << "Input: 5.05. Expected Output: true. Actual Output: " << endl;
	
	if(is_float("5.05") == true) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	
	cout << "Input: Hello. Expected Output: false. Actual Output: " << endl;
	if(is_float("Hello") == true) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}

	//Testing for is_capital
	cout << "Testing is_capital" << endl;
	cout << "Input 'R'. Expected Output: true. Actual Output: " << endl;

	if(is_capital('R')) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	
	cout << "Input '6'. Expected Output: false. Actual Output: " << endl;
	if(is_capital('6')) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}

	//Testing for is_even
	cout << "Testing is_even" << endl;
	cout << "Input: 1024. Expected Output: true. Actual Output: " << endl;
	if(is_even(1024)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	
	cout << "Input: 111. Expected Output: false. Actual Output: " << endl;
	if(is_even(111)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}

	//Testing for is_odd
	cout << "Testing is_odd" << endl;
	cout << "Input: 99. Expected Output: true. Actual Output: " << endl;
	if(is_odd(99)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}

	cout << "Input: 50. Expected Output: false. Actual Output: " << endl;
	if(is_odd(50)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}

	//Testing for equality_test
	cout << "Testing equality_test" << endl;
	cout << "Input: a=1, b=5. Expected Output: -1. Actual Output:\n "; 
	cout << equality_test(1,5) << endl;
	cout << "Input: a=3, b=3. Expected Output: 0. Actual Output:\n ";
	cout << equality_test(3,3) << endl;
	cout << "Input: a=10, b=-5. Expected Output: 1. Actual Output:\n ";
	cout << equality_test(10,-5) << endl;

	//Testing for float_is_equal
	cout << "Testing float_is_equal" << endl;
	cout << "Input: num1=1, num2=1.001, precision=0.00001. Expected Output: true. Actual Output: " << endl;
	if(float_is_equal(1,1.001,0.00001)) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	
	cout << "Input: num1=4, num2=4.05, precision=0.1. Expected Output: false. Actual Output: " << endl;
	if(float_is_equal(4,4.05,0.1)) {
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}
	
	//Testing for numbers_present
	cout << "Testing numbers_present" << endl;
	cout << "Input: 1340897134. Expected Output: true. Actual Output: " << endl;
	if(numbers_present("1340897134")) {
		cout << "True, PASS" << endl;
		}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << "Input: HelloWorld. Expected Output: false. Actual Output: " << endl;
	if(numbers_present("HelloWorld")){
		cout << "True, FAIL" << endl;
	}
	else {
		cout << "False, PASS" << endl;
	}

	//Testing for letters_present
	cout << "Testing letters_present" << endl;
	cout << "Input: HelloWorld. Expected Output: true. Actual Output: " << endl;
	if(letters_present("HelloWorld")) {
		cout << "True, PASS" << endl;
		}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << "Input: 34. Expected Output: false. Actual Output: " << endl;
	if(letters_present("34")) {
		cout << "True, FAIL" << endl;
		}
	else {
		cout << "False, PASS" << endl;
	}
	
	//Testing contains_sub_string
	cout << "Testing contains_sub_string" << endl;
	cout << "Input: Racecar, car. Expected Output: true. Actual Output: " << endl;
	if(contains_sub_string("Racecar", "car")) {
		cout << "True, PASS" << endl;
	}
	else {
		cout << "False, FAIL" << endl;
	}
	cout << "Input: This is taking forever, I am so bored. Expected Output: false. Actual Output: " << endl;
	if(contains_sub_string("This is taking forever", "I am so bored")) {
		cout << "True, FAIL" << endl;
		}
	else {
		cout << "False, PASS" << endl;
	}

	//Testing word_count
	cout << "Testing word_count" << endl;
	cout << "Input: This assignment is very long. Expected Output: 5. Actual Output:\n";
	cout << word_count("This assignment is very long.") << endl;
	
	//Testing to_upper
	cout << "Testing to_upper" << endl; 
	cout << "Input: Does this work. Expected Output: DOES THIS WORK. Actual Output:\n";
	cout << to_upper("Does this work") << endl;
	cout << "Input: 592cmz. Expected Output: 592CMZ. Actual Output:\n";
	cout << to_upper("592cmz") << endl;

	//Testing to_lower
	cout << "Testing to_lower" << endl;
	cout << "Input: SUPER BOWL SUNDAY. Expected Output: super bowl sunday. Actual Output:\n";
	cout << to_lower("SUPER BOWL SUNDAY") << endl;
	cout << "Input: 443CVD. Expected Output: 443cvd. Actual Output:\n";
	cout << to_lower("443CVD") << endl;

	//Testing get_int
	cout << "Testing get_int" << endl;
	get_int();
	
	//Testing get_float
	cout << "Testing get_float" << endl;
	get_float();

return 0;
}

