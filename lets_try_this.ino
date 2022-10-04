#include<LiquidCrystal.h>
int rs = 4, e = 3, d4 = 2, d5 = A1, d6 = A2, d7 = A3; 
LiquidCrystal score(rs, e, d4, d5, d6, d7);


int bg = 8, bb = 7, br = 9, by = 6;
int play = A4;

int lb = 11, lg = 12, lr = 13, ly = 10;

int buzz = 5;
int value, click, did = 0;
int time = 500, timeup = 1000, wait = 40;
int i, k, j = 2, m = 1;
int l = 1;



int leds[] = {lb, lg, lr, ly};
int ran[20] = {0};
int parss[20] = {0};


String clr;

bool isit;

void setup() 
{
  pinMode(bg, INPUT);
  digitalWrite(bg, HIGH);
  pinMode(bb, INPUT);
  digitalWrite(bb, HIGH);
  pinMode(br, INPUT);
  digitalWrite(br, HIGH);
  pinMode(by, INPUT);  
  digitalWrite(by, HIGH);
  pinMode(play, INPUT_PULLUP);

  pinMode(lb, OUTPUT);
  pinMode(lg, OUTPUT);
  pinMode(lr, OUTPUT);
  pinMode(ly, OUTPUT);
  
  pinMode(buzz, OUTPUT);

  Serial.begin(9600);
  score.begin(16, 2);
  score.clear();
  score.print("WELCOME");
  delay(timeup);
  score.clear();

  randomSeed(analogRead(0));

}

void loop() 
{

  j = 2;
  score.print(" _CLICK PLAY_ ");
  score.setCursor(0, 1);
  score.print(" _TO START_ ");
  while(digitalRead(play) == HIGH) {}
  score.clear();
  tone (buzz, 312, 500); 

  for( i = 1; i < j; i++)
  {
    Serial.println(i);

    level_counter();
    flash();
    for( k = 0; k < i; k++) 
    {
      while (digitalRead(bg) == HIGH && digitalRead(bb) == HIGH && digitalRead(br) == HIGH && digitalRead(by) == HIGH ) {}
      which_is_clicked();
      delay(time);
    }
    for (int z = 0; z < j; z++) 
    { 
      Serial.print(ran[z]);
      Serial.print("and");
      Serial.println(parss[z]); 
    }

    l = 1;
    did = 0;

    for (int g = 0; g < j; g++) 
    {
      if (ran[g] == parss[g]) {did++;}
      else {break;}
    }
    
    if (j == 21) 
    {
      score.clear();
      delay(time);
      score.println("_YOU WON_");
      delay(time);
      score.clear();
      tone(buzz, 512, 500);
      break;
    }
    else if (did == j) 
    {
      score.clear();
      delay(time);
      score.println("CORRECT");
      delay(time);
      tone (buzz, 30, 1500);
      j++;
    }
    
    else 
    {
      score.clear();
      delay(time);
      score.println("Wrong");
      delay(time);
      score.clear();
      tone(buzz, 500, 1000);
      break;
    } 
    delay(time);
    }
    delay(timeup);
    
  }

void flash() 
{
  value = random(4);
  ran[i] = value;
  digitalWrite(leds[value], HIGH);
  delay(timeup);
  digitalWrite(leds[value], LOW);
  delay(time);
}
int which_is_clicked() 
{

  if (digitalRead(bb) == LOW) 
    {
      click = 0;
    }
  else if (digitalRead(bg) == LOW) 
    {
      click = 1;
    }
  else if (digitalRead(br) == LOW) 
    {
      click = 2;
    }
  else if (digitalRead(by) == LOW) 
    {
      click = 3;
    }
  parss[l] = click;
  l++;
}
int level_counter()
{
  score.setCursor(0, 0);
  score.print("LEVEL ");
  score.println(i);
  delay(time);
  score.clear();
  delay(time);
  score.setCursor(0, 0);
  score.print("LEVEL ");
  score.println(i);
  delay(time);

}

