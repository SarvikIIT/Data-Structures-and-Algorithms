# Contributing to Data Structures and Algorithmic Work

Thank you for your interest in contributing to this library! This document provides guidelines for contributing to the project.

## 🚀 Getting Started

1. Fork the repository
2. Clone your fork locally
3. Create a new branch for your feature/fix
4. Make your changes
5. Test your changes thoroughly
6. Submit a pull request

## 📝 Code Style Guidelines

### C++ Standards
- Use C++17 or later
- Follow modern C++ practices
- Use meaningful variable and function names
- Include comprehensive documentation

### Documentation
- Every header file must include detailed documentation
- Document time and space complexity for all algorithms
- Include usage examples in comments
- Use Doxygen-style comments

### Code Organization
- Keep related functionality together
- Use appropriate namespaces if needed
- Separate interface from implementation
- Include proper error handling

## 🧪 Testing

### Test Requirements
- All new algorithms must include test cases
- Test edge cases and boundary conditions
- Verify time complexity claims
- Include performance benchmarks for critical algorithms

### Test Structure
```cpp
void testAlgorithm() {
    // Test case 1: Normal case
    // Test case 2: Edge case
    // Test case 3: Boundary condition
    // Verify results
}
```

## 📋 Pull Request Guidelines

### Before Submitting
- [ ] Code compiles without warnings
- [ ] All tests pass
- [ ] Documentation is updated
- [ ] Code follows style guidelines
- [ ] Performance is acceptable

### PR Description
- Clearly describe what the PR does
- Reference any related issues
- Include test results
- Mention any breaking changes

## 🎯 Areas for Contribution

### High Priority
- Advanced data structures (Fenwick Tree, Sparse Table)
- String algorithms (KMP, Z-algorithm, Suffix Array)
- Number theory algorithms
- Geometry algorithms

### Medium Priority
- More DP patterns and optimizations
- Additional sorting algorithms
- Graph algorithm variants
- Utility functions

### Low Priority
- Code optimization
- Documentation improvements
- Example problems
- Performance benchmarks

## 🐛 Bug Reports

When reporting bugs, please include:
- Clear description of the issue
- Steps to reproduce
- Expected vs actual behavior
- Code snippet if applicable
- Environment details (compiler, OS)

## 💡 Feature Requests

For new features, please:
- Describe the use case
- Explain the expected behavior
- Consider implementation complexity
- Discuss potential alternatives

## 📊 Performance Guidelines

### Optimization Principles
- Profile before optimizing
- Measure actual performance impact
- Consider both time and space complexity
- Document performance characteristics

### Benchmarking
- Use consistent test data
- Run multiple iterations
- Compare with standard implementations
- Report results in documentation

## 🔍 Code Review Process

### Review Checklist
- [ ] Algorithm correctness
- [ ] Code style compliance
- [ ] Documentation completeness
- [ ] Test coverage
- [ ] Performance considerations
- [ ] Security implications

### Review Guidelines
- Be constructive and respectful
- Focus on the code, not the person
- Suggest specific improvements
- Ask questions for clarification
- Approve when all concerns are addressed

## 📚 Documentation Standards

### Header Documentation
```cpp
/**
 * @file algorithm_name.h
 * @brief Brief description of the algorithm
 * 
 * Detailed description including:
 * - What the algorithm does
 * - When to use it
 * - Time/space complexity
 * - Example usage
 * 
 * @author Your Name
 * @version 1.0
 */
```

### Function Documentation
```cpp
/**
 * @brief Brief description of the function
 * @param param1 Description of parameter 1
 * @param param2 Description of parameter 2
 * @return Description of return value
 * 
 * Detailed description of what the function does,
 * including any side effects or special considerations.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
```

## 🏆 Recognition

Contributors will be recognized in:
- README.md contributors section
- Individual file headers
- Release notes
- Project documentation

## 📞 Getting Help

If you need help or have questions:
- Open an issue for discussion
- Check existing documentation
- Review similar implementations
- Ask in pull request comments

## 📄 License

By contributing to this project, you agree that your contributions will be licensed under the MIT License.

---

Thank you for contributing to make this library better! 🎉
