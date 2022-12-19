#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    set<int> pa;
    set<int> pb;

    for(int i = 0; i < N; i++) {
        if(A[i] != i) {
            pa.insert(A[i]);
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] != N - i - 1) {
            pb.insert(A[i]);
            if(pa.find(A[i]) != pa.end()) {
                cnt += 1;
            }
        }
    }
 
    int m = pa.size() - cnt;
    int n = pb.size() - cnt;
    int d = abs(m - n);
    //cout << m << ' ' << n << ' ' << cnt << '\n';
    
    if(cnt == 0) {
        if(pa.size() <= pb.size()) {
            cout << "First" << '\n';
        } else {
            cout << "Second" << '\n';
        }
        return;
    } 

    if(pa.size() <= n) {
        cout << "First" << '\n';
        return;
    } 

    if(pb.size() < m) {
        cout << "Second" << '\n';
        return;
    }

    cout << "Tie" << '\n';
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
