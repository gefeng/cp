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
    int N;
    cin >> N;

    string S;
    cin >> S;
    
    map<int, int> m;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;

        if(S[i] == '1') {
            cnt += 1;
            m[X] -= 1;
        } else {
            m[X] += 1;
        }
    }

    int ans = cnt;
    for(auto& [_, v] : m) {
        cnt += v;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
