#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

char array[3][3] = {{'-','-','-'}, {'-','-','-'}, {'-','-','-'}};
bool correct = false;
int x, y;
int scorex = 0;
int scoreo = 0;
string input;

void restart() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			array[i][j] = '-';
		}
	}
}

void inputchar() {
	correct = false;
	while (!correct) {
		cout << "enter row (0-2): ";
		cin >> input;
		try {
			x = stoi(input); 
			if (x < 3 && x > -1) { correct = true; }
		} catch(const invalid_argument& error) {
			cout << endl << "Invalid input. Try again." << endl << endl;
		}
		if (x > 2 || x < 0) {
			cout << endl << "Please enter number between 0-2" << endl << endl;
		}
	}
	correct = false;
	while (!correct) {
		cout << "enter column (0-2): ";
		cin >> input;
		try {
			y = stoi(input); 
			if (y < 3 && y > -1) { correct = true; }
		} catch(const invalid_argument& error) {
			cout << endl << "Invalid input. Try again." << endl << endl;
		}
		if (y > 2 || y < 0) {
			cout << endl << "Please enter number between 0-2" << endl << endl;
		}
	}
	correct = false;
}

void print() {
	cout << endl << " ===TIC TAC TOE===" << endl;
	cout << endl << " =================" << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << " ";
		for (int j = 0; j < 3; j++) {
			cout << "  " << array[i][j] << "  ";
			if (j != 2) {
				cout << "|";
			} else {
				cout << "  ";
			}
		}
		cout << endl;
		if (i != 2) {
			cout << " -----------------" << endl;
		}
	}
	cout << endl << " =================" << endl;
}

bool draw() {
	char choice;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (array[i][j] == '-') {
				return false;
			}
		}
	}
	system("clear");
	print();
	cout << endl << "Draw" << endl << endl;
	cout << "Player X Score: " << scorex << endl << "Player O Score: " << scoreo << endl;
	cout << endl << "New game? (Y/N): ";
	cin >> choice;
	while ((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n')) {
		if ((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n')) {
			cout << "Please enter either Y or N: "; 
			cin >> choice;
			cout << endl;
		}
	}
	cout << endl;
	if (choice == 'Y' || choice == 'y') {
		restart();
		return false;
	}
	return true;
}

bool end(int x, int y) {
	char choice;
	int col = 0, row = 0, diag = 0, rdiag = 0;
	char player = array[x][y];
	for (int i = 0; i < 3; i++) {
		if (array[x][i] == player) {
			col++;
		}
		if (array[i][y] == player) {
			row++;
		}
		if (array[i][i] == player) {
			diag++;
		}
		if (array[i][2-i] == player) {
			rdiag++;
		}
	}
	if (col == 3 || row == 3 || diag == 3 || rdiag == 3) {
		system("clear");
		print();
		cout << endl << "*** Winner: Player " << player << " ***"<< endl << endl;
		if (player == 'X') {
			scorex++;
		}
		else {
			scoreo++;
		}
		cout << "Player X Score: " << scorex << endl << "Player O Score: " << scoreo << endl;
		cout << endl << "New game? (Y/N): ";
		cin >> choice;
		while ((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n')) {
			if ((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n')) {
				cout << "Please enter either Y or N: "; 
				cin >> choice;
				cout << endl;
			}
		}
		cout << endl;
		if (choice == 'Y' || choice == 'y') {
			restart();
			return false;
		}
		return true;
	}
	return false;
}

int main() {
	char prev = 'X';
	char next = 'O';
	bool done = false;
	bool correct = false;
	while (!done) {
		system("clear");
		print();
		
		if (!done) {
			cout << endl << "it is Player " << next << "'s turn" << endl << endl;
		}
		
		inputchar();

		if (array[x][y] == '-') {
			if (prev == 'X') {
				next = prev;
				array[x][y] = 'O';
				prev = 'O';
			} else {
				next = prev;
				array[x][y] = 'X';
				prev = 'X';
			}
			done = end(x, y) || draw();
		} else {
			cout << endl << "Slot unavailable, try again." << endl << endl;
		}
	}
	return 0;
}