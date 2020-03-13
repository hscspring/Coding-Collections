import os
import argparse
import json


def get_text(test_file: str, length: int) -> str:
    with open(test_file, "r") as f:
        text = f.read()
    return text[:length]


def main():
    """
    Example:  python run.py -f bench_text.txt -l 3000 -c 1 -s 127.0.0.1:12345
    """
    parser = argparse.ArgumentParser(
        description='Bench test.')
    parser.add_argument(
        '-f', dest='filepath', type=str, help='File dirname.')
    parser.add_argument(
        '-l', dest='length', type=int, help='Text length.')
    parser.add_argument(
        '-c', dest='concurrency', type=int, help='Request concurrency.')
    parser.add_argument(
        '-s', dest='server', type=str, help='GRPC server.')
    args = parser.parse_args()

    test_file = args.filepath
    length = args.length
    concurrency = args.concurrency
    server = args.server

    data = {"text": get_text(test_file, length)}
    test_data = json.dumps(data, ensure_ascii=False)

    outfile = "-".join(["Pseg",
                        "Length", str(length),
                        "Concurrency", str(concurrency)])
    title = "########## " + outfile + " ##########"

    os.system("echo '{}' >> {}".format(title, "pseg_stress_test.txt"))
    cmd = "ghz --config ./config.json -d '{}' -c {} {} >> {}".format(
        test_data, concurrency, server, "pseg_stress_test.txt")
    os.system(cmd)


if __name__ == '__main__':
    main()
