#include <AES.h>
#include <AES_config.h>
#include <printf.h>

#include <stdio.h>


#define BLOCK 16


AES aes ;

void setup() {
  Serial.begin (57600) ;
  printf_begin();
  delay(500);
}

int digit(uint16_t dig) {
  int  len = 1;
  while (dig /= 10) {
    len++;
  }
  return len;
}

char key_select(int ID) {
  char *this_key;
  if (ID == 1) {
    this_key = "1234567891234567";
  }
  else if (ID == 2) {
    this_key = "2345678912345671";
  }
  else if (ID == 3) {
    this_key = "3456789123456712";
  }
  else if (ID == 4) {
    this_key = "4567891234567123";
  }
  else if (ID == 5) {
    this_key = "5678912345671234";
  }
  else if (ID == 6) {
    this_key = "6789123456712345";
  }
  else if (ID == 7) {
    this_key = "7891234567123456";
  }
  else if (ID == 8) {
    this_key = "8912345671234567";
  }
  else if (ID == 9) {
    this_key = "9123456712345678";
  }
  return this_key;
}

int encryptor(uint16_t input) {

  char *key = "1234567891234567";

  uint16_t input_data = input;

  int N = digit(input_data) + 1;

  byte plain[N];

  sprintf(plain, "%u", input_data);

  unsigned long long int my_iv = 123456789;

  int keyBits = 128;

  byte iv [16] ;
  byte plain_p [N] ;
  byte cipher [16];
  byte check [16];
  aes.set_IV(my_iv);
  aes.get_IV(iv);
  aes.do_aes_encrypt(plain, N, cipher, key, keyBits, iv);


  uint16_t trans_data [16];
  for(int i = 0; i<16; i++){
    trans_data[i]=cipher[i];
    }

  /*char tester[16];
    for (int i = 0; i < 16; i++)
    tester[i] = cipher[i];

    sscanf(tester, "%d", &trans_data);*/

  printf("\n\nPLAIN :");
  aes.printArray(plain, (bool)true);
  printf("\nCIPHER:");
  aes.printArray(cipher, (bool)false);

  aes.set_IV(my_iv);
  aes.get_IV(iv);
  aes.do_aes_decrypt(cipher, 16, check, key, keyBits, iv);
  printf("\nCHECK :");
  aes.printArray(check, (bool)true);

  printf("\n Trans_data: \n");
  for(int i = 0; i<16; i++){
    Serial.println(trans_data[i]);
    }

  delay(20000);
}

void loop() {
  encryptor(123);



}
