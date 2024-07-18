// IAFPS PROJECT PROTOTYPE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Application.hpp"


int main()
{
    Application app;
    app.initialize();
    app.run();

    return 0;
}

