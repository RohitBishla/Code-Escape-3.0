#include <bits/stdc++.h>
using namespace std;
// TC: O(1)
// SC: O(1);

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        // If n is odd and m is even our answer always be No else always possible. 
        if(n%2 == 1 && m%2 == 0) cout << "NO" << endl;

        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}