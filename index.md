# RFID and Fingerprint Safe
This is a RFID and fingerprint safe that uses RFID technology and a fingerprint scanner to turn a servo that acts as the locking mechanism. When a RFID tag is sensed and the correct fingerprint is scanned the servo will rotate 90 degrees allowing the safe box to open.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Sohan Shah | Xavier High School | Biomedical / Civil Engineering | Incoming Junior

<HTML>
  
<img src="images/RFID:Fingerprint.jpg" width=700 align=center style="float:center; padding-right:10px">
  
</HTML>
  
# Final Milestone
My final milestone is  

[![Final Milestone] Under construction {:target="_blank" rel="noopener"}

# Third Milestone
My third milestone is 

The steps I took during this milestone began with downloading an external 

[![Third Milestone] Under construction {:target="_blank" rel="noopener"}

# Second Milestone

[![Milestone 2 Video](https://res.cloudinary.com/marcomontalbano/image/upload/v1625876159/video_to_markdown/images/youtube--NUQF3P64RwM-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/NUQF3P64RwM "Milestone 2 Video"){:target="_blank" rel="noopener"}


<HTML>

 <img src="images/Scanner.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML>

During my second milestone I tested the fingerprint scanner, added a buzzer to play a melody when the servo turned 90 degrees, and integrated the fingerprint scanner with the RFID sensor to create a circuit where when both the correct RFID tag and finger was sensed, the servo would turn 90 degrees in addition to playing a melody through the buzzer. During this milestone I added the fingerprint scanner and a piezo buzzer. The fingerprint scanner is an optical sensor that takes a picture of the finger placed on it and stores the data produced by that image, so when the correct finger is placed on the sensor, it would recognize the finger. The piezo buzzer is a small component that has many purposes such as playing sounds, but they can also detect vibration. The circuit that I created during this milestone works by first scanning an RFID tag, and if this tag is correct, the Arduino would process this data and move onto the second layer of security which is the fingerprint scanner. Once this scanner is on, a red light will start to blink prompting the user to scan their finger, and if the correct fingerprint is scanned, the servo will turn 90 degrees. Not only this, but a melody will also play signifying that the opening procedure was a success. The main issue that I ran into during this milestone is integrating the codes of the RFID and fingerprint sensor. At first I thought I could create an if statement with 2 conditions, but that did not work, so instead I had to make it where a variable becomes true when the first condition is met, then make another if statement stating that if the variable is true to then turn the servo 90 degrees.


<HTML>

 <img src="images/Oldservo.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML>

<HTML>

 <img src="images/buzzer.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML>

The steps I took during this milestone start with calibrating the fingerprint sensor to record and store my fingerprint. Before doing so, I first attached the corresponding pins on the Arduino. I used a code found on the Arduino IDE called “enroll” that gave prompts on the serial monitor telling me when I should place my finger in order for it to be recorded. After having my fingerprint stored in the scanner, I found a code online that could be used to turn a servo when the correct fingerprint is sensed. I modified the code to include the correct pins and so it only went through my code once. After learning about how the fingerprint sensor works, I decided to combine the code of that sensor with the RFID’s code. I copied the code for the fingerprint scanner into a new file of code because it seemed a bit more complex than the code for the RFID. I added the elements of RFID code including libraries, the tag’s identification number, and the if statement that made a servo turn when the correct tag was sensed. I was confused on how to combine the codes, so I tried the first idea that I thought of, which is creating an if statement with simply two conditions instead of one, but this idea did not work. So I began manipulating my code to where you had to scan the RFID card and place your finger on the sensor simultaneously in order for the servo to turn. In order to make the fingerprint sensor and RFID not have to work simultaneously, I instead had to make it where a variable becomes true when the first condition is met, then make another if statement stating that if the variable is true to turn on the next sensor. Once this circuit successfully ran, I decided to add a buzzer that would play a melody when the servo opened the safe. First I tested the buzzer by just playing the melody without any conditions telling it to turn on. After this worked, I created a variable in order to turn true when both the RFID and fingerprint sensor read correct readings. Then I created an if statement that said that if the variable that I made was true, to turn on the melody. The last part of this milestone was upgrading the reset button to a bigger and nicer looking button, and switching the plastic geared servo to one that had metal gears and was compatible with metal hardware which would ensure the safe was strong when closed.

<HTML>

 <img src="images/Finger.jpg" width=300 align=left style="float:left; padding-right:10px">  

</HTML>

<HTML>

 <img src="images/speaker.jpg" width=500 align=right style="float:right; padding-right:10px">  

</HTML>

Add code I used...


# First Milestone

[![Milestone 1 Video](https://res.cloudinary.com/marcomontalbano/image/upload/v1625842096/video_to_markdown/images/youtube--GdxWI6m55lo-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/GdxWI6m55lo "Milestone 1 Video"){:target="_blank" rel="noopener"}

<HTML>

 <img src="images/IMG_9720.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML>

<HTML>

 <img src="images/IMG_9721.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML> 


During my first milestone I tested the servo motor with a simple sweep code found on the Arduino IDE, set up the RFID sensor to sense the RFID tag with its unique identification number, and lastly integrated these two parts together to create a circuit where when the correct RFID tag is sensed, the servo motor turns 90 degrees. The main parts that were involved in the milestone are an Arduino microcontroller, a servo motor, and a RFID sensor with a RFID tag. An Arduino is a microcontroller which means it is essentially the brains of the circuit as it is where code is uploaded to and the component that sends and receives data from the various inputs and outputs that are connected to the Arduino. Without the Arduino, all of the sensors and outputs would be unable to work and communicate with each other. The servo motor is similar to a regular motor, but it cannot make a full 360 degree turn, it can only swing back and forth, which is important for my project as the servo acts as the locking mechanism, therefore I really only want it to move 90 degrees. The RFID sensor uses radio frequency to sense and identify an RFID tag. Each RFID tag has a unique identification number that allows it to be sensed and read. This is important for my project because if the correct RFID tag is read, this information is sent to the Arduino and back out to the servo in order for it to turn 90 degrees. The circuit works by first sensing any RFID tag that comes into close contact with it, and either accepting or rejecting the card based on its unique identification number. Next this information is sent back to the Arduino which processes it and either prints on the serial monitor “Wrong Card” or prints “Correct Card” and if the correct card is sensed, the Arduino tells the servo to turn 90 degrees which is what will unlock the safe box in the final project. 


<HTML>

 <img src="images/IMG_9716.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML>

<HTML>

 <img src="images/IMG_9712.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML>



The steps I took during my first milestone began with connecting the servo to the Arduino. The servo had three wires attached to it, one for power, ground, and the third wire is where information travels that tells the servo how far the servo should move left or right. After attaching the wires to their corresponding pins on the Arduino, I found code on the Arduino IDE that swings the servo which I used to test the servo. This code uses a “for loop” to ensure that the servo moves a certain amount of degrees, then returns back to its original position. I ran into a minor issue with uploading the code to my Arduino, but it was simply a privacy issue. After testing the servo, I moved onto the other major component which is the RFID reader. Before I could test it, I first soldered the pins that came with the RFID sensor to it so I could attach jumper wires and connect those to the Arduino. Once the sensor was connected to the Arduino I decided to test it to eventually have the RFID sensor trigger the servo to move 90 degrees. I found code online that was similar to my goal of using the RFID to turn on a servo, but I had to first download an external library which I never have done before. After learning how to do so by downloading and moving files I eventually successfully downloaded the RFID library needed for the code to work. In order for the code to be compatible with my RFID tag, I had to have the RFID sensor read the tag to print the tag’s unique identification number of the serial monitor. I input the identification number into my code so that my card will be read as the correct card when sensed. After doing so, I also manipulated other parts of the code in order to ensure the servo turned correctly. Finally I tested the code, and it was a success where when the RFID tag was sensed by the reader, the servo turned 90 degrees. After testing this circuit I realized that I had no way to return the servo back to the locked position, so I added a reset button where reset the code and brought everything back to where it was before the code had run where the servo was in the lock position.

<HTML>

 <img src="images/Servo.jpg" width=300 align=left style="float:left; padding-right:10px">  

</HTML>

<br>

<HTML>

 <img src="images/RFID.jpg" width=300 align=right style="float:right; padding-right:10px">  

</HTML>

<br>

<HTML>

 <img src="images/Reset.jpg" width=200 align=right style="float:right; padding-right:10px">  

</HTML>

<br>

Add code I used...


