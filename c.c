#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// Returns a random int
int genRand() {
  int fd = open("/dev/random", O_RDONLY);
  int p[1];
  read(fd, p, 4);
  close(fd);
  return p[0];
}

void printArr(int *arr, unsigned char length) {
  int i = 0;
  printf("[");
  for( ; i <length-1; i++)
    printf("%d, ", arr[i]);
  printf("%d]\n", arr[i+1]);
}

void writeArrToFile(int *arr){
  int fd = open("filey.mcfileface", O_CREAT | O_RDWR, 0644);
  write(fd, arr,10);
  close(fd);
}

void readArrFromFile(int *arr){
  int fd = open("filey.mcfileface", O_RDONLY);
  read(fd, arr,10);
  close(fd);
}

int main() {
  int arr1[10];
  int i = 0;
  for (; i<10; i++)
    arr1[i] = genRand();
  printArr(arr1, 10);

  printf("Writing numbers to file...\n");
  writeArrToFile(arr1);
  printf("\n");
  
  printf("Reading numbers from file...\n");
  int arr2[10];
  readArrFromFile(arr2);
  printf("\n");
  
  printf("Verification that written values were the same:\n");
  printArr(arr2, 10);

  return 0;
}
