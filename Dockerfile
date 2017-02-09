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
RUN DEBIAN_FRONTEND=noninteractive  apt-get install -y \ 
 vim \
 git \
 make \
 man \
 wget \
 libc6 \
 libc6-i386 \
 Tk \
 gcc-arm-embedded

# Ceedling and test framework
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y ruby-full
RUN DEBIAN_FRONTEND=noninteractive gem install ceedling

# MSP432 support tools
COPY ./deps/msp432-gcc-1.1.0.1-linux-x64-support-package-installer.run /tmp/msp432-tools.run
RUN chmod a+x /tmp/msp432-tools.run
RUN /tmp/msp432-tools.run --prefix /usr/local/msp432-tools --mode unattended
RUN rm /tmp/msp432-tools.run

#MSP432 support tools config
ENV DEVICE MSP432P401R
ENV GCC_BIN_DIR /usr/bin/
ENV GCC_INC_DIR /usr/arm-none-eabi/include
ENV PATH /usr/local/msp432-tools/emulation/common/uscif:$PATH
RUN chmod a+x /usr/local/msp432-tools/emulation/common/uscif/gdb_agent_console
ENV PATH /usr/local/msp432-tools/emulation/common/uscif/xds110:$PATH
RUN chmod a+x /usr/local/msp432-tools/emulation/common/uscif/xds110/xdsdfu
#RUN echo 'alias hi="echo hello"' >> ~/.bashrc

#Code Composer Studio
#COPY ./deps/CCS7.0.0.00043_linux-x64.tar.gz /tmp/CCS7.tar.gz
#RUN mkdir -p /tmp/CCS
#RUN wget -O /tmp/CCS/CCS7.tar.gz  http://software-dl.ti.com/ccs/esd/CCSv7/CCS_7_0_0/exports/CCS7.0.0.00043_web_linux-x64.tar.gz
#RUN tar -xvzf /tmp/CCS/CCS7.tar.gz -C /tmp/CCS
#RUN /tmp/CCS/ccs_setup_linux64_7.0.0.00043.bin --prefix /usr/local/ccs-7.0 --mode unattended --apps-select-all true

# Enter command shell
CMD ["/bin/bash"]

