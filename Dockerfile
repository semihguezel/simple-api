FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Gerekli paketlerin kurulumu
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    curl \
    libssl-dev \
    wget \
    libboost-all-dev \
    && rm -rf /var/lib/apt/lists/*

# Standalone Asio'yu indir ve kur
RUN wget https://github.com/chriskohlhoff/asio/archive/refs/tags/asio-1-24-0.tar.gz -O /tmp/asio.tar.gz && \
    tar -xzf /tmp/asio.tar.gz -C /tmp && \
    cp -r /tmp/asio-asio-1-24-0/asio/include/asio.hpp /usr/local/include/ && \
    cp -r /tmp/asio-asio-1-24-0/asio/include/asio /usr/local/include/ && \
    rm -rf /tmp/asio*

# Proje dosyalarının kopyalanması
COPY . /app
WORKDIR /app

# Uygulamanın derlenmesi
RUN mkdir build && cd build && cmake .. && make

EXPOSE 9080
CMD ["./build/simple_api"]
