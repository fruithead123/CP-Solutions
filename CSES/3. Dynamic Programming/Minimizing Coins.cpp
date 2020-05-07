
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, coins[110];
    cin >> n >> x;
    int *dp = (int*)malloc((x+5) * sizeof(int));
    for(int i=0; i<=x; i++){
        dp[i] = 2000000;
    }
    for(int i=0; i<n; i++){
        cin >> coins[i];
        if(coins[i] <= x){
            dp[coins[i]] = 1;
        }
    }

    for(int i=0; i<=x; i++){
        for(int c=0; c<n; c++){
            if(i - coins[c] > 0){
                dp[i] = min(1 + dp[i-coins[c]], dp[i]);
            }
        }
    }
    if(dp[x] == 2000000){
        cout << -1 << endl;
    }
    else{
        cout << dp[x] << endl;
    }

}
