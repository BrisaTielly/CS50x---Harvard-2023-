import re
def get_coleman_liau_index(avg_letters, avg_sentences):
    return round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)
sentence = input("Text: ").lower()
letters = len(re.findall(r"[a-z]", sentence))
words = len(sentence.split(" "))
sentences = len(re.split(r"[.!?]", sentence))-1
avg_letters = letters * 100 / words
avg_sentences = sentences * 100 / words
coleman_liau_score = get_coleman_liau_index(avg_letters, avg_sentences)
if (coleman_liau_score < 1):
    print("Before Grade 1")
elif (coleman_liau_score > 16):
    print("Grade 16+")
else:
    print(f"Grade {coleman_liau_score}")
