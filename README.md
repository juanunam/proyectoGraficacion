banderas para compilar
g++ pruebaMain.cpp -lGLU -lGL -lglut -o pruebaMain 
#SOLO PARA INFORMACION DE COMO SE GENERARON LAS COORDENADAS DE CUBOS
g++ generaCoordenadas.cpp -o generaCoordenadas
#Para llenar el archivo de coordenadas
./generaCoordenadas > coordenadas.txt
