class Solution {
public:
    string reorganizeString(string s)
    {
        string res(s.size(),'');
        
        unordered_map<char,int> letter;
        //int letter[26]={0};
        int max_freq=0;
        int number_of_max_freq=0;
        
        for(auto& i:tasks)
        {
            ++letter[i];
            max_freq=max(max_freq,letter[i]);
        }
        //printf("%d %d \n",max_freq,number_of_max_freq);
        
        auto it=letter.begin();
        while(it!=letter.end())
        {
            
        }
        
        int start=0;
        for(int i=0; i<26; ++i)
        {
            
            if(letter[i]==max_freq)
            {
                while(start<res.size())
                {
                    
                }
            }
        }
        
        int empty_letter=(max_freq-1);
        
    }
};
