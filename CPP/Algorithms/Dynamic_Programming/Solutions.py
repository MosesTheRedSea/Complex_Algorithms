# DO NOT ADD ANY IMPORTS
from typing import *

class Solutions:
    # DO NOT MODIFY INIT
    def __init__(self):
        pass
    
    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Changes Made
    # Problem 1: Real Estate Profits
    # Explanation and Runtime:
    #This problem had me thinking about Matrix Chain Multiplication or Greedy / Dynamic Programming.
    # It's similiar to one problem we had on our homework, However I chose to go from Matrix Multiplication
    """
    During lecture we learned how given a sequence of matrices m0, m1, m2, ... mn. Where Mi has the dim(mi-1 * mi)
    For matrix multiplication we're supposed to determine the most efficent way to multiply the matrices, 
    minimizing tthe total number of operations.
    For my algorithm instead of dp[i][j] representing the minimum cost to mulyiple matrices mi to mj
    it represents the maximum profit by selling properties between i and j
    Here is ouir recurrence relation
    dp[i][j] = max(profit from selling property k + dp[i][k-1] + dp[k+1][j]) 
              for i <= k <= j
    k is the index where we sell a specific property and break the sequence into two smaller subarrays of properties
    We altered the values array becuase since profit[i] is equal to the current value at index * values[i-1] * values[i+1]
    We could get an out of bounds error for the first and last elements in the list, hence why we added 1 to both ends
    The outter loop i, inner loop j, and most inner loop k  all run in O(n) runtime, total iterations is O(n^3)
    The value we're lookiong for as in the max Real Estate Profit is located in the first array at index n,
    dp[1][n]
    """

    def realEstatePrices(values: List[int]) -> int:
        n = len(values)
        if n == 0:
            return 0
        values = [1] + values + [1]
        dp = [[0] * (n + 2) for _ in range(n + 2)]
        for length in range(1, n + 1):
            for i in range(1, n - length + 2):
                j = i + length - 1
                max_profit = 0
                for k in range(i, j + 1):
                    current_profit = values[i - 1] * values[k] * values[j + 1]
                    total_profit = current_profit + dp[i][k - 1] + dp[k + 1][j]
                    max_profit = max(max_profit, total_profit)
                dp[i][j] = max_profit
        return dp[1][n]
    
    """
        
    ░█▀▀▀ ─█▀▀█ ▀█▀ ░█─── ░█▀▀▀ ░█▀▀▄ 
    ░█▀▀▀ ░█▄▄█ ░█─ ░█─── ░█▀▀▀ ░█─░█ 
    ░█─── ░█─░█ ▄█▄ ░█▄▄█ ░█▄▄▄ ░█▄▄▀
    """
    # Changes Made
    # Problem 2: Warehouse Package Stacking
    # Explanation and Runtime:
    """
    This problem is similiar of the Longest Increasing Subsequence (LIS) problem.
    First, we sort the packages by width (ascending) and by height (descending) for packages with the same width.
    Then, we focus on the height, treating it as an LIS problem.
    We maintain a dynamic list `dp` to track the smallest possible end values of subsequences of each length.
    For each package, we find the correct position in `dp` to either extend the subsequence or replace an element.
    The length of `dp` at the end gives the maximum number of packages we can stack.
    Time complexity: Sorting takes O(n log n), and for each package, we perform a linear scan of `dp`, 
    resulting in an overall time complexity of O(n^2).
    """
    def maxPackages(packages: List[Tuple[int, int]]) -> int:
        if not packages:
            return 0

        packages.sort(key=lambda x: (x[0], -x[1]))

        dp = []
        for _, height in packages:
            pos = len(dp)
            for i in range(len(dp)):
                if dp[i] >= height:
                    pos = i
                    break
            if pos == len(dp):
                dp.append(height)
            else:
                dp[pos] = height

        return len(dp)
    

    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 3: Building Blocks
    # Explanation and Runtime:
    """
    This problem is about finding the minimum number of swaps needed to make two sequences strictly increasing.
    We use dynamic programming to track two possibilities at each index: 
    1. No swap (nums1[i], nums2[i] in original order).
    2. Swap (nums1[i], nums2[i] swapped).
    For each pair of elements at index i, we check both conditions for whether swapping or not swapping results in a valid sequence.
    We then take the minimum swaps needed for the final sequence to be strictly increasing.
    Time complexity: O(n), as we only need to traverse the lists once, performing constant-time comparisons at each step.
    """
    def minSwap(nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        dp = [[float('inf'), float('inf')] for _ in range(n)]
        dp[0][0] = 0
        dp[0][1] = 1
        for i in range(1, n):
            if nums1[i] > nums1[i-1] and nums2[i] > nums2[i-1]:
                dp[i][0] = min(dp[i][0], dp[i-1][0])
            if nums1[i] > nums2[i-1] and nums2[i] > nums1[i-1]:
                dp[i][0] = min(dp[i][0], dp[i-1][1])
            
            if nums1[i] > nums2[i-1] and nums2[i] > nums1[i-1]:
                dp[i][1] = min(dp[i][1], dp[i-1][0] + 1)
            if nums1[i] > nums1[i-1] and nums2[i] > nums2[i-1]:
                dp[i][1] = min(dp[i][1], dp[i-1][1] + 1)
        return min(dp[n-1][0], dp[n-1][1])
    


    
    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 4: Modular Two Sum 
    # Explanation and Runtime: 
    # This Method was fun to the write the descriptions for I used skills we learned in 2050
    """
    This problem is about counting pairs of numbers in a list whose sum is divisible by a given integer k. 
    We use modular arithmetic to track the remainders of each number when divided by k.
    For each number, we compute its remainder num % k. 
    Then, we check if we can find a complement remainder that, when added to the current remainder, sums to a multiple of k.
    We use a dictionary (tracker) to keep count of each remainder, and then calculate the valid pairs based on these remainders.
    Time complexity: O(n), as we iterate through the list once, performing constant-time operations for each element.
    """
    def modTwoSum(A: List[int], k: int) -> int:
        # modular arithmetic
        tracker = {}
        for num in A:
            remainder = num % k
            if remainder in tracker:
                tracker[remainder] += 1
            else:
                tracker[remainder] = 1
        
        count = 0
        
        if 0 in tracker:
            count += (tracker[0] * (tracker[0] - 1)) // 2
        
        for r in range(1, (k // 2) + 1):
            if r == k - r:
                if r in tracker:
                    count += (tracker[r] * (tracker[r] - 1)) // 2
            else:
                if r in tracker and (k - r) in tracker:
                    count += tracker[r] * tracker[k - r]
        return count

    # Problem 5: Maximum Magic Path Power
    # Explanation and Runtime:
    """
    This problem involves finding the maximum "magic power" in a graph of nodes, where each node has energy,
    and edges between nodes have travel times. We need to explore the graph using DFS while staying within a 
    given time limit (maxTime), maximizing the total energy accumulated along the way.
    Graph Representation We store the graph as an adjacency list.
    DFS Traversal We perform DFS starting from node 0, exploring all paths and accumulating energy.
    Time Constraint If time spent exceeds `maxTime`, we stop exploring that path.
    Backtracking After exploring each node, we backtrack to allow for other paths.
    Time Complexity The worst-case time complexity is O(2^n) due to the recursive DFS exploration of all paths.
    However, the runtime of constructing the graph owuld be O(V + E), V the set of vertexes and E the set of edges
    The result is stored in `maxPower[0]`, which is updated during DFS.
    """
    def maximumMagicPathPower(energies: List[int], edges: List[List[int]], maxTime: int) -> int:
        n = len(energies)
        graph = {i: [] for i in range(n)}
        for u, v, time in edges:
            graph[u].append((v, time))
            graph[v].append((u, time))

        maxPower = [0]
        visited = set()

        def dfs(node, timeSpent, currentPower):
            if timeSpent > maxTime:
                return
            if node == 0 and visited:
                maxPower[0] = max(maxPower[0], currentPower)
            wasVisited = node in visited
            if not wasVisited:
                visited.add(node)
                currentPower += energies[node]
            for neighbor, travelTime in graph[node]:
                dfs(neighbor, timeSpent + travelTime, currentPower)
            if not wasVisited:
                visited.remove(node)

        dfs(0, 0, 0)
        return maxPower[0]
        
    # Problem 6: Divide the Harvest
    # Explanation and Runtime:
    """
    This problem is about splitting the harvest into `k+1` portions. We want the smallest portion to be as large as possible.
    We use binary search to find the biggest size for the smallest portion we can get.
    First, we do a binary search to find the largest possible size for the smallest portion. We start by looking at sizes
    between 1 and the total sum of the harvest.
    For each size we check, we see if it’s possible to divide the harvest into at least `k+1` portions of that size.
    After we find the biggest size, we split the harvest into portions and sort them. The second largest portion is the answer.
    The time it takes for the binary search is O(log(sum(quantity))).
    Each check takes O(n), where n is the length of the list.
    So the overall time complexity is O(n * log(sum(quantity))).
    The final result is the second largest portion after sorting.
    """
    def divideTheHarvest(quantity: List[int], k: int) -> int:
        low, high = 1, sum(quantity)
        result = 0
        def canDivide(minPortion):
            portions, currentSum = 0, 0
            for q in quantity:
                currentSum += q
                if currentSum >= minPortion:
                    portions += 1
                    currentSum = 0
            return portions >= k + 1

        while low <= high:
            mid = (low + high) // 2
            if canDivide(mid):
                result = mid
                low = mid + 1
            else:
                high = mid - 1
        portions = []
        currentSum = 0
        for q in quantity:
            currentSum += q
            if currentSum >= result:
                portions.append(currentSum)
                currentSum = 0

        portions.sort()
        if len(portions) < 2:
            return -1
        return portions[1]



    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 7: Coloring Sidewalks 
    # Explanation and Runtime:
    """
    In this problem, we need to color sidewalks with three different colors while minimizing the total time.
    The goal is to make sure no two adjacent sidewalks have the same color.
    We use dynamic programming (dp) to keep track of the minimum time needed to color the sidewalks up to each point.
    Each sidewalk can be colored in three different ways, so we check the minimum time needed for each possible color at each step.
    The first sidewalk is colored with each color, and for the rest, we pick the color that results in the least time, 
    making sure it's not the same as the previous one.
    The time complexity is O(n), where n is the number of sidewalks. For each sidewalk, we check all three colors.

    """
    def coloringSidewalks(time: List[int]) -> int:
        n = len(time)
        dp = [[0]*3 for _ in range(n)]

        for color in range(3):
            dp[0][color] = time[0][color]
        
        for i in range(1, n):
            for color in range(3):
                dp[i][color] = min(dp[i-1][(color+1)%3], dp[i-1][(color+2)%3]) + time[i][color]
        
        return min(dp[n-1])
    
    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 8: Chemical Concoctions
    # Explanation and Runtime:
    """
    In this problem, we have a list of chemical formulas, and we need to figure out the order in which to mix them based on their characters.
    Each formula has some characters, and the formulas are ordered in a way that certain characters should come before others.
    We can think of the problem like a graph where each character is a node. An edge from one character to another means one must come before the other.
    To solve this, we use a technique called topological sorting, which helps us order nodes based on their dependencies.
    First, we build a graph by comparing each pair of consecutive formulas and finding the first differing character.
    We then use this to create edges in the graph. For each character, we also count how many other characters need to come before it (its indegree).
    After building the graph, we can find the characters with no dependencies (indegree 0) and start from there.
    We process each character, reduce the indegree of its neighbors, and add them to the queue if their indegree becomes 0.
    The time complexity is O(n * m), where n is the number of formulas and m is the average length of the formulas.
    
    """
    def chemicalConcoctions(formulas: List[str]) -> str:
        graph = {}
        indegree = {}
        all_chars = set("".join(formulas))

        for i in range(len(formulas) - 1):
            formula1, formula2 = formulas[i], formulas[i + 1]
            for c1, c2 in zip(formula1, formula2):
                if c1 != c2:
                    if c1 not in graph:
                        graph[c1] = set()
                    if c2 not in indegree:
                        indegree[c2] = 0
                    if c2 not in graph[c1]:
                        graph[c1].add(c2)
                        indegree[c2] += 1
                    break
            for c in formula1:
                if c not in indegree:
                    indegree[c] = 0
            for c in formula2:
                if c not in indegree:
                    indegree[c] = 0

        queue = [char for char in all_chars if indegree.get(char, 0) == 0]
        order = []

        while queue:
            char = queue.pop(0)
            order.append(char)
            for neighbor in graph.get(char, []):
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        return "".join(order) if len(order) == len(all_chars) else ""
    

    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 9: Maximum Sum of Non-Adjacent Subsequences
    # Explanation and Runtime:
    """
    This problem asks us to find the maximum sum of a subsequence of numbers, where no two numbers in the subsequence are adjacent.
    We can solve this problem using dynamic programming.
    We create a list `dp` where each element represents the maximum sum we can get by considering elements up to that index.
    At each step, we have two choices:
        Either we skip the current element and take the maximum sum up to the previous element.
        Or we take the current element and add it to the maximum sum up to the element before the previous one.
    We update the `dp` list with the maximum of these two choices for each element.
    Finally, the last element in the `dp` list will give us the maximum sum we can achieve without taking adjacent elements.
    The time complexity is O(n), where n is the length of the list, because we loop through the list only once.
    """
    def maxNonAdjSum(A: List[int]) -> int:
        n = len(A)
        if n == 0:
            return 0
        if n == 1:
            return A[0]

        dp = [0] * n
        dp[0] = A[0]
        dp[1] = max(A[0], A[1])

        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2] + A[i])
        
        return dp[n-1]
    
    # Problem 10: DigitGPT
    # Explanation and Runtime:
    """
    This problem involves checking whether we can adjust the digits in a ticket such that the sums of the two halves are equal.
    The ticket contains digits and stars ('*'). Each star can be changed to any digit between 0 and 9.
    The goal is to check if we can change the stars in the two halves of the ticket to make the sums of the two halves equal.
    We do this by first calculating the sum of digits in each half, then figuring out the maximum adjustment we can make by changing the stars.
    We then check if we can make the sums equal by adjusting the stars in the ticket.
    The algorithm works by:
    1. Dividing the ticket into two halves.
    2. Calculating the sum of digits in each half.
    3. Counting the number of stars in each half.
    4. Determining the possible range of differences between the two halves after adjusting for stars.
    5. If the difference can be adjusted to 0, the ticket is "revivable", meaning the sums of the halves can be made equal.
    The time complexity is O(n), where n is the length of the ticket, because we only loop through the ticket once.
    """
    def reviveStrings(n: int, ticket: str) -> bool:
        half = n // 2
        firstHalfSum = 0
        secondHalfSum = 0
        firstHalfStars = 0
        secondHalfStars = 0

        for i in range(n):
            ch = ticket[i]
            if ch == '*':
                if i < half:
                    firstHalfStars += 1
                else:
                    secondHalfStars += 1
            else:
                digit = int(ch)
                if i < half:
                    firstHalfSum += digit
                else:
                    secondHalfSum += digit

        diff = firstHalfSum - secondHalfSum
        maxFirstHalfAdjustment = 9 * firstHalfStars
        maxSecondHalfAdjustment = 9 * secondHalfStars
        minDiff = diff - maxFirstHalfAdjustment + maxSecondHalfAdjustment
        maxDiff = diff + maxFirstHalfAdjustment - maxSecondHalfAdjustment

        return minDiff <= 0 and maxDiff >= 0
    

    """
        
    ░█▀▀▀ ─█▀▀█ ▀█▀ ░█─── ░█▀▀▀ ░█▀▀▄ 
    ░█▀▀▀ ░█▄▄█ ░█─ ░█─── ░█▀▀▀ ░█─░█ 
    ░█─── ░█─░█ ▄█▄ ░█▄▄█ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 11: Building a Brick Wall
    # Explanation and Runtime:
    """
    This problem is about determining how many ways we can build a wall of length `l` using bricks of given lengths in the list `B`.
    The idea is to calculate the number of ways to reach the length `l` by combining the bricks in different ways.
    The solution uses dynamic programming to solve the problem efficiently.
    We create a list `dp` where `dp[i]` represents the number of ways to build a wall of length i using the available bricks.
    Initially, `dp[0]` is set to 1 because there's one way to build a wall of length 0 (by using no bricks).
    For each brick, we check every possible length from the brick length to `l` and update dp[i] by adding the number of ways to build a wall of length `i - brick` (this shows that we can use the current brick to reach length `i`).
    Finally, the value at `dp[l]` gives the number of ways to build the wall of length l.
    The time complexity of the solution is O(n * l), where `n` is the number of bricks and l is the length of the wall, because we loop through each brick and update the `dp` list for each possible length up to `l`.
    """
    def buildBrickWall(B: List[int], l: int) -> int:
        dp = [0] * (l + 1)
        dp[0] = 1
        for brick in B:
            for i in range(brick, l + 1):
                dp[i] += dp[i - brick]
        return dp[l]


    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 12: Archipelagos
    # Explanation and Runtime:
    """
    This problem is about finding the bridges in an undirected graph. A bridge is an edge that, if removed, would
    increase the number of connected components in the graph. In the context of this problem, the graph is represented
    by `n` islands and a list of edges connecting pairs of islands.
    To find these bridges, we use a depth-first search (DFS) technique with the concept of discovery and low times.
    Discovery time refers to the time when a node is first visited, while low time refers to the lowest discovery time
    reachable from the node.
    The algorithm works by:
    1. Using DFS to explore the graph, and for each node, tracking the discovery time and low time.
    2. For each edge, checking if it forms a bridge by comparing the low time of the adjacent node with the discovery time.
    3. If the low time of the adjacent node is greater than the discovery time of the current node, that edge is a bridge.
    The time complexity is O(v + e), where v is the number of nodes (islands) and e is the number of edges, 
    because we visit each node and each edge once during the DFS.
    """
    def findNeededBridges(n: int, edges: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
        graph = {}  
        for u, v in edges:
            if u not in graph:
                graph[u] = []
            if v not in graph:
                graph[v] = []
            graph[u].append(v)
            graph[v].append(u)

        time = [0]
        bridges = []
        visited = [False] * n
        low = [0] * n
        disc = [-1] * n

        def dfs(u, parent):
            visited[u] = True
            disc[u] = low[u] = time[0]
            time[0] += 1

            for v in graph[u]:
                if not visited[v]:
                    dfs(v, u)
                    low[u] = min(low[u], low[v])
                    if low[v] > disc[u]:
                        bridges.append([u, v])
                elif v != parent:
                    low[u] = min(low[u], disc[v])

        for i in range(n):
            if not visited[i]:
                dfs(i, -1)

        return bridges
    

    """
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    """
    # Problem 13: Search Engineer 
    # Explanation and Runtime:
    """
    This problem is about counting the number of distinct subsequences of a string `text` that match a given `pattern`.
    A subsequence is formed by deleting characters from `text` without changing the order of the remaining characters.
    We want to find how many times the `pattern` can appear as a subsequence in `text`.
    The solution uses dynamic programming (DP). We define a 2D array `dp` where `dp[i][j]` represents the number of ways
    to match the first `j` characters of the `pattern` using the first `i` characters of `text`.
    The base case is:
    `dp[0][0] = 1` because there's one way to match an empty pattern with an empty text.
    For any `i > 0`, `dp[i][0] = 1` because an empty pattern can always be matched with any prefix of the text.
    For each character of `text` and `pattern`, we check:
    If the characters match (`text[i - 1] == pattern[j - 1]`), then we can either:
    Use this character to match, which adds `dp[i - 1][j - 1]` ways.
    Or skip it, which adds `dp[i - 1][j]` ways.
    If the characters don't match, we skip the current character of `text`, and the count is `dp[i - 1][j]`.
    The final answer is stored in `dp[len(text)][len(pattern)]`, which gives the total number of ways to match the `pattern` in the `text`.
    The time complexity of this solution is O(n * m), where `n` is the length of `text` and `m` is the length of `pattern`,
    because we fill a 2D DP table of size `(n+1) x (m+1)`.
    """
    def numDistinct(text: str, pattern: str) -> int:
        dp = [[0] * (len(pattern) + 1) for _ in range(len(text) + 1)]
        dp[0][0] = 1

        for i in range(1, len(text) + 1):
            dp[i][0] = 1  # Empty pattern can always be matched

        for i in range(1, len(text) + 1):
            for j in range(1, len(pattern) + 1):
                if text[i - 1] == pattern[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j]

        return dp[len(text)][len(pattern)]

    # Problem 14: Buzz's Bees
    # Explanation and Runtime:
    #
    #
    def minNetworkCost(coords: list[tuple[int, int]]) -> int:
        n = len(coords)
        def squared_distance(a, b):
            return (a[0] - b[0])**2 + (a[1] - b[1])**2
        visited = [False] * n
        total_cost = 0
        edges_used = 0
        visited[0] = True
        while edges_used < n - 1:
            min_cost = float('inf')
            min_edge = (-1, -1)
            for u in range(n):
                if visited[u]:
                    for v in range(n):
                        if not visited[v]:
                            cost = squared_distance(coords[u], coords[v])
                            if cost < min_cost:
                                min_cost = cost
                                min_edge = (u, v)
            u, v = min_edge
            visited[v] = True
            total_cost += min_cost
            edges_used += 1
        return total_cost

    # print(moduler)
    # print(minSwap([3, 4, 5, 4], [1,2,3,8]))
    #print(maxPackages([(5, 4), (6, 4), (6, 7), (2, 3)]))
    #print(realEstatePrices([5, 1, 8, 3]))
