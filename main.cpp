#include <fstream>
#include <iostream>
#include <pqxx/pqxx>

#include "exerciser.h"

using namespace std;
using namespace pqxx;

void createTables(connection * C) {
  string drop_sql = "DROP TABLE IF EXISTS PLAYER, TEAM, STATE, COLOR;";

  string player_sql = "CREATE TABLE PLAYER("
                      "PLAYER_ID SERIAL PRIMARY KEY NOT NULL,"
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

  string team_sql = "CREATE TABLE TEAM("
                    "TEAM_ID SERIAL PRIMARY KEY NOT NULL,"
                    "NAME VARCHAR(100) NOT NULL,"
                    "STATE_ID INT NOT NULL,"
                    "COLOR_ID INT NOT NULL,"
                    "WINS INT NOT NULL,"
                    "LOSSES INT NOT NULL);";

  string state_sql = "CREATE TABLE STATE("
                     "STATE_ID SERIAL PRIMARY KEY NOT NULL,"
                     "NAME VARCHAR(100) NOT NULL);";

  string color_sql = "CREATE TABLE COLOR("
                     "COLOR_ID SERIAL PRIMARY KEY NOT NULL,"
                     "NAME VARCHAR(100) NOT NULL);";

  //create a transactional object
  work W(*C);

  //execute SQL query
  W.exec(drop_sql);
  W.exec(player_sql);
  W.exec(team_sql);
  W.exec(state_sql);
  W.exec(color_sql);

  W.commit();
}

void initPlayer(connection * C) {
  int player_id, team_id, uniform_num, mpg, ppg, rpg, apg;
  string first_name, last_name;
  double spg, bpg;
  string line;
  ifstream ifs;
  ifs.open("player.txt", ifstream::in);
  while (getline(ifs, line)) {
    stringstream buffer;
    buffer << line;
    buffer >> player_id >> team_id >> uniform_num >> first_name >> last_name >> mpg >>
        ppg >> rpg >> apg >> spg >> bpg;
    add_player(
        C, team_id, uniform_num, first_name, last_name, mpg, ppg, rpg, apg, spg, bpg);
  }
  ifs.close();
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
    initPlayer(C);
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
