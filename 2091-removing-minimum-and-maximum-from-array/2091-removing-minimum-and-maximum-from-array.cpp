class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int size = nums.size();
        int minIdx = 0;
        int maxIdx = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        if (minIdx < size / 2 && maxIdx < size / 2) {
            return max(minIdx, maxIdx) + 1;
        }

        if (minIdx >= size / 2 && maxIdx >= size / 2) {
            return max(size - minIdx, size - maxIdx);
        }

        if (minIdx < size / 2 && maxIdx >= size / 2) {
            return min(
                minIdx + 1 + size - maxIdx,
                min(size - minIdx, maxIdx + 1)
            );
        }

        return min(
            maxIdx + 1 + size - minIdx,
            min(size - maxIdx, minIdx + 1)
        );
    }
};