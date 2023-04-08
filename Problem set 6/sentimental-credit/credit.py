from cs50 import get_int

def main():
    card = get_int("Number: ")

    if valid_card(card):
        card_company(card)
    else:
        print("INVALID")

def valid_card(num):
    sum = 0
    for i, c in enumerate(reversed(str(num))):
        if i % 2 == 0:
            sum += int(c)
        else:
            for j in str(int(c) * 2):
                sum += int(j)
    if sum % 10 == 0:
        return True
    else:
        return False
def card_company(card):
    num = int(str(card)[0:2])
    if (num == 34 or num == 37) and len(str(card)) == 15:
        print("AMEX")
    elif num > 50 and num < 56 and len(str(card)) == 16:
        print("MASTERCARD")
    elif num >= 40 and num < 50 and (len(str(card)) == 13 or len(str(card)) == 16):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()