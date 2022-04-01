#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if 1
typedef int (*cmp_t)(void const * lhs, void const * rhs);

int compare (void const *lhs, void const* rhs) { 

	return *((const int *)lhs) < *((const int *) rhs); 
}
#endif 
static void swap (char *lhs, char *rhs, int eltsize) 
{
	char *tmp = NULL;
	tmp = (char*) calloc (eltsize, sizeof (char));
	assert (tmp);
	assert (lhs);
	assert (rhs);

	for (int i = 0; i < eltsize; ++i) 
    {
		tmp[i] = lhs[i];
		lhs[i] = rhs[i];
		rhs[i] = tmp[i];
	}

	free (tmp);
}

int selstep (void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp) 
{		
	int minInd = nsorted;
	assert (parr);

	for (int i = nsorted + 1; i < numelts; ++i) 
		if (cmp (parr + (i * eltsize), parr + (minInd * eltsize)))
			minInd = i;
	
	if (minInd != nsorted) 
		swap (parr + (nsorted * eltsize), parr + (minInd * eltsize), eltsize);
	
	return 0;
}
#if 1

int sort (void *parr, int eltsize, int numelts) {
	
	cmp_t cmp = compare;
	assert (parr);

	for (int i = 0; i < numelts; ++i) 	
		selstep (parr, eltsize, numelts, i, cmp);
	
}

static void dump (const int *arr, int n) {

	for (int i = 0; i < n; ++i)
		printf ("%d ", arr[i]);
}

static void fill (int *arr, int n) {
	
	for (int i = 0; i < n; ++i)
		scanf ("%d", arr + i);
}

int main () {
	
	int num = 0;
	int* a = NULL;

	scanf ("%d", &num);
	a = (int*) calloc (num, sizeof (a));

	fill (a, num);		
	sort (a, sizeof (a[0]), num);
	
	dump (a, num);	
	
	free (a);
	return 0;
}
#endif 
