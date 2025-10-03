// Pin where the relay is connected
const int relayPin = 7;

void setup() {
  // Initialize relay pin as output
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // start OFF

  // Start serial communication
  Serial.begin(115200);
  Serial.println("Relay controller ready. Send ON or OFF.");
}

void loop() {
  // Check if data is available on serial
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // read until newline
    command.trim(); // remove spaces / newlines

    if (command.equalsIgnoreCase("ON")) {
      digitalWrite(relayPin, HIGH); // turn relay ON
      Serial.println("Relay ON");
    }
    else if (command.equalsIgnoreCase("OFF")) {
      digitalWrite(relayPin, LOW); // turn relay OFF
      Serial.println("Relay OFF");
    }
    else {
      Serial.print("Unknown command: ");
      Serial.println(command);
    }
  }
}
