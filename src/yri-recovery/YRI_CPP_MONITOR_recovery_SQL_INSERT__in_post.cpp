/*
 * YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post.cpp
 *
 *      Author: Pr.  Prof.  Dr.-Ing. Xavier Noundou
 */

#include "YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post.hpp"


#include "src/YRI_CPP_MONITOR_STATE.hpp"



QString YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post::build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY()
 {
    ___SQL_INSERT_QUERY_for_ERROR_STATE_SAFE_RECOVERY.clear();


    if (0 == _A_SOURCE_STATE ||
        0 == _A_TARGET_STATE)
    {
        return YRI_CPP_UTILS::EMPTY_STRING;
    }


    QDEBUG_STRING_OUTPUT_1("YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post::build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY");

//    _A_SOURCE_STATE->print();
//
//    _A_TARGET_STATE->print();

    QString DB_SQL_TABLE;


    if (!_A_TARGET_STATE->Is_SQL_RECOVERY_QUERY_STRING_Empty())
    {
        QString a_target_SQL_RECOVERY_QUERY_STRING =
            _A_TARGET_STATE->Get_SQL_RECOVERY_QUERY_STRING();

        DB_SQL_TABLE = _A_TARGET_STATE->Get_SQL_RECOVERY_QUERY_DB_TABLE();

        QDEBUG_STRING_OUTPUT_2("DB_SQL_TABLE - 1", DB_SQL_TABLE);

        QDEBUG_STRING_OUTPUT_2("YRI recovery_in_post ", a_target_SQL_RECOVERY_QUERY_STRING);


        if (a_target_SQL_RECOVERY_QUERY_STRING.contains("yri_id"))
        {
            a_target_SQL_RECOVERY_QUERY_STRING
                .replace("yri_id",
                         QString("(SELECT COALESCE(MAX(id), 0) + 1 FROM %1)")
                         .arg(DB_SQL_TABLE));
        }

//        a_target_SQL_RECOVERY_QUERY_STRING.replace("'", "");
//        a_target_SQL_RECOVERY_QUERY_STRING.replace("#", "'");

        QDEBUG_STRING_OUTPUT_2("a_target_SQL_RECOVERY_QUERY_STRING",
                                a_target_SQL_RECOVERY_QUERY_STRING);



        return a_target_SQL_RECOVERY_QUERY_STRING;
    }


    return ___SQL_INSERT_QUERY_for_ERROR_STATE_SAFE_RECOVERY;
 }

