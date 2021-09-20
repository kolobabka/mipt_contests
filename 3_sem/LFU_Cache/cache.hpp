#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>
#include <cassert>
//--------------------------------------------------------
//--------------------------------------------------------
enum whatList{

    IN,
    OUT,
    HOT
};
//--------------------------------------------------------
//--------------------------------------------------------
template <typename Data> struct ListNode {

    Data data;
    whatList place;
};
//--------------------------------------------------------
//--------------------------------------------------------
namespace caches {
    
    template <typename Key, typename Data>  
    struct QueueMap {

        size_t sizeList;

        std::list<ListNode<Data>> List;

        QueueMap(size_t size) : sizeList(size) {}

        bool IsFull () const {
            
            if (sizeList <= List.size ())
                return true;
            
            return false;
        }
    };

    template <typename Key, typename Data>  
    struct Cache_2Q {

        size_t cacheSize;

        QueueMap<Key, Data> In;
        QueueMap<Key, Data> Out;
        QueueMap<Key, Data> Hot;

        using ListIt = typename std::list<ListNode<Data>>::iterator;

        std::unordered_map<Key, ListIt> Map;

        Cache_2Q (size_t size) : 
            cacheSize (size), 
            In  (size / 5),
            Hot (size / 5),
            Out (size - size / 5 - size / 5) {}

        ~Cache_2Q () {}
    };
}
//--------------------------------------------------------
//--------------------------------------------------------
// template <typename Key, typename Data>  
// int CacheHit (caches::Cache_2Q<Key, ListNode<Data>> Cache, size_t numPages);