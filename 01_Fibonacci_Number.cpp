//using recursion
class Solution {
public:
    int recurSolve(int n)
    {
        //base case 
        if(n == 0 || n == 1)
        {
            return n;
        }
        int ans = recurSolve(n - 1)+recurSolve(n - 2);

        return ans;
    }
    int fib(int n) 
    {
        int result = recurSolve(n);
        return result;        
    }
};
/*
Time Complexity: O(2^n)
Space Complexity: O(n)

*/

//using DP
class Solution {
public:
    
    int topDown(int n ,  vector<int>&dp)
    {
         //step 1:base case 
        if(n == 0 || n == 1)
        {
            return n;
        }
        //step 3:
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        //step 2 : replace ans with dp[n]
        dp[n]= topDown(n -1 , dp)+topDown( n -2 , dp);

        return dp[n];

        
    }
    int fib(int n) 
    {
        //step 1: create dp array
        vector<int>dp(n+1,-1);
        int ans =topDown(n,dp);
        return ans;      
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)

*/

//using dp : Bottom Up (tabulation , No recursion only iterative)
class Solution {
public:
    int BottomUp(int n)
    {
        if( n == 0 || n == 1)return n;
        //step 1: create dp array
        vector<int>dp(n+1, -1);
        //step 2: observe base case in above solution

       dp[0]=0;
       dp[1]=1;

       //step 3:
       for(int i=2;i<=n;i++)
       {
        dp[i]=dp[i-1]+dp[i-2];
       }
        return dp[n];
    }
    int fib(int n) 
    {
        int result = BottomUp(n);
        return result;        
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)

*/

//using dp : space optimization

class Solution {
public:
    int spaceOpt(int n)
    {
        //base case
        if( n == 0 || n == 1)return n;
        
        //step 1: base case

       int prev2=0;
       int prev1=1;

       //step 3:
       int curr;
       for(int i=2;i<=n;i++)
       {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
       }
        return curr;
    }
    int fib(int n) 
    {
        int result = spaceOpt(n);
        return result;        
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)

*/
