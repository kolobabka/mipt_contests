#include <iostream>
#include <list>
#include <unordered_map>

template <typename T, typename F, typename KeyT = int>

struct cache_t {

    size_t sz_;
    
    std::list<T> cache_;
    using ListIt = typename std::list<T>::iterator;
    std::unordered_map<int, ListIt> hash_;
    bool full() const;
    bool lookup_update(KeyT key, F slow_get_page);
};