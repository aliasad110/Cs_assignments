#include <iostream>
using namespace std;

int main() {
    
    int num1, num2, den1, den2,res;
    char operation;
    cout << "Enter numerator and denominator of first fraction: ";
    cin >> num1 >> den1;
    cout << "Enter numerator and denominator of second fraction: ";
    cin >> num2 >> den2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        cout << "Invalid operation!" << endl;
        return 1;
    }
    else if(operation == '+' ) {
        int result_num = num1 * den2 + num2 * den1;
        int result_den = den1 * den2;
        for (int i = 9999999999; i >=0; i--){
            if (result_num % i == 0 && result_den % i == 0){
                cout<<"Result: "<<result_num/i<<"/"<<result_den/i<<endl;
                break;
            }
        
    }
} 
    else if(operation == '-' )
    {
        int result_num = num1 * den2 - num2 * den1;
        int result_den = den1 * den2;
        for (int i = 9999999999; i >=0; i--){
            if (result_num % i == 0 && result_den % i == 0){
                cout<<"Result: "<<result_num/i<<"/"<<result_den/i<<endl;
                break;
            }
        
    }
}
    else if(operation == '*' )
    {
        int result_num = num1 * num2;
        int result_den = den1 * den2;
       for (int i = 9999999999; i >=0; i--){
            if (result_num % i == 0 && result_den % i == 0){
                cout<<"Result: "<<result_num/i<<"/"<<result_den/i<<endl;
                break;
            }
        
    }
    }
    else if(operation == '/' )
    {
        if(num2 == 0) {
            cout<<"Error! Division by zero."<<endl;
            return 1;
    }

        int result_num = num1 * den2;
        int result_den = den1 * num2;
        for (int i = 9999999999; i >=0; i--){
            if (result_num % i == 0 && result_den % i == 0){
                cout<<"Result: "<<result_num/i<<"/"<<result_den/i<<endl;
                break;
            }
        
    }
}
    return 0;
}