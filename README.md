# Flight Path Optimization

## CS 225 Final Project:
### Siddarth Aananth, Vinit Gupta, Divyansh Jain, Akash Arunabharathi

<br>

# Project Description

As travel resumes in a world that is moving out of a pandemic, people are ever more conscious of the time they spend on all non-productive activities. Commute is one such activity. In order to allow people to focus on that which is most important w.r.t their purpose of travel, we aim to build a general search tool that allows people to easily minimize time spent on getting to and from their destinations. Using the dataset for OpenFlights, we will use a Shortest Path Algorithm for finding the shortest distances between two airports. Additionally, as a discovery tool, we will also allow users to find the most popular transit hubs servicing their end destinations.

View the demo as shown below to view our solution to the above question.

*Note: You can read more about the project in the project proposal file*

<br>
<br>

# Setting Up Project

### Cloning the repository
```
$ git clone https://github.com/aananth02/flight-path-optimization.git
```

**Note: This is done inside the cs225 repo i.e. inside the docker**

### Getting Compilation Setup using cmake
```
$ mkdir build
$ cd build
$ cmake ..
```

### Getting Python setup for ipynb file

*VS code packages for .ipynb files and python files must be installed inside environment*

### Check if Python is Working with
```
$ python3 --version
```

### Installing pip inside the linux environment

• This is needed to run the python commands in ipynb file

• pip is also needed to install packages

```
$ apt update
$ apt install python3-pip
```

<strong> or, if above command fails - </strong>

```
$ sudo apt update
$ sudo apt install python3-pip
```

### Installing Pandas with pip

```
$ pip install pandas
```

<br>
<br>

# Running Project

<strong>More information on the test cases and data is included below: </strong>

**Note: You need to be inside the build directory, else run:**
```
cd build
```

### Running Demo
```
$ make main
$ ./main
```

### Running Tests
```
$ make test
$ ./main
```

<br>
<br>

# Notes:

### File and Project Structure

**We have used a very conventional file structure**

* /src contains all the main source code and each file is the namesake of the code it contains
* /test contains all the test cases
* /data contains the dataset, cleaned dataset and smaller subset which we used for testing purposes
* /entry contains the main file, with the code for the demo
* /lib was created and has been configured with CMake, it is however not used and is inplace if required later for further development
* Several .md files contain information such as report, contract, and Project proposal
* Also have included file with link for video presentation above...

### Development and Testing information

**Note: Information on each function can be viewed in .h and .cpp file above in /src, we have included several comments to make the code more readable**

*View running command from the above...*

* Test cases while developing project: Tested Graphs implementation, Tested Data Extraction
* Test cases on completion: Tested ALL algorithms (along with usefull output to visualize mistakes if any)
* Note: Some of the testing has been done on a smaller dataset for visualization and runtime purposes
* *Ref. above included written report for more information on test-cases*


<br>
<br>

# Disclaimer:

### <strong>DataSet Cleaning</strong>:

*See the jupyter notebook file: for more details*

**Why we need to reduce data**

* The function is implemented in a manner that we do not need to do this, however, it is taking to long to run since we have 60K + routes

* Thus, we decided to create a cleaned data, which is easier to run

**How we cleaned it i.e. reduced the size**

* We did not want to make it a random process i.e. use a sample function

* Rather we decided to remove NA values

**Why this is not ideal**

* The data that we are removing does not make a great difference since CodeShare does not affect our code, however, it is good that we are removing other NA values

* This results in a smaller graph that is not representative of the data

**What can be done**

* For testing purposes so that the code runs faster we can use this cleaned dataset

* For real-world implementation we need to ensure that we use the enstire dataset as we have accounted for all edge cases anyways. While this would take time to run, it is the more correct and ideal implementation

**Note: To check with all routes data just change the path for routes data in main file, DISCLAIMER: will take a long time to run**

### <strong>Data Itself</strong>

* All the data used is from 2014, which is not upto date
* Data is not clean and has a lot of NULL / missing values


#
