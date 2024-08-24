#include "chrono"
#include "constants.h"
#include "canvas.cpp"
#include "cell.cpp"

int main() {
  canvas c = canvas(24, 80);
  int start = std::chrono::duration_cast<std::chrono::milliseconds>(
                  std::chrono::system_clock ::now().time_since_epoch())
                  .count();
  while (1) {
    int cur = std::chrono::duration_cast<std::chrono::milliseconds>(
                  std::chrono::system_clock ::now().time_since_epoch())
                  .count();
    if (cur - start > 100) {
      c.render_cells();
      c.next_gen();
      start = cur;
    }
  }
  return 0;
}
