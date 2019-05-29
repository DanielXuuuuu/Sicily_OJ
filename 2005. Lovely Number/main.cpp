#include <iostream>
#include <utility>
#include <map>
using namespace std;

int main(){
    int N, num;
    while(cin >> N){
    //     map<int, int> m;
    //     for(int i = 0; i < N; i++){
    //         cin >> num;
    //         if(m.find(num) == m.end())
    //             m.insert(std::pair<int, int>(num, 0));
    //         m[num]++;
    //     }
    //     for(auto i : m){
    //         if(i.second % 2 == 1){
    //             cout << i.first << endl;
    //             break;
    //         }
    //     }
    // }


    //异或， 偶数个的数全部异或后都是0
        int res = 0;
        for(int i = 0; i < N; i++){
            cin >> num;
            res ^= num;
        }
        cout << res << endl;
    }
    return 0;
}