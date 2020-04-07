################# stage 1:build ###########
#docker build -t sammywang/ubuntu-python .
FROM sammywang/ubuntu-devel:latest AS builder

# prepare env
RUN apt-get update && apt-get install -y --no-install-recommends \
        graphviz \
    && apt-get clean -y \
    && apt-get autoremove -y \
    && rm -rf /var/lib/apt/lists/*

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

