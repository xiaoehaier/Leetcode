/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

#include <vector>
#include <iostream>
#include <cmath>
using std::max;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int candy(vector<int> &ratings) 
    {
        vector<int> candyPerChild(ratings.size(),1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) candyPerChild[i] = candyPerChild[i-1]+1;
        }
        int sum = candyPerChild[ratings.size()-1];
        for (int i = ratings.size() - 2; i >= 0 ; i--)
        {
            if (ratings[i] > ratings[i+1]) 
                candyPerChild[i] = max(candyPerChild[i], candyPerChild[i+1]+1);
            sum += candyPerChild[i];
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> ratings;
	ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(4);
	ratings.push_back(4);
	ratings.push_back(3);
	Solution a;

	cout << a.candy(ratings) << endl;
	return 0;
}