
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[5010][5010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    int m,n;
    cin >> s1;
    cin >> s2;
    m = s1.length();
    n = s2.length();
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
    }
    cout << dp[m][n] << endl;

}
