#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
double N;
cout << "Enter a positive number: ";
cin >> N;

// Step 1: Choose interval [a, b]
double a = 0;
double b = (N < 1) ? 1 : N;

double m;

// Step 2–5: Repeat until good enough
while (true) {
m = (a + b) / 2; // midpoint
double f = m*m - N; // f(m) = m^2 - N

if (fabs(f) < 0.01) { // stop when close enough
break;
}

if (f > 0) {
b = m; // root is in [a, m]
} else {
a = m; // root is in [m, b]
}
}

cout << fixed << setprecision(2);
cout << "Square root ≈ " << m << endl;

return 0;
}