#include "AlgorithmManager.h"

// Run the algorithm manager
bool AlgorithmManager::Run()
{
	int impl;
	bool showRuntime;
	try
	{
		m_consoleUI.ReadInput(m_L, m_S, m_W, impl, showRuntime); // Read user input
		auto solver = createSolver(impl); // Create solver based on user choice
		Solution solution = solver->solve(); // Solve the problem
		m_consoleUI.printSolution(solution); // Print the solution
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}

	return showRuntime;
}

// Create solver based on implementation
std::unique_ptr<AbstractSolver> AlgorithmManager::createSolver(int impl) const {
	if (impl == 1)
		return std::unique_ptr<AbstractSolver>(new BFSFullGraphSolver(m_L, m_S, m_W)); // Full graph BFS
	else if (impl == 2)
		return std::unique_ptr<AbstractSolver>(new BFSLazySolver(m_L, m_S, m_W)); // Lazy BFS
	else
		throw std::invalid_argument("invalid input");
}

// Print runtime information
void AlgorithmManager::printRuntime(long long runtime) const {
	m_consoleUI.printRuntime(runtime);
}
