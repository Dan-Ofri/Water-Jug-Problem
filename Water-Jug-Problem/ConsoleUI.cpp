#include "ConsoleUI.h"

// Read user input for jug sizes, target, algorithm, and runtime option
void ConsoleUI::ReadInput(int& o_L, int& o_S, int& o_W, int& o_Impl, bool& o_ShowRuntime)
{
    std::cout << "Enter the capacity of the large jug (L): ";
    std::cin >> o_L;
    std::cout << "Enter the capacity of the small jug (S): ";
    std::cin >> o_S;
    std::cout << "Enter the target amount of water (W): ";
    std::cin >> o_W;
    std::cout << "Choose implementation (1 for BFS Full Graph, 2 for BFS Lazy): ";
    std::cin >> o_Impl;
    std::cout << "Show runtime? (1 for Yes, 0 for No): ";
    std::cin >> o_ShowRuntime;

    if (std::cin.fail()) {
        throw std::invalid_argument("Invalid input: expected integers.");
    }

    checkInput(o_L, o_S, o_W, o_Impl, o_ShowRuntime); // Validate input
}

// Print the solution steps and result
void ConsoleUI::printSolution(const Solution& solution) const
{
    if (solution.success) {
        int i = 1;
        std::cout << "Number of operations: " << solution.operationCount << "\nOperations:\n";
        for (const auto& step : solution.steps) {
            std::cout << i << ". " << step.toString() << "\n"; // Print each step
            i++;
        }
    }
    else {
        std::cout << "No solution.\n";
    }
}

// Validate and check user input
void ConsoleUI::checkInput(int& i_L, int& i_S, int& i_W, int& i_Impl, bool& i_ShowRuntime)
{
    if (i_L <= 0 || i_S <= 0 || i_W < 0 || i_W > i_L) {
        throw std::invalid_argument("Invalid input: capacities must be positive and target must be within range.");
    }
    if (i_L <= i_S) {
        throw std::invalid_argument("Invalid input: Large jug capacity must be greater than the small jug capacity.");
    }
    if (i_Impl != 1 && i_Impl != 2) {
        throw std::invalid_argument("Invalid input: Implementation must be 1 or 2.");
    }
    if (i_ShowRuntime != 0 && i_ShowRuntime != 1) {
        throw std::invalid_argument("Invalid input: Runtime flag must be 0 or 1.");
    }
}

// Print the runtime of the algorithm
void ConsoleUI::printRuntime(long long i_runtime) const
{
    std::cout << "Function took " << i_runtime << " microseconds." << std::endl; // Print runtime
}