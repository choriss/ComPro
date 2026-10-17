// 1点更新・区間和 セグメント木
struct SegTree {
    int n;
    vector<long long> seg;

    SegTree(int N) {
        n = 1;
        while (n < N) n <<= 1;
        seg.assign(2 * n, 0);
    }

    // a[pos] = val
    void update(int pos, long long val) {
        pos += n;
        seg[pos] = val;
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
        }
    }

    // [l, r) の区間和
    long long query(int l, int r) {
        long long res = 0;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) res += seg[l++];
            if (r & 1) res += seg[--r];
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};