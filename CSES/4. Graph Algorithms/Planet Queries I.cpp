
#include <bits/stdc++.h>
using namespace std;

//Preprocess succesors of powers of 2
//For each query, advance according to binary expansion of number

typedef long long ll;

int n,q, planets[200009], succ[200009][30]; //succ[x][y] -> where we land starting from x, taking 2^y steps
int a,b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> planets[i];
        succ[i][0] = planets[i];
    }
    for(int i=1; i<30; i++){
        for(int p=1; p<=n; p++){
            succ[p][i] = succ[succ[p][i-1]][i-1];
        }
    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=0; j<5; j++){
            cout << succ[i][j] << " ";
        }
        cout << endl;
    }
    */

    while(q--){
        cin >> a >> b;
        int ans = a;
        for(int i=0; i<30; i++){
            if(b%2 == 1){
                ans = succ[ans][i];
            }
            b/=2;
        }
        cout << ans << endl;
    }
}
