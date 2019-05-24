#include <iostream>
using namespace std;

//int pos[21] = {0};

int main(){
    int c, num, pos;
    cin >> c;
    while(c--){
        int min = 100, max = -1;
        cin >> num;
        for(int i = 0; i < num; i++){
            cin >> pos;
            if(pos < min)
                min = pos;
            if(pos > max)
                max = pos;
        }
        cout << 2 * (max - min) << endl;
    }
    return 0;
}