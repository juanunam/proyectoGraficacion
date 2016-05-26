banderas para compilar
g++ pruebaMain.cpp -lGLU -lGL -lglut -o pruebaMain --std=c++11
g++ generaCoordenadas.cpp -o generaCoordenadas
#Para llenar el archivo de coordenadas
./generaCoordenadas > coordenadas.txt
