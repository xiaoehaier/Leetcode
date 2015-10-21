/*
Given n points on a 2D plane, 
find the maximum number of points that lie on the same straight line.
*/



 /** Definition for a point.*/
 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };
 
#include <vector>
#include <map>
#include <iostream>
#include <utility>
#include <cmath>
using std::endl;
using std::abs;
using std::cout;
using std::pair;
using std::vector;
using std::map;

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int max = 0;
        int infinite = 0;
        int same = 0;

        vector<pair<double, int> > slopeCnt;

        for (int i = 0; i < points.size(); ++i) {
        	same = infinite = 0;
        	slopeCnt.clear();
        	for (int j = 0; j < points.size() ; ++j) {
        		if (points[j].x == points[i].x ) {
        			if (points[j].y == points[i].y)
        				++same;
        			else 
        				++infinite;
        			continue;
        		}
        		float slope = (float)(points[j].y-points[i].y)/(float)(points[j].x-points[i].x);

        		int tmp;
        		for (tmp = 0; tmp < slopeCnt.size(); ++tmp) {
        			if (abs(slopeCnt[tmp].first - slope) < 1.0E-10)
						++slopeCnt[tmp].second;
        		}
        		if (tmp == slopeCnt.size())
        			slopeCnt.push_back(pair<double, int>(slope,1));
        	}

        	if (infinite + same > max) max = infinite + same;

        	for (int tmp = 0; tmp < slopeCnt.size(); ++tmp) 
        		if (slopeCnt[tmp].second + same > max) 
        			max = slopeCnt[tmp].second + same;   		
        }

        return max;
    }
};



int main(int argc, char const *argv[])
{
	vector<Point> points;
	points.push_back(Point(0,0));
	points.push_back(Point(1,2));
	points.push_back(Point(2,2));
	points.push_back(Point(4,3));
	points.push_back(Point(5,5));
	points.push_back(Point(4,3));

	Solution a;
	cout << a.maxPoints(points) << endl;
	return 0;
}