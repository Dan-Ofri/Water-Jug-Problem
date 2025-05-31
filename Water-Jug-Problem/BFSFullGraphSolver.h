#pragma once
#include "AbstractSolver.h"
#include <queue>
#include <vector>
#include "JugState.h"
#include "Solution.h"

class BFSFullGraphSolver : public AbstractSolver
{
	std::vector<bool> m_Visited;
	std::vector<JugState> m_Parents;

public:
	Solution solve() override;
};

