
x = ['C', 'T', 'A', 'G', 'G', 'A', 'T', 'C']
y = ['T', 'G', 'C', 'C', 'A', 'T', 'G', 'C', 'T']


def lcs(i, j) -> int:
    global x, y
    if i == 0 or j == 0:
        return 1

    if x[i] == y[j]:
        return lcs(i - 1, j - 1) + 1

    return max(lcs(i - 1, j), lcs(i, j - 1))


def main():
    global x, y
    longest = lcs(len(x) - 1, len(y) - 1)

    print(f'Longest Common Sequence: {longest}')


main()
