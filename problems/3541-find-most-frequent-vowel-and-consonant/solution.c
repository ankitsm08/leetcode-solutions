#include <stdbool.h>

int maxFreqSum(char *s) {
  int freq[26] = {0};
  const bool isVowel[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
                            0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

  for (int i = 0; *(s + i) != '\0'; i++) {
    freq[*(s + i) - 'a']++;
  }

  int maxVowel = 0;
  int maxConsonant = 0;
  for (int i = 0; i < 26; i++) {
    if (isVowel[i]) {
      if (freq[i] > maxVowel)
        maxVowel = freq[i];
    } else {
      if (freq[i] > maxConsonant)
        maxConsonant = freq[i];
    }
  }

  return maxVowel + maxConsonant;
}
