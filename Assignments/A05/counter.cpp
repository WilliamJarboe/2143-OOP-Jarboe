#include <SFML/Graphics.hpp>
#include <iostream>

// https://www.sfml-dev.org/tutorials/2.5/system-time.php

using namespace std;

class Counter {
	// Your awesomeness here...
	private:
		bool decrementing;
		bool isInfinite;
		sf::Clock clock;
		sf::Time start;
		sf::Time end;
		sf::Time elapsed;
		bool reachedEnd;
	public:
		Counter(int secondsStart, int secondsEnd) {
			if (secondsStart>secondsEnd) {
				decrementing = true;
			}
			else { 
				decrementing = false;
			}
			start = sf::seconds(secondsStart);
			end = sf::seconds(secondsEnd);
			reachedEnd = false;
			isInfinite = false;
		}

		Counter(int secondsStart, int secondsEnd, bool infinite) {
			if (secondsStart>secondsEnd) {
				decrementing = true;
			}
			start = sf::seconds(secondsStart);
			end = sf::seconds(secondsEnd);
			reachedEnd = false;
			isInfinite = infinite;
		}

		int calculateTime()
		{
			elapsed = clock.getElapsedTime();

			if (!decrementing) {
				if ((start + elapsed).asSeconds() == end.asSeconds()) {
					reachedEnd = true;
				}
				return start.asSeconds() + elapsed.asSeconds();
			}
			if ((start - elapsed).asSeconds() == end.asSeconds()) {
				reachedEnd = true;
			}
			return start.asSeconds() - elapsed.asSeconds();
		}


		int getTimeSeconds()
		{
			return calculateTime();
		}

		void resetTimer() {
			clock.restart();
		}
	
		bool hasReachedEnd() {
			return reachedEnd;
		}

};


int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	/*sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	start = sf::seconds(50);
	end = sf::seconds(50);*/

	Counter c = Counter(10,15);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		cout << "Incrementing Clock: " << c.getTimeSeconds() << endl;

		if (c.hasReachedEnd())
		{
			window.close();
		}

		window.clear();
		//window.draw(shape);
		window.display();
	}

	return 0;
}
