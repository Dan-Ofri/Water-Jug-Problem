#pragma once
#include <queue>
#include <vector>
#include "AbstractSolver.h"
#include "DirectedGraph.h"
#include "JugState.h"
#include "Solution.h"

class BFSFullGraphSolver : public AbstractSolver
{
	std::vector<int> m_Depth;
	std::vector<int> m_Parents;

public:
	BFSFullGraphSolver(int i_L, int i_S, int i_W)
		: AbstractSolver(i_L, i_S, i_W) {
	}
	Solution solve() override;

private:
	inline int stateToIndex(const JugState& state) const;
	inline JugState indexToState(int index) const;
	void buildFullGraph(DirectedGraph& graph) const;
	Solution BuildSolution(int startIdx, const std::vector<eOperationType>& opFromParent) const;
};

