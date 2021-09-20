#include "cache.hpp"
//--------------------------------------------------------
//--------------------------------------------------------
template <typename Key, typename Data>
int CacheHit (caches::Cache_2Q<Key, Data> Cache, size_t numPages) {

    int numHit = 0;

    for (int i = 0; i < numPages; i++) {

        Data data;
        std::cin >> data;

        assert (std::cin.good ());

        auto page = Cache.Map.find (data);

        if (page == Cache.Map.end ()) {

            ListNode<Data>node = {data, IN};
            if (Cache.In.IsFull ()) {

                auto backList = Cache.Map.find(Cache.In.List.back().data);

                if (!Cache.Out.IsFull ()) {
                
                    auto Iter = *(backList->second);

                    Cache.Map.erase(Iter);
                    
                    Iter.place = OUT;
                    Cache.Out.List.push_front(Iter);
                
                    Cache.Map.insert({(Iter).data, Cache.Out.List.begin()});

                    Cache.In.List.pop_back();

                }
                else {

                    auto backOut = Cache.Map.find(Cache.Out.List.back().data);
                    Cache.Map.erase(backOut);
                    Cache.Out.List.pop_back();

                    auto Iter = backList->second;

                    Cache.Map.erase(backList);

                    Iter->place = OUT;
                    Cache.Out.List.push_front(*(Iter));

                    Cache.Map.insert({Iter->data, Cache.Out.List.begin()});
                    Cache.In.List.pop_back();

                }

                Cache.In.List.push_front (node);
                Cache.Map.insert({data, Cache.In.List.begin()});

            }
            else {

                Cache.In.List.push_front (node);
                Cache.Map.insert({data, Cache.In.List.begin()});

                auto page_2 = Cache.Map.find (data);
            }

        }
        else {

            if (page->second->place == IN) {

                ++numHit;
                continue;
            }

            if (page->second->place == OUT) {

                if (!Cache.Hot.IsFull ()) {

                    page->second->place = HOT;
                    Cache.Hot.List.splice(Cache.Hot.List.begin(), Cache.Out.List, page->second);

                    ++numHit;
                    continue;
                }
                else {

                    auto backHot = Cache.Map.find(Cache.Hot.List.back().data);
                    Cache.Map.erase(backHot);
                    Cache.Hot.List.pop_back();

                    page->second->place = HOT;
                    Cache.Hot.List.splice(Cache.Hot.List.begin(), Cache.Out.List, page->second);

                    ++numHit;
                    continue;
                }
            }
            if (page->second->place == HOT) {

                Cache.Hot.List.splice(Cache.Hot.List.begin(), Cache.Hot.List, page->second);
                ++numHit;
            }
        }

    }

    return numHit;
}

int main () {

    size_t cacheSize = 0;
    size_t numPages  = 0;

    std::cin >> cacheSize >> numPages;
    assert(std::cin.good());

    caches::Cache_2Q<int, int> Cache{cacheSize};

    int result = CacheHit (Cache, numPages);

    std::cout << result << std::endl;
}
