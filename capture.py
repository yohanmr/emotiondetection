import cv2
import classifier
import os
size = 4

# We load the xml file
classify = cv2.CascadeClassifier("C:\\Users\\ramakriy\\AppData\\Local\\Programs\\Python\\Python35\\Lib\\site-packages\\cv2\\data\\haarcascade_frontalface_alt.xml")

webcam = cv2.VideoCapture(0)

while True:
    (rval, im) = webcam.read()
    im=cv2.flip(im,1,0)
    mini = cv2.resize(im, (int(im.shape[1]/size), int(im.shape[0]/size)))
    faces = classify.detectMultiScale(mini)
    # Draw rectangles around each face
    for f in faces:
        (x, y, w, h) = [v * size for v in f]
        cv2.rectangle(im, (x,y), (x+w,y+h), (0,255,0), 4)
        sub_face = im[y:y+h, x:x+w]
        FaceFileName = "test.jpg" #Saving the current image from the webcam for testing.
        cv2.imwrite(FaceFileName, sub_face)
        text = classifier.main(FaceFileName)# Getting the Result from the label_image file, i.e., Classification Result.
        text = text.title()
        font = cv2.FONT_HERSHEY_TRIPLEX
        cv2.putText(im, text,(x+w,y), font, 1, (0,0,255), 2)

    # Show the image
    cv2.imshow('Capture',   im)
    key = cv2.waitKey(10)
    # if Esc key is press then break out of the loop
    if key == 27: 
        break
