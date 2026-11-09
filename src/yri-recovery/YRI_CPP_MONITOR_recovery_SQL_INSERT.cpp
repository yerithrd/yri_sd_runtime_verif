/*
 * YRI_CPP_MONITOR_recovery_SQL_INSERT.cpp
 *
 *      Author: Pr.  Prof.  Dr.-Ing. Xavier Noundou
 */

#include "YRI_CPP_MONITOR_recovery_SQL_INSERT.hpp"


#include "src/YRI_CPP_MONITOR_STATE.hpp"



bool YRI_CPP_MONITOR_recovery_SQL_INSERT::RUN_SQL_query_string()
{
    bool query_success = false;

    QString SQL_QUERY_STRING =
                build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY();

    SQL_QUERY_STRING.replace("#", "\"");

    QDEBUG_STRING_OUTPUT_2("YRI_CPP_MONITOR_recovery_SQL_INSERT::RUN_SQL_query_string; SQL_QUERY_STRING",
                            SQL_QUERY_STRING);


    bool dbg_MSG = true;


    query_success =
        YRI_CPP_UTILS::execQueryRowCount(SQL_QUERY_STRING,
                                        dbg_MSG);

    return query_success;
}


QString YRI_CPP_MONITOR_recovery_SQL_INSERT::build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY()
{
    QDEBUG_STRING_OUTPUT_2("YRI_CPP_MONITOR_recovery_SQL_INSERT:build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY", "... NOT IMPLEMENTED virtual method...");

    return QString("YRI_CPP_MONITOR_recovery_SQL_INSERT:build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY: ... NOT IMPLEMENTED virtual method...");
}

