#pragma once
#include <iostream>
#include <string>
#include "eOperationType.h"
#include "JugState.h"

struct Step
{
	eOperationType operation;
	JugState resultState;    // Resulting state after operation

	// Convert step to string (operation only)
	std::string toString() const {
		return OpTypeToString(operation);
	}

    // Convert operation type to readable string
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
};