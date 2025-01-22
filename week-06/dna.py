import csv
import sys
def main():
    if len(sys.argv) != 3:
        sys.exit("Please input correct arguments as: file.csv file.txt")
    dataset = str()
    csv_db = []
    with open(sys.argv[1]) as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            if len(row) == 4:
                dataset = "small"
                csv_db.append({"name": row["name"], "AGATC": row["AGATC"], "AATG": row["AATG"], "TATC": row["TATC"]})
            else:
                dataset = "large"
                csv_db.append({"name": row["name"], "AGATC": row["AGATC"], "TTTTTTCT": row["TTTTTTCT"], "AATG": row["AATG"],
                               "TCTAG": row["TCTAG"], "GATA": row["GATA"], "TATC": row["TATC"], "GAAA": row["GAAA"], "TCTG": row["TCTG"]})
    dna_sequence = str()
    with open(sys.argv[2]) as txt_file:
        dna_sequence = txt_file.read()
    if dataset == "small":
        dna_combo = "{n1}{n2}{n3}".format(
            n1=longest_match(dna_sequence, "AGATC"),
            n2=longest_match(dna_sequence, "AATG"),
            n3=longest_match(dna_sequence, "TATC"))
    else:
        dna_combo = "{n1}{n2}{n3}{n4}{n5}{n6}{n7}{n8}".format(
            n1=longest_match(dna_sequence, "AGATC"),
            n2=longest_match(dna_sequence, "TTTTTTCT"),
            n3=longest_match(dna_sequence, "AATG"),
            n4=longest_match(dna_sequence, "TCTAG"),
            n5=longest_match(dna_sequence, "GATA"),
            n6=longest_match(dna_sequence, "TATC"),
            n7=longest_match(dna_sequence, "GAAA"),
            n8=longest_match(dna_sequence, "TCTG"))
    output_text = "No match"
    for entry in csv_db:
        if len(entry) == 4:
            current_dna_combo = "{s1}{s2}{s3}".format(s1=entry["AGATC"], s2=entry["AATG"], s3=entry["TATC"])
        else:
            current_dna_combo = "{s1}{s2}{s3}{s4}{s5}{s6}{s7}{s8}".format(
                s1=entry["AGATC"],
                s2=entry["TTTTTTCT"],
                s3=entry["AATG"],
                s4=entry["TCTAG"],
                s5=entry["GATA"],
                s6=entry["TATC"],
                s7=entry["GAAA"],
                s8=entry["TCTG"])
        if dna_combo == current_dna_combo:
            output_text = entry["name"]
            break
    print(output_text)
    return
def longest_match(sequence, subsequence):
