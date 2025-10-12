#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int width, height, initialInfected, totalDays = 30, recoveryDays = 5;
    double infectionProb, worsenProb;

    cout << "Enter grid width and height: ";
    cin >> width >> height;

    cout << "Enter initial number of infected individuals: ";
    cin >> initialInfected;

    cout << "Enter infection probability (0..1): ";
    cin >> infectionProb;

    cout << "Enter worsening probability w (0..1): ";
    cin >> worsenProb;

    vector<vector<int>> grid(height, vector<int>(width, 0));

    for (int count = 0; count < initialInfected; count++) {
        int x = rand() % width, y = rand() % height;
        if (grid[y][x] == 0) grid[y][x] = 1;
        else count--;
    }

    cout << "\nInitial grid state:\n";
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int state = grid[row][col];
            if (state == 0) cout << ".";
            else if (state == -1) cout << "R";
            else if (state == 10) cout << "X";
            else cout << state;
        }
        cout << "\n";
    }

    for (int day = 1; day <= totalDays; day++) {
        vector<vector<int>> nextGrid = grid;

        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                int currentState = grid[row][col];

                if (currentState == 0) {
                    bool hasInfectedNeighbor = false;
                    int maxSeverity = 0;
                    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = col + dx[dir], ny = row + dy[dir];
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height &&
                            grid[ny][nx] > 0 && grid[ny][nx] < 10) {
                            hasInfectedNeighbor = true;
                            maxSeverity = max(maxSeverity, grid[ny][nx]);
                        }
                    }

                    if (hasInfectedNeighbor && ((double)rand() / RAND_MAX) < infectionProb)
                        nextGrid[row][col] = 1 + rand() % maxSeverity;
                }

                else if (currentState > 0 && currentState < 10) {
                    if (((double)rand() / RAND_MAX) < worsenProb)
                        nextGrid[row][col] = currentState + 1;
                    else
                        nextGrid[row][col] = currentState - 1;

                    if (nextGrid[row][col] >= 9 && ((double)rand() / RAND_MAX) < worsenProb)
                        nextGrid[row][col] = 10;

                    if (currentState >= recoveryDays && currentState < 9 && day % recoveryDays == 0)
                        nextGrid[row][col] = -1;
                }

                else if (currentState == -1)
                    nextGrid[row][col] = -1;

                else if (currentState == 10)
                    nextGrid[row][col] = 10;
            }
        }

        grid = nextGrid;

        int healthyCount = 0, infectedCount = 0, recoveredCount = 0, deadCount = 0;
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                int state = grid[row][col];
                if (state == 0) healthyCount++;
                else if (state > 0 && state < 10) infectedCount++;
                else if (state == -1) recoveredCount++;
                else if (state == 10) deadCount++;
            }
        }

        cout << "Day " << day << ": Healthy: " << healthyCount
             << ", Infected: " << infectedCount
             << ", Recovered: " << recoveredCount
             << ", Dead: " << deadCount << "\n";
    }

    cout << "\nFinal grid state:\n";
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int state = grid[row][col];
            if (state == 0) cout << ".";
            else if (state == -1) cout << "R";
            else if (state == 10) cout << "X";
            else cout << state;
        }
        cout << "\n";
    }

    return 0;
}
