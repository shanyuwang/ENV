################# stage 1:build ###########
#docker build -t sammywang/python-devel:ubuntu .
FROM sammywang/ubuntu-devel:latest AS builder

# prepare env
RUN apt-get update && apt-get install -y --no-install-recommends \
        graphviz \
        nodejs \
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
    faiss-cpu \
    annoy \
    hnswlib \
    Jupyter \
    jupyterlab \
    nbdime \
    livelossplot \
    fastprogress \
    jupyter_nbextensions_configurator \
    jupyter_contrib_nbextensions \
    ipykernel \
    flask

#for pytorch
RUN python3 -m pip --no-cache-dir install --upgrade torch==1.4.0+cpu torchvision==0.5.0+cpu -f https://download.pytorch.org/whl/torch_stable.html

#for jupyter,password=notebook
ARG jupyter_password="sha1:a077f3f98e9b:c5c8fff0cfca7d3a74d08a37558f5e0c3f4757d2"
RUN jupyter nbextensions_configurator enable --sys-prefix \
        && jupyter contrib nbextension install --sys-prefix \
        && jupyter notebook --generate-config \
        && echo "c.NotebookApp.password = u\"${jupyter_password}\"" >> /root/.jupyter/jupyter_notebook_config.py \
        && echo -e '#!/bin/bash\njupyter notebook --ip 0.0.0.0 --no-browser --allow-root --port=8080 --notebook-dir=./ $*' > /root/start_jupyter.sh \
        && chmod +x /root/start_jupyter.sh

