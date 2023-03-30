#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    LL L;
    cin >> L;

    int N, M;
    cin >> N >> M;

    vector<pair<LL, LL>> A(N);
    vector<pair<LL, LL>> B(M);

    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second; 
    }

    for(int i = 0; i < M; i++) {
        cin >> B[i].first >> B[i].second;
    }
    
    LL l1 = 1LL;
    LL r1 = 1LL;
    LL l2 = 1LL;
    LL r2 = 1LL;
    LL ans = 0LL;
    for(int i = 0, j = 0; i < N || j < M; ) {
        int v1 = i == N ? A[i - 1].first : A[i].first;
        int v2 = j == M ? B[j - 1].first : B[j].first;
         
        r1 = i == N ? L : l1 + A[i].second - 1; 
        r2 = j == M ? L : l2 + B[j].second - 1;

        if(v1 == v2) {
            ans += min(r1, r2) - max(l1, l2) + 1;
        }

        if(r1 == r2) {
            if(i + 1 < N) {
                l1 = r1 + 1; 
            }
            if(j + 1 < M) {
                l2 = r2 + 1;
            }
            i = min(N, i + 1);
            j = min(M, j + 1);
        } else if(r1 < r2) {
            i += 1;
            l1 = r1 + 1;
        } else {
            j += 1;
            l2 = r2 + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
