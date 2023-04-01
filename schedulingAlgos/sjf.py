# Program to implement the Shortest Job First (SJF) scheduling algorithm without arrival time

class Process:
    def __init__(self, pid: int, bt: int) -> None:
        self.pid = pid
        self.bt = bt # burst time
        self.ct = 0 # completion time
        self.tat = 0 # turn around time
        self.rt = 0 # response time
    
    def __str__(self) -> str:
        return "Process id: " + str(self.pid) + " Burst time: " + str(self.bt)
    
    def __repr__(self) -> str:
        return self.pid

def takeProcessInput() -> list:
    processes = []
    for i in range(int(input("Enter number of processes: "))):
        print(f"Enter process {i+1} details")
        bt = int(input("Burst time: "))
        processes.append(Process(i+1, bt))
    return processes

def sjf() -> list:
    # taking input from user
    processes = takeProcessInput()
    
    # sorting processes by burst time
    for i in range(len(processes)):
        for j in range(i+1, len(processes)):
            if processes[i].bt > processes[j].bt:
                processes[i], processes[j] = processes[j], processes[i]
    
    # Performing Shortest Job First scheduling algorithm
    for process in processes:
        if process == processes[0]:
            process.ct = process.bt
        else:
            process.ct = processes[processes.index(process)-1].ct + process.bt
        process.tat = process.ct
        process.rt = process.tat - process.bt
    
    return processes

def printOutput() -> None:
    # calling sjf function
    processes = sjf()
    print("Process\tBurst Time\tCompletion Time\tTurn Around Time\tResponse Time")
    for process in processes:
        print(f"{process.pid}\t{process.bt}\t\t{process.ct}\t\t{process.tat}\t\t\t{process.rt}")
    print("Average Turn Around Time: ", sum([process.tat for process in processes])/len(processes))
    print("Average Waiting Time: ", sum([process.tat-process.bt for process in processes])/len(processes))
    print("Average Response Time: ", sum([process.rt for process in processes])/len(processes))