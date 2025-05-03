#ifndef BALENCE_SCALES
#define BALENCE_SCALES
#include "Scale.h"

#include <unordered_map>
#include <vector>
#include <string>

class BalenceScales
{
public:
	BalenceScales(std::unordered_map<std::string, ScalePtr> scales, std::vector<std::string> order):  _scales(scales), _order(order)
	{
		balence();
	}
	std::vector<ScalePtr> getBalancedScales();
private:
	void balence();
	void balenceScale(ScalePtr scale);
	void balenceScale(std::string& scaleName);
	std::unordered_map<std::string, ScalePtr> _scales;
	std::vector<std::string> _order;
};
#endif

