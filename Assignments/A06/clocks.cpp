//CMPS2143
//william jarboe
//bouncing clocks
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include "Group.h"

#include <ctime> 
#include <iostream> 

using namespace std;

class Counter{
private:
	//to keep track of time...
	sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	
	
public:
	//default constructor
	Counter() {
		start = sf::seconds(0);
		end = sf::seconds(0);
	}
	//start and end constructor
	Counter(int s, int e) {
		start = sf::seconds(s);
		end = sf::seconds(e);
	}

	//get duration
	int getElapsed() {
		elapsed = clock.getElapsedTime();
		//used round function to get rid of decimals
		return round(elapsed.asSeconds());
	}

	//return beginning time
	int getStart() {
		return start.asSeconds();
	}
	
	//set beginning time(but why?) 
	void setStart(int s) {
		start = sf::seconds(s);
	}

	//get ending time
	int getEnd() {
		return end.asSeconds();
	}

	//set the ending time
	void setEnd(int e) {
		end = sf::seconds(e);
	}

	//set start and ending time
	void setTimes(int s, int e) {
		start = sf::seconds(s);
		end = sf::seconds(e);
	}
};

class Clock : public sf::Text{
private:
	sf::Font font;
	float xVel, yVel;
	Counter c;
	bool increasing;

public:
	
	Clock() {
		//Out-blocked in the world of blocky letters!
		if (!font.loadFromFile("imagine_font.otf"))
			std::cout << "Could not find font\n";
		setFont(font);
		setString("FDEF now presents: H");
		setCharacterSize(18);
		setFillColor(sf::Color::Cyan);
		setPosition(150, 150);
		//I set origin later so that it doesnt get messed up.
		setOrigin(17, 7);
		xVel = .05;
		yVel = .05;
		increasing = true;
		
	}


	void setTime(int x, int y) {
		c.setStart(x);
		c.setEnd(y);
		if (x > y)
			increasing = false;
		else if (x == y)
			setString("");

		setOrigin(0,0);
	}

	//Changes the font to the specified filepath
	void newFont(string filepath) {
		if (!font.loadFromFile(filepath))
			std::cout << "Could not find font\n";
		setFont(font);
		setOrigin(0,0);
	}


	void updateText()
	{
		//Set clock to updated time
		if (increasing)
			setString("" + to_string(c.getStart() + c.getElapsed()));
		else
			setString("" + to_string(c.getStart() - c.getElapsed()));
	}

	//teleportal me to the coordinates.
	void setPos(int x, int y)
	{
		setPosition(x, y);
	}

	//are we done yet????
	bool checkClose()
	{
		if ((c.getStart() + c.getElapsed()) == c.getEnd() + 1)
			return true;
		else if ((c.getStart() - c.getElapsed()) == c.getEnd() - 1)
			return true;
		else
			return false;
	}

	//set the text color of the clock to this color
	void settextColor(sf::Color c)
	{
		setColor(c);
	}

	void settextColor(int x, int y, int z)
	{
		setColor(sf::Color(x, y, z));
	}
};
	
class ScreensaverClock : public Group {
private:
	float width;
	float height;
	float xVel;
	float yVel;
public:
	Clock clock;
	sf::RectangleShape box;
	ScreensaverClock()
	{
		
		clock.setTime(0, 100);
		box = sf::RectangleShape();

		width = 57;
		height = 29;
		box.setSize(sf::Vector2f(width, height));
		box.setOrigin(width / 2, height / 2);
		box.setFillColor(sf::Color::Transparent);
		box.setOutlineColor(sf::Color::Cyan);
		box.setOutlineThickness(2);
		box.setPosition(50, 50);
		clock.setPosition(box.getPosition().x-5, box.getPosition().y-10);

		xVel = -0.124;
		yVel = 0.062;

		push_back(box);
		push_back(clock);
	}

	void update()
	{
		pop_back();
		pop_back();
		if (box.getPosition().x >= 500 || box.getPosition().x <= 0) {
			xVel = xVel * -1;
		}
		if (box.getPosition().y >= 500 || box.getPosition().y <= 0) {
			yVel = yVel * -1;
		}
		box.move(xVel, yVel);
		clock.move(xVel, yVel);
		clock.updateText();
		push_back(box);
		push_back(clock);
	}
	//sets the time on the clock
	void setClockTime(int start, int end) {
		clock.setTime(start, end);
	}

	//Changes the font of the clock
	void setClockFont(string path) {
		clock.newFont(path);
	}
	//Changes the color of the clock
	void setClockColor(sf::Color c) {
		clock.setFillColor(c);
	}
	//sets the outline color
	void setBorderColor(sf::Color c) {
		box.setOutlineColor(c);
	}
	//edits the velocity of the clock
	void setVelocity(double nxVel, double nyVel) {
		xVel = nxVel;
		yVel = nyVel;
	}

	//edits the size of the font
	void setFontSize(int fontsize) {
		clock.setCharacterSize(fontsize);
	}

	//edits the location of the clock
	void setLoc(int x, int y) {
		box.setPosition(x, y);
		clock.setPosition(x, y);
	}
};


int main()
{
	ScreensaverClock A;
	ScreensaverClock B;
	ScreensaverClock C;
	
	A.setClockFont("Segment7Standard.otf");
	A.setClockColor(sf::Color::Magenta);
	A.setBorderColor(sf::Color::Blue);
	A.setVelocity(0.04, 0.05);
	A.setClockTime(80, 30);
	
	B.setClockFont("Open 24 Display St.ttf");
	B.setClockColor(sf::Color::Green);
	B.setBorderColor(sf::Color::Red);
	B.setVelocity(0.08, -0.14);
	B.setClockTime(30, 45);

	C.setClockFont("imagine_font.otf");
	C.setClockColor(sf::Color::Yellow);
	C.setBorderColor(sf::Color::White);
	C.setVelocity(0.01, 0.04);
	C.setClockTime(0, 99);

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	 while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
        window.clear();
        window.draw(A);
		window.draw(B);
		window.draw(C);
        window.display();
		A.update();
		B.update();
		C.update();
		if (A.clock.checkClose())
			window.close();

    }
	return 0; 
}
