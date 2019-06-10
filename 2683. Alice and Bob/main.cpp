#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        if((n * n - 1) % 2 == 1){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}