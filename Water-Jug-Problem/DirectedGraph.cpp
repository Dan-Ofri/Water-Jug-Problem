#include "DirectedGraph.h"
using namespace std;

// Get index for a state
int DirectedGraph::StateToIndex(const JugState& state, int s) const {
	return state.first * (s + 1) + state.second;
}

// Initialize empty graph with n nodes
void DirectedGraph::MakeEmptyGraph(int n) {
	m_AdjLists.clear();
	m_AdjLists.resize(n);
}

// Add directed edge u -> v
void DirectedGraph::AddEdge(const JugState& u, const JugState& v, int s)
{
	int idx = StateToIndex(u, s);
	if (std::find(m_AdjLists[idx].begin(), m_AdjLists[idx].end(), v) == m_AdjLists[idx].end())
	{
		m_AdjLists[idx].push_back(v); // Add edge if not already present
	}
}

// Get adj list for state u
list<JugState> DirectedGraph::GetAdjList(const JugState& u, int s) const
{
	int idx = StateToIndex(u, s);
	return m_AdjLists[idx]; // Return adjacency list for state
}
