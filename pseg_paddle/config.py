import os
import logging

ROOT = os.path.dirname((os.path.abspath(__file__)))

profile = os.environ.get("PROFILE", "develop")


# logging
name = os.path.basename(ROOT).split(".")[0]
logger = logging.getLogger(name)
log_file_path = os.path.join(ROOT, "logs", name + ".log")

if profile == "develop":
    log_level = logging.DEBUG
else:
    log_level = logging.INFO


logger.setLevel(log_level)


ch = logging.StreamHandler()
ch.setLevel(log_level)
ch_format = logging.Formatter('%(name)s - %(levelname)s - %(message)s')
ch.setFormatter(ch_format)

# store errors
fh = logging.FileHandler(log_file_path)
fh.setLevel(logging.ERROR)
fh_format = logging.Formatter(
    '%(asctime)s - %(name)s - %(levelname)s - %(message)s')
fh.setFormatter(fh_format)

logger.addHandler(ch)
logger.addHandler(fh)

if __name__ == '__main__':
    print(ROOT)
