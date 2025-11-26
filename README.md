# 🚗 Sistema de Asistencia de Aparcamiento por Proximidad (Arduino)

## 👥 Integrantes

- **Marcos**
- **Fernando** 

---

## 🎯 Propósito del Proyecto

Desarrollar un **asistente de aparcamiento basado en distancia**, usando un **sensor ultrasónico HC-SR04** para calcular la proximidad a un obstáculo y un **buzzer junto con LEDs indicadores** para mostrar el nivel de alerta al usuario.

El comportamiento del sistema dependerá de la distancia detectada:

| Distancia | Indicador | Respuesta |
|----------|-----------|-----------|
| 🟢 Lejana / segura | LED verde | Sin señal sonora |
| 🟡 Media / alerta | LED amarillo | Pitidos pausados |
| 🔴 Muy cercana / riesgo | LED rojo | Pitidos rápidos y continuos |

El objetivo es imitar un asistente real de parking, sencillo pero completamente funcional.

---

## 📝 Funcionamiento General

- El HC-SR04 realiza lecturas constantes de distancia.  
- Arduino interpreta los valores recibidos y define el nivel de riesgo.  
- El sistema responde con iluminación y sonido según la cercanía del objeto.  
- Proporciona una retroalimentación en tiempo real para evitar choques al aparcar.

---

## 🔧 Material Utilizado

### Sensores / Salidas

- 📡 HC-SR04 — Distancia por ultrasonidos  
- 🔊 Buzzer piezoeléctrico  
- 💡 LEDs verde/amarillo/rojo (o RGB como alternativa)

### Otros componentes necesarios

- Arduino UNO o equivalente  
- Protoboard  
- Resistencias  
- Cables Dupont  

---

## 📁 Estructura del Repositorio

- `README.md` → Documentación principal  
- `/src` o `/arduino` → Código fuente del sistema  
- `/docs` → Planos, esquemas electrónicos e imágenes  
- `/media` *(opcional)* → Fotografías del montaje + vídeos de funcionamiento  

---

## 🚦 Progreso Actual

**Fase inicial completada:**

- Lectura estable del sensor ultrasónico  
- LED indicador integrado  
- Control del buzzer en función de la distancia  
- Código base funcionando en protoboard  

---

## 🗂️ Planificación por Fases

### Etapa 1 — Lectura de distancia (Finalizada)

- Conexión del HC-SR04  
- Lecturas procesadas mediante Serial  
- Pruebas iniciales de medición  
- Revisión de estabilidad de señal

### Etapa 2 — Sistema de alertas

- Añadir respuesta acústica progresiva  
- Relación LED-distancia mejor definida  
- Documentación del circuito  
- Pruebas en entorno más realista

### Etapa final — Presentación y mejora visual

- Montaje limpio o carcasa para sensor  
- Material visual para exposición  
- Vídeo explicativo  
- Ajuste fino de distancias umbral  

---

## 📒 Registro de Desarrollo

### 11/11 — Propuesta y bases iniciales
- Se plantea el sistema de parking con medición por ultrasonidos.  
- Revisión de funcionamiento del HC-SR04.  
- Primer esquema conceptual y estructura del repositorio.

---

### 13/11 — Investigación y planificación
- Lectura técnica del sensor y tiempos de respuesta.  
- Simulación previa del circuito.  
- Diseño preliminar de los niveles de alerta.



---

### 18/11 — Montaje básico
- Conexión del sensor y LEDs.  
- Validación de lectura estable en monitor Serial.  
- Primera interacción LED-distancia.



---

### 20/11 — Señales acústicas
- Buzzer implementado con cambios de frecuencia.  
- Ajuste de retardos y umbrales de alarma.  
- Respuesta combinada luz + sonido operativa.

---

### 25/11 — Mejoras y pulido
- Reducción de fluctuación en lecturas.  
- Se añaden márgenes de seguridad.  
- Sistema listo para fase demostrativa.

