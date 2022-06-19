// first approach using multiset

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        string current = "";
        multiset<string> store;
        vector<string> temp;
        vector<vector<string>> ans;
        
        for(auto c: searchWord)
        {
            current += c;
            store.clear();
            
            for(auto s: products)
            {
                if(s.substr(0, current.length()) == current)
                    store.insert(s);
            }
            temp.clear();
            
            for(int i=0; i<3 && !store.empty(); i++)
            {
                temp.push_back(*store.begin());
                store.erase(store.begin());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

// using sorting to optimize a little

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        string current = "";
        vector<string> temp;
        vector<vector<string>> ans;
        
        sort(products.begin(), products.end());
        
        for(auto c: searchWord)
        {
            current += c;
            temp.clear();
            
            for(auto s: products)
            {
                if(s.substr(0, current.length()) == current)
                    temp.push_back(s);
                if(temp.size() == 3) break;
            }
            
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};