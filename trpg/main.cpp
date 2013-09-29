#include <SFML/Graphics.hpp>
#include "Combat.h"

using namespace TRPG;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


	Guerrier battler("Jack");
	Empereur emp("Mark");

	battler.affiche();
	emp.affiche();
	Map carto;
	carto.initializeMap();
	carto.ajouterCombattant(&battler, 5,8);
	carto.ajouterCombattant(&emp, 6,12);
	carto.afficheMap();

	Team equipe;
	equipe.ajoutHeros(&battler);
	equipe.affiche();

	Combat battle(&equipe);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}