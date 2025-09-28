#include<iostream>
using namespace std;

int main() {
    int amount;
    int parts[7];
    int temp;
    int digits = 0;
    bool printedThousand = false;

    cout << "Enter an amount in figures: ";
    cin >> amount;

    int original_amount = amount;

    if (original_amount < 0) {
        cout << "Negative ";
        return 0;
    }

    if (original_amount > 999999) {
        cout << "Error! Amount too large";
        return 0;
    }

    if (original_amount == 0) {
        cout << "Zero";
        return 0;
    }

    while (amount != 0) {
        temp = amount % 10;
        parts[digits] = temp;
        amount = amount / 10;
        digits++;
    }

    for (int i = digits - 1; i >= 0; i--) {
        temp = parts[i];

        if (i == 5) {
            if (temp == 1) cout << "One Hundred";
            if (temp == 2) cout << "Two Hundred";
            if (temp == 3) cout << "Three Hundred";
            if (temp == 4) cout << "Four Hundred";
            if (temp == 5) cout << "Five Hundred";
            if (temp == 6) cout << "Six Hundred";
            if (temp == 7) cout << "Seven Hundred";
            if (temp == 8) cout << "Eight Hundred";
            if (temp == 9) cout << "Nine Hundred";
            if (temp != 0) cout << " ";
        }

        if (i == 4) {
            if (temp == 0) continue;
            if (temp == 1) {
                i--;
                temp = parts[i];
                if (temp == 0) cout << "Ten Thousand";
                if (temp == 1) cout << "Eleven Thousand";
                if (temp == 2) cout << "Twelve Thousand";
                if (temp == 3) cout << "Thirteen Thousand";
                if (temp == 4) cout << "Fourteen Thousand";
                if (temp == 5) cout << "Fifteen Thousand";
                if (temp == 6) cout << "Sixteen Thousand";
                if (temp == 7) cout << "Seventeen Thousand";
                if (temp == 8) cout << "Eighteen Thousand";
                if (temp == 9) cout << "Nineteen Thousand";
                printedThousand = true;
                cout << " ";
                continue;
            }
            if (temp == 2) cout << "Twenty ";
            if (temp == 3) cout << "Thirty ";
            if (temp == 4) cout << "Forty ";
            if (temp == 5) cout << "Fifty ";
            if (temp == 6) cout << "Sixty ";
            if (temp == 7) cout << "Seventy ";
            if (temp == 8) cout << "Eighty ";
            if (temp == 9) cout << "Ninety ";
        }

        if (i == 3) {
            if (temp == 1) cout << "One Thousand";
            if (temp == 2) cout << "Two Thousand";
            if (temp == 3) cout << "Three Thousand";
            if (temp == 4) cout << "Four Thousand";
            if (temp == 5) cout << "Five Thousand";
            if (temp == 6) cout << "Six Thousand";
            if (temp == 7) cout << "Seven Thousand";
            if (temp == 8) cout << "Eight Thousand";
            if (temp == 9) cout << "Nine Thousand";
            if (temp != 0) {
                printedThousand = true;
                cout << " ";
            }
        }

        if (i == 2) {
            if (temp == 1) cout << "One Hundred";
            if (temp == 2) cout << "Two Hundred";
            if (temp == 3) cout << "Three Hundred";
            if (temp == 4) cout << "Four Hundred";
            if (temp == 5) cout << "Five Hundred";
            if (temp == 6) cout << "Six Hundred";
            if (temp == 7) cout << "Seven Hundred";
            if (temp == 8) cout << "Eight Hundred";
            if (temp == 9) cout << "Nine Hundred";
            if (temp != 0) cout << " ";
        }

        if (i == 1) {
            if (temp == 1) {
                i--;
                temp = parts[i];
                if (temp == 0) cout << "Ten";
                if (temp == 1) cout << "Eleven";
                if (temp == 2) cout << "Twelve";
                if (temp == 3) cout << "Thirteen";
                if (temp == 4) cout << "Fourteen";
                if (temp == 5) cout << "Fifteen";
                if (temp == 6) cout << "Sixteen";
                if (temp == 7) cout << "Seventeen";
                if (temp == 8) cout << "Eighteen";
                if (temp == 9) cout << "Nineteen";
                break;
            }
            if (temp == 2) cout << "Twenty ";
            if (temp == 3) cout << "Thirty ";
            if (temp == 4) cout << "Forty ";
            if (temp == 5) cout << "Fifty ";
            if (temp == 6) cout << "Sixty ";
            if (temp == 7) cout << "Seventy ";
            if (temp == 8) cout << "Eighty ";
            if (temp == 9) cout << "Ninety ";
        }

        if (i == 0) {
            if (temp == 1) cout << "One";
            if (temp == 2) cout << "Two";
            if (temp == 3) cout << "Three";
            if (temp == 4) cout << "Four";
            if (temp == 5) cout << "Five";
            if (temp == 6) cout << "Six";
            if (temp == 7) cout << "Seven";
            if (temp == 8) cout << "Eight";
            if (temp == 9) cout << "Nine";
        }
    }

    // Fix missing "Thousand" when the number is rounded like 600000
    if (original_amount >= 1000 && original_amount % 1000 == 0 && !printedThousand) {
        cout << "Thousand";
    }

    return 0;
}
