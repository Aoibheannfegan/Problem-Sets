from cs50 import get_float

def main():
    change_owed = get_positive_float()
    calculate_float(change_owed)


def get_positive_float():
    while True:
        change_owed = get_float("Change owed: ")
        if change_owed > 0:
            break
    return change_owed

def calculate_float(n):
    change = n * 100
    coins = 0
    quarter = 25
    dime = 10
    nickel = 5
    cent = 1

    while change > 0:
        while change >= quarter:
            coins+=1
            change = change - quarter
        while change >= dime:
            coins+=1
            change = change - dime
        while change >= nickel:
            coins+=1
            change = change - nickel
        while change >= cent:
            coins+=1
            change = change - cent


    print(coins)

main()
