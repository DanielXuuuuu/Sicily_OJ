#include <iostream>
#include <vector>
#include <string>
using namespace std;

void code(int n){
    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");
    for(int i = 2; i <= n; i++){
        vector<string> temp(gray);
        for(auto it = gray.begin(); it != gray.end(); it++){
            *it = "0" + *it;
        }
        for(auto it = temp.rbegin(); it != temp.rend(); it++){
            gray.push_back("1" + *it);
        }
    }
    for(auto item : gray){
        cout << item << endl;
    }
}

int main(){
    int n;
    while(cin >> n && n != 0){
        code(n);
        cout << endl;
    }
    return 0;
}