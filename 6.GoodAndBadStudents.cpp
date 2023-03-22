#include<bits/stdc++.h>
using namespace std;

// Approch: BFS
// TC: O(n^2)
// SC: O(n^2)

int maxDistance(vector<vector<int>>& arr) {
    int n = arr.size();
    queue<pair<int, int>> qu;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                qu.push({i, j});
            }
        }
    }
    if(qu.size() == 0 || qu.size() == n*n) return -1;
    qu.push({-1, -1});
    int ans = 0;
    while(!qu.empty()){
        pair<int, int> p = qu.front();
        qu.pop();
        int i = p.first;
        int j = p.second;
        if(i == -1 && j == -1){
            if(!qu.empty()){ 
                ans++;
                qu.push({-1, -1});
            }
        }
        else{
            if(i > 0 && arr[i - 1][j] == 0){
                arr[i - 1][j] = 1;
                qu.push({i - 1, j});
            }
            if(i < n - 1 && arr[i + 1][j] == 0){
                qu.push({i + 1, j});
                arr[i + 1][j] = 1;
            }
            if(j > 0 && arr[i][j - 1] == 0){
                arr[i][j - 1] = 1;
                qu.push({i, j - 1});
            }
            if(j < n - 1 && arr[i][j + 1] == 0){
                arr[i][j + 1] = 1;
                qu.push({i, j + 1});
            }
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    cout << maxDistance(mat) << endl;
    return 0;
}