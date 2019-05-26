#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

string s1, s2, s;
bool dp[205][205]; //s1的前i个字符和s2的前j个字符可以组成s的前i + j个字符

int main(){
    int caseNum;
    cin >> caseNum;
    for(int i = 1; i <= caseNum; i++){
        cin >> s1 >> s2 >> s;
        cout << "Data set " << i << ": ";

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i <= s1.size(); i++){
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s[i - 1];    
        }
        
        for(int j = 1; j <= s2.size(); j++){
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s[j - 1];    
        }

        for(int i = 1; i <= s1.size(); i++){
            for(int j = 1; j <= s2.size(); j++){
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s[i + j - 1]); 
            }
        }
        if(dp[s1.size()][s2.size()])
            cout << "yes" << endl;
        else
            cout << "no" << endl; 
    }
    return 0;
}
