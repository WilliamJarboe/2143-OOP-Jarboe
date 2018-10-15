/*Auth: William Jarboe
*-Course: CMPS 2143 - OOP
*-ver: 1.0 10/14/18
*-Github located at https://github.com/WilliamJarboe/2143-OOP-Jarboe
*/
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
// better way of handling frames per second
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace sf;

const int FRAMERATE = 1;

struct GOLCell {
	bool alive;
	bool nextState;
	RectangleShape Rect;
	int w;
	int h;

	GOLCell() {
		w = 10;
		h = 10;

		//gol cell graphics stuff
		Rect.setSize(sf::Vector2f(w, h));
		Rect.setFillColor(Color::Blue);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
		alive = 0;
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*w, y*h);
	}
};

struct GameOfLife {
	//integer declarations
	int w;
	int h;
	int iterations;
	int arrayRow;
	int arrayColumn;

	//game of life stuff
	GOLCell** thegame;
	RenderWindow Window;

	//constructor
	GameOfLife(int width, int height) {

		w = width + 1;
		h = height + 1;
		//we multiply the width and height by the cell size to show the whole window
		Window.create(VideoMode(w * 10, h * 10), "Game of Life! remixed by William Jarboe");
		thegame = new GOLCell*[w];
		for (int i = 0; i < w; i++) {
			thegame[i] = new GOLCell[h];
			for (int j = 0; j < h; j++) {
				thegame[i][j].setCellPos(i, j);
			}
		}
	}
	void drawthegame();
	void osmoseData(std::ifstream&infile);
	int countAdjacent(int i, int j);
	void generateNext();
	void printToFile(std::ofstream & outfile);
};

//main driver loop.
//command line args: infilename.txt 1000
int main(int argc, char **argv) {
	//file operations
	std::ifstream infile;
	std::ofstream outfile;
	outfile.open(argv[2]);
	infile.open(argv[1]);

	//3rd parameter is 1000
	int numberofIterations = std::stoi(argv[3]);

	//create GOL
	GameOfLife Gol(50, 40);
	Gol.iterations = 1;

	//print header
	outfile << "Auth: William Jarboe\n"
		<< "Ver: 1.0 10/14/18\n"
		<< "2143 - OOP \n\n\n";

	//read in data
	Gol.osmoseData(infile);
	//main driver loop
	while (Gol.iterations < numberofIterations)
	{
		//draw to screen
		Gol.drawthegame();
		Gol.generateNext();

		//implementation of the thread sleep method
		//i first used this method 4 years ago in java
		std::this_thread::sleep_for(std::chrono::milliseconds(12));

		std::cout << "\nIteration count: " << Gol.iterations;
		Gol.iterations++;
	}
	Gol.Window.close();
	//print to the outfile
	Gol.printToFile(outfile);
	infile.close();
	outfile.close();
	return 0;
}
//draw one iteration of the world
void GameOfLife::drawthegame() {
	Window.clear();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (thegame[i][j].alive) {
				Window.draw(thegame[j][i].Rect);
			}
		}
	}
	Window.display();
}

//read in the data from the file.
//param: std::ifstream
void GameOfLife::osmoseData(std::ifstream& infile) {
	std::string line = "";
	//the rows and columns for the program
	infile >> arrayRow >> arrayColumn;
	//traverse 2d array and input data
	for (int i = 0; i < arrayRow; i++) {
		infile >> line;

		for (int j = 0; j < arrayColumn; j++)
			// -48 for ascii offset
			thegame[i][j].alive = line[j] - 48;
	}
}

//count neighbors of this cell in specific
int GameOfLife::countAdjacent(int i, int j) {
	int neighbors = 0;
	//cycle through each nearby cell
	//the letter 'r' before each one signifies it is a relative value
	for (int ry = j - 1, rx = i - 1; rx <= i + 1; rx++) {
		if (rx >= 0 && rx < h && ry >= 0 && ry < w) {
			if (thegame[rx][ry].alive)
				neighbors += 1;
		}
	}
	for (int ry = j + 1, rx = i - 1; rx <= i + 1; rx++) {
		if (rx >= 0 && rx < h && ry >= 0 && ry < w) {
			if (thegame[rx][ry].alive)
				neighbors += 1;
		}

	}
	for (int ry = j, rx = i - 1; rx <= i + 1; rx++) {
		if (rx >= 0 && rx < h && ry >= 0 && ry < w && rx != i) {
			if (thegame[rx][ry].alive)
				neighbors += 1;
		}
	}
	//return total neighbors of this cell
	return neighbors;
}

//cycles through a single update
void GameOfLife::generateNext() {
	//need to save neighbors per cell to do algos on that number later
	int neighbors = 0;
	//2d array traversal
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			//for each cell, find neighbor
			neighbors = countAdjacent(i, j);
			//do ops on it
			if (thegame[i][j].alive) {
				if (neighbors < 2 || neighbors>3) {
					thegame[i][j].nextState = false;
				}
			}
			else {

				if (neighbors == 3) {
					thegame[i][j].nextState = true;
				}
				else {
					thegame[i][j].nextState = false;
				}
			}
		}
	}
	/*up until now, all updates have been stored in a boolean saved in each cell, as to
	*-not tamper with the cell's actual active state. now,
	*-we can apply updates all at once without having to worry about it.
	*/
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			//update cell
			thegame[i][j].alive = thegame[i][j].nextState;
		}
	}
}

/*prints the whole world to the output file specified
*-param: std::ofstream
*-return: void
*/
void GameOfLife::printToFile(std::ofstream & outfile)
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			//booleans print as if they were 0's and 1's
			outfile << thegame[i][j].alive;
		}
		outfile << std::endl;
	}
}

