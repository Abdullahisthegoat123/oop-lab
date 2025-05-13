#include <iostream>
#include <stdexcept>

using namespace std;

class DatabaseException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException
{
};
class QueryTimeoutException : public DatabaseException
{
};

template <typename T>
class DatabaseConnector
{
public:
    void connect(const T &dbName)
    {
        if (dbName == "invalid_db")
        {
            throw ConnectionFailedException();
        }
        else if (dbName == "slow_db")
        {
            throw QueryTimeoutException();
        }
        else
        {
            cout << "Connected to database: " << dbName << endl;
        }
    }
};

int main()
{
    DatabaseConnector<string> connector;

    try
    {
        cout << "Attempting to connect to invalid_db..." << endl;
        connector.connect("invalid_db");
    }
    catch (const ConnectionFailedException &e)
    {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }
    catch (const DatabaseException &e)
    {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    try
    {
        cout << "Attempting to connect to slow_db..." << endl;
        connector.connect("slow_db");
    }
    catch (const QueryTimeoutException &e)
    {
        cout << "Caught QueryTimeoutException - what(): " << e.what() << endl;
    }
    catch (const DatabaseException &e)
    {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}