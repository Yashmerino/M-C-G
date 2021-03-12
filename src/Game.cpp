#include "../headers/Game.h"

Game::Game()
{
	backgroundsTextures[0].loadFromFile("img/background.png"); //Setting backgrounds
	backgroundsTextures[1].loadFromFile("img/toolbarBg.png");
	
	for (int i = 0; i < 2; i++)
	{
		backgrounds[i].setTexture(backgroundsTextures[i]);
		backgrounds[i].setOrigin(backgrounds[i].getLocalBounds().width / 2, backgrounds[i].getLocalBounds().height / 2);
	}

	backgrounds[0].setPosition(float(480 / 2), float(640 / 2 - backgrounds[1].getTexture()->getSize().y));
	backgrounds[1].setPosition(float(480 / 2), float(640 - backgrounds[1].getTexture()->getSize().y / 2));

	cardsTextures[0].loadFromFile("img/gamecardC++.png"); //Setting cards
	cardsTextures[1].loadFromFile("img/gamecardJava.png");
	cardsTextures[2].loadFromFile("img/gamecardJS.png");
	cardsTextures[3].loadFromFile("img/gamecardPHP.png");
	cardsTextures[4].loadFromFile("img/gamecardPy.png");
	cardsTextures[5].loadFromFile("img/gamecardRy.png");
	cardsTextures[6].loadFromFile("img/gamecardDefault.png");
	cardsTextures[7].loadFromFile("img/gamecardHover.png");

	for (int i = 0; i < 6; i++)
	{
		cards[i].setTexture(&cardsTextures[6]);
		cards[11 - i].setTexture(&cardsTextures[6]);

		cards[i].setSize(sf::Vector2f(115.f, 115.f));
		cards[11 - i].setSize(sf::Vector2f(115.f, 115.f));
	}

	cards[0].setPosition(45.f, 15.f);
	cards[1].setPosition(180.f, 15.f);
	cards[2].setPosition(315.f, 15.f);
	cards[3].setPosition(45.f, 145.f);
	cards[4].setPosition(180.f, 145.f);
	cards[5].setPosition(315.f, 145.f);
	cards[6].setPosition(45.f, 275.f);
	cards[7].setPosition(180.f, 275.f);
	cards[8].setPosition(315.f, 275.f);
	cards[9].setPosition(45.f, 405.f);
	cards[10].setPosition(180.f, 405.f);
	cards[11].setPosition(315.f, 405.f);

	buttonsTextures[0].loadFromFile("img/toolbarClose.png"); //Setting buttons
	buttonsTextures[1].loadFromFile("img/toolbarCloseHover.png");
	buttonsTextures[2].loadFromFile("img/toolbarNew.png");
	buttonsTextures[3].loadFromFile("img/toolbarNewHover.png");

	buttons[0].setTexture(&buttonsTextures[0]);
	buttons[1].setTexture(&buttonsTextures[2]);

	buttons[0].setSize(sf::Vector2f(60.f, 60.f));
	buttons[1].setSize(sf::Vector2f(130.f, 70.f));

	for (int i = 0; i < 2; i++)
		buttons[i].setOrigin(buttons[i].getLocalBounds().width / 2, buttons[i].getLocalBounds().height / 2);

	buttons[0].setPosition(420.f, 585.f);
	buttons[1].setPosition(240.f, 585.f);

}

Game::~Game()
{

}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(480, 640), "Pexeso");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//

		window.clear(sf::Color::White);
		for (int i = 0; i < 2; i++)
			window.draw(backgrounds[i]);
		for (int i = 0; i < 12; i++)
			window.draw(cards[i]);
		for (int i = 0; i < 2; i++)
			window.draw(buttons[i]);
		window.display();
	}
}
