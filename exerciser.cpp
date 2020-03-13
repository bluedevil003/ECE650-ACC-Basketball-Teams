#include "exerciser.h"

void exercise(connection * C) {
  query1(C, 1, 35, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  query1(C, 0, 35, 40, 0, 0, 0, 1, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  query1(C, 0, 35, 40, 0, 0, 0, 0, 5, 10, 0, 0, 0, 0, 0, 0, 1, 3, 5);
  query1(C, 0, 0, 0, 1, 10, 30, 1, 10, 30, 0, 0, 0, 0, 0, 0, 1, 3, 5);
  query2(C, "Red");
  query2(C, "Black");
  query3(C, "Duke");
  query3(C, "UNC");
  query3(C, "NCSU");
  query4(C, "NC", "DarkBlue");
  query4(C, "GA", "Green");
  query4(C, "NY", "Red");
  query5(C, 12);
  query5(C, 10);
}
