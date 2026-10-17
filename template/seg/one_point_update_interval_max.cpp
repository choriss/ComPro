struct SegTreeMAX {
    int n;
    vector<long long> seg;
    const long long INF = (1LL << 60);

    SegTreeMAX(int N) {
        n = 1;
        while (n < N) n <<= 1;
        seg.assign(2 * n, -INF);
    }

    // a[pos] = val
    void update(int pos, long long val) {
        pos += n;
        seg[pos] = val;
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = max(seg[pos << 1] , seg[pos << 1 | 1]);
        }
    }

    // [l, r) の区間和
    long long query(int l, int r) {
        long long res = -INF;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) res = max(seg[l++],res);
            if (r & 1) res = max(seg[--r],res);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};