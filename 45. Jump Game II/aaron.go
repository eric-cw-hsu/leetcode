func jump(nums []int) int {
	dp := make([]int, len(nums))

	for i := 0; i < len(nums); i++ {
		steps := nums[i]
		for j := 1; j <= steps && i+j < len(nums); j++ {
			if dp[i+j] == 0 {
				dp[i+j] = dp[i] + 1
			} else {
				dp[i+j] = min(dp[i+j], dp[i]+1)
			}
		}
	}
	return dp[len(nums)-1]
}

func min(num1 int, num2 int) int {
	if num1 < num2 {
		return num1
	}
	return num2
}
