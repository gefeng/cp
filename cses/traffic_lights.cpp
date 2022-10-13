#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void run_case() {
    int X, N;
    cin >> X >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<int> seg;
    map<int, int> len;
    seg.insert(0);
    seg.insert(X);
    len[X]++;

    for(int i = 0; i < N; i++) {
        int p = A[i];  
    
        auto ub = seg.upper_bound(p); 
        auto lb = prev(ub);

        if(--len[*ub - *lb] == 0) {
            len.erase(*ub - *lb);
        }

        len[*ub - p]++;
        len[p - *lb]++;
        seg.insert(p);

        cout << len.rbegin()->first << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
