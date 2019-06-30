#include <iostream>
#include <queue>
using namespace std;

int main(){
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        queue<int> q;
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        while(q.size() >= 2){
            cout << q.front() << ' ';
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ' ' << endl;
    }
    return 0;
}