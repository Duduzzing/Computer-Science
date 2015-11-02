

#include "stdafx.h" // for visual studio
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class ProgressBar {

public:

	int getProgress(){

		return progress;

	};

	int getMax(){

		return max;

	};
	
	int getPercent(){

		return (progress / max) * 100;

	};

	int getLength(){

		return length;

	};

	void setMax(int _max){

		max = _max;

	};

	void setProgress(int value){

		if (value < max)
			progress = value;

	};

	void setProgressColor(int color){

		HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, color);

	};
	
	void setLength(int _length){

		length = _length;

	};

	void render(){

		cout << "|";

		for (int a = 0; a < length; a++) {

			if (a > progress / max * length)
				cout << "=";
			else
				cout << "#";
		}

		cout << "|";  << endl;

	};



private:

	int progress = 0;
	double max = 100.0;
	int length = 25;

};

/*
Color            Background Foreground
-------------------------------------------- -
Black            0           0
Blue             1           1
Green            2           2
Cyan             3           3
Red              4           4
Magenta          5           5
Brown            6           6
White            7           7
Gray - 8
Intense Blue - 9
Intense Green - 10
Intense Cyan - 11
Intense Red - 12
Intense Magenta - 13
Yellow - 14
Intense White - 15

*/

int _tmain(int argc, _TCHAR* argv[])
{

	ProgressBar bar;

	bar.setMax(220);
	bar.setLength(35); 

	for (int k = 0; k < bar.getMax(); k++)
	{
		bar.setProgress(k);
		bar.render();

		cout << bar.getPercent() << "%" << endl;

		Sleep(10);

		system("cls");
	}


	return 0;
}
