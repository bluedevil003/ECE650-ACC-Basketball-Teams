#include <iostream>
#include <pqxx/pqxx>

#include "exerciser.h"

using namespace std;
using namespace pqxx;

void dropTables(connection * C) {
}

void createTables(connection * C) {
  string player_sql = "CREATE TABLE PLAYER("
                      "PLAYER_ID INT NOT NULL,"
                      "TEAM_ID INT NOT NULL,"
                      "UNIFORM_NUM INT NOT NULL,"
                      "FIRST_NAME VARCHAR(100) NOT NULL,"
                      "LAST_NAME VARCHAR(100) NOT NULL,"
                      "MPG INT NOT NULL,"
                      "PPG INT NOT NULL,"
                      "RPG INT NOT NULL,"
                      "APG INT NOT NULL,"
                      "SPG REAL NOT NULL,"
                      "BPG REAL NOT NULL);";

  //create a transactional object
  work W(*C);

  //execute SQL query
  W.exec(player_sql);

  W.commit();
}

void initPlayer(connection * C) {
}

void initTeam(connection * C) {
}

void initState(connection * C) {
}

void initColor(connection * C) {
}

int main(int argc, char * argv[]) {
  //Allocate & initialize a Postgres connection object
  connection * C;

  try {
    //Establish a connection to the database
    //Parameters: database name, user name, user password
    C = new connection("dbname=ACC_BBALL user=postgres password=passw0rd");
    if (C->is_open()) {
      cout << "Opened database successfully: " << C->dbname() << endl;
    }
    else {
      cout << "Can't open database" << endl;
      return 1;
    }
  }
  catch (const exception & e) {
    cerr << e.what() << endl;
    return 1;
  }

  //TODO: create PLAYER, TEAM, STATE, and COLOR tables in the ACC_BBALL database
  //      load each table with rows from the provided source txt files
  try {
    createTables(C);
  }
  catch (const exception & e) {
    cerr << e.what() << endl;
    return 1;
  }

  exercise(C);

  //Close database connection
  C->disconnect();

  return 0;
}
