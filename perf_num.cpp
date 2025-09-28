#include <iostream>
using namespace std;

int main() {

int pos_int = 0;
while (pos_int<=0){
    cout<<"Please enter a positive integer: ";
    cin>>pos_int;
    if (pos_int<=0){
        cout<<"Error! Not a positive integer."<<endl;
    }
}
int sum = 0;



for (int i = 1; i<pos_int; i++){
    if(pos_int%i == 0){
    sum += i;
    }
}
if (sum == pos_int){
    cout<<"Perfect number"<<endl;
}
else{
    cout<<"Not a perfect number"<<endl;
}

}