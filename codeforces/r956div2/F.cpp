#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct node {
    std::array<int, 2> ch = {-1, -1};
    int last = -1;
};

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto count = [&](int ub) {
        std::vector<node> nodes;
        nodes.push_back(node());

        int64_t res = 0;
        int pre = 0;
        for(int i = 0; i < N; i++) {
            int v = A[i];
            int last = -1;
            int cur = 0;
            bool equal = true;
            for(int j = 30; j >= 0; j--) {
                int bt = (ub & (1 << j)) ? 1 : 0;
                int bs = (v & (1 << j)) ? 1 : 0; 
                
                if(bs == 0) {
                    if(bt == 0) {
                        if(nodes[cur].ch[0] == -1) {
                            equal = false;
                            break;
                        }
                        cur = nodes[cur].ch[0];
                    } else {
                        if(nodes[cur].ch[0] != -1) {
                            last = std::max(last, nodes[nodes[cur].ch[0]].last);
                        } 
                        if(nodes[cur].ch[1] == -1) {
                            equal = false;
                            break;
                        }
                        cur = nodes[cur].ch[1];
                    }
                } else {
                    if(bt == 0) {
                        if(nodes[cur].ch[1] == -1) {
                            equal = false;
                            break;
                        }
                        cur = nodes[cur].ch[1];
                    } else {
                        if(nodes[cur].ch[1] != -1) {
                            last = std::max(last, nodes[nodes[cur].ch[1]].last);
                        }
                        if(nodes[cur].ch[0] == -1) {
                            equal = false;
                            break;
                        }
                        cur = nodes[cur].ch[0];
                    }
                }
            }

            if(equal) {
                last = std::max(last, nodes[cur].last);
            }

            res += std::max(pre, last + 1);
            pre = std::max(pre, last + 1);

            cur = 0;
            for(int j = 30; j >= 0; j--) {
                int b = (v & (1 << j)) ? 1 : 0;
                if(nodes[cur].ch[b] == -1) {
                    nodes.push_back(node());
                    nodes[cur].ch[b] = nodes.size() - 1;
                }
                cur = nodes[cur].ch[b];
                nodes[cur].last = i;
            }
        }

        return res;
    };

    int lo = 0;
    int hi = 0x7FFFFFFF;
    int ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        int64_t cnt = count(mid);
        
        if(cnt >= K) {
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
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
