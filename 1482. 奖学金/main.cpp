#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, vector<int>> a, pair<int, vector<int>> b){
    vector<int> a_grade = a.second;
    vector<int> b_grade = b.second;
    int a_id = a.first, b_id = b.first;
    int a_sum = a_grade[0] + a_grade[1] + a_grade[2];
    int b_sum = b_grade[0] + b_grade[1] + b_grade[2];
    if(a_sum != b_sum){
        return a_sum > b_sum;
    }else if(a_grade[0] != b_grade[0]){
        return a_grade[0] > b_grade[0];
    }else{
        return a_id < b_id;
    }
}

int main(){
    int num, chinese, math, english;
    int temp = 0;
    while(cin >> num){
        if(temp != 0)
            cout << endl;
        temp++;
        
        vector<pair<int, vector<int>>> students;
        for(int i = 1; i <= num; i++){  
            cin >> chinese >> math >> english;
            students.push_back(pair<int, vector<int>>{i,vector<int>{chinese, math, english}});
        }
        sort(students.begin(), students.end(), compare);
        int count = 0;
        for(auto student : students){
            cout << student.first << " " << student.second[0] + student.second[1] + student.second[2] << endl; 
            if(++count == 5)
                break;
        }
    }   

    return 0;
}