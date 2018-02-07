import cv2
import numpy as np
cap=cv2.VideoCapture(0)          #initialize camera
while(1):                     
  ret,img=cap.read()   #read from camera and store it in variable img
  cv2.imshow('Voila!',img)
  cv2.imwrite('voila.jpg',img)  #storing it
  cv2.waitKey(0)
  break;
cap.release()    #release from cameraq
cv2.destroyAllWindows()
