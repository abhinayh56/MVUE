#ifndef ESTIMATORS_MVUE_4_H_BLUE_4_H
#define ESTIMATORS_MVUE_4_H_BLUE_4_H

namespace estimators
{
    namespace mvue
    {
        template <typename T>
        class MVUE_4
        {
        public:
            MVUE_4();
            ~MVUE_4();
            void init(T var_1_, T var_2_, T var_3_, T var_4_);
            void set_param(T var_1_, T var_2_, T var_3_, T var_4_);
            T update(T x1_i, T x2_i, T x3_i, T x4_i);
            void reset();

        private:
            T var_1 = 0.0;
            T var_2 = 0.0;
            T var_3 = 0.0;
            T var_4 = 0.0;
        };

#include "MVUE_4.tpp"
    }
}

#endif // ESTIMATORS_MVUE_4_H_BLUE_4_H
