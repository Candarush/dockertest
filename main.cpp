#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    cout<<"Hello SFML!"<<endl;
    
    sf::RenderWindow window(sf::VideoMode(300, 300), "RoboDodge");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }
        
        RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(100, 50));
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setOutlineThickness(5);
        rectangle.setPosition(10, 20);
        
        window.clear();
        
        window.draw(rectangle);
        
        window.display();
    }
    return 0;
}
