#pragma once

#include <memory>
#include <stdexcept>
#include "AbstractSolver.h"
#include "BFSFullGraphSolver.h"
#include "BFSLazySolver.h"
#include "ConsoleUI.h"

class AlgorithmManager
{
    int m_L;
    int m_S;
    int m_W;

public:
    /*AlgorithmManager(int i_L, int i_S, int i_W)
        : m_L(i_L), m_S(i_S), m_W(i_W) {
    }*/

    bool Run();

    std::unique_ptr<AbstractSolver> createSolver(int impl) const;
};
