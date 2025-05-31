#pragma once
#include <queue>
#include <vector>
#include "AbstractSolver.h"
#include "DirectedGraph.h"
#include "JugState.h"
#include "Solution.h"

class BFSFullGraphSolver : public AbstractSolver
{
	std::vector<int> m_Depth;   // Depth of each state in BFS
	std::vector<int> m_Parents; // Parent index for each state

public:
	// Constructor: initialize with jug sizes and target
	BFSFullGraphSolver(int i_L, int i_S, int i_W)
		: AbstractSolver(i_L, i_S, i_W) {
	} 

	Solution solve() override; // Solve the water jug problem using BFS

private:
	inline int StateToIndex(const JugState& state) const; // Convert state to unique index
	inline JugState indexToState(int index) const;        // Convert index back to state
	void buildFullGraph(DirectedGraph& graph) const;      // Build the full state graph
	Solution BuildSolution(int startIdx, const std::vector<eOperationType>& opFromParent) const; // Build solution path
};
