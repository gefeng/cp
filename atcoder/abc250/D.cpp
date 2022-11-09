#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int MAX = (int)1e6;

void run_case() {
    LL N;
    cin >> N;

    vector<bool> is_prime(MAX + 1, true);
    is_prime[1] = false;
    
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = false;
            }   
        }
    }
    
    vector<int> p;
    p.reserve(MAX);
    for(int i = 2; i <= MAX; i++) {
        if(1LL * i * i * i <= N && is_prime[i]) {
            p.push_back(i);
        }
    }

    LL ans = 0LL;
    int n = p.size();
    for(int i = 0; i < n; i++) {
        LL t = N / p[i];
         
        int lo = i + 1;
        int hi = n - 1;
        int j = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(1LL * p[mid] * p[mid] * p[mid] <= t) {
                j = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if(j != -1) {
            ans += j - i;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
