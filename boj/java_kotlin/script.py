import os
import shutil

for item in os.scandir("."):
    if item.is_dir():
        name = item.name

        try:
            os.scandir("../" + name)
        except:
            os.mkdir("../" + name)

        for src in os.scandir("./" + name):
            shutil.move("./" + name + "/" + src.name, "../" + name)
