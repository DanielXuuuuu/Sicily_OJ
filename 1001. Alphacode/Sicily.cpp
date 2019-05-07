#include <iostream>
#include <string>
using namespace std;


//动态规划，一位一位增加 
int dp[10000];
int decode(string msg){
	int n = msg.size();
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		int x = msg[i - 2] - '0'; //x是当前位的前一位 
		int y = msg[i - 1] - '0'; //y是当前位 
		int z = x * 10 + y;
		if(x == 0)
			dp[i] = dp[i - 1];
		else if(y == 0)
			dp[i] = dp[i - 2];
		else if(z >= 1 && z <= 26)
			dp[i] = dp[i - 1] + dp[i - 2];
		else
			dp[i] = dp[i - 1];
	}
	return dp[n];
}



/* TLE

int decode(string msg, int begin){
	if(begin >= msg.size())
		return 1;
	if((msg[begin] - '0') >= 3){
		return decode(msg, begin + 1);
	}else{
		if(begin < msg.size() - 1 && (msg[begin + 1] - '0') == 0 ){
			return decode(msg, begin + 2);
		}else if(begin < msg.size() - 1 && (msg[begin + 1] - '0') < 7){
				return decode(msg, begin + 1) + decode(msg, begin + 2);
		}else{
			return decode(msg, begin + 1);
		}
	} 
}
*/ 
int main(){
	string msg; 
	while(cin >> msg && msg != "0"){
		cout << decode(msg) << endl;	
	}
	return 0;
} 
