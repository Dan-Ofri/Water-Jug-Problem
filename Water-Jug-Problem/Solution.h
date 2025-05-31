#pragma once
#include <vector>
#include "Step.h"

struct Solution 
{
    std::vector<Step> steps;
    int operationCount = 0;
    bool success = false;
};
