################# stage 1:build ###########
#docker build -t sammywang/ubuntu-devel .
ARG UBUNTU_VERSION=18.04

FROM ubuntu:${UBUNTU_VERSION} AS builder

MAINTAINER Sammy WANG <sammy.wsy@foxmail.com>

# prepare env
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        apt-utils \
        curl \
        openssl \
        ca-certificates \
        git \
        patch \
        unzip \
        zip \
        wget \
        less \
        gcc \
        g++ \
        make \
        autoconf \
        libtool \
        pkg-config \
        cmake \
        libssl-dev \
        xz-utils \
        zlib1g-dev \
        libgflags-dev \
        libprotobuf-dev \
        libprotoc-dev \
        protobuf-compiler \
        libleveldb-dev \
        libsnappy-dev \
        libgoogle-perftools-dev \
        libgtest-dev \
        python3 \
        python3-dev \
        python3-pip \
        python3-setuptools \
    && apt-get clean -y \
    && apt-get autoremove -y \
    && rm -rf /var/lib/apt/lists/*

#install python deps
RUN python3 -m pip --no-cache-dir install --upgrade pip
RUN python3 -m pip --no-cache-dir install --upgrade \
    setuptools \
    Cython 
RUN rm -f /usr/bin/python ; ln -s $(which python3) /usr/bin/python
