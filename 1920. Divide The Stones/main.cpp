#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

// int stone[50005];

int main(){
    int T, N, num;
    cin >> T;
    while(T--){
        deque<int> stone;
        // memset(stone, 0, sizeof(stone));
        cin >> N;
        long long int turn = 0;
        while(N--){
            cin >> num;
            if(num != 1){
                turn += (num - 1);
            }
        }
        if(turn % 2 == 1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}