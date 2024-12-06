// Time Complexity:
// 1. The outer loop runs from 1 to n, which gives it a time complexity of O(n).
// 2. Inside the loop, the `find` function is called, which has a time complexity of O(m), where m is the size of the `banned` vector. In the worst case, if the banned list is large, this could lead to a significant increase in the overall time complexity.
// 3. Therefore, the overall time complexity of the solution can be expressed as O(n * m) in the worst case, where n is the range of numbers being considered and m is the size of the banned list.

// Space Complexity:
// 1. The space complexity is O(1) for the variables used (counter and sum) since they do not depend on the input size.
// 2. The space used by the `banned` vector is not counted in the space complexity of the algorithm itself, as it is part of the input.
// 3. Thus, the overall space complexity is O(1).

// In summary, the time complexity is O(n * m) and the space complexity is O(1).


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int counter = 0, sum = 0;

        for(int i = 1; i <= n; i++) {
            auto it = find(banned.begin(), banned.end(), i);
            if(it != banned.end()) {
                continue;
            }
            sum = sum + i;
            if(sum <= maxSum) {
                counter++;
            } else {
                break;
            }
        }

        return counter;
    }
};


// The time complexity of the given solution is O(n), where n is the upper limit of the numbers we are considering (from 1 to n). This is because we iterate through all integers from 1 to n, checking each one against the banned set and updating the sum and count accordingly. The operations of checking membership in the unordered_set (ban.count(i)) and inserting elements into it are average O(1) due to the underlying hash table implementation.

// The space complexity is O(m), where m is the number of elements in the banned list. This is because we store the banned elements in an unordered_set, which requires space proportional to the number of banned elements. In the worst case, if all numbers from 1 to n are banned, the space complexity would be O(n), but typically it is O(m) where m is much smaller than n. 

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        
        int sum = 0, count = 0;

        for(int i = 1; i <= n; i++) {
            if(ban.count(i) == 0) {
                sum = sum + i;
                
                if(sum > maxSum) {
                    break;
                }

                count++;
            }            
        }

        return count;
    }
};