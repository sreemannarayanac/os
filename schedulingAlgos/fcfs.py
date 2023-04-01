# Python program for implementation of FCFS scheduling algorithm

class Process:
    def __init__(self, pid: int, at: int, bt: int) -> None:
        self.pid = pid
        self.at = at # arrival time
        self.bt = bt # burst time
        self.ct = 0 # completion time
        self.tat = 0 # turn around time
        self.rt = 0 # response time
    
    def __str__(self) -> str:
        return "Process id: " + str(self.pid) + " Arrival time: " + str(self.at) + " Burst time: " + str(self.bt)
    
    def __repr__(self) -> str:
        return self.pid

def takeProcessInput() -> list:
    processes = []
    for i in range(int(input("Enter number of processes: "))):
        print(f"Enter process {i+1} details")
        at = int(input("Arrival time: "))
        bt = int(input("Burst time: "))
        processes.append(Process(i+1, at, bt))
    return processes

def FCFS():
    # Take input
    processes = takeProcessInput()
    
    # Sorting processes by arrival time
    for i in range(len(processes)):
        for j in range(i+1, len(processes)):
            if processes[i].at > processes[j].at:
                processes[i], processes[j] = processes[j], processes[i]
    
    # Calculating completion time, turn around time and response time
    for process in processes:
        if process == processes[0]:
            process.ct = process.at + process.bt
        else:
            process.ct = processes[processes.index(process)-1].ct + process.bt
        process.tat = process.ct - process.at
        process.rt = process.tat - process.bt
    
    return processes

def printOutput() -> None:
    # Calling FCFS function
    processes = FCFS()
    print("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tResponse Time")
    for process in processes:
        print(f"{process.pid}\t{process.at}\t\t{process.bt}\t\t{process.ct}\t\t{process.tat}\t\t\t{process.rt}")
    print("Average Turn Around Time: ", sum([process.tat for process in processes])/len(processes))
    print("Average Waiting Time: ", sum([process.tat-process.bt for process in processes])/len(processes))

if __name__ == "__main__":
    printOutput()