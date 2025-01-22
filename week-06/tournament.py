import csv
import sys
import random
N = 95000
def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")
    teams = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            row["rating"] = int(row["rating"])
            teams.append(row)
    counts = {}
    for instance in range(0, N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")
def simulate_game(team1, team2):
    winners = []
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners
def simulate_tournament(teams):
CONTENTS OF ANSWERS.TXT
Times:
10 simulations: 0m0.029s
100 simulations: 0m0.033s
1000 simulations: 0m0.040s
10000 simulations: 0m0.125s
100000 simulations: 0m0.924s
1000000 simulations: 0m8.084s
Questions:
Which predictions, if any, proved incorrect as you increased the number of simulations?:
In "N less than 100" simulations, middle ranked countires (Canada, Sweeden, Norway, Netherlands etc.) were getting large percentages and bottom ranked countries were not showing at all.
At N 1000 predictions stabilized enough to have presentable results.
Suppose you're charged a fee for each second of compute time your program uses.
After how many simulations would you call the predictions "good enough"?:
Since in most cases N of 1000 gets processed under half a second with similar probability ranks to 10000 which mostly gets over one second or running time, that would be a "two instances per fee payed" and viable option.
