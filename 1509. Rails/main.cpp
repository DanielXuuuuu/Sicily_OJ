#include <iostream>
#include <stack>
using namespace std;

int order[1005];

int main(){
    int N, num;
    bool flag;
    while(cin >> N && N != 0){
        int i = 0;
        while(cin >> num && num != 0){
            order[i++] = num;
            if(i == N){
                stack<int> s;
                int j = 0;
                for(int k = 1; k <= N; k++){
                    s.push(k);
                    while(!s.empty() && s.top() == order[j]){
                        s.pop();
                        j++;
                    }
                }
                if(s.empty()){
                    cout << "Yes" << endl;
                }else
                    cout << "No" << endl;
                i = 0;
            }
        }
        cout << endl;
    }
    return 0;
}