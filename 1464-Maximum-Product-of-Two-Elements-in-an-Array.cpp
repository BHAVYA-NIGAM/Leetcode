// The time complexity of the given solution is O(n^2), where n is the number of elements in the input vector `nums`. This is because there are two nested loops: the outer loop iterates through each element, and for each element, the inner loop iterates through the remaining elements. As a result, the total number of iterations is proportional to the square of the number of elements.

// The space complexity of the solution is O(1). This is because the algorithm uses a constant amount of extra space regardless of the input size. The only additional variables used are `res`, `n`, and `temp`, which do not depend on the size of the input vector. Thus, the space complexity remains constant.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int temp = (nums[i] - 1) * (nums[j] - 1);
                res = res < temp ? temp : res;
            }
        }
        
        return res;
    }
};