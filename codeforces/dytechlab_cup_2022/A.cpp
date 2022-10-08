#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    array<int, 26> cnt{0};
    for(char c : S) {
        cnt[c - 'a']++;
    }

    string ans = "";
    for(int i = 0; i < K; i++) {
        int tot = N / K;
        int mex = -1;
        
        int len = 0;
        for(int j = 0; j < 26; j++) {
            if(cnt[j]) {
                len++; 
            } else {
                break;
            }
        }

        mex = min(len, tot);
        if(len) {
            for(int j = 0; j < 26; j++) {
                if(cnt[j] && len) {
                    cnt[j]--;
                    len--;
                }
            }    
        }

        ans.push_back((char)(mex + 'a'));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
