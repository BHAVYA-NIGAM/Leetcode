// Time Complexity:
// - The outer loop iterates through each character of the string `s`, which takes O(n) time, where n is the length of the string.
// - The inner while loop may also iterate through characters, but each character is processed at most twice (once when it is added to the set and once when it is removed). Therefore, the total number of operations across all iterations of the while loop is O(n).
// - Consequently, the overall time complexity of the algorithm is O(n).

// Space Complexity:
// - The space complexity is determined by the set `st`, which stores unique characters from the substring. In the worst case, if all characters in the string are unique, the set can contain up to O(min(n, m)) characters, where m is the size of the character set (e.g., 256 for extended ASCII or 26 for lowercase English letters).
// - Thus, the space complexity is O(min(n, m)).

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0; 
        int removeDub = 0; 
        set<char> st; 
        for (int i = 0; i < s.size(); ++i) {
            while (st.find(s[i]) != st.end()) {
                st.erase(s[removeDub]); 
                removeDub++;  
            }
            st.insert(s[i]);
            max = max > (i - removeDub + 1) ? max : (i - removeDub + 1) ;
        }
        
        return max;
    }

};