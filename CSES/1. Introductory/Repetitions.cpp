
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string seq;
    cin >> seq;
    int longest=1, cnt=1;
    char prev = 0;
    for(char& c : seq){
        if(c == prev){
            cnt++;
        }
        else{
            prev = c;
            longest = max(longest, cnt);
            cnt = 1;
        }
    }
    longest = max(longest, cnt);
    cout << longest << endl;
}
