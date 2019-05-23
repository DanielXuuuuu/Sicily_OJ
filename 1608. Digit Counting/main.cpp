#include <iostream>
#include <memory.h>
using namespace std;

int c[10] = {0};

void countDigit(int n){
    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp != 0){
            c[temp % 10]++;
            temp /= 10;
        }
    }
}

int main(){ 
    int caseNum;
    int num;
    cin >> caseNum;
    while(caseNum--){
        cin >> num;

        countDigit(num);

        for(int i = 0; i < 10; i++){
            cout << c[i];
            if(i != 9)
                cout << " ";
            else
                cout << endl;
        }
        memset(c, 0, sizeof(c));
    }

    return 0;
}