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
#include <algorithm>
#include <fstream>

using namespace std;

// Function called in the creation of a thread object to handle the job given by the input in main
vector<pair<int, int>> parallelizeJobs(int n, int m, const vector<int>& processingTime) {
	
    vector<int> threadTime(n, 0); // initialize starting times for each thread
    vector<pair<int, int>> jobSchedule;

    for (int i = 0; i < m; ++i) {
        int currentJobTime = processingTime[i];
        auto minThreadIndex = min_element(threadTime.begin(), threadTime.end()) - threadTime.begin();
        jobSchedule.push_back(make_pair(minThreadIndex, threadTime[minThreadIndex])); // record job schedule
        threadTime[minThreadIndex] += currentJobTime;
    }
    return jobSchedule;
}

int main() 
{
    // Variables
    int n, m; // n number of threads, m number of jobs
    vector<int> times; // Using m as the index to match the job to the vector list of times
    string inputFileName;

    // Prompt for input file name
    cout << "Enter the name of the file: ";
    cin >> inputFileName;

    // File input
    ifstream inputFile(inputFileName);

    // Checking if opened properly
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Read n and m from file
    inputFile >> n >> m;

    // Check if the reading was successful
    if (inputFile.fail()) {
        cerr << "Error reading values from the file." << endl;
        return 1;
    }

    // Resizing the vector list according to input file
    times.resize(m);

    // Reading m time numbers from file and stores in vector
    for (int i = 0; i < m; i++) {
        inputFile >> times[i];
    }

    // Creating threads and feeding the input to the threads
    auto outputSchedule = parallelizeJobs(n, m, times);

    // Output of threads
    for (const auto& job : outputSchedule) {
        cout << job.first << " " << job.second << endl;
    }

    // Closing file
    inputFile.close();

    return 0;
}