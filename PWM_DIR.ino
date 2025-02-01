#define PWM1_PIN 25
#define DIR1_PIN 26
#define PWM2_PIN 27
#define DIR2_PIN 14

void setup() {
  // Configure pins
  pinMode(PWM1_PIN, OUTPUT);
  pinMode(DIR1_PIN, OUTPUT);
  pinMode(PWM2_PIN, OUTPUT);
  pinMode(DIR2_PIN, OUTPUT);

  // Setup PWM channels
  ledcAttachPin(PWM1_PIN, 0); // Channel 0 for Motor 1
  ledcSetup(0, 1000, 8);      // 1 kHz, 8-bit resolution

  ledcAttachPin(PWM2_PIN, 1); // Channel 1 for Motor 2
  ledcSetup(1, 1000, 8);      // 1 kHz, 8-bit resolution
}

void loop() {
  // Motor 1: Forward at 50% speed
  digitalWrite(DIR1_PIN, HIGH);
  ledcWrite(0, 128); // 50% duty cycle (128/255)
  delay(2000);

  // Motor 1: Reverse at full speed
  digitalWrite(DIR1_PIN, LOW);
  ledcWrite(0, 255); // Full speed
  delay(2000);

  // Motor 2: Forward at 75% speed
  digitalWrite(DIR2_PIN, HIGH);
  ledcWrite(1, 192); // 75% duty cycle (192/255)
  delay(2000);

  // Motor 2: Reverse at 25% speed
  digitalWrite(DIR2_PIN, LOW);
  ledcWrite(1, 64); // 25% duty cycle (64/255)
  delay(2000);
}