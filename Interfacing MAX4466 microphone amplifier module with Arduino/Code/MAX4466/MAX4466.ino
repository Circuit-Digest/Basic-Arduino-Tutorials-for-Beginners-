const int sampleWindow = 50;  // Sample window width in mS (50 mS = 20Hz)
int const Input_Pin = A0;     // Preamp output pin connected to A0
unsigned int ADC_Value;
void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startMillis = millis();  // Start of sample window

  unsigned int PeakValue = 0;  // peak-to-peak level
  unsigned int InMax = 0;
  unsigned int InMin = 1024;
  // collect data for 50 mS and then plot data
  while (millis() - startMillis < sampleWindow) {
    ADC_Value = analogRead(Input_Pin);
    if (ADC_Value < 1024)  // toss out spurious readings
    {
      if (ADC_Value > InMax) {
        InMax = ADC_Value;  // save just the max levels
      } else if (ADC_Value < InMin) {
        InMin = ADC_Value;  // save just the min levels
      }
    }
  }
  PeakValue = InMax - InMin;  // max - min = peak-peak amplitude
  if (PeakValue < 30) {
    PeakValue = 0;
  }
  Serial.println(PeakValue);
}
