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
    int N; LL K;
    cin >> N >> K;

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, int> m_pos;
    vector<LL> path;
    LL cur = 0LL;
    LL sum = 0LL;
    LL cnt = 0LL;
    LL cyc = 0LL;
    LL pre = 0LL;
    while(true) {
        int v = A[cur];
        if(m_pos.find(cur) != m_pos.end()) {
            pre = m_pos[cur];
            cyc = cnt - m_pos[cur];
            break;
        }

        m_pos[cur] = cnt;
        path.push_back(cur);

        sum += v;
        cur = sum % N;
        cnt += 1LL;
    }

    //cout << pre << ' ' << cyc << ' ' << (K - pre) % cyc << '\n';
    
    LL ans = 0LL;
    if(K <= pre) {
        for(int i = 0; i < K; i++) {
            ans += A[path[i]];
        } 
    } else {
        for(int i = 0; i < pre; i++) {
            ans += A[path[i]];
        }

        sum = 0LL;
        for(int i = 0; i < cyc; i++) {
            sum += A[path[pre + i]];
        }

        ans += (K - pre) / cyc * sum;
        
        for(int i = 0; i < (K - pre) % cyc; i++) {
            ans += A[path[pre + i]];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
