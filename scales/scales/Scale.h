#ifndef SCALE_H
#define SCALE_H

#include <string>
#include <memory>

class Pan
{
public:
    void setName(std::string name);
    unsigned getTotalMass();
    void addMass(unsigned toAdd);
    std::string aboveScaleName;
    void setMass(unsigned toSet);
    unsigned getMass();
    unsigned getAddedMass();
    unsigned getAboveMass();
    void addAboveMass(unsigned above);
   
private:
    std::string _name;
    unsigned _mass = 0;
    unsigned _aboveMass = 0;
    unsigned _addedMass = 0;
    unsigned _totalMass = 0;
};

class Scale
{
public:
    std::string name;
    Pan leftPan;
    Pan rightPan;

    Scale();
    bool isBalenced();
    unsigned getTotalMass();
   
private:
    unsigned _scaleWeight = 1;
};
typedef std::shared_ptr<Scale> ScalePtr;


#endif