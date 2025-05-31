#pragma once
#include <vector>
#include "Step.h"

// Stores the result of solving the water jug problem
struct Solution 
{
    std::vector<Step> steps;    // Steps to reach the goal
    int operationCount = 0;     // Number of operations performed
    bool success = false;       // True if a solution was found
};
