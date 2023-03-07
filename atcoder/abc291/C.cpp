#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

const LL MAX = (LL)2e6;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin  >> S;

    set<LL> vis;
    LL r = 0LL;
    LL c = 0LL;
    vis.insert(0LL);
    for(int i = 0; i < N; i++) {
        if(S[i] == 'U') {
            r += 1LL; 
        } else if(S[i] == 'D') {
            r -= 1LL;
        } else if(S[i] == 'R') {
            c += 1LL;
        } else {
            c -= 1LL;
        }
        
        LL h = r * MAX + c;
        if(vis.find(h) != vis.end()) {
            cout << "Yes" << '\n';
            return;
        }
        vis.insert(h);
    } 

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
