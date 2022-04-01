#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if 1
typedef int (*xcmp_t)(void *lhs, int lsz, void *rhs, int rsz);

int compare (void const *lhs, int lsz, void const* rhs, int rsz) 
{ 

    // return lsz - rsz;
	return *((const int *)lhs) < *((const int *) rhs); 
}
#endif 

inline static void deep_copy (char* dest, const char* source, int len) 
{
    assert (dest && source);

    for (int i = 0; i < len; ++i)
        dest[i] = source[i];
}

static void swap (char *lhs, int lsz, char *rhs, int rsz) 
{
    char* between = NULL;
    char* tmpLhs = NULL;
    size_t distance = 0;

    if (lhs == rhs)
        return;

    distance = rhs - lhs - lsz;
    
    between = (char*) calloc (distance, sizeof (char));
    assert (between);
    tmpLhs = (char*) calloc (lsz, sizeof (char));
    assert (tmpLhs);

    deep_copy (between, lhs + lsz, distance);
    deep_copy (tmpLhs, lhs, lsz);

    for (int i = 0; i < rsz; ++ i)
        lhs[i] = rhs[i];
    
    lhs += rsz; 
    for (int i = 0; i < distance; ++i)
        *(lhs + i) = between[i];

    lhs += distance;
    for (int i = 0; i < lsz; ++i)
        *(lhs + i) = tmpLhs[i];

    free (between);
    free (tmpLhs);
}  

inline static int count_len (int* sizes, int dest)
{
    int totalSize = 0;
    for (int i = 0; i < dest; ++i)
        totalSize += sizes[i];

    return totalSize;
}

static char* merge_sort(char *mem, char *buffer, int* sizes, unsigned left, unsigned right, xcmp_t cmp)
{
    if (left == right)
    {
        buffer[left] = mem[left];
        return buffer;
    }

    int sizeToLeft = 0;
    int sizeToRight = 0;

    unsigned int middle = left + (right - left) / 2;

    // разделяй и сортируй
    int *l_buff = merge_sort(mem, buffer, sizes, left, middle, cmp);
    int *r_buff = merge_sort(mem, buffer, sizes, middle + 1, right, cmp);

    // слияние двух отсортированных половин
    int *target = l_buff == mem ? buffer : mem;
    unsigned l_cur = left, r_cur = middle + 1;

    for (unsigned i = left; i <= right; i++)
    {
        sizeToLeft = count_len (sizes, left);
        if (l_cur <= middle && r_cur <= right)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}

void xmsort(void *mem, int *sizes, int nelts, xcmp_t cmp) 
{
    int totalSize = 0;
    char* buffer = NULL;
    assert (mem && sizes);

    totalSize = count_len (sizes, nelts);
    
    buffer = (char*) calloc (totalSize, sizeof (char));
    assert (buffer);

    mem = (char*) merge_sort ((char*) mem, buffer, sizes, 0u, nelts, cmp);

    free (buffer);
}


#if 1
/*

int sort (void *parr, int eltsize, int numelts) {
	
	xcmp_t cmp = compare;
	assert (parr);

	for (int i = 0; i < numelts; ++i) 	
		selstep (parr, eltsize, numelts, i, cmp);
	
}


*/

static void dump (const int *arr, int n) {

	for (int i = 0; i < n; ++i)
		printf ("%d ", arr[i]);
    
    printf ("\n");
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

	dump (a, num);	
    swap ((char*) (a + 2), sizeof(a[0]), (char*) (a + num - 3), sizeof(a[0]));
    dump (a, num);
	// sort (a, sizeof (a[0]), num);
	
	free (a);
	// return 0;
}
#endif 
