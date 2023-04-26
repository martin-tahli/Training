//
// Напишете функцията int linear_search(const int a[], int n, int key);
//използвайки адресна аритметика без инкрементиращи променливи


#include <stdio.h>

int linear_search(const int a[], int n, int key)
{int i;
int *ptr=a;

  for ( i = 0; i < n; i++,ptr++)
  {
    if (*ptr == key)    /* If required element is found */
    {
      printf("%d is present at location %d.\n", key, i+1);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array.\n", key);
}

int main()
{
int arr[]={1,2,6,8,3,4,8,9,5};
int n=9;
int key=41;
linear_search(arr,n,key);

return 0;
}
