FROM ubuntu:latest

RUN apt-get update && apt-get install -y
RUN apt-get -y install g++
RUN apt-get -y install make
RUN apt-get -y install mosquitto
RUN apt-get -y install mosquitto-clients
RUN apt-get install libmosquitto-dev
RUN apt-get install -y git
RUN apt-get -y install tmux
RUN apt -y install vim
     

RUN git clone https://github.com/bairdob/MaximovArchitectureIS.git
#Set working directory
WORKDIR /MaximovArchitectureIS/PZ4/example
RUN make 

CMD ["/bin/bash"]