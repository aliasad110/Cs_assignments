#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const int w = 80;
    const int h = 20;
     double x_min, x_max;
    const double y_min = -1.0, y_max = 1.0;
cout << "Enter x_min (in radians): ";
    while(true){
    if ((cin >> x_min)) {
        break;}
    else {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    }
    
cout << "Enter x_max (radians): ";
    while(true){
        if ((cin >> x_max) || x_max <= x_min) {
            break;}
        else {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number greater than x_min.\n";
        }
    }
char grid[h][w];
for (int r = 0; r < h; r++)
        for (int c = 0; c < w; c++)
            grid[r][c] = ' ';
int midY = h / 2;
int midX = w / 2;
for (int c = 0; c < w; c++)
        grid[midY][c] = '-';
    for (int r = 0; r < h; r++)
        grid[r][midX] = '|';
    grid[midY][midX] = '+'; 
for (int c = 0; c < w; c++) {
        double x = x_min + (x_max - x_min) * c / (w - 1);
        double y = sin(x);
        int row = (int)((y_max - y) / (y_max - y_min) * (h - 1));
        if (row >= 0 && row < h)
            grid[row][c] = '*';}
for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++)
            cout << grid[r][c];
        cout << endl;}
return 0;
}