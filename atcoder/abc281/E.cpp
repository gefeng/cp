#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    multiset<int> ks;
    multiset<int> ms;

    LL sum = 0LL;
    for(int i = 0; i < N; i++) {
        ms.insert(A[i]);

        if(i >= M - 1) {
            if(i == M - 1) {
                for(int j = 0; j < K; j++) {
                    auto it = ms.begin();
                    sum += *it;
                    ks.insert(*it);
                    ms.erase(it);
                }
            } else {
                int x = A[i - M];
                auto it = ks.find(x);

                if(it != ks.end()) {
                    sum -= x;
                    ks.erase(it);

                    it = ms.begin();
                    sum += *it;
                    ks.insert(*it);
                    ms.erase(it);
                } else {
                    it = ms.find(x);
                    ms.erase(x);
                    
                    it = ms.begin();
                    sum += *it;
                    ks.insert(*it);
                    ms.erase(it);

                    it = prev(ks.end());
                    sum -= *it;
                    ms.insert(*it);
                    ks.erase(it);
                }
            }

            cout << sum << " \n"[i == N - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
