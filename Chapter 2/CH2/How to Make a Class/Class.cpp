/* This program will create a log class, in order to understand how classes work*/

#include<iostream>

class Log
{
    //Define the Log Levels member variables
    public: //varibles
    const int LogLevelWarning = 0;
    const int LogLevelError = 1;
    const int LogLevelInfo = 2;

    private:
        int m_LogLevel = LogLevelInfo;

    //Set the log level
    public: //methods
        void SetLevel(int level) //what does void do???
        {
            m_LogLevel = level; //assigns the "member variable" with the paramter
        }

        void Info(const char* message) //using a const char* pointer as a string...Not sure how this works
        {
            if (m_LogLevel >= LogLevelInfo )
                std::cout << "[INFO]" << message << std::endl;
        }

        void Warn(const char* message) 
        {
            if (m_LogLevel >= LogLevelWarning)
                std::cout << "[WARNING]" << message << std::endl;
        }

        void Error(const char* message) 
        {
            if (m_LogLevel >= LogLevelError)
                std::cout << "[ERROR]" << message << std::endl;
        }
};

int main()
{
    Log log;        //Instantiate the class
    log.SetLevel(log.LogLevelError);
    log.Warn("Cant do that");
    log.Error("Cant do that");
    log.Info("Cant do that");
    std::cin.get();
}