// -----------------------------

// Configuración matriz 8x8 1588BS

// -----------------------------

const int ROWS = 8;

const int COLS = 8;



// FILAS (en orden fila 1 → fila 8)

const int row[ROWS] = {

  6,    // fila 1

  9,    // fila 2

  7,    // fila 3

  A1,   // fila 4

  3,    // fila 5

  2,    // fila 6

  10,   // fila 7

  12    // fila 8

};



// COLUMNAS (en orden columna 1 → columna 8)

const int col[COLS] = {

  5,    // columna 1

  11,   // columna 2

  A0,   // columna 3

  13,   // columna 4

  4,    // columna 5

  A2,   // columna 6

  8,    // columna 7

  A3    // columna 8

};



// -----------------------------

// Joystick

// -----------------------------

const int VRX = A4;   // Horizontal

const int VRY = A5;   // Vertical

const int SW  = 1;    // Botón joystick (no lo usamos mucho aquí, pero lo dejamos configurado)



// -----------------------------

// Buzzer

// -----------------------------

const int BUZZER = 0; // Buzzer en pin 0



// -----------------------------

// Snake

// -----------------------------

const int MAX_SNAKE_LENGTH = ROWS * COLS;



int snakeRow[MAX_SNAKE_LENGTH];

int snakeCol[MAX_SNAKE_LENGTH];

int snakeLength = 3;



// Dirección actual del snake (dr, dc)

// Empezamos moviéndonos hacia la derecha

int dirRow = 0;

int dirCol = 1;



// Tiempo entre movimientos del snake (ms)

unsigned long lastMoveTime = 0;

unsigned long MOVE_INTERVAL = 350; // Puedes ajustar la velocidad



// -----------------------------

// Manzana

// -----------------------------

int appleRow = 0;

int appleCol = 0;



// Parpadeo de la manzana

bool appleVisible = true;

unsigned long lastAppleBlinkTime = 0;

const unsigned long APPLE_BLINK_INTERVAL = 400; // ms



// -----------------------------

// Buffer de la matriz (qué LEDs están ON)

// -----------------------------

bool matrix[ROWS][COLS];



// Para el refresco por filas

byte currentScanRow = 0;



// Zona muerta del joystick

const int DEAD_ZONE_MIN = 400;

const int DEAD_ZONE_MAX = 600;



// Para evitar cambiar dirección demasiado rápido

unsigned long lastDirectionTime = 0;

const unsigned long DIRECTION_DELAY = 120;



// ---------------------------------

// Setup

// ---------------------------------

void setup() {

  // Configurar pines de la matriz

  for (int i = 0; i < ROWS; i++) {

    pinMode(row[i], OUTPUT);

    digitalWrite(row[i], HIGH);  // OFF (fila en HIGH)

  }

  for (int i = 0; i < COLS; i++) {

    pinMode(col[i], OUTPUT);

    digitalWrite(col[i], LOW);   // OFF (columna en LOW)

  }



  // Joystick

  pinMode(VRX, INPUT);

  pinMode(VRY, INPUT);

  pinMode(SW, INPUT_PULLUP);



  // Buzzer

  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);



  // Semilla aleatoria para la manzana

  randomSeed(analogRead(A3));



  // Inicializar juego

  resetGame();

}



// ---------------------------------

// Loop principal

// ---------------------------------

void loop() {

  // 1. Refrescar la pantalla (muy rápido, fila a fila)

  refreshDisplay();



  // 2. Actualizar dirección según joystick

  handleJoystickDirection();



  // 3. Hacer avanzar la serpiente cada cierto tiempo

  updateSnakeMovement();



  // 4. Gestionar parpadeo de la manzana

  updateAppleBlink();

}



// ---------------------------------

// Reiniciar juego

// ---------------------------------

void resetGame() {

  // Centrar el snake en el medio, orientación horizontal

  snakeLength = 3;



  int startRow = ROWS / 2; // fila 4

  int startCol = COLS / 2; // col 4



  snakeRow[0] = startRow;     // cabeza

  snakeCol[0] = startCol;

  snakeRow[1] = startRow;     // cuerpo

  snakeCol[1] = startCol - 1;

  snakeRow[2] = startRow;     // cola

  snakeCol[2] = startCol - 2;



  dirRow = 0;

  dirCol = 1; // hacia la derecha



  // Crear primera manzana

  spawnApple();



  // Limpiar matriz

  clearMatrix();

  drawSnakeAndApple();

}



// ---------------------------------

// Limpiar buffer de matriz

// ---------------------------------

void clearMatrix() {

  for (int r = 0; r < ROWS; r++) {

    for (int c = 0; c < COLS; c++) {

      matrix[r][c] = false;

    }

  }

}



// ---------------------------------

// Dibujar snake y manzana en el buffer

// ---------------------------------

void drawSnakeAndApple() {

  clearMatrix();



  // Dibujar cuerpo del snake

  for (int i = 0; i < snakeLength; i++) {

    int r = snakeRow[i];

    int c = snakeCol[i];

    matrix[r][c] = true;

  }



  // Dibujar manzana (si está "visible" para el parpadeo)

  if (appleVisible) {

    matrix[appleRow][appleCol] = true;

  }

}



// ---------------------------------

// Refresco de la matriz LED fila a fila

// ---------------------------------

void refreshDisplay() {

  // Apagar todas las filas y columnas

  for (int r = 0; r < ROWS; r++) {

    digitalWrite(row[r], HIGH); // filas OFF

  }

  for (int c = 0; c < COLS; c++) {

    digitalWrite(col[c], LOW);  // columnas OFF

  }



  // Activar solo la fila actual

  digitalWrite(row[currentScanRow], LOW);



  // Encender columnas de esa fila

  for (int c = 0; c < COLS; c++) {

    if (matrix[currentScanRow][c]) {

      digitalWrite(col[c], HIGH);

    }

  }



  // Siguiente fila para el siguiente loop

  currentScanRow++;

  if (currentScanRow >= ROWS) {

    currentScanRow = 0;

  }

}



// ---------------------------------

// Leer joystick y actualizar dirección

// ---------------------------------

void handleJoystickDirection() {

  unsigned long now = millis();

  if (now - lastDirectionTime < DIRECTION_DELAY) {

    return;

  }



  int x = analogRead(VRX);

  int y = analogRead(VRY);



  int newDirRow = dirRow;

  int newDirCol = dirCol;



  // Horizontal

  if (x < DEAD_ZONE_MIN) {

    // izquierda

    newDirRow = 0;

    newDirCol = -1;

  } else if (x > DEAD_ZONE_MAX) {

    // derecha

    newDirRow = 0;

    newDirCol = 1;

  }



  // Vertical

  if (y < DEAD_ZONE_MIN) {

    // arriba

    newDirRow = -1;

    newDirCol = 0;

  } else if (y > DEAD_ZONE_MAX) {

    // abajo

    newDirRow = 1;

    newDirCol = 0;

  }



  // Evitar girar 180º (no puedes ir de derecha a izquierda directamente)

  if (!(newDirRow == -dirRow && newDirCol == -dirCol)) {

    if (newDirRow != dirRow || newDirCol != dirCol) {

      dirRow = newDirRow;

      dirCol = newDirCol;

      lastDirectionTime = now;

    }

  }

}



// ---------------------------------

// Movimiento del snake

// ---------------------------------

void updateSnakeMovement() {

  unsigned long now = millis();

  if (now - lastMoveTime < MOVE_INTERVAL) {

    return;

  }

  lastMoveTime = now;



  // Nueva cabeza

  int newHeadRow = snakeRow[0] + dirRow;

  int newHeadCol = snakeCol[0] + dirCol;



  // Comprobar choque con paredes

  if (newHeadRow < 0 || newHeadRow >= ROWS || newHeadCol < 0 || newHeadCol >= COLS) {

    // Sonido de "muerte" y reset

    tone(BUZZER, 200, 300);

    delay(300);

    resetGame();

    return;

  }



  // Comprobar choque con el propio cuerpo

  for (int i = 0; i < snakeLength; i++) {

    if (snakeRow[i] == newHeadRow && snakeCol[i] == newHeadCol) {

      // Sonido de "muerte" y reset

      tone(BUZZER, 150, 300);

      delay(300);

      resetGame();

      return;

    }

  }



  // ¿Come manzana?

  bool ateApple = (newHeadRow == appleRow && newHeadCol == appleCol);



  // Mover cuerpo: desplazamos todos los segmentos hacia atrás

  for (int i = snakeLength - 1; i > 0; i--) {

    snakeRow[i] = snakeRow[i - 1];

    snakeCol[i] = snakeCol[i - 1];

  }



  // Nueva cabeza

  snakeRow[0] = newHeadRow;

  snakeCol[0] = newHeadCol;



  if (ateApple) {

    // Crecer: aumentamos longitud (si no hemos llegado al máximo)

    if (snakeLength < MAX_SNAKE_LENGTH) {

      snakeLength++; // Y colocamos el nuevo trozo justo donde estaba la antigua cola

snakeRow[snakeLength - 1] = snakeRow[snakeLength - 2];

snakeCol[snakeLength - 1] = snakeCol[snakeLength - 2];

    }



    // Sonido "positivo"

    tone(BUZZER, 800, 140);



    // Nueva manzana

    spawnApple();

  }



  // Redibujar en el buffer

  drawSnakeAndApple();

}



// ---------------------------------

// Generar nueva manzana en una casilla libre

// ---------------------------------

void spawnApple() {

  while (true) {

    int r = random(0, ROWS);

    int c = random(0, COLS);



    bool occupied = false;

    for (int i = 0; i < snakeLength; i++) {

      if (snakeRow[i] == r && snakeCol[i] == c) {

        occupied = true;

        break;

      }

    }



    if (!occupied) {

      appleRow = r;

      appleCol = c;

      break;

    }

  }



  // Reiniciamos parpadeo

  appleVisible = true;

  lastAppleBlinkTime = millis();

}



// ---------------------------------

// Parpadeo de la manzana

void updateAppleBlink() {
  unsigned long now = millis();

  if (now - lastAppleBlinkTime >= APPLE_BLINK_INTERVAL) {
    appleVisible = !appleVisible;          // alterna visible / invisible
    lastAppleBlinkTime = now;
    drawSnakeAndApple();                   // redibujar con el nuevo estado
  }
}


