# 🚀 Quick Start - Water Jug Problem

Get running in **2 minutes**!

---

## ⚡ Super Fast Setup

### Option 1: Build from Source

```bash
# Clone
git clone https://github.com/Dan-Ofri/Water-Jug-Problem.git
cd Water-Jug-Problem

# Build
build.bat
# Or open Water-Jug-Problem.sln in Visual Studio and press F7
```

---

## 📝 Create Your First Problem

### 1. Create `input.txt`

In `Water-Jug-Problem/` folder, create `input.txt`:

```
5 3 4
BFS
```

**Format:**
- **Line 1:** `<capacityA> <capacityB> <target>`
- **Line 2:** Algorithm: `BFS`, `DFS`, `BFS_LAZY`, or `DFS_LAZY`

### 2. Run

```bash
.\x64\Release\Water-Jug-Problem.exe
```

### 3. View Results

Check `output.txt`:

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

## 🎮 Try These Examples

### Classic Die Hard Problem
```
3 5 4
BFS
```

### Larger Jugs
```
8 5 3
BFS
```

### Impossible Problem
```
6 9 5
BFS
```
→ Result: `No solution found.`

---

## 🔧 Algorithms

| Algorithm | Use When |
|-----------|----------|
| **BFS** | Want shortest solution (recommended) |
| **DFS** | Want any solution |
| **BFS_LAZY** | Large state space |
| **DFS_LAZY** | Memory constrained |

---

## 📞 Need Help?

- 📖 **Full docs:** [README.md](README.md)
- 📧 **Email:** ofridan@gmail.com
- 🐛 **Issues:** [GitHub Issues](https://github.com/Dan-Ofri/Water-Jug-Problem/issues)

---

**Happy Solving! 🚰**
