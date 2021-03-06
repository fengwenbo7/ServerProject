/*
fengwenbo 2022-06
*/

#ifndef SQLCONNRAII_H
#define SQLCONNRAII_H
#include "sql_conn_pool.h"

/* 资源在对象构造初始化 资源在对象析构时释放*/
class SqlConnRAII {
public:
    SqlConnRAII(MYSQL** sql, SqlConnPool *connpool) {
        assert(connpool);
        *sql = connpool->GetConn();
        if(!*sql){
            std::cout<<"conn_pool->GetConn() return nullptr."<<std::endl;
        }
        sql_ = *sql;
        connpool_ = connpool;
    }
    
    ~SqlConnRAII() {
        if(sql_) { connpool_->FreeConn(sql_); }
    }
    
private:
    MYSQL *sql_;
    SqlConnPool* connpool_;
};

#endif