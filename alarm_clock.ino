#include <LiquidCrystal.h>

const int saniyeButton=2,dakikaButton=7,saatButton=8,startButton=12,buzzer=13,rs=3,e=5,d4=6,d5=9,d6=10,d7=11;

LiquidCrystal lcd(rs,e,d4,d5,d6,d7);


int saat = 0;
int dakika = 0;
int saniye = 0;
bool geriSayimBasladi = false;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(saatButton, INPUT);
  pinMode(dakikaButton, INPUT);
  pinMode(saniyeButton, INPUT);
  pinMode(startButton, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(saatButton) == HIGH) {
    saat++;
    if (saat > 23) saat = 0;
    guncelleLCD();
    delay(200); // Debounce için
  }
  if (digitalRead(dakikaButton) == HIGH) {
    dakika++;
    if (dakika > 59) dakika = 0;
    guncelleLCD();
    delay(200); // Debounce için
  }
  if (digitalRead(saniyeButton) == HIGH) {
    saniye++;
    if (saniye > 59) saniye = 0;
    guncelleLCD();
    delay(200); // Debounce için
  }
  if (digitalRead(startButton) == HIGH) {
    geriSayimBasladi = true;
  }

  if (geriSayimBasladi) {
    geriSayim();
  }
}

void guncelleLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  //lcd.print("Saat: ");
  if (saat < 10) lcd.print('0');
  lcd.print(saat);
  lcd.print(":");
  if (dakika < 10) lcd.print('0');
  lcd.print(dakika);
  lcd.print(":");
  if (saniye < 10) lcd.print('0');
  lcd.print(saniye);
}

void geriSayim() {
  if (saniye == 0) {
    if (dakika == 0) {
      if (saat == 0) {
        // Geri sayım bitti
        alarmcaliyor();
        geriSayimBasladi = false;
        return;
      } else {
        saat--;
        dakika = 59;
      }
    } else {
      dakika--;
    }
    saniye = 59;
  } else {
    saniye--;
  }
  guncelleLCD();
  delay(1000); // 1 saniye beklet
}


void alarmcaliyor()
{
  tone(buzzer,262);
  delay(500);
  noTone(buzzer);
  delay(1000);
  tone(buzzer,262);
  delay(500);
  noTone(buzzer);
  delay(1000);
  tone(buzzer,262);
  delay(500);
  noTone(buzzer);
  delay(1000);
  tone(buzzer,262);
  delay(500);
  noTone(buzzer);
  delay(1000);
  tone(buzzer,262);
  delay(500);
  noTone(buzzer);
  delay(1000);
}