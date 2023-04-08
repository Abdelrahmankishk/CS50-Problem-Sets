# TODO
letter=0
word=1
sentence=0

text = input("Text: ")

text_lenght = len(text)

for i in range(text_lenght):
    if(text[i].isalpha()):
        letter += 1
    if(text[i].isspace()):
        word += 1
    if(text[i] == '.' or text[i] == '?' or text[i] == '!'):
        sentence += 1

calc = (0.0588 * letter/word*100) - (0.296 * sentence/word*100) - 15.8

a7a = round(calc)

if a7a < 1:
    print("Before Grade 1")
elif a7a >= 16:
    print("Grade 16+")
else:
    print(f"Grade {a7a}")
