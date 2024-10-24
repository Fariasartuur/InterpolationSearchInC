#include <stdio.h>

int interpolationSearch(int array[], int arraySize, int num){
  int first = 0;
  int last = arraySize - 1;
  int position;
  int attempts = 0;

  while(first <= last && num >= array[first] && num <= array[last]){

    attempts++;
    position = first + ((num - array[first]) * (last - first)) / (array[last] - array[first]);

    if(array[position] == num){
      printf("%d attempts.\n", attempts);
      return position;
    }

    if(array[position] < num){
      first = position + 1;
    }

    if(array[position] > num){
      last = position - 1;
    }
    
  }
  return -1;
}

int main(){
  int array[] = {2, 5, 6, 8, 9, 10, 13, 15, 16, 20, 23, 25, 28, 32, 35, 39, 50, 52, 55, 58, 60};
  int arraySize = sizeof(array) / sizeof(array[0]);
  int num = 23;

  int result = interpolationSearch(array, arraySize, num);

  if(result == -1){
    printf("Couldn't find the number %d at the array\n", num);
  } else{
    printf("number %d found at the index %d", num, result);
  }
  return 0;
}
