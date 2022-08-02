#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] % 2) {
            A[i] += A[i] % 10;
        }
        max_v = max(max_v, A[i]);
    }
    
    unordered_set<int> t_set;
    int v = max_v;
    for(int i = 0; i < 5; i++) {
        t_set.insert(v);
        v += v % 10;
    }

    bool ans = true;
    for(int i = 0; i < N; i++) {
        if(A[i] % 10 == 0 && A[i] != max_v) {
            ans = false;
            break;
        }
        
        int x = A[i];
        x += (max_v - x) / 20 * 20;
        while(x < max_v) {
            x += x % 10;
        }
        
        bool ok = false;
        for(int j = 0; j < 5; j++) {
            if(t_set.count(x)) {
                ok = true;
                break;
            } 
            x += x % 10;
        } 

        if(!ok) {
            ans = false;
            break;
        }
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
