#include "AlgorithmManager.h"

bool AlgorithmManager::Run()
{
	int impl;
	bool showRuntime;
	try
	{
	m_consoleUI.ReadInput(m_L, m_S, m_W, impl, showRuntime);
	auto solver = createSolver(impl);
	Solution solution = solver->solve();
	m_consoleUI.printSolution(solution);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}

	return showRuntime;
}

std::unique_ptr<AbstractSolver> AlgorithmManager::createSolver(int impl) const {
	if (impl == 1)
		return std::make_unique<BFSFullGraphSolver>(m_L, m_S, m_W);
	else if (impl == 2)
		return std::make_unique<BFSLazySolver>(m_L, m_S, m_W);
	else
		throw std::invalid_argument("invalid input");
}

void AlgorithmManager::printRuntime(long long runtime) const {
	m_consoleUI.printRuntime(runtime);
}
