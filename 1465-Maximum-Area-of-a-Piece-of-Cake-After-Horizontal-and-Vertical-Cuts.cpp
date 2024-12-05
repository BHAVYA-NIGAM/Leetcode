// The time complexity of the given solution can be analyzed as follows:

// 1. **Sorting**: The solution sorts the `horizontalCuts` and `verticalCuts` arrays. Sorting an array of size `n` takes O(n log n) time. In this case, the sizes of the arrays are `h1` (which is `horizontalCuts.size() + 2`) and `v` (which is `verticalCuts.size() + 2`). Therefore, the sorting operations contribute O(h1 log h1) and O(v log v) to the time complexity.

// 2. **Finding Maximum Height and Width**: After sorting, the solution iterates through the `horizontalCuts` and `verticalCuts` arrays to find the maximum height and width. Each of these iterations takes O(h1) and O(v) time, respectively.

// Combining these, the overall time complexity is O(h1 log h1 + v log v + h1 + v), which simplifies to O(h1 log h1 + v log v) since the linear terms are dominated by the logarithmic terms.

// The space complexity of the solution is primarily determined by the additional space used for the `horizontalCuts` and `verticalCuts` arrays. The solution modifies these arrays in place by adding two elements each, which does not significantly increase space usage. Thus, the space complexity is O(1) if we consider only the additional space used, or O(h1 + v) if we consider the space used by the input arrays themselves. However, since the input arrays are provided as part of the function parameters, we typically focus on the additional space used, which is O(1). 

// In summary:
// - Time Complexity: O(h1 log h1 + v log v)
// - Space Complexity: O(1) (excluding input space)class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        const int m = 1e9 + 7;

        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int h1 = horizontalCuts.size(), v =  verticalCuts.size();

        int height = INT_MIN, width = INT_MIN;

        for(int i = 0; i < h1 - 1; i++) {
            int temp = horizontalCuts[i + 1] - horizontalCuts[i];
            height = max(height, temp);
        }

        for(int i = 0; i < v - 1; i++) {
            int temp = verticalCuts[i + 1] - verticalCuts[i];
            width = max(width, temp);
        }

        return ((1LL * height * width) % m);
    }
};