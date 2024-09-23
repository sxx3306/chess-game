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

		// Convert row characters to integers
		int from_row_int = from_row - '0';
		int row_int = row - '0';

		if (grid[col] > 7 || row_int > 8 || grid[col] < 0 || row_int < 1) {
			return false;
		}

		if (piece == 'Q') {
			// Queen logic: horizontal, vertical, or diagonal moves
			if ((from_col == col && from_row != row) ||
				(from_col != col && from_row == row) ||
				(abs(grid[from_col] - grid[col]) == abs(from_row_int - row_int))) {
				return true;
			}
		}
		else if (piece == 'R') {
			// Rook logic: horizontal or vertical moves
			if ((from_col == col && from_row != row) ||
				(from_col != col && from_row == row)) {
				return true;
			}
		}
		else if (piece == 'B') {
			// Bishop logic: diagonal moves
			if (abs(grid[from_col] - grid[col]) == abs(from_row_int - row_int)) {
				return true;
			}
		}
		else if (piece == 'N') {
			// Knight logic: "L" shape moves
			if ((abs(grid[from_col] - grid[col]) == 2 && abs(from_row_int - row_int) == 1) ||
				(abs(grid[from_col] - grid[col]) == 1 && abs(from_row_int - row_int) == 2)) {
				return true;
			}
		}
		else if (piece == 'K') {
			// King logic: move one square in any direction
			if (abs(grid[from_col] - grid[col]) <= 1 && abs(from_row_int - row_int) <= 1) {
				return true;
			}
		}
	}
	else if (notation.size() == 5) {

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
