#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int Q;
    cin >> Q;
    
    vector<pair<LL, LL>> A(Q, {0, 0});
    for(int i = 0; i < Q; i++) {
        char C;
        cin >> C;
        cin >> A[i].second;

        if(C == '+') {
            A[i].first = 0;
        } else {
            A[i].first = 1;
        } 
    }

    set<LL> seen;
    map<LL, LL> save;
    seen.insert(0LL);
    for(auto& p : A) {
        LL o = p.first;
        LL x = p.second;

        if(o == 0) {
            seen.insert(x);
        } else {
            if(seen.find(x) == seen.end()) {
                cout << x << '\n';
            } else {
                LL pre = 0LL;
                if(save.find(x) != save.end()) {
                    pre = save[x]; 
                }

                LL mex = pre;
                while(seen.find(mex) != seen.end()) {
                    mex += x;
                }
                save[x] = mex;
                cout << mex << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
