#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> M(N, {0, 0});
    for(int i = 0; i < N; i++) {
        cin >> M[i].first;
        cin >> M[i].second;
    }
    
    sort(M.begin(), M.end());
    
    int ans = 0;
    int last = 0;
    for(int i = 0; i < N; i++) {
        pair<int, int>& m = M[i];
        int st = m.first;
        int ed = m.second;

        if(st >= last) {
            ans++;
            last = ed;
        } else {
            last = min(last, ed); 
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
