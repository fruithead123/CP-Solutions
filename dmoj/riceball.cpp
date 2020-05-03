#include <bits/stdc++.h>
using namespace std;
int N, balls[410], solved[410][410];

int canMakeBall(int s, int e){
    if(s >= e){
        return 1;
    }
    if(solved[s][e] != -1){
        return solved[s][e];
    }
    for(int i=s; i<=e; i++){
        for(int j=i+1; j<=e; j++){
            int tot1=0, tot2=0;
            for(int k=s; k<=i; k++){
                tot1 += balls[k];
            }
            for(int k=j; k < min(N, e+1); k++){
                tot2 += balls[k];
            }
            if(tot1 == tot2){
                if(canMakeBall(s,i) * canMakeBall(i+1, j-1) * canMakeBall(j,e) == 1){
                    solved[i][j] = 1;
                    return 1;
                }
            }
        }
    }
    solved[s][e] = 0;
    return 0;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    memset(solved, -1, sizeof solved);
    int best = 0;
    for(int i=0; i<N; i++){
        cin >> balls[i];
        solved[i][i] = 1;
        best = max(best, balls[i]);
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(canMakeBall(i,j)){
                int sum = 0;
                for(int k=i; k<=j; k++){
                    sum += balls[k];
                }
                if(sum > best){
                    best = sum;
                }
            }
        }
    }
    cout << best << endl;
}
