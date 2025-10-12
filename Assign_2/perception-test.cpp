#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double w = 4.65;
    double b = 0.10;
    int xs[10];
    int correct = 0;

    cout << "Enter 10 integer x values:\n";
    for (int i = 0; i < 10; ) {
        if (!(cin >> xs[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number: ";
        } else {
            i++;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nx\tPred(y)\tTrue(t)\tAbsErr\t%Err\tResult\n";

    for (int i = 0; i < 10; i++) {
        double x = xs[i];
        double y = w * x + b;
        double t = 2 * x * x - 4;
        double absErr = fabs(y - t);
        double pctErr = fabs(absErr / t) * 100.0;
        bool ok = absErr <= 1.0;
        cout << x << "\t" << y << "\t" << t << "\t" << absErr << "\t" << pctErr << "%\t" << (ok ? "Correct" : "Incorrect") << endl;
        if (ok) correct++;
    }

    double accuracy = (correct / 10.0) * 100.0;
    cout << "\nAccuracy = " << accuracy << "%\n";
    return 0;
}

