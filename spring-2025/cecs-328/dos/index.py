import ast
from pathlib import Path


def dos(k: int, arr: list[int]) -> int:
    arr.sort()
    return arr[k - 1]


def main():

    folder = Path('tests')

    for obj in sorted(folder.iterdir()):
        if not obj.is_file():
            continue

        # if obj.name == '8.txt' or obj.name == '9.txt' or obj.name == '10.txt':
        #     continue

        with obj.open('r') as file:
            text = file.read()
            text = text.replace('{', '[').replace('}', ']')
            k, arr = ast.literal_eval(text)

            print(f'File {obj.name}: {dos(k, arr)}')


main()
