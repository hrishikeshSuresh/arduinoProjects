#Made by Master Hrishikesh ,the handsome devil of PES
from collections import deque
import numpy as np
import argparse
import imutils
import cv2
import serial
import time
x=0 
y=0
r=0
ser = serial.Serial('/dev/ttyACM0', 9600)

# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
#ap.add_argument("-v", "--video",help="path to the (optional) video file")
ap.add_argument("-b", "--buffer", type=int, default=64,help="max buffer size")
args = vars(ap.parse_args())

greenLower = (5,100,100)
greenUpper = (25,127,153)
pts = deque(maxlen=args["buffer"])

camera = cv2.VideoCapture(1)
#ret, frame = camera.read()

def ball_track():
    # grab the current frame
	ret, frame = camera.read()
	cv2.circle(frame,(325,215), 2, (0,255,0), -1)
	# resize the frame, blur it, and convert it to the HSV
	# color space
	frame = imutils.resize(frame,width=500)
	blurred = cv2.GaussianBlur(frame, (11, 11), 0)
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

	# construct a mask for the color "green", then perform
	# a series of dilations and erosions to remove any small
	# blobs left in the mask

	mask = cv2.inRange(hsv, greenLower, greenUpper)
	cv2.imshow("mask",mask)
	mask = cv2.erode(mask, None, iterations=2)
	mask = cv2.dilate(mask, None, iterations=2)
        cv2.imshow('Original',frame)

	# find contours in the mask and initialize the current
	# (x, y) center of the ball
	cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)[-2]
	center = None

	# only proceed if at least one contour was found
	if len(cnts) > 0:
		# find the largest contour in the mask, then use
		# it to compute the minimum enclosing circle and
		# centroid
		c = max(cnts, key=cv2.contourArea)
		((x1, y1), radius) = cv2.minEnclosingCircle(c)
		M = cv2.moments(c)
		center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

		# only proceed if the radius meets a minimum size
		if radius > 0:
			# draw the circle and centroid on the frame,
			# then update the list of tracked points
			cv2.circle(frame, (int(x1), int(y1)), int(radius),(0, 255, 255), 2)
			cv2.circle(frame, center, 5, (0, 0, 255), -1)
			global x
			x=int(x1)
			global y
			y=int(y1)
			global r
			r=int(radius)
			print x,y,r
			
		    
      # cv2.imshow("frame",frame)
        
	#return(x,y,r)







#values
x1 = 128
x2 = 374
x3 = 256
rmin = 15
rmax = 130

#L = ball_track()

#while True :

   #cv2.imshow("Frame",frame)
''' if(r<rmax):
      while(r!=rmax):
         ser.write("F")
         ball_track()
      ser.write("S")

   elif(x<x1):
      while(x!=x1):
         ser.write("R")
         ball_track()
      ser.write("S") 

   elif(x>x2):
      while(x!=x1):
         ser.write("L")
         ball_track()
      ser.write("S")

   else:
       ser.write("S")'''

while True:
    #ser.write("start")
    ball_track()
    key=cv2.waitKey(1) & 0xFF
    if key==ord('q'):
        break

    elif(r>32):
            ser.write("S")
           


    if(x<x1):
      #while(x!=x1):
         ser.write("R")
         #ball_track()
      #ser.write("S") 

    if(x>x2):
      #while(x!=x1):
         ser.write("L")
         #ball_track()
      #ser.write("S")



    if(r<rmax):
      #while(r!=rmax):
         ser.write("F")
         #ball_track()
      #ser.write("S")



ser.close()
camera.release()
cv2.destroyAllWindows()



