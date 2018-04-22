import serial #Serial imported for Serial communication
import time #Required to use delay functions
import pyautogui

ArduinoSerial = serial.Serial('/dev/ttyACM0',9600) #Create Serial port object called arduinoSerialData
time.sleep(1) #wait for 2 seconds for the communication to get established
x = 100
y = 200
pyautogui.moveTo(x,y,1);
while 1:
    incoming = str (ArduinoSerial.readline()) #read the serial data and print it as line
    print(incoming)
    
    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in incoming:
        pyautogui.hotkey('ctrl', 'left')  
        pyautogui.hotkey('ctrl', 'pgup')

    if 'Forward' in incoming:
        pyautogui.hotkey('ctrl', 'right') 
        pyautogui.hotkey('ctrl', 'pgdn') 

    if 'Vup' in incoming:
        pyautogui.hotkey('ctrl', 'up')
        pyautogui.hotkey('up')

    if 'Vdown' in incoming:
        pyautogui.hotkey('ctrl', 'down')
        pyautogui.hotkey('down')

    if 'MouseUp' in incoming:
        y = y + 10
        pyautogui.moveTo(x,y,0.5)
    
    if 'MouseDown' in incoming:
        y = y - 10
        pyautogui.moveTo(x,y,0.5)

    if 'LeftClick' in incoming:
        pyautogui.click() 	
    
    if 'MoveLeft' in incoming:
        x = x - 10
        pyautogui.moveTo(x,y,0.5)

    if 'RightClick' in incoming:
        pyautogui.click(button="right")

    if 'MoveRight' in incoming:
        x = x + 10
        pyautogui.moveTo(x,y,0.5)

    incoming = "";
