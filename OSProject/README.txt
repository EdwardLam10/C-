/***************************************************************
Title: README.txt
Author: Edward Lam
Date Created: 12/10/2017
Class: FALL 2017, CSCI 340
Purpose: OS Project
***************************************************************/

MakeFile Instructions:

make all: creates all the files needed to run programs

make clean: rm all the files that were created by make all.

For the run functions there will be arguments passed in through the command line.
for example:
	"make run ram=200 page=2 hdd=4" 
	will run the program with 200bytes in RAM, each size/frame will be 2, and 4 HDDs.
	*Please note that the make run is space and case sensitive. There should not be any spaces between each =.
