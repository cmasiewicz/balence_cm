// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Scale.h"
#include "HandleInput.h"
#include "BalenceScales.h"

using namespace std;

int main()
{
   /*
   Example Input
        #ScaleName, Left, Right
        B1, 10, B2
        B2, B3, 4
        B3, 7, 8
        */
    HandleInput input;
    input.handleInput();
    BalenceScales scales(input.getScales(), input.getOrder());

}
