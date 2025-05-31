#include "BFSLazySolver.h"
#include <queue>
#include <vector>
using namespace std;

Solution BFSLazySolver::solve()
{
    int totalStates = (m_L + 1) * (m_S + 1);

    //DirectedGraph graph;
    unordered_map<JugState, eOperationType> opFromParent;
    queue<JugState> q;

    m_Visited.insert(m_start);
    q.push(m_start);

    while (!q.empty()) {
        JugState current = q.front();
        q.pop();

        if (current == m_goal) {
            break;
        }

        for (const auto& step : getNextStates(current)) {
			JugState neighbor = step.second;

            if (m_Visited.find(neighbor) == m_Visited.end()) 
            {
                m_Visited.insert(neighbor);
                m_Parents[neighbor] = current;
                opFromParent[neighbor] = step.first;
                q.push(neighbor);
            }
        }
    }

    return BuildSolution(opFromParent);
}

Solution BFSLazySolver::BuildSolution(unordered_map<JugState, eOperationType>& opFromParent) 
{
    Solution solution;
    if (m_Visited.find(m_goal) == m_Visited.end()) {
        solution.success = false;
        return solution;
    }

    JugState currVertex = m_goal;
    while (currVertex != m_start) {
        solution.steps.push_back({ opFromParent[currVertex], currVertex });
        solution.operationCount++;
        currVertex = m_Parents[currVertex];
    }

    std::reverse(solution.steps.begin(), solution.steps.end());
    solution.success = true;

    return solution;
}