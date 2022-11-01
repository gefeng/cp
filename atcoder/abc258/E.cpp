#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, Q;
    LL X;
    cin >> N >> Q >> X;

    vector<LL> A(2 * N, 0LL);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i + N] = A[i];
    }

    vector<LL> B(Q, 0LL);
    for(int i = 0; i < Q; i++) {
        cin >> B[i]; 
    }

    LL tot = accumulate(A.begin(), A.begin() + N, 0LL);
    LL rem = X % tot;

    vector<LL> cnt_potato(N, X / tot * N); // count potatoes in box if starting with i-th potatoes

    LL sum = 0LL;
    for(int l = 0, r = 0; l < N; l++) {
        if(r < l) {
            r = l;
            sum = 0LL;
        }
        while(sum < rem) {
            sum += A[r++];
        }
        cnt_potato[l] += r - l;
        sum -= A[l];
    }
     vector<int> order(N, -1);
    vector<int> path;
    int loop = -1;
    for(int u = 0, k = 0; ; k++) {
        if(order[u] != -1) {
            loop = k - order[u];
            break;
        }
        order[u] = k;
        path.push_back(u);
        u = (u + cnt_potato[u]) % N;
    }

    int non_loop = path.size() - loop;
    for(LL q : B) {
        q -= 1;
        if(q < non_loop) {
            cout << cnt_potato[path[q]] << '\n';
        } else {
            q = (q - non_loop) % loop + non_loop;
            cout << cnt_potato[path[q]] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
