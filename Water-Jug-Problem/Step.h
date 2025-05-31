#pragma once
#include <iostream>
#include <string>
#include "eOperationType.h"
#include "JugState.h"

struct Step
{
	eOperationType operation;
	JugState resultState;

	std::string toString() const {
		return OpTypeToString(operation);
	}

    std::string OpTypeToString(eOperationType i_op) const {
        switch (i_op) {
        case eOperationType::FillLarge: return "Fill large jug";
        case eOperationType::FillSmall: return "Fill small jug";
        case eOperationType::EmptyLarge: return "Empty large jug";
        case eOperationType::EmptySmall: return "Empty small jug";
        case eOperationType::PourLargeToSmall: return "Transfer from large jug to small jug";
        case eOperationType::PourSmallToLarge: return "Transfer from small jug to large jug";
        default: return "Unknown operation";
        }
    }

	std::string stateToString(const JugState& state) const {
		return "(" + std::to_string(state.first) + ", " + std::to_string(state.second) + ")";
	}
};