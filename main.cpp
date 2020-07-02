#include <SFML/Graphics.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace sf;
using namespace cv;

bool nextFrame = true;

int main()
{
    cout<<"Hello SFML!"<<endl;
    
    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML");
    
    VideoCapture cap("BallTestLine.mp4");

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;

    Mat frameRGB;

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
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                if (event.key.code == sf::Keyboard::Up)
                    nextFrame = true;
            }
        }

        RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(100, 50));
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setOutlineThickness(5);
        rectangle.setPosition(10, 20);
        Mat frameRGBA;
        
        if (nextFrame)
        {
            cap >> frameRGB;
            nextFrame = false;
        }
        
        if(frameRGB.empty())
        {
            cout<<"Видео закончилось."<<endl;
            window.close();
        }
        
        cv::cvtColor(frameRGB, frameRGBA, cv::COLOR_BGR2RGBA);
        
        image.create(frameRGBA.cols, frameRGBA.rows, frameRGBA.ptr());

        if (!texture.loadFromImage(image))
        {
            cout<<"Ошибка"<<endl;
            return -2;
        }

        sprite.setTexture(texture);
        sprite.setPosition(500,0);

        window.clear();

        window.draw(rectangle);
        
        window.draw(sprite);

        window.display();
    }
    
    
    return 0;
}
