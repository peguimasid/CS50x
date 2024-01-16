from sys import argv


def main():
    credit_card_number = argv[1]

    first = []
    second = []

    for index, char in enumerate(credit_card_number[::-1]):
        if index % 2 != 0:
            for char in str(int(char) * 2):
                first.append(int(char))
        else:
            second.append(int(char))

    digits_sum = sum(first) + sum(second)

    if digits_sum % 10 != 0:
        print("INVALID")
        return

    start = f"{credit_card_number[0]}{credit_card_number[1]}"

    if start[0] == "4":
        print("VISA")
        return

    if start in ["34", "37"]:
        print("AMEX")
        return

    if start in ["51", "52", "53", "54", "55"]:
        print("MASTERCARD")


main()
