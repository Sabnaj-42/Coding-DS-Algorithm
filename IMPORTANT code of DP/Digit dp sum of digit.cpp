#include <bits/stdc++.h>
using namespace std;

// dp table to store answers(memoization)
int memo[18][19][2];
//total digit of the number is less than 18
//sum less than 19
//tight position or not

// function to calculate how many number from  l to r with digit sum x
int dp(vector<int>& digit,int pos, int x, int tight)
{
    // base case
    if(x<0)return 0;
    if(pos==digit.size())
    {
        // x is current sum
        if(x==0)return 1;
        else return 0;
    }
    // if this state has already been calculated return it
    if(memo[pos][x][tight]!=-1)
    {
        return memo[pos][x][tight];
    }

    // this variable denotes the upper bound
    // on the digits that can be chosen for this position
    int limit = 9;
    // if tight is 1, that means we will have a restriction
    // on the digits that can be chosen, it cannot be greater than
    // digits[pos] else we have no limits
    if(tight==1)
    {
        limit = digit[pos];
    }

    // answer variable
    int answer = 0;

    // for loop over all the digits that can be considered for this position
    for(int i=0; i<=limit; i++)
    {
        // in the next iteration we need to decide the value of new tight
        int new_tight = tight;

        // if tight is 1 and the current digit we are choosing
        // is equal to digits[pos], then we need to set tight to 1
        if(tight==1 && i==digit[pos])
        {
            new_tight = 1;
        }
        // else we have no restrictions in the next iteration
        else
        {
            new_tight = 0;
        }

        // recurse for next iteration and add to answer
        answer += dp(digit,pos+1,x-i,new_tight);

    }

    // store this answer in the dp table and return it
    return memo[pos][x][tight] = answer;

}
int main()
{

    // declare variables
    long long al,ar;
    cin>>al>>ar;
    al--;
    string l,r;
    l=to_string(al);
    r=to_string(ar);

    int x;
    cin>>x;
    vector<int>l_digit,r_digit;
    for(int i=0;i<l.size();i++)
    {
        int d=l[i]-'0';
        l_digit.push_back(d);
    }
     for(int i=0;i<r.size(); i++)
    {
        int d=r[i]-'0';
        r_digit.push_back(d);
    }

    // initialize memo with -1
    memset(memo,-1,sizeof(memo));

    // compute answer for a
    int answer_l = dp(l_digit,0,x,1);

    // initialize memo with -1
    memset(memo,-1,sizeof(memo));

    // compute answer for b
    int answer_r = dp(r_digit,0,x,1);
    cout<<answer_r<<" "<<answer_l<<endl;

    // final answer
    int answer = answer_r - answer_l;

    cout<<answer<<endl;
}
