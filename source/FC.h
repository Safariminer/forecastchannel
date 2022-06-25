#pragma once

#include <iostream>
#include <vector>

typedef enum {fahrenheit, celsius} TFMode;

class TownForecast{
    public:
        std::string townName;
        std::string funFact;
        std::vector<int> temperatures; // SHOULD BE 7 LONG
        TFMode mode;
};