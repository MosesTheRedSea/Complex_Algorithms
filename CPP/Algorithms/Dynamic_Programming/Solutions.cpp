#include <algorithm>
#include <array>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

/*
    █▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█  
    █░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
    █──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀
*/

class Solutions {
public:

    /*
    ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█──░█ ░█▀▀▀ ░█▀▀▄ 
    ─▀▀▀▄▄ ░█──░█ ░█─── ─░█░█─ ░█▀▀▀ ░█─░█ 
    ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ──▀▄▀─ ░█▄▄▄ ░█▄▄▀
    */

    // Problem 1: Real Estate Profits
    /* Explanation and Runtime:
    This problem had me thinking about Matrix Multiplication or Greedy / Dynamic Programming. It's similiar 
    to one problem we had on our homework 
    However I chose to go from Dynamic Programming
    We're trying to 
    */
	static int realEstatePrices(const std::vector<int>& values) {
        /*
            Example Run Through
            Input : [5, 1, 8, 3]
            Output : 180

            0 0 0 0 0 0
            0 0 0 0 0 0
            0 0 0 0 0 0
            0 0 0 0 0 0
            0 0 0 0 0 0
            0 0 0 0 0 0

            [5, 1, 8, 3]
        
            5 * 1 * 1

            [8,3]

            # Define Recurrence Relation

            Special Cases where the index is 0 or values.size() - 1
            Since we need 3 values to calculate the profit at index i
        */
        // Size of Input Array (1D)
        int n = values.size();
        if (n == 0) {
            return 0;
        }

        // Creating our Dynamic Programming Table 
        // Base Cases Adding 1 to the front and end of the 1D Vector
        values.insert(values.begin(), 1);
        values.push_back(1);




       
    }


    // Problem 2: Warehouse Package Stacking
    /* Explanation and Runtime:

        This problem is a Dynamic Programming, similiar to Longest Increasing Subsequence.
    


     * 
     */
    static int maxPackages(const vector<vector<int>>& maxPackages) {
        for (int i = 0; i < max.size(); ++i) {}
        return -1;
    }

    // Problem 3: Building Blocks
    /* Explanation and Runtime:

        This is a Dynamic Programming Programming
     * 
     */
    static int minSwap(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        return -1;
    }

    // Problem 4: Modular Two Sum 
    /* Explanation and Runtime:

        This is a  Modular Arithmetic problem
     * 
     */
    static int modTwoSum(const std::vector<int>& A, int k) {
        // O(n^2) formula
        // int count = -1;
        // for (int i = 0; i < A.size(); ++i) {
        //     (for j = 0; j < A.size(); ++j) {
        //         if (j != i) {
        //             count += (A[i] + A[j] % k == 0) ? 1 : 0;
        //         }
        //     }
        // }
        // return count;
        return -1
    }
  
    // Problem 5: Maximum Magic Path Power 
    /* Explanation and Runtime:

        This is a Graph Theory / Dynamic Programming

     * 
     */
    static int maximumMagicPathPower(const std::vector<int>& energies, const std::vector<std::vector<int>>& edges, int maxTime) {
        return -1;
    }
  
    // Problem 6: Divide the Harvest
    /* Explanation and Runtime:
 
        This is a  Dynamic Programming, similiar to Knapsack 

     * 
     */
    static int divideTheHarvest(const std::vector<int>& quantity, int k) {
        return -1;
    }
  
    // Problem 7: Coloring Sidewalks 
    /* Explanation and Runtime:

       This is a graph problem Dynamic Programming
     * 
     */
    static int coloringSidewalks(vector<vector<int>>& time) {
        return -1;
    }

    // Problem 8: Chemical Concoctions
    /* Explanation and Runtime:
     * 
     */
    static string chemicalConcoctions(const std::vector<string>& formulas) {
        return "";
    }

    // Problem 9: Maximum Sum of Non-Adjacent Subsequences
    /* Explanation and Runtime:
     * I could create a 1D array(vector) called dp, given our input vector A, we define
       dp[i] as the maximum sum for 
     */
    static int maxNonAdjSum(const std::vector<int>& A) {
        int n = A.size();
        vector<int>(n);
        

        return -1;
    }

    // Problem 10: DigitGPT
    /* Explanation and Runtime:
     * 
     */
    static bool reviveStrings(int n, string ticket) {
        return false;
    }

    // Problem 11: Building a Brick Wall
    /* Explanation and Runtime:
     * 
     */
    static int buildBrickWall(const std::vector<int>& B, int l) {
        return -1;
    }

    
    // Problem 12: Archipelagos
    /* Explanation and Runtime:
     * 
     */
    static vector<pair<int, int>> findNeededBridges(int n, vector<pair<int, int>> edges) {
        return {};
    }

	// Problem 13: Search Engineer
    /* Explanation and Runtime:
     * 
     */
	static int numDistinct(const std::string &text, const std::string pattern) {
		return -1;
	}
    
    // Problem 14: Buzz's Bees
    /* Explanation and Runtime:
     * 
     */
    static long long minNetworkCost(const vector<pair<int, int>>& coords) {
        return -1;
    }

    int main() {

        vector<int> nums{5, 1, 8, 3};
        cout << realEstatePrices(nums) << endl;
        return 0;
    }
};