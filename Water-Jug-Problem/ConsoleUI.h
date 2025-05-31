#pragma once
#include <iostream>
#include <stdexcept>
#include "Solution.h"

class ConsoleUI
{
   
public:
    void ReadInput(int& o_L, int& o_S, int& o_W, int& o_Impl, bool& o_ShowRuntime);
    void printSolution(const Solution& solution) const;
    void printRuntime(long long i_runtime) const;

private:
    void checkInput(int& i_L, int& i_S, int& i_W, int& i_Impl, bool& i_ShowRuntime);
};
