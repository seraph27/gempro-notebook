import sys
import hashlib
from sys import argv

def remove_comments_from_line(line):
    return line.split('//')[0]

def remove_comments(template):
    return '\n'.join(remove_comments_from_line(line) for line in template.split('\n'))

def process(template):
    return template.split('// begin template //')[-1].split('// end template //')[0].rstrip().lstrip()

def hash(template):
    template = remove_comments(template).replace('\n', '').replace(' ', '').replace('\t', '')
    return hashlib.md5(template.encode()).hexdigest()[:6]

def generate(template):
    with open("/tmp/gempro-prepared-template.tex", "w") as f:
        f.write(
f"""
\\captionof{{listing}}{{{hash(template)} - {argv[1]}}}
\\begin{{minted}}{{cpp}}
{remove_comments(template)}
\\end{{minted}}
""")

if __name__ == "__main__":
    template = sys.stdin.read()
    generate(process(template))
