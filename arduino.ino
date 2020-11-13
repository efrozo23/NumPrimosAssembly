/*
Este arduino lee un número por teclado y calcula los números primos
que se encuentran
*/
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte FILAS = 4;          // define numero de filas
const byte COLUMNAS = 4;       // define numero de columnas
char keys[FILAS][COLUMNAS] = { // define la distribucion de teclas
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte pinesFilas[FILAS] = {9, 8, 7, 6};       // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5, 4, 3, 2}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS); // crea objeto
/*
	Config LCD
*/
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);
bool x;
int value, count, j,indice = 0;
char data[2];


void setup()
{

    Serial.begin(9600);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("PROGRAMA  QUE MUESTRA NUMEROS PRIMOS");
    delay(2000);
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("INGRESE EL NUMERO");

    char key = teclado.getKey();

    if (key == '#')
    {
        
        value = atoi(data);
      	Serial.println("Valor a procesar");
        Serial.println(value);
        delay(200);
        lcd.clear();
        calcularNumeros(value);
        indice = 0;
        
    }
  if(key  != NO_KEY && key != '#'){
    
    data[indice] = key;
    lcd.setCursor(indice, 1);
    lcd.print(key);
    indice++;
    Serial.println(key);
    
  }
}

void calcularNumeros(int n)
{
    lcd.setCursor(0, 0);
    lcd.print("NUMEROS");
    int i;
    for (i = 0; i <= n; i++)
    {
        bool isP = isPrime(i);
        if (isP)
        {

            lcd.setCursor(0, 1);
            lcd.print(i);
            delay(100);
            count++;
        }
    }

    Serial.println(count);
    lcd.setCursor(5, 1);
    lcd.print(String("Cant:") + String(count));
    delay(500);
    lcd.clear();
}

bool isPrime(int n)
{

    if (n <= 3)
    {
        return n > 1;
    }
    else if ((n % 2) == 0 || (n % 3) == 0)
    {
        return false;
    }
    int i = 5;
    while (i * i <= n)
    {
        if ((n % i) == 0 || (n % (i + 2) == 0))
        {
            return false;
        }
    }

    return true;
}

bool isPrime2(int n)
{
    int i;
    if (n == 2) return true;
    if (n < 2) return false;
    if(isOdd(n))
    {
        for ( i = 0; i <=(n/3); i+=2)
        {
            if(n % i == 0) return false;
        }
        return true;
        
    }
    else return false;
    
}

bool isOdd(int check)
{
    return ((check % 2) != 0) ? true : false;
}
