# Disclaimer

This repository serves as a personal space for experimentation and practice, and it is **NOT** representative of my professional coding standards. It primarily houses solutions to math problems, algorithms, and competitive programming exercises that I use to enhance my problem-solving capabilities.

In this context, I prioritize developer speed and efficiency over strict adherence to certain best practices, such as meaningful variable naming, function reusability, and code modularity. For instance, in competitive programming, it is common to use concise variable names like `TC` or `n` instead of more descriptive ones like `testCases` or `numberOfX`. These solutions are **NOT** intended to be production-ready; rather, they are part of my ongoing journey to hone my problem-solving skills. In actual professional software development, I recognize and adhere to industry-standard practices for maintaining clean, efficient, and maintainable code.

**Do NOT use `#using namespace std;` in production!** For small programs (especially in competitive programming) `#using namespace std;` can speed up development and improve readability by reducing verbosity. In these contexts, the chance of name conflicts is lower, and the benefits of quick syntax outweigh the costs.

**Do NOT use `#include <bits/stdc++.h>` in production!** This directive is an optimization meant solely for competitive programming contests, designed to save developer time at the expense of a negligible increase in compilation time. It includes ALL C++ STL libraries, which you most likely do **NOT** want. Additionally, it is specific to GCC and may not be available on other C++ compilers. In production environments, maintaining control over the libraries you include is crucial for clarity, performance, and maintainability.

The indiscriminate use of macros like `#define int long long` is also a poor practice that should **NOT** be applied in production.

# Documentation

## Config
* [Local Configuration](docs/LOCAL_CONFIG.md)

## Competitive Programming Snippets
* [Snippets - Algorithms & Data Structures](docs/SNIPPETS_ALGORITHMS&DS.md)
* [Snippets - Misc](docs/SNIPPETS.md)
