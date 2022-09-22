#include <stdio.h>

//Declaring functions
void bubble(int n,int k[]);
int binary(int k[], int find, int low, int high);
int binaryRec(int k[], int find, int low, int high);


int main(void)
{
    int problem[] = {6,2,3,4,5,1,7,8,14,10,11,12,13,9,15,16,17,18,20,19,26,25,32,31,31};
    
    //Length of array
    size_t problemLen = sizeof(problem) / sizeof(problem[0]);

    bubble(problemLen, problem);

    //Print the newly sorted array
    printf("Sorted array: \n");
    for(int y = 0; y < problemLen; y++)
    {
        printf("%i ", problem[y]);
    }
    printf("\n");

    //Printing the index of an element through binary search
    int result = binary(problem, 25, 0, problemLen - 1);
    int resultRec = binaryRec(problem, 25, 0, problemLen - 1);
    if(result == -1)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Element is found at index %d\n", result);
    }



    if(resultRec == -1)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("(Recursive version) Element is found at index %d\n", resultRec);
    }

}







//Bubble sort
void bubble(int n, int k[])
{
    int swapCounter = 1;
    while(swapCounter != 0)
    {
        swapCounter = 0;
        for(int x = 0; x < n - 1; x++)
        {
            if(k[x] > k[x+1])
            {
                int subvar = k[x];
                k[x] = k[x+1];
                k[x+1] = subvar;
                swapCounter += 1;

            }
        }
    }
}


//Iterative Binary Search
int binary(int k[], int find, int low, int high)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(k[mid] == find)
        {
            return mid;
        }
        if(k[mid] < find)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

//Recursive Binary Search
int binaryRec(int k[], int find, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (k[mid] == find)
      return mid;

    // Search the left half
    if (k[mid] > find)
      return binaryRec(k, find, low, mid - 1);

    // Search the right half
    return binaryRec(k, find, mid + 1, high);
  }

  return -1;
}
