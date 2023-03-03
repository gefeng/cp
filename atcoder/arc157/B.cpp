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

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'X') {
            cnt += 1;
        }
    }

    if(cnt == K) {
        cout << N - 1 << '\n';
        return;
    }

    if(cnt == 0) {
        cout << max(0, N - K - 1) << '\n';  
        return;
    }

    if(cnt == N) {
        cout << max(0, K - 1) << '\n';
        return;
    }

    int ans = 0;
    if(cnt < K) {
        ans = N - 1;
        K -= cnt;
        
        int l = 0;
        int r = N - 1;
        while(l < N && S[l] == 'Y' && K) {
            ans = max(0, ans - 1);
            l += 1;
            K -= 1;
        }

        while(r > l && S[r] == 'Y' && K) {
            ans = max(0, ans - 1);
            r -= 1;
            K -= 1;
        }

        vector<int> seg;
        for(int i = l + 1; i <= r; i++) {
            if(S[i] == 'Y' && S[i - 1] == 'X') {
                int j = i;
                while(i <= r && S[i] == 'Y') {
                    i += 1;
                }

                if(i <= r) {
                    seg.push_back(i - j);
                }
            } 
        }
        
        sort(seg.begin(), seg.end(), greater<int>());
        
        for(int s : seg) {
            if(K) {
                if(K >= s) {
                    ans = max(0, ans - s - 1);
                    K -= s;
                } else {
                    ans = max(0, ans - K - 1);
                    K = 0;
                }
            }
        }
    } else {
        for(int i = 1; i < N; i++) {
            if(S[i] == 'Y' && S[i - 1] == 'Y') {
                ans += 1;
            } 
        }
        
        vector<int> seg;
        for(int i = 1; i < N; i++) {
            if(S[i] == 'X' && S[i - 1] == 'Y') {
                int j = i;
                while(i < N && S[i] == 'X') {
                    i += 1;
                }

                if(i < N) {
                    seg.push_back(i - j);
                }
            }
        }

        sort(seg.begin(), seg.end());

        for(int s : seg) {
            if(K) {
                if(s <= K) {
                    K -= s;
                    ans += s + 1;
                }
            }
        }

        ans += K;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
