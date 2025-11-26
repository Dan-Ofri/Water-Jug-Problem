# Water Jug Problem Solver

A comprehensive C++ implementation of the classic Water Jug Problem using multiple graph search algorithms.

## 🎯 Problem Description

The Water Jug Problem is a classic puzzle in computer science and mathematics:

Given two jugs with capacities **A** and **B** liters, and a target amount **C** liters, find a sequence of operations to measure exactly **C** liters using only these jugs.

### Available Operations
1. **Fill** a jug to its maximum capacity
2. **Empty** a jug completely
3. **Pour** water from one jug to another (until source is empty or destination is full)

## ✨ Features

- **Multiple Solving Algorithms**:
  - BFS (Breadth-First Search) with full graph construction
  - BFS with lazy graph construction (memory-efficient)
  - Extensible architecture for adding new algorithms

- **Professional Architecture**:
  - Abstract solver base class for easy algorithm extension
  - Directed graph implementation for state space representation
  - Clean separation of concerns (UI, logic, algorithms)

- **User-Friendly Interface**:
  - Interactive console-based UI
  - Clear step-by-step solution display
  - Input/output file support

## 🏗️ Architecture

```
┌─────────────────────────────────────────┐
│         AlgorithmManager                │
│  (Coordinates solving strategies)       │
└────────────┬────────────────────────────┘
             │
             ├──► AbstractSolver (Base Class)
             │
             ├──► BFSFullGraphSolver
             │    (Pre-builds complete graph)
             │
             └──► BFSLazySolver
                  (Builds graph on-the-fly)
```

### Key Components

- **`AbstractSolver`**: Base class defining the solver interface
- **`DirectedGraph`**: Graph data structure for state space
- **`JugState`**: Represents a state (jug A volume, jug B volume)
- **`AlgorithmManager`**: Manages solver selection and execution
- **`ConsoleUI`**: Handles user interaction

## 🚀 Getting Started

### Prerequisites

- Visual Studio 2017 or later
- C++17 or higher
- Windows OS (Console application)

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/Dan-Ofri/Water-Jug-Problem.git
   cd Water-Jug-Problem
   ```

2. Open `Water-Jug-Problem.sln` in Visual Studio

3. Build the solution:
   - **Debug**: `Ctrl+Shift+B`
   - **Release**: Set configuration to Release, then build

### Running the Program

#### Option 1: Visual Studio
- Press `F5` to run with debugging
- Or `Ctrl+F5` to run without debugging

#### Option 2: Command Line
```bash
cd Water-Jug-Problem\x64\Release
Water-Jug_Problem.exe
```

## 📝 Usage

### Interactive Mode

```
=== Water Jug Problem Solver ===

Enter jug A capacity: 4
Enter jug B capacity: 3
Enter target amount: 2

Choose algorithm:
1. BFS (Full Graph)
2. BFS (Lazy)

Your choice: 1

Solution found in 6 steps:
Step 1: Fill jug A → (4, 0)
Step 2: Pour A to B → (1, 3)
Step 3: Empty jug B → (1, 0)
Step 4: Pour A to B → (0, 1)
Step 5: Fill jug A → (4, 1)
Step 6: Pour A to B → (2, 3) ✓ TARGET REACHED
```

### File Input

Create an `input.txt` file:
```
4 3 2
```

Results will be saved to `output.txt`.

## 🧪 Example Problems

| Jug A | Jug B | Target | Solvable | Steps |
|-------|-------|--------|----------|-------|
| 4     | 3     | 2      | ✅ Yes   | 6     |
| 5     | 3     | 4      | ✅ Yes   | 6     |
| 7     | 5     | 4      | ✅ Yes   | 8     |
| 6     | 9     | 4      | ❌ No    | -     |

**Note**: A solution exists if and only if the target is divisible by GCD(A, B) and target ≤ max(A, B).

## 🎓 Algorithms Explained

### BFS Full Graph Solver
- **Strategy**: Pre-builds the entire state graph before searching
- **Advantages**: Fast repeated queries, good for analysis
- **Disadvantages**: Higher memory usage
- **Best for**: Small state spaces, educational purposes

### BFS Lazy Solver
- **Strategy**: Builds graph nodes only as needed during search
- **Advantages**: Memory efficient, faster for single queries
- **Disadvantages**: Cannot reuse graph for multiple queries
- **Best for**: Large state spaces, one-time solutions

## 📂 Project Structure

```
Water-Jug-Problem/
├── AbstractSolver.h/cpp        # Base solver interface
├── BFSFullGraphSolver.h/cpp    # Full graph BFS implementation
├── BFSLazySolver.h/cpp         # Lazy graph BFS implementation
├── AlgorithmManager.h/cpp      # Algorithm coordination
├── DirectedGraph.h/cpp         # Graph data structure
├── JugState.h                  # State representation
├── Solution.h                  # Solution structure
├── Step.h                      # Step representation
├── eOperationType.h            # Operation enumeration
├── ConsoleUI.h/cpp             # User interface
├── Main.cpp                    # Entry point
├── input.txt                   # Input file (optional)
└── output.txt                  # Output file (generated)
```

## 🛠️ Technologies Used

- **Language**: C++17
- **IDE**: Visual Studio 2017+
- **Data Structures**: 
  - Custom Directed Graph implementation
  - Queue (for BFS)
  - Vector, Set (STL containers)
- **Design Patterns**:
  - Strategy Pattern (multiple solving algorithms)
  - Template Method Pattern (AbstractSolver)

## 🎯 Learning Objectives

This project demonstrates:
- Graph algorithms (BFS)
- Object-oriented design in C++
- Algorithm complexity analysis
- Memory vs. time tradeoffs
- State space search techniques

## 👥 Authors

Developed by **[Dan Ofri](https://github.com/Dan-Ofri)** and **Nave Tzavig**

Part of **Algorithms Course** project

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🙏 Acknowledgments

- Classic Water Jug Problem formulation
- Graph search algorithms from algorithm design courses
- BFS algorithm optimization techniques

---

⭐ **Star this repository if you found it helpful!**
