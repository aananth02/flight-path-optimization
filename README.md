# Flight Path Optimization

## CS 225 Final Project:
### Siddarth Aananth, Vinit Gupta, Divyansh Jain, Akash Arunabharathi

<br>

# Project Description

<br>
<br>

# Setting Up Project

## Cloning the repository
```
$ git clone https://github.com/aananth02/flight-path-optimization.git
```

**Note: This is done inside the cs225 repo i.e. inside the docker**

## Getting Compilation Setup using cmake
```
$ mkdir build
$ cd build
$ cmake ..
```

## Getting Python setup for ipynb file

*VS code packages for .ipynb files and python files must be installed inside environment*

### Check if Python is Working with
```
$ python3 --version
```

## Installing pip inside the linux environment

• This is needed to run the python commands in ipynb file

• pip is also needed to install packages

```
$ apt update
$ apt install python3-pip
```

## Installing Pandas with pip

```
$ pip install pandas
```

<br>
<br>

# Running Project

**Note: You need to be inside the build directory, else run:**
```
cd build
```

## Running Demo
```
$ make main
$ ./main
```

## Running Tests
```
$ make test
$ ./main
```

<br>
<br>


## <strong>Notes and Disclaimers: