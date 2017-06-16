# Proyecto de Cubo que aprende a armarse solo, dependiendo de la experiencia
***Proyecto escolar como parte de la materia teoría de la sistemas inteligentes **
## Funcionamiento
El funcionamiento basico del trabajo se encuentra explicado a detalle en el documento <a href="https://github.com/juanunam/proyectoGraficacion/blob/master/explicacionTeorica.pdf">explicacionTeorica.pdf</a>
## Requisitos
- Instalar librerias opengl y glut
- Poder correr por terminal o cmd los comandos que vienen en la sección <b>Correr</b>
## Correr
### banderas para compilar
<code>g++ pruebaMain.cpp -lGLU -lGL -lglut -o pruebaMain </code>
### SOLO PARA INFORMACION DE COMO SE GENERARON LAS COORDENADAS DE CUBOS
<code> g++ generaCoordenadas.cpp -o generaCoordenadas </code>
### Para llenar el archivo de coordenadas
<code> ./generaCoordenadas > coordenadas.txt <code>
