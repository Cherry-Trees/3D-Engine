#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.hpp"
#include "HalfEdge.hpp"
#include "utils.hpp"

int main()
{
    const unsigned WINDOW_WIDTH = 1200;
    const unsigned WINDOW_HEIGHT = 1200;
    const float FOV = PI / 2.f;

    Cube cube1;
    Cube cube2;
    Cube cube3;

    Mesh meshArray[] = {
        cube1,
        cube2,
        cube3
    };

    for (auto &&entry : cube1.map()) {
        entry.key->coordinate
            // .translate({-0.5f, -0.5f, 0.f})
            // .scale({2.f, 1.f, 1.f})
            .rotateX(1.2f)
            .rotateY(0.5f)
            .rotateZ(0.9f)
            .translate({1.f, 0.f, 2.5f})
            .project(WINDOW_WIDTH, WINDOW_HEIGHT, FOV)
            .translate({1.f, 1.f, 0.f})
            .scale({0.5f * WINDOW_WIDTH, 0.5f * WINDOW_HEIGHT, 1.f});
    }

    for (auto &&entry : cube2.map()) {
        entry.key->coordinate
            // .translate({-0.5f, -0.5f, 0.f})
            .scale({2.f, 1.f, 1.f})
            .rotateX(.2f)
            .rotateY(-1.2f)
            .rotateZ(1.6f)
            .translate({-2.5f, -0.4f, 4.5f})
            .project(WINDOW_WIDTH, WINDOW_HEIGHT, FOV)
            .translate({1.f, 1.f, 0.f})
            .scale({0.5f * WINDOW_WIDTH, 0.5f * WINDOW_HEIGHT, 1.f});
    }

    for (auto &&entry : cube3.map()) {
        entry.key->coordinate
            // .translate({-0.5f, -0.5f, 0.f})
            // .scale({2.f, 1.f, 1.f})

            .translate({-0.7f, 0.7f, 1.5f})
            .project(WINDOW_WIDTH, WINDOW_HEIGHT, FOV)
            .translate({1.f, 1.f, 0.f})
            .scale({0.5f * WINDOW_WIDTH, 0.5f * WINDOW_HEIGHT, 1.f});
    }
    

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        

        window.clear();
        for (auto &&mesh : meshArray) {
            for (auto &&entry : mesh.map()) {

                sf::Vertex line[2];
                line[0] = to_SFML_Vector2(entry.key->coordinate);

                for (auto &&adj : entry.value) {
                    line[1] = to_SFML_Vector2(adj->coordinate);
                    window.draw(line, 2, sf::Lines);
                }
            }
        }

        window.display();
    }

    return 0;
}


// TO RUN:

// g++ -I"C:\SFML-2.6.1\include" -c main.cpp -o main.o
// g++ main.o -o app.exe -L"C:\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows

// OR

// MinGW32-make compile
// MinGW32-make link

// OR

// MinGW32-make all
