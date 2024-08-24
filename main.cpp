#include "chrono"
#include "constants.h"
#include "iostream"
#include <cstdio>
#include <vector>

class cell {
public:
  char text;
  cell(char t) { text = t; }
};

class canvas {
public:
  std::vector<std::vector<cell>> rows;
  std::vector<std::vector<cell>> next_gen_rows;

  canvas(int row_count, int col_count) {
    for (int i = 0; i < row_count; i++) {
      rows.push_back(std::vector<cell>(col_count, cell(' ')));
      next_gen_rows.push_back(std::vector<cell>(col_count, cell(' ')));
    }using namespace std::chrono;
milliseconds ms = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch()
);
    rows[row_count / 2][col_count / 2].text  = '*';
    rows[row_count / 2][col_count / 2 - 1].text = '*';
    rows[row_count / 2 - 1][col_count / 2].text = '*';
    rows[row_count / 2 + 1][col_count / 2].text = '*';
    rows[row_count / 2 + 1][col_count / 2+1].text  = '*';
  };

  bool is_alive(int row, int col) {
    if (row >= 0 && row < rows.size() && col >= 0 && col < rows[row].size()) {
      cell c = rows[row][col];
      if (c.text == '*')
        return true;
      return false;
    }
    return false;
  }

  void next_gen() {
    for (int i = 0; i < rows.size(); i++) {
      for (int j = 0; j < rows[i].size(); j++) {
        int neighbour_count = 0;
        if (is_alive(i + 1, j))
          neighbour_count++;
        if (is_alive(i - 1, j))
          neighbour_count++;
        if (is_alive(i, j + 1))
          neighbour_count++;
        if (is_alive(i, j - 1))
          neighbour_count++;
        if (is_alive(i + 1, j + 1))
          neighbour_count++;
        if (is_alive(i + 1, j - 1))
          neighbour_count++;
        if (is_alive(i - 1, j + 1))
          neighbour_count++;
        if (is_alive(i - 1, j - 1))
          neighbour_count++;

        bool is_cur_cell_alive = is_alive(i, j);

        if (is_cur_cell_alive) {
          if (neighbour_count < 2)
            next_gen_rows[i][j].text = ' ';
          else if (neighbour_count == 2 || neighbour_count == 3)
            next_gen_rows[i][j].text = '*';
          else if (neighbour_count > 3)
            next_gen_rows[i][j].text=' ';
        } else {
          if (neighbour_count == 3)
            next_gen_rows[i][j].text  = '*';
        }
      }
    }
    rows = next_gen_rows;
  }

  void render_cells() {
    printf(CLEAR_SCREEN);
    for (auto row : rows) {
      for (cell c : row) {
        printf("%c", c.text);
      }
      printf("\n");
    }
  }
};

int main() {
  canvas c = canvas(24, 80);
  int start = std::chrono::duration_cast<std::chrono::milliseconds>(
                  std::chrono::system_clock ::now().time_since_epoch())
                  .count();
  while (1) {
    int cur = std::chrono::duration_cast<std::chrono::milliseconds>(
                  std::chrono::system_clock ::now().time_since_epoch())
                  .count();
    if (cur - start > 1000) {
      c.render_cells();
      c.next_gen();
	  start = cur;
    }
  }
  return 0;
}
