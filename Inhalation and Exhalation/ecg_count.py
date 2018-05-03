import serial
import time

serial = serial.Serial("/dev/ttyACM0", 115200, timeout=1)
f = open("data_heartbeat_ecg.sql", "w")
#f = open("update.js","w")
f.write("use ccbd\n")
i = 1
while True:
  data = str (serial.readline())
  data = data.replace("b\'","")
  data = data.replace("B","")
  #data = data.replace(",","")
  data = data.replace("r","")
  data = data.replace("n","")
  data = data.replace("\\","")
  data = data.replace("\'","")
  data_list = data.split(",")
  if len(data_list) == 3:
    #f.write("db.heart_beat.insert({\'Time\':"+time.strftime("%T"))
    #f.write(",")
    #print(data)
    #print(data_list)
    bpm = data_list[2]
    bpm = int(bpm)//3 + 15
    #f.write(str(bpm))
    f.write("db.inhale_exhale.update({\"_id\":\""+time.strftime("%T")+"\"},{$set:{\"bpm\":"+str(bpm)+"}},false,true)\n");
    i = i + 1
    #f.write("\'bpm\':");
    #f.write("})\n")
  f.flush()

f.close()
