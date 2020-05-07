
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    string s;
    cin >> s;
    int lets[26];
    memset(lets, 0, sizeof lets);
    for(char c : s){
        lets[c-'A']++;
    }
    int odd = 0, os=0;
    for(int i=0; i<26; i++){
        if (lets[i]%2 == 1){
            odd++;
            os = i;
        }
    }
    if(odd > 1){
        cout << "NO SOLUTION" << endl;
    }
    else if(odd == 0){
        for(int i=0; i<26; i++){
            for(int j=0; j<lets[i]/2; j++){
                cout << (char)('A'+i);
            }
        }
        for(int i=25; i>=0; i--){
            for(int j=0; j<lets[i]/2; j++){
                cout << (char)('A'+i);
            }
        }
    }
    else{
        for(int i=0; i<26; i++){
            if(i != os){
                for(int j=0; j<lets[i]/2; j++){
                cout << (char)('A'+i);
                }
            }
        }
        for(int i=0; i<lets[os]; i++){
            cout << (char)('A'+os);
        }
        for(int i=25; i>=0; i--){
            if(i != os){
                for(int j=0; j<lets[i]/2; j++){
                cout << (char)('A'+i);
                }
            }
        }
        cout << endl;
    }
}
