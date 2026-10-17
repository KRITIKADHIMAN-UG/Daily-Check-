#define MOD 1000000007
#define MAXN 100005

long long count_total[4 * MAXN];
long long sq_total[4 * MAXN];
long long lazy[4 * MAXN];

void apply(int node, int tleft, int tright, long long x) {
    long long L = tright - tleft + 1;
    long long l_x = x % MOD;
    sq_total[node] = (sq_total[node] + 2 * l_x * count_total[node] + L * l_x % MOD * l_x) % MOD;
    count_total[node] = (count_total[node] + L * l_x) % MOD;
    lazy[node] = (lazy[node] + x) % MOD;
}

void push(int node, int tleft, int tright) {
    if (lazy[node] != 0) {
        int mid = tleft + (tright - tleft) / 2;
        apply(2 * node, tleft, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, tright, lazy[node]);
        lazy[node] = 0;
    }
}

void update(int node, int tleft, int tright, int ql, int qr) {
    if (qr < tleft || tright < ql) {
        return;
    }
    if (ql <= tleft && tright <= qr) {
        apply(node, tleft, tright, 1);
        return;
    }
    push(node, tleft, tright);
    int mid = tleft + (tright - tleft) / 2;
    update(2 * node, tleft, mid, ql, qr);
    update(2 * node + 1, mid + 1, tright, ql, qr);
    
    count_total[node] = (count_total[2 * node] + count_total[2 * node + 1]) % MOD;
    sq_total[node] = (sq_total[2 * node] + sq_total[2 * node + 1]) % MOD;
}

int sumCounts(int* nums, int numsSize) {
    int n = numsSize;
    
    // Clear global/static arrays for the current test case
    for (int i = 0; i < 4 * n; i++) {
        count_total[i] = 0;
        sq_total[i] = 0;
        lazy[i] = 0;
    }
    
    // Track last seen index of each element (nums[i] <= 10^5)
    int* lasti = (int*)malloc(sizeof(int) * 100005);
    for (int i = 0; i <= 100000; i++) {
        lasti[i] = -1;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int prev = lasti[num];
        
        update(1, 0, n - 1, prev + 1, i);
        lasti[num] = i;
        
        ans = (ans + sq_total[1]) % MOD;
    }
    
    free(lasti);
    return (int)ans;
}