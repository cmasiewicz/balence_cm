#include "Scale.h"

void Pan::setName(std::string name)
{
    _name = name;
}

unsigned Pan::getTotalMass()
{
    return _mass + _addedMass + _aboveMass;
}

void Pan::addMass(unsigned toAdd)
{
    _addedMass += toAdd;
}

void Pan::setMass(unsigned toSet)
{
    _mass = toSet;
}
unsigned Pan::getMass()
{
    return _mass;
}

unsigned Pan::getAddedMass()
{
    return _addedMass;
}

unsigned Pan::getAboveMass()
{
    return _aboveMass;
}

void Pan::addAboveMass(unsigned above)
{
    if (!aboveScaleName.empty())
    {
        _aboveMass += above;
    }
}

Scale::Scale()
{
    leftPan.setName(name + "leftPan");
    rightPan.setName(name + "rightPan");
}

bool Scale::isBalenced()
{
    if (rightPan.getTotalMass() == leftPan.getTotalMass()) return true;
    else return false;
}

unsigned Scale::getTotalMass()
{
    return leftPan.getTotalMass() + rightPan.getTotalMass() + _scaleWeight;
}


