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

const int MSPERFRAME = 5;

struct GOLCell {
	bool isAlive;
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
		Rect.setOutlineThickness(2);
		isAlive = 0;
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
	GOLCell** World;
	RenderWindow Window;

	//constructor
	GameOfLife(int width, int height) {

		w = width+1;
		h = height+1;

		Window.create(VideoMode(w*10, h*10), "Game of Life! remixed by William Jarboe");
		World = new GOLCell*[w];
		for (int i = 0; i < w; i++) {
			World[i] = new GOLCell[h];
			for (int j = 0; j < h; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}
	void drawWorld();
	void osmoseData(std::ifstream&infile);
	int checkNeighbors(int i, int j);
	void updateWorld();
	void printWorld(std::ofstream & outfile);
};


int main(int argc, char **argv) {
	//file operations
	std::ifstream infile;
	std::ofstream outfile;
	outfile.open(argv[2]);
	infile.open(argv[1]);

	//3rd parameter is 1000
	int numberofIterations = std::stoi(argv[3]);

	//create GOL
	GameOfLife Gol(50,40);
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
		Gol.drawWorld();
		Gol.updateWorld();

		//implementation of the thread sleep method
		//i first used this method 4 years ago in java
		std::this_thread::sleep_for(std::chrono::milliseconds(MSPERFRAME));
		
		std::cout << "\nIteration count: " << Gol.iterations;
		Gol.iterations++;
	}
	Gol.Window.close();
	//print to the outfile
	Gol.printWorld(outfile);
	infile.close();
	outfile.close();
	return 0;
}

	void GameOfLife::drawWorld() {
		Window.clear();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (World[i][j].isAlive) {
					Window.draw(World[j][i].Rect);
				}
			}
		}
		Window.display();
	}

	
	void GameOfLife::osmoseData(std::ifstream& infile) {
		std::string line = "";
		infile >> arrayRow >> arrayColumn;

		for (int i = 0; i < arrayRow; i++) {
			infile >> line;

			for (int j = 0; j < arrayColumn; j++)
				// -48 for ascii offset
				World[i][j].isAlive = line[j] - 48;
		}
	}


	int GameOfLife::checkNeighbors(int i, int j) {
		int neighbors = 0;
			for (int ry = j - 1, rx = i - 1; rx <= i + 1; rx++) {
				if (rx >= 0 && rx < h && ry >= 0 && ry < w) {
					if (World[rx][ry].isAlive)
						neighbors += 1;
				}
			}
			for (int ry = j + 1, rx = i - 1; rx <= i + 1; rx++) {
				if (rx >= 0 && rx < h && ry >= 0 && ry < w) {
					if (World[rx][ry].isAlive)
						neighbors += 1;
				}

			}
			for (int ry = j, rx = i - 1; rx <= i + 1; rx++) {
				if (rx >= 0 && rx < h && ry >= 0 && ry < w && rx != i) {
					if (World[rx][ry].isAlive)
						neighbors += 1;
				}
			}
			return neighbors;
	}

	/*cycles through a single update
	*-
	*/
	void GameOfLife::updateWorld() {
		int neighbors = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				neighbors = checkNeighbors(i,j);
				if (World[i][j].isAlive) {
					if (neighbors < 2 || neighbors>3) {
						World[i][j].nextState = false;
					}
				}
				else {
					
					if (neighbors == 3) {
						World[i][j].nextState = true;
					}
					else {
						World[i][j].nextState = false;
					}
				}
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				World[i][j].isAlive = World[i][j].nextState;
			}
		}
	}

	/*prints the whole world to the output file specified
	*-param: std::ofstream
	*-return: void
	*/
	void GameOfLife::printWorld(std::ofstream & outfile)
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				//booleans print as if they were 0's and 1's
				outfile << World[i][j].isAlive;
			}
			outfile << std::endl;
		}
	}

