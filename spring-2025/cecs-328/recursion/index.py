import math
import ast
from pathlib import Path


def find_distance_between_closest_points(points: list[tuple]) -> float:
    if len(points) < 2:
        raise Exception()

    smallest_distance = math.dist(points[0], points[1])

    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            distance = math.dist(points[i], points[j])

            if distance < smallest_distance:
                smallest_distance = distance

    return smallest_distance


def main():
    folder_path = Path('tests')

    for file in sorted(folder_path.iterdir()):
        if not file.is_file:
            continue

        with file.open('r') as f:
            print(f'Reading file: {file.name}')
            points = f.read()
            points = points.replace("{", "[").replace("}", "]")
            points = ast.literal_eval(points)

            distance = find_distance_between_closest_points(points)
            print(f'Smallest Distance: {round(distance, 3)}')


main()
