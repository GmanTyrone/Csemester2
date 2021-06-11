#include <stdio.h>

template<typename T>
T *sort(T *array, int n)
{
    for(int i=0; i<n;++i)
    {
        //finding the smallest number in the subarray
        int index_of_smallest = i;
        for(int j=i; j<n; j++)
        {
            if (array[j]<array[index_of_smallest])
                index_of_smallest = j;
        }

        //swapping
        T temp = array[i];
        array[i] = array[index_of_smallest];
        array[index_of_smallest] = temp;
    }
    return array;
}

int main(void)
{
    int n[10]={2,5,1,3,6,4,5,8,4,1};
    sort(n,9);
    for(int i=0;i<10;++i){
        printf("%d ",n[i]);
    }
    return 0;
}
