#include <SFML/Graphics.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>

#include <iostream>

using namespace std;
using namespace sf;
using namespace cv;

int main()
{
    cout<<"Hello SFML!"<<endl;
    
    Mat3b GreenBox(400, 100, Vec3b(0,255,0));
    imshow("OpenCV", GreenBox);
    
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML");
    
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
