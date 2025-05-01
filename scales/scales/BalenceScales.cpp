#include "BalenceScales.h"
#include <iostream>
#include <string>

using namespace std;

std::vector<Scale> BalenceScales::getBalancedScales()
{
	vector<Scale> retval;
	// todo return in order
	for (auto iter = _order.begin(); iter != _order.end(); iter++)
	{
		auto found = _scales.find(*iter);
		if (found == _scales.end())
		{
			cerr << "mismtch in scales and order" << endl;
			abort();
		}

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
		Scale scale = _scales[*r_iter];

		balanceScale(scale);
	}
}
void BalenceScales::balanceScale(Scale& scale)
{

}