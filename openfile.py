import shutil
import os
import tkinter as tk
from tkinter import filedialog
from PIL import Image

root = tk.Tk()
root.withdraw()

user = os.getlogin()

files = filedialog.askopenfilenames()
str = ''.join(files)
str.replace("(", "")
str.replace(")", "")
str.replace("\'", "")
print("cpyed "+str+" to public pictures as pic.png")
shutil.copy(str, "C:\\Users\\Public\\Pictures\\pic.png")
basewidth = 800
img = Image.open('C:\\Users\\Public\\Pictures\\pic.png')
wpercent = (basewidth / float(img.size[0]))
hsize = int((float(img.size[1]) * float(wpercent)))
img = img.resize((basewidth, hsize), Image.ANTIALIAS)
img.save('C:\\Users\\Public\\Pictures\\pic.png')