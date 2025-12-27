🎯 **Lexical Analyzer in C**  

“Breaking code into tokens — the first step in building a compiler.”

---

## Project Overview
The Lexical Analyzer (Lexer) is a **C-based program** designed to **scan source code and convert it into tokens** — the smallest meaningful units like keywords, identifiers, operators, and literals. This project simulates the first phase of a compiler, helping understand how programming languages are processed internally.  

Standard C compilers handle this automatically, but this project implements it **from scratch**, providing insight into compiler design and parsing logic.  

The project is modular:  
- `main.c` — Entry point and user interface.  
- `lexer.c / lexer.h` — Core logic for tokenizing input.  
- `input.c` — Handles reading source code from files.  
- `tokens.h` — Defines the token structures.  

---

## Features
- Reads source code from files.  
- Identifies and classifies:  
  - **Keywords** (if, else, while, etc.)  
  - **Identifiers** (variable and function names)  
  - **Operators** (+, -, *, /, etc.)  
  - **Literals** (numbers, characters, strings)  
- Ignores whitespace and comments.  
- Modular code for easy maintenance and extension.  
- Provides clear tokenized output for further compiler stages.  

---

## How to Run
1. Compile the code using GCC:

```bash
gcc main.c lexer.c input.c -o lexical
# Lexical-Analyzer
