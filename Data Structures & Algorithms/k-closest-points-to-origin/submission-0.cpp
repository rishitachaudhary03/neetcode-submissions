class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp=[](const vector<int>& a, const vector<int>&b){
            return a[0]*a[0] + a[1]*a[1]> b[0]*b[0] +b[1]*b[1];
            };
            priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>minheap(comp);
            vector<vector<int>> result;
            for(auto const& point:points){
                minheap.push({point[0],point[1]});
            } 
            for(int i =0; i<k; i++){
                result.push_back(minheap.top());
                minheap.pop();
            }
            return result;
        }
};
