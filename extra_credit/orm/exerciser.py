import os
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "orm.settings")

import django
django.setup()

import manage
from query import query1, query2, query3, query4, query5
from acc.models import Player, Team, State, Color

def addPlayer():
    data = open('data/player.txt')
    for line in data:
        player_id, team_id, uniform_num, first_name, last_name, mpg, ppg, rpg, apg, spg, bpg = line.split(' ')
        Player.objects.create(team_id=Team.objects.get(team_id=team_id), uniform_num=uniform_num, first_name=first_name,last_name=last_name, mpg=mpg, ppg=ppg, rpg=rpg, apg=apg, spg=spg, bpg=bpg)
    data.close()
    return

def addTeam():
    data = open('data/team.txt')
    for line in data:
        team_id, name, state_id, color_id, wins, losses = line.split(' ')
        Team.objects.create(name=name, state_id=State.objects.get(state_id=state_id), color_id=Color.objects.get(color_id=color_id), wins=wins, losses=losses)
    data.close()
    return

def addState():
    data = open('data/state.txt')
    for line in data:
        state_id, name = line.strip("\n").split(' ')
        State.objects.create(name=name)
    data.close()
    return
    
def addColor():
    data = open('data/color.txt')
    for line in data:
        color_id, name = line.strip("\n").split(' ')
        Color.objects.create(name=name)
    data.close()
    return

if __name__ == "__main__":
    addState()
    addColor()
    addTeam()
    addPlayer()
    
    print('35 to 40')
    query1(1, 35, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    print()
    print('2+ blocks')
    query1(0, 35, 40, 0, 0, 0, 0, 5, 10, 0, 0, 0, 0, 0, 0, 1, 2, 10)
    print()
    print('10+ rebounds')
    query1(0, 0, 0, 0, 10, 30, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0, 3, 5)
    print()
    print('10+ points & 10+ rebounds')
    query1(0, 0, 0, 1, 10, 30, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0, 3, 5)
    print()
    print('10+ points & 5+ assists')
    query1(0, 0, 0, 1, 10, 30, 0, 10, 30, 1, 5, 20, 0, 0, 0, 0, 3, 5)
    print()
    print('2 2 2 1 1')
    query1(0, 0, 0, 1, 2, 40, 1, 2, 30, 1, 2, 20, 1, 1, 10, 1, 1, 10)
    print()
    print('Red')
    query2("Red")
    print()
    print("Black")
    query2("Black")
    print()
    print("DarkBlue")
    query2("DarkBlue")
    print()
    print("Duke")
    query3("Duke")
    print()
    print("UNC")
    query3("UNC")
    print()
    print("NCSU")
    query3("NCSU")
    print()
    print("NC DarkBlue")
    query4("NC", "DarkBlue")
    print()
    print("GA Green")
    query4("GA", "Green")
    print()
    print("GA Gold")
    query4("GA", "Gold")
    print()
    print("VA Green")
    query4("VA", "Green")
    print()
    print("12+ wins")
    query5(12)
    print()
    print("10+ wins")
    query5(10);
        
