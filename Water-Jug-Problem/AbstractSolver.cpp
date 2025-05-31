#include "AbstractSolver.h"

std::vector<std::pair<eOperationType, JugState>> AbstractSolver::getNextStates(const JugState& state) const {
    std::vector<std::pair<eOperationType, JugState>> result;
    int large = state.first;
    int small = state.second;

    if (large < m_L) {
        result.emplace_back(eOperationType::FillLarge, JugState(m_L, small));
    }
    if (small < m_S) {
        result.emplace_back(eOperationType::FillSmall, JugState(large, m_S));
    }
    if (large > 0) {
        result.emplace_back(eOperationType::EmptyLarge, JugState(0, small));
    }
    if (small > 0) {
        result.emplace_back(eOperationType::EmptySmall, JugState(large, 0));
    }
    if (large > 0 && small < m_S) {
        int transfer = std::min(large, m_S - small);
        result.emplace_back(eOperationType::PourLargeToSmall, JugState(large - transfer, small + transfer));
    }
    if (small > 0 && large < m_L) {
        int transfer = std::min(small, m_L - large);
        result.emplace_back(eOperationType::PourSmallToLarge, JugState(large + transfer, small - transfer));
    }

    return result;
}
