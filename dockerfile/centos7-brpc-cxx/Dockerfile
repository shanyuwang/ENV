################# stage 1:build ###########
#docker build -t sammywang/centos7-brpc-cxx .
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
		gcc \
		gcc-c++ \
		make \
		autoconf \
		libtool \
		automake \
		pkg-config \
		openssl-devel \
		gflags-devel \
        protobuf-devel \
		protobuf-compiler \
		leveldb-devel \
		snappy-devel \
		gperftools-devel \
		glibc-common \
		glib2-devel \
		glibc-devel \
		patch \
		unzip \
		wget \
		which \
		xz-devel \
		zlib-devel \
		cmake3 && \
	yum clean all
#for cmake3 -> cmake
RUN alternatives --install /usr/local/bin/cmake cmake /usr/bin/cmake3 20 \
	--slave /usr/local/bin/ctest ctest /usr/bin/ctest3 \
	--slave /usr/local/bin/cpack cpack /usr/bin/cpack3 \
	--slave /usr/local/bin/ccmake ccmake /usr/bin/ccmake3 \
	--family cmake
#RUN yum -y install yum-utils && yum clean all
#RUN yum -y groupinstall development && yum clean all
######################
# Build grpc
#ENV BRPC_RELEASE_TAG 0.9.6
ENV BRPC_RELEASE_TAG 0.9.7-rc03

WORKDIR /usr/local/src/

RUN git clone -b ${BRPC_RELEASE_TAG} https://github.com/apache/incubator-brpc.git brpc && \
	cd brpc && \
	git checkout tags/${BRPC_RELEASE_TAG} &&\
	git submodule update --init --recursive &&\
	echo "--- compile brpc ---" && \
	sh config_brpc.sh --headers=/usr/include --libs=/usr/lib64 && \
    make  && \
	echo "--- output ---" && \
	cp -r output /brpc && \
	cd .. && rm -rf brpc
	#mkdir bld && cd bld && cmake .. && make

