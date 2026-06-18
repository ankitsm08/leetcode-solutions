#include <algorithm>

using namespace std;

class Solution {
public:
  double angleClock(int hour, int minutes) {
    const double hourAngle = (hour % 12) * 30 + minutes * 0.5;
    const double minuteAngle = minutes * 6;
    const double angle = abs(hourAngle - minuteAngle);
    return min(angle, 360 - angle);
  }
};
