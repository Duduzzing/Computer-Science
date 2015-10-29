

#include "stdafx.h"
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

	}

	int getPercent(){

		return (progress / max) * 100;

	}

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

	void render(){

		cout << "|";
		
		for (int a = 0; a < max / 10; a++) {

			if (a > progress / 10)
				cout << "=";
			else
				cout << "#";
		}

		cout << "|" << endl;

	};


private:

	int progress = 0;
	double max = 100.0;

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

	for (int k = 0; k < bar.getMax(); k++)
	{
		bar.setProgress(k);
		bar.render();


		cout << bar.getMax() << endl;
		cout << bar.getProgress() << endl;
		cout << bar.getPercent() << "%" << endl;

		Sleep(10);

		system("cls");
	}
	
	
	return 0;
}

