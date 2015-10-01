
#include <stdafx.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

int playerOneScore = 0;
int playerTwoScore = 0; //computer's score too
int whosTurn = 0; //0 = player1, 1 = player2 or com
bool isPvp = true;


void showOption();
void pvcPlay();
void pvpPlay();


class NumberBox {

public:

	char value;

	NumberBox(char _value) {

		value = _value;

	}

	~NumberBox() {}

	char getValue() {
		return value;
	}
	bool isOqupied() {
		return (value == 'X' || value == 'O') ? true : false;
	}

	void setValue(char v) {
		value = v;
	}

};

void comAI();
NumberBox* getRandomBox();


NumberBox one('1');
NumberBox two('2');
NumberBox three('3');
NumberBox four('4');
NumberBox five('5');
NumberBox six('6');
NumberBox seven('7');
NumberBox eight('8');
NumberBox nine('9');



void updateGrid() {
	system("cls");

	cout << "whosturn: " << whosTurn << endl;

	string str1;
	string oppoName = (isPvp) ? "Player2 " : "Computer";

	if (whosTurn == 0) {
		str1 = "Player1";
	}
	else {
		str1 = (isPvp) ? "Player2 " : "Computer";
	}

	str1 += "'s turn.";

	cout << "Tic-Tac-Toe Game\n\n"
		<< "+---+---+---+\n"
		<< "| " << one.getValue() << " | " << two.getValue() << " | " << three.getValue() << " |\n"
		<< "+---+---+---+\n"
		<< "| " << four.getValue() << " | " << five.getValue() << " | " << six.getValue() << " |\n"
		<< "+---+---+---+\n"
		<< "| " << seven.getValue() << " | " << eight.getValue() << " | " << nine.getValue() << " |\n"
		<< "+---+---+---+\n\n"
		<< str1 << "\n\n"
		<< "----------------------------\n"
		<< "    Player   |   Score\n"
		<< "-------------+--------------\n"
		<< "Player1  (O) |    " << playerOneScore << "\n"
		<< oppoName + " (X) |    " << playerTwoScore << "\n"
		<< endl;

}


bool isOneToNine(int num) {
	if (num > 0 && num < 10) {
		return true;
	}
	return false;
}


NumberBox* getNumberBoxByIndex(int index) {
	if (index == 1) return &one;
	if (index == 2) return &two;
	if (index == 3) return &three;
	if (index == 4) return &four;
	if (index == 5) return &five;
	if (index == 6) return &six;
	if (index == 7) return &seven;
	if (index == 8) return &eight;
	if (index == 9) return &nine;
	throw "Index have to be 1 ~ 9";
}

char win() {

	char _one = one.getValue();
	char _two = two.getValue();
	char _three = three.getValue();
	char _four = four.getValue();
	char _five = five.getValue();
	char _six = six.getValue();
	char _seven = seven.getValue();
	char _eight = eight.getValue();
	char _nine = nine.getValue();
	char X = 'X';
	char O = 'O';

	if (one.isOqupied() &&
		two.isOqupied() &&
		three.isOqupied() &&
		four.isOqupied() &&
		five.isOqupied() &&
		six.isOqupied() &&
		seven.isOqupied() &&
		eight.isOqupied() &&
		nine.isOqupied()) {
		return 'D'; //Draw
	}

	if ((_one == X && _two == X && _three == X) ||
		(_four == X && _five == X && _six == X) ||
		(_seven == X && _eight == X && _nine == X) ||
		(_one == X && _four == X && _seven == X) ||
		(_two == X && _five == X && _eight == X) ||
		(_three == X && _six == X && _nine == X) ||
		(_one == X && _five == X && _nine == X) ||
		(_three == X && _five == X && _seven == X)) {
		return 'X'; //X won
	}
	if ((_one == O && _two == O && _three == O) ||
		(_four == O && _five == O && _six == O) ||
		(_seven == O && _eight == O && _nine == O) ||
		(_one == O && _four == O && _seven == O) ||
		(_two == O && _five == O && _eight == O) ||
		(_three == O && _six == O && _nine == O) ||
		(_one == O && _five == O && _nine == O) ||
		(_three == O && _five == O && _seven == O)) {
		return 'O'; //O won
	}

	return 'N'; //Noting

}


void inputValue(int input) {
	char symbol = (whosTurn == 0) ? 'O' : 'X';

	NumberBox* box = getNumberBoxByIndex(input);

	if (box->isOqupied() == false) {
		box->setValue(symbol);
		whosTurn = (whosTurn == 0) ? 1 : 0;
	}

}


void pvpPlay() {

	int input;

	while (true) {

		cin >> input;

		if (isOneToNine(input)) {

			inputValue(input);

			updateGrid();

			char result = win();

			if (result == 'D') {
				cout << "----It's Draw!!!----\n" << endl;

				showOption();

				break;
			}
			if (result == 'O') {

				playerOneScore++;

				updateGrid();

				cout << "----O Won!!!----\n" << endl;

				showOption();

				break;
			}
			else if (result == 'X') {

				playerTwoScore++;

				updateGrid();

				cout << "----X Won!!!----\n" << endl;

				showOption();

				break;

			}

		}

	}

}




void pvpOrCom() {

	system("cls");

	cout << "Tic-Tac-Toe Game\n\n"
		<< "What would you like to play?\n\n"
		<< "  PVP (1)    |    Computer (2)\n\n";

	srand(time(NULL));

	whosTurn = rand() % 2;

	while (true) {
		int input;

		cin >> input;

		if (input == 1) {
			isPvp = true;

			updateGrid();

			pvpPlay();

			break;
		}
		else if (input == 2) {
			isPvp = false;

			updateGrid();

			pvcPlay();

			break;
		}

	}

}




void reset(bool isRestart) {

	if (isRestart) {
		playerOneScore = 0;
		playerTwoScore = 0;
	}
	one.setValue('1');
	
	two.setValue('2');

	three.setValue('3');

	four.setValue('4');

	five.setValue('5');

	six.setValue('6');

	seven.setValue('7');

	eight.setValue('8');

	nine.setValue('9');

	whosTurn = 0;

}

void showOption() {

	cout << "What do you want?\n\n"
		<< "Another game (1)\n"
		<< "Restart game (2)\n"
		<< "Quit         (3)\n";
	int input;

	cin >> input;

	if (input == 1) {
		reset(false);
		updateGrid();
		if (isPvp) {
			pvpPlay();
		}
		else {
			pvcPlay();
		}
	}
	else if (input == 2) {
		reset(true);
		pvpOrCom();
	}
	else {
		system("cls");

		string winner;

		if (playerOneScore == playerTwoScore) {
			winner = "DRAW";

		}
		else if (playerOneScore > playerTwoScore) {
			winner = "Player1 WIN";
		}
		else {
			winner = (isPvp) ? "Player2 WIN" : "Computer WIN";
		}
		cout << "@@@@@@@@@@@@@@@@@@@@\n"
			<< "\n"
			<< "    " << winner << "\n"
			<< "\n"
			<< "@@@@@@@@@@@@@@@@@@@@\n\n";
	}

}



void pvcPlay() {

	int input;

	while (true) {

		if (whosTurn == 0) {

			while (true) {

				cin >> input;

				if (isOneToNine(input)) {

					char symbol ='O';

					NumberBox* box = getNumberBoxByIndex(input);

					if (box->isOqupied() == false) {
						box->setValue(symbol);
						
						whosTurn = (whosTurn == 0) ? 1 : 0;

						break;
					}
				}
			}

			updateGrid();		

		}
		//computer's turn
		else {
			//defence, attack
			//Com is always 'X'

			Sleep(1000);

			comAI();

			updateGrid();

			whosTurn = (whosTurn == 0) ? 1 : 0;
		}

		char result = win();

		if (result == 'D') {
			cout << "----It's Draw!!!----\n" << endl;

			showOption();

			break;
		}
		if (result == 'O') {

			playerOneScore++;

			updateGrid();

			cout << "----O Won!!!----\n" << endl;

			showOption();

			break;
		}
		else if (result == 'X') {

			playerTwoScore++;

			updateGrid();

			cout << "----X Won!!!----\n" << endl;

			showOption();

			break;
		}

		updateGrid();
	}

}


void comAI() {
	char _one = one.getValue();
	char _two = two.getValue();
	char _three = three.getValue();
	char _four = four.getValue();
	char _five = five.getValue();
	char _six = six.getValue();
	char _seven = seven.getValue();
	char _eight = eight.getValue();
	char _nine = nine.getValue();
	char X = 'X';
	char O = 'O';

	NumberBox* onePointer = &one;
	NumberBox* twoPointer = &two;
	NumberBox* threePointer = &three;
	NumberBox* fourPointer = &four;
	NumberBox* fivePointer = &five;
	NumberBox* sixPointer = &six;
	NumberBox* sevenPointer = &seven;
	NumberBox* eightPointer = &eight;
	NumberBox* ninePointer = &nine;

	NumberBox* theBox = &one;
	bool haveUsedTurn = false;
	char symbol = 'X';

	//attack conditions
	//only check it's one move before winnig

	//cross
	if (_one == X && _five == X) {
		if (!nine.isOqupied()) {
			theBox = ninePointer;
			haveUsedTurn = true;
		}
	}
	if (_five == X && _nine == X) {
		if (!one.isOqupied()) {
			theBox = onePointer;
			haveUsedTurn = true;
		}
	}
	if (_one == X && _nine == X) {
		if (!five.isOqupied()) {
			theBox = fivePointer;
			haveUsedTurn = true;
		}
	}
	if (_three == X && _five == X) {
		if (!seven.isOqupied()) {
			theBox = sevenPointer;
			haveUsedTurn = true;
		}
	}
	if (_five == X && _seven == X) {
		if (!three.isOqupied()) {
			theBox = threePointer;
			haveUsedTurn = true;
		}
	}
	if (_three == X && _seven == X) {
		if (!five.isOqupied()) {
			theBox = fivePointer;
			haveUsedTurn = true;
		}
	}
	//row
	if (_one == X && _two == X) {
		if (!three.isOqupied()) {
			theBox = threePointer;
			haveUsedTurn = true;
		}
	}
	if (_two == X && _three == X) {
		if (!one.isOqupied()) {
			theBox = onePointer;
			haveUsedTurn = true;
		}
	}
	if (_one == X && _three == X) {
		if (!two.isOqupied()) {
			theBox = twoPointer;
			haveUsedTurn = true;
		}
	}
	if (_four == X && _five == X) {
		if (!six.isOqupied()) {
			theBox = sixPointer;
			haveUsedTurn = true;
		}
	}
	if (_five == X && _six == X) {
		if (!four.isOqupied()) {
			theBox = fourPointer;
			haveUsedTurn = true;
		}
	}
	if (_four == X && _six == X) {
		if (!five.isOqupied()) {
			theBox = fivePointer;
			haveUsedTurn = true;
		}
	}
	if (_seven == X && _eight == X) {
		if (!nine.isOqupied()) {
			theBox = ninePointer;
			haveUsedTurn = true;
		}
	}
	if (_eight == X && _nine == X) {
		if (!seven.isOqupied()) {
			theBox = sevenPointer;
			haveUsedTurn = true;
		}
	}
	if (_seven == X && _nine == X) {
		if (!eight.isOqupied()) {
			theBox = eightPointer;
			haveUsedTurn = true;
		}
	}
	//column
	if (_one == X && _four == X) {
		if (!seven.isOqupied()) {
			theBox = sevenPointer;
			haveUsedTurn = true;
		}
	}
	if (_four == X && _seven == X) {
		if (!one.isOqupied()) {
			theBox = onePointer;
			haveUsedTurn = true;
		}
	}
	if (_one == X && _seven == X) {
		if (!four.isOqupied()) {
			theBox = fourPointer;
			haveUsedTurn = true;
		}
	}
	if (_two == X && _five == X) {
		if (!eight.isOqupied()) {
			theBox = eightPointer;
			haveUsedTurn = true;
		}
	}
	if (_five == X && _eight == X) {
		if (!two.isOqupied()) {
			theBox = twoPointer;
			haveUsedTurn = true;
		}
	}
	if (_two == X && _eight == X) {
		if (!five.isOqupied()) {
			theBox = fivePointer;
			haveUsedTurn = true;
		}
	}
	if (_three == X && _six == X) {
		if (!nine.isOqupied()) {
			theBox = ninePointer;
			haveUsedTurn = true;
		}
	}
	if (_six == X && _nine == X) {
		if (!three.isOqupied()) {
			theBox = threePointer;
			haveUsedTurn = true;
		}
	}
	if (_three == X && _nine == X) {
		if (!six.isOqupied()) {
			theBox = sixPointer;
			haveUsedTurn = true;
		}
	}


	//defence conditions

	if (haveUsedTurn == false) {
		//cross
		if (_one == O && _five == O) {
			if (!nine.isOqupied()) {
				theBox = ninePointer;
				haveUsedTurn = true;
			}
		}
		if (_five == O && _nine == O) {
			if (!one.isOqupied()) {
				theBox = onePointer;
				haveUsedTurn = true;
			}
		}
		if (_one == O && _nine == O) {
			if (!five.isOqupied()) {
				theBox = fivePointer;
				haveUsedTurn = true;
			}
		}
		if (_three == O && _five == O) {
			if (!seven.isOqupied()) {
				theBox = sevenPointer;
				haveUsedTurn = true;
			}
		}
		if (_five == O && _seven == O) {
			if (!three.isOqupied()) {
				theBox = threePointer;
				haveUsedTurn = true;
			}
		}
		if (_three == O && _seven == O) {
			if (!five.isOqupied()) {
				theBox = fivePointer;
				haveUsedTurn = true;
			}
		}
		//row
		if (_one == O && _two == O) {
			if (!three.isOqupied()) {
				theBox = threePointer;
				haveUsedTurn = true;
			}
		}
		if (_two == O && _three == O) {
			if (!one.isOqupied()) {
				theBox = onePointer;
				haveUsedTurn = true;
			}
		}
		if (_one == O && _three == O) {
			if (!two.isOqupied()) {
				theBox = twoPointer;
				haveUsedTurn = true;
			}
		}
		if (_four == O && _five == O) {
			if (!six.isOqupied()) {
				theBox = sixPointer;
				haveUsedTurn = true;
			}
		}
		if (_five == O && _six == O) {
			if (!four.isOqupied()) {
				theBox = fourPointer;
				haveUsedTurn = true;
			}
		}
		if (_four == O && _six == O) {
			if (!five.isOqupied()) {
				theBox = fivePointer;
				haveUsedTurn = true;
			}
		}
		if (_seven == O && _eight == O) {
			if (!nine.isOqupied()) {
				theBox = ninePointer;
				haveUsedTurn = true;
			}
		}
		if (_eight == O && _nine == O) {
			if (!seven.isOqupied()) {
				theBox = sevenPointer;
				haveUsedTurn = true;
			}
		}
		if (_one == O && _nine == O) {
			if (!three.isOqupied()) {
				theBox = threePointer;
				haveUsedTurn = true;
			}
		}
		//column
		if (_one == O && _four == O) {
			if (!seven.isOqupied()) {
				theBox = sevenPointer;
				haveUsedTurn = true;
			}
		}
		if (_four == O && _seven == O) {
			if (!one.isOqupied()) {
				theBox = onePointer;
				haveUsedTurn = true;
			}
		}
		if (_one == O && _seven == O) {
			if (!four.isOqupied()) {
				theBox = fourPointer;
				haveUsedTurn = true;
			}
		}
		if (_two == O && _five == O) {
			if (!eight.isOqupied()) {
				theBox = eightPointer;
				haveUsedTurn = true;
			}
		}
		if (_five == O && _eight == O) {
			if (!two.isOqupied()) {
				theBox = twoPointer;
				haveUsedTurn = true;
			}
		}
		if (_two == O && _eight == O) {
			if (!five.isOqupied()) {
				theBox = fivePointer;
				haveUsedTurn = true;
			}
		}
		if (_three == O && _six == O) {
			if (!nine.isOqupied()) {
				theBox = ninePointer;
				haveUsedTurn = true;
			}
		}
		if (_six == O && _nine == O) {
			if (!three.isOqupied()) {
				theBox = threePointer;
				haveUsedTurn = true;
			}
		}
		if (_three == O && _nine == O) {
			if (!six.isOqupied()) {
				theBox = sixPointer;
				haveUsedTurn = true;
			}
		}
	}

	if (haveUsedTurn) {
		theBox->setValue(symbol);
		return;
	}

	vector<int> ava;

	for (int a = 1; a <= 5; a++) {

		int b = a * 2 - 1;

		if (getNumberBoxByIndex(b)->isOqupied() == false) {
			ava.push_back(b);
		}
	}

	if (ava.size() > 0) {

		int random = rand() % ava.size();

		theBox = getNumberBoxByIndex(ava[random]);

		theBox->setValue(symbol);

		return;

	}

	theBox = getRandomBox();
	theBox->setValue(symbol);

}


NumberBox* getRandomBox() {
	vector<int> ava;

	for (int a = 1; a < 10; a++) {
		if (getNumberBoxByIndex(a)->isOqupied() == false) {
			ava.push_back(a);
		}
	}

	while (true) {
		int random = ava[rand() % ava.size()];

		NumberBox* theBox = getNumberBoxByIndex(random);

		if (theBox->isOqupied() == false) {
			return theBox;
		}

		ava.erase(ava.begin() + random);

	}
}





int main()
{

	pvpOrCom();

	return 0;

}
