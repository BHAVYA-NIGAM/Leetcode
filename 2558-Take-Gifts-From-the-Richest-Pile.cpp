// 1. **Building the priority queue**: Initializing the priority queue with the gifts vector takes O(n) time, where n is the number of gifts.

// 2. **Processing k iterations**: In each of the k iterations, the algorithm performs the following operations:
//    - `pq.top()` takes O(1) time to access the top element.
//    - `pq.pop()` takes O(log n) time to remove the top element.
//    - Calculating the square root `sqrt(gift)` takes O(1) time.
//    - `pq.push(newGift)` takes O(log n) time to insert the new element.
//    Therefore, each iteration takes O(log n) time, and for k iterations, this results in O(k log n) time.

// 3. **Calculating the sum**: Finally, summing up all the elements in the priority queue takes O(n log n) time, as each element is removed from the priority queue.

// Combining these, the overall time complexity is O(n + k log n + n log n), which simplifies to O(n log n + k log n).

// The space complexity of the solution is primarily determined by the priority queue, which stores all the gifts. Thus, the space complexity is O(n) for storing the gifts in the priority queue. 
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while(k--) {
            int gift = pq.top();
            int newGift = sqrt(gift);
            pq.pop();
            pq.push(newGift);
        }

        long long sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
