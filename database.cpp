#include "database.h"
#include <iostream>

DatabaseManager::DatabaseManager() { db = nullptr;}
DatabaseManager::~DatabaseManager() { close(); }

bool DatabaseManager::open(const std::string& filename) {
    return sqlite3_open(filename.c_str(), &db) == SQLITE_OK;
}

void DatabaseManager::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    } 
}  

bool DatabaseManager::create_table() {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS USERS(
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            NAME TEXT
            );
    )";
    char* error_msg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &error_msg);
    return rc == SQLITE_OK; 
}

bool DatabaseManager::add_record(const std::string& name) {
    std::string sql = "INSERT INTO USERS (NAME) VALUES ('" + name + "');";
    return sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr) == SQLITE_OK;
}