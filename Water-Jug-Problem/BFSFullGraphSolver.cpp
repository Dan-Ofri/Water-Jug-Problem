#include "BFSFullGraphSolver.h"
using namespace std;

Solution BFSFullGraphSolver::solve()
{
	Solution solutions;
	m_start = { 0, 0 };
	m_goal = { m_W, 0 };
	m_Visited.clear();
	m_Visited.resize((m_L + 1) * (m_S + 1), false);
	std::queue<JugState> queue;

	queue.push(m_start);
	m_Visited[m_start.first * (m_S + 1) + m_start.second] = true;
	while (!queue.empty()) {
		JugState current = queue.front();
		queue.pop();
		if (current == m_goal) 
		{
			solutions.success = true;

			break;
		}
		for (const auto& next : getNextStates(current)) 
		{
			if (!m_Visited[next.second.first * (m_S + 1) + next.second.second]) 
			{
				m_Visited[next.second.first * (m_S + 1) + next.second.second] = true;
				queue.push(next.second);
			}
		}
		solutions.operationCount++;

	}

	return solutions; 
}
