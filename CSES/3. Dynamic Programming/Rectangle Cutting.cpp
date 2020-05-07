
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cut[510][510];

int solve(int a, int b){
    if(cut[a][b] != 10000){
        return cut[a][b];
    }
    if(a==0 || b==0){
        cut[a][b] = 10001;
        cut[b][a] = 10001;
        return cut[a][b];
    }
    if(a == b){
        cut[a][b] = 0;
        cut[b][a] = 0;
        return cut[a][b];
    }
    else{
        for(int i=1; i<a; i++){
            cut[a][b] = min(cut[a][b], 1 + solve(a-i, b) + solve(i, b));
        }
        for(int i=1; i<b; i++){
            cut[a][b] = min(cut[a][b], 1 + solve(a, b-i) + solve(a, i));
        }
        return cut[a][b];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> a >> b;
    for(int i=0; i<510; i++){
        for(int j=0; j<510; j++){
            cut[i][j] = 10000;
        }
    }
    cout << solve(a,b) << endl;
}
