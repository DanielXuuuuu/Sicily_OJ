#include <iostream>
#include <string>
using namespace std;

int main(){
    string ISBN;
    while(cin >> ISBN){
        int weight = 10, sum = 0;
        for(auto i : ISBN){
            if(i != '-'){
                sum += ((i - '0') * weight);
                weight--;
            }
        }
        int temp = sum % 11;
        if(temp == 0)
            temp = 11;
        if(temp == 1){
            ISBN += "-X";
        }else{
            ISBN += "-";
            ISBN += (11 - temp +'0');
        }
        cout << ISBN << endl;
    }
    return 0;
}