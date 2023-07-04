#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

constexpr int LOG = 20;

void run_case() {
    int N;
    std::cin >> N;

    int64_t K;
    std::cin >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(2 * N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }
    
    for(int i = N + 1; i <= 2 * N; i++) {
        psum[i] = psum[i - 1] + A[i - N - 1];
    }

    std::vector<int> save(N, 0);
    for(int i = 0; i < N; i++) {
        int lo = i;
        int hi = 2 * N - 1;
        int res = 0;

        while(lo <= hi) {
            int mid = (lo + hi) >> 1;

            int64_t sum = psum[mid + 1] - psum[i];
            if(sum <= K) {
                res = mid - i + 1;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        res = std::min(res, N);

        save[i] = res;
    }

    std::vector<std::vector<int>> nxt(LOG + 1, std::vector<int>(N, 0));
    std::vector<std::vector<int64_t>> cnt(LOG + 1, std::vector<int64_t>(N, 0)); 
    for(int i = 0; i < N; i++) {
        nxt[0][i] = (i + save[i]) % N;
        cnt[0][i] = save[i];
    }

    for(int i = 1; i <= LOG; i++) {
        for(int j = 0; j < N; j++) {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
            cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][nxt[i - 1][j]];
        }
    }

    int lo = 1;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        bool ok = false;
        for(int st = 0; st < N; st++) {
            int64_t cnt_ele = 0;
            int v = st;
            for(int i = LOG; i >= 0; i--) {
                if(mid & (1 << i)) {
                    cnt_ele += cnt[i][v];
                    v = nxt[i][v];
                }
            }

            if(cnt_ele >= N) {
                ok = true;
                break;
            }
        }

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
