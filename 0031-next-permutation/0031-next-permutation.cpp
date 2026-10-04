class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        // finding the pivot idx i -> a[i] < a[i+1], first element from the last
        int pivot = -1;
        int n = nums.size();

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // if pivot didn't change, we are at our maximum number
        // that can be formed
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        // finding rightmost element greater than pivot
        // and swap it with pivot
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[pivot], nums[i]);
                break;
            }
        }

        // reverse the suffix to get the minimum possible arrangement
        reverse(nums.begin() + pivot + 1, nums.end());

        return nums;
    }
};