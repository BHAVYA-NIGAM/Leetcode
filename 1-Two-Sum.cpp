// Time Complexity:
// The algorithm iterates through the `nums` vector exactly once, performing constant time operations for each element. The key operations include checking if a value exists in the unordered_map and inserting a new key-value pair, both of which are average O(1) operations. Therefore, the overall time complexity is O(n), where n is the number of elements in the `nums` vector.

// Space Complexity:
// The space complexity is determined by the additional storage used by the unordered_map and the result vector. In the worst case, the unordered_map could store all n elements if no two numbers sum to the target. Thus, the space complexity for the unordered_map is O(n). The result vector, which stores the indices of the two numbers, will use O(2) space in the best case, but we can consider it as O(1) since it does not grow with the input size. Therefore, the overall space complexity is O(n).class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res;
        unordered_map <int, int> mp;
        for(auto i = 0; i < nums.size(); i++) {
            int sub = target - nums[i];
            if(mp.find(sub) != mp.end()) {
                res.emplace(res.begin(), i);
                res.emplace(res.begin() + 1, mp[sub]);
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};


// Time Complexity:
// The outer loop runs `n` times, where `n` is the size of the `nums` array. For each iteration of the outer loop, the inner loop runs up to `n - 1` times in the worst case. Therefore, the total number of iterations is approximately n * (n - 1) / 2, which simplifies to O(n^2). Thus, the time complexity of this solution is O(n^2).

// Space Complexity:
// The space complexity is primarily determined by the space used to store the result. In the worst case, if the solution finds a valid pair, it will store two indices in the `res` vector. This results in a constant space usage of O(1) for the indices, plus the space used by the `res` vector, which can be considered O(1) since it holds a fixed number of elements (at most 2). Therefore, the overall space complexity is O(1) if we disregard the input size.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    res.emplace(res.begin(), i);
                    res.emplace(res.begin() + 1, j);
                }
            }
        }
        return res;
    }
};


// Time Complexity:
// The function uses a nested loop to iterate through the array `nums`. The outer loop runs `numsSize` times, and for each iteration of the outer loop, the inner loop runs up to `numsSize - 1` times. This results in a time complexity of O(n^2), where n is the size of the input array `nums`. In the worst case, the function will check every possible pair of elements in the array.

// Space Complexity:
// The space complexity of the function is O(1) if we do not consider the space used for the output. The function allocates a fixed amount of space for the result array, which holds two integers (the indices of the two numbers that add up to the target). Therefore, the space complexity is O(1) for the additional space used, but O(2) for the result array, which can be simplified to O(1) in big O notation. However, if we consider the space allocated for the result, it would be O(2) or O(1) in terms of big O notation.


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    for(int i=0;i<numsSize;i++) {
        for(int j=i+1;j<numsSize;j++) {
            if((nums[i]+nums[j])==target) {
                result[0]=i;
                result[1]=j;
                return result;
            }
        }
    }
    *returnSize=0;
    free(result);
    return NULL;
}