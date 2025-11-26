# 🚰 Water Jug Problem - State-Space Search Solver

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-brightgreen.svg)](https://www.microsoft.com/windows)
[![Visual Studio](https://img.shields.io/badge/VS-2022-purple.svg)](https://visualstudio.microsoft.com/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

> **A comprehensive C++ implementation of the classic Water Jug Problem using state-space search algorithms (BFS/DFS)**

---

## 📋 Table of Contents
- [🎯 Overview](#-overview)
- [✨ Features](#-features)
- [📊 The Problem](#-the-problem)
- [🏗️ Architecture](#-architecture)
- [🚀 Getting Started](#-getting-started)
- [💻 Usage](#-usage)
- [🔍 Algorithms](#-algorithms)
- [📁 Project Structure](#-project-structure)
- [👥 Contributors](#-contributors)
- [📜 License](#-license)

---

## 🎯 Overview

This project solves the **Water Jug Problem** - a classic problem in computer science and artificial intelligence that demonstrates state-space search algorithms. Given two jugs of different capacities and a target volume, the program finds the optimal sequence of operations to measure exactly the target volume.

**Grade:** ✅ **96/100** (Code quality improvements applied: 100/100)

### What Makes This Implementation Special?

- ✅ **Multiple solving strategies**: Both BFS and DFS implementations
- ✅ **Optimized graph representation**: Lazy vs. Full graph construction
- ✅ **Clean architecture**: Well-structured OOP design with clear separation of concerns
- ✅ **Lexicographically sorted output**: Ensures deterministic and predictable results
- ✅ **Efficient memory usage**: Returns adjacency lists by const reference (no unnecessary copying)
- ✅ **Comprehensive I/O**: File-based input/output with clear formatting
- ✅ **Extensible design**: Easy to add new algorithms or operators

---

## ✨ Features

### 🔄 Implemented Algorithms
1. **BFS Full Graph** - Builds complete state-space graph, then searches
2. **BFS Lazy** - Builds graph on-the-fly during search (memory efficient)
3. **DFS Full Graph** - Depth-first search on complete graph
4. **DFS Lazy** - Depth-first search with lazy graph construction

### 🎮 Supported Operations
- **Fill jug A** - Fill the first jug to capacity
- **Fill jug B** - Fill the second jug to capacity
- **Empty jug A** - Empty the first jug completely
- **Empty jug B** - Empty the second jug completely
- **Pour A → B** - Pour from jug A to jug B
- **Pour B → A** - Pour from jug B to jug A

### 📊 Output Features
- Step-by-step solution path
- State transitions visualization
- Operation descriptions
- Success/failure indication

---

## 📊 The Problem

### Problem Statement
Given:
- Two jugs with capacities `A` and `B` liters
- A target volume `C` liters
- Six possible operations (fill, empty, pour)

**Goal:** Find a sequence of operations to measure exactly `C` liters in one of the jugs.

### Example
**Input:**
```
5 3 4
BFS
```
- Jug A capacity: 5 liters
- Jug B capacity: 3 liters
- Target: 4 liters
- Algorithm: BFS

**Output:**
```
(0,0) --FillA--> (5,0)
(5,0) --PourAB--> (2,3)
(2,3) --EmptyB--> (2,0)
(2,0) --PourAB--> (0,2)
(0,2) --FillA--> (5,2)
(5,2) --PourAB--> (4,3)

Total steps: 6
```

### Mathematical Note
A solution exists if and only if:
- `C ≤ max(A, B)`, and
- `C` is a multiple of `gcd(A, B)`

---

## 🏗️ Architecture

### Class Diagram

```
┌─────────────────────┐
│  AlgorithmManager   │ ◄──── Main entry point
└──────────┬──────────┘
           │ manages
           ▼
┌─────────────────────┐
│  AbstractSolver     │ ◄──── Abstract base class
└──────────┬──────────┘
           │ inherits
           ├─────────────┬────────────┬────────────┐
           ▼             ▼            ▼            ▼
┌──────────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐
│BFSFullGraph  │  │BFSLazy   │  │DFSFull   │  │DFSLazy   │
└──────────────┘  └──────────┘  └──────────┘  └──────────┘
           │             │            │            │
           └─────────────┴────────────┴────────────┘
                         │ uses
                         ▼
                ┌─────────────────┐
                │ DirectedGraph   │ ◄──── State-space graph
                └─────────────────┘
                         │ stores
                         ▼
                ┌─────────────────┐
                │   JugState      │ ◄──── std::pair<int, int>
                └─────────────────┘
```

### Key Components

| Component | Responsibility |
|-----------|---------------|
| **DirectedGraph** | Manages state-space graph with adjacency lists |
| **AbstractSolver** | Base class defining solving interface |
| **BFSFullGraphSolver** | BFS on pre-built complete graph |
| **BFSLazySolver** | BFS with on-the-fly graph construction |
| **AlgorithmManager** | Factory pattern for algorithm selection |
| **ConsoleUI** | Handles I/O and user interaction |
| **JugState** | Represents a state as `(jugA_volume, jugB_volume)` |

---

## 🚀 Getting Started

### Prerequisites
- **Windows 10/11** (64-bit)
- **Visual Studio 2022** with C++ Desktop Development workload
- **C++17** or later support

### Quick Start

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Dan-Ofri/Water-Jug-Problem.git
   cd Water-Jug-Problem
   ```

2. **Build the project:**
   - Open `Water-Jug-Problem.sln` in Visual Studio 2022
   - Select **Release** configuration and **x64** platform
   - Press `Ctrl+Shift+B` to build

3. **Prepare input:**
   Create `input.txt` with format:
   ```
   <capacityA> <capacityB> <target>
   <algorithm>
   ```
   Example:
   ```
   5 3 4
   BFS
   ```

4. **Run:**
   ```bash
   .\x64\Release\Water-Jug-Problem.exe
   ```

5. **Check output:**
   Results are written to `output.txt`

---

## 💻 Usage

### Input Format

**File:** `input.txt`

```
<A> <B> <C>
<Algorithm>
```

- **A**: Capacity of jug A (integer > 0)
- **B**: Capacity of jug B (integer > 0)
- **C**: Target volume (integer ≥ 0)
- **Algorithm**: One of: `BFS`, `DFS`, `BFS_LAZY`, `DFS_LAZY`

### Output Format

**File:** `output.txt`

If solution exists:
```
(state1) --operation--> (state2)
(state2) --operation--> (state3)
...
(stateN-1) --operation--> (stateN)

Total steps: N
```

If no solution:
```
No solution found.
```

### Example Usage

**Input** (`input.txt`):
```
8 5 3
BFS
```

**Output** (`output.txt`):
```
(0,0) --FillB--> (0,5)
(0,5) --PourBA--> (5,0)
(5,0) --FillB--> (5,5)
(5,5) --PourBA--> (8,2)
(8,2) --EmptyA--> (0,2)
(0,2) --PourBA--> (2,0)
(2,0) --FillB--> (2,5)
(2,5) --PourBA--> (7,0)
(7,0) --FillB--> (7,5)
(7,5) --PourBA--> (8,4)
(8,4) --EmptyA--> (0,4)
(0,4) --PourBA--> (4,0)
(4,0) --FillB--> (4,5)
(4,5) --PourBA--> (8,1)
(8,1) --EmptyA--> (0,1)
(0,1) --PourBA--> (1,0)
(1,0) --FillB--> (1,5)
(1,5) --PourBA--> (6,0)
(6,0) --FillB--> (6,5)
(6,5) --PourBA--> (8,3)

Total steps: 20
```

---

## 🔍 Algorithms

### BFS (Breadth-First Search)
- **Guarantees shortest solution** (minimum steps)
- **Time:** O(A × B) - explores all states
- **Space:** O(A × B) - stores entire graph
- **Best for:** Finding optimal solutions

### DFS (Depth-First Search)
- **Finds any solution** (not necessarily shortest)
- **Time:** O(A × B) worst case
- **Space:** O(A + B) - recursion depth
- **Best for:** Memory-constrained scenarios

### Full Graph vs. Lazy
- **Full Graph:** Pre-builds complete state-space (faster search, more memory)
- **Lazy:** Builds graph during search (slower search, less memory)

### Algorithm Selection Guide

| Scenario | Recommended Algorithm |
|----------|----------------------|
| Need shortest solution | **BFS Full** |
| Limited memory | **DFS Lazy** |
| Large state space | **BFS Lazy** |
| Small state space | **BFS Full** |

---

## 📁 Project Structure

```
Water-Jug-Problem/
├── Water-Jug-Problem.sln          # Visual Studio solution
├── README.md                      # This file
├── LICENSE                        # MIT License
│
└── Water-Jug-Problem/             # Source code directory
    ├── Main.cpp                   # Entry point
    ├── ConsoleUI.h/cpp            # I/O handling
    ├── AlgorithmManager.h/cpp     # Algorithm factory
    │
    ├── AbstractSolver.h/cpp       # Base solver class
    ├── BFSFullGraphSolver.h/cpp   # BFS full implementation
    ├── BFSLazySolver.h/cpp        # BFS lazy implementation
    │
    ├── DirectedGraph.h/cpp        # Graph data structure
    ├── JugState.h                 # State representation
    ├── Step.h                     # Solution step
    ├── Solution.h                 # Solution container
    ├── eOperationType.h           # Operation enum
    │
    ├── input.txt                  # Sample input
    ├── output.txt                 # Generated output
    └── readme.txt                 # Original project readme
```

### File Responsibilities

| File | Purpose |
|------|---------|
| `Main.cpp` | Program entry point, initializes UI |
| `ConsoleUI` | Handles file I/O and user interaction |
| `AlgorithmManager` | Selects and creates appropriate solver |
| `AbstractSolver` | Defines solver interface and common logic |
| `BFSFullGraphSolver` | BFS with pre-built graph |
| `BFSLazySolver` | BFS with lazy graph construction |
| `DirectedGraph` | State-space graph with adjacency lists |
| `JugState` | State as `std::pair<int, int>` |
| `Step` | Represents one operation in solution |
| `Solution` | Container for solution path |
| `eOperationType` | Enum for six jug operations |

---

## 👥 Contributors

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Dan-Ofri">
        <img src="https://github.com/Dan-Ofri.png" width="100px;" alt="Dan Ofri"/><br />
        <sub><b>Dan Ofri</b></sub>
      </a><br />
      <sub>ID: 322527227</sub><br />
      <sub>📧 ofridan@gmail.com</sub>
    </td>
    <td align="center">
      <a href="https://github.com/navehtz">
        <img src="https://github.com/navehtz.png" width="100px;" alt="Naveh Tzadok"/><br />
        <sub><b>Naveh Tzadok</b></sub>
      </a><br />
      <sub>ID: 207080185</sub>
    </td>
  </tr>
</table>

### 🎓 Academic Project
**Institution:** Israeli Academic Institution  
**Course:** Algorithms  
**Grade:** 96/100 → **100/100** (after code quality improvements)

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- **Instructor feedback** that led to code quality improvements:
  - Return adjacency lists by const reference (avoid unnecessary copying)
  - Maintain lexicographically sorted adjacency lists
- Classic Water Jug Problem from AI literature
- State-space search algorithm concepts from computer science curriculum

---

## 📞 Contact

For questions, suggestions, or collaboration opportunities:

- **Email:** ofridan@gmail.com
- **GitHub:** [@Dan-Ofri](https://github.com/Dan-Ofri)
- **LinkedIn:** [Dan Ofri](https://www.linkedin.com/in/dan-ofri)

---

<div align="center">

**⭐ If you found this project helpful, please consider giving it a star!**

Made with ❤️ by [Dan Ofri](https://github.com/Dan-Ofri) & [Naveh Tzadok](https://github.com/navehtz)

</div>
