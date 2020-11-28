/*******************************************************************************************************************************************************************************************
** Program Filename: CS 161 Homework 2
** Author: Andrew Victor
** Date: January 19th, 2018
** Description: Text Adventure
********************************************************************************************************************************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100;

int main () {
	int x1, x2, x3, x4, x5, x6, x7;
	cout << "Welcome to the text adventure!" << endl;
	cout << "You have entered a forest and can't decide which way to go." << endl;
	
	srand(time(NULL));
	x1 = rand() %2;
	cout << "You have decided to go "; 

	if (x1==0) {
	cout << "right" << endl;
	cout << "You go right and see a cabin. To go inside the cabin, enter 1, to keep walking, enter 2." << endl;
	
	cin >> x2;
		if (x2==1) {
		cout << "You enter the cabin and see a box. To open the box, enter 1, to keep looking around, enter 2." << endl;
		
		cin >> x3;
			if (x3==1) {
			cout << "You open the box and find a phone. To call your mom, enter 1, to call the police, enter 2" << endl; 
			cin >> x4;
				if (x4==1) {
				cout << "Your mom comes and picks you up. Your adventure is over" << endl;
				}
				else if (x4==2) { 
				cout << "The police come and give you a ticket for calling them for no reason. Your adventure is over" << endl;
				} 
			}
			else if(x3==2) {
			cout << "You go upstairs and find a man in one of the rooms. To fight, enter 1, to flee, enter 2." << endl;
			cin >> x5;
				if (x5==1) {
				cout << "You try fighting but are defeated. Your adventure is over." << endl;
				}
				else if(x5==2) {
				cout << "You try to flee but are caught and defeated by the man. Your adventure is over." << endl;
				}
			}
		}
		else if (x2==2) {
		cout << "You come across a sasquatch. To fight him, enter 1, to run and look for shelter, enter 2. " << endl;
		cin >> x6; 
			if (x6==1) {
			cout << "Sasquatch kills you. Your adventure is over." << endl;
			}
			else if (x6==2) {
			cout << "Sasquatch chases you down and kills you. Your adventure is over." << endl;
			}
		}
	}
	else if (x1==1) {
	cout << "left" << endl;
	cout << "You go left and see a lake. To try swimming in the lake, enter 1, to continue exploring, enter 2." << endl;
	cin >> x7;
		if (x7==1) {
		cout << "You try to swim in the lake and drown. Your adventure is over." << endl;
		}
		else if (x7==2) {
		cout << "You get lost in the forest and die of dehydration. Your adventure is over" << endl;
		}
	}  
	
	else {}

return 0;
}
