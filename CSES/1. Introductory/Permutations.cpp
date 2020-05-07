
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
    }
    if(n == 2 or n == 3){
        cout << "NO SOLUTION" << endl;
    }
    if(n == 4){
        cout << "2 4 1 3\n";
    }
    if(n%2 == 0){
        for(int i=1; i <= n/2; i++){
            cout << i << " " << i + n/2 << " ";
        }
        cout << "\n";
    }
    else{
        for(int i=1; i <= n/2; i++){
            cout << i << " " << i+ n/2 + 1 << " ";
        }
        cout << n/2+1 << endl;
    }
}
