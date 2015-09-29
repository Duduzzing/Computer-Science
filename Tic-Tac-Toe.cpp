
#include <stdafx.h>
#include <iostream>
#include <string>

using namespace std;

int playerOneScore = 0;
int playerTwoScore = 0;
int computerScore = 0;
int whosTurn = 0; //0 = player1, 1 = player2 or com
bool isPvp = false;


void showOption();

class NumberBox {

public:

	char value;
	bool isBoxOqupied;

	NumberBox(char _value) {

		value = _value;
		isBoxOqupied = false;

	}

	~NumberBox() {}

	char getValue() {
		return value;
	}
	bool isOqupied() {
		return isBoxOqupied;
	}

	void setValue(char v) {
		value = v;
	}
	void setOqupied(bool o) {
		isBoxOqupied = o;
	}


};


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

	string str1;
	string oppoName = (isPvp) ? "Computer" : "Player2 ";

	if (whosTurn == 0) {
		str1 = "Player1";
	}
	else {
		str1 = (isPvp) ? "Computer" : "Player2";
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


bool isOneToNine(char num) {
	if (num != '1' &&
		num != '2' &&
		num != '3' &&
		num != '4'&&
		num != '5'&&
		num != '6'&&
		num != '7'&&
		num != '8'&&
		num != '9') {
		return false;
	}
	return true;
}



NumberBox* getNumberBoxByValue(char value){
if(one.getValue() == value) return &one;
if(two.getValue() == value) return &two;
if(three.getValue() == value) return &three;
if(four.getValue() == value) return &four;
if(five.getValue() == value) return &five;
if(six.getValue() == value) return &six;
if(seven.getValue() == value) return &seven;
if(eight.getValue() == value) return &eight;
if(nine.getValue() == value) return &nine;
 NumberBox a('a');
 a.setOqupied(true);
 return &a; //Memory leak?
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
	if ((_one == O && _two == O && _three == O )||
		(_four == O && _five == O && _six == O )||
		(_seven == O && _eight == O && _nine == O )||
		(_one == O && _four == O && _seven == O )||
		(_two == O && _five == O && _eight == O )||
		(_three == O && _six == O && _nine == O) ||
		(_one == O && _five == O && _nine == O )||
		(_three == O && _five == O && _seven == O)) {
		return 'O'; //O won
	}

	return 'N'; //Noting

}


void inputValue(char input) {
	char symbol = (whosTurn == 0) ? 'O' : 'X';

	NumberBox* box = getNumberBoxByValue(input);

	if (box->getValue() == input && !box->isOqupied()) {
		box->setValue(symbol);
		box->setOqupied(true);
		whosTurn = (whosTurn == 0) ? 1 : 0;
	}

}


void pvpPlay() {

	char input;

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

			if (result == 'X') {

				playerOneScore++;

				updateGrid();

				cout << "----X Won!!!----\n" << endl;

				showOption();
				//todo offer another game

				break;

			}
			else if (result == 'O') {

				playerTwoScore++;

				updateGrid();

				cout << "----O Won!!!----\n" << endl;

				showOption();
				//todo offer another game

				break;

			}

		}
		else {

		}

	}

}




void pvpOrCom() {

	cout << "Tic-Tac-Toe Game\n\n"
		<< "What would you like to play?\n\n"
		<< "  PVP (1)    |    Computer (2)\n\n";


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
			cout << "nothing yet :)" << endl;
			break;
		}
		else {

		}
	}

}




void reset(bool isRestart) {

	if (isRestart) {
		playerOneScore = 0;
		playerTwoScore = 0;
		computerScore = 0;
	}

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
		pvpPlay();
	}
	else if (input == 2) {
		reset(true);
		cout << "notehinf";
	}
	cout <<"input:" <<input;

}

int main()
{

	pvpOrCom();



}


