#include <iostream>
#include <vector>
#include <algorithm>  // For std::max
using namespace std;


/*
       
    █▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ 　 █▀▀█ █▀▀▄ █▀▀ █░░░█ █▀▀█ █░░ █░░█ 　 ░░ 　 █▀▀▄ █▀▀█ 
    █░▀░█ █░░█ ▀▀█ █▀▀ ▀▀█ 　 █▄▄█ █░░█ █▀▀ █▄█▄█ █░░█ █░░ █░░█ 　 ▀▀ 　 █░░█ █░░█ 
    ▀░░░▀ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ 　 ▀░░▀ ▀▀▀░ ▀▀▀ ░▀░▀░ ▀▀▀▀ ▀▀▀ ░▀▀▀ 　 ░░ 　 ▀▀▀░ █▀▀▀
*/

/*
	def longestConSubSeq(nums):
	    if len(nums) == 0:
	        return 0
	    if len(nums) == 1:
	        return nums[0]
	    dp = [0] * len(nums)
	    dp[0] = nums[0]
	    n = dp[0]
	    for i in range(1, len(nums)):
	        curr = nums[i]
	        dp[i] = max(dp[i-1] + nums[i], nums[i])
	        n = max(n, dp[i])
	    return n
	print(longestConSubSeq([5, 15, -30, 10, -5, 40, 10]))
*/

int maxContinuousSubseq(onst vector<int>& T) {
	// Size of Vector Array
	int n = T.size();
	// Base Cases
	if (n == 0)
        return 0;
    if (n == 1)
        return T[0];
    vector<int> dp(n);
}