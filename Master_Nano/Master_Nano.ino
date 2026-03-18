// C++ code
// Master Code

// SPI PIN Definition
#define MISO 12
#define MOSI 11
#define SCK 13
#define CS 10

byte clock_state = LOW;
byte counter = 0;

void setup()
{
  pinMode(SCK, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  
  // Set initial state of SPI pins
  digitalWrite(SCK, clock_state);
  digitalWrite(MOSI, LOW);
  digitalWrite(CS, HIGH); // CS is active LOW, so HIGH means idle
}

void send_byte(byte data){
  // Begin communication by pulling CS LOW
  digitalWrite(CS, LOW);
  clock_state = LOW;
  digitalWrite(SCK, clock_state);

  // Send data byte bit by bit, starting with the Most Significant Bit (MSB)
  for(int bit = 7; bit >= 0; bit--){
    // Extract the current bit to send
    byte bitToSend = (data >> bit) & 0x01;
    digitalWrite(MOSI, bitToSend);   
    delay(250); // Delay for visualization
    
    // Generate clock pulse (HIGH)
    clock_state = HIGH;
    digitalWrite(SCK, clock_state);    
    delay(250); // Delay for visualization
    
    // Generate clock pulse (LOW)
    clock_state = LOW;
    digitalWrite(SCK, clock_state);
  }
 
  // End communication by pulling CS HIGH
  digitalWrite(CS, HIGH);
  digitalWrite(MOSI, LOW);
}

void loop()
{
  // Reset counter after reaching 32
  if(counter == 32) {
    counter = 0;
  }
  
  // Send the current counter value
  send_byte(counter);
  delay(2000); // Wait 2 seconds before sending the next byte
  counter++;
}