#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// int ans = INT_MAX;
bool check(int c, vector<int>& arr, int k){
    int temp = 0;
    int i = 0;
    int n = arr.size();
    while(i < n){
        if(arr[i] <= c){
            temp++;
            i+=2;
        }
        else i++;
    }
    if(temp >= k) return true;
    return false;
}
int main() {
    // int t;
    // cin >> t;
    // while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int left = INT_MAX;
        int right = INT_MIN;
        for(int i = 0; i < n; i++){ 
            cin >> arr[i];
            left = min(left, arr[i]);
            right = max(right, arr[i]);
        }
        int ans = -1;
        while(left <= right){
            long long int mid = (left + right)/2;
            bool temp = check(mid, arr, k);
            if(temp){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        cout << ans << endl;
    // }
    return 0;
}
