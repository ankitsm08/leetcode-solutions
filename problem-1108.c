#include <stdlib.h>
#include <string.h>

char *defangIPaddr(char *address) {
  int len = strlen(address);
  char *defangedAddress = malloc(len + 6 + 1);

  int idx = 0;
  for (int i = 0; i < len; i++) {
    if (address[i] == '.') {
      defangedAddress[idx++] = '[';
      defangedAddress[idx++] = '.';
      defangedAddress[idx++] = ']';
    } else {
      defangedAddress[idx++] = address[i];
    }
  }

  defangedAddress[len + 6] = '\0';
  return defangedAddress;
}
