height = int(input("Height: "))

start_spaces = height - 1

for i in range(height):
    print(" " * start_spaces, end="")
    start_spaces -= 1
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1), end="")
    print()
