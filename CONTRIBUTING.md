# Contributing to Water Jug Problem

Thank you for your interest in contributing to the Water Jug Problem project! 🎉

This document provides guidelines for contributing to this repository.

---

## 📋 Table of Contents
- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute)
- [Development Setup](#development-setup)
- [Coding Standards](#coding-standards)
- [Pull Request Process](#pull-request-process)
- [Reporting Bugs](#reporting-bugs)
- [Suggesting Enhancements](#suggesting-enhancements)

---

## 📜 Code of Conduct

This project adheres to a code of conduct that all contributors are expected to follow:

- Be respectful and inclusive
- Accept constructive criticism
- Focus on what is best for the community
- Show empathy towards other community members

---

## 🤝 How Can I Contribute?

### 1. Reporting Bugs
If you find a bug, please create an issue with:
- Clear description of the problem
- Steps to reproduce
- Expected vs. actual behavior
- Input file that caused the issue
- System information (OS, VS version, etc.)

### 2. Suggesting Enhancements
We welcome feature requests! Please include:
- Clear use case for the enhancement
- How it benefits users
- Possible implementation approach (optional)

### 3. Code Contributions
We accept pull requests for:
- Bug fixes
- Performance improvements
- New algorithms (e.g., A*, IDA*)
- Additional features
- Documentation improvements
- Test coverage expansion

---

## 🛠️ Development Setup

### Prerequisites
- Windows 10/11 (64-bit)
- Visual Studio 2022 with C++ Desktop Development workload
- Git for version control

### Setup Steps

1. **Fork the repository**
   ```bash
   # Click "Fork" on GitHub
   ```

2. **Clone your fork**
   ```bash
   git clone https://github.com/YOUR-USERNAME/Water-Jug-Problem.git
   cd Water-Jug-Problem
   ```

3. **Add upstream remote**
   ```bash
   git remote add upstream https://github.com/Dan-Ofri/Water-Jug-Problem.git
   ```

4. **Create a branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

5. **Make your changes**
   - Open `Water-Jug-Problem.sln` in Visual Studio
   - Write your code
   - Build and test

6. **Commit and push**
   ```bash
   git add .
   git commit -m "feat: Add your feature description"
   git push origin feature/your-feature-name
   ```

7. **Create Pull Request**
   - Go to GitHub and click "New Pull Request"
   - Fill in the PR template

---

## 📝 Coding Standards

### C++ Style Guide

1. **Naming Conventions**
   ```cpp
   // Classes: PascalCase
   class DirectedGraph { };
   
   // Functions/Methods: PascalCase
   void AddEdge();
   
   // Variables: camelCase
   int currentState;
   
   // Member variables: m_ prefix
   std::vector<int> m_AdjLists;
   
   // Constants: UPPER_CASE
   const int MAX_CAPACITY = 100;
   ```

2. **Code Organization**
   ```cpp
   // Header files (.h)
   #pragma once
   #include <vector>
   
   class MyClass {
   public:
       // Public methods
       void PublicMethod();
   
   private:
       // Private methods
       void PrivateMethod();
       
       // Member variables
       int m_MemberVar;
   };
   ```

3. **Documentation**
   ```cpp
   /**
    * @brief Brief description of the function
    * @param param1 Description of parameter 1
    * @param param2 Description of parameter 2
    * @return Description of return value
    */
   int MyFunction(int param1, int param2);
   ```

4. **Comments**
   - Use `//` for single-line comments
   - Use `/* */` for multi-line comments
   - Explain **why**, not **what** (code should be self-explanatory)

5. **Error Handling**
   ```cpp
   // Validate inputs
   if (capacity <= 0) {
       throw std::invalid_argument("Capacity must be positive");
   }
   ```

6. **Performance**
   - Return by const reference when possible
   - Avoid unnecessary copying
   - Use move semantics where appropriate
   - Keep collections sorted if ordering matters

---

## 🔄 Pull Request Process

### PR Checklist
Before submitting a pull request, ensure:

- [ ] Code compiles without warnings (Release x64)
- [ ] All existing tests pass
- [ ] New tests added for new features
- [ ] Code follows style guide
- [ ] Documentation updated (README, comments)
- [ ] Commit messages are clear and descriptive
- [ ] No debug code or commented-out code left
- [ ] LICENSE headers maintained in new files

### Commit Message Format
```
<type>: <subject>

<body>

<footer>
```

**Types:**
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation only
- `style`: Formatting, missing semicolons, etc.
- `refactor`: Code restructuring
- `perf`: Performance improvement
- `test`: Adding tests
- `chore`: Build process, dependencies

**Example:**
```
feat: Add A* algorithm for optimal path finding

Implemented A* search algorithm with Manhattan distance heuristic
for finding optimal solutions faster than BFS in large state spaces.

Closes #42
```

### Review Process
1. Maintainers will review your PR
2. Address feedback in new commits
3. Once approved, PR will be merged
4. Branch will be deleted automatically

---

## 🐛 Reporting Bugs

### Bug Report Template

**Title:** Brief description (e.g., "BFS crashes with capacity > 100")

**Description:**
```
Clear description of the bug
```

**To Reproduce:**
```
1. Create input.txt with content:
   150 100 50
   BFS
2. Run Water-Jug-Problem.exe
3. Observe crash
```

**Expected Behavior:**
```
Should find solution without crashing
```

**Actual Behavior:**
```
Program crashes with access violation
```

**Environment:**
- OS: Windows 11 64-bit
- Visual Studio: 2022 version 17.x
- Configuration: Release x64

**Additional Context:**
- Attach `input.txt` and `output.txt` if relevant
- Stack trace or error message
- Any other relevant information

---

## ✨ Suggesting Enhancements

### Enhancement Request Template

**Title:** Brief description of enhancement

**Problem:**
```
What problem does this enhancement solve?
```

**Proposed Solution:**
```
Detailed description of your suggested solution
```

**Alternatives Considered:**
```
Other approaches you've thought about
```

**Benefits:**
- Benefit 1
- Benefit 2

**Potential Drawbacks:**
- Drawback 1

**Implementation Notes:**
```
Any technical details or suggestions
```

---

## 🧪 Testing Guidelines

### Running Tests
```bash
# Build in Debug mode
build.bat Debug

# Run with test inputs
x64\Debug\Water-Jug-Problem.exe
```

### Writing Tests
When adding new features:
1. Create test input files
2. Document expected output
3. Verify edge cases:
   - Invalid inputs
   - Impossible problems
   - Very large capacities
   - Zero capacities

### Test Coverage Areas
- Algorithm correctness
- Edge cases
- Performance benchmarks
- Memory usage
- Input validation
- Output formatting

---

## 📞 Questions?

If you have questions about contributing:

- 📧 **Email:** ofridan@gmail.com
- 💬 **Discussion:** [GitHub Discussions](https://github.com/Dan-Ofri/Water-Jug-Problem/discussions)
- 🐛 **Issues:** [GitHub Issues](https://github.com/Dan-Ofri/Water-Jug-Problem/issues)

---

## 🙏 Thank You!

Your contributions make this project better for everyone. We appreciate your time and effort! ❤️

---

**Happy Coding! 🚰💻**
