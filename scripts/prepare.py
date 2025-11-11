import sys

def process(template):
    return template.split('// begin template //')[-1].split('// end template //')[0].rstrip().lstrip()

def generate(template):
    with open("/tmp/gempro-prepared-template.tex", "w") as f:
        f.write(f"\\begin{{minted}}{{cpp}}\n{template}\n\\end{{minted}}\n")

if __name__ == "__main__":
    template = sys.stdin.read()
    generate(process(template))
