int maxSum(int* nums, int numsSize, int k) {
    const long long MOD = 1000000007LL;
    int bitCount[30] = {0};

    for (int i = 0; i < numsSize; i++) {
        for (int bit = 0; bit < 30; bit++) {
            if ((nums[i] >> bit) & 1) {
                bitCount[bit]++;
            }
        }
    }

    long long result = 0;

    for (int i = 0; i < k; i++) {
        long long currentNum = 0;

        for (int bit = 0; bit < 30; bit++) {
            if (bitCount[bit] > 0) {
                currentNum |= (1LL << bit);
                bitCount[bit]--;
            }
        }

        result = (result + currentNum * currentNum) % MOD;
    }

    return (int) result;
}