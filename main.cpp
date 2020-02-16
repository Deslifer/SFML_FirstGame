#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void main() {

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	window.setFramerateLimit(120);

	//sf::CircleShape shape(20.f);
	//shape.setFillColor(sf::Color::Green);
	sf::Texture texture;
	texture.loadFromFile("C:/Users/kolmi/source/repos/SFML_FirstGame/Release/smile.png");
	sf::Sprite sprite(texture);
	sprite.setPosition(100, 100);
	sprite.setColor(sf::Color::Green);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	sprite.setScale(1.7f, 1.7f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyReleased) {
				sprite.setColor(sf::Color::Green);
			}
			if (event.type == sf::Event::KeyPressed) {
				sprite.setColor(sf::Color::Red);
				switch (event.key.code) {
				case sf::Keyboard::Key::Left:
					sprite.move(-10, 0);
					break;
				case sf::Keyboard::Key::Right:
					sprite.move(10, 0);
					break;
				case sf::Keyboard::Key::Up:
					sprite.move(0, -10);
					break;
				case sf::Keyboard::Key::Down:
					sprite.move(0, 10);
					break;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				sprite.setColor(sf::Color::Red);
				sprite.setPosition(event.mouseButton.x, event.mouseButton.y);
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				sprite.setColor(sf::Color::Green);
			}
		}

		sprite.move(0.1f, 0.f);

		window.clear();
		window.draw(sprite);
		window.display();
	}
}