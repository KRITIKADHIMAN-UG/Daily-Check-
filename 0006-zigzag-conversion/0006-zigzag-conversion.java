class Solution {
    public String convert(String s, int numRows) {
        if(s.length() <= numRows || numRows == 1) return s;
        StringBuilder ans=new StringBuilder();
        int skip=(numRows - 2) + numRows;

        // System.out.println(skip+" ");

        for(int i=0; i < numRows; i++){
            ans.append(s.charAt(i));

            int printDia=2 * i;

            int j=i+skip;

            while(j < s.length()){
                if(i != 0 && i < numRows-1) ans.append(s.charAt(j - printDia));

                ans.append(s.charAt(j));
                j+=skip;
            }

            if(i != 0 && i < numRows-1 && j - printDia < s.length()){
                ans.append(s.charAt(j - printDia));
            }

        }

        return ans.toString();
    }
}