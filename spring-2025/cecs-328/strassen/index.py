import ast
import numpy as np
from pathlib import Path


def brute_force_dot_product_sum(a: list[list[int]], b: list[list[int]]):
    result = 0

    for curr_a_row in range(len(a)):
        for curr_b_row in range(len(b)):
            for curr_a_col in range(len(a[0])):
                result += a[curr_a_row][curr_a_col] * b[curr_a_col][curr_b_row]

    print(result)


def main():
    path = Path('tests')

    for folder in sorted(path.iterdir()):
        if folder.is_file():
            continue

        # if folder.name != '0':
        #     continue

        matricies = []

        for file in sorted(folder.iterdir()):
            if not file.is_file():
                continue

            with file.open('r') as f:
                print(f'Reading file: {f.name}')
                matrix = f.read()
                matrix = matrix.replace("{", "[").replace("}", "]")
                matrix = ast.literal_eval(matrix)

                matricies.append(matrix)

        brute_force_dot_product_sum(*matricies)


main()
