FROM ubuntu:16.04

RUN apt-get update

RUN apt-get install build-essential  -y
RUN apt-get install wget -y
RUN apt-get install gcc -y
RUN apt-get install clang -y
RUN apt-get install g++ -y
RUN apt-get install libsfml-dev -y

RUN apt-get install -y cmake git libgtk2.0-dev pkg-config libavcodec-dev \
libavformat-dev libswscale-dev python-dev python-numpy libtbb2 libtbb-dev \
libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev unzip

RUN cd \
    && wget https://github.com/opencv/opencv/archive/3.2.0.zip \
    && unzip 3.2.0.zip \
    && cd opencv-3.2.0 \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make -j8 \
    && make install \
    && cd \
    && rm 3.2.0.zip

COPY . /usr/robot2d/
WORKDIR /usr/robot2d/

# Сборка
RUN make

#Запуск
CMD ["./exec"]
