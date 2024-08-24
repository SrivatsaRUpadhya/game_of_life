#include "chrono"
#include "vector"

/*
 * cell just holds one char field 
 * '*' indicates a live cell
 * ' ' indicates a dead cell
 */

#ifndef _Cell_
#define _Cell_
class cell {
public:
  char text;
  cell(char t);
};
#endif

/*
 * Canvas holds the previous generation and new generation as a 2D array
 *
 * next_gen generates method the next generation based on 4 rules
 *  1.Any live cell with fewer than two live neighbours dies, as if by underpopulation.
 *  2.Any live cell with two or three live neighbours lives on to the next generation.
 *  3.Any live cell with more than three live neighbours dies, as if by overpopulation.
 *  4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 *
 *  render_cells method renders the canvas
 *	is_alive checks returns true if the current cell is alive and false otherwise
 */
#ifndef _Canvas_
#define _Canvas_
class canvas {
public:
  std::vector<std::vector<cell>> rows;
  std::vector<std::vector<cell>> next_gen_rows;

  canvas(int row_count, int col_count);

  bool is_alive(int row, int col);

  void next_gen();

  void render_cells();
};
#endif
