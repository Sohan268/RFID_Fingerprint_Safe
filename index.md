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

<HTML>

 <img src="image" width=300 align=left style="float:left; padding-right:10px">  Foxes live on every continent except Antarctica. The most common and widespread species of fox is the red fox (Vulpes vulpes) with about 47 recognized subspecies. The global distribution of foxes, together with their widespread reputation for cunning, has contributed to their prominence in popular culture and folklore in many societies around the world. The hunting of foxes with packs of hounds, long an established pursuit in Europe, especially in the British Isles, was exported by European settlers to various parts of the New World.

</HTML>

During my first milestone I tested the servo motor with a simple sweep code found on the Arduino IDE, set up the RFID sensor to sense the RFID tag with its unique identification number, and lastly integrated these two parts together to create a circuit where when the correct RFID tag is sensed, the servo motor turns 90 degrees. The main parts that were involved in the milestone are an Arduino microcontroller, a servo motor, and a RFID sensor with a RFID tag. An Arduino is a microcontroller which means it is essentially the brains of the circuit as it is where code is uploaded to and the component that sends and receives data from the various inputs and outputs that are connected to the Arduino. Without the Arduino, all of the sensors and outputs would be unable to work and communicate with each other. The servo motor is similar to a regular motor, but it cannot make a full 360 degree turn, it can only swing back and forth, which is important for my project as the servo acts as the locking mechanism, therefore I really only want it to move 90 degrees. The RFID sensor uses radio frequency to sense and identify an RFID tag. Each RFID tag has a unique identification number that allows it to be sensed and read. This is important for my project because if the correct RFID tag is read, this information is sent to the Arduino and back out to the servo in order for it to turn 90 degrees. The circuit works by first sensing any RFID tag that comes into close contact with it, and either accepting or rejecting the card based on its unique identification number. Next this information is sent back to the Arduino which processes it and either prints on the serial monitor “Wrong Card” or prints “Correct Card” and if the correct card is sensed, the Arduino tells the servo to turn 90 degrees which is what will unlock the safe box in the final project. 

The steps I took during my first milestone began with connecting the servo to the Arduino. The servo had three wires attached to it, one for power, ground, and the third wire is where information travels that tells the servo how far the servo should move left or right. After attaching the wires to their corresponding pins on the Arduino, I found code on the Arduino IDE that swings the servo which I used to test the servo. This code uses a “for loop” to ensure that the servo moves a certain amount of degrees, then returns back to its original position. I ran into a minor issue with uploading the code to my Arduino, but it was simply a privacy issue. After testing the servo, I moved onto the other major component which is the RFID reader. Before I could test it, I first soldered the pins that came with the RFID sensor to it so I could attach jumper wires and connect those to the Arduino. Once the sensor was connected to the Arduino I decided to test it to eventually have the RFID sensor trigger the servo to move 90 degrees. I found code online that was similar to my goal of using the RFID to turn on a servo, but I had to first download an external library which I never have done before. After learning how to do so by downloading and moving files I eventually successfully downloaded the RFID library needed for the code to work. In order for the code to be compatible with my RFID tag, I had to have the RFID sensor read the tag to print the tag’s unique identification number of the serial monitor. I input the identification number into my code so that my card will be read as the correct card when sensed. After doing so, I also manipulated other parts of the code in order to ensure the servo turned correctly. Finally I tested the code, and it was a success where when the RFID tag was sensed by the reader, the servo turned 90 degrees. After testing this circuit I realized that I had no way to return the servo back to the locked position, so I added a reset button where reset the code and brought everything back to where it was before the code had run where the servo was in the lock position.


Add code I used...

[![First Milestone] Under Construction {:target="_blank" rel="noopener"}
