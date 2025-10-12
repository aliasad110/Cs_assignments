#include <iostream>
#include <iomanip>
using namespace std;
int main() {
double w = 0.0, b = 0.0;      
double a = 0.01;          
double x = 3.0;
double target = 2 * x * x - 4; 
double y, error;
cout << fixed << setprecision(2);
for (int step = 0; step <= 1000; step++) {
y = w * x + b;                
error = target - y;           
w += alpha * error * x;       
b += alpha * error;           

if (step % 100 == 0)
cout << "Step " << setw(4) << step << ": prediction=" << setw(6) << y << ", error=" << setw(6) << error << endl;}
cout << "\nFinal prediction at x=3: " << y << endl;
cout << "Target value: " << target << endl;
cout << "Final w=" << w << ", b=" << b << endl;
return 0;
}