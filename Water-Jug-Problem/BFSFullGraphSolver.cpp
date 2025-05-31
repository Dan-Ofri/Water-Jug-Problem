#include "BFSFullGraphSolver.h"
#include <queue>
#include <algorithm>

using namespace std;

inline int BFSFullGraphSolver::stateToIndex(const JugState& state) const {
    return state.first * (m_S + 1) + state.second;
}

inline JugState BFSFullGraphSolver::indexToState(int index) const {
    return { index / (m_S + 1), index % (m_S + 1) };
}

void BFSFullGraphSolver::buildFullGraph(DirectedGraph& graph) const
{
    for (int l = 0; l <= m_L; ++l) {
        for (int s = 0; s <= m_S; ++s) {
            JugState current = { l, s };
            for (const auto& step : getNextStates(current)) {
                graph.AddEdge(current, step.second);
            }
        }
    }
}

Solution BFSFullGraphSolver::BuildSolution(int startIdx, const std::vector<eOperationType>& opFromParent) const
{
    Solution solution;
    int goalIdx = stateToIndex(m_goal);
    if (m_Depth[goalIdx] == INT_MAX) {
        solution.success = false;
        return solution;
    }

    int currIdx = goalIdx;
    while (currIdx != startIdx) {
        solution.steps.push_back({ opFromParent[currIdx], indexToState(currIdx) });
        solution.operationCount++;
        currIdx = m_Parents[currIdx];
    }

    std::reverse(solution.steps.begin(), solution.steps.end());
    solution.success = true;

    return solution;
}

Solution BFSFullGraphSolver::solve() 
{
    int totalStates = (m_L + 1) * (m_S + 1);

    DirectedGraph graph;
    graph.MakeEmptyGraph(totalStates);
	buildFullGraph(graph);

    m_Depth = vector<int>(totalStates, INT_MAX);
    m_Parents = vector<int>(totalStates, -1);
    vector<eOperationType> opFromParent(totalStates);

    queue<JugState> q;
    int startIdx = stateToIndex(m_start);
    m_Depth[startIdx] = 0;
    q.push(m_start);

    while (!q.empty()) {
        JugState current = q.front();
        q.pop();

        if (current == m_goal) {
            break;
        }

        for (const JugState& neighbor : graph.getAdjList(current)) {
            int neighborIdx = stateToIndex(neighbor);
            if (m_Depth[neighborIdx] == INT_MAX) {
				int indexOfCurrent = stateToIndex(current);
                m_Depth[neighborIdx] = m_Depth[indexOfCurrent] + 1;
                m_Parents[neighborIdx] = indexOfCurrent;

                for (const auto& step : getNextStates(current)) {
                    if (step.second == neighbor) {
                        opFromParent[neighborIdx] = step.first;
                        break;
                    }
                }

                q.push(neighbor);
            }
        }
    }

	return BuildSolution(startIdx, opFromParent);
    
}
