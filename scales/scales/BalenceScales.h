#ifndef BALENCE_SCALES
#define BALENCE_SCALES
#include "Scale.h"

#include <unordered_map>
#include <vector>
#include <string>

class BalenceScales
{
public:
	BalenceScales(std::unordered_map<std::string, Scale> scales, std::vector<std::string> order):  _scales(scales), _order(order)
	{
		balence();
	}
	std::vector<Scale> getBalancedScales();
private:
	void balence();
	void balanceScale(Scale& scale);
	std::unordered_map<std::string, Scale> _scales;
	std::vector<std::string> _order;
};
#endif

