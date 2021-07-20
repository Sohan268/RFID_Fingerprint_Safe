#include <Adafruit_Fingerprint.h>
#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#include "pitches.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

const int soundpin = A0;
const int threshold = 350;
VR myVR(6, 7);
int LED = 5;
int LED1 = A1;
int LED2 = A2;
int LED3 = A3;
uint8_t records[7];
uint8_t buf[64];
#define code1    (2) //two
#define code2   (3) //six
#define code3    (4)//three
#define mode    (5)//one
#define code4    (6)//five
#define code5    (7)//eight
#define lock2    (8) //lock
int led = 5;

#define onRecord    (0) //OPEN
#define offRecord   (1) //LOCK

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
int pos = 0;
RFID rfid(10, 9);
boolean match = false;
boolean sound = false;
boolean microphone = false;
boolean unlock = false;
boolean mode1 = false;
boolean step1 = false;
boolean step2 = false;
boolean step3 = false;
boolean step4 = false;
boolean knock = false;
byte kart[5] = {185, 114, 251, 178, 130};
byte kart2[5] = {154, 22, 225, 63, 82};
boolean card;

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)

SoftwareSerial mySerial(2, 3);

#else

#define mySerial Serial1

#endif

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};


int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
  pinMode(soundpin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  lcd.init();
  myservo.attach(8);
  SPI.begin();
  rfid.init();

  Serial.begin(9600);
  while (!Serial);  
  delay(100);


  myVR.begin(9600);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");
  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  if (myVR.load((uint8_t)code1) >= 0) {
    Serial.println("code1loaded");
  }

  if (myVR.load((uint8_t)code2) >= 0) {
    Serial.println("code2loaded");
  }
  if (myVR.load((uint8_t)code3) >= 0) {
    Serial.println("code3loaded");
  }

  if (myVR.load((uint8_t)mode) >= 0) {
    Serial.println("modeloaded");
  }
  if (myVR.load((uint8_t)code4) >= 0) {
    Serial.println("code4loaded");
  }
  if (myVR.load((uint8_t)code5) >= 0) {
    Serial.println("code5loaded");
  }
  if (myVR.load((uint8_t)lock2) >= 0) {
    Serial.println("offRecord loaded");
  }

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Choose Unlock");
  lcd.setCursor(3, 1);
  lcd.print("Mode 1 or 2");
}
void(* resetFunc) (void) = 0;
void loop()                     
{
  digitalWrite(LED3, HIGH);


  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    switch (buf[1]) {
      case mode:
        mode1 = true;
        lcd.backlight();
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Locked");
        lcd.setCursor(4, 1);
        lcd.print("Scan Card");
        break;
      case code1:
        lcd.backlight();
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Locked-Enter");
        lcd.setCursor(0, 1);
        lcd.print("4-Digit Passcode");
        digitalWrite(LED2, HIGH);
        Serial.println("mode 2");
        step1 = true;
    }
  }
  if (mode1 == true) {
    if (rfid.isCard())
    {


      if (rfid.readCardSerial())
      {
        Serial.print("Found ID: ");
        Serial.print(rfid.serNum[0]);
        Serial.print(",");
        Serial.print(rfid.serNum[1]);
        Serial.print(",");
        Serial.print(rfid.serNum[2]);
        Serial.print(",");
        Serial.print(rfid.serNum[3]);
        Serial.print(",");
        Serial.println(rfid.serNum[4]);

      }
      for (int i = 1; i < 5; i++)
      {
        if (rfid.serNum[0] == kart[0] && rfid.serNum[1] == kart[1] && rfid.serNum[2] == kart[2] && rfid.serNum[3] == kart[3] && rfid.serNum[4] == kart[4] || rfid.serNum[0] == kart2[0] && rfid.serNum[1] == kart2[1] && rfid.serNum[2] == kart2[2] && rfid.serNum[3] == kart2[3] && rfid.serNum[4] == kart2[4])
        {
          card = true;
        }
        else {
          card = false;
        }
      }
      if (card == true)
      {
        digitalWrite(LED2, HIGH);
        lcd.backlight();
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Locked");
        lcd.setCursor(3, 1);
        lcd.print("Scan Finger");
        while (match == false)
        {
          Serial.println("\n\nAdafruit finger detect test");

          // set the data rate for the sensor serial port
          finger.begin(57600);
          delay(5);
          if (finger.verifyPassword()) {
            Serial.println("Found fingerprint sensor!");
          } else {
            Serial.println("Did not find fingerprint sensor :(");
            while (1) {
              delay(1);
            }
          }

          Serial.println(F("Reading sensor parameters"));
          finger.getParameters();
          Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
          Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
          Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
          Serial.print(F("Security level: ")); Serial.println(finger.security_level);
          Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
          Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
          Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

          finger.getTemplateCount();

          if (finger.templateCount == 0) {
            Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
          }
          else {
            Serial.println("Waiting for valid finger...");
            Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
          }
          getFingerprintID();
          delay(50);  //don't ned to run this at full speed.


          if (match == true)
          {
            myVR.begin(9600);
            Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");



            if (myVR.clear() == 0) {
              Serial.println("Recognizer cleared.");
            } else {
              Serial.println("Not find VoiceRecognitionModule.");
              Serial.println("Please check connection and restart Arduino.");
              while (1);
            }

            if (myVR.load((uint8_t)onRecord) >= 0) {
              Serial.println("onRecord loaded");
            }

            if (myVR.load((uint8_t)offRecord) >= 0) {
              Serial.println("offRecord loaded");
            }
            lcd.backlight();
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("Locked-Enter");
            lcd.setCursor(1, 1);
            lcd.print("Secret Password");
            digitalWrite(LED1, HIGH);
            while (microphone == false) {
              int ret;
              ret = myVR.recognize(buf, 50);
              if (ret > 0) {
                switch (buf[1]) {
                  case onRecord:
                    microphone = true;
                    break;
                    
                }

              }
            }

          }
          if (microphone == true)
          {
            myservo.write(180);
            sound = true;
            lcd.backlight();
            lcd.clear();
            lcd.setCursor(3, 0);
            lcd.print("Open-Press");
            lcd.setCursor(2, 1);
            lcd.print("Button to Lock");
            unlock = true;
            digitalWrite(LED, HIGH);
          }
        }
      }

    }
  }
  if (step1 == true) {

    if (ret > 0) {
      switch (buf[1]) {
        case code5:
          step2 = true;
          Serial.println("8");
          lcd.backlight();
          lcd.clear();
          lcd.setCursor(5, 0);
          lcd.print("Locked");
          lcd.setCursor(4, 1);
          lcd.print("*");

      }
    }

    if (step2 == true) {

      if (ret > 0) {
        switch (buf[1]) {
          case code3:
            step3 = true;
            Serial.println("3");
            lcd.backlight();
            lcd.clear();
            lcd.setCursor(5, 0);
            lcd.print("Locked");
            lcd.setCursor(4, 1);
            lcd.print("**");
            step2 = false;
            break;
        }
      }
    }
    if (step3 == true)
    {

      if (ret > 0) {
        switch (buf[1]) {
          case code4:
            step4 = true;
            Serial.println("5");
            lcd.backlight();
            lcd.clear();
            lcd.setCursor(5, 0);
            lcd.print("Locked");
            lcd.setCursor(4, 1);
            lcd.print("***");
            step3 = false;
            break;
        }
      }
    }
    if (step4 == true)
    {
      if (ret > 0) {
        switch (buf[1]) {
          case code2:
            Serial.println("6");
            digitalWrite(LED1, HIGH);
            knock = true;
            lcd.backlight();
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("Locked-Enter");
            lcd.setCursor(1, 1);
            lcd.print("Secret Password");
            step4 = false;
            break;
        }
      }
    }
    delay(200);
    while (knock == true) {

      int soundsens = analogRead(soundpin);
      Serial.println(soundsens);
      if (soundsens >= threshold) {
        myservo.write(180);
        sound = true;
        lcd.backlight();
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("Open-Press");
        lcd.setCursor(2, 1);
        lcd.print("Button to Lock");
        unlock = true;
        sound = true;
        digitalWrite(LED, HIGH);
        knock = false;
        step1 = false;

      }

    }
  }
  if (sound == true) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(4, melody[thisNote], noteDuration);

      
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      
      noTone(4);
    }
    sound = false;
  }
  if (unlock == true)
  {

    int ret;
    ret = myVR.recognize(buf, 50);
    if (ret > 0) {
      switch (buf[1]) {
        case offRecord:
          resetFunc();
          break;
        case lock2:
          resetFunc();
          break;
      }
    }
  }
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      delay(500);
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }



  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  


  
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    match = true;
    // myservo.write(0);

  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

}
