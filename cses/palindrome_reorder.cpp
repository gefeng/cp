#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    array<int, 26> cnt{0};
    for(char c : S) {
        cnt[c - 'A']++;
    }

    int n = S.length();
    if(n & 1) {
        bool ok = true;
        int cnt_odd = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] & 1) {
                if(cnt_odd) {
                    ok = false;
                    break;
                }
                cnt_odd++;
            }
        }

        if(!ok) {
            cout << "NO SOLUTION" << '\n';
        } else {
            string prefix = "";
            string suffix = "";
            string mid = "";
            for(int i = 0; i < 26; i++) {
                if(cnt[i] & 1) {
                    mid = (char)(i + 'A');
                    cnt[i]--;
                }
                while(cnt[i]) {
                    prefix.push_back((char)(i + 'A')); 
                    suffix.push_back((char)(i + 'A')); 
                    cnt[i] -= 2;
                }
            } 

            reverse(suffix.begin(), suffix.end());

            cout << prefix + mid + suffix << '\n';
        }
    } else {
        bool ok = true;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] & 1) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            cout << "NO SOLUTION" << '\n';
        } else {
            string prefix = "";
            string suffix = "";
            for(int i = 0; i < 26; i++) {
                while(cnt[i]) {
                    prefix.push_back((char)(i + 'A')); 
                    suffix.push_back((char)(i + 'A')); 
                    cnt[i] -= 2;
                }
            }

            reverse(suffix.begin(), suffix.end());
        
            cout << prefix + suffix << '\n'; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
