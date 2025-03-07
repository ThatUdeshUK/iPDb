FROM ubuntu
    
RUN apt update
RUN apt-get install build-essential -y
RUN apt-get install wget unzip curl cmake make git ninja-build g++ python3 -y

WORKDIR /root/temp
RUN mkdir /root/utf8proc
RUN wget https://github.com/JuliaStrings/utf8proc/archive/refs/tags/v2.10.0.tar.gz
RUN tar -xvf v2.10.0.tar.gz && mv utf8proc-2.10.0 utf8proc
RUN cd utf8proc && \
    mkdir build && \
    cmake -S . -B build && \
    cmake --build build && \
    make prefix="/root/utf8proc" install

WORKDIR /root/temp
RUN rm -rf /root/onnxruntime && mkdir /root/onnxruntime
RUN wget https://github.com/microsoft/onnxruntime/releases/download/v1.19.2/onnxruntime-linux-x64-1.19.2.tgz
RUN tar -xvf onnxruntime-linux-x64-1.19.2.tgz && mv onnxruntime-linux-x64-1.19.2/* /root/onnxruntime/

WORKDIR /root
RUN rm -rf /root/temp

WORKDIR /root/duckml
COPY . .

RUN make clean
RUN export ONNX_INSTALL_PREFIX="/root/onnxruntime" && export UTF8PROC_INCLUDE_DIRS="/root/utf8proc" && make debug GEN=ninja DISABLE_SANITIZER=1 ENABLE_PREDICT=1 USE_TORCH=0
