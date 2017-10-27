#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

//TODO
int genRand(int bytes) {
  int fd = open("/dev/random", O_RDONLY);
  return ;
}

int main() {

  return 0;
}
