FROM ubuntu:trusty

USER root

# Update
RUN DEBIAN_FRONTEND=noninteractive apt-get update

# ARM compiler repository
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y software-properties-common python-software-properties 
RUN DEBIAN_FRONTEND=noninteractive add-apt-repository ppa:team-gcc-arm-embedded/ppa

# Update again
RUN DEBIAN_FRONTEND=noninteractive apt-get update

# Basic dev tools
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \ 
  vim \
  git \
  make \ 
  wget
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y man

# Other dependencies  
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \
  libc6 \
  libc6-i386 \
  Tk \
  gcc-arm-embedded \
  libgtk2.0-0 \
  usbutils

RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \
  libasound2 \ 
  libgconf-2-4 \
  libnspr4 \
  libnss3 \
  libnss3-tools \
  libcanberra0

RUN ln -s /lib/x86_64-linux-gnu/libudev.so.1 /lib/x86_64-linux-gnu/libudev.so.0

RUN DEBIAN_FRONTEND=noninteractive apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libnotify4 

# Ceedling and test framework
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y ruby-full
RUN DEBIAN_FRONTEND=noninteractive gem install ceedling

# MSP432 compiler support tools
COPY ./deps/msp432-gcc-1.1.0.1-linux-x64-support-package-installer.run /tmp/msp432-tools.run
RUN chmod a+x /tmp/msp432-tools.run
RUN /tmp/msp432-tools.run --prefix /usr/local/msp432-tools --mode unattended
RUN rm /tmp/msp432-tools.run

#MSP432 compiler support tools config
ENV DEVICE MSP432P401R
ENV GCC_BIN_DIR /usr/bin/
ENV GCC_INC_DIR /usr/arm-none-eabi/include
ENV PATH /usr/local/msp432-tools/emulation/common/uscif:$PATH
RUN chmod a+x /usr/local/msp432-tools/emulation/common/uscif/gdb_agent_console
ENV PATH /usr/local/msp432-tools/emulation/common/uscif/xds110:$PATH
RUN chmod a+x /usr/local/msp432-tools/emulation/common/uscif/xds110/xdsdfu

# Cleanup
RUN rm -r /tmp/*

# Enter command shell
CMD ["/bin/bash"]

