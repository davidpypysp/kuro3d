FROM ubuntu:18.04

RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y cmake

RUN apt-get install -y libgl1-mesa-dev
RUN apt-get install -y xorg-dev

ADD . /kuro3d
RUN rm -r /kuro3d/build && mkdir -p /kuro3d/build
WORKDIR /kuro3d/build
RUN cmake ..
RUN make -j4

# Replace 1000 with your user / group id
RUN export uid=1000 gid=1000 && \
	mkdir -p /home/developer && \
	echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
	echo "developer:x:${uid}:" >> /etc/group && \
	chown ${uid}:${gid} -R /home/developer
USER developer
ENV HOME /home/developer






CMD /kuro3d/build/src/kuro3d

