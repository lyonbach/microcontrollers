import sys
import os

source_file_path = sys.argv[1]

with open(source_file_path, "r") as sf:
    data_as_list = sf.readlines()

target_file = open(os.path.basename(source_file_path), "w")

target_file.writelines(data_as_list)
print("file has successfully copied...")
