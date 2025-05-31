#include "BFSFullGraphSolver.h"
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Convert state to unique index
inline int BFSFullGraphSolver::StateToIndex(const JugState& state) const {
    return state.first * (m_S + 1) + state.second;
}

// Convert index back to state
inline JugState BFSFullGraphSolver::indexToState(int index) const {
    return { index / (m_S + 1), index % (m_S + 1) };
}

// Build the full state graph
void BFSFullGraphSolver::buildFullGraph(DirectedGraph& graph) const
{
    for (int l = 0; l <= m_L; ++l) {
        for (int s = 0; s <= m_S; ++s) {
            JugState current = { l, s };
            for (const auto& step : GetNextStates(current)) {
                graph.AddEdge(current, step.second, m_S); // Add edge for each possible move
            }
        }
    }
}

// Build solution path
Solution BFSFullGraphSolver::BuildSolution(int startIdx, const std::vector<eOperationType>& opFromParent) const
{
    Solution solution;
    int goalIdx = StateToIndex(m_goal);
    if (m_Depth[goalIdx] == INT_MAX) {
        solution.success = false; // No solution found
        return solution;
    }

    int currIdx = goalIdx;
    while (currIdx != startIdx) {
        solution.steps.push_back({ opFromParent[currIdx], indexToState(currIdx) }); // Add step to solution
        solution.operationCount++;
        currIdx = m_Parents[currIdx];
    }

    std::reverse(solution.steps.begin(), solution.steps.end()); // Reverse to get correct order
    solution.success = true;

    return solution;
}

// Solve the water jug problem using BFS
Solution BFSFullGraphSolver::solve() 
{
    int totalStates = (m_L + 1) * (m_S + 1);

    DirectedGraph graph;
    graph.MakeEmptyGraph(totalStates); // Initialize graph
    buildFullGraph(graph); // Build all possible transitions

    m_Depth = vector<int>(totalStates, INT_MAX); // Track depth of each state
    m_Parents = vector<int>(totalStates, -1);    // Track parent of each state
    vector<eOperationType> opFromParent(totalStates); // Track operation to reach each state

    queue<JugState> q;
    int startIdx = StateToIndex(m_start);
    m_Depth[startIdx] = 0;
    q.push(m_start);

    while (!q.empty()) {
        JugState current = q.front();
        q.pop();

        if (current == m_goal) {
            break; // Goal reached
        }

        for (const JugState& neighbor : graph.GetAdjList(current, m_S)) {
            int neighborIdx = StateToIndex(neighbor);
            if (m_Depth[neighborIdx] == INT_MAX) {
                int indexOfCurrent = StateToIndex(current);
                m_Depth[neighborIdx] = m_Depth[indexOfCurrent] + 1;
                m_Parents[neighborIdx] = indexOfCurrent;

                // Find which operation led to this neighbor
                for (const auto& step : GetNextStates(current)) {
                    if (step.second == neighbor) {
                        opFromParent[neighborIdx] = step.first;
                        break;
                    }
                }

                q.push(neighbor);
            }
        }
    }

    return BuildSolution(startIdx, opFromParent); // Build and return the solution
}
