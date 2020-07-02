FROM ubuntu

RUN apt-get update

RUN apt-get install build-essential  -y

RUN apt-get install wget -y

RUN apt-get install gcc -y

RUN apt-get install clang -y

RUN apt-get install g++ -y

RUN apt-get install libsfml-dev -y

COPY . /usr/robot2d/
WORKDIR /usr/robot2d/

# Сборка
RUN make

#Запуск
CMD ["./exec"]
