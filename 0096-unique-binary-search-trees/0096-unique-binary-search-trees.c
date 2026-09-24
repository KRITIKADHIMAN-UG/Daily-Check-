int numTrees(int n) {
    // dp[i] stores the number of unique BSTs for i nodes
    int* dp = (int*)calloc(n + 1, sizeof(int));
    
    dp[0] = 1;
    dp[1] = 1;

    for (int nodes = 2; nodes <= n; nodes++) {
        for (int root = 1; root <= nodes; root++) {
            int left = root - 1;
            int right = nodes - root;
            dp[nodes] += dp[left] * dp[right];
        }
    }

    int result = dp[n];
    free(dp);
    return result;
}

