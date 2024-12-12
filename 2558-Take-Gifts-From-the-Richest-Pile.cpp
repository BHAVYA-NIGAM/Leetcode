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