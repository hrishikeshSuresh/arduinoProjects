import cv2
import numpy as np
img=cv2.imread('img1.jpg')     #read the file and store as matrix
cv2.imshow('ACSYN',img)        #display image in 'frame'
cv2.waitKey(0)                 #wait for any key to be pressed
cv2.destroyAllWindows()        #close all windows created
