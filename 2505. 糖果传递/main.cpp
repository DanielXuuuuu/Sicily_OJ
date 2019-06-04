#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int candy[1000005] = {0};
int c[1000005] = {0};

int main(){
    int num;
    lli sum = 0, ans = 0, avg;
    cin >> num;
    for(int i = 1; i <= num; i++){
        cin >> candy[i];
        sum += candy[i];
    }
    avg = sum / num;
    for(int i = 1; i <= num; i++){
        c[i] = c[i - 1] + candy[i] - avg;
    }
    sort(c + 1, c + num + 1);
    lli temp = c[num/2];
    for(int i = 1; i <= num; i++){
        ans += abs(c[i] - temp);
    }
    cout << ans << endl;

    return 0;
}