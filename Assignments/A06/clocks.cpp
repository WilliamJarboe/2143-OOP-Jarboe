//William jarboe
//11/12/2014
//Github: https://github.com/WilliamJarboe/2143-OOP-Jarboe/tree/master/Assignments
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Group.h"
// https://www.sfml-dev.org/tutorials/2.5/system-time.php

using namespace std;

//Clock that keeps track of time, and utilizes SFML
class Clock : public sf::Text {
private:
	Counter ref;//needs to keep track of eachother
				//SFML stuff!!!
				//speed in x and y axis
	int xVel, yVel;
	float w, h;
	//size to draw in
	int drawSize;
	sf::Color fillColor;
	bool countUp;
public:
	Clock()
	{
		//set color
		fillColor = sf::Color::White;
		//This is where my program crashes on my home machine, but not in the lab.
		//load font
		//https://www.dafont.com/imagine-font.font
		sf::Font f;
		if (!f.loadFromFile("IMAGINE.ttf")) {
			std::cout << "Could not find font\n";
		}
		setFont(f);
		setFillColor(fillColor);
		//determine if we are counting up or down
		countUp = true;
		setCharacterSize(drawSize);
		setString("the h squad despises your functionality and praises your patience");
		drawSize = 14;
		xVel = .024;
		yVel = .024;
		setPosition(200, 200);
		setOrigin(getLocalBounds().width / 2, getLocalBounds().height / 2);


	}

	void shiftClock()
	{
		//update clock time
		setString("" + (ref.getStart() + ref.getElapsed()));
		//shift the clock
		int xpos = getPosition().x;
		int ypos = getPosition().y;
		if (xpos + (w / 2) >= 600 || xpos - (w / 2) <= 0)
			xVel = -1 * yVel;
		if (ypos + (h / 2) >= 400 || ypos - (h / 2) <= 0)
			yVel = -1 * yVel;
		move(xVel, yVel);
	}
	//changes the Textcoor of the clock (requirements)
	void setTextColor(sf::Color newTextcolor) {
		setFillColor(newTextcolor);
		fillColor = newTextcolor;
	}
	//get text color
	//can be used to make clock change color rapidly on a variable gradient
	sf::Color getTextColor() {
		return fillColor;
	}

	void setTime(int s, int e) {
		ref.setBeginTime(s);
		ref.setEnd(e);
		if (s > e) {
			countUp = false;
		}
		setString("" + s);
	}
	//function to make timer infinite. for all
	//PRACTICAL uses...
	void setTimetoInfinite(int s) {
		ref.setBeginTime(s);
		ref.setEnd(9999999);
	}
	//shift position (requirements)
	void setPosition(int x, int y) {
		setPosition(x, y);
	}
};
//this is the rectangle behind the clock. I decided to make it take the clock with it.
class ClockBackground : public sf::RectangleShape {
private:
	int w;
	int h;
	int xVel, yVel;
public:
	//default constructor
	ClockBackground() {
		xVel = .024;
		yVel = .024;
	}
	//parameterized constructor
	//accepts sf::Text
	//we use this one.
	ClockBackground(sf::Text text)
	{
		w = text.getLocalBounds().width;
		h = text.getLocalBounds().height;
		xVel = .024;
		yVel = .024;
		//someone needs to write an int version
		setSize(sf::Vector2f(w, h));
		//color settings
		setFillColor(sf::Color::Black);
		setOutlineColor(sf::Color::Magenta);
		setPosition(text.getPosition().x, text.getPosition().y);
	}
	//shift the background (requirements)
	void shiftBG()
	{
		//We're a background. we don't need to edit our text.
		int xpos = getPosition().x;
		int ypos = getPosition().y;
		if (xpos + (w / 2) >= 600 || xpos - (w / 2) <= 0)
			xVel = -1 * yVel;
		if (ypos + (h / 2) >= 400 || ypos - (h / 2) <= 0)
			yVel = -1 * yVel;
		move(xVel, yVel);
	}
	//edit function for background fill color (requirements)
	void setBGColor(sf::Color newColor) {
		setFillColor(newColor);
	}
	//edit function for background border color (requirements)
	void setBGBorder(sf::Color newColor) {
		setOutlineColor(newColor);
	}
	//edit position (requirements)
	void setPosition(int x, int y) {
		setPosition(x, y);
	}
};

//Essentially, what this class does is it keeps track of the Clock's start and end for it.
//It doesn't do any of the actual counting. It also doesn't interact with SFML really.
class Counter {
private:
	//clock to use for keeping track of time elapsed.
	sf::Clock clock;
	//beginning time, in seconds.
	sf::Time sbegin;
	//ending time, in seconds.
	sf::Time send;
public:
	//default constructor
	Counter() {
		sbegin = sf::seconds(0);
		send = sf::seconds(0);
	}
	//start and end params
	Counter(int start, int endd) {
		sbegin = sf::seconds(start);
		send = sf::seconds(endd);
	}
	//start counter, make it infinite
	Counter(int start) {
		sbegin = sf::seconds(start);
		send = sf::seconds(9999999);
	}
	//You should never have to use this
	//Changes the end of the timer.
	void setEnd(int newEnding)
	{
		send = sf::seconds(newEnding);
	}
	//You should never have to use this
	//changes the start of the timer.
	void setBeginTime(int x)
	{
		sbegin = sf::seconds(x);
	}

	//returns ending time as an integer
	int getEnd()
	{
		return send.asSeconds();
	}
	//Returns elapsed time as integer
	int getElapsed() {
		return round(clock.getElapsedTime().asSeconds());
	}
	//returns the starting time
	int getStart() {
		return sbegin.asSeconds();
	}
};

//Driver loop
int main()
{
	Group giantGroup;
	Clock clock1;
	//set clock time
	clock1.setTimetoInfinite(0);
	//add the clock inswide its background rectangle
	ClockBackground BG(clock1);

	//make window
	sf::RenderWindow window(sf::VideoMode(400, 600), "B  O  N  C  C");
	//mail driver loop
	//me and evan had a study group together
	while (window.isOpen())
	{
		//since it thinks it's static, i have to
		//make it think it still is static by changing it.
		giantGroup.push_back(BG);
		//be wary of draw order
		giantGroup.push_back(clock1);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//be wary of order
		window.clear();
		window.draw(giantGroup);
		window.display();
		giantGroup.pop_back();
		giantGroup.pop_back();
		clock1.shiftClock();
	}

	//NORMALLY close files... but nothing to close.
	return 0;
}
