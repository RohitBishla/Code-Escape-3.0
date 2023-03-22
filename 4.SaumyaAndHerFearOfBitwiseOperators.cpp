// Method: 1 (Optimize)
#include <bits/stdc++.h>

using namespace std;

bool ifset(int num , int i){
    if(num&(1<<i)) return true;
    else return false;
}

int main() {
    int tc; cin>>tc;
    while(tc--){
        long long a , b , c; cin >> a >> b >> c;
        long long ans = 1;
        for(int i = 0 ; i <= 21 ; i++){
            int totalSetBits = ifset(a,i) + ifset(b,i) + ifset(c,i);
            if(totalSetBits == 1){
                ans = 0;
                break;
            }
            if(totalSetBits == 3){
                ans *= 4;    
            }
        }
        cout << ans << endl;
    }
    return 0;
}


// Method: 2


#include<bits/stdc++.h>
using namespace std;
// (P|Q) = A , (Q|R) = B and (R|P) = C

string helper(){
    string s;
    for(int i = 0; i < 32; i++){
        s += '?';
    }
    return s;
}

void convert(string& main, string& a, string& b){
    for(int i = 0; i < main.size(); i++){
        if(main[i] == '0'){
            a[i] = '0';
            b[i] = '0';
        }
        else{
            if(a[i] == '0' && b[i] == '?'){
                b[i] = '1';
            }
            else if(a[i] == '?' && b[i] == '0'){
                a[i] = '1';
            }
        }
    }
}

bool isvalid(string& p1, string& p2, string& p3){
    bool flag = true;
    for(int i = 0; i < 32; i++){
        int count = 0;
        if(p1[i] == '1') count++;
        if(p2[i] == '1') count++;
        if(p3[i] == '1') count++;
        if(count == 1){
            flag = false;
            break;
        }
    }
    return flag;
}


int main(void) {
    int t;
    cin >> t;
    while(t--){
        
        int p, q, r;
        cin >> p >> q >> r;
        string p1 = bitset<32> (p).to_string();
        string p2 = bitset<32> (q).to_string();
        string p3   = bitset<32> (r).to_string();
        
        if(!isvalid(p1, p2, p3)){
            cout << 0 << endl;
            continue;
        }
        
        string a = helper();
        string b = helper();
        string c = helper();

        convert(p1, a, b);
        convert(p2, b, c);
        convert(p3, a, c);

        int ans = 1;
        for(int i = 0; i < a.size(); i++){
            int count = 0;
            if(a[i] == '?') count++;
            if(b[i] == '?') count++;
            if(c[i] == '?') count++;

            if(count == 3){
                ans *= 4;
            }
        }
        cout << ans << endl;

    }
    return 0;
}
