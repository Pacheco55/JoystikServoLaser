# Sistema de Control Láser con Servomotores - PIXELBITS Edition

![Arduino](https://img.shields.io/badge/Arduino-NANO-blue)
![Servo](https://img.shields.io/badge/Motors-SG90-green)
![Laser](https://img.shields.io/badge/Control-Laser-red)
![License](https://img.shields.io/badge/License-MIT-yellow)
![Live](https://img.shields.io/badge/Created%20Live-Twitch-purple)

**Sistema de control láser automatizado con precisión milimétrica y control interactivo en tiempo real**

*Una innovadora plataforma de control desarrollada en vivo para Twitch por PIXELBITS Studios, que combina la precisión de servomotores industriales SG90 con la versatilidad de control manual mediante joystick y funciones automatizadas inteligentes para crear espectáculos láser personalizables.*

---

## **¿Por qué elegir nuestro Sistema de Control Láser?**

En el mundo del entretenimiento tecnológico y las aplicaciones industriales de precisión, **el control exacto de haces láser** es fundamental. Este sistema no es solo un proyecto educativo, es una **plataforma completa de control láser** que ofrece tanto operación manual intuitiva como automatización programable para crear efectos visuales impresionantes.

### **Características Revolucionarias**

**Control de Precisión Dual**
Movimiento independiente en ejes X e Y mediante servomotores SG90 de alta precisión, rango completo de 180 grados en ambos ejes, mapeo directo entre joystick analógico y posición de servomotores y respuesta en tiempo real con latencia mínima de 20ms.

**Sistema de Retroalimentación Visual**
Indicadores LED RGB que reflejan la posición del joystick en tiempo real, LED indicador central para posición neutra (zona muerta), indicadores de extremos con LEDs azul y verde y retroalimentación inmediata del estado del sistema.

**Modos de Operación Inteligentes**
Control manual preciso mediante joystick analógico, activación/desactivación del láser con botón integrado del joystick, modo aleatorio para patrones automáticos y monitoreo serial para debugging y calibración.

**Construcción Robusta y Modular**
Diseño optimizado para Arduino NANO, componentes de calidad industrial, conexiones claramente documentadas y estructura de código modular para fácil expansión.

---

## **Especificaciones Técnicas del Sistema**

### **Hardware Requerido**

**Controlador Principal**
Arduino NANO (recomendado R3 con ATmega328P)

**Actuadores de Precisión**
2x Servomotores SG90 (180 grados, 4.8-6V), torque: 2.5kg/cm, velocidad: 0.1s/60°

**Sistema Láser**
Diodo láser (3-5V, recomendado 5mW para seguridad), soporte de montaje ajustable

**Interfaz de Control**
Joystick analógico de 2 ejes con pulsador integrado, botón adicional para función aleatoria

**Sistema de Retroalimentación**
LED RGB (cátodo común), LED ámbar indicador, 4x resistencias 10kΩ para pull-up

**Alimentación**
Fuente 5V 2A mínimo para Arduino y servomotores, conexión USB para programación

### **Diagrama de Conexiones Específicas**

#### **Servomotores SG90**
```
Servo X (Eje Horizontal):
  Pin 9 Arduino → Señal PWM Servo X
  5V Arduino → VCC Servo X  
  GND Arduino → GND Servo X

Servo Y (Eje Vertical):
  Pin 7 Arduino → Señal PWM Servo Y
  5V Arduino → VCC Servo Y
  GND Arduino → GND Servo Y
```

#### **Joystick Analógico**
```
Pin A0 (Analógico) → Eje X del Joystick
Pin A1 (Analógico) → Eje Y del Joystick  
Pin 3 (Digital) → Pulsador del Joystick (INPUT_PULLUP)
5V Arduino → VCC Joystick
GND Arduino → GND Joystick
```

#### **Sistema Láser y Control**
```
Pin 13 (Digital) → Diodo Láser (con resistencia limitadora)
Pin 8 (Digital) → Botón Random (INPUT_PULLUP)
GND Arduino → GND común
```

#### **Sistema de Indicadores LED**
```
Pin 4 (Digital) → LED Azul (indicador extremo izquierdo/inferior)
Pin 5 (Digital) → LED Verde (indicador extremo derecho/superior)  
Pin 6 (Digital) → LED Ámbar (indicador posición central)
GND Arduino → Cátodo común LEDs (con resistencias 220Ω)
```

#### **Resistencias Pull-up Externas**
```
4x Resistencias 10kΩ:
- Joystick Switch → 5V
- Botón Random → 5V  
- Reserva para expansiones futuras
```

### **Software y Dependencias**

#### **Arduino IDE Setup**

**Descargar Arduino IDE** (Versión 1.8.13 o superior)
[Descarga oficial](https://www.arduino.cc/en/software)

**Configuración para Arduino NANO**
```
Tools → Board → Arduino AVR Boards → Arduino Nano
Tools → Processor → ATmega328P (Old Bootloader si es necesario)
Tools → Port → [Seleccionar puerto COM correspondiente]
```

#### **Librerías Requeridas**

**Servo.h**
Librería estándar incluida con Arduino IDE para control de servomotores. Proporciona funciones `attach()`, `write()` y `read()` para gestión completa de servos.

**Librerías del Sistema**
Todas las demás funciones utilizan librerías estándar de Arduino: `analogRead()`, `digitalRead()`, `digitalWrite()`, `map()`, `random()`, `delay()`.

---

## **Instalación y Configuración**

### **Preparación del Hardware**

**Paso 1: Montaje Mecánico**
Monta los servomotores en una base estable formando un sistema de cardán (gimbal) con el eje X controlando movimiento horizontal y el eje Y controlando inclinación vertical. Fija el diodo láser al servo Y para movimiento completo en ambos planos.

**Paso 2: Conexiones Eléctricas**
Realiza todas las conexiones según el diagrama específico proporcionado. Verifica continuidad con multímetro antes de alimentar. Usa protoboard o PCB para conexiones permanentes.

**Paso 3: Calibración Inicial**
Centra manualmente ambos servomotores en posición 90°. Verifica que el joystick esté en posición neutra. Confirma que todos los LEDs respondan correctamente.

### **Instalación del Software**

**Paso 1: Preparar el entorno**
```bash
# Descargar e instalar Arduino IDE
# Configurar drivers para Arduino NANO
# Verificar comunicación serial a 9600 baud
```

**Paso 2: Carga del código**
```cpp
#include <Servo.h>
// El código completo está optimizado y listo para usar
// No requiere modificaciones para funcionamiento básico
```

**Paso 3: Verificación del sistema**
Abre el Monitor Serial (9600 baud) para observar valores en tiempo real del joystick. Verifica movimiento suave de ambos servomotores. Confirma activación correcta del láser mediante el botón del joystick.

---

## **Manual de Operación**

### **Controles Básicos**

**Control Manual del Láser**
Mueve el joystick horizontalmente para controlar el servo X (movimiento horizontal del láser). Mueve el joystick verticalmente para controlar el servo Y (movimiento vertical del láser). Los servomotores responden instantáneamente con mapeo directo 1:1.

**Activación del Láser**
Presiona el botón integrado del joystick para alternar encendido/apagado del diodo láser. El estado se mantiene hasta la siguiente pulsación. Ideal para crear patrones intermitentes o puntos de referencia.

**Modo Aleatorio**
Presiona el botón Random (pin 8) para activar movimiento automático. El sistema genera ángulos aleatorios entre 0-180° para ambos servos. Mantiene la posición durante 2 segundos antes de permitir nueva activación.

### **Sistema de Retroalimentación LED**

**Indicadores de Posición**
LED Azul se activa cuando el joystick está en extremo izquierdo o inferior (valores ≤100). LED Verde se activa en extremo derecho o superior (valores ≥800). LED Ámbar indica posición central neutra (valores 400-500).

**Monitor Serial**
El sistema envía continuamente valores en formato: "X: [valor] Y: [valor] SW: [estado]". Útil para calibración, debugging y monitoreo de rendimiento del sistema.

### **Rangos de Operación**

**Joystick Analógico**
Rango de entrada: 0-1023 (resolución 10-bit), mapeo a servomotores: 0-180 grados, zona muerta central: 400-500 para estabilidad

**Servomotores SG90**
Rango angular: 0-180 grados, resolución: aproximadamente 0.5 grados, tiempo de respuesta: 20ms por actualización

---

## **Características Técnicas Avanzadas**

### **Algoritmos de Control**

**Mapeo Proporcional**
Utiliza la función `map()` de Arduino para conversión lineal directa entre valores analógicos del joystick (0-1023) y ángulos de servo (0-180°). Proporciona control intuitivo y preciso.

**Detección de Estados**
Implementa detección de flancos para botones, evitando activaciones múltiples. Variables de estado (`joyswestado`, `btnRandomEstado`) garantizan respuesta única por pulsación.

**Generación Aleatoria**
Función `random(0, 180)` para patrones automáticos impredecibles. Ideal para demostraciones, pruebas de rango completo y efectos visuales dinámicos.

### **Optimización de Rendimiento**

**Gestión de Delays**
Delays optimizados: 20ms para servos (evita sobrecarga), 100ms para debounce de botones, 10ms para LEDs (respuesta visual rápida), 2000ms para patrones aleatorios.

**Uso Eficiente de Pines**
Aprovecha capacidades analógicas del NANO (A0, A1), utiliza pines digitales para control directo, implementa INPUT_PULLUP para reducir componentes externos.

**Estructura Modular**
Funciones separadas para cada subsistema: `joylectura()`, `joyswfunction()`, `joyXmove()`, `joyYmove()`, `MovimientoRandom()`. Facilita mantenimiento y expansión.

### **Monitoreo y Debugging**

**Telemetría Serial**
Transmisión continua de estados en formato tabular legible. Incluye valores X, Y del joystick y estado del pulsador. Baud rate 9600 para compatibilidad universal.

**Indicadores Visuales Múltiples**
Sistema LED triple proporciona retroalimentación inmediata sin depender de monitor serial. Útil para operación independiente o demostraciones.

---

## **Aplicaciones del Sistema**

### **Entretenimiento y Espectáculos**

**Shows Láser Personalizados**
Creación de patrones geométricos precisos, efectos visuales sincronizados con música, presentaciones interactivas en vivo y demostraciones educativas de óptica.

**Streaming y Contenido Digital**
Perfecto para streams de Twitch como el original de PIXELBITS Studios, contenido educativo de YouTube, demostraciones técnicas en vivo y proyectos de maker spaces.

### **Aplicaciones Educativas**

**Enseñanza de Robótica**
Introducción a servomotores y control de posición, programación de sistemas embebidos, conceptos de retroalimentación y control, integración de múltiples sensores y actuadores.

**Proyectos Universitarios**
Sistemas de control automático, interfaces humano-máquina, programación en tiempo real y diseño de sistemas mecatrónicos.

### **Aplicaciones Industriales**

**Prototipado de Sistemas de Apuntado**
Base para sistemas de tracking solar, plataformas de comunicación satelital, sistemas de apuntado láser industrial y control de cámaras automatizadas.

**Calibración y Alineación**
Herramienta de alineación para equipos ópticos, calibración de sistemas de medición, verificación de precisión mecánica y testing de componentes.

---

## **Expansiones y Mejoras**

### **Mejoras de Hardware**

**Sistema de Alimentación Mejorado**
Regulador de voltaje dedicado para servomotores, filtros de alimentación para reducir ruido, indicadores de estado de alimentación y protección contra sobrecorriente.

**Sensores Adicionales**
Encoders para retroalimentación de posición real, sensores de temperatura para protección térmica, acelerómetros para estabilización automática y sensores de proximidad para límites de seguridad.

---

## **Seguridad y Consideraciones Legales**

### **Seguridad del Láser**

**Clasificación y Potencia**
Usa únicamente láseres Clase 1 o 2 (≤1mW) para aplicaciones recreativas. Láseres de mayor potencia requieren certificación y equipo de protección. Nunca apuntes directamente a personas, vehículos o aeronaves.

**Protección Ocular**
Usa gafas de protección láser apropiadas para la longitud de onda utilizada. Mantén el sistema en área controlada durante operación. Incluye señalización de advertencia visible.

### **Regulaciones Locales**

**Uso Recreativo**
Verifica regulaciones locales sobre uso de láseres. Algunos países requieren licencias para láseres >1mW. Respeta normativas de protección radiológica.

**Uso en Espectáculos**
Para aplicaciones profesionales, consulta autoridades competentes. Requiere análisis de riesgo y planes de seguridad. Considera seguros de responsabilidad civil.

---

## **Resolución de Problemas**

### **Problemas de Hardware**

**Servomotores no responden**
Verifica alimentación de 5V estable con al menos 1A disponible. Comprueba conexiones PWM en pines 7 y 9. Confirma que los servos no estén físicamente bloqueados.

**Joystick da lecturas erráticas**
Limpia contactos del joystick con alcohol isopropílico. Verifica conexiones en pines A0 y A1. Considera filtros capacitivos si persiste el ruido.

**LEDs no funcionan correctamente**
Verifica polaridad de LEDs (ánodo a pin digital, cátodo a GND). Confirma resistencias limitadoras (220Ω recomendado). Comprueba continuidad de conexiones.

### **Problemas de Software**

**Movimiento irregular de servos**
Ajusta delays en funciones de movimiento si es necesario. Verifica que la alimentación sea estable durante picos de corriente. Considera filtros de alimentación.

**Botones no responden**
Confirma configuración INPUT_PULLUP en setup(). Verifica que las resistencias pull-up estén conectadas. Ajusta delays de debounce si es necesario.

**Monitor Serial sin datos**
Verifica baud rate 9600 en monitor serial. Confirma que el cable USB transmita datos (no solo alimentación). Reinicia Arduino si persiste el problema.

---

## **Especificaciones de Rendimiento**

### **Precisión del Sistema**

**Resolución Angular**
Servomotores SG90: ~0.5° de resolución práctica, joystick analógico: 10-bit (1024 posiciones), mapeo lineal directo sin pérdida de precisión

**Velocidad de Respuesta**
Actualización de posición: 20ms (50Hz), respuesta de LEDs: 10ms, debounce de botones: 100ms, patrones aleatorios: 2 segundos de duración

**Rango de Operación**
Movimiento angular: 0-180° en ambos ejes, voltaje de operación: 4.8-6V, corriente máxima: 500mA por servo bajo carga

### **Consumo Energético**

**Componentes Individuales**
Arduino NANO: ~20mA, servomotores en reposo: ~10mA c/u, servomotores en movimiento: ~200-500mA c/u, LEDs: ~20mA total, láser: ~30-100mA según modelo

**Consumo Total del Sistema**
Reposo: ~80mA (sin láser), operación normal: ~300-600mA, picos durante movimiento: hasta 1.2A

---

## **Historia del Proyecto**

### **Desarrollo en Vivo**

**Transmisión Original**
Desarrollado completamente en vivo durante stream de Twitch de PIXELBITS Studios el 21 de febrero de 2025 a las 9:51 PM. La audiencia participó en tiempo real sugiriendo mejoras y funcionalidades.

**Evolución del Código**
El código se desarrolló de forma iterativa durante la transmisión, comenzando con control básico de servomotores y agregando progresivamente funcionalidades avanzadas como modo aleatorio e indicadores LED.

**Interacción con la Comunidad**
Los espectadores de Twitch contribuyeron con ideas para mejoras, testing en tiempo real de funcionalidades y feedback sobre la experiencia de usuario.

---

## **Contribuir al Proyecto**

### **Reportar Mejoras**

Comparte tus modificaciones del código original, documenta nuevas funcionalidades implementadas, reporta problemas encontrados durante construcción y sugiere mejoras de seguridad o rendimiento.

### **Expansiones de la Comunidad**

Desarrolla nuevos patrones de movimiento automático, crea interfaces de control alternativas, implementa funciones de seguridad adicionales y comparte aplicaciones innovadoras del sistema.

---

## **Créditos**

### **Desarrollo Principal**

**PIXELBITS Studios**
*Innovación en tecnología embebida*
*Especialistas en IoT y sistemas de monitoreo*

### **Lead Developer**

**Pacheco 55**
*Arquitecto de software y especialista en Microcontroladores*
*Experto en protocolos de comunicación inalámbrica*

---

## **Licencia**

Este proyecto está licenciado bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

---

## **¡Apóyanos!**

Si este proyecto te ha sido útil:

Dale una estrella al repositorio, compártelo con otros developers, déjanos tus comentarios y contribuye al proyecto.

---

<div align="center">

### **Hecho con amor por PIXELBITS Studios**

*Transformando ideas en código, un ESP32 a la vez.*

**[Instagram](https://www.instagram.com/pixelbits_studios/) | [YouTube](https://www.youtube.com/channel/UCkLUjIeYTECtigFdcQjWu5Q) | [Twitter](https://x.com/pixelbitstud) | [Twitch](https://www.twitch.tv/pixelbits_studio/about)**

---

*Sistema de Control Láser - Porque la precisión y creatividad van de la mano.*

</div>
