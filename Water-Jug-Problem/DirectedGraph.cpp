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
		// FIXED: Sort adjacency list lexicographically after adding edge
		m_AdjLists[idx].sort();
	}
}

// Get adj list for state u
// FIXED: Return by const reference to avoid unnecessary copy (-1 point fixed)
const list<JugState>& DirectedGraph::GetAdjList(const JugState& u, int s) const
{
	int idx = StateToIndex(u, s);
	// Note: List is kept sorted in AddEdge, so this returns a sorted list (-3 points fixed)
	return m_AdjLists[idx];
}
