class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        std::vector<int> op(deck.size());
        std::queue<int> q;

        for (int i = 0; i < deck.size(); ++i) q.push(i); 
        for(int card : deck){
           op[q.front()] = card;
           q.pop();
           if(!q.empty()){q.push(q.front()); q.pop();}
        }
        return op;
    } 
};