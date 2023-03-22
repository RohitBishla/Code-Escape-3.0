#include<bits/stdc++.h>
using namespace std;

// Approch: Backtracking Dynamic Programming
// TC: O(n*m^2)
// SC: O(n*m^2)


int helper(int l, int r, int i, vector<vector<int>>& mat, vector<vector<vector<int>>>& dp){
    int n = mat.size();
    if(i == n) return 0;
    
    // cout << l << ", " << r << " => " << i << endl;
    if( l < 0 || r < 0) return 0;
    if(dp[l][r][i] != -1) return dp[l][r][i];
    int m = mat[i].size();
    if(l == m || r == m) return 0;
    int temp1 = mat[i][l];
    int temp2 = mat[i][r];
    int ans = mat[i][l];
    mat[i][l] = 0;
    ans += mat[i][r];
    i++;
    int t = helper(l + 1, r, i, mat, dp);
    t = max(t, helper(l, r + 1, i, mat, dp));
    t = max(t, helper(l + 1, r + 1, i, mat, dp));
    t = max(t, helper(l - 1, r + 1, i, mat, dp));
    t = max(t, helper(l, r, i, mat, dp));
    t = max(t, helper(l - 1, r, i, mat, dp));
    t = max(t, helper(l, r - 1, i, mat, dp));
    t = max(t, helper(l + 1, r - 1, i, mat, dp));
    t = max(t, helper(l - 1, r - 1, i, mat, dp));
    i--;
    mat[i][l] = temp1;
    mat[i][r] = temp2;
    return dp[l][r][i] = ans + t;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    if(m == 0 || n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    
    int ans = helper(0, m - 1, 0, mat, dp) ;
    cout << ans << endl;
    return 0;
}
