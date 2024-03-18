#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Alamat I2C, jumlah kolom, jumlah baris LCD

// Menetapkan Pin dan Variabel
#define pirPin 12 
int statusPir = LOW; 
int gerakanPir; 

// Inisialisasi LCD dan Tampilan Pesan Awal
void setup() {
  pinMode(pirPin, INPUT); 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("PRAKTIKUM 3");
  lcd.setCursor(3,1);
  lcd.print("Sensor PIR");
  Serial.begin(9600); 
  delay(2000);
}

// Membaca sensor PIR dan menampilkan hasilnya
void loop() {
  gerakanPir = digitalRead(pirPin);
  if(gerakanPir==HIGH){ 
    lcd.backlight();  
    lcd.setCursor(0, 0);  
    lcd.print("Motion detect!!!");
    delay(1000) ;
  }
  else{  
    Serial.println("No motion detect");
    lcd.clear();
  }
  delay(2000);
}
