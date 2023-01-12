cd depinstall
winget install --id=Python.Python.3.10  -e
python get-pip.py
python -m pip install --upgrade pip
pip install numpy
pip install opencv-python
pip install pyautogui
python -m pip install --upgrade Pillow