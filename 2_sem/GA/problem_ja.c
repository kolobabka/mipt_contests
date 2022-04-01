#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct order_t { 

    int number; 
    int deadline; 
    int cost; 
};

struct answer_t { 

    int norders; 
    int *numbers; 
};

typedef int (*int_cmp_t) (const void *lhs, const void *rhs);

static int compare (const void* lhs, const void* rhs) {

    struct order_t* left = (struct order_t*) lhs;
    struct order_t* right = (struct order_t*) rhs;
    assert (lhs && rhs);

    return right->deadline - left->deadline;
}

static void dumpOrders (const struct order_t* orders, size_t n) {

    assert (orders);

    for (size_t i = 0; i < n; ++i) 
        printf ("number: %d\n\tdeadline: %d, cost: %d\n", 
                orders[i].number, orders[i].deadline, orders[i].cost);
}

static void dumpAnsw (const struct answer_t* answ) {

    assert (answ);

    for (int i = 0; i < answ->norders; ++i) 
        printf ("norders: %d\n\tnumber: %d\n", 
                i + 1, answ->numbers[i]);
}

static void fillOrders (struct order_t* orders, size_t n) {

    assert (orders);

    for (size_t i = 0; i < n; ++i) {

        orders[i].number = i + 1;
        assert (scanf ("%d%d", &(orders[i].cost), &(orders[i].deadline)) == 2);
    }
}

struct answer_t betforjobs (struct order_t * orders, int n, int totaltime) {

    int curDeadline = 0;
    struct answer_t answ;
    struct order_t *copyOrders = NULL;
    assert (orders);

    answ.norders = 0;
    answ.numbers = (int*) calloc (totaltime, sizeof (int));
    assert (answ.numbers);
    copyOrders = (struct order_t *) calloc (n, sizeof (struct order_t));
    assert (copyOrders); 

    memcpy (copyOrders, orders, sizeof (struct order_t) * n);
    qsort (copyOrders, n, sizeof (struct order_t), (int_cmp_t) compare);

    #if 0
    dumpOrders (copyOrders, n);
    #endif 

    curDeadline = copyOrders[0].deadline;


    for (int i = 0; i < totaltime; ++i) {

        int curMaxCost = 0, curMaxInd = 0; 

        if (curDeadline == -1)
            break;
        
        for (int j = 0; j < n && copyOrders[j].deadline >= curDeadline; ++j) {

            if (curMaxCost < copyOrders[j].cost) {
                
                curMaxInd = j;
                curMaxCost = copyOrders[j].cost;
            }   
        }   

        --curDeadline;
        ++answ.norders;
        answ.numbers[i] = copyOrders[curMaxInd].number;
        copyOrders[curMaxInd].cost = -1;
    }

    #if 0
    dumpAnsw (copyOrders, n);
    #endif 

    free (copyOrders);
    return answ;
}



int main () { 

    int n = 0, totaltime = 0;
    struct order_t* orders = NULL;
    struct answer_t res;
    int sum = 0;

    assert (scanf ("%d%d", &totaltime, &n) == 2);

    orders = (struct order_t*) calloc (n, sizeof (struct order_t));
    assert (orders);

    fillOrders (orders, n);
    res = betforjobs (orders, n, totaltime);

    for (int i = 0; i < res.norders; ++i)
        sum += orders[res.numbers[i] - 1].cost;

    printf ("sum = %d\n", sum);
    free (orders);
    free (res.numbers);
    return 0;
}

