#include <iostream>
#include <string>
using namespace std;

bool play(string a, string b){
    if(a.size() !=  b.size())
        return false;
    int n = a.size(), pos;
    for(int i = 0; i < n; i++){
        if((pos = b.find(a[i])) == -1)
            return false;
        b.erase(pos, 1);
        
    }
    return true;
}

int main(){
    string a, b;
    while(cin >> a >> b){
        if(play(a, b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }

    return 0;
}