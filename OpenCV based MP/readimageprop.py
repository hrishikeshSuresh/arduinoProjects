import cv2
import numpy as np
img=cv2.imread('img1.jpg')
px=img[100,100]  #read row and column
print(px)        #GBR values of px
px=[255,255,255] #reassinging GBR values
print(img.shape) #returns number of tuples,columns and channels
print(img.size)  #returns number of pixels
print(img.dtype) #datatype of image
cv2.imshow('Let us see',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
