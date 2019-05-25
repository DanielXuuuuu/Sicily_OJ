#include <iostream>
#include <set>
using namespace std;

int ap[105] = {0};
int bp[105] = {0};
int cp[105] = {0};
int dp[105] = {0};
int ep[105] = {0};

int main(){
    int caseNum, a, b, c, d, e;
    cin >> caseNum;
    while(caseNum--){
        cin >> a >> b >> c >> d >> e;
        for(int i = 0; i < a; i++)
            cin >> ap[i];
        for(int i = 0; i < b; i++)
            cin >> bp[i];
        for(int i = 0; i < c; i++)
            cin >> cp[i];
        for(int i = 0; i < d; i++)
            cin >> dp[i];
        for(int i = 0; i < e; i++)
            cin >> ep[i];

        set<int> prices;
        int price;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                for(int k = 0; k < d; k++){
                    price = ap[i] + bp[j] + dp[k];
                    if(price >= 0) prices.insert(price);
                }
            }
        }
        for(int i = 0; i < a; i++){
            for(int j = 0; j < c; j++){
                for(int k = 0; k < d; k++){
                    price = ap[i] + cp[j] + dp[k];
                    if(price >= 0) prices.insert(price);
                }
            }
        }
        for(int i = 0; i < d; i++){
            for(int j = 0; j < e; j++){
                price = dp[i] + ep[j];
                if(price >= 0) prices.insert(price);
            }
        }
        
        cout << prices.size() << endl;
    }
    return 0;
}