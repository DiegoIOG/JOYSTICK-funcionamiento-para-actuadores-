# JOYSTICK ACTIVADOR DE DE LASER Y LED

## Objetivo
El objetivo del proyecto es poder hacer que mediante un joystick se puedan enviar señales a diferentes actuadores como lo son el LED, el laser de esta manera activando estos se puede inferir lo que esta haciendo un operador, en el caso del uso en las industrias como  indicadores visuales y sistemas de alarma.


## Funcionalidad

-JOYSTICK se mueve a la derecha se envia señal al led VERDE
-JOYSTICK se mueve a la derecha se envia señal al led ROJO
-JOYSTICK se mueve a la abajo se envia señal al led relé se activa el laser , tambien se activa el led azul
-JOYSTICK se mueve a la arriba se desactiva el relé por ende el  laser
-JOYSTICK se presiona se activa el RGB dando un color blanco 

## Componentes utilizados 
-KY-016 RGB LED
-KY-019 RELE
-KY-023 JOYSTICK
-KY-008 LASER
-Protoboard
-Arduino UNO
-Cables

## Conexiones 
-RGB LED
~9   | R
~10  | G
~11  | B
GND  | -
-RELE
GND  | -
5V   | +
8    | S
5V   | COMUN
-JOYSTICK
2    | SW
A1   | VRy
A0   | VRx
5V   | +5V
GND  | GND
-LASER
GND  | - 
NO   | S 


## Foto del circuito
![CIRCUITO](https://github.com/user-attachments/assets/ed0d050f-6d37-45f5-9e80-a09836929824)



## Serial Monitor 
<img width="566" height="681" alt="Serial_monitor" src="https://github.com/user-attachments/assets/9c4e6bf3-2761-43f3-a126-63da6f7d3d9a" />



## Video del funcionamiento 

https://youtube.com/shorts/rDp0okvKE4s?feature=share 
