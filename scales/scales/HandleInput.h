#ifndef HANDLE_INPUT
#define HANDLE_INPUT
#include <vector>
#include <string>
#include <unordered_map>

#include "Scale.h"

class HandleInput
{

public:
    void handleInput(); 
    std::vector<std::string> getOrder();
    std::unordered_map<std::string, Scale> getScales();

private:
    std::vector<std::string> parseTokens(std::string& line);
    std::unordered_map<std::string, Scale> _scales;
    std::vector<std::string> _order;
};

#endif
