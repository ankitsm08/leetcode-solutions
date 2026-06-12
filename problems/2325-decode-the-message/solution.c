#include <stdlib.h>

char *decodeMessage(char *key, char *message) {
  int key_len = 0;
  char *p = key;
  while (*p++)
    key_len++;

  char map[26] = {0};
  int mi = 0;
  for (int i = 0; i < key_len; i++) {
    if (key[i] == ' ')
      continue;
    else if (map[key[i] - 'a'] == 0)
      map[key[i] - 'a'] = 'a' + mi++;
  }

  p = message;
  int message_len = 0;
  while (*p++)
    message_len++;

  char *decoded = malloc(message_len + 1);
  int di = 0;
  while (*message) {
    if (*message == ' ')
      decoded[di++] = ' ';
    else
      decoded[di++] = map[*message - 'a'];
    message++;
  }

  decoded[di] = '\0';
  return decoded;
}
