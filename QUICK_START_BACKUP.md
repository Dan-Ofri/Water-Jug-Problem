# 🚀 Quick Start Guide - Water Jug Problem

Get up and running in **2 minutes**!

---

## ⚡ Super Fast Setup

### Option 1: Use Pre-Built Release (Fastest! ⚡)

1. **Download** the latest release from [Releases](https://github.com/Dan-Ofri/Water-Jug-Problem/releases)
2. **Extract** the ZIP file
3. **Double-click** `Water-Jug-Problem.exe`
4. **Done!** Check `output.txt` for results

### Option 2: Build from Source

1. **Clone:**
   ```bash
   git clone https://github.com/Dan-Ofri/Water-Jug-Problem.git
   cd Water-Jug-Problem
   ```

2. **Open** `Water-Jug-Problem.sln` in Visual Studio 2022

3. **Build:** Press `F7` or `Ctrl+Shift+B`

4. **Run:** Press `F5` or `Ctrl+F5`

---

## 📝 Creating Your First Problem

### Step 1: Create `input.txt`

Create a file named `input.txt` next to the executable with this content:

```
5 3 4
BFS
```

**Explanation:**
- Line 1: `5 3 4` = Jug A (5L), Jug B (3L), Target (4L)
- Line 2: `BFS` = Use Breadth-First Search algorithm

### Step 2: Run the Program

**Windows:**
```cmd
Water-Jug-Problem.exe
```

**Visual Studio:**
- Press `F5` (Debug) or `Ctrl+F5` (Run without debugging)

### Step 3: View Results

Open `output.txt` to see the solution:

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

## 🎮 Try Different Problems

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
Result: "No solution found." (5 is not a multiple of gcd(6,9)=3)

---

## 🔧 Algorithm Options

You can use different algorithms in line 2 of `input.txt`:

| Algorithm | Description | When to Use |
|-----------|-------------|-------------|
| `BFS` | Breadth-First (Full Graph) | **Best for most cases** - Shortest solution |
| `DFS` | Depth-First (Full Graph) | Any solution (not shortest) |
| `BFS_LAZY` | BFS with lazy graph | Large state spaces |
| `DFS_LAZY` | DFS with lazy graph | Memory-constrained |

**Recommendation:** Start with `BFS` - it finds the shortest solution!

---

## ❓ Common Issues & Solutions

### Issue: "Input file not found"
**Solution:** Make sure `input.txt` is in the **same folder** as the EXE

### Issue: "No solution found"
**Check:**
- Target must be ≤ max(A, B)
- Target must be a multiple of gcd(A, B)

**Example of unsolvable:**
```
6 9 5
```
gcd(6,9) = 3, but 5 is not divisible by 3 → No solution!

### Issue: Program crashes immediately
**Solution:**
- Check `input.txt` format (2 lines, numbers space-separated)
- Use only positive integers
- Valid algorithm name (BFS, DFS, BFS_LAZY, DFS_LAZY)

---

## 📊 Understanding the Output

### Output Format
```
(stateA,stateB) --Operation--> (newA,newB)
```

### Operations Explained

| Operation | Meaning |
|-----------|---------|
| `FillA` | Fill jug A to capacity |
| `FillB` | Fill jug B to capacity |
| `EmptyA` | Empty jug A completely |
| `EmptyB` | Empty jug B completely |
| `PourAB` | Pour from A to B (until A empty or B full) |
| `PourBA` | Pour from B to A (until B empty or A full) |

### Example Trace
```
(0,0) --FillA--> (5,0)    ← Fill A (now has 5L, B has 0L)
(5,0) --PourAB--> (2,3)   ← Pour A→B (A now 2L, B now 3L/full)
(2,3) --EmptyB--> (2,0)   ← Empty B (A still 2L, B now 0L)
```

---

## 🎯 Next Steps

1. ✅ **Try the examples above**
2. 📖 **Read the full [README.md](README.md)** for detailed documentation
3. 🔍 **Explore the source code** to understand the algorithms
4. 🎓 **Experiment with different jug capacities** and targets
5. ⭐ **Star the repository** if you found it helpful!

---

## 📞 Need Help?

- 📧 **Email:** ofridan@gmail.com
- 🐛 **Issues:** [GitHub Issues](https://github.com/Dan-Ofri/Water-Jug-Problem/issues)
- 📖 **Full docs:** [README.md](README.md)

---

**Happy Solving! 🚰💧**
