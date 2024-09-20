#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <map>

using namespace std;

bool check(string notation) {
	map<char, int> grid = {
		{'a', 0},
		{'b', 1},
		{'c', 2},
		{'d', 3},
		{'e', 4},
		{'f', 5},
		{'g', 6},
		{'h', 7}
	};

	if (notation.size() > 5) {
		char side = notation[0];
		char piece = notation[1];
		char from_col = notation[2];
		char from_row = notation[3];
		char col = notation[4];
		char row = notation[5];

		if (col > 8 || row > 8 || col < 1 || row < 1) {
			return false;
		}

		if (piece == 'Q') {
			if ((from_col == col) && (from_row != row) || (from_col != col) && (from_row == row) || (abs(grid[from_col] - grid[col]) == abs(from_row - row))) {
				return true;
			}
		} else if (piece == 'R') {
			if ((from_col == col) && (from_row != row) || (from_col != col) && (from_row == row)) {
				return true;
			}
		} else if (piece == 'B') {
			if (abs(grid[from_col] - grid[col]) == abs(from_row - row)) {
				return true;
			}
		} else if (piece == 'N') {

		}
		else if (piece == 'K') {
			if (abs(grid[from_col] - grid[col]) <= 1 && abs(from_row - row) <= 1) {
				return true;
			}
		}
	} else if (notation.size() == 5) {
		char side = notation[0];
		char from_col = notation[1];
		char from_row = notation[2];
		char col = notation[3];
		char row = notation[4];
	}
	else {
		return false;
	}

	return false;
}

int main() {
	string board[8][8] = {
		{"BRa8", "BNb8", "BBc8", "BQd8", "BKe8", "BBf8", "BNg8", "BRh8"},
		{"Ba7", "Bb7", "Bc7", "Bd7", "Be7", "Bf7", "Bg7", "Bh7"},
		{"", "", "", "", "", "", "", ""},
		{"", "", "", "", "", "", "", ""},
		{"", "", "", "", "", "", "", ""},
		{"", "", "", "", "", "", "", ""},
		{"Wa2", "Wb2", "Wc2", "Wd2", "We2", "Wf2", "Wg2", "Wh2"},
		{"WRa1", "WNb1", "WBc1", "WQd1", "WKe1", "WBf1", "WNg1", "WRh1"}
	};

	string move;

	cin >> move;
	cout << check(move);
}
