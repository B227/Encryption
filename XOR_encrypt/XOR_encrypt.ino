void setup() {
  Serial.begin(9600);
}

uint16_t val = 432;



uint16_t enc_xor(int ID, uint16_t value) {
  uint16_t key_array[] = {123, 124, 125, 126, 127, 128, 129, 130, 131};
  value ^= key_array[ID];
  return value;
}

uint16_t dec_xor(int ID, uint16_t value){
    uint16_t key_array[] = {123, 124, 125, 126, 127, 128, 129, 130, 131};
    value ^= key_array[ID];
    return value; 
  }

void loop() {
  
}
