#include <iostream>
#include <pqxx/pqxx>

#include "exerciser.h"

using namespace std;
using namespace pqxx;

void dropTables(connection * C){

}

void createTables(connection * C){

}

void initPlayer(connection * C){

}

void initTeam(connection * C){

}

void initState(connection * C){

}

void initColor(connection * C){

}

int main (int argc, char *argv[]) 
{

  //Allocate & initialize a Postgres connection object
  connection *C;

  try{
    //Establish a connection to the database
    //Parameters: database name, user name, user password
    C = new connection("dbname=ACC_BBALL user=postgres password=passw0rd");
    if (C->is_open()) {
      cout << "Opened database successfully: " << C->dbname() << endl;
    } else {
      cout << "Can't open database" << endl;
      return 1;
    }
  } catch (const exception &e){
    cerr << e.what() << endl;
    return 1;
  }


  //TODO: create PLAYER, TEAM, STATE, and COLOR tables in the ACC_BBALL database
  //      load each table with rows from the provided source txt files
  try{

  } catch(const exception &e){
    cerr << e.what() << endl;
    return 1;
  }

  exercise(C);


  //Close database connection
  C->disconnect();

  return 0;
}


