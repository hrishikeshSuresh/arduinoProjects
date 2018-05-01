import serial 
serial = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
f = open("output.json", "w")
while True:
  data = serial.read()
  print(strftime("{%Y-%m-%d,%H:%M:%S,"))
  print data
  print("}\n")
  f.write(data)
  f.flush()
f.close()
