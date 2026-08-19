#include <cstdint>
#include <memory_resource>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  static inline pmr::unsynchronized_pool_resource pool;

public:
  static int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
    const int m = static_cast<int>(reservedSeats.size());

    pmr::unordered_map<int, uint8_t> seats(&pool);
    seats.reserve(m);

    for (auto &seat : reservedSeats) {
      const int col = seat[1];
      if (col < 2 || col > 9)
        continue;
      seats[seat[0]] |= 1 << (col - 2);
    }

    const uint8_t A = 0b00001111;
    const uint8_t B = 0b00111100;
    const uint8_t C = 0b11110000;
    const uint8_t D = A | C;

    int cnt = static_cast<int>(n - seats.size()) * 2;

    for (auto [_, S] : seats) {
      S = static_cast<uint8_t>(~S);
      cnt += (S & A) == A || (S & B) == B || (S & C) == C;
      cnt += (S & D) == D;
    }

    return cnt;
  }
};
