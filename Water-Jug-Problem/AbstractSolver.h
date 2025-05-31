#pragma once
#include "JugState.h"
#include "Step.h"
#include <vector>
#include <utility>
#include "Solution.h"
#include "eOperationType.h"

class AbstractSolver {
protected:
    int m_L, m_S, m_W; // Jug sizes and target
    JugState m_start = { 0, 0 }; // Start state
    JugState m_goal = { m_W, 0 }; // Goal state

public:
    // Initialize solver with jug sizes and target
    AbstractSolver(int L, int S, int W)
        : m_L(L), m_S(S), m_W(W), m_start({ 0, 0 }), m_goal({ W, 0 }) {
    }

    // Solve the problem (to be implemented by derived classes)
    virtual Solution solve() = 0;

protected:
    // Get all possible next states from current state
    std::vector<std::pair<eOperationType, JugState>> GetNextStates(const JugState& state) const;
};
