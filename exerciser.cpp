#include "exerciser.h"

void exercise(connection * C) {
  cout << "35 to 40 min" << endl;
  query1(C, 1, 35, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  cout << "2+ blocks" << endl;
  query1(C, 0, 35, 40, 0, 0, 0, 0, 5, 10, 0, 0, 0, 0, 0, 0, 1, 2, 10);
  cout << "10+ rebounds" << endl;
  query1(C, 0, 0, 0, 0, 10, 30, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0, 3, 5);
  cout << "10+ points & 10+ rebounds" << endl;
  query1(C, 0, 0, 0, 1, 10, 30, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0, 3, 5);
  cout << "10+ points & 5+ assists" << endl;
  query1(C, 0, 0, 0, 1, 10, 30, 0, 10, 30, 1, 5, 20, 0, 0, 0, 0, 3, 5);
  cout << "2 2 2 1 1" << endl;
  query1(C, 0, 0, 0, 1, 2, 40, 1, 2, 30, 1, 2, 20, 1, 1, 10, 1, 1, 10);
  cout << "Red" << endl;
  query2(C, "Red");
  cout << "Black" << endl;
  query2(C, "Black");
  cout << "DarkBlue" << endl;
  query2(C, "DarkBlue");
  cout << "Duke" << endl;
  query3(C, "Duke");
  cout << "UNC" << endl;
  query3(C, "UNC");
  cout << "NCSU" << endl;
  query3(C, "NCSU");
  cout << "NC DarkBlue" << endl;
  query4(C, "NC", "DarkBlue");
  cout << "GA Green" << endl;
  query4(C, "GA", "Green");
  cout << "NY Red" << endl;
  query4(C, "NY", "Red");
  cout << "12+ wins" << endl;
  query5(C, 12);
  cout << "10+ wins" << endl;
  query5(C, 10);
}
