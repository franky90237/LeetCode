//2022-06-14
//TLE
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        string tmp;
        lcs(tmp,0,0,word1,word2);
        
        //cout<<tmp<<endl;
                
        return word1.size()-tmp.size() + word2.size()-tmp.size();
    }
    
    void lcs(string& tmp, int i1, int i2, string& word1, string& word2)
    {        
        if(i1==word1.size() || i2==word2.size()) return;
        
        int c1=word1[i1];
        int c2=word2[i2];
        if(c1==c2) 
        {
            tmp.push_back(word1[i1]);
            lcs(tmp,i1+1,i2+1,word1,word2);
            //tmp.pop_back();
        }
        else
        {
            string tmp1=tmp;
            lcs(tmp1,i1+1,i2,word1,word2);
            //string tmp1=tmp;
            
            string tmp2=tmp;
            lcs(tmp2,i1,i2+1,word1,word2);
            //string tmp2=tmp;
            
            if(tmp1.size()>=tmp2.size()) tmp=tmp1;
            else tmp=tmp2;
        }
    }
};
