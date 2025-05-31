#pragma once  
#include <vector>  
#include <utility>  
#include <list> 
#include <algorithm>
#include "JugState.h"  

class DirectedGraph
{
	std::vector<std::list<JugState>> m_AdjLists;

public:
	int StateToIndex(const JugState& state, int s) const; // Get index for a state
	void MakeEmptyGraph(int n); // Initialize empty graph with n nodes
	void AddEdge(const JugState& u, const JugState& v, int s); // Add directed edge u -> v
	std::list<JugState> GetAdjList(const JugState& u, int s) const; // Get adj list for state u
};
