# (L * 0.0588) - (S * 0.296) - 15.8
# L is the average number of letters per 100 words in the text: that is, the number of letters divided by the number of words, all multiplied by 100.
# S is the average number of sentences per 100 words in the text: that is, the number of sentences divided by the number of words, all multiplied by 100.
# You can consider any sequence of characters that ends with a . or a ! or a ? to be a sentence.

# Grade 1 - 16 - "Grade X"
# Grade < 1 - "Before Grade 1"
# Grade > 16 - "Grade 16+"


def count_letters(text: str) -> int:
    return len([c for c in text if c.isalpha()])


def count_words(text: str) -> int:
    return len([c for c in text if c.isspace()])


def count_sentences(text: str) -> int:
    return len([c for c in text if (c == "." or c == "?" or c == "!")])


text = "Would you like them here or there? I would not like them here or there. I would not like them anywhere."

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

L = letters / words * 100
S = sentences / words * 100

grade = (L * 0.0588) - (S * 0.296) - 15.8

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(grade)}")
