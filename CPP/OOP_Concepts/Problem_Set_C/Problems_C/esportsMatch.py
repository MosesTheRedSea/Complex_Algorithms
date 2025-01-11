def matchHistory(team1, team2):
    matchDict = {'Liquid': 4, 'The Guard': 6, 'Mang0':10000, 'Hbox': -1, 'Plup': 100, 'Leffen': 8,
                 'Fnatic': 3, 'Armada': 7, 'Paper Rex': 1000, 'DRX': 500, 'Optic': 300, 'OG': 1000, 'Alliance': 1}

    if team1 not in matchDict.keys() or team2 not in matchDict.keys():
        return None
    else:
        if matchDict[team1] > matchDict[team2]:
            return team1
        else:
            return team2
