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
    int K, N;
    cin >> K >> N;
    
    vector<bool> rem(N + 1, false);
    int d = 1;
    int tot = 0;
    for(int i = 3; i <= N && tot + d <= N - K; i++) {
        int j = i;
        while(j + d <= N && i < j + d) {
            rem[i++] = true;
        }
        tot += d; 
        d += 1;
    }
    
    vector<int> ans;
    for(int i = 1; i <= N && ans.size() < K; i++) {
        if(!rem[i]) {
            ans.push_back(i);
        }
    }

    for(int i = 0; i < K; i++) {
        cout << ans[i] << " \n"[i == K - 1];
    }
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
