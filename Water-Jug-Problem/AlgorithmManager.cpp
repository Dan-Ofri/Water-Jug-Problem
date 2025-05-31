#include "AlgorithmManager.h"

bool AlgorithmManager::Run()
{
	ConsoleUI consoleUI;
	int impl;
	bool showRuntime;

	consoleUI.ReadInput(m_L, m_S, m_W, impl, showRuntime);

	auto solver = createSolver(impl);

	solver->solve(m_L, m_S, m_W);

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
