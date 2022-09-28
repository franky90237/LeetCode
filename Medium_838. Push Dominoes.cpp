//2022-09-27
//time  : O(n)
//space : O(1)
class Solution {
public:
    string pushDominoes(string dominoes)
    {
        /*

        RR.L

        RR.L

        .L.R...LR..L..
         * ^   *

        LL.RR.LL

        LL.RRR.LRR.L..

        */
        
        int n=dominoes.size();
        int i=0;
        int posL=-1;
        while(i < n && dominoes[i] != 'R') 
        {
            if(dominoes[i] == 'L') posL=i;
            ++i;
        }
        
        if(posL != -1)
        {
            for(int k=0; k<posL; ++k) dominoes[k]='L';
        }
        
        int prePos=i;        
        ++i;
        while(i < n)
        {
            while(i < n && dominoes[i] == '.') ++i;
            
            if(i >= n)
            {
                if(dominoes[prePos] == 'R') 
                {
                    for(int k=prePos+1; k<n; ++k) dominoes[k]='R';
                }
                break;
            }
            
            if(dominoes[prePos] == 'L' && dominoes[i] == 'L')
            {
                for(int k=prePos+1; k<i; ++k) dominoes[k]='L';
            }
            else if(dominoes[prePos] == 'R' && dominoes[i] == 'R')
            {
                for(int k=prePos+1; k<i; ++k) dominoes[k]='R';
            }
            else if(dominoes[prePos] == 'R' && dominoes[i] == 'L')
            {
                int l=prePos+1;
                int r=i-1;
                while(l<r)
                {
                    dominoes[l]='R';
                    dominoes[r]='L';
                    ++l;
                    --r;
                }                
            }                        
            
            prePos=i;
            ++i;
        }
                
        return dominoes;
    }
};

//2022-09-28
//time  : O(n)
//space : O(n)
class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        /*
        ".L.R...LR..L.."

        1(L) 3(R) 7(L) 8(R) 11(L)

        */
        int n=dominoes.size();
        
        vector<int> table;        
        for(int i=0; i<n; ++i)
        {
            if(dominoes[i]=='L' || dominoes[i]=='R') table.push_back(i);        
        }
        
        int prePos=-1;
        char preChar='L';
        int i=0;
        while(i < table.size())
        {
            int idx=table[i];
            
            if(preChar=='L' && dominoes[idx]=='L')
            {
                for(int k=prePos+1; k<idx; ++k) dominoes[k]='L';                
            }
            else if(preChar=='R' && dominoes[idx]=='R')
            {
                for(int k=prePos+1; k<idx; ++k) dominoes[k]='R';
            }
            else if(preChar=='R' && dominoes[idx]=='L')
            {
                int l=prePos+1;
                int r=idx-1;
                while(l<r)
                {
                    dominoes[l]='R';
                    dominoes[r]='L';
                    ++l;
                    --r;
                }
            }       
            
            prePos=idx;
            preChar=dominoes[idx];
            ++i;
        }      
        
        if(preChar == 'R')
        {
            for(int k=prePos+1; k<n; ++k) dominoes[k]='R';
        }
        
        return dominoes;
    }
};
