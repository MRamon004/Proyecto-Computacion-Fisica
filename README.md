# 🐍 Juego Snake con Arduino y Matriz LED 8x8

## 👥 Integrantes

- **Marcos**  
- **Fernando**

---

## 🎯 Propósito del Proyecto

Desarrollar una versión del clásico juego **Snake** utilizando **Arduino**, una **matriz LED 8x8** como sistema de visualización, un **joystick analógico** para el control del movimiento y un **buzzer** para proporcionar feedback sonoro.

El objetivo del juego es mover la serpiente por la matriz, recoger manzanas para aumentar su tamaño y evitar colisiones con los bordes o con su propio cuerpo, reproduciendo la experiencia básica del juego original en un entorno de hardware sencillo.

---

## 📝 Funcionamiento General

- El estado del juego se representa en una **matriz LED 8x8**, controlada mediante un sistema de refresco por filas.  
- El **joystick analógico** permite controlar la dirección del snake (arriba, abajo, izquierda y derecha).  
- El movimiento del snake se gestiona mediante intervalos de tiempo para asegurar una velocidad constante.  
- Cuando el snake recoge una manzana, aumenta su longitud y se genera una nueva de forma aleatoria.  
- Si se produce una colisión, el juego se reinicia automáticamente.  
- El **buzzer** emite sonidos distintos al comer una manzana y al perder la partida.

Todo el sistema funciona en tiempo real dentro del bucle principal de Arduino.

---

## 🔧 Material Utilizado

### Entradas / Salidas

- 🎮 Joystick analógico  
- 🔊 Buzzer pasivo  
- 💡 Matriz LED 8x8 (modelo 1588BS)

### Otros componentes necesarios

- Arduino UNO o placa compatible  
- Protoboard  
- Resistencias para la matriz LED  
- Cables Dupont macho–macho  

---

## 🚦 Progreso Actual

**Proyecto completado:**

- Control correcto de la matriz LED 8x8.  
- Movimiento fluido del snake mediante joystick analógico.  
- Generación aleatoria de manzanas evitando posiciones ocupadas.  
- Detección de colisiones con bordes y cuerpo del snake.  
- Implementación de feedback sonoro con buzzer.  
- Código organizado mediante funciones para facilitar su comprensión y mantenimiento.

---

## 🗂️ Planificación por Fases

### Etapa 1 — Visualización en la matriz

- Estudio del funcionamiento de la matriz LED 8x8.  
- Implementación del refresco por filas para mostrar gráficos en la matriz.  
- Creación del buffer interno para representar el estado del juego.

---

### Etapa 2 — Control y lógica del juego

- Lectura del joystick mediante entradas analógicas.  
- Implementación del control de dirección evitando giros inválidos.  
- Desarrollo de la lógica de movimiento del snake y gestión del tiempo.  

---

### Etapa final — Sonido y pulido

- Implementación del buzzer para eventos importantes del juego.  
- Ajuste de tiempos y comportamiento general para mejorar la jugabilidad.  
- Preparación del proyecto para su montaje físico y presentación final.

---

## 📒 Registro de Desarrollo

### 11/11 — Propuesta y bases iniciales

- Decisión de desarrollar el juego Snake como proyecto en Arduino.  
- Análisis de los componentes necesarios y viabilidad del proyecto.  
- Primera estructura del código y pruebas iniciales en Tinkercad.

---

### 18/11 — Desarrollo del juego

- Implementación del refresco de la matriz LED.  
- Desarrollo del movimiento del snake y control mediante joystick.  
- Pruebas de colisiones y reinicio del juego.

---

### 25/11 — Optimización y finalización

- Mejora de la organización del código mediante funciones.  
- Implementación del sonido con buzzer.  
- Ajustes finales de jugabilidad y preparación de la documentación.  

