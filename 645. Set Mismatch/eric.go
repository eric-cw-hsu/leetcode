func findErrorNums(nums []int) []int {
    mp := make(map[int]int)
    ans := make([]int, 2)
    var val int
    var ok bool
    
    for i := 0; i < len(nums); i++ {
        mp[nums[i]]++
    }

    for i := 1; i <= len(nums); i++ {
        val, ok = mp[i];

        if !ok {
            ans[1] = i
        }

        if val > 1 {
            ans[0] = i
        }
    }

    return ans
} 
