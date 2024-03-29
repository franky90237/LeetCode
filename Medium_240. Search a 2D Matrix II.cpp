//divide and conquer (3 sub_matrix)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int left=0, right=matrix[0].size()-1;
        int top=0, down=matrix.size()-1;
        
        return searchMatrix(matrix,target,left,right,top,down);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target, int left, int right, int top, int down)
    {
        //cout<<left<<" : "<<right<<" : "<<top<<" : "<<down<<endl;
        if(left>right || top>down) return false;
        if(left==right && top==down && matrix[top][left]!=target) return false;
        
        int midr=top+(down-top)/2;
        int midc=left+(right-left)/2;
        
        //cout<<" * "<<midr<<" : "<<midc<<"***"<<matrix[midr][midc]<<endl;
        
        if(target==matrix[midr][midc]) return true;
        else if(target<matrix[midr][midc])
        {
            return 
                searchMatrix(matrix,target,midc,right,top,midr-1) || 
                searchMatrix(matrix,target,left,midc-1,top,midr-1) ||
                searchMatrix(matrix,target,left,midc-1,midr,down);
        }
        else
        {
            return
                searchMatrix(matrix,target,left,midc,midr+1,down) || 
                searchMatrix(matrix,target,midc+1,right,midr+1,down) ||
                searchMatrix(matrix,target,midc+1,right,top,midr);
        }
    }
};


//divide and conquer (2 sub_matrix : one big and one small)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int left=0, right=matrix[0].size()-1;
        int top=0, down=matrix.size()-1;
        
        return searchMatrix(matrix,target,left,right,top,down);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target, int left, int right, int top, int down)
    {
        //cout<<left<<" : "<<right<<" : "<<top<<" : "<<down<<endl;
        if(left>right || top>down) return false;
        if(left==right && top==down && matrix[top][left]!=target) return false;
        
        int midr=top+(down-top)/2;
        int midc=left+(right-left)/2;
        
        //cout<<" * "<<midr<<" : "<<midc<<"***"<<matrix[midr][midc]<<endl;
        
        if(target==matrix[midr][midc]) return true;
        else if(target<matrix[midr][midc])
        {
            return
                searchMatrix(matrix,target,left,right,top,midr-1) ||
                searchMatrix(matrix,target,left,midc-1,midr,down);
        }
        else
        {
            return
                searchMatrix(matrix,target,left,right,midr+1,down) ||
                searchMatrix(matrix,target,midc+1,right,top,midr);
        }
    }
};

//time  : O(n+m)
//space : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int r=0,c=m-1;
        while(r<n && c>=0)
        {
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) --c;
            else ++r;
        }
        
        return false;
    }
};

//2022-08-03
//time  : O(m+n)
//space : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int row=m-1;
        int col=0;
        
        while(row>=0 && col<n)
        {
            int val=matrix[row][col];
            
            if(val == target) return true;
            else if(val > target) --row;
            else ++col;
        }
        
        return false;
    }
};
