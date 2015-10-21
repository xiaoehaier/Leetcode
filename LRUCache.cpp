/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, 
otherwise return -1.

set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item 
before inserting a new item.
*/
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


struct CacheNode
{
	int key;
	int value;
	CacheNode *pre;
	CacheNode *next;
    CacheNode():key(-1), value(-1), pre(NULL), next(NULL){} 
};

class LRUCache{

	CacheNode *bottom;
	CacheNode *top;
	CacheNode *cur;
	

public:
    LRUCache(int capacity) {
        bottom  = new CacheNode [capacity+2];
        top = bottom + sizeof(CacheNode)*(capacity+1);

        for (cur = bottom; cur < top; cur = cur->pre) {
        	cur->pre = cur + sizeof(CacheNode);
            cur->pre->next = cur;
        }
        cur = bottom->pre;
    }
    ~LRUCache()
    {
        delete [] bottom;
    }

    void toFirst(CacheNode *one)
    {
        one->pre->next = one->next;
        one->next->pre = one->pre;

        one->pre = cur;
        one->next = cur->next;
        one->next->pre = one;
        cur->next = one;
    }
    
    int get(int key) {
        CacheNode *tmp;
    	for (tmp = cur->next; tmp != bottom; tmp = tmp->next) 
    		if (tmp->key == key) break;

            
        if (tmp == bottom) return -1;

        if (tmp != cur->next)
            toFirst(tmp);
        
        return tmp->value;	
    }
    
    void set(int key, int value) {
        if (get(key) != -1) {
            cur->next->value = value;
            return;
        }

        if (cur == top) {
            CacheNode *tmp = bottom->pre;
            tmp->key = key;
            tmp->value = value;

            toFirst(tmp);
        } else {        
            cur->key = key;
            cur->value = value;
            cur = cur->pre; 
        }
    }

    void showCache()
    {
        CacheNode *tmp;
        for (tmp = cur->next; tmp != bottom; tmp = tmp->next)
            cout << tmp->key << "--" << tmp->value << endl;
        cout << endl;
    }
};


int main(int argc, char const *argv[])
{
    LRUCache a(10);
    a.set(10,13);a.set(3,17);a.set(6,11);a.set(10,5);a.set(9,10);
    a.showCache();
    cout << "13==" <<a.get(13) << endl << endl;
    a.set(2,19);
    a.showCache();
    cout << "2==" <<a.get(2) << endl << endl;
    cout << "3==" <<a.get(3) << endl << endl;
    a.set(5,25);
    a.showCache();
    cout << "8==" <<a.get(8) << endl << endl;
    a.set(9,22);a.set(5,5);a.set(1,30);
    a.showCache();
    cout << "11==" <<a.get(11) << endl << endl;
    a.set(9,12);
    a.showCache();
    cout << "7==" <<a.get(7) << endl << endl;
    cout << "5==" <<a.get(5) << endl << endl;
    cout << "8==" <<a.get(8) << endl << endl;
    cout << "9==" <<a.get(9) << endl << endl;
    a.set(4,30);a.set(9,3);
    a.showCache();
    cout << "9==" <<a.get(9) << endl << endl;
    cout << "10==" <<a.get(10) << endl << endl;
    cout << "10==" <<a.get(10) << endl << endl;
    a.set(6,14);a.set(3,1);
    a.showCache();
    cout << "3==" <<a.get(3) << endl << endl;
    a.set(10,11);
    a.showCache();
    cout << "8==" <<a.get(8) << endl << endl;
    a.set(2,14);
    a.showCache();
    cout << "1==" <<a.get(1) << endl << endl;
    cout << "5==" <<a.get(5) << endl << endl;
    cout << "4==" <<a.get(4) << endl << endl;
    
    a.set(11,4);a.set(12,24);a.set(5,18);
    a.showCache();
    cout << "13==" <<a.get(13) << endl << endl;
  
    a.set(7,23);
    a.showCache();
    cout << "8==" <<a.get(8) << endl << endl;
    cout << "12==" <<a.get(12) << endl << endl;
    
    a.set(3,27);a.set(2,12);
    a.showCache();
    cout << "5==" <<a.get(5) << endl << endl;
    a.set(2,9);a.set(13,4);a.set(8,18);a.set(1,7);
    a.showCache();
    cout << "6==" <<a.get(6) << endl << endl;
    a.set(9,29);a.set(8,21);
    a.showCache();
    cout << "5==" <<a.get(5) << endl << endl;
    a.set(6,30);a.set(1,12);
    a.showCache();

    cout << "10==" <<a.get(10) << endl << endl;
    a.set(4,15);a.set(7,22);a.set(11,26);a.set(8,17);a.set(9,29);
    a.showCache();
    cout << "5==" <<a.get(5) << endl << endl;
    a.set(3,4);a.set(11,30);
    a.showCache();
    cout << "12==" <<a.get(12) << endl << endl;
    a.set(4,29);
    a.showCache();
    cout << "3==" <<a.get(3) << endl << endl;
    cout << "9==" <<a.get(9) << endl << endl;
    cout << "6==" <<a.get(6) << endl << endl;
    
    a.set(3,4);
    a.showCache();
    cout << "1==" <<a.get(1) << endl << endl;
    cout << "10==" <<a.get(10) << endl << endl;
    a.set(3,29);a.set(10,28);a.set(1,20);a.set(11,13);
    a.showCache();
    cout << "3==" <<a.get(3) << endl << endl;
    a.set(3,12);a.set(3,8);a.set(10,9);a.set(3,26);
    a.showCache();
    cout << "8==" <<a.get(8) << endl << endl;
    cout << "7==" <<a.get(7) << endl << endl;
    cout << "5==" <<a.get(5) << endl << endl;
    a.set(13,17);a.set(2,27);a.set(11,15);
    a.showCache();
    cout << "12==" <<a.get(12) << endl << endl;
    a.set(9,19);a.set(2,15);a.set(3,16);
    a.showCache();
    cout << "1==" <<a.get(1) << endl << endl;
    a.set(12,17);a.set(9,1);a.set(6,19);
    a.showCache();
    cout << "4==" <<a.get(4) << endl << endl;
    cout << "5==" <<a.get(5) << endl << endl;
    cout << "5==" <<a.get(5) << endl << endl;

    a.set(8,1);a.set(11,7);a.set(5,2);a.set(9,28);
    a.showCache();
    cout << "1==" <<a.get(1) << endl << endl;
    a.set(2,2);a.set(7,4);a.set(4,22);a.set(7,24);a.set(9,26);a.set(13,28);a.set(11,26);
    a.showCache();


    /*a.set(1, 100);
    a.set(2, 200);
    a.showCache();
    a.get(2);
    a.get(1);
    a.showCache();
    a.set(2, 2000);
    a.showCache();
    a.set(3, 300);
    a.set(4, 400);
    a.set(3, 3000);
    a.get(1);
    a.showCache();
    a.set(5, 50);
    a.showCache();
    a.set(6, 600);
    a.showCache();
    a.set(6, 60);
    a.showCache();
    a.set(7, 70);
    a.showCache();
    a.get(1);
    a.showCache();*/
    /*a.set(1, 10);
    a.set(2, 20);
    a.set(3, 30);
    a.set(4, 40);
    a.set(5, 50);
    a.showCache();
    a.set(6, 60);
    a.showCache();*/


    return 0;
}