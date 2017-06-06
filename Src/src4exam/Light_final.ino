//  lux
#define CDS_INPUT 0
void setup() {
Serial.begin(9600);
}
void loop() {
  int value = analogRead(CDS_INPUT);
  Serial.println(int(luminosity(value)));
  delay(1000);
}

//Voltage to LuxLux
double luminosity (int RawADC0){
  double Vout=RawADC0*0.0048828125;  // 5/1024 (Vin = 5 V)
  int lux=(2500/Vout-500)/10;  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
