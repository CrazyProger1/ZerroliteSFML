import os
import sys

for file in os.listdir(os.path.split(sys.argv[0])[0]):
    os.rename(file, file.replace(sys.argv[1], ""))
