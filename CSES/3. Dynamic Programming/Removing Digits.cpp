
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = 3000000;
    }
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int tmp = i;
        while(tmp > 0){
            int dig = tmp%10;
            if(i - dig >= 0){
                dp[i] = min(dp[i], 1 + dp[i-dig]);
            }
            tmp/=10;
        }
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[n] << endl;
}
