func rob(nums []int) int {
	var tmp int
	dp := make([]int, 2)
	dp[0] = 0
	dp[1] = nums[0]

	for i := 1; i < len(nums); i++ {
		tmp = dp[0]
		dp[0] = max(dp[0], dp[1])
		dp[1] = tmp + nums[i]
	}
	return max(dp[0], dp[1])
}

func max(num1 int, num2 int) int {
	if num1 > num2 {
		return num1
	}
	return num2
}
