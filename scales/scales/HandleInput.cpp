#include "HandleInput.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

void  HandleInput::handleInput()
{
    while (1)
    {
        string line;

        getline(std::cin, line);
        if (!std::cin)
        {
            if (!std::cin.eof())
            {
                cerr << "cin failure: cannot build scale tree" << endl;
                abort();
            }
        }
        if (line.size() && line[0] == '#')
        {
            // ignore comment
        }
        else if (line.size())
        {
            // parse line comma seperated
            std::vector<string> vec = parseTokens(line);
            if (vec.size() != 3)
            {
                cerr << "bad input cannot build scale tree: " << line << endl;
                abort();
            }
            else
            {
                Scale node;
                
                string scaleName = vec[0];
                node.name = scaleName;

                string left = vec[1];
                
                if (isdigit(left[0]))
                {
                    // it is a weight
                    node.leftPanWeight = stoi(left);
                }
                else
                {
                    // it is a scale
                    node.leftPanScaleName = left;
                }
                string right = vec[2];
                if (isdigit(right[0]))
                {
                    // it is a weight
                    node.rightPanWeight = stoi(right);
                }
                else
                {
                    // it is a scale
                    node.rightPanScaleName = right;
                }

                if (node.leftPanScaleName.empty() && node.rightPanScaleName.empty())
                {
                    // balence it now
                    if (node.leftPanWeight > node.rightPanWeight)
                    {
                        node.addRight = node.leftPanWeight - node.rightPanWeight;
                    }
                    else if (node.rightPanWeight > node.leftPanWeight)
                    {
                        node.addLeft = node.rightPanWeight - node.leftPanWeight;
                    }
                    node.isBalenced = true;
                }
                _scales[node.name] = node;
                _order.push_back(node.name);
            }
        }
    }
}

std::vector<string> HandleInput::parseTokens(string& line)
{
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string token;
    while (getline(ss, token, ','))
    {
        result.push_back(token);
    }
    return result;
}

vector<string> HandleInput::getOrder()
{
    return  _order;
}

std::unordered_map<std::string, Scale> HandleInput::getScales()
{
    return _scales;
}
