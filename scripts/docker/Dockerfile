# sudo setenforce Permissive
# sudo systemctl start docker
# # See https://www.youtube.com/watch?v=YFl2mCHdv24

########################################################################################################################

FROM ubuntu:18.04
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y git autoconf automake make \
                       gcc g++ mcpp \
                       python python3 openjdk-8-jdk \
                       flex bison \
                       sqlite libsqlite-dev sqlite3 libsqlite3-dev \
                       zlib1g zlib1g-dev \
                       doxygen libncurses5-dev libtool libffi-dev wget python3-matplotlib graphviz gnupg2 \
                       task-spooler procps passwd openssh-server vim curl 

RUN cd root; \
    wget -c https://github.com/Z3Prover/z3/archive/z3-4.8.6.tar.gz; \
    tar -xf z3-4.8.6.tar.gz; \
    cd z3-z3-4.8.6; \
        mkdir -p /usr/local/lib/python3.6/dist-packages; \
        python scripts/mk_make.py --python --pypkgdir=/usr/local/lib/python3.6/dist-packages; \
        cd build; \
            make -j 8; \
            make install

RUN pip install networkx

RUN git clone https://github.com/jt0202/DatalogLearning && \
    ./DatalogLearning/scripts/build.sh && \
	cd DatalogLearning/prosynth
CMD ./scripts/main.py

########################################################################################################################

# sudo docker build -t IMAGE_NAME .
# sudo docker images
# sudo docker run -it IMAGE_NAME /bin/bash

########################################################################################################################

# sudo docker images
# sudo docker rmi IMAGE_NAME
# sudo docker images
