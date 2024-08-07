class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        priority_queue<int,vector<int>, greater<int>> pq;
        
        for(auto i:arr1){
            pq.push(i);
        }
        
        
        for(auto i:arr2){
            pq.push(i);
        }
        
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};
