/*
File: IOpract.cpp
Desc: Practice with input and output but allow for multiple input data files to be used with the same program. This could be used in case you were running simulations 
and you had multiple output files generated per sim and you wanted to use a program to take each output file (now an input file) and do the same processing to each of 
them.

Date: 07/22/24
Author: spoonais
*/

#include<iostream>
#include<fstream>
#include<string>

int main()
{
    //1. Declare and init variables
    std::string filename;
    int value1(0), value2(0), counter(0), sum(0);
    
    //2. Create stream objects
    std::ifstream fin;
    std::ofstream fout;

    //3. Pick the input file you want to use
    std::cout << "Please pick the input file to use" << std::endl;
    std::cin >> filename;

    //4. Associate the stream objects with their files
    fin.open(filename.c_str());
    fout.open("FinalOut.txt");

    //5. Check to make sure that the files are open/closed with no errors
    if (fin. fail())
    {
        std::cout << "FAILED to open input file: " << filename << std::endl;
        exit(1); 
    }
    if (fout. fail())
    {
        std::cerr << "FAILED to open output file: FinalOut.txt" << std::endl;
        exit(1);
    }

    //6. Get first set of values from input file:
    

    //7. Read input file
    //Note: Not sure why this is skipping over the very last data point in "Data1.txt"???
    //This could have the answer: https://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-i-e-while-stream-eof-cons
    while (fin >> value1 >> value2)
    {
        //Initialize to line 1
        counter++;

        //Add the values 
        sum = value1 + value2;

        if(sum == 10)
        {
            fout << "The values add to ten on line " << counter << std::endl;
        } 
            else
            {
                std::cerr << "Invalid data on line " << counter << std::endl;

            }
        
    }

    //8. Close files
    fin.close();
    fout.close();

    //9. Pause program:
    system("pause");

    //10. Exit Program
    return (0);

}
