# Title: Smallest multiple
#
# Problem #: 22
#
# Description: Using names.txt (right click and 'Save Link/Target As...'), a 
# 46K text file containing over five-thousand first names, begin by sorting 
# it into alphabetical order. Then working out the alphabetical value for 
# each name, multiply this value by its alphabetical position in the list 
# to obtain a name score.
# 
# For example, when the list is sorted into alphabetical order, COLIN, 
# which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the 
# list. So, COLIN would obtain a score of 938  53 = 49714.

# What is the total of all the name scores in the file?
#
# Author: epicoxymoron
# Language: Python

def parse_names(fname):
    """Reads the file and gets a list of names"""
    with open(fname, 'r') as f:
        lines = []
        for line in f:
            lines = lines + line[1:-1].split('","')
    return lines

def name_points(name):
    """Gets the base points for a single name"""
    val = 0
    for c in name:
        val += ord(c) - 64
    return val

def score_file(fname):
    """Gets the score for the full file"""
    names = sorted(parse_names(fname))
    pos = 1
    score = 0
    for name in names:
        score += (name_points(name) * pos)
        pos += 1
    return score

if __name__ == '__main__':
    print(score_file('names.txt'))
