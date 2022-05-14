class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,list<pair<int,int>>>graph ;
        
        for(vector<int>&x:times){
            graph[x[0]].push_back({x[1],x[2]});
        }
        
        unordered_map<int,int>dist ; 
        for(int i=1;i<=N;i++){
            dist[i] = INT_MAX ;
        }
        
        dist[K] = 0 ;
        
        set<pair<int,int>>closest ;/// {dist,node}
        
        closest.insert({0,K}) ;
        
        
        while(closest.size()){
            //find node in front. 
            int curr_node =   (*(closest.begin())).second ;
            int curr_dist = (*(closest.begin())).first ;
            
            closest.erase(closest.begin());
            
            //travel all the children .
            for(auto childPair: graph[curr_node]){
                if(curr_dist +childPair.second < dist[childPair.first]){
                    int child_node = childPair.first ;
                    
                    if(closest.find({dist[child_node],child_node})!=closest.end()){
                        closest.erase({dist[child_node],child_node});
                    }
                    
                    dist[child_node] = curr_dist+childPair.second ;
                    closest.insert({dist[child_node],child_node});
                    
                }
            }
        }
        
        int res= -1; 
        for(auto x:dist){
            res = max(res,x.second);
        }
        return res==INT_MAX?-1:res; 
        
    }
};