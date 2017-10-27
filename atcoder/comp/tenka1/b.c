#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[50002];
int length;

int get_pa_end(void) {
    int i;
    for(i = 0; i < length; i++ ) {
        if(string[i] == '}') {
            return i;
        }
    }
}

int get_pa_start(int end) {
    int i;
    for(i = end; 0 <= i; i-- ) {
        if(string[i] == '{') {
            return i;
        }
    }
}

int d_or_s(int start, int end) {
  int i;
  for(i = start; i < end; i++ ) {
    if(string[i] == ',') {
      return 1;
    }
  }
  return 0;
}

void slide(int start, int end ) {
  int i, gap;
  gap = end - start + 1;
  for(i = 1; i <= gap; i++ ) {
    string[i + start] = '0';
  }
}

int main(void) {
  int i, j, n, end, start, sd;

    scanf("%s",string);
    length = strlen(string);

    while(1) {
        end = get_pa_end();
        start = get_pa_start(end);
	sd = d_or_s(start, end); //1S0D

	if(sd) {
	  string[start] = 's';
	} else {
	  string[start] = 'd';
	}

	//length -= (end - start);
	//printf("%d\n",length);
		if(string[0] == 's' || string[0] == 'd') {
		  break;
	  }
	slide(start, end);
	//printf("%s",string);
    }
    if(string[0] == 's') {
      puts("set");
    } else {
      puts("dict");
    }
    return 0;
}
