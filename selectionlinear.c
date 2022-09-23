#include <stdio.h>

//Declaring of functions
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void linearSearch(int arr[], int n, int result);

int main(void)
{
    int problem[] = {6,2,3,4,5,1,7,8,14,10,11,12,13,9,15,16,17,18,20,19,26,25,32,31,31};

    //Finding length of list
    int problemLen = sizeof(problem) / sizeof(problem[0]);

    selectionSort(problem, problemLen);

    printf("Sorted array: \n");
    for(int k = 0; k < problemLen; k++)
    {
        printf("%d ", problem[k]);
    }
    printf("\n");

    linearSearch(problem, problemLen, 31);

    return 0;
}


//Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            swap(&arr[min], &arr[i]);
        }
        
    }
}


//Swapping positions betwwen 2 positions in list
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


//Linear Search
void linearSearch(int arr[], int n, int result)
{   
    int x;
    for(x = 0; x < n; x++)
    {
        if(result == arr[x])
        {
            printf("Element is found at index %d\n", x);
        }
    }
}

