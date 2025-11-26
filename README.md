# 🚗 Proyecto: Sistema de Proximidad para Aparcamiento (Arduino)

## 👥 Equipo

- **Juan** — Programador  
- **Darío** — Programador  

Ambos colaboramos en la programación, conexión del hardware y validación del prototipo físico.

---

## 🎯 Objetivo del Proyecto

Diseñar un **sistema de ayuda al aparcamiento basado en proximidad**, utilizando un **sensor ultrasónico HC-SR04** para medir la distancia con respecto a un obstáculo y un **buzzer + LEDs** para avisar al conductor con señales visuales y acústicas.

El sistema detectará la distancia del coche frente al objeto y responderá de la siguiente forma:

- 🟢 **Distancia segura** → LED verde — sin alarma  
- 🟡 **Zona de alerta** → LED amarillo — pitidos lentos  
- 🔴 **Peligro de colisión** → LED rojo — pitidos rápidos  

El objetivo es crear un asistente de aparcamiento funcional, económico y educativo.

---

## 📝 Descripción General

- El sensor ultrasónico mide continuamente la distancia.
- El microcontrolador procesa los valores y decide el nivel de alerta.
- El sistema avisa con **patrones de sonido y color según la cercanía**.
- Permite visualizar en tiempo real el riesgo de colisión.

La finalidad es reproducir el comportamiento de un asistente de aparcamiento real, como los que llevan los vehículos modernos.

---

## 🔧 Componentes

### Sensores y actuadores

- 📡 Sensor ultrasónico **HC-SR04**
- 🔊 **Buzzer piezoeléctrico**
- 💡 LEDs (verde/amarillo/rojo) o **tira RGB** opcional

### Otros componentes

- 🔌 Arduino UNO o similar  
- 🧩 Protoboard  
- 🔗 Resistencias  
- 🔌 Cables Dupont  

---

## 📁 Contenido del repositorio

- `README.md`  
  - Objetivo  
  - Estado del proyecto  
  - Bitácora de desarrollo  
  - Explicación del funcionamiento  

- Carpeta `src/` o `arduino/`  
  - Código completo del sistema

- Carpeta `docs/`  
  - Esquema del circuito (Tinkercad o Fritzing)  
  - Capturas de las pruebas  
  - Registro de componentes

- Extras  
  - 📸 Fotos del montaje  
  - 🎥 Vídeo del sistema funcionando  

---

## 🚦 Estado Actual

**Sprint 1 — base funcional del sistema**

- 📡 Lectura estable del sensor ultrasónico  
- 🟢 Visualización por LEDs  
- 🔊 Control del buzzer según distancia  
- 🔧 Código inicial estructurado  

---

## 🗂️ Plan de trabajo (Sprints)

### 🟩 Sprint 1 — Detección de distancia (completado)

- Conexión del sensor HC-SR04  
- Lectura y filtrado de distancia  
- Envío de lectura por Serial  
- Pruebas iniciales con buzzer  

### 🟨 Sprint 2 — Señalización inteligente

- Intensidad de sonido según proximidad  
- Integración de LEDs de tres niveles  
- Esquema limpio para documentación  
- Pruebas con diferentes rangos

### 🟥 Sprint final — Demo y presentación

- Caja o soporte para el sensor  
- Material visual para exposición  
- Vídeo mostrando funcionamiento real  
- Presentación clara para evaluación  

---

## 📒 Bitácora de Trabajo

### 🗓️ 11/11 — Inicio del proyecto

- Definimos el objetivo: sistema de proximidad para aparcamiento.  
- Revisión de cómo funciona el sensor HC-SR04.  
- Leímos documentación de temporizado y ultrasonidos en Arduino.  
- Se estableció la estructura del repositorio.  

---

### 🗓️ 13/11 — Investigación técnica

- Estudio de rangos eficaces del sensor.  
- Simulación del circuito en Tinkercad/Fritzing.  
- Definimos niveles de alerta por distancia.  

**Pendiente:** pruebas de medición en físico.

---

### 🗓️ 18/11 — Montaje inicial en protoboard

- Cableado correcto del sensor y LEDs.  
- Primeras mediciones estables.  
- Debug vía Serial para validar lecturas.  

**Pendiente:** buzzer y alertas graduales.

---

### 🗓️ 20/11 — Lógica de respuesta

- Implementación de sonidos según distancia.  
- Ajuste del tiempo entre pitidos.  
- Primera integración de señalización luminosa.  

**Pendiente:** carcasa física / soporte.

---

### 🗓️ 25/11 — Optimización y pulido

- Filtrado de valores para evitar lecturas inestables.  
- Gestión de errores y límites mínimos/máximos.  
- Mejoras preparadas para la demo final.  

**Pendiente:** grabar vídeo + documentación final.

---

## 📌 Tareas Pendientes

- [ ] Soporte físico / diseño 3D opcional  
- [ ] Añadir efecto PWM o tiras RGB dinámicas  
- [ ] Subir vídeo demostrativo  
- [ ] Incluir esquemas en alta resolución  
- [ ] Documentación final para entrega  
