#include <string.h>

char *interpret(char *command) {
  int originalLen = strlen(command);

  int count = 0;
  for (int i = 0; i < originalLen; i++) {
    if (command[i] == 'G') {
      command[count++] = 'G';
    } else if (command[i] == '(' && command[i + 1] == ')') {
      command[count++] = 'o';
      i++;
    } else if (command[i] == '(' && command[i + 1] == 'a') {
      command[count++] = 'a';
      command[count++] = 'l';
      i += 3;
    }
  }
  command[count] = '\0';

  return command;
}
