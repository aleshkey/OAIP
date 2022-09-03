#include <SFML/Graphics.hpp>
#include <string>
#include <Windows.h>
#include <sstream>
using namespace sf;
int main()
{
	int nowx = 175, nowy = 0, w = 500, step=10;
	RenderWindow window(VideoMode(w, 85), "animation");
	bool posicion = true;
	while (window.isOpen()) {
		std::string path;
		if (posicion) {
			path = "D:/oaip/1.png";
		}
		else {
			path = "D:/oaip/-1.png";
		}
		Texture Picture;
		Picture.loadFromFile(path);
		Sprite Sprite1(Picture);
		window.clear(Color::White);
		Sprite1.setPosition(nowx, nowy);
		window.draw(Sprite1);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
				for (int i = 2; i < 6; i++) {
					std::stringstream ss;
					ss << i;
					std::string str = ss.str();
					std::string path = "D:/oaip/" + str + ".png";
					Texture Picture;
					Picture.loadFromFile(path);
					Sprite Sprite1(Picture);
					nowx += step;
					Sprite1.setPosition(nowx, nowy);
					sf::Event event;
					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							window.close();
					}

					window.clear(Color::White);
					window.draw(Sprite1);
					window.display();
					Sleep(150);
					window.clear(Color::White);
				}
				posicion = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			for (int i = 2; i < 6; i++) {
				std::stringstream ss;
				ss << i;
				std::string str = ss.str();
				std::string path = "D:/oaip/-" + str + ".png";
				Texture Picture;
				Picture.loadFromFile(path);
				Sprite Sprite1(Picture);
				nowx -= step;
				Sprite1.setPosition(nowx, nowy);
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}

				window.clear(Color::White);
				window.draw(Sprite1);
				window.display();
				Sleep(150);
				window.clear(Color::White);
				posicion = false;
			}
		}
	}
	return 0;
}