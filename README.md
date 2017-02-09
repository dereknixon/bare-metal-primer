# bare-metal-primer
Concepts of embedded development

## MSP432P401R

This project uses the MSP432P401R development kit provided by [Texas Instruments](http://www.ti.com/tool/MSP-EXP432P401R)

## Docker 

[Docker](https://www.docker.com/) is used to provide easier setup of the development environment.  Additional information on installing 
Docker can be found [here](https://docs.docker.com/)

# Setup

From the root of the cloned repository...

###Build the Docker image

```bash
$> docker built -t <your_docker_image_name> .
```

Run the image to be dropped into a development command shell

```bash
$> docker run -it --rm -v `pwd`:/src <your_docker_image_name>
```

