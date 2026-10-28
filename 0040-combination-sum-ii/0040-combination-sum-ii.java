class Solution {
    public void backtrack(int[] candidates, int target, int startIndex,
                          List<Integer> combination,
                          List<List<Integer>> combinations) {
        if (target == 0) {
            combinations.add(new ArrayList<>(combination));
            return;
        }

        for (int i = startIndex; i < candidates.length; i++) {
            if (i > startIndex && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i])
                break;

            combination.add(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1,
                      combination, combinations);
            combination.remove(combination.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> combinations = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), combinations);
        return combinations;
    }
}