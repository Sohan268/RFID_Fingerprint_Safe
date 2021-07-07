# RFID and Fingerprint Safe
This is a RFID and fingerprint safe that uses RFID technology and a fingerprint scanner to turn a servo that acts as the locking mechanism. When a RFID tag is sensed and the correct fingerprint is scanned the servo will rotate 90 degrees allowing the safe box to open.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Sohan Shah | Xavier High School | Biomedical / Civil Engineering | Incoming Junior

![Headstone Image](https://bluestampengineering.com/wp-content/uploads/2016/05/improve.jpg)
  
# Final Milestone
My final milestone is  

[![Final Milestone] Under construction {:target="_blank" rel="noopener"}

# Second Milestone
My second milestone is 

[![Third Milestone] Under Construction {:target="_blank" rel="noopener"}
# First Milestone


During my first milestone I tested the servo motor with a simple sweep code found on the Arduino IDE, set up the RFID sensor to sense the RFID tag with its unique identification number, and lastly integrated these two parts together to create a circuit where when the correct RFID tag is sensed, the servo motor turns 90 degrees. The main parts that were involved in the milestone are an Arduino microcontroller, a servo motor, and a RFID sensor with a RFID tag. Arduino is a microcontroller which means it is eventually the brains of the circuit as it is where code is uploaded to and sent to the various components connected to the Arduino. Without the Arduino, all of the sensors and outputs would be unable to work and communicate with each other. The servo motor is similar to a regular motor, but it cannot make a full 360 degree turn, it can only swing back and forth, which is important for my project as the servo acts as the locking mechanism, therefore I really only want it to move 90 degrees. The RFID sensor uses radio frequency to sense and identify an RFID tag. Each RFID tag has a unique identification number that allows it to be sensed and read. This is important for my project because if the correct RFID tag is read, this information is sent back to the Arduino and back out to the servo in order for it to turn 90 degrees, acting and the locking and unlocking mechanism. The circuit works by first sensing any RFID tag that comes into close contact with it, and either accepting or rejecting the card based on its unique identification number. Next this information is sent back to the Arduino which processes it and either prints on the serial monitor “Wrong Card” or prints “Correct Card”  which in that case, the Arduino tells the servo to turn 90 degrees which is what will unlock the safe box in the final project. The main challenge that I ran into during this milestone was getting the RFID sensor to work as it involved external libraries that I was not familiar with. This caused me to have to sift through code in order to understand different types of data types necessary for the RFID tag’s unique identification number to be stored and understand the series of if and else statements that work to turn the servo when the correct card is sensed. 


[![First Milestone] Under Construction {:target="_blank" rel="noopener"}
