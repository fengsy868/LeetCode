#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int * res = (int*)malloc(sizeof(int)*(nums1Size + nums2Size));
    int m = nums1Size;
    int n = nums2Size;
    int* head = res;
    double median;
    printf("m = %d, n = %d\n",m,n);
    
    while(m != 0 | n!= 0)
    {
        if(m == 0){
            *res = *nums2;
            nums2 = nums2 + 1;
            n--;
            res += 1;
        }else if(n == 0){
            *res = *nums1;
            nums1 = nums1 + 1;
            m--;
            res += 1;
        }else if(*nums1 > *nums2){
            *res = *nums2;
            res += 1;
            nums2 += 1;
            n--;
        }else{
            *res = *nums1;
            res += 1;
            nums1 += 1;
            m--;
        }
        
    }
    
    for (int i = 0; i < nums1Size+nums2Size; ++i)
    {
        printf("Index : %d\tValue : %d\n",i, head[i] );
    }

    if((nums2Size+nums1Size)%2 == 0) median=(double)(head[(nums2Size+nums1Size)/2-1]+head[(nums2Size+nums1Size)/2])/2;
    else median = head[(nums2Size+nums1Size+1)/2 -1];
    
    printf("Median = %f\n",median);

    return median;
}

int main(){
    int nums1[] = {0,4,4,5};
    int nums2[] = {1,4,5,6,8,9};

    size_t m = sizeof(nums1)/sizeof(int);
    size_t n = sizeof(nums2)/sizeof(int);

    double res = findMedianSortedArrays(nums1, m, nums2, n);

    printf("Result is = %f\n", res);

    return 0;
}