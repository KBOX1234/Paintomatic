import numpy as np
import cv2
import pyautogui
import shutil
import os
import tkinter as tk
from tkinter import filedialog

root = tk.Tk()
root.withdraw()

user = os.getlogin()

files = filedialog.askopenfilenames()
str = ''.join(files)
str.replace("(", "")
str.replace(")", "")
str.replace("\'", "")

image = pyautogui.screenshot()

image = cv2.cvtColor(np.array(image),cv2.COLOR_RGB2BGR)

cv2.imwrite(str, image)