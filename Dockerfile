FROM ubuntu:xenial

# Ruby
RUN apt-get update

RUN apt-get install -y ruby-full

RUN apt-get install -y vim git

RUN gem install ceedling

CMD /bin/bash

