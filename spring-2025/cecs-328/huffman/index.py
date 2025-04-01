from queue import PriorityQueue


class Node:
    def __init__(self, char: str | None, freq: int):
        self.char = char
        self.freq = freq
        self.left: Node = None
        self.right: Node = None

    def __lt__(self, other):
        return self.freq < other.freq

    def __str__(self):
        return f"{self.char}: {self.freq}"


def calc_freq(text: str):
    frequencies = {}

    for c in text:
        if c in frequencies.keys():
            frequencies[c] += 1
        else:
            frequencies[c] = 1

    return frequencies


def build_huffman_tree(frequencies: dict[str, int]) -> Node:
    nodes = PriorityQueue()

    for pair in frequencies.items():
        char = pair[0]
        freq = pair[1]
        nodes.put(Node(char, freq))

    while nodes.qsize() != 1:
        left = nodes.get()
        right = nodes.get()

        freq = left.freq + right.freq
        parent = Node(None, freq)
        parent.left = left
        parent.right = right

        nodes.put(parent)

    return nodes.get()


def generate_huffman_codes(node: Node, current_code: str, codes: dict):
    if node is None:
        return

    if node.char is not None:
        codes[node.char] = current_code

    generate_huffman_codes(node.left, current_code + '0', codes)
    generate_huffman_codes(node.right, current_code + '1', codes)


def encode_text(text: str, codes: dict[str, str]) -> str:
    encoded_text = ''

    for c in text:
        encoded_text += codes[c]

    return encoded_text


def main():
    text = 'vuitfocmin'
    # text = 'aafljidgyo'

    frequencies = calc_freq(text)
    root = build_huffman_tree(frequencies)

    codes = {}
    generate_huffman_codes(root, '', codes)

    encoded_text = encode_text(text, codes)

    print(len(encoded_text))


main()
