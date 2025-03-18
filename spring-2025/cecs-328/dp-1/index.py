from ast import literal_eval
from pathlib import Path


def knapsack(capacity, bricks):
    n = len(bricks)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        value, weight, _ = bricks[i - 1]
        for w in range(capacity + 1):
            if weight > w:
                dp[i][w] = dp[i - 1][w]  # Can't take the item
            else:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1]
                               [w - weight] + value)  # Take or skip

    # Backtrack to find selected items
    w = capacity
    selected = []
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:  # Item was taken
            selected.append(i)
            w -= bricks[i - 1][1]

    return dp[n][capacity], sorted(selected)


def main():
    folder = Path('tests')

    for obj in sorted(folder.iterdir()):
        if not obj.is_file():
            continue

        if obj.name == '10.txt':
            continue

        with obj.open('r') as file:
            raw = file.read()
            formatted = raw.replace('{', '[').replace('}', ']')
            capacity, bricks = literal_eval(formatted)

            max_profit, selected_items = knapsack(capacity, bricks)

            print(f"File: {file.name}")
            print(f"Maximum Profit: {max_profit}")


main()
