#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    
    vector<vector<int>> fact(N);
    for(int i = 0; i < N; i++) {
        int x = A[i];
        for(int f = 1; f * f <= x; f++) {
            if(x % f == 0) {
                if(f <= M) {
                    fact[i].push_back(f);
                }
                if(f * f != x && x / f <= M) {
                    fact[i].push_back(x / f);
                }
            }
        }
    }
    
    vector<int> cnt(M + 1, 0);
    int cover = 0;
    int ans = -1;
    for(int l = 0, r = 0; r < N; r++) {
        for(int f : fact[r]) {
            if(++cnt[f] == 1) {
                cover += 1;
            }
        }  
        while(cover == M && l < r) {
            bool thrink = true;
            for(int f : fact[l]) {
                if(cnt[f] == 1) {
                    thrink = false;
                    break;
                } 
            }
            if(thrink) {
                for(int f : fact[l]) {
                    cnt[f] -= 1;
                }
                l += 1;
            } else {
                break;
            }
        }

        if(cover == M) {
            ans = ans == -1 ? A[r] - A[l] : min(ans, A[r] - A[l]);
        }
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
