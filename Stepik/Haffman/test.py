from heapq import heappop, heappush, heapify
from collections import Counter

def main():
    string = input()

    counter = Counter(string)

    if len(counter) == 1:
        codes = dict.fromkeys(counter, '0')
    else:
        codes = dict.fromkeys(counter, '')

        heap = [(count, sym) for sym, count in counter.items()]

        heapify(heap)

        while (len(heap) > 1):
            cntr, symr = heappop(heap)
            cntl, syml = heappop(heap)

            node = (cntr + cntl, symr + syml)

            heappush(heap, node)

            for sym in syml:
                codes[sym] = '0' + codes[sym]

            for sym in symr:
                codes[sym] = '1' + codes[sym]

    encoded = ''.join(codes[sym] for sym in string)

    print(len(counter), len(encoded))

    for ch in codes:
        print(ch + ":", codes[ch])

    print(encoded)

if __name__ == "__main__":
    main()
