#include <sqlite3.h>
#include <string>
#include <vector>

class Storage {
protected:
    sqlite3* db;
public:
    virtual bool open(const std::string& filename) = 0;
    virtual void close() = 0;
};

class DatabaseManager : public Storage {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool open(const std::string& filename) override;
    void close() override;

    bool create_table();

    bool add_record(const std::string& name);

    bool operator!() const { // перегрузка для проверки создана ли бд 
        return db == nullptr;
    }
};