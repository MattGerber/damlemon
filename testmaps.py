import os
import subprocess
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
output = open(THIS_FOLDER + "/output.txt", "w+")
my_lemin = os.path.join(THIS_FOLDER, "lem-in")
for filename in os.listdir('/home/ben/Docs/personal/lemin/maps'):
    my_file = os.path.join(THIS_FOLDER, "maps/" + filename)
    cmd = my_lemin + ' < ' + my_file
    so = os.popen(cmd).read()
    output.write(filename)
    output.write("\n")
    output.write(so)
    output.write("\n")
    output.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    output.write("\n")