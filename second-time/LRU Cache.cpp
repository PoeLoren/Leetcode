class LRUCache{
public:
    struct CacheEntry{
        int key;
        int value;
        CacheEntry(int k, int v):key(k), value(v){
        };
    };
    LRUCache(int capacity) {
        mCapacity = capacity;
    }
    
    int get(int key) {
        if(mMap.find(key) == mMap.end())
            return -1;
        MoveToHead(key);
        return mLruCache.begin()->value;
    }
    
    void set(int key, int value) {
        if(mMap.find(key) == mMap.end())
        {
            CacheEntry cacheEntry(key, value);
            if(mLruCache.size() == mCapacity)
            {
                mMap.erase(mLruCache.back().key);
                mLruCache.pop_back();
            }
            mLruCache.push_front(cacheEntry);
            mMap[key] = mLruCache.begin();
            return;
        }
        mMap[key]->value = value;
        MoveToHead(key);
        return;
    }
    
private:
    void MoveToHead(int key)
    {
        auto item = *mMap[key];
        mLruCache.erase(mMap[key]);
        mLruCache.push_front(item);
        mMap[key] = mLruCache.begin();
    }
    unordered_map<int, list<CacheEntry>::iterator>  mMap;
    list<CacheEntry>  mLruCache;
    int mCapacity;
};