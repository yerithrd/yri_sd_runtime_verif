/*
 * YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post.hpp
 *
 *      Author: Pr.  Prof.  Dr.-Ing. Xavier Noundou
 */

#ifndef _YRI_CPP_MONITOR_RECOVERY_SQL_INSERT__in_post
#define _YRI_CPP_MONITOR_RECOVERY_SQL_INSERT__in_post


#include "YRI_CPP_MONITOR_recovery_SQL_INSERT.hpp"


class YRI_CPP_MONITOR_STATE;


/**
 * WE ONLY SUPPORT "MISSING DATABASE TABLE COLUMN VALUE DEFINITION" as
 * DESCRIBED IN yerith_qvge user's guide (https://zenodo.org/record/8387240).
 */

class YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post : public YRI_CPP_MONITOR_recovery_SQL_INSERT
{
	Q_OBJECT


public:

    YRI_CPP_CLASS_OPERATORS


    inline YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post(YRI_CPP_MONITOR        *A_RUNTIME_MONITOR,
                                                        YRI_CPP_MONITOR_STATE  *a_source_state,
                                                        YRI_CPP_MONITOR_STATE  *a_target_state)
    :YRI_CPP_MONITOR_recovery_SQL_INSERT(A_RUNTIME_MONITOR,
                                         a_source_state,
                                         a_target_state)
    {
    }


    virtual inline ~YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post()
    {
    }


    virtual QString build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY();


protected:

    inline YRI_CPP_MONITOR_recovery_SQL_INSERT__in_post()
    :YRI_CPP_MONITOR_recovery_SQL_INSERT()
    {
    }
};



#endif // _YRI_CPP_MONITOR_RECOVERY_SQL_INSERT__in_post
