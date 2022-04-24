#include<stdio.h>
struct Process
{
    int pid;
    int burst;
    int arrival_time;
    int waiting_time;
    int turnaroud_time;
    int priority;
    int Gantt_time;
};
void initaialise_FCFS(int n , struct Process f[100])
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        f[i].pid = i;
        printf("\n");
        printf("Arrival Time of process %d : " , i);
        scanf("%d",&f[i].arrival_time); 
        printf("Burst Time of process %d : " , i);
        scanf("%d",&f[i].burst);
        printf("Enter Priority of the process %d : " , i);
        scanf("%d",&f[i].priority);
        printf("\n");
        f[i].waiting_time = 0;
        f[i].turnaroud_time = 0;
        f[i].Gantt_time = 0;
    }
}

void evaluate_FCFS(int n , struct Process f[100])
{
    int time = 0;
    for(int i = 0 ; i < n ; i++)
    {
        f[i].waiting_time = time - f[i].arrival_time;
        time += f[i].burst;  
        f[i].turnaroud_time = time - f[i].arrival_time;
    }
}

void print_Process(int n , struct Process f[100])
{
    int i;
    printf("Process    Burst     Arrival     Wait Time    Turnaround Time\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d          %d            %d             %d           %d " , f[i].pid , f[i].burst , f[i].arrival_time , f[i].waiting_time , f[i].turnaroud_time);
        printf("\n");
    }
}
void print_Priority(int n , struct Process f[100])
{
    int i;
    printf("Process    Burst     Arrival     Wait Time    Turnaround Time    Priority\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d          %d            %d             %d           %d        %d " , f[i].pid , f[i].burst , f[i].arrival_time , f[i].waiting_time , f[i].turnaroud_time , f[i].priority);	
        printf("\n");
    }
}
void evaluate_SJF(int n , struct Process f[100])
{
    int time_reached = 0;
    int count = 0;
    int min = 10000000;
    int array[100];
    int c_i;
    int time = 0;
    for(int i = 0 ; i < n ; i++)
        array[i] = 0;
    while (count != n)
    {
        for(int i = 0 ; i <n ; i++)
        {
            if(array[i] == 0 && f[i].arrival_time <= time_reached)
            {
                if(min > f[i].burst)
                {
                    min = f[i].burst;
                    c_i = i;
                }
            }
        }
        ++count;
        array[c_i] = 1;
        min = 10000000;
        f[c_i].waiting_time = time_reached - f[c_i].arrival_time;
        time_reached += f[c_i].burst; 
        f[c_i].turnaroud_time = time_reached - f[c_i].arrival_time;
    }
}

void evaluate_Priority(int n , struct Process f[100])
{
    int time_reached = 0;
    int count = 0;
    int min = 10000000;
    int array[100];
    int c_i;
    int time = 0;
    for(int i = 0 ; i < n ; i++)
        array[i] = 0;
    while (count != n)
    {
        for(int i = 0 ; i <n ; i++)
        {
            if(array[i] == 0 && f[i].arrival_time <= time_reached)
            {
                if(min > f[i].priority)
                {
                    min = f[i].priority;
                    c_i = i;
                }
            }
        }
        ++count;
        array[c_i] = 1;
        min = 10000000;
        f[c_i].waiting_time = time_reached - f[c_i].arrival_time;
        time_reached += f[c_i].burst; 
        f[c_i].turnaroud_time = time_reached - f[c_i].arrival_time;
    }
}
void evaluate_RR(int n , struct Process f[100] , int time_quantum)
{
    int time_reached = 0;
    int count = 0;
    int ready_queue[100];
    int burst_time[100];
    int front = 0;
    int rear = -1;
    ready_queue[++rear] = f[0].pid;
    int waiting_array[100];
    int id_reached = 0;
    
    for(int i = 0; i < n ; i++) {
        waiting_array[i] = 0;
        burst_time[i] = f[i].burst;
    }
    while(front == 0 || front <= rear)
    {
        int i;
        int id = ready_queue[front++];
        if(burst_time[id] > time_quantum)
        {
            burst_time[id] -= time_quantum;
            time_reached += time_quantum;
            f[id].waiting_time+=time_quantum;
        }else
        {
            f[id].waiting_time = time_reached - f[id].arrival_time - f[id].waiting_time;
            time_reached += burst_time[id];
            burst_time[id] = 0;
            f[id].turnaroud_time = time_reached - f[id].arrival_time;
        }

        for ( i = id_reached + 1 ; i < n; i++)
        {
            if(f[i].arrival_time <= time_reached)
            {
                ready_queue[++rear] = f[i].pid;
                id_reached = i;
            }
        }

        if(burst_time[id]!= 0)
        {
            ready_queue[++rear] = f[id].pid;
        }
    }
}

void main()
{
    char ch;
    int choice,x;
    struct Process f[100];
    int n;
    printf("Enter the number of processes : ");
    scanf("%d" , &n);
    initaialise_FCFS(n,f);
    do
    {
        printf("\n 1.FCFS\n 2.SJF\n 3.RR\n 4.Priority");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:     evaluate_FCFS(n,f);
                        printf("\n");
                        print_Process(n,f);
                        break;

            case 2:     evaluate_SJF(n,f);
                        printf("\n");
                        print_Process(n,f);
                        break;

            case 3:
                        printf("Enter time quantum : ");
                        scanf("%d", &x);
                        evaluate_RR(n, f, x);
                        printf("\n");
                        print_Process(n, f);
                        break;

            case 4:     evaluate_Priority(n,f);	
                        printf("\n");
                        print_Process(n,f);
                        break;

            default:    printf("Invalid choice");	

        }

        printf("\nDo you want to continue?(y/n)");
        scanf(" %c",&ch);
    
    } while (ch == 'y');
    
}