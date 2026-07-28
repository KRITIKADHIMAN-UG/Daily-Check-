class Solution {
    public int longestPalindrome(String s) {
        int ans = 0;
        boolean isOdd = false;
        int arr[] = new int[128];

        for(char c : s.toCharArray()){
            arr[c]++;
        }

        for(int no : arr){
            if(no % 2 == 0)ans += no;
            else{
                isOdd = true;
                ans += no - 1;
            }
        }

        return isOdd ? ans + 1 : ans;
    }
}