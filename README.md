# 🚰 Water Jug Problem - State-Space Search Solver

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-brightgreen.svg)](https://www.microsoft.com/windows)
[![Visual Studio](https://img.shields.io/badge/VS-2022-purple.svg)](https://visualstudio.microsoft.com/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

> **C++ implementation of the classic Water Jug Problem using state-space search algorithms (BFS/DFS)**

**Academic Project** | Algorithms Course | **Grade: 96/100 → 100/100** (after code improvements)

---

## 🎯 Overview

This project solves the **Water Jug Problem**: Given two jugs of different capacities and a target volume, find the optimal sequence of operations (fill, empty, pour) to measure exactly the target volume.

**Key Features:**
- ✅ Multiple algorithms: BFS/DFS with Full/Lazy graph construction
- ✅ Clean OOP architecture with abstract base class
- ✅ Optimized: Returns by const reference, lexicographically sorted output
- ✅ File-based I/O with clear formatting

---

## 🚀 Quick Start

### Build & Run

```bash
# Clone
git clone https://github.com/Dan-Ofri/Water-Jug-Problem.git
cd Water-Jug-Problem

# Build (Visual Studio 2022)
build.bat

# Or open Water-Jug-Problem.sln and press F7
```

### Create Input

Create `input.txt` in `Water-Jug-Problem/` folder:
```
5 3 4
BFS
```
- Line 1: `<capacityA> <capacityB> <target>`
- Line 2: Algorithm (`BFS`, `DFS`, `BFS_LAZY`, `DFS_LAZY`)

### Run & Check Output

```bash
.\x64\Release\Water-Jug-Problem.exe
```

Output in `output.txt`:
```
(0,0) --FillA--> (5,0)
(5,0) --PourAB--> (2,3)
(2,3) --EmptyB--> (2,0)
(2,0) --PourAB--> (0,2)
(0,2) --FillA--> (5,2)
(5,2) --PourAB--> (4,3)

Total steps: 6
```

---

## 🏗️ Architecture

```
AlgorithmManager
    ↓
AbstractSolver (base class)
    ↓
BFSFullGraph | BFSLazy | DFSFull | DFSLazy
    ↓
DirectedGraph (state-space graph)
    ↓
JugState (std::pair<int, int>)
```

**Key Components:**
- `DirectedGraph` - State-space graph with adjacency lists
- `AbstractSolver` - Base class for all solving strategies
- `AlgorithmManager` - Factory pattern for algorithm selection
- `ConsoleUI` - File I/O handling

---

## 💻 Usage Examples

### Example 1: Classic Die Hard Problem
```
3 5 4
BFS
```

### Example 2: Larger Jugs
```
8 5 3
BFS
```

### Example 3: Impossible Problem
```
6 9 5
BFS
```
→ Output: `No solution found.` (5 is not a multiple of gcd(6,9)=3)

**Operations:**
- `FillA/FillB` - Fill jug to capacity
- `EmptyA/EmptyB` - Empty jug completely
- `PourAB/PourBA` - Pour from one jug to another

---

## 🔍 Algorithm Comparison

| Algorithm | Best For | Time | Space |
|-----------|----------|------|-------|
| **BFS** | Shortest solution | O(A×B) | O(A×B) |
| **DFS** | Any solution | O(A×B) | O(A+B) |
| **Full Graph** | Fast search | - | More memory |
| **Lazy** | Large state space | - | Less memory |

**Recommendation:** Use `BFS` for optimal solutions (shortest path).

**Mathematical Note:** Solution exists iff `C ≤ max(A,B)` and `C` is divisible by `gcd(A,B)`.

---

## 📁 Project Structure

```
Water-Jug-Problem/
├── README.md                      # This file
├── QUICK_START.md                 # Detailed quick start
├── build.bat                      # Build automation
├── LICENSE                        # MIT License
└── Water-Jug-Problem/
    ├── Main.cpp                   # Entry point
    ├── DirectedGraph.h/cpp        # Graph implementation
    ├── AbstractSolver.h/cpp       # Base solver
    ├── BFSFullGraphSolver.h/cpp   # BFS implementation
    ├── AlgorithmManager.h/cpp     # Algorithm factory
    └── ConsoleUI.h/cpp            # I/O handling
```

---

## 👥 Contributors

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Dan-Ofri">
        <img src="https://github.com/Dan-Ofri.png" width="80px;" alt="Dan Ofri"/><br />
        <sub><b>Dan Ofri</b></sub>
      </a><br />
      <sub>📧 ofridan@gmail.com</sub>
    </td>
    <td align="center">
      <a href="https://github.com/navehtz">
        <img src="https://github.com/navehtz.png" width="80px;" alt="Naveh Tzadok"/><br />
        <sub><b>Naveh Tzadok</b></sub>
      </a>
    </td>
  </tr>
</table>

**Code Quality Improvements:**
- ✅ Return adjacency lists by const reference (avoid copying)
- ✅ Maintain lexicographically sorted adjacency lists
- ✅ Clean OOP design with clear separation of concerns

---

## 📜 License

MIT License - see [LICENSE](LICENSE) file.

---

<div align="center">

**⭐ Found this helpful? Give it a star!**

Made with ❤️ by [Dan Ofri](https://github.com/Dan-Ofri) & [Naveh Tzadok](https://github.com/navehtz)

</div>
