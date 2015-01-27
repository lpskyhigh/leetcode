public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        int len = A.length + B.length;
        if (len % 2 == 1)
            return findKth(A, 0, B, 0, len / 2 + 1);
        else
            return (findKth(A, 0, B, 0, len / 2) + findKth(A, 0, B, 0, len / 2 + 1)) / 2;
    }

    double findKth(int A[], int startA, int B[], int startB, int k) {
        if (startA >= A.length)
            return B[startB + k - 1];
        if (startB >= B.length)
            return A[startA + k - 1];
        if (k == 1)
            return A[startA] < B[startB] ? A[startA] : B[startB];

        int lenA = (startA + k / 2 < A.length) ? k / 2 : A.length - startA;
        int lenB = (startB + k - lenA < B.length) ? k - lenA : B.length - startB;
        if (lenA == 0)
            return B[startB + k - 1];
        if (lenB == 0)
            return A[startA + k - 1];

        int a = A[startA + lenA - 1];
        int b = B[startB + lenB - 1];

        if (a < b) {
           return findKth(A, startA + lenA, B, startB, k - lenA);
        }
        if (a > b) {
           return findKth(A, startA, B, startB + lenB, k - lenB);
        }
        return a;
    }
}
