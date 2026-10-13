func heightChecker(heights []int) int {
    ans := 0
	sorted := make([]int, len(heights))
	copy(sorted, heights)
	sort.Ints(sorted)
	for i := 0; i < len(heights); i++ {
		if sorted[i] != heights[i] {
			ans++
		}
	}
	return ans
}