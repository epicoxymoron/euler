
def parse_names(fname):
    with open(fname, 'r') as f:
        lines = []
        for line in f:
            lines = lines + line[1:-1].split('","')
    return lines

def name_points(name):
    val = 0
    for c in name:
        val += ord(c) - 64
    return val

if __name__ == '__main__':
    names = sorted(parse_names('names.txt'))
    pos = 1
    score = 0
    for name in names:
        score += (name_points(name) * pos)
        pos += 1
    print(score)

