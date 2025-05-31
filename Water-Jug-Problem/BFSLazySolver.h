#pragma once
#include <unordered_set>
#include <unordered_map>
#include "AbstractSolver.h"	
#include "JugState.h"
#include "Solution.h"
#include "eOperationType.h"
#include "Step.h"
#include "DirectedGraph.h"

class BFSLazySolver : public AbstractSolver
{
	std::unordered_set<JugState> m_Visited;
	std::unordered_map<JugState, JugState> m_Parents;

public:
	BFSLazySolver(int i_L, int i_S, int i_W)
		: AbstractSolver(i_L, i_S, i_W) {
	}
	Solution solve() override;
	Solution BuildSolution(std::unordered_map<JugState, eOperationType>& opFromParent);

};

