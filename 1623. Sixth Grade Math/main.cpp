#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y){
    if(x > y) swap(x, y);
    for(int i = x; i > 0; i--){
        if(x % i == 0 && y % i == 0)
            return i;
    }
}

int lcm(int x, int y){
    return x * y / gcd(x, y);
}

int main(){
    int c, x, y;
    cin >> c;
    for(int i = 1; i <= c; i++){
        cin >> x >> y;
        cout << i << " " << lcm(x, y) << " " << gcd(x, y) << endl;
    }

    return 0;
}