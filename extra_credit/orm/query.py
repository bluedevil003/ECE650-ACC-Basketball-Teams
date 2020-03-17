import os
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "orm.settings")

import django
django.setup()

from acc.models import Player, Team, State, Color

def query1(use_mpg, min_mpg, max_mpg, use_ppg, min_ppg, max_ppg, use_rpg, min_rpg, max_rpg, use_apg, min_apg, max_apg, use_spg, min_spg, max_spg, use_bpg, min_bpg, max_bpg):
    R = Player.objects.all()
    if use_mpg:
        R = R.filter(mpg__lte = max_mpg, mpg__gte = min_mpg)
    if use_ppg:
        R = R.filter(ppg__lte = max_ppg, ppg__gte = min_ppg)
    if use_rpg:
        R = R.filter(rpg__lte = max_rpg, rpg__gte = min_rpg)
    if use_apg:
        R = R.filter(apg__lte = max_apg, apg__gte = min_apg)
    if use_spg:
        R = R.filter(spg__lte = max_spg, spg__gte = min_spg)
    if use_bpg:
        R = R.filter(bpg__lte = max_bpg, bpg__gte = min_bpg)
    print("PLAYER_ID TEAM_ID UNIFORM_NUM FIRST_NAME LAST_NAME MPG PPG RPG APG SPG BPG")
    for r in R:
        print(r.player_id, r.team_id.team_id, r.uniform_num, r.first_name, r.last_name, r.mpg, r.ppg, r.rpg, r.apg, r.spg, r.bpg)
    return


def query2(team_color):
    R = Team.objects.filter(color_id__name = team_color)
    print("NAME")
    for r in R:
        print(r.name)
    return

def query3(team_name):
    R = Player.objects.filter(team_id__name = team_name).order_by('-ppg')
    print("FIRST_NAME LAST_NAME")
    for r in R:
        print(r.first_name, r.last_name)
    return

def query4(team_state, team_color):
    R = Player.objects.filter(team_id__state_id__name = team_state, team_id__color_id__name = team_color).order_by('player_id')
    print("FIRST_NAME LAST_NAME UNIFORM_NUM")
    for r in R:
        print(r.first_name, r.last_name, r.uniform_num)
    return

def query5(num_wins):
    R = Player.objects.filter(team_id__wins__gt = num_wins)
    print("FIRST_NAME LAST_NAME NAME WINS")
    for r in R:
        print(r.first_name, r.last_name, r.team_id.name, r.team_id.wins)
    return
