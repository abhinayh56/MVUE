#ifndef ESTIMATORS_MVUE_2_H_BLUE_2_H
#define ESTIMATORS_MVUE_2_H_BLUE_2_H

namespace estimators
{
    namespace mvue
    {
        template <typename T>
        class MVUE_2
        {
        public:
            MVUE_2();
            ~MVUE_2();
            void init(T var_1_, T var_2_);
            void set_param(T var_1_, T var_2_);
            T update(T x1_i, T x2_i);
            void reset();

        private:
            T var_1 = 0.0;
            T var_2 = 0.0;
        };

#include "MVUE_2.tpp"
    }
}

#endif // ESTIMATORS_MVUE_2_H_BLUE_2_H
