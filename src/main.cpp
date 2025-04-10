#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Card.h"

int main()
{
    ///Setting up the main window
    srand(time(0));
    sf::VideoMode videoMode(sf::Vector2u(720u, 420u), 32u);
    sf::RenderWindow window(videoMode, "Bouncing Ball");
    window.setFramerateLimit(60);

    /// Object creation of the ball and paddle
    /// Param for paddle: (length, height) relative to pixels
    Paddle paddle1;
    paddle1.setKeys(sf::Keyboard::Key::W,sf::Keyboard::Key::S);

    paddle1.setPosition({50,50});
    paddle1.setFillColor(sf::Color::White);

    Paddle paddle2;
    paddle2.setKeys(sf::Keyboard::Key::Up,sf::Keyboard::Key::Down);
    paddle2.setPosition({600,50});

    ///Creation of a vector of object bs to hold multiple balls and make object creation easier
    ///Here 5 balls are created and their sizes are randomized followed by random velocitys
    ///and random colors
    std::vector<Ball> bs;
    for (int i=0; i<5; i++)
    {
        bs.emplace_back(static_cast<float>(rand() % (100 - 25 + 1) + 25));
        float f = rand() % 5 + 1;
        bs.back().setVelocity({f, f});
        bs.back().setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    }
    ///Card drawing
    sf::Texture texture;
	texture.loadFromFile("src/images/cards.jpg");
    ///GUI Window
	Card card(texture);
    ///GUI Window
    sf::Vector2u winSize = window.getSize();
    while (window.isOpen())
    {

        /// Event Listener
        while (auto event = window.pollEvent())
        {

            /// Event Handling
            if (event->getIf<sf::Event::Closed>())
            {
                window.close();
            }


        }

        paddle1.handleEvent(window);
        paddle2.handleEvent(window);

        ///Prompting our 5 ball objects to bounce
        /// using bounce function
        /// param: windowsize for making sure ball objects stay within the window
        for (auto & ball : bs)
            ball.bounce(winSize);

        window.clear();
        ///Drawing our objects within the window for loop for the multiple ball objeects
        for (auto & ball : bs)
            window.draw(ball);

        window.draw(paddle1);
        window.draw(paddle2);
        window.display();
    }
    return 0;
}