# Lobster-selection-problem
The Lobster Selection Problem is a variant of the classic "Knapsack Problem," where the goal is to maximize the total value of items (lobsters, in this case) that can be carried within a given weight (capacity) limit.

Prerequisites
Ensure you have a C compiler installed on your system. Common options include gcc for Linux/Unix-based systems and clang for macOS. For Windows, you can use MinGW or a similar package that includes gcc.
Ensure your development environment (terminal or command prompt) is set up correctly with the necessary paths to the compiler.

Source Code File
Save the following C code to a file named lobster_selection.c:


#include <stdio.h>

int main()
{
    float Size[50], Value[50], ratio[50], Totalvalue = 0, temp, capacity;
    int i, j, number;
    
    printf("Enter the number of Lobsters :");
    scanf("%d", &number);

    printf("Lobsters available :");
    for (i = 1; i <= number; i++)
    {
        printf("\n\nEnter Size and Value for Lobster [%d] :\n", i);
        scanf("%f %f", &Size[i], &Value[i]);
    }
    
    printf("\n\nEnter capacity of the fisherman's net :\n");
    scanf("%f", &capacity);

    for (i = 0; i < number; i++)
        ratio[i] = Value[i + 1] / Size[i + 1];

    for (i = 0; i < number; i++)
    {
        for (j = i + 1; j < number; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = Size[j + 1];
                Size[j + 1] = Size[i + 1];
                Size[i + 1] = temp;

                temp = Value[j + 1];
                Value[j + 1] = Value[i + 1];
                Value[i + 1] = temp;
            }
        }
    }

    for (i = 0; i < number; i++)
    {
        if (Size[i + 1] > capacity)
            break;
        else
        {
            Totalvalue = Totalvalue + Value[i + 1];
            capacity = capacity - Size[i + 1];
        }
    }

    if (i < number)
        Totalvalue = Totalvalue + (ratio[i] * capacity);
    
    printf("\nThe total value of gold coins is :%f\n", Totalvalue);
    return 0;
}

Compilation Instructions

Linux/Unix (using gcc):
Open a terminal.
Navigate to the directory where lobster_selection.c is saved.
Compile the code using gcc:
gcc -o lobster_selection lobster_selection.c
If there are no errors, an executable named lobster_selection will be created in the same directory.

macOS (using clang):
Open a terminal.
Navigate to the directory where lobster_selection.c is saved.
Compile the code using clang:

clang -o lobster_selection lobster_selection.c
If there are no errors, an executable named lobster_selection will be created in the same directory.
Windows (using MinGW):
Open a command prompt.
Navigate to the directory where lobster_selection.c is saved.
Compile the code using gcc:


gcc -o lobster_selection.exe lobster_selection.c
If there are no errors, an executable named lobster_selection.exe will be created in the same directory.
Running the Program
After compiling the program, run it by executing the binary:

Linux/Unix:
./lobster_selection

macOS:
./lobster_selection

Windows:
lobster_selection.exe

Example Run
When you run the program, it will prompt you for input. Follow the prompts to enter the number of lobsters, their sizes, values, and the capacity of the net. The program will then output the total value of the selected lobsters.


Enter the number of Lobsters : 3
Lobsters available :

Enter Size and Value for Lobster [1] :
1 10

Enter Size and Value for Lobster [2] :
2 15

Enter Size and Value for Lobster [3] :
3 40

Enter capacity of the fisherman's net :
5

The total value of gold coins is :55.000000
