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
            Hot (size / 5),
            Out (3 * (size / 5)),
            In (size - (3* (size / 5)) - (size / 5)) {}

        ~Cache_2Q () {}

        
        int CacheHit (size_t numPages) {

            int numHit = 0;

            for (size_t i = 0; i < numPages; i++) {

                Data data;
                std::cin >> data;

                assert (std::cin.good ());
                
                auto page = Map.find (data);

                if (page == Map.end ()) {
                    
                    ListNode<Data>node = {data, IN};
                    if (In.IsFull ()) {

                        auto backList = Map.find(In.List.back().data);

                        if (!Out.IsFull ()) {
                        
                            backList->second->place = OUT;
                            Out.List.splice(Out.List.begin(), In.List, backList->second);

                        }
                        else {

                            if (Out.List.size () == 0) {

                                Map.erase (backList);
                                In.List.pop_back();
                                In.List.push_front (node);
                                Map.insert({data, In.List.begin()});

                                continue;
                            }

                            auto backOut = Map.find(Out.List.back().data);
                            Map.erase(backOut);
                            Out.List.pop_back();

                            backList->second->place = OUT;
                            Out.List.splice(Out.List.begin(), In.List, backList->second);

                        }

                        In.List.push_front (node);
                        Map.insert({data, In.List.begin()});

                    }
                    else {

                        In.List.push_front (node);
                        Map.insert({data, In.List.begin()});
                    }

                }
                else {

                    if (page->second->place == IN) {

                        ++numHit;
                        continue;
                    }

                    if (page->second->place == OUT) {

                        if (!Hot.IsFull ()) {

                            page->second->place = HOT;
                            Hot.List.splice(Hot.List.begin(), Out.List, page->second);

                            ++numHit;
                            continue;
                        }
                        else {

                            auto backHot = Map.find(Hot.List.back().data);
                            Map.erase(backHot);
                            Hot.List.pop_back();

                            page->second->place = HOT;
                            Hot.List.splice(Hot.List.begin(), Out.List, page->second);

                            ++numHit;
                            continue;
                        }
                    }
                    if (page->second->place == HOT) {

                        Hot.List.splice(Hot.List.begin(), Hot.List, page->second);
                        ++numHit;
                    }
                }

            }

        return numHit;
        }
    };
}
//--------------------------------------------------------
//--------------------------------------------------------
// template <typename Key, typename Data>  
// int CacheHit (caches::Cache_2Q<Key, ListNode<Data>> Cache, size_t numPages);