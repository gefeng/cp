#ifndef CP_SEGMENT_TREE_HPP
#define CP_SEGMENT_TREE_HPP

#include <vector>

struct seg_tree {
    int N, M, H;
    std::vector<int> st;

    seg_tree(int n) {
        build(n);
    }

    seg_tree(std::vector<int>& v) {
        build(v);
    }

    int highest_one_bit(unsigned int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1); 
    }

    void propagate(int i) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }

    void build(int n) {
        N = n;
        M = highest_one_bit(std::max(1, N - 1)) << 2; 
        H = M / 2;
        st.resize(M, 0);
    }

    void build(std::vector<int>& v) {
        build(v.size());
        
        for(int i = 0; i < N; i++) {
            st[i + H] = v[i];
        }
        
        for(int i = H - 1; i > 0; i--) {
            propagate(i);
        }
    }

    void add(int i, int v) {
        st[i + H] = v;
        for(int j = (i + H) >> 1; j > 0; j >>= 1) {
            propagate(j);
        }
    }

    int query(int l, int r) {
        int sum = 0;   
        for(l += H, r += H; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) {
                sum += st[l++];
            }
            if(!(r & 1)) {
                sum += st[r--];
            }
        }
        return sum;
    }
};

#endif
