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
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    vector<pair<LL, LL>> A(Q);
    for(int i = 0; i < Q; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    for(auto& q : A) {
        LL t = q.first;
        LL k = q.second;
        
        k -= 1LL;
        
        char c;
        int cnt = 0;
        while(true) {
            if(t == 0LL) {
                c = (char)((S[k] - 'A' + cnt % 3) % 3 + 'A');
                break;
            }
            if(k == 0LL) {
                c = (char)((S[0] - 'A' + cnt + t) % 3 + 'A');
                break;
            }
            
            if(k & 1) {
                cnt += 2;
            } else {
                cnt += 1;
            }

            k /= 2LL;
            t -= 1LL;
        }

        cout << c << '\n';
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
