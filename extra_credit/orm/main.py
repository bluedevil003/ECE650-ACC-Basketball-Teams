import manage
import query
from acc.models import Player, Team, State, Color

def addPlayer():
    data = open('data/state.txt')
    for line in data:
        player_id, team_id, uniform_num, first_name, last_name, mpg, ppg, rpg, apg, spg, bpg = line.split(' ')
        Color.objects.create(team_id=Team.objects.get(team_id=team_id), uniform_num=uniform_num, first_name=first_name,last_name=last_name, mpg=mpg, ppg=ppg, rpg=rpg, apg=apg, spg=spg, bpg=bpg)
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
        state_id, name = line.split(' ')
        State.objects.create(name=name)
    data.close()
    return
    
def addColor():
    data = open('data/color.txt')
    for line in data:
        color_id, name = line.split(' ')
        Color.objects.create(name=name)
    data.close()
    return

def main():
    addState()
    addColor()
    addTeam()
    addPlayer()

if __name__ == "__main__":
    main()
