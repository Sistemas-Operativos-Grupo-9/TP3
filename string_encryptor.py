#!/usr/bin/env python3

import re
from sys import argv

def replace_escaped(s, m) -> str:
    for l, ch in m.items():
        s = s.replace('\\'+l, ch)
    return s


def parse_c_string(s: str) -> str:
    return replace_escaped(s, {
        'n': '\n',
        '\\': '\\',
        'b': '\b',
        't': '\t',
    }) + '\0'


offset = 0x21
def encrypt_string(s: str) -> str:
    return ''.join(map(lambda v:"\\x{:x}".format((v+offset) % 256), parse_c_string(s).encode()))


input_file = argv[1]
with open(input_file, 'r') as file:
    content = file.read()

modified = re.sub(re.compile(r'ENCRYPTED\("(.*?)"\)'),
                  lambda match: '"'+encrypt_string(match.group(1))+'"', content)

print(modified)
