// C++ code
// Slave Code

// SPI PIN Definition
#define MISO 12
#define MOSI 11
#define SCK 13
#define CS 10

int prevClockState = LOW;
byte currentByte = 0;
int bitCount = 0; 
bool byteReady = false;

void setup()
{
  pinMode(SCK, INPUT);
  pinMode(CS, INPUT); // Changed SS to CS to match your define statement
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  
  // Initialize serial communication for printing the received data
  Serial.begin(9600);
}

void loop()
{
  // Check if the Master has initiated communication (CS is active LOW)
  if (digitalRead(CS) == LOW) {
    int clockState = digitalRead(SCK);
    
    // Detect the rising edge of the clock signal
    if (clockState == HIGH && prevClockState == LOW) {
      // Read the received bit from the MOSI line
      byte receivedBit = digitalRead(MOSI);
      
      // Shift the current bits and add the newly received bit to form a byte
      currentByte = (currentByte << 1) | receivedBit;
      bitCount++;

      // If 8 bits are received, set the flag that the byte is ready
      if (bitCount == 8) {
        byteReady = true;
        bitCount = 0;
      }
    }
    
    // Store the current clock state for the next iteration
    prevClockState = clockState;
    
  } else {
    // Reset the counter and byte buffer if communication is finished or inactive
    bitCount = 0;
    currentByte = 0;
  }
  
  // If a full byte was received, print it to the Serial Monitor
  if (byteReady) {
    Serial.print("Received byte: ");
    Serial.println(currentByte);
    byteReady = false; // Reset the flag for the next byte
  }
}