#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> A(k, 0);
    for(int i = 0; i < k; i++) {
        int x = 0;
        cin >> x;
        A[i] = x;
    }

    sort(A.begin(), A.end());

    bool ans = false;
    for(int i = 0; i < 2; i++) {
        if(A[k - 1] / n >= m) {
            ans = true;
            break;
        }

        LL sum_eve = 0;
        LL sum_odd = 0;
        for(int j = 0; j < k; j++) {
            int cnt = A[j] / n;
            if(cnt > 1) {
                if(cnt % 2) {
                    sum_odd += cnt;
                } else {
                    sum_eve += cnt;
                }
            }
        }
        
        if(m % 2) {
            if(sum_odd == 0) {
                if(A[k - 1] / n < 3) {
                    ans = false;
                } else {
                    ans = sum_eve - 1 >= m;
                }
            } else {
                sum_odd = sum_odd % 2 ? sum_odd : sum_odd - 1;
                ans = sum_odd + sum_eve >= m;
            }
        } else {
            sum_odd = sum_odd % 2 ? sum_odd - 1 : sum_odd;
            ans = sum_odd + sum_eve >= m;
        }
        
        if(ans) {
            break;
        }
        swap(n, m);
    }
    
    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
