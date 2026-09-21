FROM ubuntu:24.04 AS builder

# Qt6 Core/Network i protobuf iz apt-a, reproducibilan build
# gui zavisnosti nisu potrebne (server je headless)
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        ninja-build \
        qt6-base-dev \
        protobuf-compiler \
        libprotobuf-dev 

WORKDIR /src
COPY . .

RUN cmake -S . -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_CLIENT=OFF \
        -DBUILD_SERVER=ON \
        -DBUILD_TESTS=OFF \
    && cmake --build build 

# seperate image to save space
FROM ubuntu:24.04 AS runtime

# Samo runtime biblioteke, bez kompajlera i hedera
RUN apt-get update && apt-get install -y --no-install-recommends \
        libqt6core6t64 \
        libqt6network6t64 \
        libprotobuf32t64 


WORKDIR /home/catan

# kopiramo builovan server iz proslog image-a
COPY --from=builder /src/build/appServer/Server /usr/local/bin/catan-server

ENTRYPOINT ["/usr/local/bin/catan-server"]
