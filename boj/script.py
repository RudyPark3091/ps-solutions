import os
import shutil

lst = os.scandir(".")


for item in lst:
    if not item.is_dir() and item.name != "script.py":
        name = item.name
        dirname = name.split(".")[0]

        try:
            os.scandir("./" + dirname)
            shutil.move(item.name, "./" + dirname)
        except:
            os.mkdir(dirname)
            shutil.move(item.name, "./" + dirname)
