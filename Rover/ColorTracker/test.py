import cv2
import numpy as np
import cv2.cv as cv
import time
import serial
cap=cv2.VideoCapture(0)
ser = serial.Serial('/dev/ttyACM0',9600)
while(1):
  ret,frame=cap.read()
  hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
  lower_colour=np.array([0,144,215],dtype=np.uint8)
  upper_colour=np.array([34,255,255],dtype=np.uint8)
  mask=cv2.inRange(hsv,lower_colour,upper_colour)
  res=cv2.bitwise_and(frame,frame,mask=mask)
  kernel=np.ones((5,5),np.uint8)
  erosion=cv2.erode(mask,kernel,iterations=1)
  dilation=cv2.dilate(mask,kernel,iterations=1)
  opening=cv2.morphologyEx(mask,cv2.MORPH_OPEN,kernel)
  closing=cv2.morphologyEx(mask,cv2.MORPH_CLOSE,kernel)
  circles=cv2.HoughCircles   (closing,cv.CV_HOUGH_GRADIENT,2,120,param1=100,param2=55,minRadius=10,maxRadius=0)
  if circles is not None:
     for i in circles[0,:]:
        cv2.circle(frame,(int(round(i[0])),int(round(i[1]))),int(round(i[2])),cv2.circle(frame,(int(round(i[0])),int(round(i[1]))),1,(0,255,0),4))
  cv2.imshow('tracking',frame)
  cv2.imshow('Original',frame)
  cv2.imshow('Mask',mask)
  cv2.imshow('Result',res)
  k=cv2.waitKey(5) & 0xFF
  if k==27:
    break
  a=960
  b=100
  c=1000
  output="X{0:d}Y{1:d}Z{2:d}".format(a,b,c)
  ser.write(output)
  print(output)
cv2.destroyAllWindows()
cap.release()   
