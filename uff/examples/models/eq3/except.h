#ifndef EXCEPT_H
#define EXCEPT_H

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

#define __error(message)                                               \
    fprintf(stderr, "%s:In function `%s':\n" "%s:%d: %s\n",            \
            __FILE__, __FUNCTION__, __FILE__,  __LINE__, message"\n"); \
        exit(EXIT_FAILURE)

#endif       /* EXCEPT_H */

