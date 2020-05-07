
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int t,a,b;
    cin >> t;
    for(int q=0; q<t; q++){
        cin >> a >> b;
        if (b>a) swap(a,b);
        if(a>2*b){
            cout << "NO" << endl;
        }
        else{
            a%=3;
            b%=3;
            if(b>a) swap(a,b);

            if((a==0 && b==0) || (a==2 && b == 1)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}
