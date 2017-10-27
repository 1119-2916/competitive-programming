#include <stdio.h>
#include <string.h>


int main(void) {
  int n = 0, i, end = 0, count;
  char array[50002] = {0};
  scanf("%s",array);
  n = strlen(array);
  for(i = 0; i < n; i++ ) {
    if(count == 1) {
      if(array[i] == ':') {
	puts("dict");
	end = 1;
	break;
      }
      if(array[i] == ',') {
	puts("set");
	end = 1;
	break;
      }
    }
    if(array[i] == '{') {
      count++;
    } else if(array[i] == '}') {
      count--;
    }
  }
  if(!end) {
    puts("dict");
  }
  return 0;
}
