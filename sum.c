#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024

int main() {
  char buf [BUFSIZE];
  char key [BUFSIZE];
  char value [BUFSIZE];
  char last_key [BUFSIZE] = "\0";
  double el;
  double sum;
  int count = 0;
  int i;
  while (fgets(buf, sizeof(buf), stdin) != NULL) {
    for (i = 0; i < strlen(buf); i++) {
      // We've got our key for comparison
      if (buf[i] == '\t') {
        // Check key against previous key
        key[i] = '\0';

        // Advance counters
        count++;
        strncpy(value, buf + strlen(key) + 1, strlen(buf) - strlen(key) - 2);
        value[strlen(buf) - strlen(key) - 2] = '\0';
        el = atof(value);
        sum += el;

        // Keys do not match, print summary and reset counters
        if (strncmp(key, last_key, strlen(key))) {
          // If this is not the first row, print the key and aggregates
          if (strlen(last_key) > 1) {
            printf("%s\t%d\t%f\n", last_key, count, sum);
          }
          
          // Reset the counters
          sum = 0.0;
          count = 0;
          strncpy(last_key, key, strlen(key));
          last_key[strlen(key)] = '\0';
        }
      } else {
        key[i] = buf[i];
      }
    }
  }

  count++;
  printf("%s\t%d\t%f\n", key, count, sum);
}