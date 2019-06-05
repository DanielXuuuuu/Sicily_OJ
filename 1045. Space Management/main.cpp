#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

//离散化思想，把无限空间的有限元素映射到有限空间
//把大数映射到小数，提高效率

#define N 505

struct Ducument{
    int sx, sy, ex, ey;
}dcmt[N];

int X[2*N], Y[2*N];
int map[N][N] = {0};


int binarySearch(int* array, int num, int n){
    int left = 0, right = n - 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(array[mid] == num) 
            return mid;
        else if(array[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}



int main(){
    int T, num, x, y, width, height;
    cin >> T;
    while(T--){
        cin >> num;
        for(int i = 0; i < num; i++){
            cin >> x >> y >> width >> height;
            dcmt[i].sx = x , dcmt[i].sy = y, dcmt[i].ex = x + width, dcmt[i].ey = y + height;
            X[2 * i] = x, X[2 * i + 1] = x + width, Y[2 * i] = y, Y[2 * i + 1] = y + height;
        }
        
        sort(X, X + 2 * num);
        sort(Y, Y + 2 * num);
        int xcnt = 1;
        int ycnt = 1;
        for(int i = 1; i < 2 * num; i++){
            if(X[i] != X[i - 1]) X[xcnt++] = X[i];
            if(Y[i] != Y[i - 1]) Y[ycnt++] = Y[i];
        }

        memset(map, 0, sizeof(map));

        for(int i = 0; i < num; i++){
            int x1 = binarySearch(X, dcmt[i].sx, xcnt);
            int y1 = binarySearch(Y, dcmt[i].sy, ycnt);
            int x2 = binarySearch(X, dcmt[i].ex, xcnt);
            int y2 = binarySearch(Y, dcmt[i].ey, ycnt);
            for(int i = x1; i < x2; i++){
                for(int j = y1; j < y2; j++){
                    map[i][j] = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < xcnt; i++){
            for(int j = 0; j < ycnt; j++){
                if(map[i][j]){
                    ans += (X[i+1] - X[i]) * (Y[j+1] - Y[j]);
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}