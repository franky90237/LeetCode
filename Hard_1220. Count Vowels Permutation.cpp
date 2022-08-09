//2022-08-09
class Solution {
public:
    int countVowelPermutation(int n)
    {
        /*
        a : {e}
        e : {a,i}
        i : {a,e,o,u}
        o : {i,u}
        u : {a}                
        */
        
        unordered_map<char,vector<char>> table;
        table.insert({'a', {'e'} } );
        table.insert({'e', {'a','i'} } );
        table.insert({'i', {'a','e','o','u'} } );
        table.insert({'o', {'i','u'} } );
        table.insert({'u', {'a'} } );
        
        unordered_map<char,long long> next;
        unordered_map<char,long long> vowels;
        vowels.insert({'a',1});
        vowels.insert({'e',1});
        vowels.insert({'i',1});
        vowels.insert({'o',1});
        vowels.insert({'u',1});
        
        for(int i=2; i<=n; ++i)
        {
            //cout<<i<<endl;
            for(auto& vowel:vowels)
            {
                char c=vowel.first;
                long long cnt=vowel.second;
                
                for(auto& followed:table[c])
                {
                    next[followed]=(next[followed]+cnt)%1000000007;
                }
            }
            
            swap(next,vowels);
            for(auto& x:next) x.second=0;
            //next.clear();
        }
        
        long long sum=0;
        for(auto vowel:vowels) sum=(sum+vowel.second)%1000000007;
        
        return sum;
    }
};
