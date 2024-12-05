class Solution {
public:
    static bool comp(int a,int b){
        return a>b;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mep;
        for(auto i:nums){
            
            mep[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto i:mep){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;

        
    }
};
