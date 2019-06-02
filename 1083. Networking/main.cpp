#include <iostream>
#include <limits.h>
#include <memory.h>
using namespace std;

int matrix[51][51];
int dist[51];

int findMin(int n){
    int i, k = -1;
    for(i = 1; i <= n; i++){
        if(dist[i] != 0 && dist[i] != INT_MAX){
            k = i;
            break;
        }
    }
    if(k == -1)
        return k;

    for(i; i <= n; i++){
        if(dist[i] != 0 && dist[i] != INT_MAX && dist[i] < dist[k]){
            k = i;
        }
    }
    return k;
}

int prim(int n){
    int len = 0;
    dist[1] = 0;
    for(int i = 1; i <= n; i++){
        if(matrix[1][i] != 0)
            dist[i] = matrix[1][i];
    }

    while(1){
        int k = findMin(n);
        if(k == -1)
            break;

        len += dist[k];
        
        dist[k] = 0;
        for(int i = 1; i <= n; i++){
            if(matrix[k][i] != 0 && dist[i] != 0){
                if(matrix[k][i] < dist[i])
                    dist[i] = matrix[k][i];
            }
        }
    }
    return len;
}

int main(){
    int p, r, a, b, len;
    while(cin >> p && p != 0){
        cin >> r;
        if(p == 1 && r == 0){
            cout << "0" << endl;
            continue;
        }
        memset(matrix, 0, sizeof(matrix));
        for(int i = 0; i < 51; i++)
            dist[i] = INT_MAX;

        for(int i = 0; i < r; i++){
            cin >> a >> b >> len;
            if(matrix[a][b] > len || matrix[a][b] == 0){
                matrix[a][b] = matrix[b][a] = len;
            }
        }
        cout << prim(p) << endl;
    }
    return 0;
}