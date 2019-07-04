#include <iostream>
#include <algorithm>
using namespace std;

int num[3];

int main(){
    int T;
    int a, b, c;
    cin >> T;
    while(T--){
        int M = 0;
        for(int i = 0; i < 3; i++){
            cin >> num[i];
            if(num[i] > num[M])
                M = i;
        } 
        //cout << M;  
        int sum = 0;
        for(int i = 0; i < 3; i++){
            if(i != M)
                sum += num[i];
        }
        //cout << sum << " " << M << " " << num[M];
        if(sum == num[M]){
            int k = 0;
            for(int i = 0; i < 3; i++){
                if(i != M){
                    if(k == 0){
                        cout << num[i] << " + ";
                        k++;
                    }else{
                        cout << num[i] << " = ";
                    }
                }
            }
            cout << num[M] << endl;
        }else{
            for(int i = 0; i < 3; i++){
                cout << num[i] << " ";
            }
            cout << "NO SUM" << endl;
        }
    }
    return 0;
}