################# stage 1:build ###########
#docker build -t sammywang/python-devel:centos7 .
FROM sammywang/centos7-devel:latest AS builder

# install deps
RUN yum -y update && yum -y install -y\
        graphviz \
	&& yum clean all

#install python deps
RUN python3 -m pip --no-cache-dir install --upgrade \
    pyflakes \
    requests \
    protobuf \
    h5py \
    keras_preprocessing \
    matplotlib \
    numpy \
    scipy \
    sklearn \
    pandas \
    xgboost \
    scikit-image \
    scikit-plot \
    seaborn \
    jieba \
    paddlepaddle-tiny \
    opencv-python \
    tensorflow \
    annoy \
    hnswlib \
    Jupyter \
    jupyterlab \
    nbdime \
    livelossplot \
    fastprogress \
    jupyter_nbextensions_configurator \
    jupyter_contrib_nbextensions \
    ipykernel 
#for pytorch
RUN python3 -m pip --no-cache-dir install --upgrade torch==1.4.0+cpu torchvision==0.5.0+cpu -f https://download.pytorch.org/whl/torch_stable.html

