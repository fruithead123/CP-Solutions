
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    set<string> perms;
    string str;
    cin >> str;
    sort(str.begin(), str.end());

    do{
        perms.insert(str);
    } while(next_permutation(str.begin(), str.end()));
    cout << perms.size() << "\n";
    for(string s : perms){
        cout << s << "\n";
    }
}
