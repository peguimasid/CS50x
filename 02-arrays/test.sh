gcc substitution.c -o substitution

# i dont want to get user input so everything user need to pass it will
# be in command line

# Validate:
# 1. Contains exactly 26 chars -> DONE
# 2. Contains only alphabetical chars -> DONE
# 3. Contains each letter exacly once ->


./substitution # "Usage: ./substitution <key> <plaintext>"
./substitution YUIOLKP "Hello!"  # "Key must contain 26 characters."
./substitution YTNSHKVEFXRBAUQZCLWDMIPGJ2 "Hello!" # "Key must only contain alphabetic characters."
./substitution YTNSHKVEYXRBAUQZCLWDMIPGJO "Hello!" # "Each char must appear just once"
./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO "Hello!" # "ciphertext: Ehbbq!"

rm substitution
