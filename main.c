#include <stdio.h>

int interpolationSearch(int arr[], int arrSize, int num){
  int first = 0;
  int last = arrSize - 1;
  int position;
  

  while(first <= last && num <= arr[last] && num >= arr[first]){
    
    if(arr[first] == arr[last]){
      if(arr[first] == num){
        return first;
      } else {
        return -1;
      }
    }

      position = first +
        ((num - arr[first]) *
        (last - first)) /
        (arr[last] - arr[first]);

    if(arr[position] == num){
      return position;
    }

    if (arr[position] < num) {
      first = position + 1;
    } else {
      last = position - 1;
    }
    
  }

  return -1;
}

int main(void) {

  int array[] = {10,20,30,40,50,60,70,80,90,100};
  int arraySize = sizeof(array) / sizeof(array[0]);

  int num = 90;

  int result = interpolationSearch(array, arraySize, num);

  if(result == -1){
    printf("Couldn't find %d on the array\n", num);
  } else{
    printf("Number %d found on the index %d", num, result);
  }
  
  return 0;
}