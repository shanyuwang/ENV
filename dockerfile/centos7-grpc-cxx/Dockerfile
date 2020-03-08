################# stage 1:build ###########
#fork from  https://raw.githubusercontent.com/bryanayers/centos7-grpc-cxx/master/Dockerfile
FROM centos:7.5.1804 AS builder

MAINTAINER Sammy WANG <sammy.wsy@foxmail.com>

RUN yum -y update; yum clean all
RUN yum -y install epel-release
RUN \
	yum -y install \
		build-essential \
		autoconf \
		automake \
		pkg-config \
		curl \
		gcc \
		gcc-c++ \
		gflags-devel \
		git \
		glib2-devel \
		glibc-common \
		glibc-devel \
		gtest-devel \
		libtool \
		make \
		patch \
		unzip \
		wget \
		which \
		curl \
		xz-devel \
		zlib-devel \
		golang \
		cmake3 && \
	yum clean all

#RUN yum -y install yum-utils && yum clean all
#RUN yum -y groupinstall development && yum clean all
# Build grpc
#$(curl -L https://grpc.io/release)
ENV GRPC_RELEASE_TAG v1.27.3
#ENV GRPC_RELEASE_TAG $(curl -L https://grpc.io/release)

RUN git clone -b ${GRPC_RELEASE_TAG}  https://github.com/grpc/grpc.git /usr/local/src/grpc
RUN \
	cd /usr/local/src/grpc &&\
	git checkout tags/${GRPC_RELEASE_TAG} &&\
	git submodule update --init --recursive &&\
	echo "--- compile bugfix ---" && \
	wget https://raw.githubusercontent.com/shanyuwang/ENV/master/dockerfile/centos7-grpc-cxx/patch_for_urandom_test.cc && \
	cat ./third_party/boringssl/crypto/fipsmodule/rand/urandom_test.cc >> patch_for_urandom_test.cc  &&\
	mv -f ./patch_for_urandom_test.cc ./third_party/boringssl/crypto/fipsmodule/rand/urandom_test.cc &&\
	echo "--- compile grpc ---" && \
	mkdir -p cmake/build && \
	cd cmake/build && \
	cmake3 ../.. && \
	make && \
	echo "--- installing grpc ---" && \
	make install && \
	make clean && \
	cd /usr/local/src/ &&\
	rm -Rf grpc*

