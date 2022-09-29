#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    LL ans = 0LL;
    vector<LL> cost(N + 1, 0LL);

    for(int i = 1; i <= N; i++) {
        cost[i] = i;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            if(S[j - 1] == '1') {
                break; 
            }
            cost[j] = min(cost[j], (LL)i);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(S[i - 1] == '0') {
            ans += cost[i];
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
