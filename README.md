# Calculator
a calculator proyect
<div align="center">

```
 ██████╗ █████╗ ██╗      ██████╗
██╔════╝██╔══██╗██║     ██╔════╝
██║     ███████║██║     ██║
██║     ██╔══██║██║     ██║
╚██████╗██║  ██║███████╗╚██████╗
 ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝
```

# Advanced Calculator C++

**A command-line calculator with 17+ operations, built in modern C++.**

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square&logo=cplusplus)](https://en.cppreference.com/w/cpp/17)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey?style=flat-square)]()
[![Build](https://img.shields.io/badge/build-passing-brightgreen?style=flat-square)]()

</div>

---

## Overview

`calc` is a terminal-based calculator that replaces menu navigation with a clean command prompt. Type a command, get a result — no menus, no clicks.

```
calc> pow 2 16
  2 ^ 16
  ==> 65536.000000

calc> logn 2 1024
  log_2(1024)
  ==> 10.000000

calc> fact 12
  ==> 12! = 479001600
```

---

## Features

| Category         | Operations                                          |
|------------------|-----------------------------------------------------|
| **Arithmetic**   | Addition, Subtraction, Multiplication, Division, Modulo |
| **Powers**       | Power, Square Root, Nth Root                        |
| **Logarithms**   | Natural Log, Log base 10, Log base N                |
| **Trigonometry** | Sine, Cosine, Tangent *(input in degrees)*          |
| **Conversions**  | Degrees ↔ Radians                                   |
| **Other**        | Absolute Value, Factorial (0–20)                    |

- ✅ Input validation on every command
- ✅ Meaningful error messages with usage hints
- ✅ ANSI color output (Linux / macOS / WSL)
- ✅ Zero dependencies — standard C++ only

---

## Getting Started

### Requirements

- `g++` with C++17 support (GCC 7+ or Clang 5+)
- Works on **Linux**, **macOS**, and **Windows** (WSL or MinGW)

### Build & Run

**Using Make:**
```bash
make
./calc
```

**Manually:**
```bash
g++ -std=c++17 -O2 -o calc src/main.cpp -lm
./calc
```

**Windows (MinGW):**
```bash
g++ -std=c++17 -O2 -o calc.exe src/main.cpp -lm
calc.exe
```

---

## Command Reference

### Basic Arithmetic
```
add  <a> <b>      →  a + b
sub  <a> <b>      →  a - b
mul  <a> <b>      →  a * b
div  <a> <b>      →  a / b
mod  <a> <b>      →  a % b  (integers)
```

### Powers & Roots
```
pow   <base> <exp>    →  base ^ exp
sqrt  <n>             →  square root of n
root  <n> <index>     →  nth root of n
```

### Logarithms
```
ln    <n>             →  natural log (base e)
log   <n>             →  log base 10
logn  <base> <n>      →  log base <base> of n
```

### Trigonometry *(angles in degrees)*
```
sin   <angle>         →  sine
cos   <angle>         →  cosine
tan   <angle>         →  tangent
```

### Conversions
```
rad   <degrees>       →  degrees to radians
deg   <radians>       →  radians to degrees
```

### Other
```
abs   <n>             →  absolute value of n
fact  <n>             →  factorial of n  (0 ≤ n ≤ 20)
```

### Meta
```
help                  →  show command reference
exit                  →  quit the program
```

---

## Usage Examples

```bash
calc> sqrt 2
  sqrt(2.000000)
  ==> 1.414214

calc> pow 3 4
  3 ^ 4
  ==> 81.000000

calc> logn 2 256
  log_2(256)
  ==> 8.000000

calc> sin 45
  sin(45.000000 deg)
  ==> 0.707107

calc> root 125 3
  3-root(125)
  ==> 5.000000

calc> rad 270
  270 deg in radians
  ==> 4.712389

calc> fact 15
  ==> 15! = 1307674368000

calc> mod 100 7
  100 % 7
  ==> 2
```

---

## Project Structure

```
.
├── src/
│   └── main.cpp        # Full calculator source
├── Makefile            # Build rules
├── .gitignore          # Ignores binaries and build artifacts
├── LICENSE             # MIT License
└── README.md           # This file
```

---

## Error Handling

The calculator never crashes on bad input — it always shows a helpful message and returns to the prompt.

| Situation                          | Response                                  |
|------------------------------------|-------------------------------------------|
| Division / modulo by zero          | `✗ Error: Division by zero.`              |
| Square root of negative number     | `✗ Error: Not a real number.`             |
| Logarithm of non-positive number   | `✗ Error: Argument must be > 0.`          |
| Even root of negative number       | `✗ Error: Not a real number.`             |
| Factorial out of range             | `✗ Error: Enter an integer between 0–20.` |
| Wrong number of arguments          | `✗ Error + usage example`                 |
| Unknown command                    | Suggests typing `help`                    |

---

## License

Distributed under the **MIT License**. See [LICENSE](LICENSE) for details.

---

<div align="center">
  Made with C++ and ☕
</div>
