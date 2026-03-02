# L = Σ* "carlos" Σ* "aguilera" Σ*
# Accept if the string contains "carlos" and then later "aguilera"

# Tools used:
# - VS Code

# State meanings:
# 0 = haven't found "carlos" yet
# 1 = found "carlos", now looking for "aguilera"
# 2 = found both (accepting state)

state = 0
buffer = ""

print("Enter one character at a time. Press Enter with no input to finish.")
print(f"Current state: {state}")

while True:
    char = input("> ")

    if char == "":
        break

    if len(char) > 1:
        print("Please enter one character at a time.")
        continue

    buffer += char

    # Check state transitions based on current buffer
    if state == 0:
        if "carlos" in buffer:
            state = 1
    elif state == 1:
        if "aguilera" in buffer:
            state = 2

    print(f"Current state: {state}, buffer: {buffer}")

print()

if state == 2:
    print("Result: accept")
else:
    print("Result: reject")
