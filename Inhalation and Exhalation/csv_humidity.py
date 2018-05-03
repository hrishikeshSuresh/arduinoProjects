import serial
import time

serial = serial.Serial("/dev/ttyACM0", 115200, timeout=1)
f = open("humidity_csv.csv","a")

while True:
  data = str (serial.readline())
  f.write(time.strftime("%d/%m/%Y"))
  f.write(",")
  f.write(time.strftime("%T"))
  f.write(",")
  data = data.replace("b","")
  data = data.replace("  ",",")
  data = data.replace("\'","")
  f.write(data)
  f.write(",\n")
  f.flush()
f.close()
