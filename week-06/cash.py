import cs50
while True:
    try:
        change = cs50.get_float("Change owed: ")
        if change > 0:
            break
    except:
        print("Enter number greater than 0.")
cents = round(change * 100)
coins_count = 0
while cents > 0:
    if cents >= 25:
        coins_count += 1
        cents -= 25
    elif cents >= 10:
        coins_count += 1
        cents -= 10
    elif cents >= 5:
        coins_count += 1
        cents -= 5
    elif cents >= 1:
        coins_count += 1
        cents -= 1
print(coins_count)
