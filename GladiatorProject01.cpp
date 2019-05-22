// Name: Phoenix L. Franco
// 
// Date: 4/02/2019
// 
// Project: Gladiator

#include "pch.h" 
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using namespace std;

// user home menu
void MainMenu();
// option one, create character
void CharacterCreate();
// checks to see if desired character (entered by user exists)
bool CheckCharacterExist(fstream& rosterFile, string CharacterName);
// option 2, menu for duel
void DuelMenu();
// Function to handle player one vs. player two
void PlayerSelect(string player, string& PlayerName, string& PlayerTitle, int& health, int& strength, int& defense, int& luck, string& faction, string& specialItem);
// Function for player one and player two to duel
void Player1VsPlayer2(string Player1Name, string Player1Title, int Player1Health, int Player1Strength, int Player1Defense, int Player1Luck, string Player1Faction, string Player1SpecialItem, string Player2Name, string Player2Title, int Player2Health, int Player2Strength, int Player2Defense, int Player2Luck, string Player2Faction, string Player2SpecialItem);
// function for when the player wants to attack 
int Attack(int PlayerStrength, int PlayerDefense);

//*****************************
//End of Preprocessor stuffs
//Let the games begin
//*****************************


int main()
{

	MainMenu();

}
// user home menu
void MainMenu() {

	//this is used to make sure that any random variables we are using will come
	//out random/different each time the program is initiated
	srand(time(NULL));

	//Reset choice variable
	int choice = 0;

	//To validate input and detect 'Quit Game' selection
	while (choice != 3) {


		system("CLS");

		//main menu and selection
		cout << "   ULTIMATE GLADIATOR ARENA!  " << endl;
		cout << "------------------------------" << endl;
		cout << "-- Select an option to begin--" << endl;
		cout << "------------------------------" << endl;
		cout << "1) Gladiator Creation         " << endl;
		cout << "2) DUEL TO THE DEATH!!        " << endl;
		cout << "3) Quit Game                  " << endl;
		cin >> choice;

		if (choice == 1) {

			system("CLS");
			CharacterCreate();
		}
		else if (choice == 2) {

			DuelMenu();

		}
		else if (choice == 3) {

			cout << "Good-Bye" << endl;
			break;
		}
		else {

			choice = 0;
			system("CLS");
			cout << "Choice is invalid, please try again" << endl;
			system("PAUSE");

		}
	}
}
// option one, create character
void CharacterCreate() {

	string name;
	string title;
	int health = 100;
	int strength;
	int defense;
	int luck;
	string faction;
	string specialItem;

	int attributePoints;
	int attributePointsReserve;

	//reestablish attribute points
	attributePoints = 180;


	//intialize attributes
	//player one name
	cout << "Name: ";
	cin >> name;

	//Don't know why but getline works when you use this
	cin.ignore();
	//player one title
	cout << "Title: ";
	getline(cin, title);


	//player one health
	cout << "Health: 100 \n\n";

	// In case the user goes over their attribute point limit this will
	// take attribute points back to its original value so that the 
	// rest of the slots aren't negative (resulting in a value of "1"
	// for the remaining slots).
	attributePointsReserve = attributePoints;

	//available attribute points displayed on top, keeps a running total
	cout << "Available attribute points: " << attributePoints << endl;
	//player one strength
	cout << "Strength: ";
	cin >> strength;

	//subtracting the points used for strength from total
	attributePoints -= strength;

	//testing values, if less than "0" value of "1" assigned to strength
	if (attributePoints < 0) {

		strength = 1;

		system("CLS");

		//regurgitate what the program should look like before
		//the incident.
		cout << "Creating Player One" << endl;
		cout << "-------------------" << endl;
		cout << "Name: " << name << endl;
		cout << "Title: " << title << endl;
		cout << "Health: 100 \n\n";
		cout << "Strength: " << strength << endl;

		//reassign value to keep attribute points out of the negative
		attributePoints = attributePointsReserve;

		//keeping the universe in balance
		attributePointsReserve = attributePoints;
	}


	attributePointsReserve = attributePoints;

	//available attribute points displayed on top, keeps a running total
	cout << "Available attribute points: " << attributePoints << endl;
	//player one defense
	cout << "Defense: ";
	cin >> defense;

	//subtracting the points used for defense from total
	attributePoints -= defense;

	//testing values, if less than "0" value of "1" assigned to defense
	if (attributePoints < 0) {

		defense = 1;

		system("CLS");

		cout << "Creating Player One" << endl;
		cout << "-------------------" << endl;
		cout << "Name: " << name << endl;
		cout << "Title: " << title << endl;
		cout << "Health: 100 \n\n";
		cout << "Strength: " << strength << endl;
		cout << "Defense: " << defense << endl;

		//reassign value to keep attribute points out of the negative
		attributePoints = attributePointsReserve;

		//keeping the universe in balance
		attributePointsReserve = attributePoints;
	}

	//available attribute points displayed on top, keeps a running total
	cout << "Available attribute points: " << attributePoints << endl;
	//player one's luck
	cout << "Luck: ";
	cin >> luck;

	//subtracting the points used for defense from total
	attributePoints -= luck;

	//testing values, if less than "0" value of "1" assigned to defense
	if (attributePoints < 0) {

		luck = 1;

		system("CLS");

		cout << "Creating Player One" << endl;
		cout << "-------------------" << endl;
		cout << "Name: " << name << endl;
		cout << "Title: " << title << endl;
		cout << "Health: 100 \n\n";
		cout << "Strength: " << strength << endl;
		cout << "Defense: " << defense << endl;
		cout << "Luck: " << luck << endl;

		//reassign value to keep attribute points out of the negative
		attributePoints = attributePointsReserve;

		//keeping the universe in balance
		attributePointsReserve = attributePoints;
	}

	if (strength > defense && strength > luck) {

		faction = "Wolves";
		specialItem = "Sword";

	}
	else if (defense > strength && defense > luck) {

		faction = "Ape";
		specialItem = "Armor";

	}
	else if (luck > strength && luck > defense) {

		faction = "Cat";
		specialItem = "Coincidence";

	}
	else {






		//in case the attributes just happen to all be equivalent
		//I'm using this
		short int decider = (rand() % 3) + 1;

		if (strength == defense && defense == luck && strength == luck) {

			if (decider == 1) {

				faction = "Wolves";
				specialItem = "Sword";

			}
			else if (decider == 2) {

				faction = "Ape";
				specialItem = "Armor";

			}
			else {

				faction = "Cat";
				specialItem = "Coincidence";

			}


		}
		else if (strength == defense) {

			if (decider == 1) {

				faction = "Wolves";
				specialItem = "Sword";

			}
			else if (decider == 2) {

				faction = "Ape";
				specialItem = "Armor";

			}
			else {}


		}
		else if (defense == luck) {

			if (decider == 1) {

				faction = "Cat";
				specialItem = "Coincidence";

			}
			else if (decider == 2) {

				faction = "Ape";
				specialItem = "Armor";

			}
			else {



			}

		}
		else if (strength == luck) {


			if (decider == 1) {

				faction = "Wolves";
				specialItem = "Sword";

			}
			else if (decider == 2) {

				faction = "Cat";
				specialItem = "Coincidence";

			}
			else {



			}


		}
		else {

		}
	}


	//clear screen
	system("CLS");



	//Save character to a file

	ofstream character;

	character.open("Characters\\" + name + ".txt");

	character << name << endl;
	character << title << endl;
	character << health << endl;
	character << strength << endl;
	character << defense << endl;
	character << luck << endl;
	character << faction << endl;
	character << specialItem << endl;

	character.close();

	//Add Character to roster
	ofstream roster;

	roster.open("Characters\\Roster.txt", ofstream::app);
	//saving into file format
	roster << name << endl;
	roster << "-------------" << endl;
	roster.close();


	//display stats to user
	cout << "Player One Stats" << endl;
	cout << "----------------" << endl;
	cout << "Name        : " << name << endl;
	cout << "Title       : " << title << endl;
	cout << "Health      : " << health << endl;
	cout << "Strength    : " << strength << endl;
	cout << "Defense     : " << defense << endl;
	cout << "Luck        : " << luck << endl;
	cout << "Faction     : " << faction << endl;
	cout << "Special Item: " << specialItem << endl;
	system("PAUSE");

}
// checks to see if desired character (entered by user exists)
bool CheckCharacterExist(fstream& charStatsFile, string CharacterPath)
{
	
	bool exists1;

	ifstream character;

	CharacterPath = "Characters\\"+ CharacterPath +".txt";

	// opens character file

	character.open(CharacterPath);

	//check to see if character exists
	if (!character.is_open()) {

		character.close();

		//roster.close();

		cout << "Invalid character name, try again" << endl;

		system("PAUSE");

		exists1 = 0;
		return exists1;


	}
	else {

		exists1 = 1;

		return exists1;

		//roster.close();
		character.close();
	}


}
// option 2, menu for duel
void DuelMenu() {

	//Reset choice variable
	int choice = 0;

	//player 1
	string playerNum = "Player1";
	string PlayerName;
	string PlayerTitle;
	int health = 100;
	int strength;
	int defense;
	int luck;
	string faction;
	string specialItem;

	//player 2
	string Player2Name;
	string Player2Title;
	int health2 = 100;
	int strength2;
	int defense2;
	int luck2;
	string faction2;
	string specialItem2;

	while (choice != 3) {

		system("CLS");

		//Duel Menu
		cout << "--------------------------" << endl;
		cout << "|1. Player 1 Vs. Player 2|" << endl;
		cout << "|------------------------|" << endl;
		cout << "|2. Player 1 Vs. Computer|" << endl;
		cout << "|------------------------|" << endl;
		cout << "|3. Return to Main Menu  |" << endl;
		cout << "--------------------------" << endl;
		cin >> choice;

		//Result of menu option choice
		if (choice == 1) {



			system("CLS");
			//resets player value	

			//player 1
			PlayerSelect(playerNum, PlayerName, PlayerTitle, health, strength, defense, luck, faction, specialItem);

			playerNum = "Player2";

			//player 2
			PlayerSelect(playerNum, Player2Name, Player2Title, health2, strength2, defense2, luck2, faction2, specialItem2);

			Player1VsPlayer2(PlayerName, PlayerTitle, health, strength, defense, luck, faction, specialItem,
				             Player2Name, Player2Title, health2, strength2, defense2, luck2, faction2, specialItem2);


		}

		else if (choice == 2) {


			cout << "Option unavailible at this time" << endl;


		}
		else if (choice == 3) {





		}
		else {


			cout << "Please enter a valid input" << endl;


		}

	}
}
// Function to handle player one vs. player two
void PlayerSelect (string player, string& PlayerName, string& PlayerTitle, int& health, int& strength, int& defense, int& luck, string& faction, string& specialItem) {

	//int Player;
	string read;

	


		//opens character roster file
		fstream rosterFile;
		rosterFile.open("Characters\\Roster.txt");


		system("CLS");

		if (player == "Player1") {

			cout << "          Player One " << endl;
		}
		else {
			cout << "          Player Two " << endl;
		

		}





		//resets choice variable
		int choice = 0;

		cout << "  -------------------------- " << endl;
		cout << "1. Load Created character" << endl;
		cout << "2. Randomly create characater" << endl;
		cin >> choice;




		if (choice == 1) {

			int status = 0;

			while (status == 0)
			{

				//reset loop exit variable
				//status = 0;


				while (rosterFile.good()) {

					rosterFile >> read;
					cout << read << endl;


				}

				//give the user to enter a character in the roster



				//calcuate the character path
				//1. name
				//2. name + ".txt"
				//3. 

				//ask which character to load
				cout << "Choose your character: ";
				cin >> PlayerName;

				bool exists = CheckCharacterExist(rosterFile, PlayerName);

				if (exists == 1) {


					//creates write from file object named character
					ifstream character;

					character.open("Characters\\" + PlayerName + ".txt");

					//parses data file for character stats input
					getline(character, PlayerName);
					getline(character, PlayerTitle);
					character >> health;
					character >> strength;
					character >> defense;
					character >> luck;
					//getline(character, faction);
					//getline(character, specialItem);
					character >> faction;
					character >> specialItem;

					//make sure to close your files kiddos
					character.close();
					rosterFile.close();

					break;
				}

				else {

					status = 0;
				
				}
			}
		}




		else if (choice == 2) {

			//specific ints for random name and title function
			short int NumTitleA = (rand() % 10) + 1;
			short int NumTitleB = (rand() % 10) + 1;
			short int NumNameA = (rand() % 5) + 1;
			short int NumNameB = (rand() % 5) + 1;

			string nameA;
			string nameB;

			string titleA;
			string titleB;


			//part A, assign random first part of name
			//pretty self explanitory, if NumNameA is "1"
			//then the nameA variable will be assigned to
			//hold the string "Fo".
			if (NumNameA == 1) {

				nameA = "Fo";
			}
			else if (NumNameA == 2) {

				nameA = "Ram";

			}
			else if (NumNameA == 3) {

				nameA = "Oh";
			}
			else if (NumNameA == 4) {

				nameA = "Gro";

			}
			else {

				nameA = "Je";
			}

			//now for part B of random name
			if (NumNameB == 1) {

				nameB = "luk";
			}
			else if (NumNameB == 2) {

				nameB = "op";

			}
			else if (NumNameB == 3) {

				nameB = "rump";
			}
			else if (NumNameB == 4) {

				nameB = "ale";

			}
			else {

				nameB = "stan";
			}

			//now to combine for name variable

			PlayerName = nameA + nameB;


			//And now we do something very similar for the Title var

			if (NumTitleA == 1) {

				titleA = "Eater";

			}
			else if (NumTitleA == 2) {

				titleA = "Destroyer";

			}
			else if (NumTitleA == 3) {

				titleA = "Smeller";

			}
			else if (NumTitleA == 4) {

				titleA = "Lover";

			}
			else if (NumTitleA == 5) {

				titleA = "Taster";

			}
			else if (NumTitleA == 6) {

				titleA = "Inventor";

			}
			else if (NumTitleA == 7) {

				titleA = "Ruler";

			}
			else if (NumTitleA == 8) {

				titleA = "Savior";

			}
			else if (NumTitleA == 9) {

				titleA = "Father";

			}
			else {

				titleA = "Giver";
			}

			//rinse and repeat

			if (NumTitleB == 1) {

				titleB = "Worlds";

			}
			else if (NumTitleB == 2) {

				titleB = "Farts";

			}
			else if (NumTitleB == 3) {

				titleB = "Grass";

			}
			else if (NumTitleB == 4) {

				titleB = "Tacos";

			}
			else if (NumTitleB == 5) {

				titleB = "Toilets";

			}
			else if (NumTitleB == 6) {

				titleB = "Bob";

			}
			else if (NumTitleB == 7) {

				titleB = "Turtles";

			}
			else if (NumTitleB == 8) {

				titleB = "Kittens";

			}
			else if (NumTitleB == 9) {

				titleB = "Socks";

			}
			else {

				titleB = "Men";
			}

			//combine for title

			PlayerTitle = titleA + " of " + titleB;

			//Random attribute and point allocation
			//just to ensure they refill
			int attributePoints = 180;

			//allocate random value for strength
			strength = (rand() % attributePoints - 1) + 1;

			//subject points for strength from attribute points
			attributePoints -= strength;

			//allocate random value for defense
			defense = (rand() % attributePoints - 1) + 1;

			//subject points for defense from attribute points
			attributePoints -= defense;

			//allocate remaining value for luck
			luck = attributePoints;

			if (strength > defense && strength > luck) {

				faction = "Wolves";
				specialItem = "Sword";

			}
			else if (defense > strength && defense > luck) {

				faction = "Ape";
				specialItem = "Armor";

			}
			else if (luck > strength && luck > defense) {

				faction = "Cat";
				specialItem = "Coincidence";

			}
			else {






				//in case the attributes just happen to all be equivalent
				//I'm using this
				short int decider = (rand() % 3) + 1;

				if (strength == defense && defense == luck && strength == luck) {

					if (decider == 1) {

						faction = "Wolves";
						specialItem = "Sword";

					}
					else if (decider == 2) {

						faction = "Ape";
						specialItem = "Armor";

					}
					else {

						faction = "Cat";
						specialItem = "Coincidence";

					}


				}
				else if (strength == defense) {

					if (decider == 1) {

						faction = "Wolves";
						specialItem = "Sword";

					}
					else if (decider == 2) {

						faction = "Ape";
						specialItem = "Armor";

					}
					else {}


				}
				else if (defense == luck) {

					if (decider == 1) {

						faction = "Cat";
						specialItem = "Coincidence";

					}
					else if (decider == 2) {

						faction = "Ape";
						specialItem = "Armor";

					}
					else {



					}

				}
				else if (strength == luck) {


					if (decider == 1) {

						faction = "Wolves";
						specialItem = "Sword";

					}
					else if (decider == 2) {

						faction = "Cat";
						specialItem = "Coincidence";

					}
					else {



					}


				}
				else {

				}
			}

			
		}


		

	


}
// Function for player one and player two to duel
void Player1VsPlayer2(string name1, string title1, int health1, int strength1, int defense1, int luck1, string faction1, string specialItem1, string name2, string title2, int health2, int strength2, int defense2, int luck2, string faction2, string specialItem2)
{

	int Round;
	int player;
	int choice = 0;

	ofstream battleData;
	battleData.open("Characters\\Battle Data.txt", ofstream::app);
	
	system("CLS");


	//display stats
	cout << "Player One Stats\t\t\t\t\t Player Two Stats" << endl;
	cout << "----------------\t\t\t\t\t ----------------" << endl;
	cout << "Name        : " << name1 << "\t\t\t\t\t Name        : " << name2 << endl;
	cout << "Title       : " << title1 << "\t\t\t\t Title       : " << title2 << endl;
	cout << "Health      : " << health1 << "\t\t     _  \t\t Health       : " << health2 << endl;
	cout << "Strength    : " << strength1 << "\t\t|  /( \t\t\t Strength     : " << strength2 << endl;
	cout << "Defense     : " << defense1 << "\t\t|/  _).\t\t\t Defense      : " << defense2 << endl;
	cout << "Luck        : " << luck1 << "\t\t\t\t\t Luck         : " << luck2 << endl;
	cout << "Faction     : " << faction1 << "\t\t\t\t\t Faction      : " << faction2 << endl;
	cout << "Special Item: " << specialItem1 << "\t\t\t\t\t Special Item : " << specialItem2 << endl;
	system("PAUSE");



	system("CLS");

	Round = 1;

	//reestabish player int
	player = 1;

	int attack = 0;



	//record battle data names
	battleData << name1 << " Vs. " << name2 << endl;

	while (choice != 3) {

		choice = 0;

		system("CLS");

		//player one's turn
		if (player == 1) {

			cout << "Round: " << Round << endl;

			if (player == 1) {
				cout << name1 << "'s turn" << endl;

			}
			else {

				cout << name2 << "'s turn" << endl;

			}

			cout << "------------" << endl;
			cout << "1 => Attack" << endl;
			cout << "2 => Item " << endl;
			cout << "3 => Forfeit" << endl;
			cout << "------------" << endl;
			cout << "\n\n " << name1 << "'s HP = " << health1 << "\t\t\t " << name2 << "'s HP = " << health2 << endl;
			cin >> choice;


			if (choice == 1) {

				attack = Attack(strength1, defense2);

				cout << name1 << " attacks!" << endl;
				cout << " Attack does " << attack << " damage!" << endl;
				health2 -= attack;
				cout << "\n\n" << name1 << "'s HP = " << health1 << "\t\t\t " << name2 << "'s HP = " << health2 << endl;
				system("Pause");
			}
			else if (choice == 2) {

				cout << "Uses Item " << endl;
				cout << "\n\n" << name1 << "'s HP = " << health1 << "\t\t\t " << name2 << "'s HP = " << health2 << endl;
			}
			else if (choice == 3) {

				choice = 0;

				system("CLS");

				//record to file
				battleData << "Rounds: " << Round << endl;
				battleData << name1 << " Forfeited" << endl;
				battleData << name2 << " WINS!" << endl;
				battleData << "------------" << endl;

				// close to stop recording battle data
				battleData.close();

				//print data to users
				cout << "Rounds: " << Round << endl;
				cout << name1 << " Forfeited" << endl;
				cout << name2 << " WINS!" << endl;
				system("PAUSE");
				break;
			}

			//HEALTH CHECK! If below or equal to zero exits loop
			if (health1 <= 0) {

				system("CLS");

				//record to file
				battleData << "Rounds: " << Round << endl;
				battleData << name1 << " Died" << endl;
				battleData << name2 << " WINS!" << endl;
				battleData << "------------" << endl;

				// close to stop recording battle data
				battleData.close();

				//print data to users
				cout << "Rounds: " << Round << endl;
				cout << name1 << " Died" << endl;
				cout << name2 << " WINS!" << endl;
				system("Pause");
				break;

			}
			else if (health2 <= 0) {

				system("CLS");

				//record to file
				battleData << "Rounds: " << Round << endl;
				battleData << name2 << " Died" << endl;
				battleData << name1 << " WINS!" << endl;
				battleData << "------------" << endl;

				// close to stop recording battle data
				battleData.close();
				
				//print data to users
				cout << "Rounds: " << Round << endl;
				cout << name2 << " Died" << endl;
				cout << name1 << " WINS!" << endl;
				system("PAUSE");
				break;

			}
			else {

				//keeps players rotating
				player += 1;
			}

		}


		//player two's turn
		else {

			cout << "Round: " << Round << endl;

			if (player == 1) {
				cout << name1 << "'s turn" << endl;

			}
			else {

				cout << name2 << "'s turn" << endl;

			}

			cout << "------------" << endl;
			cout << "1 => Attack" << endl;
			cout << "2 => Item " << endl;
			cout << "3 => Forfeit" << endl;
			cout << "------------" << endl;
			cout << "\n\n " << name1 << "'s HP = " << health1 << "\t\t\t " << name2 << "'s HP = " << health2 << endl;
			cin >> choice;


			if (choice == 1) {
				attack = Attack(strength2, defense1);
				cout << name2 << " attacks!" << endl;
				cout << " Attack does " << attack << " damage!" << endl;
				health1 -= attack;
				cout << "\n\n" << name1 << "'s HP = " << health1 << "\t\t\t " << name2 << "'s HP = " << health2 << endl;
				system("Pause");
			}
			else if (choice == 2) {

				cout << "Uses Item " << endl;
				cout << "\n\n" << name1 << "'s HP = " << health1 << "\t\t\t " << name2 << "'s HP = " << health2 << endl;
			}
			else if (choice == 3) {

				choice = 0;

				system("CLS");

				//record to file
				battleData << "Rounds: " << Round << endl;
				battleData << name2 << " Forfeited" << endl;
				battleData << name1 << " WINS!" << endl;
				battleData << "------------" << endl;

				// close to stop recording battle data
				battleData.close();

				//print data to users
				cout << "Rounds: " << Round << endl;
				cout << name2 << " Forfeited" << endl;
				cout << name1 << " WINS!" << endl;
				system("PAUSE");
				break;
			}

			//HEALTH CHECK! If below or equal to zero exits loop
			if (health1 <= 0) {

				system("CLS");

				//record to file
				battleData << "Rounds: " << Round << endl;
				battleData << name1 << " Died" << endl;
				battleData << name2 << " WINS!" << endl;
				battleData << "------------" << endl;

				// close to stop recording battle data
				battleData.close();

				//print data to users
				cout << "Rounds: " << Round << endl;
				cout << name1 << " Died" << endl;
				cout << name2 << " WINS!" << endl;
				system("Pause");
				break;

			}
			else if (health2 <= 0) {

				system("CLS");

				//record to file
				battleData << "Rounds: " << Round << endl;
				battleData << name2 << " Died" << endl;
				battleData << name1 << " WINS!" << endl;
				battleData << "------------" << endl;

				// close to stop recording battle data
				battleData.close();

				//print data to users
				cout << "Rounds: " << Round << endl;
				cout << name2 << " Died" << endl;
				cout << name1 << " WINS!" << endl;
				system("PAUSE");
				break;

			}
			else {

				//keeps players rotating
				player -= 1;
				//update round
				Round++;

				system("CLS");
				//display round update
				cout << "   ROUND " << Round << "!" << endl;
				system("PAUSE");
				system("CLS");
			}
		}
	}

}
// function for when the player wants to attack 
int Attack(int PlayerStrength, int PlayerDefense) {

	int strength1 = PlayerStrength;
	int defense2 = PlayerDefense;
	int attack1;

	float baseDamage = (rand() % 20) + 1;

	//calculate attack power based off of player strength

	float rawPercent = (rand() % strength1) + 1;

	rawPercent = rawPercent / 100;

	float addAttack = rawPercent * baseDamage;

	floor(rawPercent);

	floor(baseDamage);

	int RawAttack = baseDamage + addAttack;

	// Now to calculate the defense buff

	float rawDef = (rand() % defense2) + 1;

	rawDef = rawDef / 100;

	floor(rawDef);

	int defBuff = RawAttack * rawDef;

	if (RawAttack > defBuff) {

		attack1 = RawAttack - defBuff;

	}
	else if (defBuff > RawAttack) {

		attack1 = 0;

	}
	else {


	}

	return attack1;
}