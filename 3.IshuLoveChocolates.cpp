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
        int n, m;
        cin >> n >> m;
        if(n%2 == 1 && m%2 == 0) cout << "NO" << endl;

        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}