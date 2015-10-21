#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
/**********************quesiton 1 ***************
class Solution {
public:
    int findMin(vector<int> &num) {
        if (num[0] <= num.back())
        	return num[0];

        int head = 0;
        int tail = num.size()-1;
        
        while (1) {
        	if (num[(head + tail)/2] < num[tail]) 
        		tail = (head + tail)/2;
 			else 
 				head = (head + tail)/2 + 1;
 
 			if (head == tail) return num[head];       	
        }
    }
};
*/
class Solution {
public:
    int findMin(vector<int> &num) {

        int head = 0;
        int tail = num.size()-1;

        while (num[head] == num[tail]) 
        	if (head++ == tail) return num[tail];
        		
        
        while (1) {

        	if (num[(head + tail)/2] <= num[tail]) 
        		tail = (head + tail)/2;
 			else 
 				head = (head + tail)/2 + 1;  

 			if (head == tail) return num[head];    	
        }
    }
};

int main(int argc, char const *argv[])
{
	vector<int> hello;

	

	
		hello.push_back(3);
		hello.push_back(3);


	/*	hello.push_back(3);
		hello.push_back(1);
		hello.push_back(3);
		hello.push_back(3);
		hello.push_back(3);
		hello.push_back(3);
		hello.push_back(3);
		hello.push_back(3);
		hello.push_back(3);
	*/
	Solution a;
	cout << a.findMin(hello) << endl;
	return 0;
}