#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, pos;
    string str;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> pos >> str;
        str.erase(pos - 1, 1);
        cout << i << " " << str << endl;
    }

    return 0;
}