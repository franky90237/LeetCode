class Solution {
public:
    //The solution I tried for the first time.
    //too messy, too many boundary conditions
    string reverseWords(string s) 
    {
      int start=0;
      int end=s.size()-1;

      while(s[start]==' ') ++start;

      int push_index;
      bool greater_than_end=false;
      if(start!=0) 
      {
          push_index=0;                        
      }
      else
      {            
          for(;start<=end;++start)
          {
              push_index=start;
              while(s[start]==' ' && start<=end)
              {                    
                  ++start;
              }

              if(start>end)
              {
                  greater_than_end=true;
                  break;
              }
              if(start-push_index>1) break;
          }                    
      }

      //if(push_index==start) cout<<push_index<<" "<<start<<" "<<end<<endl;

      for(int i=start;i<=end;++i)
      {
          if(s[i]==' ') continue;

          if(push_index!=0) ++push_index;
          while(s[i]!=' ' && i<=end)
          {
              s[push_index]=s[i];
              s[i]=' ';                    

              ++i;
              ++push_index;
          }
          //cout<<push_index<<" "<<i<<endl;
          if(i>end)
          {
              greater_than_end=true;
              break;
          }
      }

      if(s[end]==' ')
      {
          s.resize(push_index);
          end=s.size()-1;
      }        

      //return s;

      reverse_string_with_boundery(s,0,end);

      start=0;
      for(end=0;end<s.size();++end)
      {
          if(s[end]==' ')
          {                
              reverse_string_with_boundery(s,start,end-1);
              start=end+1;               
          }
      }
      reverse_string_with_boundery(s,start,end-1);

      return s;
    }

    void reverse_string_with_boundery(string& s, int start, int end)
    {
      while(start<end)
      {           
          int temp=s[start];
          s[start]=s[end];
          s[end]=temp;

          ++start;
          --end;
      }        
    }
    
    //This is the solution obtained by referring to the discussion.
    //clean, pretty solution
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());
        
        int insert_index=0;
        for(int current_index=0;current_index<s.size();++current_index)
        {
            if(s[current_index]!=' ')
            {
                if(insert_index!=0) ++insert_index;
                
                int word_index=current_index;
                while(word_index<s.size() && s[word_index]!=' ')
                {
                    s[insert_index]=s[word_index];
                    //if(insert_index!=word_index) s[word_index]=' ';
                    ++insert_index;
                    ++word_index;
                }
                s[insert_index]=' ';
                reverse(s.begin()+insert_index-(word_index-current_index),s.begin()+insert_index);
                current_index=word_index;                
            }
        }
        
        s.resize(insert_index);
        
        return s;
    }  
};
