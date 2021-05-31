FROM debian
COPY 7361LGV_lab4_1.cpp ./
COPY 7361LGV_lab4_2.cpp ./
RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y build-essential
RUN apt-get install -y procps

