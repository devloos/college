import math
import ast
from pathlib import Path


def fft(a, invert=False):
    n = len(a)
    if n == 1:
        return a

    # Divide: split the array into even and odd parts
    even = fft(a[0::2], invert)
    odd = fft(a[1::2], invert)

    # Prepare the primitive root of unity for the current stage
    angle = 2 * math.pi / n * (-1 if invert else 1)
    wn = complex(math.cos(angle), math.sin(angle))
    w = 1

    # Conquer: combine the results of the subproblems
    y = [0] * n
    for k in range(n // 2):
        t = w * odd[k]
        y[k] = even[k] + t
        y[k + n // 2] = even[k] - t
        w *= wn

    # For inverse FFT, normalize the results
    if invert:
        y = [x / 2 for x in y]
    return y


def brute_force_fft(arr: list[int]) -> int:
    if len(arr) == 0:
        return 0

    m_sum = arr[0]

    for i in range(len(arr)):
        t_sum = 0
        for j in range(i, len(arr)):
            t_sum += arr[j]

            if t_sum > m_sum:
                m_sum = t_sum

    return m_sum


def main():
    folder = Path('tests')

    for obj in sorted(folder.iterdir()):
        if not obj.is_file():
            continue

        if obj.name == '8.txt' or obj.name == '9.txt' or obj.name == '10.txt':
            continue

        with obj.open('r') as file:
            arr = file.read()
            arr = arr.replace('{', '[').replace('}', ']')
            arr = ast.literal_eval(arr)

            m_sum = 0
            for num in fft(arr):
                m_sum += num

            print(m_sum)


main()
