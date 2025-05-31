#pragma once  
#include <vector>  
#include <utility>  
#include <list> 
#include <algorithm>
#include "JugState.h"  

class DirectedGraph
{
	std::vector<std::pair<JugState, std::list<JugState>>> m_Vertices;

public:

	void MakeEmptyGraph(int n);
	void AddEdge(const JugState& u, const JugState& v);
	std::list<JugState> getAdjList(const JugState& u);
	const std::vector<std::pair<JugState, std::list<JugState>>>& getVertices() const;
};
