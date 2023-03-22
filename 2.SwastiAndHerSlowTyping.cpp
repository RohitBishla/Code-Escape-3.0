#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        string t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n && j < m){
            if(s[i] != t[j]){
                j++;
                ans++;
            }
            else{
                i++;
                j++;
            }
        }
        ans += (m - j);
        if(i == n){
            cout << ans << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}