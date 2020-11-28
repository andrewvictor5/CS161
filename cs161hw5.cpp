/****************************************************************************************************************************************************************************************
** Program Filename: Homework Assignment 5
** Author: Andrew Victor
** Date: March 1st, 2018
** Description: Farkle
****************************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;



bool isFarkle(int*, int&);
int max_score(int*, int&);

/****************************************************************************************************************************************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************************************************************************************************************/

/****************************************************************************************************************************************************************************************
** Function: check_users
** Description: This function will check to see if the number of players input by the user for the game is valid
** Parameters: bool, string
****************************************************************************************************************************************************************************************/
/*bool check_users(string input){
	bool check = false;
	for(int i=0; i<input.length(); i++){
		if(input[i] >= '2')
			check = true;
		else if(input[i] >= 10)
			check = true;
		else if(0 <= input[i] && input[i] <= 47)
			return false;
		else if(58 <= input[i] && input[i] <= 127)
			return false;
	}
	
	return check;
}*/
/****************************************************************************************************************************************************************************************
** Function: get_players
** Description: This function will allow the user to select however many players they would like to have play in the game
** Parameters: string
** Pre-Conditions: Valid number of players selected by the user
****************************************************************************************************************************************************************************************/
string get_users(int &players) {
	string input;
	do{
		cout << "Welcome to Farkle!\nPlease enter the number of players you wish to have play in this game" << endl;
		getline(cin, input);
		stringstream convert(input);
		if(!(convert >> players))
			players = 0;
	}
	while(players < 2);
	cout << "Number of players in this game: " << players << endl;
	return input;
}
/****************************************************************************************************************************************************************************************
** Function: scoreboard
** Description: This function will generate a scoreboard for however many players are in the game
** Parameters: string
** Pre-Conditions: Valid number of players selected by the user
** Post-Conditions: Array that is the size of the number of players in the game
****************************************************************************************************************************************************************************************/
int *scoreboard(int players){
	int *scores = new int[players];
	for(int i=0; i<players; i++){
		scores[i] = 0;
	}
	cout << "Scores: " << endl;
	for(int i=0; i<players; i++){
		cout << scores[i] << endl;
	}
	return scores;
}
/****************************************************************************************************************************************************************************************
** Function: roll_dice
** Description: This function will simulate a dice roll
** Parameters: int
****************************************************************************************************************************************************************************************/
void roll_dice(int *dice, int count) {
	for(int i=0; i<count; i++){
		dice[i] = rand() %6 + 1;
	}
	for(int i=0; i<count; i++){
		cout << "Dice " << i+1 << ": " << dice[i] << endl;
	}
	return;
}
/****************************************************************************************************************************************************************************************
** Function: singles
** Description: This function will check to see if the user rolled any 1's
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
int singles(int *dice, int &count) {

	for(int i=0; i<count; i++){
		if(dice[i] == 1){
			count--;
			return 2;
		}
		else if(dice[i] == 5){
			count--;
			return 1;
		}
	}

	return 0;
}
/****************************************************************************************************************************************************************************************
** Function: triples
** Description: This function will check to see if the user rolled triples
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
int triples(int *dice, int &count){
	int numbers[count];
	
	for(int j=0; j<count; j++) {
		numbers[j] = 0;
	}

	for(int i=0; i<count; i++) {
		numbers[dice[i]]++;
		if(numbers[dice[i]] > 2)
			return i;
	}

	return 0;
}
/****************************************************************************************************************************************************************************************
** Function: fours
** Description: This function will check to see if the user rolled four of a kind
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
bool fours(int *dice, int &count){
	int numbers[count];

	for(int j=0; j<count; j++) {
		numbers[j] = 0;
	}

	for(int i=0; i<count; i++) {
		numbers[dice[i]]++;
		if(numbers[dice[i]] > 3)
			return true;
	}

	return false;
}
/****************************************************************************************************************************************************************************************
** Function: fives
** Description: This function will check to see if the user rolled a five of a kind
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
bool fives(int *dice, int &count){
	int numbers[count];

	for(int j=0; j<count; j++) {
		numbers[j] = 0;
	}

	for(int i=0; i<count; i++) {
		numbers[dice[i]]++;
		if(numbers[dice[i]] > 4)
			return true;
	}

	return false;
}
/****************************************************************************************************************************************************************************************
** Function: sixes
** Description: This function will check to see if the user rolled a six of a kind
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
bool sixes(int *dice, int &count){
	for(int i=0; i<5; i++){
		if(dice[i] != dice[i+1])
			return false;
	}
	count -= 6;

	return true;
}
/****************************************************************************************************************************************************************************************
** Function: is_straight
** Description: This function will check to see if the user rolled a straight
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
bool is_straight(int *dice, int &count){
	int numbers[count];
	for(int j=0; j<count; j++) {
		numbers[j] = 0;
	}

	for(int i=0; i<count; i++) {
		numbers[dice[i]]++;
		if(numbers[dice[i]] > 1)
			return false;
	}

	return true;
}
/****************************************************************************************************************************************************************************************
** Function: three_pairs
** Description: This function will check to see if the user rolled three pairs
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
bool three_pairs(int *dice, int &count){
	int numbers[count];
	int pairCount = 0;

	for(int j=0; j<count; j++) {
		numbers[j] = 0;
	}

	for(int i=0; i<count; i++) {
		numbers[dice[i]]++;
		if(numbers[i] == 2)
			pairCount++;
	}

	if(pairCount > 2)
		return true;

	return false;
}
/****************************************************************************************************************************************************************************************
** Function: two_triples
** Description: This function will check to see if the user rolled two triples
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
bool two_triples(int *dice, int &count){
	int numbers[count];
	int tripCount = 0;

	for(int j=0; j<count; j++) {
		numbers[j] = 0;
	}

	for(int i=0; i<count; i++) {
		numbers[dice[i]]++;
		if(numbers[i] == 3)
			tripCount++;
	}

	if(tripCount > 1)
		return true;

	return false;
}
/****************************************************************************************************************************************************************************************
** Function: fours_pair
** Description: This function will check to see if the user rolled a four of a kind and a pair
** Parameters: bool, int
****************************************************************************************************************************************************************************************/
bool fours_pair(int *dice, int &count){
	int numbers[count];
	bool four = 0, pair = 0;

	for(int j=0; j<count; j++) {
		numbers[j] = 0;
	}

	for(int i=0; i<count; i++) {
		numbers[dice[i]]++;
		if(numbers[i] == 2)
			pair = 1;
		if(numbers[i] == 4)
			four = 1;
	}

	if(pair && four)
		return true;

	return false;
}
/****************************************************************************************************************************************************************************************
** Function: is_score
** Description: This funtion will check to see if the user picked a valid score or if they received a Farkle
** Parameters: int
****************************************************************************************************************************************************************************************/
/*
int is_score(int *scores, int *dice, int &count){
	roll_dice(dice, count);
	int max_score;
	cout << "How many dice would you like to keep? " << endl;
	int num_dice = 0;
	cin >> num_dice;
	for(int i=0; i<num_dice; i++){
		cout << "Enter the number of the dice that you wish to keep" << endl;
		int dice_num = 0;
		cin >> dice_num;
		cout << dice_num[dice-1] << endl;
		for(int i=0; i<num_dice; i++){
			scores = max_score(dice_num, count);	
		}
		cout << scores << endl;
	}
}*/

int is_score(int *scores, int *dice, int &count) {
	roll_dice(dice, count);

	
	int num_dice = 0;
	

	while(isFarkle(dice, count) != false ) {
		cout << "Enter which number of dice you would like to get rid of" << endl;
		int dice_num = 0;
		cin >> dice_num;
		
		//int diceToKeep[dice_num];
		for (int i = 0; i < dice_num; i++) {
			cout << "Enter which dice you want to get rid of" << endl;
			int dicePos;
			cin >> dicePos;
			dice[dicePos-1] = 0;
			//dice[dicePos-1] = 0;
			//cout << dice_num[dice-1] << endl;
			
		}
		
	//	for (int i = 0; i < count; i++) {
			// if this isn't the dice to keep, set to 0
	//		for (int j = 0; j < dice_num; j++) {
	//			if ( i = diceToKeep[j])
	//				dice[i] = 0;
	//			
	//		}
			
		//}
		count = count - num_dice;	
		scores[0] += max_score(dice, count);
		
		// keep count of die left after removing some
		// check scoring make sure it works
		// figure out the rest of the game logic
		cout << scores[0] << endl;
		roll_dice(dice, count);
	}
	
}

/****************************************************************************************************************************************************************************************
** Function: max_score
** Description: This function will determine the score for the dice put away by the user
** Parameters: int
****************************************************************************************************************************************************************************************/
int max_score(int *dice, int &count){
	if(sixes(dice,count) == true)
		return 3000;
	else if(two_triples(dice,count) == true)
		return 2500;
	else if(fives(dice,count) == true)
		return 2000;
	else if(fours_pair(dice,count) == true)
		return 1500;
	else if(is_straight(dice,count) == true)
		return 1500;
	else if(three_pairs(dice,count) == true)
		return 1500;
	else if(fours(dice,count) == true)
		return 1000;
	else if(triples(dice,count) > 0)
		return 100 * triples(dice,count);
	else if(singles(dice,count) > 0)
		return 50 * singles(dice,count);
	else{
		return 0;
		cout << "Farkle" << endl;
	}
}

/****************************************************************************************************************************************************************************************
** Function: max_score
** Description: This function will determine the score for the dice put away by the user
** Parameters: int
****************************************************************************************************************************************************************************************/
bool isFarkle(int *dice, int &count){
	bool check;
	if(sixes(dice,count) == true)
		check = true;
	else if(two_triples(dice,count) == true)
		check = true;
	else if(fives(dice,count) == true)
		check = true;
	else if(fours_pair(dice,count) == true)
		check = true;
	else if(is_straight(dice,count) == true)
		check = true;
	else if(three_pairs(dice,count) == true)
		check = true;
	else if(fours(dice,count) == true)
		check = true;
	else if(triples(dice,count) > 0)
		check = true;
	else if(singles(dice,count) > 0)
		check = true;
	else{
		cout << "Farkle!" << endl;
		return false;
	}
	return check;
}
/****************************************************************************************************************************************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************************************************************************************************************/

int main(){
	srand(time(NULL));
	int players;
	get_users(players);
	int *scores = scoreboard(players);
	int count = 6;
	int *dice = new int;
	//roll_dice(dice, count);
	is_score(scores, dice, count);
	delete scores; 
	delete dice;
	return 0;
}






