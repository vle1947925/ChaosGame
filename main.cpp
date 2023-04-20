// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;

int main()
{
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;
	width = 800; height = 600;
	// Create a video mode object
	VideoMode vm(width, height);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	vector<Vector2f> vertices;
	vector<Vector2f> points;

	Font f;
	if (!f.loadFromFile("KOMIKAP_.ttf")) cout << "failed to load font..." << endl;
	Text instructions;
	instructions.setFont(f);
	instructions.setCharacterSize(24);
	instructions.setFillColor(Color::Green);

	int c1_x;
	int c1_y;
	int c2_x;
	int c2_y;
	int c3_x;
	int c3_y;
	int pt4_x;
	int pt4_y;
	int count = 0;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{

					if (count <= 3)
					{
						std::cout << "the right button was pressed" << std::endl;
						std::cout << "mouse x: " << event.mouseButton.x << std::endl;
						std::cout << "mouse y: " << event.mouseButton.y << std::endl;
						vertices.push_back({ (float)event.mouseButton.x, (float)event.mouseButton.y });
						if (count == 0)
						{
							c1_x = vertices.at(0).x;
							c1_y = vertices.at(0).y;
							count++;
						}
						else if (count == 1)
						{
							c2_x = vertices.at(1).x;
							c2_y = vertices.at(1).y;
							count++;
						}
						else if (count == 2)
						{
							c3_x = vertices.at(2).x;
							c3_y = vertices.at(2).y;
							count++;
						}
						else if (count == 3)
						{
							pt4_x = vertices.at(3).x;
							pt4_y = vertices.at(3).y;
							count++;
						}

					}




				}
			}

		}
		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*****************************************
			Update the scene
		*****************************************/
		//generate interior points

		ostringstream oss;
		oss << "Click stuff and \n" << "I will write stuff";
		instructions.setString(oss.str());

		FloatRect textRect = instructions.getLocalBounds();
		instructions.setOrigin(textRect.left +
			textRect.width / 2.0f,
			textRect.top +
			textRect.height / 2.0f);

		instructions.setPosition(width / 2, 50);

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last run frame
		//window.clear();

		// Draw our game scene here
		//RectangleShape r{ Vector2f{4,4} }; ///width, height.  Center uninitialized

		CircleShape r(2);
		r.setFillColor(Color::Magenta);

		int randNum;



		for (size_t i = 0; i < vertices.size(); i++)
		{

			r.setPosition(Vector2f{ vertices.at(i).x, vertices.at(i).y });
			//cout << "Current point is " << vertices.at(i).x << ", " << vertices.at(i).y << "." << endl;
			window.draw(r);

		}

		if (vertices.size() == 4)
		{

			randNum = rand() % 3;
			if (randNum == 0)
			{

				r.setPosition(Vector2f{ float(pt4_x + c1_x) / 2, float(pt4_y + c1_y) / 2 });
				pt4_x = (pt4_x + c1_x) / 2;
				pt4_y = (pt4_y + c1_y) / 2;
				window.draw(r);
			}
			else if (randNum == 1)
			{
				r.setPosition(Vector2f{ float(pt4_x + c2_x) / 2, float(pt4_y + c2_y) / 2 });
				pt4_x = (pt4_x + c2_x) / 2;
				pt4_y = (pt4_y + c2_y) / 2;
				window.draw(r);
			}
			else if (randNum == 2)
			{
				r.setPosition(Vector2f{ float(pt4_x + c3_x) / 2, float(pt4_y + c3_y) / 2 });
				pt4_x = (pt4_x + c3_x) / 2;
				pt4_y = (pt4_y + c3_y) / 2;
				window.draw(r);
			}



		}




		window.draw(instructions);
		// Show everything we just drew
		window.display();




	}

	return 0;
}
