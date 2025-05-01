#ifndef SCALE_H
#define SCALE_H

#include <string>

struct Scale
{
    std::string name;
    unsigned rightPanWeight = 0;
    unsigned rightAbovePanWeight = 0;
    unsigned addRight = 0;
    std::string rightPanScaleName;

    unsigned leftPanWeight = 0;
    unsigned addLeft = 0;
    std::string leftPanScaleName;
    unsigned leftAbovePanWeight = 0; 
    bool isBalenced = false;
    unsigned scaleWeight = 1;
    unsigned GetTotalWeight() const
    {
        return scaleWeight + rightPanWeight + addRight + rightAbovePanWeight 
            + leftPanWeight + addLeft + leftAbovePanWeight;

    }

};
#endif