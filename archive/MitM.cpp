int main(){
    ll md = expo(10LL,9LL)+7LL;
    ll N,K,M;
    cin >> N >> K >> M;
    vector<ll> A(N);
    rep(i,N){
        cin >>A[i]; 
    }

    ll h = N/2;
    vector<ll> A1,A2;
    int i;
    for (i=0;i<h;i++){
        A1.append(A[i]);
    }
    for(;i<N;i++){
        A2.append(A[i]);
    }
    vector<map<ll,ll>> A1m(N+1),A2m(N+1); 
    vector<set<ll>> a1s(N+1),a2s(N+1);
    rep(i,1<<h){
        ll sm = 0;
        ll pc = 0;
        rep(j,h){
            if(i & 1<<j){
                sm += A1[j];
                pc++;
            }
        }
        A1m[pc][sm%M] = A1m[pc][sm%M]+1;
        a1s[pc].insert(sm%M);
        // cout << pc << " "<<sm%M << endl;
    }
    // cout << endl;
    rep(i,1<<(N-h)){
        ll sm = 0;
        ll pc = 0;
        rep(j,(N-h)){
            if(i & 1<<j){
                sm += A2[j];
                pc++;
            }
        }
        A2m[pc][sm%M] = A2m[pc][sm%M]+1;
        // cout << pc << " "<<sm%M << endl;
        a2s[pc].insert(sm%M);
    }


    ll ans = 0;
    rep(i,min(h+1,K+1)){
        ans+= A1m[i][0]*A2m[K-i][0];
        // cerr << a1s[i].size() << endl;
        for(auto x:a1s[i]){
            // cout << i<<" " << x << " "<<A1m[i][x] << " " <<A2m[K-i][M-x] << endl;
            if(a2s[K-i].count(M-x))ans+= A1m[i][x]*A2m[K-i][M-x];
        }
    }
    print(ans%md);
    return 0;
}
