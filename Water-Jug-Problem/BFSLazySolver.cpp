#include "BFSLazySolver.h"
#include <queue>
#include <vector>
using namespace std;

// Solve the water jug problem using lazy BFS
Solution BFSLazySolver::solve()
{
    int totalStates = (m_L + 1) * (m_S + 1);

    // Map to track operation used to reach each state
    unordered_map<JugState, eOperationType> opFromParent;
    queue<JugState> q;

    m_Visited.insert(m_start); // Mark start as visited
    q.push(m_start);

    while (!q.empty()) {
        JugState current = q.front();
        q.pop();

        if (current == m_goal) {
            break; // Goal reached
        }

        for (const auto& step : GetNextStates(current)) {
            JugState neighbor = step.second;

            if (m_Visited.find(neighbor) == m_Visited.end()) 
            {
                m_Visited.insert(neighbor); // Mark as visited
                m_Parents[neighbor] = current; // Track parent
                opFromParent[neighbor] = step.first; // Track operation
                q.push(neighbor);
            }
        }
    }

    return BuildSolution(opFromParent); // Build and return the solution
}

// Build the solution path from parent and operation maps
Solution BFSLazySolver::BuildSolution(unordered_map<JugState, eOperationType>& opFromParent) 
{
    Solution solution;
    if (m_Visited.find(m_goal) == m_Visited.end()) {
        solution.success = false; // No solution found
        return solution;
    }

    JugState currVertex = m_goal;
    while (currVertex != m_start) {
        solution.steps.push_back({ opFromParent[currVertex], currVertex }); // Add step to solution
        solution.operationCount++;
        currVertex = m_Parents[currVertex];
    }

    std::reverse(solution.steps.begin(), solution.steps.end()); // Reverse to get correct order
    solution.success = true;

    return solution;
}