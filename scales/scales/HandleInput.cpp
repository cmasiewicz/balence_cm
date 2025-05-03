#include "HandleInput.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

void  HandleInput::handleInput()
{
    while (!cin.eof())
    {
        string line;

        getline(cin, line);

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
                ScalePtr node = make_shared<Scale>();
               

                string scaleName = vec[0];
                node->name = scaleName;

                string left = vec[1];

                if (isdigit(left[0]))
                {
                    // it is a weight
                    node->leftPan.setMass(stoi(left));
                }
                else
                {
                    // it is a scale
                    node->leftPan.aboveScaleName = left;
                }
                string right = vec[2];
                if (isdigit(right[0]))
                {
                    // it is a weight
                    node->rightPan.setMass(stoi(right));
                }
                else
                {
                    // it is a scale
                    node->rightPan.aboveScaleName = right;
                }

                if (node->leftPan.aboveScaleName.empty() && node->rightPan.aboveScaleName.empty())
                {
                    // balence it now
                    if (node->leftPan.getTotalMass() > node->rightPan.getTotalMass())
                    {
                        node->rightPan.addMass(node->leftPan.getTotalMass() - node->rightPan.getTotalMass());
                    }
                    else if (node->rightPan.getTotalMass() > node->leftPan.getTotalMass())
                    {
                        node->leftPan.addMass(node->rightPan.getTotalMass() - node->leftPan.getTotalMass());
                    }

                }

                _scales[node->name] = node;
                _order.push_back(node->name);
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

std::unordered_map<std::string, ScalePtr> HandleInput::getScales()
{
    return _scales;
}
