#include "AbstractSolver.h"

// Get all possible next states from current state
std::vector<std::pair<eOperationType, JugState>> AbstractSolver::GetNextStates(const JugState& state) const {
    std::vector<std::pair<eOperationType, JugState>> result;
    int large = state.first;
    int small = state.second;

    // Fill large jug
    if (large < m_L) {
        result.emplace_back(eOperationType::FillLarge, JugState(m_L, small));
    }
    // Fill small jug
    if (small < m_S) {
        result.emplace_back(eOperationType::FillSmall, JugState(large, m_S));
    }
    // Empty large jug
    if (large > 0) {
        result.emplace_back(eOperationType::EmptyLarge, JugState(0, small));
    }
    // Empty small jug
    if (small > 0) {
        result.emplace_back(eOperationType::EmptySmall, JugState(large, 0));
    }
    // Pour from large jug to small jug
    if (large > 0 && small < m_S) {
        int transfer = std::min(large, m_S - small);
        result.emplace_back(eOperationType::PourLargeToSmall, JugState(large - transfer, small + transfer));
    }
    // Pour from small jug to large jug
    if (small > 0 && large < m_L) {
        int transfer = std::min(small, m_L - large);
        result.emplace_back(eOperationType::PourSmallToLarge, JugState(large + transfer, small - transfer));
    }

    return result;
}
