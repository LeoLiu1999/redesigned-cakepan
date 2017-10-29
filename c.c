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
  return p[0];
}

void printArr(int *arr, unsigned char length) {
  int i = 0;
  printf("[");
  for( ; i <length-1; i++)
    printf("%d, ", arr[i]);
  printf("%d]\n", arr[i+1]);
}

int main() {
  int arr[10];
  int i = 0;
  for (; i<10; i++)
    arr[i] = genRand();
  printArr(arr, 10);
  return 0;
}
