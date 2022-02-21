//array
class KthLargest 
{
private:
    vector<int> arr;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) 
    {
        arr=nums;
        //sort(arr.begin(),arr.end(),greater<int>());
        sort(arr.begin(),arr.end());
        this->k=k;
    }
    
    int add(int val) 
    {
        int l=0,h=arr.size()-1,m;
        while(l<=h)
        {
            m=(l+h)/2;
            
            //if(arr[m]==val) break;
            if(arr[m]<=val) l=m+1;
            else h=m-1;
        }
        
        arr.push_back(0);
        for(int i=arr.size()-1; i>l; --i)
        {
            arr[i]=arr[i-1];
        }
        arr[l]=val;
        
        return arr[arr.size()-k];
    }
};

