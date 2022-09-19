//2022-09-19
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        unordered_map<string, vector<string>> groups;
        for(auto& path : paths)
        {
            int pos=path.find(' ');
            string directory=path.substr(0,pos);
            
            int i=pos+1;
            while(i<path.size())
            {
                if(path[i]==' ')
                {
                    ++i;
                    continue;                    
                }
                                
                pos=path.find('(',i);
                string file=path.substr(i,pos-i);
                
                i=pos+1;
                pos=path.find(')',i);
                string content=path.substr(i,pos-i);
                
                groups[content].push_back(directory+"/"+file);
                
                i=pos+1;
            }
        }
        
        vector<vector<string>> ans;
        for(auto& group : groups)
        {
            if(group.second.size()>=2)
            {
                ans.push_back(group.second);
            }
        }
        
        return ans;
    }
};
