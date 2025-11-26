# 🚗 Sistema de Asistencia de Aparcamiento por Proximidad (Arduino)

## 👥 Integrantes

- **Marcos**  
- **Fernando**

---

## 🎯 Propósito del Proyecto

Desarrollar un **asistente de aparcamiento basado en distancia**, utilizando un **sensor ultrasónico** para medir la proximidad a un obstáculo y un **buzzer con tres LEDs indicadores** para mostrar el nivel de alerta al usuario.

El comportamiento del sistema depende de la distancia medida por el sensor:

| Distancia              | Indicador    | Respuesta                                   |
|------------------------|-------------|---------------------------------------------|
| 🟢 Lejana / segura     | LED verde   | Solo se enciende el LED verde               |
| 🟡 Media / de alerta   | LED amarillo| Parpadeo medio + pitidos pausados           |
| 🔴 Muy cercana / riesgo| LED rojo    | Parpadeo rápido + pitidos continuos / rápidos |

El objetivo es imitar el funcionamiento de un asistente de parking real, manteniendo un montaje sencillo y fácil de replicar.

---

## 📝 Funcionamiento General

- El sensor ultrasónico (conectado al pin digital **7**) realiza lecturas periódicas de distancia.  
- Arduino calcula la distancia a partir del tiempo de eco y evalúa en qué rango se encuentra.  
- Según el rango:
  - Enciende uno de los tres LEDs (verde, amarillo o rojo).  
  - Activa el **buzzer** (pin **6**) con una frecuencia de pitidos distinta según la cercanía.  
- El código se ejecuta en bucle, proporcionando **información en tiempo real** para ayudar al aparcamiento.

---

## 🔧 Material Utilizado

### Sensores / Salidas

- 📡 Sensor ultrasónico de distancia (tipo PING/HC-SR04 o equivalente)  
- 🔊 Buzzer piezoeléctrico  
- 💡 3 LEDs:
  - LED verde → conectado al pin **10**  
  - LED amarillo → conectado al pin **9**  
  - LED rojo → conectado al pin **8**  

### Otros componentes necesarios

- Arduino UNO o placa compatible  
- Protoboard  
- Resistencias para los LEDs  
- Cables Dupont macho–macho / macho–hembra  

---

## 📁 Estructura del Repositorio

- `README.md` → Descripción del proyecto, funcionamiento y desarrollo  
- `/arduino` o `/src` → Código fuente del sistema de aparcamiento (`Codigo_Circuito_de_Aparcamiento.ino`)  
- `/docs` →  
  - Esquema del circuito (captura de Tinkercad/Fritzing)  
  - Notas de diseño y referencias  
- `/media` *(opcional)* →  
  - Fotografías del montaje real  
  - Vídeo corto mostrando el sistema en funcionamiento  

---

## 🚦 Progreso Actual

**Fase inicial completada:**

- Lectura estable del sensor ultrasónico desde Arduino.  
- Control de los **tres LEDs** (verde, amarillo y rojo) según el rango de distancia.  
- Activación del **buzzer** con distintos patrones de pitido según lo cerca que esté el obstáculo.  
- Código base probado sobre protoboard usando el circuito mostrado en el esquema.

---

## 🗂️ Planificación por Fases

### Etapa 1 — Lectura de distancia (Finalizada)

- Conexión del sensor ultrasónico al pin 7 y alimentación 5V/GND.  
- Implementación de la función `readUltrasonicDistance()` en el código para obtener la distancia.  
- Visualización de las lecturas por el monitor serie para comprobar estabilidad.

### Etapa 2 — Sistema de alertas (En curso)

- Asociación de rangos de distancia a cada LED (verde/amarillo/rojo).  
- Implementación de funciones como `parpadearLED()` y `parpadearLEDyBeep()` para combinar luz y sonido.  
- Ajuste de la velocidad de parpadeo y del tiempo de beep en función de la proximidad.

### Etapa final — Presentación y mejora visual (Pendiente)

- Montaje más limpio del circuito (cables ordenados / posible carcasa).  
- Preparación de material gráfico para la presentación (capturas y esquemas).  
- Grabación de un vídeo corto donde se observe cómo cambian los LEDs y el buzzer al acercar un objeto al sensor.  

---

## 📒 Registro de Desarrollo

### 11/11 — Propuesta y bases iniciales

- Se decide desarrollar un **sistema de asistencia de aparcamiento** con Arduino.  
- Revisión del funcionamiento del sensor ultrasónico y del buzzer.  
- Creación del primer esquema del circuito y del archivo base `.ino`.

---

### 13/11 — Investigación y planificación

- Estudio de los tiempos de disparo y eco del sensor.  
- Definición de los rangos de distancia para cada nivel (verde / amarillo / rojo).  
- Planificación de las funciones que se usarán en el código para organizar mejor la lógica.

---

### 18/11 — Montaje básico

- Conexión de los tres LEDs (pines 8, 9 y 10) con sus resistencias en protoboard.  
- Cableado del buzzer en el pin 6.  
- Pruebas con el monitor serie para comprobar que la lectura del sensor es consistente.  

---

### 20/11 — Señales acústicas

- Implementación de la función `parpadearLEDyBeep()` para combinar LED + beep.  
- Ajuste de los tiempos de `delay()` para que los pitidos sean más rápidos cuanto más cerca está el obstáculo.  
- Primera versión completa del sistema luz + sonido funcionando.

---

### 25/11 — Mejoras y pulido

- Se ajustan los umbrales de distancia para que la transición entre verde/amarillo/rojo sea más intuitiva.  
- Se mejora la organización del código con funciones auxiliares como `apagarTodo()`.  
- El circuito y el programa quedan listos para la demostración final y documentación.
