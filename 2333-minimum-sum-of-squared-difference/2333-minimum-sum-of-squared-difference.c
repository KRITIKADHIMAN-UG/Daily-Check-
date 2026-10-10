long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2) {
    long long diff[100000];
    long long k = (long long)k1 + k2;
    long long sum = 0;
    int maxDiff = 0;

    for (int i = 0; i < nums1Size; i++) {
        diff[i] = nums1[i] > nums2[i] ? nums1[i] - nums2[i] : nums2[i] - nums1[i];
        sum += diff[i];
        if (diff[i] > maxDiff)
            maxDiff = diff[i];
    }

    if (k >= sum)
        return 0;

    long long freq[100001] = {0};

    for (int i = 0; i < nums1Size; i++)
        freq[diff[i]]++;

    for (int d = maxDiff; d > 0 && k > 0; d--) {
        long long count = freq[d];
        if (count == 0)
            continue;

        long long use = count < k ? count : k;
        freq[d] -= use;
        freq[d - 1] += use;
        k -= use;
    }

    long long ans = 0;

    for (int d = 1; d <= maxDiff; d++)
        ans += freq[d] * d * d;

    return ans;
}