from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject
import cv2

wCam, hCam = 640, 480

cap = cv2.VideoCapture(0)

cap.set(3, wCam)
cap.set(4, hCam)

tip_ids = [4, 8, 12, 16, 20]

arduino = SerialObject('/dev/cu.usbmodem14101')

detector = HandDetector(detectionCon=0.75, maxHands=1)

while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)

    if hands:
        print(detector.fingersUp(hands[0]))
        fingers_up_list = detector.fingersUp(hands[0])
        arduino.sendData(fingers_up_list)
    else:
        arduino.sendData([0, 0, 0, 0, 0])

    cv2.imshow('Image', img)
    cv2.waitKey(1)