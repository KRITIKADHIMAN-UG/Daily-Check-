class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0,-1);
        int currSum = 0;
        int maxlen = 0;
        for(int i=0;i<nums.length;i++){
            currSum += (nums[i] == 0) ? -1:1;
            if(!map.containsKey(currSum)){
                map.put(currSum, i);
            }
            else{
                maxlen = Math.max(maxlen, i - map.get(currSum));
            }
        }
        return maxlen;
    }
}