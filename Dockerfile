FROM ubuntu:xenial

# Ruby
RUN apt-get update
RUN apt-get install -y ruby-full
CMD echo "Hello"

