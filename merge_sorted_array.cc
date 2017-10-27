/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m andn respectively.

分析
    算法思想是：由于合并后A数组的大小必定是m+n，所以从最后面开始往前
    赋值，先比较A和B中最后一个元素的大小，把较大的那个插入到m+n-1的
    位置上，再依次向前推。如果A循环完了，B中还有元素没加入A素没加入A，
    直接把B中所有的元素覆盖到A剩下的位置。
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int count = m + n - 1;
        m--;n--;

        while( m >= 0 && n >= 0 ) A[count--] = A[m] > B[n] ? A[m--] : B[n--];
        while( n >= 0 ) A[count--] = B[n--];
    }
};

void printArray(int A[], int n) {
    printf("{");
    for(int i=0; i<n; i++) {
        printf("%d, ", A[i]);
    }
    printf("}\n");
}

int main()
{
    Solution solu;

    int a[]={2,4,6,8,10,0,0,0};
    int b[]={1,3,5};
    solu.merge(a, 5, b, 3 );
    printArray(a,  sizeof(a)/sizeof(int));

    int a1[]={2,4,0,0,0};
    int b1[]={3,5,7};
    solu.merge(a1, 2, b1, 3 );
    printArray(a1, sizeof(a1)/sizeof(int));

    int a2[]={12,14,16,18,20,0,0,0};
    int b2[]={1,3,5};
    solu.merge(a2, 5, b2, 3 );
    printArray(a2,  sizeof(a2)/sizeof(int));

    int a3[]={2,4,6,8,10,0,0,0};
    int b3[]={11,13,15};
    solu.merge(a3, 5, b3, 3 );
    printArray(a3,  sizeof(a3)/sizeof(int));

    int a4[]={2,4,0,0,0,0,0,0};
    int b4[]={2,3,5,7,9,11};
    solu.merge(a4, 2, b4, 6 );
    printArray(a4, sizeof(a4)/sizeof(int));
    return 0;
}
