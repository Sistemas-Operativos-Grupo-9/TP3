#!/usr/bin/env python3

import re
import hashlib
from sys import argv, stderr


def replace_escaped(s, m) -> str:
    for l, ch in m.items():
        s = s.replace('\\'+l, ch)
    return s


def parse_c_string(s: str, add_null=True) -> str:
    return replace_escaped(s, {
        'n': '\n',
        '\\': '\\',
        'b': '\b',
        't': '\t',
    }) + ('\0' if add_null else '')


offset = 0x21


def encrypt_string(s: str) -> str:
    return ''.join(map(lambda v: "\\x{:x}".format((v+offset) % 256), parse_c_string(s).encode()))


def md5(s: str) -> str:
    return hashlib.md5(parse_c_string(s, False).encode('utf-8')).hexdigest()


input_file = argv[1]
with open(input_file, 'r') as file:
    content = file.read()

def encrypt_match(match):
    strings = re.findall(r'\s*"(.*?)"\s*', match.group(1))
    return '"'+encrypt_string(''.join(strings))+'"'

content = re.sub(re.compile(r'ENCRYPTED\(\s*((?:".*?"\s*)+?)\)'),
                 encrypt_match, content)
content = re.sub(re.compile(r'MD5SUM\("(.*?)"\)'),
                 lambda match: '"' + md5(match.group(1)) + '"', content)

print(content)
