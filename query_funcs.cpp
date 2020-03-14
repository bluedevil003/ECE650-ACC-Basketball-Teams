#include "query_funcs.h"

void add_player(connection * C,
                int team_id,
                int jersey_num,
                string first_name,
                string last_name,
                int mpg,
                int ppg,
                int rpg,
                int apg,
                double spg,
                double bpg) {
  work W(*C);
  stringstream sql;
  sql << "INSERT INTO PLAYER "
         "(TEAM_ID,UNIFORM_NUM,FIRST_NAME,LAST_NAME,MPG,PPG,RPG,APG,SPG,"
         "BPG) VALUES ("
      << team_id << "," << jersey_num << ",'" << W.esc(first_name) << "','"
      << W.esc(last_name) << "'," << mpg << "," << ppg << "," << rpg << "," << apg << ","
      << spg << "," << bpg << ");";
  W.exec(sql.str());
  W.commit();
}

void add_team(connection * C,
              string name,
              int state_id,
              int color_id,
              int wins,
              int losses) {
  work W(*C);
  stringstream sql;
  sql << "INSERT INTO TEAM (NAME,STATE_ID,COLOR_ID,WINS,LOSSES) VALUES ('" << name << "',"
      << state_id << "," << color_id << "," << wins << "," << losses << ");";
  W.exec(sql.str());
  W.commit();
}

void add_state(connection * C, string name) {
  work W(*C);
  stringstream sql;
  sql << "INSERT INTO STATE (NAME) VALUES ('" << name << "');";
  W.exec(sql.str());
  W.commit();
}

void add_color(connection * C, string name) {
  work W(*C);
  stringstream sql;
  sql << "INSERT INTO COLOR (NAME) VALUES ('" << name << "');";
  W.exec(sql.str());
  W.commit();
}

void query1(connection * C,
            int use_mpg,
            int min_mpg,
            int max_mpg,
            int use_ppg,
            int min_ppg,
            int max_ppg,
            int use_rpg,
            int min_rpg,
            int max_rpg,
            int use_apg,
            int min_apg,
            int max_apg,
            int use_spg,
            double min_spg,
            double max_spg,
            int use_bpg,
            double min_bpg,
            double max_bpg) {
  int count = 0;
  stringstream sql;
  sql << "SELECT * FROM PLAYER";
  if (use_mpg) {
    sql << " WHERE (MPG BETWEEN " << min_mpg << " AND " << max_mpg << ")";
    count++;
  }
  if (use_ppg) {
    if (count == 0) {
      sql << " WHERE ";
    }
    else {
      sql << " AND ";
    }
    sql << "(PPG BETWEEN " << min_ppg << " AND " << max_ppg << ")";
    count++;
  }
  if (use_rpg) {
    if (count == 0) {
      sql << " WHERE ";
    }
    else {
      sql << " AND ";
    }
    sql << "(RPG BETWEEN " << min_rpg << " AND " << max_rpg << ")";
    count++;
  }
  if (use_apg) {
    if (count == 0) {
      sql << " WHERE ";
    }
    else {
      sql << " AND ";
    }
    sql << "(APG BETWEEN " << min_apg << " AND " << max_apg << ")";
    count++;
  }
  if (use_spg) {
    if (count == 0) {
      sql << " WHERE ";
    }
    else {
      sql << " AND ";
    }
    sql << "(SPG BETWEEN " << min_spg << " AND " << max_spg << ")";
    count++;
  }
  if (use_bpg) {
    if (count == 0) {
      sql << " WHERE ";
    }
    else {
      sql << " AND ";
    }
    sql << "(BPG BETWEEN " << min_bpg << " AND " << max_bpg << ")";
    count++;
  }
  sql << ";";

  //create a non-transactional object
  nontransaction N(*C);
  result R(N.exec(sql.str()));
  cout << "PLAYER_ID TEAM_ID UNIFORM_NUM FIRST_NAME LAST_NAME MPG PPG RPG APG SPG BPG"
       << endl;
  for (result::const_iterator it = R.begin(); it != R.end(); it++) {
    cout << it[0].as<int>() << " ";
    cout << it[1].as<int>() << " ";
    cout << it[2].as<int>() << " ";
    cout << it[3].as<string>() << " ";
    cout << it[4].as<string>() << " ";
    cout << it[5].as<int>() << " ";
    cout << it[6].as<int>() << " ";
    cout << it[7].as<int>() << " ";
    cout << it[8].as<int>() << " ";
    cout << it[9].as<double>() << " ";
    cout << it[10].as<double>() << endl;
  }
}

void query2(connection * C, string team_color) {
  stringstream sql;
  sql << "SELECT TEAM.NAME FROM TEAM, COLOR "
      << "WHERE TEAM.COLOR_ID=COLOR.COLOR_ID AND COLOR.NAME='" << team_color << "';";

  nontransaction N(*C);
  result R(N.exec(sql.str()));
  cout << "NAME" << endl;
  for (result::const_iterator it = R.begin(); it != R.end(); it++) {
    cout << it[0].as<string>() << endl;
  }
}

void query3(connection * C, string team_name) {
  stringstream sql;
  sql << "SELECT FIRST_NAME, LAST_NAME FROM PLAYER, TEAM "
      << "WHERE PLAYER.TEAM_ID=TEAM.TEAM_ID AND NAME='" << team_name << "' "
      << "ORDERED BY PPG DESC;";

  nontransaction N(*C);
  result R(N.exec(sql.str()));
  cout << "FIRST_NAME LAST_NAME" << endl;
  for (result::const_iterator it = R.begin(); it != R.end(); it++) {
    cout << it[0].as<string>() << " ";
    cout << it[1].as<string>() << endl;
  }
}

void query4(connection * C, string team_state, string team_color) {
  stringstream sql;
  sql << "SELECT FIRST_NAME, LAST_NAME, UNIFORM_NUM FROM PLAYER, TEAM, STATE, COLOR "
      << "WHERE PLAYER.TEAM_ID=TEAM.TEAM_ID AND TEAM.STATE_ID=STATE.STATE_ID "
      << "AND TEAM.COLOR_ID=COLOR.COLOR_ID AND "
      << "COLOR.NAME='" << team_color << "' AND STATE.NAME='" << team_state << "';";

  nontransaction N(*C);
  result R(N.exec(sql.str()));
  cout << "FIRST_NAME LAST_NAME UNIFORM_NUM" << endl;
  for (result::const_iterator it = R.begin(); it != R.end(); it++) {
    cout << it[0].as<string>() << " ";
    cout << it[1].as<string>() << " ";
    cout << it[2].as<int>() << endl;
  }
}

void query5(connection * C, int num_wins) {
  stringstream sql;
  sql << "SELECT FIRST_NAME, LAST_NAME, TEAM.NAME, WINS FROM PLAYER, TEAM "
      << "WHERE PLAYER.TEAM_ID=TEAM.TEAM_ID AND WINS>" << num_wins << ";";

  nontransaction N(*C);
  result R(N.exec(sql.str()));
  cout << "FIRST_NAME LAST_NAME TEAM_NAME WINS" << endl;
  for (result::const_iterator it = R.begin(); it != R.end(); it++) {
    cout << it[0].as<string>() << " ";
    cout << it[1].as<string>() << " ";
    cout << it[2].as<string>() << " ";
    cout << it[3].as<int>() << endl;
  }
}
