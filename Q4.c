/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

Combine and sort the two arrays and find the median
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  unsigned int target1, target2, stop, i=0, j=0, total=0, tmp;
  int n1, n2;

  //find the position of MIDDLE
  if((nums1Size+nums2Size)%2) // odd
  {
    target1=(nums1Size+nums2Size+1)/2;
    target2=0;
  }
  else // even
  {
    target1=(nums1Size+nums2Size)/2;
    target2=target1+1;
  }

  stop=target2?target2:target1;
  while(total<=stop)
  {
    // nums1[i], nums2[j]
    if(j>=nums2Size || (*(nums1+i)<=*(nums2+j) && i<nums1Size))
    {
      tmp=*(nums1+i);
      i++;
    }
    else
    {
      tmp=*(nums2+j);
      j++;
    }
    total++;
    if(total==target1)
      n1=tmp;
    if(target2!=0 && total==target2)
      n2=tmp;
  }

  if(target2==0)
    return (double) n1; 
  else 
    return (double)(n1+n2)/2;
  
}
