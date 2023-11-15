// Team Project Data Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
* Project:
* Authors:
* Nova Thomas
* ________
* ________
* 
* Date Due: 11/20/2023
* 
* Simulation of a Linux Scheduler using Priority Queues
* Description:
* You are in possession of a program that's been parallelized and employs 𝑛 individual threads to tackle a given list of m jobs or tasks. 
* Threads operate on these tasks in the sequence they appear in the input. Whenever a thread becomes available, it promptly picks up the next job from the list. 
* Once a thread commences processing a job, it proceeds without interruption until the job reaches completion. 
* In cases where multiple threads vie for tasks from the list at the same time, the thread with the lower index takes precedence. 
* Each job comes with a precise processing time, which remains constant across all threads. 
* Your task involves determining both which threads will be responsible for processing each job and when that processing will commence.
*/

#include <iostream>
#include <thread>
#include <vector>
#include <fstream>

using namespace std;

// Function called in the creation of a thread object to handle the job given by the input in main
void threadFunction() {

}

int main()
{
	// Variables
	int n, m; // n number of threads, m number of jobs
	vector<long> times; // Using m as the index to match the job to the vector list of times
	string inputFileName;

	// Prompt for input file name

	// File input
	ifstream inputFile(inputFileName);

	// Checking if opened properly
	if (!inputFile.is_open()) {
		cerr << "Error opening the file." << endl;
		return 1;
	}

	// Read n and m from file
	inputFile >> n >> m;

	// Resizing the vector list accoring to input file
	times.resize(m);

	// Reading m time numbers from file and stores in vector
	for (int i = 0; i < m; i++) {
		inputFile >> times[i];
	}

	// Creating threads and feeding the input to the threads

	// Output of threads <---- maybe in thread function or nested in the creation of threads part?

	// Closing file
	inputFile.close();
}