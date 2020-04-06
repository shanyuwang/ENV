################# stage 1:build ###########
#docker build -t sammywang/centos7-brpc-cxx .
FROM sammywang/centos7-devel:latest AS builder

######################
# Build grpc
#ENV BRPC_RELEASE_TAG 0.9.6
#ENV BRPC_RELEASE_TAG 0.9.7-rc03
ENV BRPC_RELEASE_TAG master

WORKDIR /root

RUN git clone -b ${BRPC_RELEASE_TAG} https://github.com/shanyuwang/incubator-brpc.git brpc && \
	cd brpc && \
	git submodule update --init --recursive &&\
	echo "--- compile brpc ---" && \
	sh config_brpc.sh --headers=/usr/include --libs=/usr/lib64 && \
    make  && \
	echo "--- output ---" && \
	cp -r output /brpc && \
	cd .. && rm -rf brpc
	#mkdir bld && cd bld && cmake .. && make
	#git checkout tags/${BRPC_RELEASE_TAG} &&\

