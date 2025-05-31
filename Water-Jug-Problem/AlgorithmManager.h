#pragma once

#include <memory>
#include <stdexcept>
#include "AbstractSolver.h"
#include "BFSFullGraphSolver.h"
#include "BFSLazySolver.h"
#include "ConsoleUI.h"

class AlgorithmManager
{
    int m_L; // Large jug size
    int m_S; // Small jug size
    int m_W; // Target amount
    ConsoleUI m_consoleUI; // Console UI handler

public:
    bool Run(); // Run the algorithm manager
    std::unique_ptr<AbstractSolver> createSolver(int impl) const; // Create solver based on implementation
    void printRuntime(long long runtime) const; // Print runtime information
};
