#  User Guide — Advanced Calculator C++ v2.0

---

## 1. Requirements

| Tool     | Minimum version                                    |
|----------|----------------------------------------------------|
| Compiler | `g++` (GCC 7+) or any C++17-compatible compiler   |
| OS       | Linux, macOS, Windows (WSL or MinGW)               |

---

## 2. Compile

```bash
g++ -o calculator calculadora.cpp -lm
```

## 3. Run

```bash
./calculator          # Linux / macOS / WSL
calculator.exe        # Windows with MinGW
```

---

## 4. How it works

The calculator uses a **command prompt**. Instead of picking numbers from a menu, you type a command followed by its arguments directly:

```
calc> sqrt 144
  sqrt(144.000000)
  ==> 12.000000

calc> pow 2 10
  2 ^ 10
  ==> 1024.000000
```

Type `help` at any time to see all commands. Type `exit` to quit.

---

## 5. Command reference

### Basic arithmetic — two arguments

| Command        | Operation      | Example             | Result  |
|----------------|----------------|---------------------|---------|
| `add <a> <b>`  | Addition       | `add 8 3`           | `11`    |
| `sub <a> <b>`  | Subtraction    | `sub 10 4`          | `6`     |
| `mul <a> <b>`  | Multiplication | `mul 6 7`           | `42`    |
| `div <a> <b>`  | Division       | `div 15 4`          | `3.75`  |
| `mod <a> <b>`  | Modulo (%)     | `mod 17 5`          | `2`     |

### Powers & roots

| Command             | Operation      | Example          | Result  |
|---------------------|----------------|------------------|---------|
| `pow <base> <exp>`  | Power          | `pow 2 8`        | `256`   |
| `sqrt <n>`          | Square root    | `sqrt 225`       | `15`    |
| `root <n> <index>`  | Nth root       | `root 27 3`      | `3`     |

### Logarithms

| Command            | Operation         | Example        | Result  |
|--------------------|-------------------|----------------|---------|
| `ln <n>`           | Natural log       | `ln 2.71828`   | `≈ 1`   |
| `log <n>`          | Log base 10       | `log 1000`     | `3`     |
| `logn <base> <n>`  | Log base n        | `logn 2 8`     | `3`     |

### Trigonometry *(angles in degrees)*

| Command       | Operation | Example     | Result      |
|---------------|-----------|-------------|-------------|
| `sin <angle>` | Sine      | `sin 30`    | `0.5`       |
| `cos <angle>` | Cosine    | `cos 60`    | `0.5`       |
| `tan <angle>` | Tangent   | `tan 45`    | `1`         |

### Conversions

| Command        | Operation               | Example       | Result      |
|----------------|-------------------------|---------------|-------------|
| `rad <degrees>`| Degrees → Radians       | `rad 180`     | `3.141593`  |
| `deg <radians>`| Radians → Degrees       | `deg 3.14159` | `≈ 180`     |

### Other

| Command      | Operation                  | Example    | Result     |
|--------------|----------------------------|------------|------------|
| `abs <n>`    | Absolute value             | `abs -42`  | `42`       |
| `fact <n>`   | Factorial (0–20)           | `fact 10`  | `3628800`  |

### Meta commands

| Command | Action                  |
|---------|-------------------------|
| `help`  | Show the command list   |
| `exit`  | Quit the program        |

---

## 6. Error handling

| Situation                        | What the program does                     |
|----------------------------------|-------------------------------------------|
| Division / modulo by zero        | Shows error, stays running                |
| Square root of negative number   | Shows error                               |
| Logarithm of number <= 0         | Shows error                               |
| Factorial > 20                   | Shows error (overflow prevention)         |
| Wrong number of arguments        | Shows error + usage example               |
| Unknown command                  | Suggests typing `help`                    |

---

## 7. Sample session

```
calc> add 100 250
  100 + 250
  ==> 350.000000

calc> pow 3 4
  3 ^ 4
  ==> 81.000000

calc> sqrt 2
  sqrt(2)
  ==> 1.414214

calc> logn 2 1024
  log_2(1024)
  ==> 10.000000

calc> sin 90
  sin(90 deg)
  ==> 1.000000

calc> fact 12
  ==> 12! = 479001600

calc> exit
  Goodbye!
```

---

*Calculator built in C++ — uses standard `<cmath>` from C++17.*
