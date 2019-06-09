#include <iostream>
using namespace std;

int main(){
    for(int i = 100; i < 1000; i++){
        int num = i;
        int sum = 0;
        while(num != 0){
            int temp = num % 10;
            sum += (temp * temp * temp);
            num /= 10;
        }
        if(sum == i)
            cout << i << endl;
    }
    return 0;
}