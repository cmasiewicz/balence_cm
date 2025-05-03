#include "BalenceScales.h"
#include <iostream>
#include <string>

using namespace std;

std::vector<ScalePtr> BalenceScales::getBalancedScales()
{
	vector<ScalePtr> retval;

	for (auto iter = _order.begin(); iter != _order.end(); iter++)
	{
		auto found = _scales.find(*iter);
		if (found == _scales.end())
		{
			cerr << "mismatch in scales and order" << endl;
			abort();
		}

		retval.push_back(found->second);
	}

	return retval;
}


void BalenceScales::balence()
{
	for (auto r_iter = _order.rbegin(); r_iter != _order.rend(); r_iter++)
	{
		auto found = _scales.find(*r_iter);
		if (found == _scales.end())
		{
			cerr << "mismtch in scales and order" << endl;
			abort();
		}
		ScalePtr scale = _scales[*r_iter];

		balenceScale(scale);
	}
}

void BalenceScales::balenceScale(ScalePtr scale)
{
	if (scale->isBalenced())
	{
		return;
	}

	// else it is not balenced

	if (!scale->leftPan.aboveScaleName.empty())
	{
		if (!_scales[scale->leftPan.aboveScaleName]->isBalenced())
		{
			balenceScale(scale->leftPan.aboveScaleName);
			unsigned aboveMass = _scales[scale->leftPan.aboveScaleName]->getTotalMass();
			scale->leftPan.addAboveMass(aboveMass);

		}
		else if (_scales[scale->leftPan.aboveScaleName]->isBalenced())
		{
			// above is balanced
			unsigned aboveMass = _scales[scale->leftPan.aboveScaleName]->getTotalMass();
			scale->leftPan.addAboveMass(aboveMass);
		}
	}


	if (!scale->rightPan.aboveScaleName.empty())
	{
		if (!_scales[scale->rightPan.aboveScaleName]->isBalenced())
		{
			balenceScale(scale->rightPan.aboveScaleName);
			// above is now balended
			unsigned aboveMass = _scales[scale->rightPan.aboveScaleName]->getTotalMass();
			scale->rightPan.addAboveMass(aboveMass);
		}
		else if (_scales[scale->rightPan.aboveScaleName]->isBalenced())
		{
			// above is balanced
			unsigned aboveMass = _scales[scale->rightPan.aboveScaleName]->getTotalMass();
			scale->rightPan.addAboveMass(aboveMass);
		}
	}

	// the pans above are balanced - now balence this scale
	
	if (scale->leftPan.getTotalMass() < scale->rightPan.getTotalMass())
	{
		scale->leftPan.addMass(scale->rightPan.getTotalMass() - scale->leftPan.getTotalMass());
	}
	else if (scale->rightPan.getTotalMass() < scale->leftPan.getTotalMass())
	{
		scale->rightPan.addMass(scale->leftPan.getTotalMass() - scale->rightPan.getTotalMass());
	}

}

void BalenceScales::balenceScale(string& scaleName)
{
	balenceScale(_scales[scaleName]);
}
