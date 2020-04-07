################# stage 1:build ###########
#docker build -t sammywang/centos7-devel .
FROM centos:7.5.1804 AS builder

MAINTAINER Sammy WANG <sammy.wsy@foxmail.com>

RUN yum -y update; yum clean all
RUN yum -y install epel-release 
# install deps
RUN yum -y install -y\
        build-essential \
        curl \
        openssl \
        ca-certificates \
        git \
        patch \
        unzip \
        wget \
        which \
        gcc \
        gcc-c++ \
        make \
        autoconf \
        libtool \
        automake \
        pkg-config \
        cmake3 \
        openssl-devel \
        xz-devel \
        zlib-devel \
        gflags-devel \
        protobuf-devel \
        protobuf-compiler \
        leveldb-devel \
        snappy-devel \
        gperftools-devel \
        glibc-common \
        glib2-devel \
        glibc-devel \
        gtest-devel \
    && yum clean all
#for cmake3 -> cmake
RUN alternatives --install /usr/local/bin/cmake cmake /usr/bin/cmake3 20 \
    --slave /usr/local/bin/ctest ctest /usr/bin/ctest3 \
    --slave /usr/local/bin/cpack cpack /usr/bin/cpack3 \
    --slave /usr/local/bin/ccmake ccmake /usr/bin/ccmake3 \
    --family cmake
#RUN yum -y install yum-utils && yum clean all
#RUN yum -y groupinstall development && yum clean all
