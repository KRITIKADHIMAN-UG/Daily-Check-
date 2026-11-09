class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        if (n == 1)
            return k == 0 ? 1 : 0;

        int total = 0;

        // Equal adjacent pairs inside the string
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                total++;
        }

        // Last character and first character are also adjacent
        if (s[n - 1] == s[0])
            total++;

        // Cut an unequal edge
        if (k == total)
            return n - total;

        // Cut an equal edge
        if (k == total - 1)
            return total;

        return 0;
    }
};