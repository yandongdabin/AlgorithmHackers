// 假设这些cache块存储在某个数据结构 ，我们希望能够对这个cache块：记录时间戳
//每次set元素查看该元素是否存在，存在更新时间戳，不存在则删去时间戳最大的元素，然后插入新的元素
//get元素要求我们能够迅速的判断key是否在集合中，可以用map记录key


//现在我们采取一种策略也，不记录时间戳 而用元素在数据结构中的顺序来模拟时间戳，越靠前的元素时间戳越小 vice versa

//每次访问到而且存在于 cache中的元素 移到数据结构的前面

//我们需要的操作有 查看是否存在 map
//随意删除尾部元素 插入头部元素  将任意元素移动到首部

//可以考虑的数据结构 链表

//list  splice(list::iterator z,list y,list::iterator z) 将 y中的z元素移动到z位置

#include<unordered_map>
#include<list>
#include<iostream>
using namespace std;
class LRUCache{
public:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int key,int value){
            this->key = key;
            this->value = value;
        }
    };
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(cMap.find(key)==cMap.end()){
            return -1;
        }
        //将该元素移动到表头
        cache.splice(cache.begin(),cache,cMap[key]);
        cMap[key] = cache.begin();
        return cMap[key]->value;
    }

    void set(int key, int value) {
        if(cMap.find(key) == cMap.end()){
            if(capacity == cache.size()){
                cMap.erase(cache.back().key);
                cache.pop_back();
            }
            cache.push_front(CacheNode(key,value));
            cMap[key] = cache.begin();

        }else{
            //
            cache.splice(cache.begin(),cache,cMap[key]);
            cMap[key] = cache.begin();
            cMap[key]->value = value;
        }

    }
private:
    unordered_map<int,list<CacheNode>::iterator> cMap;
    list<CacheNode> cache;
    int capacity;
};
int main(){
    LRUCache c(2);
    c.set(1,2);
    cout<<c.get(1)<<endl;
    c.set(2,2);
    c.set(3,2);

    cout<<c.get(2)<<endl;
    cout<<c.get(4)<<endl;
    return 0;
}
