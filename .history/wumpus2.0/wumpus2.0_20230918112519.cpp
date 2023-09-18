// Hunt The Wumpus V2.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;
/*struct colors_t
{
	HANDLE hstdout;
	int    initial_colors;

	colors_t()
	{
		hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		initial_colors = getcolors();
	}

	~colors_t()
	{
		setcolors(initial_colors);
	}

	int getcolors() const
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hstdout, &csbi);
		return csbi.wAttributes;
	}

	void setcolors(int color)
	{
		SetConsoleTextAttribute(hstdout, color);
	}

	void setfg(int color)
	{
		int current_colors = getcolors();
		setcolors((current_colors & 0xF0) | (color & 0x0F));
	}

	void setbg(int color)
	{
		int current_colors = getcolors();
		setcolors(((color & 0x0F) << 4) | (current_colors & 0x0F));
	}

	int getfg() const { return  getcolors() & 0x0F; }
	int getbg() const { return (getcolors() >> 4) & 0x0F; }
};

enum {
	black,
	dark_blue,
	dark_green,
	dark_cyan,
	dark_red,
	dark_magenta,
	dark_yellow,
	light_gray,
	dark_gray,
	light_blue,
	light_green,
	light_cyan,
	light_red,
	light_magenta,
	light_yellow,
	white
};

colors_t colors;
*/
void MoveUp(int row, int matrix[5][5], int col) {

	cout << "UP" << endl;

	row -= 1;
	cout << "row = " << row << "; col = " << col << endl;
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if ((r == row) && (c == col))
				colors.setfg(light_yellow);

			cout << matrix[r][c];
			colors.setcolors(colors.initial_colors);
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void MoveLeft(int row, int matrix[5][5], int col) {
	cout << "Left" << endl;
	col -= 1;
	cout << "row = " << row << "; col = " << col << endl;
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if ((r == row) && (c == col))
				colors.setfg(light_yellow);
			cout << matrix[r][c];
			colors.setcolors(colors.initial_colors);
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}



​
void MoveRight(int row, int matrix[5][5], int col) {
	cout << "Right" << endl;
	col += 1;
	cout << "row = " << row << "; col = " << col << endl;
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if ((r == row) && (c == col))
				colors.setfg(light_yellow);
			cout << matrix[r][c];
			colors.setcolors(colors.initial_colors);
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}​


void MoveDown(int row, int matrix[5][5], int col) {
	cout << "Down" << endl;
	row += 1;
	cout << "row = " << row << "; col = " << col << endl;
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if ((r == row) && (c == col))
				colors.setfg(light_yellow);
			cout << matrix[r][c];
			colors.setcolors(colors.initial_colors);
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}​


int main()
{
	cout << "	Hunt to kill the Wumpus." << endl;
	cout << "	The Wumpus is hiding in a 5x5 square." << endl;
	cout << "	So imagine a grid labeled 1 thru 5 and then a new row begins. Then 6 thru 10 and so on." << endl;
	cout << "	You will be given hints about what you are the surrounded by, every time you move." << endl;
	cout << "	When you think you've found the Wumpus, shoot an arrow in that direction." << endl;
	cout << "	But make sure not to move into his square because he will eat you." << endl;
	cout << "	**CAUTION There are pits that you can fall into, so use the hints given and try to avoid them.**" << endl;
	cout << " " << endl;
	cout << " " << endl;
	//	How to Move
	cout << "	How to Move" << endl;
	cout << "	Press W to move up one square" << endl;
	cout << "	Press S to move down one square" << endl;
	cout << "	Press A to move to the left one square" << endl;
	cout << "	Press D to move to the Right one square" << endl;
	cout << " " << endl;
	//	How to Shoot an Arrow
	cout << "	How to SHOOT an Arrow" << endl;
	cout << "	Press the 1 to shoot an arrow UP one square" << endl;
	cout << "	Press the 2 to shoot an arrow DOWN one square" << endl;
	cout << "	Press the 3 to shoot an arrow LEFT one square" << endl;
	cout << "	Press the 4 to shoot an arrow RIGHT one square" << endl;

	random_device rd;
	uniform_int_distribution<int> RandomStartrow(0, 4);

	random_device rr;
	uniform_int_distribution<int> RandomStartcol(0, 4);

	random_device pp;
	uniform_int_distribution<int> RandomPit1r(0, 4);

	random_device pr;
	uniform_int_distribution<int> RandomPit2r(0, 4);

	random_device rp;
	uniform_int_distribution<int> RandomPit3r(0, 4);

	random_device pw;
	uniform_int_distribution<int> RandomPit1c(0, 4);

	random_device wp;
	uniform_int_distribution<int> RandomPit2c(0, 4);

	random_device ww;
	uniform_int_distribution<int> RandomPit3c(0, 4);

	random_device re;
	uniform_int_distribution<int> RandomWumpusrow(0, 4);

	random_device rc;
	uniform_int_distribution<int> RandomWumpuscol(0, 4);

	int row = RandomStartrow(rd);

	int col = RandomStartcol(rr);
	int wumpusrow = RandomWumpusrow(re);
	int wumpuscol = RandomWumpuscol(rc);
	int pit1r = RandomPit1r(pp);
	int pit2r = RandomPit2r(pr);
	int pit3r = RandomPit3r(rp);
	int pit1c = RandomPit1c(pw);
	int pit2c = RandomPit2c(wp);
	int pit3c = RandomPit3c(ww);

	int matrix[5][5] = {
		{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }
	};

	cout << "row = " << row << "; col = " << col << endl;

	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if ((r == row) && (c == col))
				colors.setfg(light_yellow);
			cout << matrix[r][c];
			colors.setcolors(colors.initial_colors);
			cout << " ";
		}
		cout << endl;
	}
	colors.setfg(light_yellow);
	cout << matrix[row][col] << "    jojiojo" << endl;
	colors.setcolors(colors.initial_colors);
	bool WumpusFound;
	int input;
	cin >> input;
	while (WumpusFound = false); {
		if (input = 1) {

			MoveUp(row, matrix, col);

			if (row == wumpusrow && col == wumpuscol) {

				WumpusFound = true;
				cout << "GAME OVER" << endl;
				cout << "You walked into the Wumpus, HE ATE YOU!" << endl;
			}
			else if (row < 0) {
				cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
			}
			else if (row == pit1r && col == pit1c) {
				cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
			}
			else if (row == pit2r && col == pit2c) {
				cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
			}
			else if (row == pit3r && col == pit3c) {
				cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
			}
			else if (pit1r = row + 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit2r = row + 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit3r = row + 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit1r = row - 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit2r = row - 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit3r = row - 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit1c = col + 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit2c = col + 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit3c = col + 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit1c = col - 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit2c = col - 1) {
				cout << "You feel a breeze go by." << endl;
			}
			else if (pit3c = col - 1) {
				cout << "You feel a breeze go by." << endl;
			}
		}
		else if (input = 2) {
			MoveDown(row, matrix, col);


		}
		else if (input = 3) {
			MoveLeft(row, matrix, col);

		}
		else if (input = 4) {
			MoveRight(row, matrix, col);

		}
	}


	return 0;
}
