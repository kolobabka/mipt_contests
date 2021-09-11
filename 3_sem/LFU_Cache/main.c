#include "LFU.hpp"

int main () {

  page_t *request = new page_t;

  request->page = 5;
  cache_t <int, int, int> Cache {10};

  std::cout << Cache.sz_ << std::endl;

  
}
