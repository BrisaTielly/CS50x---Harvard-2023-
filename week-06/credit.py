import sys
import math
def luhn_reversals(num):
    n = str(num)[::-1]
    values = str()
    for odd in n[1::2]:
        values += str(int(odd)*2)
    for even in n[::2]:
        values += even
    sum = 0
    for value in values:
        sum += int(value)
    return sum
card_num = int(input("Enter card number: "))
luhn_result = luhn_reversals(card_num)
card_num_lenght = len(str(card_num))
if card_num_lenght not in range(13, 17) or (luhn_result % 10) != 0:
    print("INVALID")
    sys.exit()
first_two = int(str(card_num)[:2])
if first_two == 34 or first_two == 37:
    print("AMEX")
elif first_two in range(50, 56):
    print("MASTERCARD")
elif (math.floor(first_two / 10)) == 4:
    print("VISA")
else:
    print("INVALID")
