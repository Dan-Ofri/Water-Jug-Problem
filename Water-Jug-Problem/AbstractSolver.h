#pragma once

#include "JugState.h"
#include "Step.h"
#include <vector>
#include <utility>
#include "Solution.h"
#include "eOperationType.h"

class AbstractSolver {
protected:
    int m_L, m_S, m_W;
    JugState m_start;
    JugState m_goal;

public:
    AbstractSolver(int L, int S, int W)
        : m_L(L), m_S(S), m_W(W), m_start({ 0, 0 }), m_goal({ W, 0 }) {
    }

    virtual ~AbstractSolver() = default;

    virtual std::vector<Solution> solve() = 0;

protected:
    std::vector<std::pair<eOperationType, JugState>> getNextStates(const JugState& state) const;
};
