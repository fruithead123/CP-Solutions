
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int div(int x){
    int ans = 0;
    for(int i=1; i*i<=x; i++){
        if(x%i == 0) ans+=2;
        if(i*i == x) ans--;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T,a; cin >> T;
    while(T--){
        cin >> a;
        cout << div(a) << "\n";
    }
}
