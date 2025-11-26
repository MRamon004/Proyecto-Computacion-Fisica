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

- Se decide desarrollar un sistema de asistencia de aparcamiento utilizando Arduino dentro de Tinkercad.  
- Se revisan las características del sensor ultrasónico PING))) y del buzzer en el entorno virtual.  
- Primera versión del circuito digital y del archivo base del programa.  

---

### 13/11 — Investigación y planificación

- Análisis del funcionamiento del sensor en Tinkercad y estudio de los tiempos de pulso.  
- Definición de los rangos de distancia (verde, amarillo, rojo y alerta crítica).  
- Planificación de la estructura del código y diseño de las funciones que organizarán la lógica.  

---

### 18/11 — Construcción del prototipo digital

- Se arma el circuito dentro de Tinkercad asignando los pines correspondientes a LEDs, buzzer y sensor.  
- Se realizan pruebas iniciales en el monitor serie para validar las lecturas de distancia.  
- Se confirma que el sensor responde correctamente en el simulador.  

---

### 20/11 — Desarrollo de señales visuales y acústicas

- Implementación del comportamiento combinado de luces y sonido según la distancia detectada.  
- Ajuste de los tiempos de parpadeo y de los pitidos para obtener una respuesta progresiva y clara.  
- Primera versión totalmente funcional del sistema en el simulador.  

---

### 25/11 — Optimización y pulido final

- Reajuste de los rangos de distancia para obtener transiciones más intuitivas entre colores.  
- Creación de funciones auxiliares como `apagarTodo()` y separación de parpadeo con y sin sonido.  
- Mejoras generales del código para hacerlo más legible, modular y fácil de mantener.  
- El prototipo queda listo para demostración, documentación y extensión futura.  

