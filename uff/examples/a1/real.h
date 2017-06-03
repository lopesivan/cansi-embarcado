#ifndef REAL_H
#define REAL_H

#ifndef DOUBLE_PRECISION
    typedef float            Scalar;
    typedef float            Real;
#else  /* DOUBLE_PRECISION */
    typedef double           Scalar;
    typedef double           Real;
#endif /* DOUBLE_PRECISION */

#define data_no_fmt          "%f"

#define data_fmt             "%8.4f"

#define atos                 atof

#endif       /* REAL_H */
