#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

using namespace std;

// ─────────────────────────────────────────────
//  ANSI Colors
// ─────────────────────────────────────────────
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define DIM     "\033[2m"

// ─────────────────────────────────────────────
//  Display result
// ─────────────────────────────────────────────
void showResult(double result, const string& expr = "") {
    cout << fixed << setprecision(6);
    if (!expr.empty())
        cout << DIM << "  " << expr << "\n" << RESET;
    cout << GREEN << BOLD << "  ==> " << result << RESET << "\n";
}

// ─────────────────────────────────────────────
//  Factorial
// ─────────────────────────────────────────────
long long factorial(int n) {
    if (n < 0 || n > 20) return -1;
    long long r = 1;
    for (int i = 1; i <= n; i++) r *= i;
    return r;
}

// ─────────────────────────────────────────────
//  Help table
// ─────────────────────────────────────────────
void showHelp() {
    cout << "\n" << BOLD << CYAN
         << "╔══════════════════════════════════════════════════════╗\n"
         << "║            ADVANCED CALCULATOR  v2.0                ║\n"
         << "║              Command-based interface                 ║\n"
         << "╚══════════════════════════════════════════════════════╝\n"
         << RESET;

    cout << YELLOW << BOLD << "\n  Basic arithmetic:\n" << RESET
         << YELLOW
         << "   add  <a> <b>     →  a + b\n"
         << "   sub  <a> <b>     →  a - b\n"
         << "   mul  <a> <b>     →  a * b\n"
         << "   div  <a> <b>     →  a / b\n"
         << "   mod  <a> <b>     →  a % b   (integers)\n"
         << RESET;

    cout << YELLOW << BOLD << "\n  Powers & roots:\n" << RESET
         << YELLOW
         << "   pow  <base> <exp>  →  base ^ exp\n"
         << "   sqrt <n>           →  square root of n\n"
         << "   root <n> <index>   →  nth root of n\n"
         << RESET;

    cout << YELLOW << BOLD << "\n  Logarithms:\n" << RESET
         << YELLOW
         << "   ln   <n>           →  natural log of n\n"
         << "   log  <n>           →  log base 10 of n\n"
         << "   logn <base> <n>    →  log base <base> of n\n"
         << RESET;

    cout << YELLOW << BOLD << "\n  Trigonometry (angles in degrees):\n" << RESET
         << YELLOW
         << "   sin  <angle>       →  sine\n"
         << "   cos  <angle>       →  cosine\n"
         << "   tan  <angle>       →  tangent\n"
         << RESET;

    cout << YELLOW << BOLD << "\n  Conversions:\n" << RESET
         << YELLOW
         << "   deg  <radians>     →  radians to degrees\n"
         << "   rad  <degrees>     →  degrees to radians\n"
         << RESET;

    cout << YELLOW << BOLD << "\n  Other:\n" << RESET
         << YELLOW
         << "   abs  <n>           →  absolute value\n"
         << "   fact <n>           →  factorial (0-20)\n"
         << RESET;

    cout << DIM
         << "\n  help               →  show this menu\n"
         << "  exit               →  quit the program\n"
         << RESET << "\n";
}

// ─────────────────────────────────────────────
//  Parse and execute a command
// ─────────────────────────────────────────────
bool runCommand(const string& line) {
    istringstream ss(line);
    string cmd;
    ss >> cmd;

    if (cmd.empty()) return true;

    // Lowercase the command
    for (char& c : cmd) c = tolower(c);

    if (cmd == "exit" || cmd == "quit") return false;
    if (cmd == "help" || cmd == "?") { showHelp(); return true; }

    double a = 0, b = 0;

    // ── Commands with TWO arguments ──────────
    if (cmd == "add" || cmd == "sub" || cmd == "mul" || cmd == "div" ||
        cmd == "mod" || cmd == "pow" || cmd == "root" || cmd == "logn") {

        if (!(ss >> a >> b)) {
            cout << RED << "  ✗ '" << cmd << "' requires two arguments.\n"
                 << "    Example: " << cmd << " 4 2\n" << RESET;
            return true;
        }

        if (cmd == "add") showResult(a + b, to_string(a) + " + " + to_string(b));
        else if (cmd == "sub") showResult(a - b, to_string(a) + " - " + to_string(b));
        else if (cmd == "mul") showResult(a * b, to_string(a) + " * " + to_string(b));
        else if (cmd == "div") {
            if (b == 0) cout << RED << "  ✗ Error: Division by zero.\n" << RESET;
            else showResult(a / b, to_string(a) + " / " + to_string(b));
        }
        else if (cmd == "mod") {
            if ((int)b == 0) cout << RED << "  ✗ Error: Modulo by zero.\n" << RESET;
            else showResult((int)a % (int)b, to_string((int)a) + " % " + to_string((int)b));
        }
        else if (cmd == "pow") {
            showResult(pow(a, b), to_string(a) + " ^ " + to_string(b));
        }
        else if (cmd == "root") {
            if (b == 0) cout << RED << "  ✗ Error: Root index cannot be 0.\n" << RESET;
            else if (a < 0 && fmod(b, 2) == 0)
                cout << RED << "  ✗ Error: Even root of negative number is not real.\n" << RESET;
            else {
                double res = (a < 0) ? -pow(-a, 1.0/b) : pow(a, 1.0/b);
                showResult(res, to_string(b) + "-root(" + to_string(a) + ")");
            }
        }
        else if (cmd == "logn") {
            if (a <= 0 || a == 1)
                cout << RED << "  ✗ Error: Base must be > 0 and != 1.\n" << RESET;
            else if (b <= 0)
                cout << RED << "  ✗ Error: Number must be > 0.\n" << RESET;
            else
                showResult(log(b) / log(a), "log_" + to_string(a) + "(" + to_string(b) + ")");
        }
        return true;
    }

    // ── Commands with ONE argument ────────────
    if (!(ss >> a)) {
        cout << RED << "  ✗ '" << cmd << "' requires one argument.\n"
             << "    Example: " << cmd << " 25\n" << RESET;
        return true;
    }

    if (cmd == "sqrt") {
        if (a < 0) cout << RED << "  ✗ Error: Square root of negative number is not real.\n" << RESET;
        else showResult(sqrt(a), "sqrt(" + to_string(a) + ")");
    }
    else if (cmd == "ln") {
        if (a <= 0) cout << RED << "  ✗ Error: Argument must be > 0.\n" << RESET;
        else showResult(log(a), "ln(" + to_string(a) + ")");
    }
    else if (cmd == "log") {
        if (a <= 0) cout << RED << "  ✗ Error: Argument must be > 0.\n" << RESET;
        else showResult(log10(a), "log10(" + to_string(a) + ")");
    }
    else if (cmd == "sin") {
        showResult(sin(a * M_PI / 180.0), "sin(" + to_string(a) + " deg)");
    }
    else if (cmd == "cos") {
        showResult(cos(a * M_PI / 180.0), "cos(" + to_string(a) + " deg)");
    }
    else if (cmd == "tan") {
        if (fmod(a, 180.0) == 90.0)
            cout << RED << "  ✗ Error: Tangent undefined for this angle.\n" << RESET;
        else
            showResult(tan(a * M_PI / 180.0), "tan(" + to_string(a) + " deg)");
    }
    else if (cmd == "abs") {
        showResult(fabs(a), "|" + to_string(a) + "|");
    }
    else if (cmd == "fact") {
        int n = (int)a;
        long long f = factorial(n);
        if (f < 0) cout << RED << "  ✗ Error: Enter an integer between 0 and 20.\n" << RESET;
        else cout << GREEN << BOLD << "  ==> " << n << "! = " << f << RESET << "\n";
    }
    else if (cmd == "deg") {
        showResult(a * 180.0 / M_PI, to_string(a) + " rad in degrees");
    }
    else if (cmd == "rad") {
        showResult(a * M_PI / 180.0, to_string(a) + " deg in radians");
    }
    else {
        cout << RED << "  ✗ Unknown command: '" << cmd << "'\n"
             << "    Type 'help' to see all available commands.\n" << RESET;
    }

    return true;
}

// ─────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────
int main() {
    cout << BOLD << MAGENTA
         << "\n  Advanced Calculator C++ v2.0\n"
         << "  Type 'help' to see all commands, 'exit' to quit.\n"
         << RESET << "\n";

    string line;
    while (true) {
        cout << BOLD << CYAN << "calc> " << RESET;
        if (!getline(cin, line)) break;
        if (!runCommand(line)) break;
    }

    cout << MAGENTA << BOLD << "\n  Goodbye!\n\n" << RESET;
    return 0;
}
