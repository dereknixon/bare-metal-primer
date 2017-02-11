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

###Using the Docker image

The docker image can be used to build the project and run tests.

To run tests only

```bash
$> /src/embedded/C/msp432p401r/rake test:all
```

To run tests and prepare the final firmware image, run

```bash
$> /src/embedded/C/msp432p401r/rake
```

NOTE: The Docker image can *not* be used to load the firware image on the development board,
due to limitations with Docker to access USB devices attached to the host in some host environments.
In order to flash the firmware image to the development board, you will need to install and run
the [UniFlash](http://processors.wiki.ti.com/index.php/Category:CCS_UniFlash)  utility from TI on 
your host system.

The final image is `/src/embedded/C/msp432p401r/build/app.out

# Branches

### turn-on-led

This branch demonstrates turning on *LED1*

### flash-led-using-software-delay

Demonstrates turning on *LED1* and causing it to flash using a software based delay.   In addition, switch
*S1* will emulate a processing delay while pressed, in order to demonstrate how processing delays can effect
softare based timing.

