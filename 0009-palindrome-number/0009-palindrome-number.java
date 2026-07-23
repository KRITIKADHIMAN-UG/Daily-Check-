class Solution {
    public boolean isPalindrome(int x) {
        if(x<0 || x%10==0 && x!=0){return false;}
        int half_rev = 0;

        while(half_rev < x){
           half_rev = half_rev*10 + x % 10;
           x = x/10;
        }

        return x==half_rev || x==half_rev/10;
    }
}

// Both odd and even conditions returning at once