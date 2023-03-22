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
        int n;
        cin >> n;
        int summ = 0;
        int digitSum = 0;
        for(int i = 0; i < n; i++){ 
            int x;
            cin >> x;
            summ += x;
            while(x > 0){
                digitSum += x%10;
                x /= 10;
            }
        }
        int temp = abs(summ - digitSum);
        if(temp%2 == 0) cout << "PIYUSH";
        else cout << "MANAV";
        cout << endl;
        
        
    }
    return 0;
}