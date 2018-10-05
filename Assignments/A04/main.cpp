#include <SFML/Graphics.hpp>

using namespace sf;

struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	golCell() {
		Width = 12;
		Height = 12;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Blue);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(2);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	int frameCount;
	int frameRate;
	RenderWindow Window;
	golCell** World;
	gameOfLife(int width, int height, int framerate) {
		Width = width;
		Height = height;
		frameRate = framerate;
		Window.create(VideoMode(Width, Height), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i<height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j<width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}

	void drawWorld() {
		Window.clear();
		for (int i = 0; i<Height; i++) {
			for (int j = 0; j<Width; j++) {
				Window.draw(World[i][j].Rect);
			}
		}
		Window.display();
	}
};



int main() {

	gameOfLife Gol(1000, 1000, 30);

	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event))
		{
			//hey here's the code i edited
			if (Gol.frameCount%Gol.frameRate==0) {
				Gol.drawWorld();
				if (event.type == Event::Closed)
					Gol.Window.close();

			}
			Gol.frameCount++;
		}


	}

	return 0;
}
