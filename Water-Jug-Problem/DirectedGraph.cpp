#include "DirectedGraph.h"
using namespace std;


void DirectedGraph::MakeEmptyGraph(int n) {
	m_Vertices.clear();
	m_Vertices.reserve(n);
}

void DirectedGraph::AddEdge(const JugState& u, const JugState& v) {
	for (auto& vertex : m_Vertices) {
		if (vertex.first == u) {
			vertex.second.push_back(v);
			return;
		}
	}
	m_Vertices.emplace_back(u, list<JugState>{v});
}

list<JugState> DirectedGraph::getAdjList(const JugState& u) {
	for (auto& vertex : m_Vertices) {
		if (vertex.first == u) {
			vertex.second.sort();
			return vertex.second;
		}
	}
	return list<JugState>(); // Return an empty list if no adj states found
}

const vector<pair<JugState, list<JugState>>>& DirectedGraph::getVertices() const {
	return m_Vertices;
}
