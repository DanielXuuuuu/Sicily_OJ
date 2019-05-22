#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    string text;
    while(cin >> text){
        list<int> l;
        int left = 0, right = 0;
        for(int i = 0; i < text.size(); i++){
            if(text[i] == '['){
                left++;
                l.push_back(text[i]);
            }else{
                right++;
                while(right > left){
                    l.push_front('[');
                    left++;
                }
                l.push_back(text[i]);
            }
        }
        while(left > right){
            l.push_back(']');
            right++;
        }
        for(char c : l){
            cout << c;
        }
        cout << endl;
    }
    return 0;
}